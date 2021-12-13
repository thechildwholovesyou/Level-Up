// week 1

//  Find pair
#include<bits/stdc++.h>
using namespace std;

void print_pairs(vector<int>&v,int key)
{
    sort(v.begin(),v.end());
    int i=0;
    int j=v.size()-1;
    while(i<=j)
    {
        if(v[i]+v[j]==key)
        {
            cout<<v[i]<<" "<<v[j]<<endl;
            break;
        }
        else if(v[i]+v[j]<key)
            i++;
        else
            j--;
    }
    return;
}

int main()
{
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        int data;
        cin>>data;
        v.push_back(data);
    }
    int key;
    cin>>key;
    print_pairs(v,key);
}

// 
