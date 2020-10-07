#include<bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t; cin>>t;
	while(t--){
	    int n, k;
	    cin >> n >> k;
	    vector <int> arr(n);
	    for (int i  =0 ; i < n; i++) cin >> arr[i];
	    list<int> dq;
	    for (int i = 0; i < k; i++) {
	        while (dq.size() > 0 && arr[dq.back()] < arr[i]) dq.pop_back();
	        dq.push_back(i);
	    }
	    
	    for (int i = k; i < n; i++) {
            int idx = dq.front();  
	        cout << arr[idx] << " ";
	        if (idx < i - k + 1) dq.pop_front();
	        while (dq.size() > 0 && arr[dq.back()] < arr[i]) dq.pop_back();
	        dq.push_back(i);
	    }
	    int idx = dq.front();  
	    cout << arr[idx] << endl;
	  
	}
	return 0;
}