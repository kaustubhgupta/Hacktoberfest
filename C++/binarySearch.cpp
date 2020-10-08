#include <iostream>

using namespace std;

//arr is array of integers, length is size of array, x is value to search
int binarySearch(int arr[], int length, int x) {
    //setting equal to index of first element
    int left = 0; 

    //setting equal to index of last element
    int right = length - 1;

    //approx average of left and right calculated during each iteration
    int middle;

    while (left <= right) {
        //calculate middle
        middle = (left + right) / 2;

        //if middle element is equal to x
        if (arr[middle] == x) { 
            //return middle(index)
            return middle; 
        } 
        //if element is greater than middle change constraints, since element is greater than middle set left equal to middle and new middle is calculated accordingly
        else if (x > arr[middle]) {
            left = middle + 1;
        }
        //if element is smaller than middle change constraints, since element is smaller than middle set right equal to middle and new middle is calculated accordingly
        else {
            right = middle - 1;
        }
    }

    return -1; //if not found return -1
}

int main() {
    int arr[] = { 45, 98, 123, 147, 265, 308};

    //test cases
    cout << binarySearch(arr, 6, 123)<<endl;
    cout << binarySearch(arr, 6, 308)<<endl;
    cout << binarySearch(arr, 6, 45)<<endl;
    cout << binarySearch(arr, 6, 50)<<endl;

    return 0;
}
