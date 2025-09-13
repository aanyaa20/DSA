// // #include <iostream>
// // #include <stack>

// // using namespace std;

// // // Definition of a binary tree node
// // struct TreeNode {
// //     int data;
// //     TreeNode* left;
// //     TreeNode* right;
    
// //     TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
// // };

// // // Iterative Pre-order Traversal
// // void preOrderTraversal(TreeNode* root) {
// //     if (root == nullptr) {
// //         return;
// //     }
    
// //     // Create an empty stack and push the root node
// //     stack<TreeNode*> s;
// //     s.push(root);
    
// //     // Continue until the stack is empty
// //     while (!s.empty()) {
// //         // Pop the top node from the stack
// //         TreeNode* curr = s.top();
// //         s.pop();
        
// //         // Print the current node's data
// //         cout << curr->data << " ";
        
// //         // Push the right child first so that the left child is processed first
// //         if (curr->right) {
// //             s.push(curr->right);
// //         }
        
// //         // Push the left child
// //         if (curr->left) {
// //             s.push(curr->left);
// //         }
// //     }
// // }

// // // Helper function to create a simple tree
// // TreeNode* createTree() {
// //     TreeNode* root = new TreeNode(1);
// //     root->left = new TreeNode(2);
// //     root->right = new TreeNode(3);
// //     root->left->left = new TreeNode(4);
// //     root->left->right = new TreeNode(5);
// //     root->right->left = new TreeNode(6);
// //     root->right->right = new TreeNode(7);
// //     return root;
// // }

// // int main() {
// //     TreeNode* root = createTree();
// //     cout << "Pre-order Traversal: ";
// //     preOrderTraversal(root);
// //     return 0;
// // }


// #include <iostream>
// #include <stack>

// using namespace std;

// class Node {
// public:
//     int data;
//     Node* left;
//     Node* right;

//     Node(int val) {
//         data = val;
//         left = right = nullptr;
//     }
// };

// class BinaryTree {
// public:
//     Node* root;

//     BinaryTree() {
//         root = nullptr;
//     }

//     // Iterative Pre-order Traversal
//     void iterativePreOrder(Node* root) {
//         if (root == nullptr)
//             return;

//         stack<Node*> nodeStack;
//         nodeStack.push(root);

//         while (!nodeStack.empty()) {
//             Node* currentNode = nodeStack.top();
//             nodeStack.pop();

//             // Process the current node
//             cout << currentNode->data << " ";

//             // Push right and then left child to the stack
//             if (currentNode->right)
//                 nodeStack.push(currentNode->right);
//             if (currentNode->left)
//                 nodeStack.push(currentNode->left);
//         }
//     }
// };

// int main() {
//     BinaryTree tree;

//     // Constructing the tree
//     tree.root = new Node(1);
//     tree.root->left = new Node(2);
//     tree.root->right = new Node(3);
//     tree.root->left->left = new Node(4);
//     tree.root->left->right = new Node(5);
//     tree.root->right->left = new Node(6);
//     tree.root->right->right = new Node(7);

//     cout << "Pre-order Traversal: ";
//     tree.iterativePreOrder(tree.root);

//     return 0;
// }


#include <iostream>
#include <stack>
using namespace std;

// Node structure definition
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// BinaryTree class definition
class BinaryTree {
public:
    Node* root;

    BinaryTree() {
        root = nullptr;
    }

    // Pre-order traversal using iterative method
    void preOrderTraversal() {
        if (root == nullptr)
            return;

        stack<Node*> nodeStack;
        nodeStack.push(root);

        while (!nodeStack.empty()) {
            Node* currentNode = nodeStack.top();
            cout << currentNode->data << " ";
            nodeStack.pop();

            // Push right child first so that left is processed first
            if (currentNode->right != nullptr) {
                nodeStack.push(currentNode->right);
            }
            if (currentNode->left != nullptr) {
                nodeStack.push(currentNode->left);
            }
        }
    }

    // Function to insert nodes (for testing)
    Node* insertNode(Node* node, int data) {
        if (node == nullptr) {
            return new Node(data);
        }
        if (data < node->data) {
            node->left = insertNode(node->left, data);
        } else {
            node->right = insertNode(node->right, data);
        }
        return node;
    }
};

int main() {
    BinaryTree tree;

    // Insert nodes into the binary tree
    tree.root = tree.insertNode(tree.root, 10);
    tree.insertNode(tree.root, 6);
    tree.insertNode(tree.root, 14);
    tree.insertNode(tree.root, 4);
    tree.insertNode(tree.root, 8);
    tree.insertNode(tree.root, 12);
    tree.insertNode(tree.root, 16);

    // Perform pre-order traversal
    cout << "Pre-order Traversal: ";
    tree.preOrderTraversal();

    return 0;
}

