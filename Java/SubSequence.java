/*This will find out all subsequences of a string
This is done using recursion.*/
import java.util.ArrayList;

public class Subsequence {
public static void main(String[] args) {
   String s="abcd";
  ArrayList<String> ls= seq(s,0);
  //to print output
  for(String st:ls){
      System.out.println(st);
  }
}
    //This method will find all subsequences
   public static ArrayList<String> seq(String s,int idx){
       if(idx==s.length()){
            ArrayList<String> ls=new ArrayList<String>();
            ls.add("");
            return ls;
       }
       ArrayList<String> ls=seq(s,idx+1);
       int l=ls.size();
       for(int i=0;i<l;i++){
           ls.add(s.charAt(idx)+ls.get(i));
       }
       return ls;
   } 
}
