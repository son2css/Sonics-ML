#include <iostream>

class Node{
public:
    int data;
    Node* next = nullptr;
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
    void add(int val){
        Node* newNode = new Node(val);
        if(head == nullptr){
            head= tail = newNode;
            return;
        }
        tail -> next = newNode;
        tail = newNode;
    }
    void Ragnarek(){
        if(head==nullptr) return;
        Node* temp = head;

        int max_global = temp->data;
        int max_current = 0;

        while(temp!=nullptr){
            max_current+=temp->data;
            if(max_current>max_global){
                max_global = max_current;
            }
            if(max_current<0){
                max_current = 0;
            }
            temp = temp->next;
        }
        std::cout<<max_global;
    }
};