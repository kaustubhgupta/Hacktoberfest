#include<iostream>
using namespace std;
void fahToCel(int f,int steps){
    for(;f<=300;f+=steps){
        int c = 5*(f-32)/9;
        cout<<f<<" "<<c<<endl;
    }
    return;
}
int main(){
    fahToCel(100,50);
    cout<<endl;
    fahToCel(200,10);
}
