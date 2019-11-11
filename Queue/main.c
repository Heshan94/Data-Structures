#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int A[10];
int front=-1;
int rear=-1;
int N=10;
bool IsEmpty(){
    if(front==-1 && rear==-1){
        return true;
    }
    return false;
}

void Enqueue(int x){
    if(IsEmpty()){
        front=0;
        rear=0;
         A[rear]=x;
        return;
    }

    else if((rear+1)%N==front){
        return;
    }

    else{
        rear=(rear+1)%N;
    }

    A[rear]=x;

}

int Dequeue(){
     int temp;
    if(IsEmpty()){
        return -1;
    }
    else if(rear==front){
        rear=-1;
        front=-1;
    }


    else{
        temp= A[front];
        front=(front+1)%N;
    }
    return temp;
}

void Print(){
   if(IsEmpty()){
    printf("Queue is empty");
   }

   else if(front <=rear){
    for(int i=front;i<=rear;i++){
        printf("%d ",A[i]);
    }
   }
   else{
        for(int i=front;i<N;i++){
            printf("%d ",A[i]);
        }

        for(int j=0;j<=rear;j++){
            printf("%d ",A[j]);
        }
   }
}

int main()
{
    Enqueue(1);
    Enqueue(2);
    Enqueue(3);
    Enqueue(4);
    Enqueue(5);
    Enqueue(6);
    Enqueue(7);
    Enqueue(8);
    Enqueue(9);
    Enqueue(10);
    Dequeue();
    Dequeue();
    Dequeue();
    Dequeue();

    Enqueue(11);
    Enqueue(12);

    Print();
    return 0;
}
