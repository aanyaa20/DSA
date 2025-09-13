#include <iostream>
#include <stack>

using namespace std;

// Definition of a binary tree node
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Iterative Pre-order Traversal
void preOrderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    
    // Create an empty stack and push the root node
    stack<TreeNode*> s;
    s.push(root);
    
    // Continue until the stack is empty
    while (!s.empty()) {
        // Pop the top node from the stack
        TreeNode* curr = s.top();
        s.pop();
        
        // Print the current node's data
        cout << curr->data << " ";
        
        // Push the right child first so that the left child is processed first
        if (curr->right) {
            s.push(curr->right);
        }
        
        // Push the left child
        if (curr->left) {
            s.push(curr->left);
        }
    }
}

// Helper function to create a simple tree
TreeNode* createTree() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    return root;
}

int main() {
    TreeNode* root = createTree();
    cout << "Pre-order Traversal: ";
    preOrderTraversal(root);
    return 0;
}
