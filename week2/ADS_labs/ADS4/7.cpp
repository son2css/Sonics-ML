#include <iostream>
#include <algorithm>

class Node {
public: 
    int data;
    Node* right;
    Node* left;
    Node(int val) {
        data = val;
        right = left = nullptr;
    }
};

class bts {
public:
    int maxdist = 0;
    Node* root;

    bts() {
        root = nullptr;
    }

    // Iterative insertion to prevent Stack Overflow and TLE on sorted inputs
    void insert(int val) {
        if (root == nullptr) {
            root = new Node(val);
            return;
        }

        Node* current = root;
        while (true) {
            if (val == current->data) {
                // Ignore duplicate values as per problem statement
                return;
            } else if (val > current->data) {
                if (current->right == nullptr) {
                    current->right = new Node(val);
                    return;
                }
                current = current->right;
            } else {
                if (current->left == nullptr) {
                    current->left = new Node(val);
                    return;
                }
                current = current->left;
            }
        }
    }

    int distance(Node* node) {
        if (node == nullptr) return 0;

        int lh = distance(node->left);
        int rh = distance(node->right);

        maxdist = std::max(maxdist, 1 + lh + rh);

        return 1 + std::max(rh, lh);
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    bts* b = new bts();

    int n, el;
    if (!(std::cin >> n)) return 0;

    for (int i = 0; i < n; i++) {
        std::cin >> el;
        b->insert(el);
    }

    b->distance(b->root);

    std::cout << b->maxdist << "\n";

    delete b;
    return 0;
}