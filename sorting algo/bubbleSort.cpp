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