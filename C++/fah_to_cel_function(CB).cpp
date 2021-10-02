#include<iostream>
#include<iomanip>
using namespace std;
void fahToCel(int f,int steps){
    for(;f<=300;f+=steps){
        float c = 5*(f-32)/9.0;
        cout<<f<<" deg. F in Celcius is "<<fixed<<setprecision(2)<<c<<" deg. C."<<endl;
    }
    return;
}
int main(){
    fahToCel(100,50);
    cout<<endl;
    fahToCel(200,10);
}
