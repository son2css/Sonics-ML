#include <iostream>
struct Node{
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = nullptr;
    }
};
class LinkedList{
public:
    Node* head;
    Node* tail;
    LinkedList(){
        head= tail = nullptr;
    }

    void insert_front(int val){
        Node* newNode = new Node(val);

        if(head==nullptr){
            head = tail = newNode;
            return;
        }
        newNode->next = head;
        head = newNode;
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
    LinkedList list;
    int n;
    std::cin>>n;

    for(int i=0; i<n; i++){
        int el;
        std::cin>>el;
        list.insert_front(el);
    }
    list.show();
    return 0;
}