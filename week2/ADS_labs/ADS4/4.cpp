#include <iostream>
#include <vector>
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

class bts{
public:
    Node* root;
    std::vector<int> a;
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

    void sum_of_each_level(Node* node, int depth){
        if(node == nullptr) return;

        if(depth == a.size()) a.push_back(node->data);
        else a[depth]+= node->data;

        sum_of_each_level(node->left, depth+1);
        sum_of_each_level(node->right, depth+1);
    }
};

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    bts* b = new bts();

    int n, el;
    
    std::cin>>n;
    while(n--){
        std::cin>>el;
        b->root = b->insert(b->root, el);
    }

    b->sum_of_each_level(b->root, 0);
    std::cout<<b->a.size()<<"\n";
    for(int i=0; i<b->a.size(); i++){
        std::cout<<b->a[i]<<" ";
    }
}