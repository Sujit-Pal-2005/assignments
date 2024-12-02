#include <stdio.h>
#include <stdlib.h>
#include<math.h>
//structure
typedef struct node nd;
struct node{
    int key;
    nd* left, *right ,*parent;
};
//initialise queue for traversal
int size = 1, rear = -1, front = -1;
nd** queue = NULL; 
// Function to enqueue
void enqueue(nd* ptr) {
    if (rear == -1) {
        queue = (nd**)malloc(sizeof(nd*)); 
        front++;
    }
    rear++;  
    // Reallocate if the queue is full
    if (rear == size) {
        size = size * 2;
        nd** temp = realloc(queue, size * sizeof(nd*));
        if (temp == NULL) {
            printf("\nMemory allocation failed!\n");
            return;
        }
        queue = temp;
    }
    queue[rear] = ptr;
}
// Function to dequeue
nd* dequeue() {
    if (rear == -1) {
        //printf("\nThe queue is empty\n");
        return NULL;
    }
    nd* dequeuedNode = queue[front]; 
    front++;
    // Check if the queue is empty after dequeueing
    if (front > rear) {
        //printf("\nThe queue is empty\n");
        rear = -1;
        front = -1;
        size = 1;
        free(queue); 
        queue = NULL; 
    }
    return dequeuedNode;
}

//creation
nd* create( int data){
    nd* ptr=(nd*)malloc(sizeof(nd));
    ptr->key=data;
    ptr->left=NULL;
    ptr->right=NULL;
    ptr->parent=NULL;
    return ptr;
}
//search
nd* search(nd* root,int k,int * depth){
    if(root){
        if(k==root->key){
            return root;
        }
        else if(k>root->key){
            (*depth)++;
            return search(root->right,k,depth);
        }
        else{
            (*depth)++;
            return search(root->left,k,depth);
        }
    }
    else{
        printf("The key is not present.\n");
        return NULL;
    }
}
//height
int height(nd* root){
    if(root==NULL)return 0;
    int lefth=height(root->left);
    int righth =height(root->right);
    if(lefth>=righth)return lefth+1;
    else return righth+1;
}
//Rotation
//Left left  Rotate
void ll(nd* z,nd* y ){
    if(z->parent){
        if(z->parent->left==z){
            z->parent->left=y;
        }
        else z->parent->right =y;
    }
    y->parent=z->parent;
    z->left=y->right;
    if(y->right)y->right->parent=z;
    y->right =z;
    z->parent=y;
}
//right right rotate
void rr(nd* z,nd* y ){
    if(z->parent){
        if(z->parent->left==z){
            z->parent->left=y;
        }
        else z->parent->right =y;
    }
    y->parent=z->parent;
    z->right=y->left;
    if(y->left)y->left->parent=z;
    y->left =z;
    z->parent=y;
}
//left right rotate
void lr(nd*z ,nd*y,nd*x){
    rr(y,x);
    ll(z,x);
}
//right left rotate
void rl(nd* z,nd* y,nd* x){
    ll(y,x);
    rr(z,x);
}

//Balance
int balance(nd * root){
    int a=height(root->left);
    int b=height(root->right);
    if((a-b)>=-1&&(a-b)<=1) return 1;
    else return 0;
}
 //insertion
nd* insert(nd * root ,int key){
     //Found the parent
    nd* ptr=root;
    nd* ptr2 =NULL;
    while(ptr){
        if(ptr->key==key){
            printf("\nThe key %d is already present.\n",key);
            return root;
        }
        else if(key>ptr->key){
            ptr2=ptr;
            ptr=ptr->right;
        }
        else{
            ptr2=ptr;
            ptr=ptr->left;
        }
    }
    //Connect new node
    nd* n=create(key);
    if(ptr2==NULL){
        return n;
    }
    if(key>ptr2->key){
        ptr2->right=n;
    }
    else{
        ptr2->left=n;
    }
    n->parent=ptr2;
    //check if it is balance
    nd * x=n,*y =ptr2,*z=ptr2->parent;
    while(z){
        if(!balance(z)){
            if(z->left==y &&y->left==x ){
                ll(z,y);
                if(root==z)root=y;
            }
            else if(z->right==y && y->right==x){
                rr(z,y);
                if(root==z)root=y;
            }
            else if(z->left==y && y->right==x){
                lr(z,y,x);
                if(root==z)root=x;
            }
            else {
                rl(z,y,x);
                if(root==z)root=x;
            }
            break;
        }
        x=y;
        y=z;
        z=z->parent;
    }
    return root;
}
// Print spaces
void printSpaces(int spaces) {
    for (int i = 0; i < spaces; i++)
        printf(" ");
}
//Display
void traverse(nd* root){
    if(root==NULL) return ;
    int _height = height(root);
    int indentSpace = (int)pow(2, _height);
    enqueue(root);
    while(_height--){
        int q_size=rear-front+1;
        printSpaces(indentSpace/2);
        while(q_size--){
            nd* temp=dequeue();
            if(temp!=NULL){
                printf("%d",temp->key);
                enqueue(temp->left);
                enqueue(temp->right);
            }
            else{
                printf(" ");
                enqueue(NULL);
                enqueue(NULL);
            }
            printSpaces(indentSpace-1);   
        }
        printf("\n");
        indentSpace/=2;
    }
    //free the queue
    rear=-1;
    front=-1;
    size=1;
    free(queue);
    queue=NULL;
}

