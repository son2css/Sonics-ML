#include <iostream>
#include <vector>

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
        if(node==nullptr){
            node= new Node(val);
            return node;
        }
        if(val<=node->data){
            node->left = insert(node->left, val);
        }
        else{
            node->right = insert(node->right, val);
        }
        return node;
    }
    int cnt_leaf(Node* node){
        if(node==nullptr){
            return 0;
        }
        if(node->left == nullptr && node->right == nullptr){
            return 1;
        }
        return cnt_leaf(node->left) + cnt_leaf(node->right);
    }
};

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    bts* b= new bts();
    int n, el;

    std::cin>>n;
    for(int i=0; i<n; i++){
        std::cin>>el;
        b->root = b->insert(b->root, el);
    }

    std::cout<<b->cnt_leaf(b->root);
}