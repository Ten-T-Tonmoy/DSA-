#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
}*first=NULL; //pointer to struct global also
void create(int ar[],int n){
    int i;
    struct Node* t,*last;
    first=(struct Node*)malloc(sizeof( struct Node));
    first->data=ar[0];
    first->next=0;
    last=first;
    for(i=1;i<n;i++){
        t=(struct Node*)malloc(sizeof( struct Node));
        t->data=ar[i];
        t->next=NULL;
        
        last->next=t;
        last=t;
        
    }
}
void display(){
    struct Node* t;
    t=first;
    printf("The linked List is : ");
    while(t->next!=NULL){
        printf(" %d ",t->data);
        t=t->next;
    }
}
int main()
{   
    //in cpp its new Node;
    // p->data=10;
    // p->next=0;//will be null
    int ar[]={1,2,3,4,5,6};
    create(ar,6);
    display();

    return 0;
}