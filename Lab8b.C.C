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
void enqueue(struct node*a,int data){
    struct node*new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=data;
    new_node->next=head;
    head=new_node;
    printf("Resulting list is as follows:");
    display(head);
}
void dequeue(){
    struct node*ptr1;
    struct node*ptr;
    ptr=head;
    if(head==NULL){
        printf("Linked list is empty!\n");
    }
    else if(head->next==NULL){
        head=NULL;
        ptr=head;
        free(ptr);
        display(head);
    }
    else{
        while(ptr->next!=NULL){
            ptr1=ptr;
            ptr=ptr->next;
        }
        ptr1->next=NULL;
        ptr=NULL;
        free(ptr);
        printf("Resulting list is as follows:");
        display(head);
    }
}
int main(){
    struct node* n;
    enqueue(n,2);
    enqueue(n,4);
    enqueue(n,6);
    enqueue(n,8);
    enqueue(n,10);
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
}