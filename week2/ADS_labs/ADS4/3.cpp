#include <iostream>

class Node{
public: 
    int data;
    Node* right;
    Node* left;

    Node(int val){
        data = val;
        right = left = nullptr;
    }
};

class bts{
public:
    Node* root;
    bts(){
        root = nullptr;
    }

    Node* insert(Node* node, int val){
        if(node == nullptr){
            node = new Node(val);
            return node;
        }

        if(val>node->data){
            node->right = insert(node->right, val);
        }
        else{
            node->left = insert(node->left, val);
        }

        return node;
    }

    Node* search(Node* node, int val){

        if( (node == nullptr) || node->data == val){
            return node;
        }

        if(val>node->data){
            return search(node->right, val);
        }
        else{
            return search(node->left, val);
        }
    }
    void open_sesame(Node* node){
        if(node == nullptr) return;
        std::cout<<node->data<<" ";
        open_sesame(node->left);
        open_sesame(node->right);
    }
};

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    bts* b = new bts();

    int n, el, target;

    std::cin>>n;
    while(n--){
        std::cin>>el;
        b->root = b->insert(b->root, el);
    }
    std::cin>>target;
    Node* bruh = b->search(b->root, target);

    b->open_sesame(bruh);

}