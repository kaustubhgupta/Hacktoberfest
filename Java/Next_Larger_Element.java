import java.util.*;
class Next_Larger_Element
{
    Scanner sc=new Scanner(System.in);
    int max=1000;
    int top=-1;
    int[] stack=new int[1000];
    int push(int x)
    {
        if(top==max-1)
        {
            System.out.println("Stack Overflow");
        }
        else
        {
            stack[++top]=x;
        }
        return(top);
    }
    int pop(int x)
    {
        while(top>=0 && stack[top]<x)
        {
           System.out.print(x+" ");
           top--;
        }
        stack[++top]=x;
        return(top);
    }
    void main()
    {
        Next_Larger_Element obj=new Next_Larger_Element();
        int t;
        t=sc.nextInt();
        int i,dig;
        while(t-->0)
        {
            int topi=-1;
            int n=sc.nextInt();
            for(i=0;i<n;i++)
            {
                dig=sc.nextInt();
                if(topi==-1)
                {
                    topi=obj.push(dig);
                }
                else if(stack[topi]>dig)
                {
                    topi=obj.push(dig);
                }
                else if(stack[topi]<dig)
                {
                    topi=obj.pop(dig);
                }
            }
            for(int j=0;j<=topi;j++)
            {
                System.out.print("-1 ");
            }
            obj.top=-1;
            topi=-1;
        }
    }
}
        
  