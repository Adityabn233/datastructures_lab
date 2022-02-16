#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next;
};
struct node*head;
void display(struct node*node){
    int i=0;
    printf("\n");
    while(node!=NULL){
        printf("%d, ",node->data);
        node=node->next;
        i++;
    }
    if(i==0){
        printf("Linked list is empty!");
    }
    printf("\n");
}
void push(struct node*a,int data){
    struct node*new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=data;
    new_node->next=head;
    head=new_node;
    printf("Resulting list is as follows:");
    display(head);
}
void pop(){
    if(head==NULL){
        printf("List is empty!");
    }
    else{
    struct node*ptr;
    ptr=head;
    head=head->next;
    ptr==NULL;
    free(ptr);
    printf("Resulting list is as follows:");
    display(head);
    }
}
int main(){
    struct node* n;
    push(n,2);
    push(n,3);
    push(n,4);
    push(n,5);
    pop();
    pop();
    pop();
    pop();
    pop();
}