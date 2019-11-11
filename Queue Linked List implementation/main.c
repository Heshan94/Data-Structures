#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node * next;
};
struct Node * front=NULL;
struct Node * rear=NULL;

void Enqueue(int x){
    struct Node * temp=(struct Node *)malloc(sizeof(struct Node));
    temp->data=x;
    temp->next=NULL;

    if(front==NULL && rear==NULL){
        front=rear=temp;
        return;
    }
    else{
        rear->next=temp;
        rear=temp;
    }
}

int Dequeue(){
    struct Node * temp=front;
    if(front==NULL) return;
    else if(front==rear){
        front=rear=NULL;
    }
    else{
        front=front->next;
    }
    free(temp);
}

void Print(){
    struct Node * temp=front;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int main()
{

    Enqueue(1);
    Enqueue(2);
    Enqueue(3);
    Enqueue(4);
    Enqueue(5);
    Dequeue();
    Print();

    return 0;
}
