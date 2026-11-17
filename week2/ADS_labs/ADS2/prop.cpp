#include <iostream>

class Node{
public:
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = nullptr;
    }
};
class LinkedList{
private:
    Node* head;
    Node* tail;
public:
    LinkedList(){
        head = nullptr;
        tail = nullptr;
    }
    void Add(int val){
        Node* newNode = new Node(val);
        if(head == nullptr){
            head = tail = newNode;
            return;
        }
        tail -> next = newNode;
        tail = newNode;
    }
    void Merge(LinkedList &mylist2){
        if(head==nullptr){
            head = mylist2.head;
            tail = mylist2.tail;
            return;
        }
        if(mylist2.head==nullptr) return;
        
        Node* curr1 = head;
        Node* curr2 = mylist2.head;

        Node dummy(0);
        Node* TailMerged = &dummy;

        while(curr1!=nullptr && curr2!=nullptr){
            if(curr1<=curr2){
                TailMerged = curr1;
                curr1 = curr1->next;
            }else{
                TailMerged = curr2;
                curr2 = curr2->next;
            }
        }

        if(curr1!=nullptr){
            TailMerged = curr1;
        }else{
            TailMerged = curr2;
        }
        
        head = dummy.next;
        tail = TailMerged;
    }
};