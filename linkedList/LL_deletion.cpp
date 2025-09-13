#include<iostream>
#include<vector>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node(int data1, Node* next1)
    {
        data = data1;
        next = next1;
    }  
    Node(int data1)
    {
        data=data1;
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

Node* removeHead(Node* head)
{
   if(head == nullptr)
   {
       return head; // If the list is empty, return null
   }
   Node* temp = head;
   head = head->next; // Move head to the next node
   delete temp; // Delete the old head node
   return head; // Return the new head
}

Node* removetail(Node* head)
{
    if(head==nullptr || head->next== nullptr)
    {
        return nullptr;
    }
    Node*temp= head;
    while(temp->next->next != nullptr)
    {
        temp= temp->next;
    }
    free(temp->next);
    temp->next= nullptr;
    return head;
}

Node* removeK(Node* head, int k)
{
  if(head== nullptr)    return head;
  if(k==1)
  {
    Node* temp = head;
    head = head->next; // Move head to the next node
    delete temp; // Delete the old head node
    return head; // Return the new head
  }
  int count = 1;
  Node* temp = head;
  Node* prev = nullptr;
  while (temp != nullptr) {
    if (count == k) {
      if (prev != nullptr) {
        prev->next = temp->next; // Bypass the current node
        delete temp;
      }
      break;
    }
    prev = temp;
    temp = temp->next;
    count++;
  }
  return head;
}


Node* insertHead(Node* head, int data)
{
    Node* temp = new Node(data, head);
 // Point the new node to the current head
    return temp; // Return the new head
}

Node* insertTail( Node*head, int val)
{
    if(head==NULL)
    {
        return new Node(val);
    }
    Node*temp= head;
    while(temp->next)
    {
        temp= temp->next;
    }
    Node* newNode= new Node(val);
    temp->next= newNode; // Link the new node at the end
    return head; // Return the unchanged head
}

Node* insertPosition(Node* head, int data, int pos)
{
    if(head == nullptr)
    {
        if(pos==1)
        {
            return new Node(data);
        }
        else
        {
            return nullptr; // Invalid position
        }}
        if(pos==1)
        {
            Node* newHead= new Node(data, head);

        }
        int cnt=0;
        Node*temp= head;
        while(temp)    {
            cnt++;
            if(cnt== pos-1)
            {
                Node*x = new Node(data);
                x->next = temp->next; // Link the new node to the next node
                temp->next = x; // Link the previous node to the new node
                break;
            }
            temp = temp->next;
        }
    return head; // Return the unchanged head
}

void print(Node* head)
{
    while(head)
    {
       cout<<head->data<<" ";
        head=head->next;

    }
    cout<<endl;
}
int main()
{
    vector<int>arr= {12, 8, 5, 6, 4};
    Node*head= convertArrtoLL(arr);
    head = removeHead(head); 
    // Remove the head node
    head = removetail(head); // Remove the tail node    
    head= removeK(head, 2); // Remove the 3rd node
    head= insertHead(head, 10);// Insert a new head with value 10
    head= insertTail(head, 25); // Insert a new tail with value 25
    head = insertPosition(head, 45, 2);    
     head = insertPosition(head, 9, 7);

    print(head);
}
