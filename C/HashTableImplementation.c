//Implementation of hashtable in C language
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
typedef struct node{
	int data;
	struct node* next;
}node;
node* createNode(int data){
	node* temp = (node *) malloc(sizeof(node));
	temp->data = data;
	temp->next = NULL;
	return temp;
}
//Very simple hashfunction
int hashFunction(int key, int base){
	return key % base;
}
//Function to make everything null before adding any values into hashtable
void hashTableNull(node* hashTable[], int n){
	for(int i=0; i<n; i++){
		hashTable[i] = NULL;
	}
}
//Utility function to add data into hashtable
void insert(int data, node* hashTable[], int base){
	int index = hashFunction(data, base);
	if(hashTable[index] == NULL){
		hashTable[index] = createNode(data);
	}else{
		node* temp = createNode(data);
		node* prev = hashTable[index];
		temp->next = prev;
		hashTable[index] = temp;	
	}
}
void printHashTable(node* hashTable[], int n){
	for(int i=0; i<n; i++){
		node* temp = hashTable[i];
		printf("%d ==> ", i + 1);
		while(temp!=NULL){
			printf("%d ", temp->data);
			temp = temp->next;
		}
		printf("\n");
	}
}
int search(int data, node* hashTable[], int base){
	int index = hashFunction(data, base);
	if(hashTable[index] == NULL){
		return 0;
	}else{
		node* temp = hashTable[index];
		while(temp!=NULL){
			if(temp->data == data)
				return 1;
			temp = temp->next;
		}
		return 0;
	}
}
int delete(int data,  node* root[], int base){
    node* temp;
    node* prevNode;
    int index = hashFunction(data, base);
    prevNode = root[index];
    temp = root[index]->next;
    if(prevNode!=NULL){
        if(prevNode->data == data){
        	prevNode = temp;
        	free(temp);
            return 1;
        }
        while(temp != NULL){
            if(temp->data == data){
                prevNode->next = temp->next;
                free(temp);
                return 1;
            }
            temp = temp->next;
            prevNode = prevNode->next;
        }
    }
    else{
        return 0;
    }
}
int main(){
	int base = 10; // Took default base as 10 it can be any value
	node* hashTable[base]; //Initializing hash table
	hashTableNull(hashTable, base); //making it null before insertion
	for(int i=0; i<50; i++)
		insert(rand()%100+1, hashTable, base);
	printHashTable(hashTable, base);
}