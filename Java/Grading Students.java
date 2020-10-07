import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {
public static void main(String[] args) {
   Scanner in = new Scanner(System.in);
  int n = in.nextInt();
  int[] grades = new int[n];
 
   for(int grades_i=0; grades_i < n; grades_i++){
    grades[grades_i] = in.nextInt();
 }
 
  for(int i=0;i<n;i++)
  {
    if(grades[i]< 38)
      continue;
      if(grades[i]%5>=3)
         grades[i]=grades[i]+(5-grades[i]%5);
      else
        continue;
 }
 
  for(int i=0;i<n;i++)
    {
        System.out.println(grades[i]);
      }
 }
}
