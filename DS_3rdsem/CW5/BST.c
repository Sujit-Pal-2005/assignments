#include <stdio.h>
#include <stdlib.h>
//structure
typedef struct node nd;
struct node
{
    int key;
    nd* left, *right ,*parent;
};
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
 //insertion
nd* insert(nd * root ,int key){
     //Found the parent
    nd* ptr=root;
    nd* ptr2 =NULL;
    while(ptr){
        if(ptr->key==key){
            printf("\nThe key is already present.\n");
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
    return root;
}
//Display
void traverse(nd* root){
    if(root){
        traverse(root->left);
        printf("%d ",root->key);
        traverse (root->right);
    }
}
//Height
int height(nd* root){
    if(root==NULL)return 0;
    int lefth=height(root->left);
    int righth =height(root->right);
    if(lefth>=righth)return lefth+1;
    else return righth+1;
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
    if(z){
        if(z->left==NULL){
            root= transplant(root,z,z->right);
        }
        else if(z->right==NULL){
            transplant(root,z,z->left);
        }
        else{
            nd* y=minimum(z->right);
            if(y->parent!=z){
            root= transplant(root,y,y->right);
            y->right=z->right;
            y->right->parent=y;
            }
            root=transplant(root,z,y);
            y->left=z->left;
            y->left->parent=y;
        }
        free(z);
    }
    return root;  
}

int main(){
    nd* tree=NULL;
    int k,exit=1;
    printf(" Enter 1 for insert key \n Enter 2 for search key \n Enter 3 for Display \n Enter 4 for delete \n Enter 5 for height of node\n Enter any other for exit\n");
    while(exit){
        int choice;
        printf("Enter choice:");
        scanf("%d",&choice);
        switch (choice){
            case 1:{
                printf(" Enter key :");
                scanf("%d",&k);
                tree=insert(tree,k);
                break;
            }
            case 2:{
                printf(" Enter key :");
                scanf("%d",&k);
                int depth=0;
                nd* temp=search(tree,k,&depth);
                if(temp){
                    printf("The key is present . And the depth is %d\n",depth);
                }
                break;
            }
            case 3:{
                traverse(tree);
                printf("\n");
                break;
            }
            case 4:{
                printf(" Enter key :");
                scanf("%d",&k);
                tree=delete(tree,k);
                break;
            }
            case 5:{
                printf(" Enter key :");
                scanf("%d",&k);
                int depth=0;
                nd* temp=search(tree,k,&depth);
                if(temp){
                    printf("Height of the node is :%d\n",height(temp));
                }
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
