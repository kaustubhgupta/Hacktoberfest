#include<stdio.h>
int main(){
    float celsius, fahrenheit;
    int choice;

    //Taking input for conversion
    printf("\nEnter:\t 1 - Fahrenheit to Celsius");
    printf("\nEnter:\t 2 - Celsius to Fahrenheit");
    printf("\nEnter your choice:\n");
    scanf("%d",&choice);
    
    
    //Taking input for temperature conversion
    
    switch(choice)
    {
         case 1:
            printf("Enter the value of Fahrenheit temperature:");
            scanf("%f", &fahrenheit);
            //Formula to convert temperature in fahrenheit to celsius
            celsius=(fahrenheit - 32)*5/9;
            //printing the temperature in celcius
            printf("\nCelsius = %.3f\n",celsius);
            break;
         case 2:
            printf("Enter the value of Celsius temperature:\t");
            scanf("%f", &celsius);
            //Formula to convert temperature in celsius to fahrenheit
            fahrenheit = celsius*(9/5) + 32;
            //printing the temperature in fahrenheit
            printf("\nFahrenheit= %.3f\n",fahrenheit);
            break;
         default:
            printf("\n\nWrong Choice.....Try Again!!!\n");
    }
    
         return 0;   
    }           
              
