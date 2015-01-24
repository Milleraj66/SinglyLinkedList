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
            Head = NULL;
            Tail = NULL;
        }
        // Destructor
        ~SinglyLinkedList(){
            for(Node *p; !IsEmpty();){
                p = Head->Next;
                delete Head;
                Head = p;
            }
            /*

            while(!IsEmpty()){
                Node *p = Head->Next;
                delete Head;
                Head = p;
            }*/
        }

        // Methods
        int IsEmpty(){
            return Tail==0;
        }
        void AddToHead(int data);
        void RemoveFromHead();
        void AddToTail(int data);
        void RemoveFromTail();
        void Print(); // print out fill list


};


int main()
{
    SinglyLinkedList L1;

    cout << L1.IsEmpty() << endl;

    L1.AddToHead(1);
    cout << L1.IsEmpty() << endl;
    L1.AddToHead(2);
    L1.AddToHead(3);
    L1.AddToHead(4);
    L1.AddToHead(5);

    L1.Print();

    L1.RemoveFromHead();
    L1.AddToHead(10);
    L1.Print();

    L1.RemoveFromHead();
    L1.Print();
    L1.RemoveFromHead();
    cout << L1.IsEmpty() << endl;
    L1.Print();
    L1.RemoveFromHead();
    L1.Print();
    cout << L1.IsEmpty() << endl;
    L1.RemoveFromHead();
    L1.Print();
    L1.RemoveFromHead();
    cout << " HEY " << endl;
    L1.Print();
    L1.AddToHead(1);
    cout << L1.IsEmpty() << endl;
    L1.AddToHead(2);
    L1.AddToHead(3);
    L1.AddToHead(4);
    L1.AddToHead(5);
    L1.Print();



    L1.AddToTail(15);
    L1.Print();
    L1.AddToHead(10);
    L1.Print();
    L1.RemoveFromTail();
    L1.Print();

    cout << L1.IsEmpty() << endl;
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

    if (Head == NULL && Tail == NULL){
            cout << "Nothing to remove from head, the list is empty\n";

    }
    // If only one node left point head and tail to NULL to empty list
    else if(Head == Tail){
        //cout << "List is already empty" << endl;
        Head = NULL;
        Tail = NULL;
    }
    // Point Head to Head-> next effectively removing the head of the linked list
    else{
        Head = Head->Next;
    }
}// END RemoveFromHead()
// Print full linked list
void SinglyLinkedList::Print(){
    Node *tmp = Head;
    do {
        // If list is empty cant use tmp->next must print that list is empty
        if(IsEmpty()){
            cout << "Nothing to see here... Move along\n";
        }
        else{
            cout << tmp->Data << " -> ";
            tmp = tmp->Next;
        }

    }while(tmp != NULL);
    cout << endl;
    delete tmp;
}// END Print()
// Add node to linked list to the Tail pointer
void SinglyLinkedList::AddToTail(int data){
    // if list is not empty
    if(Tail != NULL){
        Tail->Next = new Node(data,NULL);
        Tail = Tail->Next;
    }
    // else list is empty so both head and tail point to new node
    else{
        Tail = new Node(data,NULL);
        Head = Tail;
    }
}// END AddToTail(int)
// Remove node of linked list from the tail
void SinglyLinkedList::RemoveFromTail(){
    // If list is empty, print to screen EMPTY
    if(Head == NULL && Tail == NULL){
        cout << "Nothing to remove from tail, the list is empty\n";
    }
    // If only one node left, point Head and Tail to NULL, which means empty list
    else if(Head == Tail){
        Head = NULL;
        Tail = NULL;
    }
    // If more than one node, first traverse list until second to last node is found
    // set temp node = to this value so that you can point the Tail pointer to it and
    // effectivley cut off the the last node from the list
    else{
        Node *tmp = Head;
        // find node before Tail
        while(tmp->Next != Tail){
            //cout << "before: " << tmp->Data;
            tmp = tmp->Next;
            //cout << "after: " << tmp->Data;
        }
        delete Tail;
        Tail = tmp;
        Tail->Next = NULL;
    }
}// END RemoveFromTail()
