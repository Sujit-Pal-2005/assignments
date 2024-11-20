#include <stdio.h>
#include <stdlib.h>
//Structure for node
typedef struct node nd;
struct node {
    char data;
    nd* left;
    nd* right;
};
//stack for store 
nd ** stack;
int top=-1;
//push function
void push(nd* element){
    if(top==-1){
        stack=(nd**)malloc(sizeof(nd));
        top++;
        stack[top]=element;
        return;
    }
    top++;
    stack=(nd**)realloc(stack,(top+1)*sizeof(nd*));
    stack[top]=element;
}
//pop function
nd* pop(){
    nd* result=NULL;
    if(top>-1){
        result=stack[top];
        //free(&stack[top]);
        top--;
    }
    else{
        printf("No element present in stack.");
    }
    return result;
}

//Node creation
nd* create(char a){
    nd* new=(nd*)malloc(sizeof(nd));
    new->data=a;
    new->left=NULL;
    new->right=NULL;
    return new;
}
//merge function
nd* merge(nd* root,nd* right,nd* left){
    root->left=left;
    root->right=right;
    return root;
}

//traversal function
//preordered
void preordered(nd* root){
    if(root){
        printf("%c ",root->data);
        preordered(root->left);
        preordered(root->right);
    }
}
//inordered function
void inordered(nd* root){
    if(root){
    inordered(root->left);
    printf("%c ",root->data);
    inordered(root->right);  
    }     
}
//postordered
void postordered(nd* root){
    if(root){
        postordered(root->left);
        postordered(root->right);
        printf("%c ",root->data);
    }
}

//evaluate binary tree expression
float eval(nd* root,int *flag){
    if(root){
        char ch=root->data;
        if(ch=='+'||ch=='-'||ch=='*'||ch=='/'){
            float a=eval(root->left,flag);
            float b=eval(root->right,flag);
            //evaluate smallest expression
            if(ch=='+'){
                return a+b;
            }
            else if (ch=='-'){
                return a-b;
            }
            else if(ch=='*'){
                return a*b;
            }
            else if(b!=0){
                return a/b;
            }
            else{
                if(*flag) printf("\n The expression is wrong");
                *flag=0;
            }
        }
        //for leaf node
        else{
            return (int)ch-48;
        }
    }
}

//free memory
//free memory
void free_memory(nd* root){
    if(root==NULL)
        return;
    free_memory(root->left);
    free_memory(root->right);
    free(root);
}
//main function
int main(){
    printf("Enter the postfix expression :");
    char exp[100];
    scanf("%[^\n]s",exp);
    char * ptr=exp;
    while(*ptr!='\0'){
        if(*ptr!=' '){
            char ch =*ptr;
            //create node
            nd* new=create(ch);
            //check is it operand
            if(ch!='+'&&ch!='-'&&ch!='*'&&ch!='/'){
                push(new);
            }
            else{
                nd* prev=pop();
                nd* prev2=pop();
                new=merge(new,prev,prev2);
                push(new);
            }   
        }
        ptr++;
    }
    //traversal of expression
    printf("\n Preordered of binary expression :");
    preordered(stack[top]);
    printf("\n Postordered of binary expression :");
    postordered(stack[top]);
    printf("\n Inordered of binary expression :");
    inordered(stack[top]);
    //evaluation
    int flag=1;
    float result=eval(stack[top],&flag);
    if(flag){
        printf("\n The evaluated result is %0.2f",result);
    }
    //free memory
    free_memory(stack[top]);
    free(stack);
    return 0;
}