#include<iostream>
#include<vector>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};



int maxDepth(Node* root)
{
    if(root==NULL) return 0;

    int lh= maxDepth(root->left);
    int rh= maxDepth(root->right);

    return 1+max(lh, rh);
}
void printVector(const vector<int>& vec) {
   
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;
}


int main()
{
      Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->left->right = new Node(6);
    root->right->left->left= new Node(5);
    root->right->left->left->left= new Node(7);

    int depth = maxDepth(root);
    cout << "Maximum depth of the tree: " << depth << endl;
}