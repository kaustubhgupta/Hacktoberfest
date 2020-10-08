#include <iostream>

using namespace std;

//arr is array of integers, length is size of array, x is value to search
int linearSearch(int arr[], int length, int x) {
    bool flag = false; //set to true if found
    int i; //return the index

    //iterating over array in given size/length
    for (i = 0; i < length; i++) {
        if (arr[i] == x) {
            flag = true;
            break;
        }
    }
    //if found return index else -1
    if (flag == true) {
        return i;
    } else {
        return -1;
    }
}

int main() {
    int arr[] = { 9, 2, 3, 4, 5, 8, 6};
    //test cases
    cout << linearSearch(arr, 7, 8)<<endl;
    cout << linearSearch(arr, 7, 6)<<endl;
    cout << linearSearch(arr, 7, 9)<<endl;
    cout << linearSearch(arr, 7, 50)<<endl;
    return 0;
}