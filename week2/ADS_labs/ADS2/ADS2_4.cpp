#include <iostream>

class Node{
public:
    int data;
    Node* next;
    Node(int val){
        data= val;
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
        tail->next = newNode;
        tail = newNode;
    }
    void reverse(){
        Node* old_head= head;
        if(head== nullptr){
            return;
        }
        Node* prev = nullptr;
        Node* curr = head;
        while(curr!=nullptr){
            Node* n_song = curr->next;
            curr->next = prev;
            prev = curr;
            curr = n_song;
        }
        head = prev;
        tail = old_head;
    }
    void show(){
        Node* temp = head;
        while(temp!=nullptr){
            std::cout<<temp->data<<" ";
            temp = temp->next;
        }
    }

};
int main(){
    LinkedList mylist;

    int n;
    std::cin>>n;

    int element;
    for(int i=0; i<n; i++){
        std::cin>>element;
        mylist.Add(element);
    }
    mylist.reverse();
    mylist.show();
}