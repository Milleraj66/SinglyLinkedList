// Author: Arthur Miller
// File Name: SinglyLinkedList.cpp
// Purpose: Singly Linkled list data structure for ECE304


#include <iostream>

using namespace std;

// Node for the Linked List
class Node{
        public:
            int Data;
            Node *Next;
            // Constructor
            Node(int el, Node *ptr = 0){
                 Data = el;
                 Next = ptr;
            }
}; // end class Node

// Linked List: used to form and edit linked list data structure
class SinglyLinkedList{
    private:
        Node *Head; // starting node
        Node *Tail; // last node
    public:
        // Constructor
        SinglyLinkedList(){
            Head = Tail = NULL;
        }
        // Destructor
        ~SinglyLinkedList(){
            while(!IsEmpty()){
                Node *p = Head->Next;
                delete Head;
                Head = p;
            }
        }

        // Methods
        bool IsEmpty(){
            if(Head == Tail == 0)
                return true;
            else
                return false;
        }
        void AddToHead(int data);
        void RemoveFromHead();
        void Print(); // print out fill list


};


int main()
{
    SinglyLinkedList L1;

    L1.AddToHead(1);
    L1.AddToHead(2);
    L1.AddToHead(3);
    L1.AddToHead(4);
    L1.AddToHead(5);

    L1.Print();
    return 0;
}

// Add a Node to the head (front) of the linked list
void SinglyLinkedList::AddToHead(int data){
    Head = new Node(data, Head);
    if(Tail == 0)
        Tail = Head;
} // END AddToHead()
// Remove Node from head of linked list
void SinglyLinkedList::RemoveFromHead(){
    if(IsEmpty()){
        cout << "List is already empty" << endl;
    }
    else{
        Node *tmp = Head;
        Head = tmp->Next;
        delete tmp;
    }
}// END RemoveFromHead()
// Print full linked list
void SinglyLinkedList::Print(){
    Node *tmp = Head;
    do {
        cout << tmp->Data << " -> ";
        tmp = tmp->Next;
    }while(tmp != NULL);
    delete tmp;
}// END Print()
