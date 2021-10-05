#include <stdio.h>
#include <iostream>
using namespace std;

static int count=0;
int towerOfHanoi(int n,char a,char b,char c){
    {
        if (n == 1)
        {
            cout<<"Move Disk from " << a << " to " << c<<endl;
            count++;
        }
        else {
            towerOfHanoi(n - 1, a, c, b);
            towerOfHanoi(1, a, b, c);
            towerOfHanoi(n - 1, b, a, c);
            
        }
        return count; 
    }
}
int main(){
    int n;
    cout<<"Enter the number of disks: "<<endl;
    cin>>n;
    int a = towerOfHanoi(n,'A','B','C');
    cout<<"Total number of moves = "<<a;
    return 0;
}
