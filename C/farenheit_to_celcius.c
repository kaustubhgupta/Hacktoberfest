#include<stdio.h>
int main(){
    float celsius,fahrenheit;

    //Taking input in fahrenheit
    printf("\nEnter temperature in Fahrenheit: ");
    scanf("%f",&fahrenheit);
 
    //Formula to convert temperature in fahrenheit to celcius
    celsius=(fahrenheit - 32)*5/9;

    //printing the temperature in celcius
    printf("\nCelsius = %.3f\n",celsius);
    return 0;
}