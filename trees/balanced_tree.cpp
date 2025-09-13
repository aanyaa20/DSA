#include<iostream>
#include<vector>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

int dfsHeight(Node* root)
{
    if(root==NULL) return 0;

    int lh= dfsHeight(root->left);
    if(lh==-1) return -1;

    int rh= dfsHeight(root->right);
    if(rh==-1) return -1;

    if(abs(lh-rh)>1) return -1;

    return 1+max(lh, rh);

}

bool isBalanced(Node* root)
{
    return dfsHeight(root)!= -1;
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

    bool balanced = isBalanced(root);
    if (balanced) {
        cout << "The tree is balanced." << endl;
    } else {
        cout << "The tree is not balanced." << endl;
    }
}