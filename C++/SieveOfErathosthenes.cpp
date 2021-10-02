/* This is a standard algorithm to find all prime numbers uptill n */
#include<iostream>
using namespace std;

//Function to calculate all primes using Sieve of Erathosthenes
void SieveOfErathosthenes(int n)
{
   bool arr[n+2];//arr[i] wiil be true if i is prime and false if i is not prime

   //initially initialising all the indices of arr as true
   for(int i=0;i<=n;i++)
   arr[i]=true;

   arr[0]=arr[1]=false;//since 0 and 1 are not prime, hence marking the respective indices as false


   for(int i=2;i<=n;i++)
   {
       if(arr[i]==true)
       {
           //if i is prime then all its multiple will be non prime. Hence marking them as false.
           //the multiples lesser than i*i have already been marked by the previous prime numbers. Hence only multiples greater than or equal ti i*i need to be marked
           for(int j=i*i;j<=n;j+=i)
           arr[j]=false;
       }
   }

//The indices which remain true are the prime numbers
   for(int i=1;i<=n;i++)
   {
       if(arr[i]==true)
       cout<<i<<" ";
   }
}

int main()
{
    int n;
    cout<<"Enter a number:\n";
    cin>>n;//user input
    SieveOfErathosthenes(n);
    return 0;
}

/*
Input: 50
Output: 2 3 5 7 11 13 17 19 23 29 31 37 41 43 47
*/

/*
Time Complexity: O(nlog(log(n)))
Space Complexity: O(n)
*/
