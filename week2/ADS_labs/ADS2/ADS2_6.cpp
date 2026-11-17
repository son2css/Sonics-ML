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
        tail ->next = newNode;
        tail = newNode;
    }
    void Merge(LinkedList &mylist2){
        if(head== nullptr){
            head = mylist2.head;
            tail= mylist2.tail;
            return;
        }
        if(mylist2.head == nullptr) return;

        Node dummy(0);
        Node* mergedtail = &dummy;

        Node* curr1 = head;
        Node* curr2 = mylist2.head;

        while(curr1!= nullptr && curr2!= nullptr){
            if(curr1->data <= curr2->data){
                mergedtail->next = curr1;
                mergedtail = curr1;
                curr1 = curr1->next;
            }else{
                mergedtail->next = curr2;
                mergedtail = curr2;
                curr2= curr2->next;
            }
        }
        if(curr1!=nullptr){
            mergedtail->next = curr1;
        }
        if(curr2!=nullptr){
            mergedtail->next = curr2;
        }
        head = dummy.next;       
        while(mergedtail->next!=nullptr){
            mergedtail = mergedtail->next;
        }
        tail = mergedtail;

        mylist2.head = nullptr;
        mylist2.tail = nullptr;
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
    LinkedList mylist1;
    LinkedList mylist2;
    int n;
    std::cin>>n;
    int element;

    for(int i =0; i<n; i++){
        std::cin>>element;
        mylist1.Add(element);
    }
    std::cin>>n;
    for(int i=0; i<n; i++){
        std::cin>>element;
        mylist2.Add(element);
    }
    mylist1.Merge(mylist2);
    mylist1.Show();
}
