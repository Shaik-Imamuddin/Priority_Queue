import java.util.Scanner;

class Node {
    int data,priority;
    Node next;

    Node(int val,int priority){
        data = val;
        this.priority = priority;
        next = null;
    }
}

class PriorityQueue{
    Node front;

    PriorityQueue(){
        front=null;
    }

    void insert(int val,int priority){
        Node newNode = new Node(val, priority);

        if (front==null || priority<front.priority){
            newNode.next = front;
            front = newNode;
        } 
        else{
            Node temp = front;
            while(temp.next != null && temp.next.priority <= priority){
                temp = temp.next;
            }
            newNode.next = temp.next;
            temp.next = newNode;
        }
    }

    void delete(){
        if (front==null){
            System.out.println("Queue is Empty");
            return;
        }
        System.out.println(front.data);
        front = front.next;
    }

    void display(){
        if (front==null){
            System.out.println("Queue is Empty");
            return;
        }

        Node temp = front;
        while (temp!=null){
            System.out.println(temp.data+" "+temp.priority);
            temp = temp.next;
        }
    }
}

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        PriorityQueue pq = new PriorityQueue();

        int val, priority;

        do{
            val = sc.nextInt();
            priority = sc.nextInt();
            if(val!=-1 && priority!=-1)
                pq.insert(val,priority);
        }while(val!=-1 && priority!=-1);

        pq.delete();
        pq.display();
    }
}