#include <iostream>

class Node {
    public:
    int value;
    Node* left;
    Node* right;
    
    Node(int value) {
        this->value = value;
        left = NULL;
        right = NULL;
    }
};
class Tree {
    Node* root;
    private:
    std::vector<int> traversalArray;
    public:
    Tree() {
        Node* root = NULL;
    }
    void insert(int val) {
        if (root==NULL) {
            insertIntoEmpty(val);
            return;
        }
        int alreadyIn=0;
        Node* prev=NULL, *curr=root;
        while (curr!=NULL) {
            if (val < curr->value) {
                prev=curr;
                curr=curr->left;
            }
            else if (val > curr->value) {
                prev=curr;
                curr=curr->right;
            }
            else {
                alreadyIn=1;
            }
        }
        if (!alreadyIn) {
            if (val<prev->value) {
                prev->left = new Node(val);
            }
            if (val>prev->value) {
                prev->right = new Node(val);
            }
        }
    }
    std::vector<int> inorderTraversal() {
        traversalArray = {};
        lvr(root);
        return traversalArray;
    }
    std::vector<int> preorderTraversal() {
        traversalArray = {};
        vlr(root);
        return traversalArray;
    }
    std::vector<int> postorderTraversal() {
        traversalArray = {};
        lrv(root);
        return traversalArray;
    }
    private:
    void insertIntoEmpty(int val) {
        root = new Node(val);
    }
    void lvr(Node* root) {
        if (root==NULL) {
            return;
        }
        lvr(root->left);
        traversalArray.push_back(root->value);
        lvr(root->right);
    }
    void vlr(Node* root) {
        if (root==NULL) {
            return;
        }
        traversalArray.push_back(root->value);
        vlr(root->left);
        vlr(root->right);
    }
    void lrv(Node* root) {
        if (root==NULL) {
            return;
        }
        lrv(root->left);
        lrv(root->right);
        traversalArray.push_back(root->value);
        
    }
};