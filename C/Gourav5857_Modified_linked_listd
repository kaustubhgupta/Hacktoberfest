#include<stdio.h>
typedef struct node
{
	int data;
	struct node*next;
}NODE;

NODE*st=NULL;

//fn to create node

NODE*createNode(int d)
{
	NODE*a;
	a=(NODE*)malloc(sizeof(NODE));
	a->data=d;
	a->next=NULL;
	return a;
	
}

//fn to display list

void display()
{
	NODE*a=st;
	if(st==NULL)
		printf("\nEmpty list");
	else
	{
		printf("\nData:\n");
		while(a!=NULL)
		{
			printf("%4d",a->data);
			a=a->next;
		}
	}	
}

//fn to retrive last node

NODE*getlastNode()
{
	NODE*a=st;
	while(a->next!=NULL)
	a=a->next;
	return a;
}

//fn to add new NODE at end

void addEnd(int d)
{
	NODE*a=createNode(d);
	NODE *b;
	if(st==NULL)
	st=a;
	else
	{
		b=getlastNode();
		b->next=a;
	}
}

//fn to add new node at begin

void addBeg(int d)
{
	NODE*a=createNode(d);
	a->next=st;
	st=a;
	
}

//fn to count Node from list

int count()
{
	NODE*a=st;
	int cnt=0;
	while(a!=NULL)
	{
		cnt++;
		a=a->next;
	}
	return cnt;
}

//fn to compute sum from list

int sum()
{
	NODE*a=st;
	int tot=0;
	while(a!=NULL)
	{
		tot = tot + a->data;
		a=a->next;
		
	}
	return tot;
}

//fn to search

int search(int sv)
{
	NODE*a=st;
	while(a!=NULL)
	{
		if(a->data==sv)
		break;
		a=a->next;
	}
	  if(a!=NULL)
	  return 1;
	  else
	  return 0;
	
}
//fn to replace
void findReplace(int sv, int rv)
{
	NODE*a=st;
	while(a!=NULL)
	{
		if(a->data==sv)
		a->data=rv;
		a=a->next;
	}
	return;
}

//fn to find max

int findMax()
{
	NODE*a=st;
	int max=a->data;
	a=a->next;
	while(a!=NULL)
	{
		if(a->data>max)
		max=a->data;
		a=a->next;
	}
	return max;
}

//fn to find min

int findMin()
{
	NODE*a=st;
	int min=a->data;
	a=a->next;
	while(a!=NULL)
	{
		if(a->data<min)
		min=a->data;
		a=a->next;
	}
	return min;
}

//fn to find odd count

int oddCnt()
{
	NODE*a=st;
	int odd=0;
	while(a!=NULL)
	{
		if(a->data%2!=0)
		odd++;
		a=a->next;
	}
	return odd;
}


//fn to find even count

int evenCnt()
{
	NODE*a=st;
	int even=0;
	while(a!=NULL)
	{
		if(a->data%2==0)
		even++;
		a=a->next;
	}
	return even;
}

//fn to check list data in ascending order

int isOrdered()
{
	NODE*a=st,*b;
	b=a;
	a=a->next;
	while(a!=NULL)
	{
		if(a->data<b->data)
		break;
		b=a;
		a=a->next;
		
	}
	if(a==NULL)
	return 1;
	else
	return 0;
}

//fn to sort list data in ascending order

void sort()
{
	NODE*a=st,*b,*c;
	int tmp;
	while(a->next!=NULL)
	{
		b=a;
		c=a->next;
		while(c!=NULL)
		{
			if(c->data<b->data)
			b=c;
			c=c->next;
		}
		if(a!=b)
		{
			tmp=a->data;
			a->data=b->data;
			b->data=tmp;
		}
		a=a->next;
	}
}

//fn to reverse the list data

void reverse()
{
	NODE*a=st,*b=NULL,*c;
	while(a!=NULL)
	{
		c=a->next;
		a->next=b;
		b=a;
		a=c;
	}
	st=b;
}

//fn of recurssion

void revdisplay(NODE*a)
{
	if(a==NULL)
	return;
	revdisplay(a->next);
	printf("%5d",a->data);
}



void main()
{
	int opt,d,res,sv,rv;
	while(1)
	{
		printf("\nMenu\n");
		printf("\n1AddEnd\n2AddBegin\n3Display\n4CountNode\n5DataSum\n6Search\n7Replace\n8Max\n9Min\n10OddCnt\n11EvenCnt\n12isOrdered\n13SortAscending\n14Reverse\n15Recurssion\n16Exit\nOption\n");
		scanf("%d",&opt);
		if(opt>15)
		break;
		switch(opt)
		{
			case 1:
				printf("\nAdd at End Data");
				scanf("%d",&d);
				addEnd(d);break;
				
				case 2:
				printf("\nAdd at Begin Data");
				scanf("%d",&d);
				addBeg(d);break;
				
				case 3:
					display();break;
					
					case 4:
						printf("\nNode Count:%d",count());
						break;
						
						case 5:
							printf("\nData sum:%d",sum());
							break;
							
							case 6:
								printf("\nEnter Search value");
								scanf("%d",&sv);
								if(search(sv)==0)
								printf("Not" );
								printf("Found");
								break;
								
								case 7:
									printf("\nEnter search value");
									scanf("%d",&sv);
									printf("\nReplace Value");
									scanf("%d",&rv);
									findReplace(sv,rv);
									break;
									
									case 8:
										printf("\nMax:%d",findMax);
										break;
										
										case 9:
										printf("\nMin:%d",findMin);
										break;
										
										case 10:
											printf("\nOdd count:%d",oddCnt());
											break;
											
										case 11:
											printf("\nEven count:%d",evenCnt());
										    break;
										    
										case 12:
											if(st==NULL)
											printf("\nEmpty List");
											else
											{
												if(isOrdered()==0)
												printf("\nNot Ordered");
												else
												printf("\nOrdered");
											}
											break;
											
											case 13:
												sort();
												break;
												
												case 14:
													reverse();
													break;
													
												case 15:
													revdisplay(st);
													
			}
	}
}
