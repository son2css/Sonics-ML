#include <iostream>
#include <algorithm>
class Node{
public:
    int data;
    Node* right;
    Node* left;

    Node(int val){
        data = val;
        right = nullptr;
        left = nullptr;
    }
};

class bst{
public:
    Node* root;
    bst(){
        root = nullptr;
    }

    Node* insert(Node* node, int val){
        if(node == nullptr){
            node = new Node(val);
            return node;
        }

        if(val > node->data){
            node->right = insert(node->right, val);
        }
        else{
            node->left = insert(node->left, val);
        }
        return node;
    }

    int size(Node* node){
        if(node == nullptr) return 0;
        return 1 + size(node->left) + size(node->right);
    }
    Node* search(Node* temp, int val){

        if(temp == nullptr || temp->data == val){
            return temp;
        }

        if(val> temp->data){
            return search(temp->right, val);
        }
        else{
            return search(temp->left, val);
        }
    }
};

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    bst* b = new bst();

    int n, el, target;
    std::cin>>n;

    while(n--){
        std::cin>>el;
        b->root = b->insert(b->root, el);
    }

    std::cin>>target;

    Node* seek = b->search(b->root, target);

    std::cout<<b->size(seek);
}