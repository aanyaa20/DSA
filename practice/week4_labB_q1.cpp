#include<iostream>
using namespace std;

int main()
{
    int n,i;
    cout<<"Enter the size:";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements";
    for( i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    
    int key;
    cout<<"Enter key";
    cin>>key;

    for( i=0; i<n-1; i++)
    {
        for(int j=0; j<n-i; j++)
        {
            if(arr[j+1]<arr[j])
            {
                int temp;
                temp= arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;

            }
        }
    }
    cout<<"SORTED ARRAY"<<endl;
     for(i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";}
int mid;
    if(n%2==0)
    mid=(n+1)/2;  else
    mid= n/2;

    for( i=0; i<n; i++)
    {
        if(key==arr[mid])
       { cout<<"element found at "<<i<<"index"<<endl;
        break;}
        else if(key<arr[i])
        {
while(i<mid)
{ if(key==arr[i])
{cout<<"Element found at index "<<i<<endl;
break;}}
        }

        else
        {
            while(i>mid)
            {
              if(key==arr[i])
{cout<<"Element found at index "<<i<<endl;
break;}   
            }
        }
    }
}

   
