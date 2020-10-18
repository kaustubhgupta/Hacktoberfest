//Program to find Prime Factors of any number.

#include <iostream>

using namespace std;

void primeFactors(int number) 
{ 
        for (int i = 2; i <= number; i++)
        {
             while (number % i == 0)
             {
                  number /= i;
                  cout <<  i << " ";  
             }
        }     
 
} 

int main()
    {
		cout << "Enter the number ";
		int number;
		cin >> number;
        	primeFactors(number);
		return 0; 
    }
