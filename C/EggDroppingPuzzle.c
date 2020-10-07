/* Saurabh Vijay
   Github :- https://github.com/SaurabhVj
   Solution of Egg Dropping Puzzle
*/

#include<stdio.h>
#define INT_MAX 1e9+9 

int maxi(int a , int b)
{
   if(a >= b)
    return a ;

   return b ;
}

int solve(int eggs, int floors) 
{ 

    if (floors == 1 || floors == 0) 
        return floors; 
  
  
    if (eggs == 1) 
        return floors; 
  

    int ans = INT_MAX , possible_ans ;
    int i ;
    

    for(i = 1 ; i <= floors ; i++)
    {
      possible_ans = maxi(solve(eggs-1 , i-1) , solve(eggs , floors - i)) ;
      if(possible_ans < ans)
        ans = possible_ans ;
    }
  
    return ans + 1 ;
} 
int main() 
{ 
   int eggs,floors;
   printf("Enter the number of eggs\n") ;
   scanf("%d",&eggs);
   printf("Enter the number of floors\n");
   scanf("%d",&floors);
  

   printf("Minimum attempts required having %d eggs and %d floors are %d\n",eggs,floors,solve(eggs,floors));
    
    return 0; 
} 
