#include<iostream>
using namespace std;
int main() {
    int test, c1,c2,c3,c4, n, m, R[1005], C[1005], rcost, ccost;
    cin>>test;
    while(test--){
    	cin>>c1>>c2>>c3>>c4;//ticket price
    	cin>>n>>m;//num of rickshaw, cabs ramu is going to use
    	for(int i=0;i<n;i++){
            cin>>R[i];
        }
        for(int i=0;i<m;i++){
            cin>>C[i];
        }
        // rickshaw
        rcost = 0;
        for(int i=0;i<n;i++){
            rcost += min(c1*R[i], c2);
        }
        rcost = min(rcost, c3);

        // cabs
        ccost = 0;
        for(int i=0;i<m;i++){
            ccost += min(c1*C[i], c2);
        }
        ccost = min(ccost, c3);
        // min cost
        cout<<min(c4, rcost+ccost)<<endl;
    }
    return 0;
}

/*

Input: 
2
1 3 7 19
2 3
2 5
4 4 4
4 3 2 1
1 3
798
1 2 3
Output:
12
1

*/
