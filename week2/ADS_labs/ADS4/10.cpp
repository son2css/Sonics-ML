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
        if(node==nullptr){
            node = new Node(val);
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
    void K(Node* node, int& result, int& step, int k){
        if(node==nullptr || result != -1){
            return;
        }
        K(node->left, result, step, k);
        step++;
        if(step==k){
            result= node->data;
            return;
        }
        K(node->right, result, step, k);
    }
};

int main(){
    bts* b = new bts();
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, el, k;
    std::cin>>n>>k;
    for(int i=0; i<n; i++){
        std::cin>>el;
        b->root = b->insert(b->root, el);
    }
    int result = -1;
    int step = 0;
    b->K(b->root, result, step, k);
    std::cout<<result;
}