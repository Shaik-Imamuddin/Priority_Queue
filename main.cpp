#include <iostream>
using namespace std;

class Node{
public:
    int data, priority;
    Node *next;

    Node(int val,int p){
        data = val;
        priority = p;
        next = NULL;
    }
};

class PriorityQueue{
public:
    Node *front;

    PriorityQueue(){
        front = NULL;
    }

    void insert(int val,int priority){
        Node* newNode = new Node(val,priority);

        if (front==NULL || priority<front->priority){
            newNode->next = front;
            front = newNode;
        } 
        else{
            Node *temp = front;
            while(temp->next != NULL && temp->next->priority <= priority){
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    void deleteNode(){
        if (front == NULL){
            cout<<"Queue is Empty"<<endl;
            return;
        }
        cout<<front->data<<endl;
        Node* temp = front;
        front = front->next;
        delete temp;
    }

    void display(){
        if(front == NULL){
            cout << "Queue is Empty" << endl;
            return;
        }

        Node* temp = front;
        while (temp != NULL){
            cout<<temp->data<<" "<<temp->priority<<endl;
            temp = temp->next;
        }
    }
};

int main(){
    PriorityQueue pq;

    int val, priority;

    do {
        cin>>val>>priority;
        if (val!=-1 && priority!=-1)
            pq.insert(val,priority);
    } while (val!=-1 && priority!=-1);
    
    pq.deleteNode();
    pq.display();

    return 0;
}