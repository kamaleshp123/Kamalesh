#include<stdio.h> 
#include<stdlib.h> 
   #include<string.h> 
struct node 
{ 
    char *nm; 
    struct node *left, *right; 
}; 
   
// A utility function to create a new BST node 
struct node *newNode(char *str) 
{ 
    struct node *temp =  (struct node *)malloc(sizeof(struct node)); 
    temp->nm = str ; 
    temp->left = temp->right = NULL; 
    return temp; 
} 
   
// A utility function to do inorder traversal of BST 
void inorder(struct node *root) 
{ 
    if (root != NULL) 
    { 
        inorder(root->left); 
        printf("%s \n", root->nm); 
        inorder(root->right); 
    } 
} 
   
/* A utility function to insert a new node with given key in BST */
struct node* insert(struct node* node, char *str) 
{ 
    /* If the tree is empty, return a new node */
    if (node == NULL) return newNode(str); 
  
    /* Otherwise, recur down the tree */
    if (strlen(str) <strlen(node->nm)) 
        node->left  = insert(node->left, str); 
    else if (strlen(str) >strlen(node->nm)) 
        node->right = insert(node->right, str);    
  
    /* return the (unchanged) node pointer */
    return node; 
} 
   
// Driver Program to test above functions 
int main() 
{ 
    /* Let us create following BST 
              50 
           /     \ 
          30      70 
         /  \    /  \ 
       20   40  60   80 */
    struct node *root = NULL; 
    root = insert(root, "kamales"); 
    insert(root, "patil"); 
    insert(root, "kkkkkkk"); 
    insert(root, "ssssss"); 
    insert(root, "cccccccc"); 
    insert(root, "sw"); 
    insert(root, "tddd"); 
   
    // print inoder traversal of the BST 
    inorder(root); 
   
    return 0; 
} 
