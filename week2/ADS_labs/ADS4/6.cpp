#include <iostream>
#include <vector>

class Node{
public:
    int data;
    Node* right;
    Node* left;

    Node(int data){
        this->data = data;
        right = left= nullptr;
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

        if(val<=node->data){
            node->left = insert(node->left, val);
        }else{
            node->right = insert(node->right, val);
        }
        return node;
    }
    int triangle(Node* node){
        if(node == nullptr) return 0;
        int cnt = (node->left && node->right)?1:0;
        return cnt + triangle(node->left) + triangle(node->right);
    }
};

int main(){
    bts* b = new bts();
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n, el;
    std::cin>>n;

    for(int i=0; i<n; i++){
        std::cin>>el;
        b->root = b->insert(b->root, el);
    }
    int num = b->triangle(b->root);

    std::cout<<num;
    return 0;
}