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
}; 

Node* convertArrToDLL(vector<int>& arr)
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


Node* deleteHead(Node* head)
{
    if(head==NULL || head->next == NULL)
    {
        return NULL;
    }   
    Node* prev= head;
    head= head->next;
    head->back = NULL;
    prev->next = NULL;
    delete prev;
    return head;    
}

Node* deleteTail(Node* head)
{
    if(head==NULL || head->next == NULL)
    {
        return NULL;
    }
    Node* tail = head;
    while(tail->next)
    {
        tail = tail->next;
    }
    Node* newTail = tail->back;
    newTail->next = NULL;
    tail->back = NULL;
    delete tail;
    return head;    
}


Node* deleteAtPosition(Node* head, int k)

{
    if (head == NULL)
    {
        return NULL;
    }
   int cnt=0;
   Node* kNode= head;
    while(kNode)
    {
        cnt++;
        if(cnt == k)
        {
            break;
        }
        kNode = kNode->next;
    }
    Node* prev = kNode->back;
    Node* front = kNode->next;
    if(prev==NULL && front == NULL)
    {
        return NULL;
    }
    else if(prev == NULL)
    {
      return deleteHead(head); // Deleting the head node
    }
    else if(front == NULL)
    {
        return deleteTail(head); // Deleting the tail node
    }
  prev->next = front;
  front->back = prev;
    kNode->next = NULL;
    kNode->back = NULL;
    delete kNode;
    return head;    
}

Node* insertBeforeHead(Node* head, int data)
{
    Node* newHead = new Node(data, head , nullptr);
   
    head->back= newHead;
    return newHead;    
}


Node* insertBeforeTail(Node* head, int val)
{
    if(head->next == NULL)
    {
        return insertBeforeHead(head, val);
    }
    Node* tail = head;
    while(tail->next)
    {
        tail = tail->next;
    }
    Node* prev = tail->back;
    Node* newNode= new Node(val, tail, prev);
   prev->next = newNode;
    tail->back = newNode;
    return head;    
}


Node* insertBeforeKthElement(Node* head, int k, int val)
{
    if(k == 1)
    {
        return insertBeforeHead(head, val);
    }
    Node* temp = head;
    int cnt = 0;
    while(temp)
    {
        cnt++;
        if(cnt == k)
        {
            break;
        }
        temp = temp->next;
            
    }
    Node* prev= temp->back;
    Node* newNode = new Node(val, temp, prev);
   prev->next = newNode;
    temp->back = newNode;
    return head;    
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
    head = deleteHead(head);
    head=   deleteTail(head);
    head = deleteAtPosition(head, 3);
    head= insertBeforeHead(head, 50);
    head = insertBeforeTail(head, 45);
    head = insertBeforeKthElement(head, 5, 100);
    print(head);
    return 0;           
}
