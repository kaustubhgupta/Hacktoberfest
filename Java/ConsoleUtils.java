import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Calendar;
import java.util.Date;
import java.util.List;

@SuppressWarnings({ "squid:S106", "squid:S4829" })
public final class ConsoleUtils {


    private ConsoleUtils() {
        // to make sure this is an utility class
    }

    /**
     * Reads input from the console as a string.
     *
     * @param prompt
     * @return the input read from the console
     */
    public static String readLine(final String prompt) {
        try {
            System.out.print(prompt+" ");
            final InputStreamReader converter = new InputStreamReader(System.in);
            final BufferedReader in = new BufferedReader(converter);

            return in.readLine();
        } catch (final IOException ex) {
            return "";
        }
    }

    /**
     * Reads input from the console as a string ensuring that the string is not
     * empty or composed just of whitespace.
     *
     * @param prompt
     *            the prompt for the input
     * @param message
     *            the message to show in case of bad input
     * @return the input read from the console
     */
    public static String readNonEmptyLine(final String prompt, final String message) {
        do {
            try {
                System.out.println(prompt);
                final InputStreamReader converter = new InputStreamReader(System.in);
                final BufferedReader in = new BufferedReader(converter);

                final String text = in.readLine();
                if (text == null || text.isEmpty()) {
                    System.out.println(message);
                } else {
                    return text;
                }
            } catch (final IOException ex) {
                return "";
            }
        } while (true);
    }

    /**
     * Reads while hiding a String value from the console
     *
     * @param prompt
     * @return string value that was read
     */
    public static String readPassword(String prompt) {
        return new String(System.console().readPassword(prompt));
    }

    /**
     * Reads input from the console as an integer value.
     *
     * @param prompt
     * @return the integer that was read
     */
    public static int readInteger(final String prompt) {
        do {
            try {
                final String input = readLine(prompt);
                return Integer.parseInt(input);
            } catch (@SuppressWarnings("unused") final NumberFormatException ex) {
                // nothing to do
            }
        } while (true);
    }

    /**
     * Reads input from the console as a long value.
     *
     * @param prompt
     * @return the long that was read
     */
    public static long readLong(final String prompt) {
        do {
            try {
                final String input = readLine(prompt);
                return Long.parseLong(input);
            } catch (@SuppressWarnings("unused") final NumberFormatException ex) {
                // nothing to do
            }
        } while (true);
    }

    /**
     * Reads input from the console as a boolean (Y, S, N).
     *
     * @param prompt
     * @return the boolean that was read
     */
    public static boolean readBoolean(final String prompt) {
        do {
            try {
                final String strBool = readLine(prompt).toLowerCase();
                if ("y".equals(strBool) || "s".equals(strBool)) {
                    return true;
                } else if ("n".equals(strBool)) {
                    return false;
                }
            } catch (@SuppressWarnings("unused") final NumberFormatException ex) {
                // nothing to do
            }
        } while (true);
    }

    /**
     * Reads input from the console as an integer value between <code>low</code>
     * and <code>high</code> or <code>exit</code>.
     *
     * @param low
     * @param high
     * @param exit
     * @return the integer that was read
     */
    public static int readOption(final int low, final int high, final int exit, String prompt) {
        int option;
        do {
            option = ConsoleUtils.readInteger(prompt);
            if (option == exit) {
                break;
            }
        } while (option < low || option > high);
        return option;
    }

    /**
     * Reads a date from the console.
     *
     * @param prompt
     * @return the date that was read
     */
    public static Date readDate(final String prompt) {
        return readDate(prompt, "yyyy/MM/dd");
    }

    /**
     * Reads a date from the console.
     *
     * @param prompt
     * @param dateFormat
     * @return the date that was read
     */
    public static Date readDate(final String prompt, final String dateFormat) {
        do {
            try {
                final String strDate = readLine(prompt);
                final SimpleDateFormat df = new SimpleDateFormat(dateFormat);
                return df.parse(strDate);
            } catch (@SuppressWarnings("unused") final ParseException ex) {
                // nothing to do
            }
        } while (true);
    }

    /**
     * Reads a date from the console.
     *
     * @param prompt
     * @return the date that was read
     */
    public static Calendar readCalendar(final String prompt) {
        return readCalendar(prompt, "dd-MM-yyyy");
    }

    /**
     * Reads a date from the console.
     *
     * @param prompt
     * @param dateFormat
     * @return the date that was read
     */
    public static Calendar readCalendar(final String prompt, final String dateFormat) {
        do {
            try {
                final String strDate = readLine(prompt);
                final SimpleDateFormat df = new SimpleDateFormat(dateFormat);
                return CalendarUtils.fromDate(df.parse(strDate));
            } catch (@SuppressWarnings("unused") final ParseException ex) {
                // nothing to do
            }
        } while (true);
    }

    /**
     * Reads a double form the console.
     *
     * @param prompt
     * @return the double that was read
     */
    public static double readDouble(final String prompt) {
        do {
            try {
                final String input = readLine(prompt);
                return Double.parseDouble(input);
            } catch (@SuppressWarnings("unused") final NumberFormatException ex) {
                // nothing to do
            }
        } while (true);
    }

    public static short readShort(String prompt) {
        do {
            try {
                final String input = readNonEmptyLine(prompt, "Não pode estar vazio. ");
                return Short.parseShort(input);
            } catch (@SuppressWarnings("unused") final NumberFormatException ex) {
                // nothing to do
            }
        } while (true);
    }

    public static boolean readConfirmation(final Object... inputs) {
        String confirmationString = "\nAre these values correct?(y/n)";
        for (Object obj : inputs) {
            confirmationString += "\n" + obj.toString();
        }

        return readBoolean(confirmationString);

    }

    /**
     *
     * @param prompt
     */
    @SuppressWarnings("squid:S1166")
    public static void waitForKey(final String prompt) {
        System.out.println(prompt);
        try {
            System.in.read();
        } catch (@SuppressWarnings("unused") final IOException ex) {
            // nothing to do
        }
    }

    public static <T> void printIterable(Iterable<T> iterable) {
        StringBuilder str = new StringBuilder();
        for (T object : iterable) {
            str.append("\n\n").append(object.toString());
        }

        System.out.println(str.toString());
    }

    public static <T> T showOptionsAndReturnChoice(Iterable<T> iterable, String prompt) {
        List<T> list = new ArrayList<>();
        iterable.forEach(list::add);

        for (int i = 0; i < list.size(); i++)
            System.out.println((i + 1) + " - " + list.get(i));

        int choice;
        boolean repeat;
        do {
            choice = readInteger(prompt + " (0 para terminar) ");
            repeat = choice >= list.size() - 1 && choice < 0;
            if (repeat)
                System.out.println("Inválido");
        } while (repeat);

        return choice == 0 ? null : list.get(choice - 1);
    }

}
