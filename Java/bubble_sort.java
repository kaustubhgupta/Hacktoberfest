import java.io.*;
class bubble_sort
{
    public static void main(String args[])throws IOException
    {
        BufferedReader buf=new BufferedReader(new InputStreamReader(System.in));
        int N;
        System.out.println("Enter the number of elements");
        N=Integer.parseInt(buf.readLine());
        int arr[]=new int[N];
        System.out.println("Enter the elements of array");
        for(int i=0;i<N;i++){
            arr[i]=Integer.parseInt(buf.readLine());
        }
        System.out.println("Original Array");
       for(int i=0;i<N;i++){
       System.out.print(arr[i]+"  ");
       }
       System.out.println();
       int temp;
       for(int i=0;i<N-1;i++){
           for(int j=0;j<N-i-1;j++){
              if(arr[j]>arr[j+1]){
              temp=arr[j];
              arr[j]=arr[j+1];
              arr[j+1]=temp;
              }
           }
       }
System.out.println("Sorted Array");
for(int i=0;i<N;i++){
  System.out.print(arr[i]+"  ");
}
System.out.println();
}}