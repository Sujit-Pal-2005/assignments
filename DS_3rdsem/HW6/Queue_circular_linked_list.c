#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//node creation
typedef struct node nd;
struct node{
    int data;
    nd* link;
};

//enqueue
nd* enqueue(nd* head,int data){
    nd* ptr ;
    ptr=(nd*)malloc(sizeof(nd));
    //If there is no element
    if(head==NULL){
        ptr->data=data;
        ptr->link=ptr;
        head=ptr;
        return head;
    }
    //general case
    ptr->data= head->data;
    head->data=data;
    ptr->link=head->link;
    head->link=ptr;
    head=ptr;
    return head;
}
//dequeue
nd* dequeue(nd* head){
    //no element
    if (head == NULL) {
        printf("\nQueue is empty");
        return NULL;
    }
    //for one element
    if (head->link == head) {
        free(head);
        return NULL;
    }
    //general
    nd* ptr=head->link;
    head->data=ptr->data;
    head->link=ptr->link;
    free(ptr);
    return head;
}
//traversal
void traverse(nd* head){
    if(head==NULL){
        printf("\nNo element");
        return;
    }
    nd* ptr=head->link;
    int front=head->data;
    int rear=front;
    printf("\nElements are :%d ",head->data);
    while(ptr!=head){
        rear=ptr->data;
        printf("%d ",rear);
        ptr=ptr->link;
    }
    printf("\nFront element is %d and rear element is %d",front,rear);
}
//count no of element
int  count(nd* head){
    if(head==NULL)return 0;
    int cnt=1;
    nd* ptr=head->link;
    while(ptr!=head){
        cnt++;
        ptr=ptr->link;
    }
    return cnt;
}

int main(){
    srand(time(NULL));
    nd* head=NULL;
    int n;
    printf("\nEnter number of element for enqueue: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int data=rand()%100;
        head=enqueue(head,data);
    }
    printf("\nNo of element is %d ",count(head));
    traverse(head);
    printf("\nEnter number of element for dequeue :");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        head=dequeue(head);
    }
    printf("\nNo of element is %d ",count(head));
    traverse(head);
    return 0;
}