//free memory
void free_memory(nd* root){
    if(root){
        free_memory(root->left);
        free_memory (root->right);
        free(root);
    }
}
//minimum
nd* minimum(nd* root){
    nd* ptr=root;
    while(ptr->left){
        ptr=ptr->left;
    }
    return ptr;
}
//Deletion section
//transplant
nd* transplant(nd*root ,nd* x,nd* y){
    if(x==root){
        if(y) y->parent=x->parent;
        return y;
    }
    if(y) {
        y->parent=x->parent;
    }
    if(x->parent->left==x){
        x->parent->left=y;
    }
    else{
        x->parent->right=y;
    }
    return root;
}
//delete
nd* delete(nd* root ,int key){
    int depth=0;
    nd* z=search(root,key,&depth);
    nd*w=NULL;
    if(z){
        if(z->left==NULL){
            root= transplant(root,z,z->right);
            w=z->parent;
        }
        else if(z->right==NULL){
            transplant(root,z,z->left);
            w=z->parent;
        }
        else{
            nd* y=minimum(z->right);
            if(y->parent!=z){
                w=y->parent;
                root= transplant(root,y,y->right);
                y->right=z->right;
                y->right->parent=y;
            }
            else{
                w=y;
            }
            root=transplant(root,z,y);
            y->left=z->left;
            y->left->parent=y;
        }
        free(z);
        //check for balance
    while(w){
        if(!balance(w)){
            //give z,y,x correct location
            z=w;
            nd* y,*x;
            if(height(z->left)>height(z->right)){
                y=z->left;
            }
            else y=z->right;
            if(height(y->left)>height(y->right)){
                x=y->left;
            }
            else x=y->right;
            //check which balance
            if(z->left==y &&y->left==x ){
                ll(z,y);
                if(root==z)root=y;
            }
            else if(z->right==y && y->right==x){
                rr(z,y);
                if(root==z)root=y;
            }
            else if(z->left==y && y->right==x){
                lr(z,y,x);
                if(root==z)root=x;
            }
            else {
                rl(z,y,x);
                if(root==z)root=x;
            }
        }
        w=w->parent;
    }
    }
    return root;  
}

int main(){
    nd* tree=NULL;
    int k,exit=1;
    printf(" Enter 1 for insert key \n Enter 2 for delete key \n Enter 3 for search key \n Enter 4 for display \n  Enter any other for exit\n");
    while(exit){
        int choice;
        printf("Enter choice:");
        scanf("%d",&choice);
        switch (choice){
            case 1:{
                printf(" Enter no of key:");
                int n;
                scanf("%d",&n);
                int a[n];
                printf("Enter Keys:");
                for(int i=0;i<n;i++){
                    scanf("%d",&a[i]);
                }
                for(int i=0;i<n;i++){
                    tree=insert(tree,a[i]);
                }
                break;
            }
            case 2:{
                printf(" Enter key :");
                scanf("%d",&k);
                tree=delete(tree,k);
                break;
            }
            case 3:{
                printf(" Enter key :");
                scanf("%d",&k);
                int depth=0;
                nd* temp=search(tree,k,&depth);
                if(temp){
                    printf("The key is present . And the depth is %d\n",depth);
                }
                break;
            }
            case 4:{
                traverse(tree);
                printf("\n");
                break;
            }
            default :{
                free_memory(tree);
                exit=0;
            }
        }
    }

    return 0;
}
