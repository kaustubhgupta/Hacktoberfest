/* https://www.geeksforgeeks.org/equilibrium-index-of-an-array/ */

#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define cyes cout << "YES" << endl
#define cno cout << "NO" << endl
#define f(i, a, n) for(int i = a; i < n; i++)
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define mod 1000000007
int gcd(int a, int b) { if (!b) return a; return gcd(b, a % b); }  
int lcm(int a, int b) { return (a * b) / gcd(a, b); }
using namespace std;

int equilibrium(int arr[], int n)  
{  
    int sum = 0; 
    int leftsum = 0;  

    for (int i = 0; i < n; ++i)  
        sum += arr[i];  
  
    for (int i = 0; i < n; ++i)  
    {  
        sum -= arr[i]; 
  
        if (leftsum == sum)  
            return i+1;  
  
        leftsum += arr[i];  
    }  
    return -1;  
}  


int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  int t; cin >> t;
  while(t--){
    int n; cin >> n;
    int a[n];

    for(int i=0;i<n;i++){
      cin >> a[i];
      }

      cout <<  equilibrium(a,n) << endl;
    }
  }
