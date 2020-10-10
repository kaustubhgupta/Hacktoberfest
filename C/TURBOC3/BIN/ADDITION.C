#include<iostream.h>
#include<stdio.h>
struct sparse
{
 int row,col,val;
 };
 void readmat(sparse sp[])
 {
   printf("enter total number of rows,column and total nonzero value \n");
   scanf("%d %d %d",&sp[0].row,&sp[0].col,&sp[0].val);
   printf("now start entering the values\n");
   for(int i=1;i<=sp[0].val;i++)
   scanf("%d %d %d",&sp[i].row,&sp[i]