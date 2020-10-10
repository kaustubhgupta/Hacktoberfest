import java.text.DateFormat;
import java.text.DateFormatSymbols;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.time.Instant;
import java.time.LocalDateTime;
import java.time.ZoneId;
import java.time.ZoneOffset;
import java.time.format.DateTimeFormatter;
import java.util.Calendar;
import java.util.Date;
import java.util.GregorianCalendar;
import java.util.TimeZone;
import java.util.function.Supplier;

public final class CalendarUtils {

    private static final int DAYS_TILL_END_OF_WEEK = 6;

    /**
     * Mock the system clock for unit testing.
     * <p>
     * suppress warning squid:S2885 - we are protecting the variable with synchronize getter
     */
    @SuppressWarnings("squid:S2885") //
    private static Calendar frozenTime;

    private static   Calendar fakeNow() {
        return frozenTime;
    }

    private static Calendar realNow() {
        return new GregorianCalendar();
    }

    private static Supplier<Calendar> nowFunction = CalendarUtils::realNow;

    private CalendarUtils() {
        // to make sure this is an utility class
    }

    /**
     * Overrides the use of the system clock to allow unit testing.
     */
    /* package */ static   void setNow(final Calendar frozenTime) {
        CalendarUtils.frozenTime = frozenTime;
        nowFunction = CalendarUtils::fakeNow;
    }

    /**
     * Returns the current date of the system.
     *
     * @return the current date of the system.
     */
    public static Calendar now() {
        return nowFunction.get();
    }

    /**
     * Returns the number of the week in the year given a certain date.
     *
     * @param date
     * @return the number of the week in the year given a certain date.
     */
    public static int weekNumber(final Calendar date) {
        return date.get(Calendar.WEEK_OF_YEAR);
    }

    public static Calendar fromDate(final Date date) {
        final Calendar cal = Calendar.getInstance();
        cal.setTime(date);
        return cal;
    }

    public static int currentWeekNumber() {
        return weekNumber(now());
    }

    /**
     * Returns the date of the first day of a week.
     *
     * @param year
     * @param week
     * @return the date of the first day of a week.
     */
    public static Calendar beginningOfWeek(final int year, final int week) {
        final Calendar date = new GregorianCalendar();
        date.clear();
        date.set(Calendar.YEAR, year);
        date.set(Calendar.WEEK_OF_YEAR, week);
        return date;
    }

    /**
     * Returns the date of the last day of a week.
     *
     * @param year
     * @param week
     * @return the date of the last day of a week.
     */
    public static Calendar endOfWeek(final int year, final int week) {
        final Calendar date = beginningOfWeek(year, week);
        date.add(Calendar.DATE, DAYS_TILL_END_OF_WEEK);
        return date;
    }

    /**
     * Returns the date of the last day of the current month.
     *
     * @return the date of the last day of the current month.
     */
    public static Calendar endOfCurrentMonth() {
        return endOfMonth(now());
    }

    /**
     * Returns the date of the last day of a certain month.
     *
     * @param reference
     *            a date to be used as reference month
     * @return the date of the last day of a certain month.
     */
    public static Calendar endOfMonth(final Calendar reference) {
        final Calendar lastDay = new GregorianCalendar();
        lastDay.setTime(reference.getTime());
        final int last = lastDay.getActualMaximum(Calendar.DAY_OF_MONTH);
        lastDay.set(Calendar.DAY_OF_MONTH, last);
        return lastDay;
    }

    /**
     * returns the date of the last day of a certain month.
     *
     * @param year
     * @param month
     *            month number (1 - 12)
     * @return the date of the last day of a certain month
     */
    public static Calendar endOfMonth(final int year, final int month) {
        final Calendar date = of(year, month, year);
        return endOfMonth(date);
    }

    /**
     * returns the current year.
     *
     * @return the current year
     */
    public static int currentYear() {
        return now().get(Calendar.YEAR);
    }

    /**
     * returns the current month of the year
     *
     * @return current month (1 - 12) of the year
     */
    public static int currentMonth() {
        return now().get(Calendar.MONTH) + 1;
    }

    /**
     * Creates a new Calendar object set to a specific date
     *
     * @param year
     *            the year
     * @param month
     *            the month (1 - 12). note that the Calendar class uses months from 0 to 11, not 1 to
     *            12
     * @param day
     *            the day of the month
     * @return a newly create Calendar object
     */
    public static Calendar of(final int year, final int month, final int day) {
        return new GregorianCalendar(year, month - 1, day);
    }

    /**
     * Creates a new Calendar instance with the date part set (year, month, date) from the source
     * object.
     *
     * @param source
     * @return a new Calendar instance
     */
    public static Calendar dateOf(final Calendar source) {
        return of(source.get(Calendar.YEAR), source.get(Calendar.MONTH) + 1,
                source.get(Calendar.DATE));
    }

    /**
     * Parses a string that contains a date in a certain format.
     *
     * @param aDateString
     * @param format
     * @return a Calendar object or null if there was an error parsing the string
     */
    public static Calendar parse(final String aDateString, final String format) {
        try {
            final SimpleDateFormat df = new SimpleDateFormat(format);
            final Date date = df.parse(aDateString);
            return fromDate(date);
        } catch (final ParseException ex) {
            throw new IllegalArgumentException("Could not parse date");
        }
    }

    /**
     * Creates and returns a {@link Calendar} instance by parsing a given string base on a data format.
     *
     * @param value
     *            the date in string format
     * @param dateFormat
     *            the format to use when parsing the dateString
     *
     * @return the generated {@link Calendar} instance.
     * @throws ParseException
     */
    public static Calendar parse(final String value, final DateFormat dateFormat)
            throws ParseException {
        final Calendar calendar = Calendar.getInstance();
        final Date date = dateFormat.parse(value);
        calendar.setTime(date);
        return calendar;
    }

