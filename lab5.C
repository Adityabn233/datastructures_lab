#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next;
};
struct node*head;
struct node* create(){
    struct node*new_node=(struct node*)malloc(sizeof(struct node));
    return new_node;
}
void f_ins(int data, struct node*node){
        struct node* new_node=create();
    if(node==NULL){
        new_node->data=data;
        new_node->next=NULL;
        head=new_node;
    }
    else{
        new_node->data=data;
        new_node->next=head;
        head=new_node;
    }
}
void r_ins(int data, struct node*node){
    struct node* new_node=create();
    struct node*last,*prev;
    last=head;
    while(last!=NULL){
        prev=last;
        last=last->next;
    }
    new_node->data=data;
    new_node->next=NULL;
    prev->next=new_node;
}
void pos_ins(int data, int pos){
    struct node* new_node=create();
    struct node*temp;
    temp=head;
    int i;
    if(pos==1){
        new_node->data=data;
        new_node->next=head;
        head=new_node;
    }
    else if(pos==2){
        struct node*ptr;
        ptr=temp->next;
        new_node->data=data;
        new_node->next=ptr;
        temp->next=new_node;
    }
    else{
        struct node*ptr;
        for(i=1;i<pos-1;i++){
            temp=temp->next;
            ptr=temp->next;
        }
        new_node->data=data;
        new_node->next=ptr;
        temp->next=new_node;
    }
}
void display(){
    if(head==NULL){
        printf("List underflow!!");
    }
    else{
        struct node*temp;
        temp=head;
        while(temp!=NULL){
            printf("%d, ",temp->data);
            temp=temp->next;
        }
    }
}
int main(){
    f_ins(2,head);
    r_ins(3,head);
    pos_ins(4,1);
    display();
}