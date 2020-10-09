// CPP code to generate power set of a string
#include <iostream>
#include <string>
using std::string;

// Builds two trees recursively for every index of input string until 
// base case is reached where the accumulated subset is printed out
void powerSet(string str, int index, string current_substring){
    int len =  str.length();

    // Base case 
    if (index == len){
        if (current_substring == ""){ // Ensures "Empty set" is printed out instead of a space
            std::cout << "Empty set" << std::endl;
            return;
        }
        std::cout << current_substring << std::endl; 
        return;
    }

    char & candidate = str[index];
    // Two cases are considered for every candidate:
    // 1). The candidate is included in the substring and
    // the rest of the string is recursed upon
    // 2). The candidate is not included

    powerSet(str, index + 1, current_substring + candidate);
    powerSet(str, index + 1, current_substring);
}


int main(){
    string str;
    std::cin >> str; // User input expected from standard input stream

    // str: Stores input string
    // current_substring: Stores current subset  
    // index: Index in each character in the input string
    int index = 0;
    string current_substring = "";
    powerSet(str,index,current_substring);

    return 0;
}