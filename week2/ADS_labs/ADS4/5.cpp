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
    std::vector<int> a;
    Node* root;
    bts(){
        root = new Node(1);
    }
    void insert(Node* nodes[], int par, int ch, int pos){
        if(nodes[par] == nullptr) nodes[par]= new Node(par);
        if(nodes[ch]== nullptr) nodes[ch] = new Node(ch);

        if(pos==1){
            nodes[par]->right = nodes[ch];
        }
        else{
            nodes[par] ->left = nodes[ch];
        }
    }
    void width(Node* node, int depth){
        if(node == nullptr) return;
        
        if(depth == a.size()){
            a.push_back(1);
        }
        else{
            a[depth]++;
        }
        width(node->left, depth +1);
        width(node->right, depth+1);
    }

};
int main(){
    bts* b = new bts();

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n, par, ch, pos;

    std::cin>>n;

    Node* nodes[1045] = {nullptr};
    nodes[1] = b->root;

    for(int i=0; i< n-1; i++){
        std::cin>>par>>ch>>pos;
        b->insert(nodes, par, ch, pos);
    }
    b->width(b->root, 0);

    int max = 0;
    for(int count: b->a){
        max = std::max(max, count);
    }
    std::cout<<max;
    return 0;
}