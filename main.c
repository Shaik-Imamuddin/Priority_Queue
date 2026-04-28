#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    int priority;
    struct Node *addr;
};


struct Node *front = NULL;

void insert(int val,int priority){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->priority = priority;
    newNode->addr = NULL;

    if(front==NULL || priority<front->priority){
        newNode->addr = front;
        front = newNode;
    }

    else{
        struct Node *temp = front;
        while(temp->addr!=NULL &&temp->addr->priority<=priority){
            temp=temp->addr;
        }
        newNode->addr = temp->addr;
        temp->addr = newNode;
    }
}

void delete(){
    if(front==NULL){
        printf("Queue is Empty");
        return;
    }
    struct Node *temp = front;
    printf("%d\n",front->data);
    front=front->addr;
    free(temp);
}

void display(){
    if(front==NULL){
        printf("Queue is Empty");
        return;
    }

    struct Node *temp = front;
    while(temp!=NULL){
        printf("%d %d\n",temp->data,temp->priority);
        temp=temp->addr;
    }
}

int main(){
    
    int val,priority;

    do{
        scanf("%d %d",&val,&priority);
        if(val!=-1 && priority!=-1)
            insert(val,priority);
    }while(val!=-1 && priority!=-1);
    delete();
    display();
    return 0;
}