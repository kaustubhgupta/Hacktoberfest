/* Contributed by Dhrubajyoti Chakraborty */
/* Egg Drop Puzzle Solution */

#include <bits/stdc++.h> 
using namespace std; 
  
int max(int a, int b) 
{ 
    return (a > b) ? a : b; 
} 

int eggDrop(int n, int k) 
{ 

    if (k == 1 || k == 0) 
        return k; 
  
  
    if (n == 1) 
        return k; 
  
    int min = INT_MAX, x, res; 
  
    
    for (x = 1; x <= k; x++) { 
        res = max( 
            eggDrop(n - 1, x - 1), 
            eggDrop(n, k - x)); 
        if (res < min) 
            min = res; 
    } 
  
    return min + 1; 
} 
int main() 
{ 
   int n,k;
  cin>>n>>endl;
  cin>>k;
    cout << "Min trials "
            "worst case with "
         << n << " eggs and " << k 
         << " floors : "
         << eggDrop(n, k) << endl; 
    return 0; 
} 
