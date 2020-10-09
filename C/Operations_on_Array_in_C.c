#include<stdio.h>
#include<stdlib.h>
printArr(int n, int *m)
{
	printf("\nThe Array is:\t");
	for(int i=0;i<n;i++)
		{
			printf("%d\t", *m);
			m++;
		}
}
main()
{
	int i, arr[100], noEle, b, c, d, e, f, j,  x, t;
	printf("\t\t\tOPERATIONS ON ARRAY DATA STRUCTURE");
	printf("\nEnter the Number of Elements for the Array: ");
	scanf("%d",&noEle);
	printf("Enter the elements:\n");
	for(i=0;i<noEle;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("\n\nChoose the Operation to Perform on the Array:\n1. Traverse\n2. Insert\n3. Deletion\n4. Search\n5. Sort\n");
    scanf("%d",&b);	
    switch(b)
    {
    	case 1:
    		printf("\n\n\tTRAVERSING:");
    		printArr(noEle, arr);
    		break;
		case 2:
			printf("\n\n\tINSERTION");
			printArr(noEle, arr);
			printf("\nEnter the Value to be added: ");
			scanf("%d",&c);
			printf("\nEnter the Position to which %d has to added: ",c);
			scanf("%d",&d);
			for(i=noEle;i>=b;i--)
			{
				arr[i]=arr[i-1];
			}
			arr[d-1]=c;
			printf("\nInsertion\nThe updated elements are:\t");
			for(i=0;i<noEle+1;i++)
			{
				printf("%d\t",arr[i]);
			}
			break;
		case 3:
			printf("\n\n\tDELETION");
			printArr(noEle, arr);
			printf("\nEnter the Position of the Element to be deleted:");
			scanf("%d",&e);
			for(i=e-1;i<noEle-1;i++)
			{
				arr[i]=arr[i+1];
			}
			printf("\nDeletion\nThe updated elements are:\t");
			for(i=0;i<noEle-1;i++)
			{
				printf("%d\t",arr[i]);
			}
			break;
		case 4:
			printf("\n\n\tSEARCH");
			printArr(noEle, arr);
			printf("\nEnter the Element to be searched:");
			scanf("%d",&f);
			for(i=0;i<noEle;i++)
			{
				if(f==arr[i])
				{
					printf("The element %d is at location %d of the array.",f,i+1);
					x=1;
					break;
				}
			}
			if(x!=1)
				{
					printf("The value %d is not present in the array.",f);
				}
			break;
		case 5:
			printf("\n\n\tSORT");
			printArr(noEle, arr);
			for (i=1;i<=noEle-1;i++)
		    {
			    j=i;
				while ( j > 0 && arr[j-1] > arr[j])
				{	        
		            t=arr[j];
		            arr[j]=arr[j-1];
		            arr[j-1]=t;
		            j--;
		        }
		    }
		    printf("\nThe Sorted Array is:\t");
			for(i=0;i<noEle;i++)
			{
				printf("%d\t",arr[i]);
			}
			break;
	}
}