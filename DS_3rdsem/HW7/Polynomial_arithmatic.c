#include<stdio.h>
#include<stdlib.h>
//node structure
typedef struct node nd;
struct node{
    int coefficient;
    int exponent;
    nd* link;
};
//insertion
nd* insert(nd* head,int coef,int exp){
    nd* ptr ;
    ptr=(nd*)malloc(sizeof(nd));
    //If there is no element
    if(head==NULL){
        ptr->coefficient=coef;
        ptr->exponent=exp;
        ptr->link=ptr;
        head=ptr;
        return head;
    }
    //general case
    ptr->coefficient= head->coefficient;
    ptr->exponent= head->exponent;
    head->exponent=exp;
    head->coefficient=coef;
    ptr->link=head->link;
    head->link=ptr;
    head=ptr;
    return head;
}
//free memory
void free_memory(nd* head) {
    if (head == NULL) return;
    nd* ptr = head;
    nd* start = head;
    nd* temp;
    do {
        temp = ptr;
        ptr = ptr->link;
        free(temp);
    } while (ptr != start);
}
//polynomial creation
nd* creation(){
    printf("\nEnter no of elements:");
    int n;
    scanf("%d",&n);
    printf("Enter elements in decreasing order of the exponent.\n");
    nd* head=NULL;
    for(int i=1;i<=n;i++){
        printf("Enter %d no element's coefficient and exponent : ",i);
        int coeff,exp;
        scanf("%d %d",&coeff,&exp);
        if(coeff!=0) head=insert(head,coeff,exp);
    }
    return head;
}
//display
void display (nd* head){
    if(head==NULL){
        printf("\n0");
        return;
    }
    nd* ptr=head->link;
    printf("\n%dX^%d",head->coefficient,head->exponent);
    while(ptr!=head){
        if(ptr->coefficient>0)printf("+");
        printf("%dX^%d",ptr->coefficient,ptr->exponent);
        ptr=ptr->link;
    }
}
//Addition
nd* addition(nd*a ,nd*b){
    if (!a && !b) return NULL;  // If both are empty
    if (!a) return b;           // If only one is empty
    if (!b) return a;
    nd* ptr1=a,*ptr2=b,*result=NULL;
    int flag1=0,flag2=0;
    do{
        while(ptr1->exponent>ptr2->exponent){
            result=insert(result,ptr1->coefficient,ptr1->exponent);
            ptr1=ptr1->link;
            if(ptr1==a){
                flag1=1;
                break;
            }
        }
        while(ptr1->exponent<ptr2->exponent){
            result=insert(result,ptr2->coefficient,ptr2->exponent);
            ptr2=ptr2->link;
            if(ptr2==b){
                flag2=1;
                break;
            }
        }
        while(ptr1->exponent==ptr2->exponent){
            int coef=ptr1->coefficient+ptr2->coefficient;
            if(coef!=0){
                result=insert(result,coef,ptr1->exponent);
            }
            ptr1=ptr1->link;
            ptr2=ptr2->link;
            if(ptr1==a){
                flag1=1;
            }
            if(ptr2==b){
                flag2=1;
            }
            if(flag1||flag2)break;
        }
    }while(!flag1&& !flag2);
    while(!flag1){
        result=insert(result,ptr1->coefficient,ptr1->exponent);
        ptr1=ptr1->link;
        if(ptr1==a){
            flag1=1;
            break;
        }
    }
    while(!flag2){
        result=insert(result,ptr2->coefficient,ptr2->exponent);
        ptr2=ptr2->link;
        if(ptr2==b){
            flag2=1;
            break;
        }
    }
    return result;
}
//Subtraction
nd* Subtraction(nd*a ,nd*b){
    if (!a && !b) return NULL;  // If both are empty
    if (!a) return b;           // If only one is empty
    if (!b) return a;
    nd* ptr1=a,*ptr2=b,*result=NULL;
    int flag1=0,flag2=0;
    do{
        while(ptr1->exponent>ptr2->exponent){
            result=insert(result,ptr1->coefficient,ptr1->exponent);
            ptr1=ptr1->link;
            if(ptr1==a){
                flag1=1;
                break;
            }
        }
        while(ptr1->exponent<ptr2->exponent){
            result=insert(result,-ptr2->coefficient,ptr2->exponent);
            ptr2=ptr2->link;
            if(ptr2==b){
                flag2=1;
                break;
            }
        }
        while(ptr1->exponent==ptr2->exponent){
            int coef=ptr1->coefficient-ptr2->coefficient;
            if(coef!=0){
                result=insert(result,coef,ptr1->exponent);
            }
            ptr1=ptr1->link;
            ptr2=ptr2->link;
            if(ptr1==a){
                flag1=1;
            }
            if(ptr2==b){
                flag2=1;
            }
            if(flag1||flag2)break;
        }
    }while(!flag1 && !flag2 );
    while(!flag1 ){
        result=insert(result,ptr1->coefficient,ptr1->exponent);
        ptr1=ptr1->link;
        if(ptr1==a){
            flag1=1;
            break;
        }
    }
    while(!flag2 ){
        result=insert(result,-ptr2->coefficient,ptr2->exponent);
        ptr2=ptr2->link;
        if(ptr2==b){
            flag2=1;
            break;
        }
    }
    return result;
}
//Multiplication
nd* multiplication(nd*a ,nd*b){
    nd* ptr1=a,*ptr2=b,*result=NULL;
    do{  
        int coef=ptr2->coefficient,exp=ptr2->exponent;
        nd *ptr3=NULL;
        ptr1=a;
        do{
            int rcoef=coef*ptr1->coefficient;
            int rexp=exp+ptr1->exponent;
            if(rcoef!=0){
                ptr3=insert(ptr3,rcoef,rexp);
            }
            ptr1=ptr1->link;
        }while(ptr1!=a);
        result=addition(result,ptr3);
        ptr2=ptr2->link;
    }while(ptr2 !=b);  
    return result;
}
//main function
int main(){
    int exit=1;
    int n=0;
    nd** list=NULL;
    printf("\nRule:\n 1.Create polynomial \n 2.Add polynomial \n 3.Subtract polynomial \n 4.Multiply polynomial \n 5.Display polynomial \n 6.Erase Polynomial \n 7.Exit");
    int choice;
    while(exit){
        printf("\n Enter choice:");
        scanf("%d",&choice);        
        switch(choice){
            case 1:{
                n++;
                list=(nd**)realloc(list,n*sizeof(nd*));
                list[n-1]=creation();
                printf("\n No %d polynomial created \n",n);
                break;
            }
            case 2:{
                printf("Enter two polynomials index :");
                int ind1,ind2;
                scanf("%d %d",&ind1,&ind2);
                if(ind1<=n&&ind2<=n){
                    n++;
                    list=(nd**)realloc(list,n*sizeof(nd*));
                    list[n-1]=addition(list[ind1-1],list[ind2-1]);
                    printf("\n Addition result stored at %d no polynomial position \n",n);
                }
                else{
                    printf("Enter valid polynomials.");
                }
                break;
            }
            case 3:{
                printf("Enter two polynomials index :");
                int ind1,ind2;
                scanf("%d %d",&ind1,&ind2);
                if(ind1<=n&&ind2<=n){
                    n++;
                    list=(nd**)realloc(list,n*sizeof(nd*));
                    list[n-1]=Subtraction(list[ind1-1],list[ind2-1]);
                    printf("\nSubstraction result of %d no polynomial from %d no polynomial  stored at %d no polynomial position \n",ind2,ind1,n);
                }
                else{
                    printf("Enter valid polynomials.");
                }
                break;
            }
            case 4:{
                printf("Enter two polynomials index :");
                int ind1,ind2;
                scanf("%d %d",&ind1,&ind2);
                if(ind1<=n&&ind2<=n){
                    n++;
                    list=(nd**)realloc(list,n*sizeof(nd*));
                    list[n-1]=multiplication(list[ind1-1],list[ind2-1]);
                    printf("\nMultiplication result  stored at %d no polynomial position \n",n);
                }
                else{
                    printf("Enter valid polynomials.");
                }
                break;
            }
            case 5:{
                int index;
                printf("\nEnter Polynomial index :");
                scanf("%d",&index);
                if(index>n){
                    printf("\n This polynomial is not created");
                }
                else{
                    display(list[index-1]);
                }
                printf("\n");
                break;
            }
            case 6: {
                int index;
                printf("\nEnter Polynomial index :");
                scanf("%d",&index);
                free_memory(list[index-1]);
                list[index-1]=NULL;
            }
            default:{
                for(int i = 0; i < n; i++) {
                    nd* ptr = list[i];
                    free_memory(ptr);
                }
                free(list);
                exit=0;
                break;
            }
        }
    }
    return 0;
}