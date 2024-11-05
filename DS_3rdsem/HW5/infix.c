#include<stdio.h>
//intialise
#define MAX_SIZE 100
int top=-1;
char stack[MAX_SIZE];

//push operation
void push(char a){
    if(top<MAX_SIZE-1){
        stack[++top]=a;
    }
  else  printf("The stack is full");
}
//pop operation
char pop(){
    if(top>-1){
        top--;
        return stack[top+1];
    }
    else {
        printf("The stack is empty");
        return '\0';
    }
}
//
void postfix_convert(char expression[]){
    char new_expression[MAX_SIZE];
    char op;
    int j=-1;
    for(int i=0;expression[i]!='\0';i++){
        op=expression[i];
        
        if(op=='+'||op=='-'){
            if(top!=-1&&(stack[top]=='+'||stack[top]=='-')){
                new_expression[++j]=pop();            
            }
            if(top!=-1&&(stack[top]=='*'||stack[top]=='/')){
                while(top!=-1){
                    new_expression[++j]=pop();
                }
            }
            push(op);
        }
        else if(op=='*'||op=='/'){
            if(top!=-1&&(stack[top]=='*'||stack[top]=='/')){
                new_expression[++j]=pop();
            }
            push(op);
        }
        else{
            new_expression[++j]=op;
        }
    }
    while(top!=-1){
        new_expression[++j]=pop();
    }
    new_expression[++j]='\0';
    printf("Postfix expression is :%s",new_expression);
}

int main(){
    char expression[100];
    printf("Enter the infix expression :");
    scanf("%[^\n]s",expression);
    
    postfix_convert(expression);
    return 0;
}