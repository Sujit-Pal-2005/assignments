# include <stdio.h>
#include<string.h>
//globally declare for stack
float stack[100];
int top=-1;
//push function
void push(float a){
    if(top==99){
        printf("Stack is full");
    }
    else{
        top++;
        stack[top]=a;
    }
}
//pop function
float pop(){
    if(top==-1){
        printf("Stack is empty");
    }
    else{
        top--;
        return stack[top+1];
    }
}
//evaluate function
void eval(char ch){
   float b=pop();
   float a=pop();
   float result;
   //operation
   if(ch=='+'){
    result=a+b;
   }
   else if(ch=='*'){
    result=a*b;
   }
    else if(ch=='/'){
    result=a/b;
   }
    else if(ch=='-'){
    result=a-b;
   }
    push(result);


}


int main(){
    char str[100];
    printf("Enter postfix expression :");
    scanf("%[^\n]s",str);
    //printf("%s",str);
    int n=strlen(str);
    for(int i=0;i<n;i++){
        char ch=str[i];
        if(ch=='+'||ch=='-'||ch=='*'||ch=='/')eval(ch);
        else{
            push((int)ch-48);
        }
    }
    printf("Evaluated answer is %.2f",pop());
return 0;
}