    public static Calendar parse(final String aDateString) {
        return parse(aDateString, "dd-MM-yyyy");
    }

    public static String format(final Calendar ocurrs) {
        return format(ocurrs, "YYYY/MM/dd");
    }

    /**
     * Formats a date according to ISO8601.
     * <p>
     * based on <a href=
     * "https://stackoverflow.com/questions/3914404/how-to-get-current-moment-in-iso-8601-format-with-date-hour-and-minute/33532945">Stack
     * Overflow</a>
     *
     * @param when
     * @return the date formatted according to ISO8601.
     */
    public static String iso8601(final Calendar when) {
        return DateTimeFormatter.ofPattern("yyyy-MM-dd'T'HH:mmX").withZone(ZoneOffset.UTC)
                .format(when.toInstant());
    }

    /**
     * Converts a Calendar object to Java 8 LocalDateTime
     * <p>
     * Taken from <a href=
     * "https://www.logicbig.com/how-to/java-8-date-time-api/calender-to-localdatetime.html">logicbig</a>
     * and <a href= "https://www.baeldung.com/java-date-to-localdate-and-localdatetime">Baeldung</a>
     *
     * @param calendar
     * @return the date as a LocalDateTime object
     */
    public static LocalDateTime toLocalDateTime(final Calendar calendar) {
        if (calendar == null) {
            return null;
        }
        final TimeZone tz = calendar.getTimeZone();
        final ZoneId zid = tz == null ? ZoneId.systemDefault() : tz.toZoneId();
        return LocalDateTime.ofInstant(calendar.toInstant(), zid);
    }

    /**
     * Returns the current time according to the ISO 8601 format.
     *
     * <p>
     * based on
     * https://stackoverflow.com/questions/3914404/how-to-get-current-moment-in-iso-8601-format-with-date-hour-and-minute/33532945
     *
     * @return the current time in ISO 8601 format
     */
    public static String iso8601() {
        return DateTimeFormatter.ofPattern("yyyy-MM-dd'T'HH:mmX").withZone(ZoneOffset.UTC)
                .format(Instant.now());
    }

    public static String format(final Calendar ocurrs, final String dateFormat) {
        return format(ocurrs, new SimpleDateFormat(dateFormat));
    }

    /**
     * Creates and returns a {@link String} instance by parsing a given Calendar base on a data format.
     *
     * @param calendar
     *            the Calendar object to parse
     * @param dateFormat
     *            the format to use when parsing the Calendar object
     *
     * @return the generated {@link String} instance.
     */
    public static String format(final Calendar calendar, final DateFormat dateFormat) {
        return dateFormat.format(calendar.getTime());
    }

    public static String weekdayName(final Calendar calendar) {
        final String[] dayNames = new DateFormatSymbols().getWeekdays();
        return dayNames[calendar.get(Calendar.DAY_OF_WEEK)];
    }

    /**
     * Returns yesterday's date.
     *
     * @return yesterday's date.
     */
    public static Calendar yesterday() {
        final Calendar yesterday = now();
        yesterday.add(Calendar.DATE, -1);
        return yesterday;
    }

    /**
     * Returns tomorrow's date.
     *
     * @return tomorrow's date
     */
    public static Calendar tomorrow() {
        final Calendar yesterday = now();
        yesterday.add(Calendar.DATE, 1);
        return yesterday;
    }

    /**
     * sets a date to the last instant of the given day
     *
     * @param calendar
     * @return the last instant of the day
     */
    public static Calendar setToEndOfTheDay(final Calendar calendar) {
        calendar.set(Calendar.HOUR_OF_DAY, 23);
        calendar.set(Calendar.MINUTE, 59);
        calendar.set(Calendar.SECOND, 59);
        calendar.set(Calendar.MILLISECOND, 999);

        return calendar;
    }

    /**
     * sets a date to the beginning of the day
     *
     * @param calendar
     * @return the first instant of the day
     */
    public static Calendar getStartOfTheDay(final Calendar calendar) {
        calendar.set(Calendar.HOUR_OF_DAY, 0);
        calendar.set(Calendar.MINUTE, 0);
        calendar.set(Calendar.SECOND, 0);
        calendar.set(Calendar.MILLISECOND, 0);

        return calendar;
    }

    public static Calendar calendarFromString(String str) throws IllegalArgumentException {
        String[] time = str.trim().split(" ")[0].split(":");
        String[] date = str.trim().split(" ")[1].split("/");
        int intMonth = Integer.parseInt(date[1].trim());
        int i;
        switch (intMonth) {
            case 1:
                i = Calendar.JANUARY;
                break;
            case 2:
                i = Calendar.FEBRUARY;
                break;
            case 3:
                i = Calendar.MARCH;
                break;
            case 4:
                i = Calendar.APRIL;
                break;
            case 5:
                i = Calendar.MAY;
                break;
            case 6:
                i = Calendar.JUNE;
                break;
            case 7:
                i = Calendar.JULY;
                break;
            case 8:
                i = Calendar.AUGUST;
                break;
            case 9:
                i = Calendar.SEPTEMBER;
                break;
            case 10:
                i = Calendar.OCTOBER;
                break;
            case 11:
                i = Calendar.NOVEMBER;
                break;
            case 12:
                i = Calendar.DECEMBER;
                break;
            default:
                throw new IllegalArgumentException("Mês inválido.");
        }
        return new GregorianCalendar(Integer.parseInt(date[2].trim()),
                i, Integer.parseInt(date[0].trim()),
                Integer.parseInt(time[0].trim()), Integer.parseInt(time[1].trim()),
                Integer.parseInt(time[2].trim()));
    }
}
