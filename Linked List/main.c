#include <stdio.h>
#include <stdlib.h>


struct Node{
    int data;
    struct Node* next;
};

void InsertAtEnd(int i);
void InsertAtStart(int i);
void display();
void Insert(int data, int n);
void Reverse();

struct Node * head;
int size=0;

int main(){

    head=NULL;
    InsertAtEnd(5);
    InsertAtEnd(6);
    InsertAtEnd(7);
    InsertAtEnd(8);
	InsertAtEnd(9);
    //Insert(10,12);
    //Delete(3);
    //display();
    //Reverse();
    //display();
    RecursiveReverse(head);
    print(head);
    return 0;
}

void InsertAtStart(int d){
    struct Node * temp =(struct Node*)malloc(sizeof(struct Node));
    temp->data=d;
    temp->next=head;
    head=temp;
    size++;
}

void InsertAtEnd(int d){
    struct Node * temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=d;
    if(head==NULL){
        temp->next=NULL;
        head=temp;
    }
    else{
    struct Node * temp1;
    temp1=head;
    while(temp1->next!=NULL){
        temp1=temp1->next;
    }

    temp->next=temp1->next;
    temp1->next=temp;
    }
    size++;
}

void Insert(int data, int n){
    if(n<0 || n>size){
        return -1;
    }

    struct Node * temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=data;

    if(n==1){
        temp->next=head;
        head=temp;
    }

    else{
        struct Node * temp1=head;
        for(int i=0;i<n-2;i++){
            temp1=temp1->next;
        }
        temp->next=temp1->next;
        temp1->next=temp;
    }
    size++;
}

void Delete(int n){
    if(n<0 || n>size){
        return -1;
    }

    struct Node * temp=head;

    if(n==1){
        head=temp->next;
        free(temp);
    }

    else{

        for(int i=0;i<n-2;i++){
            temp=temp->next;
        }

        struct Node * temp1=temp->next;
        temp->next=temp1->next;
        free(temp1);
    }

    size--;
}

void display(){
    struct Node * temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}


void Reverse(){
 struct Node * temp=head;
 struct Node *prev=NULL;
 struct Node * temp1;
 while(temp!=NULL){
     temp1=temp->next;
     temp->next=prev;
     prev=temp;
     temp=temp1;
 }
 head=prev;
}

void print(struct Node *p){
    if(p==NULL) return ;
    printf("%d ", p->data);
    print(p->next);
}



void RecursiveReverse(struct Node * p ){

    if(p->next ==NULL){
        head=p;
        return;
    }
    RecursiveReverse(p->next);
    struct Node * q;
    q=p->next;
    q->next=p;
    p->next=NULL;
}
