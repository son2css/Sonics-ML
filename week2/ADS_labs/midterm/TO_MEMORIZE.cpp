#include <iostream>

struct Node {
    int val;
    Node* next;
    Node(int x) {
        val = x;
        next = nullptr;
    }
};

class LinkedList {
public:
    Node* head;
    Node* tail;

    LinkedList() {
        head = tail = nullptr;
    }

    // add a value to the end of the list
    void add(int x) {
        Node* node = new Node(x);
        if (head == nullptr) {
            head = tail = node;
            return;
        }
        tail->next = node;
        tail = node;
    }

    // delete every node whose value is divisible by d
    void removeDivisible(int d) {
        // 1. delete matching nodes at the head (there can be several in a row)
        while (head != nullptr && head->val % d == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        if (head == nullptr) {          // the whole list was deleted
            tail = nullptr;
            return;
        }

        // 2. look one step ahead; move only when nothing was deleted
        Node* curr = head;
        while (curr->next != nullptr) {
            if (curr->next->val % d == 0) {
                Node* temp = curr->next;
                curr->next = temp->next;
                if (temp == tail) tail = curr;   // keep tail correct
                delete temp;
            } else {
                curr = curr->next;
            }
        }
    }

    bool empty() {
        return head == nullptr;
    }

    void show() {
        for (Node* curr = head; curr != nullptr; curr = curr->next) {
            std::cout << curr->val << " ";
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    LinkedList list;                    // a plain object, no pointer needed
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        list.add(x);
    }

    int target;
    std::cin >> target;

    list.removeDivisible(target);

    if (list.empty()) std::cout << "EMPTY";
    else list.show();

    return 0;
}





#include <iostream>
#include <vector>

void max_heap(std::vector<int>& v, int i){
    int n = v.size();
    while(2 * i < n) {
        int c = 2 * i;
        if (c+1 < n && v[c] < v[c+1]) {
            c = c + 1;
        }
        if (v[c] > v[i]) {
            std::swap(v[c], v[i]);
            i = c;
        } else break;
    }
}

int main(){
    int n;
    std::cin>>n;

    std::vector<int> v(n+1);

    for(int i=1; i<n+1; i++){
        std::cin>>v[i];
    }
    for (int i = n / 2; i >= 1; i--) {
        max_heap(v, i);
    }
    for (int i = 1 ; i <= n; ++i) {
        std::cout << v[i] << " ";
    }
    std::sort(v.begin()+1, v.end());
    std::cout<<"\n";
    for (int i = 1 ; i <= n; ++i) {
        std::cout << v[i] << " ";
    }
}