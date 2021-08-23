#include<bits/stdc++.h>
using namespace std;


int* allIndices(int arr[],int idx,int size,int data,int c)
{
   if(idx==size){
       int base[c];
       return base;
   }
   if(arr[idx]==data)
   {
       int ans[]=allIndices(arr,idx+1,size,data,c+1);
       ans[c]=idx;
       return ans;
   }
   else
   {
       int ans[]=allIndices(arr,idx+1,size,data,c);
       return ans;
   }

}

int main()
{
    // string s="abc";
    // vector<string> ans=subsequence(s);
    // for(auto ele : ans)
    //     cout<<ele<<" ";

    int arr[]={1,2,2,2,23,4,5};
    int size=sizeof(arr)/sizeof(arr[0]);

    int* ans=allIndices(arr,0,size-1,2,0);

    int n=sizeof(ans)/sizeof(ans[0]);
    for(int i=0;i<n;i++)
        cout<<ans[i]<<" ";

    return 0;
    
}