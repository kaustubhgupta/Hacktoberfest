#include<stdio.h> 
struct node 
{ 
 struct node *left; 
 struct node *right; 
 int data; 
}; 
struct node *ptr; 
 struct node *root=NULL; 
struct node* insert(struct node *root,int info) 
{ 
 if(root = = NULL) 
 { 
 root=(struct node*)malloc(sizeof(struct node)); 
 (root)->data=info; 
 (root)->left=NULL; 
 (root)->right=NULL; 
 } 17
19
 22 
 17 
 6 
 3 
 8
 2 
 14
 6 
 17 
 19 
 17 
 19 
 14 
 6 
 3 
 17 
19
 22 
 6 
 3 
Valid BST Valid BST Valid BST Valid BST 
 Valid BST Invalid BST as the right child of 6 which is 22, is 
 greater than the root 17. All nodes towards left of 
 17 should be lesser than 17. 
 else 
 { 
 if(info<(root)->data) 
 { 
 root->left=insert(root->left,info); 
 } 
 else 
 { 
 root->right=insert(root->right,info); 
 } 
 } 
 return root; 
} 
void inorder(struct node *root) 
{ 
 if(root!=NULL) 
 { 
 inorder(root->left); 
 printf("%d ",root->data); 
 inorder(root->right); 
 } 
 
} 
void preorder(struct node *root) 
{ 
 if(root!=NULL) 
 { 
 printf("%d ",root->data); 
 preorder(root->left); 
 preorder(root->right); 
 } 
 } 
void postorder(struct node *root) 
{ 
 if(root!=NULL) 
 { 
 postorder(root->left); 
 postorder(root->right); 
 printf("%d ",root->data); 
 } 
} 
struct node* inordersucc(struct node *isucc) 
{ 
 if(isucc==NULL) 
 return NULL; 
 while(isucc->left!=NULL) 
 isucc =isucc->left; 
 return isucc; 
} 
struct node* del(struct node *root,int info) 
{ 
 struct node *temp; 
 if(root==NULL)
 printf("element not present in the tree\n"); 
 else if(info<root->data) 
 root->left=del(root->left,info); 
 else if(info>root->data) 
 root->right=del(root->right,info); 
 else 
 { 
 if(root->left!=NULL && root->right!=NULL) 
 { 
 temp=inordersucc(root->right); 
 root->data=temp->data; 
 root->right=del(root->right,root->data); 
 } 
 else 
 { 
 temp=root; 
 if(root->left!=NULL) 
 root=root->left; 
 else if(root->right!=NULL) 
 root=root->right; 
 else 
 root=NULL; 
 free(temp); 
 } 
 } 
 return root; 
} 
int main() 
{ 
 int choice,info,count=0; 
 printf("enter the data to be inserted\n"); 
 scanf("%d",&info); 
 root=insert(root,info); 
 do 
 { 
 printf("do u want to continue\n1-insert 2-delete\n"); 
 printf("3-preorder 4-inorder 5-postorder 6-exit\n"); 
 scanf("%d",&choice); 
 switch(choice) 
 { 
 case 1: printf("enter the data to be inserted\n"); 
 scanf("%d",&info); 
 insert(root,info); 
 
 break; 
 case 2: printf("enter the value to be deleted\n"); 
 scanf("%d",&info); 
 root=del(root,info); 
 break; 
 case 3: preorder(root); 
 break; 
 case 4: inorder(root); 
 break; 
 case 5: postorder(root);
 break; 
 case 6: exit(0); 
 } 
 }while(choice!=6); 
}
