#include<iostream>
#include <vector>
using namespace std;

struct Node {
    public:
    int data;
    Node* next;
    Node* back;
    
 Node(int data1, Node* next1, Node* back1) {
        data = data1;
        next = next1;
        back= back1;
    }

    public:
     Node(int data1) {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
}; Node* convertArrToDLL(vector<int>& arr)
{
    Node* head = new Node(arr[0]);
    Node* prev = head;

    for(int i = 1; i < arr.size(); i++)
    {
        Node* temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
    prev= temp;
    }
    return head;
}

Node* reverseDLL(Node* head)
{
    if(head == NULL || head->next == NULL)
    {
        return head;
    }
    Node* prev = NULL;
    Node* current = head;
    
    while(current != NULL)
    {
        prev = current->back; // Store next node
        current->back = current->next;     // Reverse the next pointer
        current->next = prev; // Set back pointer to the next node
              // Move prev to current
        current = current->back;       // Move to the next node
    }
    return prev->back; // New head of the reversed list
}

void print(Node* head)
{
    while(head)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
} 
    int main()
{
    vector<int>arr= {1,5,3,4, 67, 89,8,9};
    Node* head = convertArrToDLL(arr);
  head= reverseDLL(head);
    print(head);
    return 0;           
}
