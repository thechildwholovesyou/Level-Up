// coin change wale cases

// 1: Infinite Permutation 

#include<bits/stdc++.h>
using namespace std;

int infiPermutaion(vector<int>&coins,int tar,string ans)
{
    if(tar==0)
    {
        cout<<ans<<" ";
        return 1;
    }

    int count=0;
    for(int i=0;i<coins.size();i++)
    {
        if(tar-coins[i]>=0)
        {
            count+=infiPermutaion(coins,tar-coins[i],ans+to_string(coins[i]));
        }
    }
    return count;
}

// 2. Infinite Combination 


int infiCombination1(vector<int>&coins,int idx, int tar,string ans)
{
    if(tar==0)
    {
        cout<<ans<<" ";
        return 1;
    }

    int count=0;
    for(int i=idx;i<coins.size();i++)
    {
        if(tar-coins[i]>=0)
        {
            count+=infiCombination1(coins,i,tar-coins[i],ans+to_string(coins[i]));
        }
    }
    return count;
}

// 3. Infinite Combination allowed but... infinite supply nahi h .. same coin ko  baar baar nahi le skte 

int infiCombination2(vector<int>&coins,int idx, int tar,string ans)
{
    if(tar==0)
    {
        cout<<ans<<" ";
        return 1;
    }

    int count=0;
    for(int i=idx+1;i<coins.size();i++)
    {
        if(tar-coins[i]>=0)
        {
            count+=infiCombination2(coins,i,tar-coins[i],ans+to_string(coins[i]));
        }
    }
    return count;
}

// single Combination  allowed  : ek baar me ek hi coin le skta hu 
int singleCombination(vector<int>&coins,int idx,int tar, string ans)
{
    if(tar==0)
    {
        cout<<ans<<" ";
        return 1;
    }
    int count=0;
    for(int i=idx+1;i<coins.size();i++)
    {
        if(tar-coins[i]>=0 && coins[i]>=0)
        {
            coins[i]=-coins[i];
            count+=singleCombination(coins,i,tar-coins[i], ans+to_string(coins[i]));
            coins[i]=-coins[i];

        }
    }
    return count;
}



int main()
{
    vector<int> coins={2,3,5,7};
    int tar=10;
    // int ans=infiPermutaion(coins,tar,"");
    int ans=infiCombination1(coins,0,tar,"");
    cout<<endl;
    cout<<"Number of ways "<<ans;
}