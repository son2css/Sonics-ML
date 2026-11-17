#include <iostream>
#include <cmath>

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
        Node* newNode= new Node(val);
        if(head== nullptr){
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        tail = newNode;
    }
    void Del_Mid(int n){
        int mid = std::floor(n/2);
        Node* temp = head;
        if(head == nullptr){
            return;
        }
        if(mid == 0){
            head =tail = nullptr;
            delete temp;
            return;
        }
        for(int i=0; i<mid-1; i++){
            temp = temp->next;
        }
        
        Node* to_d = temp->next;
        Node* nxt = to_d->next;
        temp->next = nxt;
        if(to_d == tail){
            tail = temp;
        }
        delete to_d;
    }
    void Show(){
        Node* temp = head;
        while(temp!=nullptr){
            std::cout<<temp->data<<(temp->next==nullptr?"":" ");
            temp = temp->next;
        }
    }
};


int main(){
    LinkedList mylist;
    int n;
    std::cin>>n;
    int el;
    for(int i=0; i<n; i++){
        std::cin>>el;
        mylist.Add(el);
    }
    mylist.Del_Mid(n);
    mylist.Show();
}