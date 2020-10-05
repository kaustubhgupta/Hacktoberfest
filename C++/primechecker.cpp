// Hacktoberfest2020 Contribution by Dhrubajyoti Chakraborty
// Prime checker with time complexity O(sqrt(n))

#include <bits/stdc++.h> 
using namespace std; 
  
bool checkPrime(int n) 
{ 
    if (n <= 1)  return false; 
    if (n <= 3)  return true; 

    if (n%2 == 0 || n%3 == 0) return false; 
  
    for (int i=5; i*i<=n; i=i+6) 
        if (n%i == 0 || n%(i+2) == 0) 
           return false; 
  
    return true; 
} 
  
  
// driver function
int main() 
{ 
    int z;
    cin>>z;
    checkPrime(z)?  cout << " true\n": cout << " false\n"; 
    return 0; 
} 
