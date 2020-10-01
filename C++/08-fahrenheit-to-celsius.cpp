#include<iostream>
using namespace std;
int main() {
    int start=0, stop, step;
    cout<<"Enter min F: ";
    cin>>start;
    cout<<"Enter max F: ";
    cin>>stop;
    cout<<"Enter steps: ";
    cin>>step;
    while(start<=stop){
        cout<<start<<" "<<(int)((5/9.0)*(start-32))<<endl;
        start+=step;
    }
    return 0;
}

/*

Input: 
    0 
    100 
    20
Output:
    0 -17 
    20 -6 
    40 4 
    60 15 
    80 26 
    100 37

*/
