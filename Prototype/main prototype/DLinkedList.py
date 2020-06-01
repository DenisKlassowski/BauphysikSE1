# This Python file uses the following encoding: utf-8

class DLinkedList:
    def __init__(self):
        self.head=None
        self.length = 0

    def __iter__(self):
        node = self.head
        while node != None:
            yield node
            node = node.next

    def add(self, data, index):
        if self.head != None:
            node = self.head
            for i in range(index):
                if node.next != None:
                    if i == index-1:
                        nodetemp=node.next
                        node.next=Node(data)
                        node.next.previous=node
                        node.next.next=nodetemp
                        node.next.next.previous=node.next
                        self.length+=1

                    else:
                        node = node.next
                else:
                    node.next=Node(data)
                    node.next.previous=node
                    self.length+=1
                    break

        else:
             self.head = Node(data)
             self.length+=1

    def remove(self, index):
        node=self.pop(index)
        del node

    def pop(self, index):
        if (index>=self.length):
            raise Exception("LinkedList: Removal/Pop: Index is out of bounds.")
        else:
            node = self.head
            for i in range(index):
                node = node.next
            if node!=self.head:
                node.previous.next=node.next
                if node.next != None:
                    node.next.previous=node.previous
            else:
                if node.next != None:
                    node.next.previous=None
                    self.head=node.next
                else:
                    self.head=None
            self.length-=1
            return node


    def getData(self,index):
        if (index>=self.length):
            raise Exception("LinkedList: getData: Index is out of bounds.")
        else:
            node=self.head
            for i in range(index):
                node=node.next
            return node.data

class Node:
    def __init__(self,data):
        self.data=data
        self.next=None
        self.previous=None

    def __repr__(self):
        return self.data
