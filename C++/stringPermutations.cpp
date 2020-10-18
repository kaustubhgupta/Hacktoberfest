#include <string>
#include <iostream>
using namespace std;


void permutation(string prefix, string suffix){
    if (suffix.length() == 0) cout << prefix << endl;

    int length = suffix.length();
    for (int i = 0 ; i < length; ++i){
        string before = suffix.substr(0,i);
        string after = suffix.substr(i+1,length);
        char cand = suffix[i];

        // Pass result down the stack
        permutation(prefix + cand, before + after);
    }
}


int main(){
    string test_string = "ABCDE";
    permutation(string(""), test_string);
}