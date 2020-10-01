#include <iostream>
#include <map>
using namespace std;
int main() {
    string s;
    int count = 0;
    map<char,int> mark;
    cin >> s;
    for(int i = 0; i < s.size(); i++){
        if(!mark[s[i]]){
            mark[s[i]] = 1;
            count++;
        }
    }
    cout << "There are " << count << " distinct characters." << endl;
}