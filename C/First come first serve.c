#include<stdio.h>
struct Process{
int p,bt,ct,tt,wt,at;
}temp;
void main()
{ struct Process P[20];
int n,i,j,ct,tat,wt,ct1;
float awt,atat;
printf("Enter the number of processes");
scanf("%d",&n );
printf("Enter the processes, arrival time and busrt time\n" );
for (i=0;i<n;i++)
{
P[i].ct=0;
P[i].tt=0;
P[i].wt=0;
}
for (i=0;i<n;i++)
{ printf("Process");
scanf("%d",&P[i].p);
printf("Arrival time");
scanf("%d",&P[i].at );
printf("Burst time");
scanf("%d",&P[i].bt );
}
for(i=0;i<n;i++)
{
for(j=i+1;j<n;j++)
{
if(P[i].at>P[j].at)
{
temp=P[i];
P[i]=P[j];
P[j]=temp;
}
}
}
tat=0;
wt=0;
awt=0;
ct1=0;
for(i=0;i<n;i++)
{ if(i==0)
{
P[i].wt=0;
}
P[i].ct=ct1+P[i].bt;
ct1=P[i].ct;
}
for(i=0;i<n;i++)
{
P[i].tt=P[i].ct-P[i].at;
P[i].wt=P[i].tt-P[i].bt;
tat=P[i].tt+tat;
wt=P[i].wt+wt;
} atat=(float)tat/n;
awt=(float)wt/n;
printf("Results \n" );
printf("Process\tAT\tBT\tCT\tTAT\tWT \n" );
for(i=0;i<n;i++)
{
printf("%d \t%d\t%d\t %d\ %d\t%d\n",P[i].p,P[i].at,P[i].bt,P[i].ct,P[i].tt,P[i].wt);
}
printf("\n");
printf("Average turn around time : %f \n Average waiting time : %f",atat,awt);
}
