import java.util.Scanner;
public class grades

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

if(marks&lt;50)                                   /* fail (&lt;50)*/

{

System.out.println(&quot;Fail&quot;);

}

else if(marks&gt;=50 &amp;&amp; marks&lt;60)      /* D grade -marks&gt;=50 &amp;&amp; marks&lt;60*/

{

System.out.println(&quot;D Grade&quot;);

}

else if(marks&gt;=60 &amp;&amp; marks&lt;70)      /* C grade- marks&gt;=60 &amp;&amp; marks&lt;70*/

{

System.out.println(&quot;C Grade&quot;);

}

else if(marks&gt;=70 &amp;&amp; marks&lt;80)      /* B grade- marks&gt;=70 &amp;&amp; marks&lt;80*/

{

System.out.println(&quot;B Grade&quot;);

}

else if(marks&gt;=80 &amp;&amp; marks&lt;90)      /* A grade- marks&gt;=80 &amp;&amp; marks&lt;90*/

{

System.out.println(&quot;A Grade&quot;);

}

else

{

System.out.println(&quot;A+ Grade&quot;);         /* A+ - marks&gt;=90 &amp;&amp; marks&lt;100*/

}

}

}
