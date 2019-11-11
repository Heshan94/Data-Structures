#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_SIZE 101
int A[MAX_SIZE];
int top=-1;

int main()
{
    push(1);
    push(2);
    push(3);
    Print();
    int x=pop();
    int y=pop();
    Print();
    return 0;
}

void push(int x){
    if(top==(MAX_SIZE-1)){
        printf("Stack Overflow\n");
        return;
    }
    top++;
    A[top]=x;
}

int pop(){
    if(top==-1){
        printf("No elements to pop\n");
    }

    int temp=A[top];
    top--;
    return temp;
}

int Top(){
    if(top==-1){
        printf("No elements in stack\n");
        return -1;
    }

    return A[top];
}
bool IsEmpty(){
    if(top==-1){
        return true;
    }

    return false;
}

void Print(){
    for(int i=0;i<=top;i++){
        printf("%d ",A[i]);
    }
    printf("\n");
}
