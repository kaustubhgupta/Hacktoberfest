//Program to find what all permutation can be made from a string using recursion.

import java.util.*;
import java.io.*;

public class PermutaionOfString{

static void findAllPermutation(int start,String s) {
    char[] chr=s.toCharArray();
    if(start==s.length()){
        System.out.println(s);
	}	
    for(int i=start;i<s.length();i++) {
        char temp=chr[i];
        chr[i]=chr[start];
        chr[start]=temp;
        findAllPermutation(start+1,new String(chr));
    }   
}
public static void main(String args[]) {
    findAllPermutation(0,"ABC");
}
}