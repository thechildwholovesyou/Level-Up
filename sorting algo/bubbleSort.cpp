#include<bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int>&nums)
{
    int n=nums.size();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(nums[j]>nums[j+1])
                swap(nums[j],nums[j+1]);
        }
    }
}
void insertionSort(vector<int>&nums)
{
    int n=nums.size();
    for(int i=0;i<n;i++)
    {
        for(int j=i-1;j>=0;j--)
        {
            if(nums[j]>nums[j+1])
                swap(nums[j],nums[j+1]);
        }
    }
}
void selectionSort(vector<int>&arr)
{
    int n=arr.size();
    for(int i=0;i<n-1;i++)
    {
        int mint_idx=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[mint_idx])
                mint_idx=j;
        }
        swap(arr[mint_idx],arr[i]);
    }
}

int main()
{
    int n;
    cin>>n;
    vector<int> v{1,3,2,5,4};
    bubbleSort(v);

    for(auto ele:v)
        cout<<ele<<" ";
    return 0;
}