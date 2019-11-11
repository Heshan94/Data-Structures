#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node{
    char data;
    struct Node * next;
};

struct Node * top=NULL;

void Push(char x){
    struct Node * temp=(struct Node *)malloc(sizeof(struct Node));
    temp->data=x;
    temp->next=top;
    top=temp;
}

char Pop(){
    struct Node * temp;
    if(top==NULL) return;

    temp=top;
    char value=top->data;
    top=top->next;
    free(temp);

    return value;
}

char Top(){
    if(top==NULL) return;

    return top->data;
}

bool IsEmpty(){
    if(top==NULL) return true;
    return false;
}

void Print(){
    struct Node * temp=top;

    while(temp!=NULL){
        printf("%c ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int main()
{


    return 0;
}


