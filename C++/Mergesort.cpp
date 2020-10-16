#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define llu unsigned long long
#define pb push_back
#define eb emplace_back
#define ll long long
#define fir first
#define sec second
#define f(i,a,b) for(ll i=a;i<b;i++)
#define fs(i, s) for(ll i=0;s[i]!='\0';i++)
#define fr(i,a,b) for(ll i=a;i>=b;i--)
#define gcd(a,b) __gcd(a,b)
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define c1(x) __builtin_popcountll(x)
#define setprs(x) cout << fixed << setprecision(x);
#define nl '\n'
const ll mod = 1e9 + 7;
const ll mod2 = 998244353;
const ll sz = 1e5 + 100;
const double PI = 3.14159265;
ll power(ll a, ll b, ll m = mod){if(b==0)return 1;else if(b==1)return a%m;else{ll t=power(a,b>>1,m);t=(t * t)%m;if(b&1)return (t * a)%m;else return t;}}
//--------------------------------------------------------
#define int long long
#define Max 100
//Merge gunction which merges two sorted lists
void merge(int List_A[],int lb,int mid,int ub)
{
    int i=lb,j=mid+1,k=0,List_B[ub-lb+1];
    while(i<=mid && j<=ub)
    {
        if(List_A[i]<List_A[j])
        {
            List_B[k++]=List_A[i];
            i++;
        }
        else
        {
            List_B[k++]=List_A[j];
            j++;
        }
    }
    while(i<=mid)
    {
        List_B[k++]=List_A[i++];
    }
    while(j<=ub)
    {
        List_B[k++]=List_A[j++];   
    }
   // for(int temp=lb;temp<=ub;temp++)
    //List_A[k++]=List_B[temp];
    for(int temp=lb;temp<=ub;temp++)
    List_A[temp]=List_B[temp-lb];
}
//Recurive mergesort which partitions an array into 2 halves and sorts them recursively
void mergesort(int List_A[],int lb,int ub)
{
    if(lb<ub)
    {
        int mid=(lb+ub)/2;
        mergesort(List_A,lb,mid);
        mergesort(List_A,mid+1,ub);
        merge(List_A,lb,mid,ub);
    }
}
int32_t main()
{
    fastio
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n1;
    cin>>n1;
    int List_A[n1];
    for(int i=0;i<n1;i++)
    cin>>List_A[i];
    mergesort(List_A,0,n1-1);
    for(int i=0;i<n1;i++)
    {
        cout<<List_A[i]<<" ";
    }
    cout<<"\n";
    return 0;
}