#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
Node(int value)
{
  data=value;
 next= NULL;
}
};
class LinkedList{
    private:
    Node* first;
    public:
    LinkedList()
    {
        first= NULL;
    }

    void InsertatHead(int data)
    {
        Node* temp= new Node(data);
        temp-> next= first;
        first= temp;
    }

    void InsertMutiple(int n)
    {
        for(int i=0; i<n; i++)
        {
            int data;
            cout<<"Enter data for node"<<i+1<<":";
            cin>>data;
            InsertatHead(data);

                   }
    }


    void display()
    {
        Node*temp= first;
    while(temp!= NULL)
        {
            cout<<temp->data;
            temp= temp-> next;
        }
    
}
int count()
{Node*p= first;
int count=0;
while(p!=NULL)
{
    count++;
    p= p-> next;
}
return count;
}

void displaySpecific()
{

}
};

int main()
{
    LinkedList list;
    int n;
    cout<<"Enter number of nodes:"<<endl;
    cin>>n;


    list.InsertMutiple(n);
list.display();
cout<<"The number of nodes are:"<<list.count();
}

Hi my name is Ansh