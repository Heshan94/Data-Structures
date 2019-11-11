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

bool ClosingPara(char opening, char closing){
    if((opening=='(' && closing==')') || (opening=='{' && closing=='}') || (opening=='[' && closing==']')) {return true;}
    return false;
}

char* isBalanced(char exp[]){
    int len=strlen(exp);
    for(int i=0;i<len;i++){
        if(exp[i]=='(' || exp[i]=='{' || exp[i]=='['){
            Push(exp[i]);
        }
        else if(exp[i]==')' || exp[i]=='}'|| exp[i]==']'){
            if(IsEmpty()|| ClosingPara(Top(), exp[i])==false ){
                return "NO";
            }
            else{
                Pop();

            }
        }
    }

    if(IsEmpty()){
        return "YES";
    }
    return "NO";
}



int main()
{

    char * exp="{(([])[])[]}";
    char * str=isBalanced(exp);
    printf("%s ",str);



    return 0;
}


