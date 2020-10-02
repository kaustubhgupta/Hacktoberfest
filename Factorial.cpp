#include <iostream>
#include<iomanip>
using namespace std;
int fact(int n) 
{
   if ((n==0)||(n==1))
   return 1;
   else
   return n*fact(n-1);
}
int main() {
   int n = 5;
   cout<<"Factorial of "<<n<<" is "<<fact(n);
   return 0;
}
