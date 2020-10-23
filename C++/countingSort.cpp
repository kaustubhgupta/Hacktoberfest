//  A program implementing the counting sort algorithm in C++.

#include<iostream>
using namespace std;

int main() {
    int size, max=0;
    cout << "Enter the number of digits to be sorted: ";
    cin >> size;                                                //  Taking input for number of elements to be sorted.
    int input[size], output[size];
    cout << "Enter the digits: ";                               //  Taking input for actual elements.
    for(int i=0 ; i<size ; i++) {
        cin >> input[i];
        if (input[i] > max)
            max = input[i];                                     //  Simultaneously calculating the maximum value.
    }

    int frequency[max];                                         //  Initializing an array to holds frequencies.
    for(int i=0 ; i<max ; i++)
        frequency[i] = 0;                                       //  Setting the frequencies to zero.
    for(int i=0 ; i<size ; i++)
        frequency[input[i]-1]++;                                //  Incrementing frequency of the respective element.
    for(int i=1 ; i<max ; i++)
        frequency[i] = frequency[i] + frequency[i-1];           //  Calculating cumulative frequencies.
    for(int i=size-1 ; i>=0 ; i--) {
        output[frequency[input[i] - 1] - 1] = input[i];         //  Generating the output array by considering the cumulative frequencies. 
        frequency[input[i] - 1]--;
    }

    cout << "Sorted sequence: ";
    for(int i=0 ; i<size ; i++)                                 //  Printing out the sorted sequence of elements.
        cout << output[i] << ' ';
    
    return 0;
}
