#include <stdio.h>
#include <stdlib.h>
typedef struct BST{
    int data;
    struct BST*left;
    struct BST*right;
}node;

node* construct(){
    node*temp;
    temp=(node*)malloc(sizeof(node));
    printf("Enter the data of the new node here :");
    scanf("%d",&temp->data);
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

void insert(node* root, node* temp){
    if(temp->data<root->data){
        if(root->left!=NULL){
            insert(root->left, temp);    
        }
        else{
            root->left=temp;
        }
    }
    if(temp->data>root->data){
        if(root->right!=NULL){
            insert(root->right,temp);
        }
        else{
            root->right=temp;
        }
    }
}
void inorder(node* root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d, ",root->data);
        inorder(root->right);
    }
}
void preorder(node* root){
    if(root !=NULL){
        printf("%d, ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(node* root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d, ",root->data);
    }
}
void display(node*root){
    printf("\nElements of the tree are: \n");
    postorder(root);
}
int main(){
    char ch='Y';
    node*temp, *root=NULL;
    while(ch=='Y' || ch=='y'){
        temp=construct();
        if(root==NULL){
            root=temp;
        }
        else{
            insert(root, temp);
        }
        printf("Enter 'Y' if you want to add another node to the BST :");
        getchar();
        scanf("%c",&ch);
    }
    printf("\nInorder traversal\n");
    inorder(root);
    printf("\nPreorder traversal\n");
    preorder(root);
    printf("\nPostorder traversal\n");
    postorder(root);
    display(root);
}