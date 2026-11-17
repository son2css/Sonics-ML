#include <iostream>
#include <vector>
class Node{
public:
    int data;
    Node* right;
    Node* left;
    Node(int val){
        data = val;
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
        if(val> node->data){
            node->right= insert(node->right, val);
        }
        else{
            node->left = insert(node->left, val);
        }
        return node;
    }
    void wizard(Node* node, int& sum){
        if(node==nullptr) return;
        wizard(node->right, sum);
        sum+=node->data;

        node->data = sum;
        std::cout<<node->data<<" ";
        wizard(node->left, sum);
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
    int samsa = 0;
    b->wizard(b->root,samsa);
}