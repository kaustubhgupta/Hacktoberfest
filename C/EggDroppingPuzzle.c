/* Saurabh Vijay
   Github :- https://github.com/SaurabhVj
   Solution of Egg Dropping Puzzle
*/

#include<stdio.h>
#define INT_MAX 1e9+9 

int max(int a , int b)
{
   if(a >= b)
    return a ;

   return b ;
}

int EggDroppingPuzzle(int eggs, int floors) 
{ 
   //Function to calculate the minimum number of attempts
    if (floors == 1 || floors == 0) 
        return floors; 
  
  
    if (eggs == 1) 
        return floors; 
  

    int ans = INT_MAX , possible_ans ;
    int i ;
    

    for(i = 1 ; i <= floors ; i++)
    {
      possible_ans = max(EggDroppingPuzzle(eggs-1 , i-1) , EggDroppingPuzzle(eggs , floors - i)) ;
      if(possible_ans < ans)
        ans = possible_ans ;
    }
  
    return ans + 1 ;
} 
int main() 
{ 
   int eggs,floors;
   
   //Input Number of Eggs here
   printf("Enter the number of eggs\n") ;
   scanf("%d",&eggs);
   
   //Input Number of Floors here
   printf("Enter the number of floors\n");
   scanf("%d",&floors);
  
   //Output Minimum number of attempts required
   printf("Minimum attempts required having %d eggs and %d floors are %d\n",eggs,floors,EggDroppingPuzzle(eggs,floors));
    
    return 0; 
} 
