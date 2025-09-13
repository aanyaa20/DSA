#include<iostream>
#include <vector>
using namespace std;

struct Node {
    public:
    int data;
    Node* next;
    
 Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    public:
     Node(int data1) {
        data = data1;
        next = nullptr;
    }
}; 


Node* convertArrtoLL(vector<int>&arr)
{
    Node* head = new Node(arr[0]);
    Node* mover = head;

    for(int i=1; i<arr.size(); i++)
    {
        Node* temp = new Node(arr[i]);
        mover->next = temp;
       mover=temp;
    }
    return head;

}

int lengthofLL(Node* head)
{
    int count = 0;
    Node* temp = head;
    while(temp)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

int main()
{
    vector<int>arr= {1,2,3,4,5};
    Node* head = convertArrtoLL(arr);
    cout<<head->data<<endl; // Output the first element to verify
    Node*temp= head;
    while(temp)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
    cout<<"Length of linked list is: "<<lengthofLL(head)<<endl;
}