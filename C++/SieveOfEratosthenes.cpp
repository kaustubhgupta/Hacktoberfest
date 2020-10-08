// An Algorithm to print all prime numbers less than or equal to a given number.
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void SieveofEratosthenes(int n){
    int a[n-2],p=2; //a is an array of all integers from 2 to n, p is the iterator
    for(int i=0;i<n-2;i++){
      a[i]=i+2;
    }
    bool prime[n-2]; //true if a number is prime
    for(int i=0;i<n-2;i++){
      prime[i]=true;
    }
    for (int p=2; p*p<=n; p++) {//multiples of p
      if (prime[p] == true) {
        for(int j=p*p;j<=n;j+=p){
          prime[j]=false;
        }  
      }
    }
    for (int p=2; p<=n; p++) 
      if (prime[p]) 
        cout << p <<endl; 
}
int main() {
  int n=20;
  SieveofEratosthenes(n);
  return 0;
}
