import java.util.Scanner;
// Other imports go here, Do NOT change the class name
class Main
{
  public static void main(String[] args)
  {
    
    Scanner obj=new Scanner(System.in);
    int t=obj.nextInt();
    for(int s=0;s<t;s++)
    {
      int r1=obj.nextInt();
      int c1=obj.nextInt();
      int a[][]=new int[r1][c1];
      for(int i=0;i<r1;i++)
      {
        for(int j=0;j<c1;j++)
        {
          a[i][j]=obj.nextInt();
        }
      }
      
       int r2=obj.nextInt();
      int c2=obj.nextInt();
      int b[][]=new int[r2][c2];
      for(int i=0;i<r2;i++)
      {
        for(int j=0;j<c2;j++)
        {
          b[i][j]=obj.nextInt();
        }
      }
      int c[][]=new int[r1][c2];
      if(c1==r2)
      {
        for(int i=0;i<r1;i++)
        {
          for(int j=0;j<c2;j++)
          {
            for(int k=0;k<c1;k++)
            {
              c[i][j]=c[i][j] + a[i][k]*b[k][j];
            }
          }
        }
      }
      
      for(int i=0;i<r1;i++)
      {
        for(int j=0;j<c2;j++)
        {
          System.out.print(c[i][j]+" ");
        }
        System.out.print("\n");
      }
      
       for(int i=0;i<r1;i++)
      {
        for(int j=0;j<c2;j++)
        {
         c[i][j]=0;
        }
      }
    }
  }
}