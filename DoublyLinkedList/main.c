#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node * prev;
    struct Node * next;
};


struct Node * GetNewNode(int x);
void InsertAtHead(int x);
void Print();
void PrintReverse();
void InsertAtTail(int x);

struct Node * head;

int main(){

   InsertAtHead(1);
   InsertAtHead(2);
   InsertAtHead(3);
   InsertAtHead(4);
   InsertAtHead(5);
   InsertAtHead(6);
   InsertAtTail(10);
   Print();
   PrintReverse();
    return 0;
}



struct Node * GetNewNode(int x){
    struct Node * newNode=(struct Node *)malloc(sizeof(struct Node));
    newNode->data=x;
    newNode->next=NULL;
    newNode->prev=NULL;

    return newNode;
}

void InsertAtHead(int x){
    struct Node * temp=GetNewNode(x);
    if(head==NULL){
        head=temp;
        return;
    }

    temp->next=head;
    head->prev=temp;
    head=temp;
}

void Print(){
    struct Node * temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }

    printf("\n");
}

void PrintReverse(){
    struct Node * temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }

    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->prev;
    }

    printf("\n");
}


void InsertAtTail(int x){
    struct Node * temp=GetNewNode(x);
    if(head==NULL){
        head=temp;
        return;
    }

    else{
        struct Node * temp1=head;
        while(temp1->next!=NULL){
            temp1=temp1->next;
        }

        temp->prev=temp1;
        temp1->next=temp;
        }
}
