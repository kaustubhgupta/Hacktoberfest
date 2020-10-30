import java.util.*;
class Twin_Prime
{
    int a,b;
    Twin_Prime(int x,int y)
    {
        a=x;
        b=y;
    }
    int isPrime(int n,int x)
    {
        if(n==x)
        {
            return 1;
        }
        else 
        {
            if(n%x==0 || n==1)
            {
                  return 0;
                }
        
             else
           {
                 return isPrime(n,++x);
            }
        }
    }
    void display()
    {
        int x=isPrime(a,2);
        int y=isPrime(b,2);
        if(x==1 && y==1 && Math.abs(x-y)==2)
        System.out.println("Twin Prime Numbers");
        else
        System.out.println(" Not Twin Prime");
    }
    public static void main()
    {
        Scanner in=new Scanner(System.in);
        int a,b;
        System.out.println("Enter the numbers");
        a=in.nextInt();
        b=in.nextInt();
        Twin_Prime gg=new Twin_Prime(a,b);
        gg.display();
    }
}
        
            
    
