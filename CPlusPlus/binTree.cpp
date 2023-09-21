#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  	
  	void preOrder(Node *root) {
		
      	if( root == NULL )
          	return;
      
      	std::cout << root->data << " ";
      	
      	preOrder(root->left);
      	preOrder(root->right);
    }

/*
Node is defined as 

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

*/

    Node * insert(Node * root, int data) {
        if (root==NULL) {
            root = new Node(data);
            return root;
        }
        Node* curr = root;
        Node* prev = NULL;
        while (curr != NULL) {
            cout << curr->data << " ";
            if (data < curr->data) {
                prev=curr;
                curr = curr->left;
            }
            else {
                prev=curr;
                curr = curr->right;
            }
        }
        if (data < curr->data) {
            prev->left = new Node(data);
        }
        else {
            prev->right = new Node(data);
        }
        

        return root;
    }

};

int main() {
  
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
  	
    myTree.preOrder(root);
  
    return 0;
}
