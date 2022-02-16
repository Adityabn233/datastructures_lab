#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next;
};
struct node*head;
void f_ins(int data, struct node*node){
    struct node*new_node=(struct node*)malloc(sizeof(struct node));
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
    struct node*new_node=(struct node*)malloc(sizeof(struct node));
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
    struct node*new_node=(struct node*)malloc(sizeof(struct node*));
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
void del_f(){
    if(head==NULL){
        printf("The list underflow!!");
    }
    else{
        struct node*temp;
        temp=head;
        head=NULL;
        free(head);
        head=temp->next;
    }
}
void del_r(){
    if(head==NULL){
        printf("The list underflow!!");
    }
    else{
        struct node*temp=head;
        struct node*ptr;
        while(temp->next!=NULL){
            ptr=temp;
            temp=temp->next;
        }
        temp=NULL;
        ptr->next=NULL;
        free(temp);
    }
}
void pos_del(int pos){
    if(head==NULL){
        printf("The list underflow!!");
    }
    else if(pos==1){
        struct node*temp;
        temp=head;
        head=NULL;
        free(head);
        head=temp->next;
    }
    else{
        struct node*ptr=head;
        struct node*ptr1=ptr;
        int i;
        for(i=1;i<pos;i++){
            ptr1=ptr;
            ptr=ptr->next;
            if(ptr1==NULL){
                printf("%d>number of nodes.",pos);
                return;
            }
        }
        ptr1->next=ptr->next;
        free(ptr);
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
    f_ins(6,head);
    r_ins(7,head);
    pos_del(2);
    del_r();
    del_f();
    display();
}