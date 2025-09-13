#include<iostream>
using namespace std;
 
int firstOccurence(int arr[], int size, int key)
{
    int start = 0;
    int end = size - 1;
    int mid = start + (end - start) / 2;
    int ans = -1;

    while(start <= end)
    {
        if(arr[mid] == key)
        {
            ans = mid;
            end = mid - 1; // look for earlier occurrence
        }
        else if(arr[mid] < key)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }
    return ans;
}

int lastOccurence(int arr[], int size, int key)
{
    int start = 0;
    int end = size - 1;
    int mid = start + (end - start) / 2;
    int ans = -1;

    while(start <= end)
    {
        if(arr[mid] == key)
        {
            ans = mid;
            start = mid + 1; // look for later occurrence
        }
        else if(arr[mid] < key)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }
    return ans;
}
int main()
{
    int even[5]= {1,2,3,3,5};
cout<<"First occurenece of 3 is at index: "<<firstOccurence(even, 5, 3)<<endl;
    cout<<"Last occurenece of 3 is at index: "<<lastOccurence(even, 5, 3)<<endl;

    int odd[5]= {1,2,3,3,3};
    cout<<"First occurenece of 3 is at index: "<<firstOccurence(odd, 5, 3)<<endl;
    cout<<"Last occurenece of 3 is at index: "<<lastOccurence(odd, 5, 3)<<endl;

    return 0;
}