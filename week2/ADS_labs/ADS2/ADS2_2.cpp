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
            head = newNode;
            tail = newNode;
            return;
        }
        tail->next = newNode;
        tail = newNode;
    }
    void show(){
        while(head!=nullptr){
            std::cout<<head->data<<(head->next==nullptr?"\n": " ");
            head = head->next;
        }
    }
};

int main(){
    LinkedList mylist;

    int n;
    std::cin>>n;
    for(int i=1; i<=n; i++){
        int element;
        std::cin>>element;
        if(i%2 == 0){
            continue;
        }
        mylist.Add(element);
    }
    mylist.show();
}