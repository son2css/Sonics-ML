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

class bst{
public:
    Node* root;

    bst(){
        root = nullptr;
    }

    Node *insert(Node* node, int val){
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
};
int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    bst* b = new bst();
    int n,m;
    std::cin>>n>>m;
    for(int i=0; i<n; i++){
        int el;
        std::cin>>el;
        b->root = b->insert(b->root, el);
    }
    while(m--){
        std::string s;
        std::cin>>s;
        Node* temp = b->root;
        bool vision = true;

        for(char c : s){
            if(c == 'L'){
                temp = temp->left;
            }else if(c=='R'){
                temp = temp->right;
            }
            if(temp == nullptr){
                vision = false;
                break;
            }
        }
        if(vision){
            std::cout<<"YES"<<"\n";
        }else{
            std::cout<<"NO"<<"\n";
        }
    }
}