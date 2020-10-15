//This program is used to find factorials of large numbers like 60!, 100!
//Traditional approach takes too much time to compute the factorials.
//We use basic multiplication technique of muliplying and adding carry to next number
 	
import java.io.*;
import java.util.*;
public class ExtraLongFactorial {
 
	public static void factorial(int num) {
		if(num==0){
			System.out.println(0);
			return;
		}
		int store[] = new int[1000];
		Arrays.fill(store, 0);
		store[0]=1;
		int start=2;
		int len=1;
		int temp=0; 
		int carry=0;
		while(start<=num){
			carry=0;
			temp=0;
			while(temp<len){
				store[temp]=store[temp]*start;
				store[temp]=store[temp]+carry;
				carry=store[temp]/10;
				store[temp]=store[temp]%10;
				temp++;
			}
			while(carry!=0){
				store[len]=carry%10;
				carry=carry/10;
				len++;
			}
			start++;	
		}
		for(int i=len-1;i>=0;i--){
			System.out.print(store[i]);
		}	  	
			
	}
	public static void main(String[] args) {
      
      factorial(60);
		
   }
}