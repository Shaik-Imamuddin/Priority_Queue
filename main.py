class Node:
    def __init__(self, val, priority):
        self.data = val
        self.priority = priority
        self.next = None


class PriorityQueue:
    def __init__(self):
        self.front = None

    def insert(self, val, priority):
        newNode = Node(val, priority)

        if self.front is None or priority < self.front.priority:
            newNode.next = self.front
            self.front = newNode
        else:
            temp = self.front
            while temp.next is not None and temp.next.priority <= priority:
                temp = temp.next

            newNode.next = temp.next
            temp.next = newNode

    def delete(self):
        if self.front is None:
            print("Queue is Empty")
            return

        print(self.front.data)
        self.front = self.front.next

    def display(self):
        if self.front is None:
            print("Queue is Empty")
            return

        temp = self.front
        while temp:
            print(temp.data, temp.priority)
            temp = temp.next

pq = PriorityQueue()

while True:
    val, priority = map(int, input().split())
    if val == -1 and priority == -1:
        break
    pq.insert(val, priority)

pq.delete()
pq.display()