import java.util.*;

//finds all possible continuous subsequences of a string and prints the ones which are a palindrome
public class PalindromeSubSequence {
      
    static boolean isPalindrome(String str){ 

        StringBuffer sbr = new StringBuffer(str);

        // Compare reverse and actual string 
        return str.compareTo(sbr.reverse().toString()) == 0;
    } 


    //recursively get all sub sequence
    static void printPalindromicSubSeq(String str, int n, int index, String temp) 
    { 
        // base condition
        if (index == n) { 
            return; 
        } 
        if (temp != null) { 
            //print if its a palindrome
            if(isPalindrome(temp))
                System.out.println(temp); 
        } 
        for (int i = index + 1; i < n; i++) { 
            temp += str.charAt(i); 

            // backtracking , remove last character to generate new sub sequence
            printPalindromicSubSeq(str, n, i, temp); 
            temp = temp.substring(0, temp.length() - 1); 
        } 
    } 
      

    public static void main(String args[]) throws Exception { 
        
        String str = "abhcddfga"; 
        int n = str.length();

        printPalindromicSubSeq(str, n, -1, "");
    } 
}