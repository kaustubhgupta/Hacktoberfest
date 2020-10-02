
#include <bits/stdc++.h>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

// Create a node
struct node *newNode(int item) {
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->key = item;
  temp->left = temp->right = NULL;
  return temp;
}

// Inorder Traversal
void inorder(struct node *root) {
  if (root != NULL) {
    // Traverse left
    inorder(root->left);

    // Traverse root
    cout << root->key << " -> ";

    // Traverse right
    inorder(root->right);
  }
}

//Preorder Traversal
void preorder(struct node *root) {
  if (root != NULL) {
  	// Traverse root
    cout << root->key << " -> ";
    // Traverse left
    preorder(root->left);
    // Traverse right
    preorder(root->right);
  }
}

//Postorder Traversal
void postorder(struct node *root) {
  if (root != NULL) {
  	
    // Traverse left
    postorder(root->left);
    // Traverse right
    postorder(root->right);
    // Traverse root
    cout << root->key << " -> ";
  }
}
//search a node
struct node* searchNode(struct node* root, int key) 
{ 
    // Base Cases: root is null or key is present at root 
    if (root == NULL || root->key == key) 
       return root; 
     
    // Key is greater than root's key 
    if (root->key < key) 
       return searchNode(root->right, key); 
  
    // Key is smaller than root's key 
    return searchNode(root->left, key); 
} 

// Find the inorder successor
struct node *minValueNode(struct node *node) {
  struct node *current = node;

  // Find the leftmost leaf
  while (current && current->left != NULL)
    current = current->left;

  return current;
}

// Insert a node
struct node* insertNode(struct node* node, int key) 
{ 
    /* If the tree is empty, return a new node */
    if (node == NULL) return newNode(key); 
  
    /* Otherwise, recur down the tree */
    if (key < node->key) 
        node->left  = insertNode(node->left, key); 
    else if (key > node->key) 
        node->right = insertNode(node->right, key);    
  
    /* return the (unchanged) node pointer */
    return node; 
} 

// Deleting a node
struct node *deleteNode(struct node *root, int key) {
  // Return if the tree is empty
  if (root == NULL) return root;

  // Find the node to be deleted
  if (key < root->key)
    root->left = deleteNode(root->left, key);
  else if (key > root->key)
    root->right = deleteNode(root->right, key);
  else {
    // If the node is with only one child or no child
    if (root->left == NULL) {
      struct node *temp = root->right;
      free(root);
      return temp;
    } else if (root->right == NULL) {
      struct node *temp = root->left;
      free(root);
      return temp;
    }

    // If the node has two children
    struct node *temp = minValueNode(root->right);

    // Place the inorder successor in position of the node to be deleted
    root->key = temp->key;

    // Delete the inorder successor
    root->right = deleteNode(root->right, temp->key);
  }
  return root;
}
