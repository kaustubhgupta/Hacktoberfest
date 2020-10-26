#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


bool cmp(Item a,Item b){
    double x1=(double)a.value/a.weight;
    double x2=(double)b.value/b.weight;
    return x1>x2;
}

// function to return fractionalweights

double fractionalKnapsack(int W, Item arr[], int n)
{
    sort(arr,arr+n,cmp);
    double ans=0.0,cap=W;
    for(int i=0;i<n;i++){
        if(cap>=arr[i].weight){
            ans+=arr[i].value;
            cap-=arr[i].weight;
        }
        else{
            ans+=((double)cap/arr[i].weight)*arr[i].value;
            cap=0;
            break;
        }
    }
    return ans;
}

int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		cout<<fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
} 
