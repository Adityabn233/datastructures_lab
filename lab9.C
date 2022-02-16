#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node*prev;
    int data;
    struct node*next;
};
struct node*head=NULL;
struct node* create(){
    struct node*new_node=(struct node*)malloc(sizeof(struct node));
    return new_node;
}
void left_ins(int data){
    struct node*new_node;
    new_node=create();
    if(head==NULL){
        new_node->data=data;
        new_node->next=NULL;
        new_node->prev=NULL;
        head=new_node;
    }
    else{
        new_node->data=data;
        new_node->next=head;
        head->prev=new_node;
        new_node->prev=NULL;
        head=new_node;
    }
}
void val_del(int value){
    struct node*temp;
    temp=head;
    if(head==NULL){
        printf("Underflow");
    }
    else if(head->data==value){
        head=NULL;
        free(head);
        head=temp->next;
        head->prev=NULL;
    }
    else{
        struct node*pre,*succ;
        pre=temp;
        temp=temp->next;
        succ=temp->next;
    while(temp!=NULL){
        if(temp->data==value){
            pre->next=succ;
            succ->prev=pre;
            temp=NULL;
            free(temp);
            return;
        }
        pre=temp;
        temp=temp->next;
        succ=temp->next;
    }
    }
}
void display(struct node*node){
    int i=0;
    struct node*temp;
    printf("\n");
    temp=node;
    while(temp!=NULL){
        printf("%d, ",temp->data);
        temp=temp->next;
        i++;
    }
    if(i==0){
        printf("Linked list is empty!");
    }
    printf("\n");
}
int main(){
    left_ins(1);
    left_ins(2);
    left_ins(3);
    left_ins(4);
    display(head);
    val_del(2);
    display(head);
}