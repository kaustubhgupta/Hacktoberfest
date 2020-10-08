/*Java Program to demonstrate the use of If else-if ladder.
• program of grading system for fail (&lt;50),
• D grade -marks&gt;=50 &amp;&amp; marks&lt;60
• C grade- marks&gt;=60 &amp;&amp; marks&lt;70,
• B grade- marks&gt;=70 &amp;&amp; marks&lt;80 ,
• A grade- marks&gt;=80 &amp;&amp; marks&lt;90
• and A+ - marks&gt;=90 &amp;&amp; marks&lt;100.*/
import java.util.Scanner;
public class Grade
{
public static void main(String args[])
{
System.out.println(&quot;Enter Marks: &quot;);
ABC S=new ABC();
S.display();
}
}
class ABC
{
Scanner A = new Scanner(System.in);
int marks=A.nextInt();
public void display()
{
if(marks&lt;50)
{
System.out.println(&quot;Fail&quot;);
}
else if(marks&gt;=50 &amp;&amp; marks&lt;60)
{
System.out.println(&quot;D Grade&quot;);
}
else if(marks&gt;=60 &amp;&amp; marks&lt;70)
{
System.out.println(&quot;C Grade&quot;);
}
else if(marks&gt;=70 &amp;&amp; marks&lt;80)
{
System.out.println(&quot;B Grade&quot;);
}
else if(marks&gt;=80 &amp;&amp; marks&lt;90)
{
System.out.println(&quot;A Grade&quot;);
}
else

{
System.out.println(&quot;A+ Grade&quot;);
}
}
}
