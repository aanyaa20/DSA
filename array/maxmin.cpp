#include<iostream>
using namespace std;


int sumOfElements(int arr[],int size)
{
    int sum=0;
    for(int i=0; i<size; i++)
    {
        sum+=arr[i];
    }
    return sum;
}
int main()
{
    int size;
    cin>>size;
     int arr[size];

    for(int i=0; i<size; i++)
    {
        cin>>arr[i];
    }
int sum=  sumOfElements(arr,size);
    cout<<"Sum of elements: "<<sum<<endl;
}