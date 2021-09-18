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
 
 
int infiCombination(vector<int>&coins,int idx, int tar,string ans)
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
            count+=infiCombination(coins,i,tar-coins[i],ans+to_string(coins[i]));
        }
    }
    return count;
}
 
// 3. Infinite Combination allowed but... infinite supply nahi h .. same coin ko  baar baar nahi le skte 
 
int singleCombination(vector<int>&coins,int idx, int tar,string ans)
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
            count+=singleCombination(coins,i+1,tar-coins[i],ans+to_string(coins[i]));
        }
    }
    return count;
}
 
 
int singlePermutaion(vector<int>&coins,vector<bool>& vis,int idx,int tar, string ans)
{
    if(tar==0)
    {
        cout<<ans<<" ";
        return 1;
    }
    int count=0;
    for(int i=0;i<coins.size();i++)
    {
        if(!vis[i] && tar-coins[i]>=0)
        {    vis[i] = true ; 
            count+=singlePermutaion(coins,vis,i,tar-coins[i], ans+to_string(coins[i]));
            vis[i] = false ;  
        }
    }
    return count;
}
 int infiPermutation_subseq(vector<int> &coins, int tar,int idx, string asf) 
 {
        if (tar == 0 || idx >=coins.size()) 
        {
            if (tar == 0) 
            {
               cout << asf << " " ; 
                return 1;
            }
            return 0;
        }
 
        int count = 0;
        if (tar - coins[idx] >= 0)
        count += infiPermutation_subseq(coins, tar - coins[idx], 0 , asf +to_string(coins[idx]));
        count += infiPermutation_subseq(coins, tar, idx + 1, asf);
 
        return count;
    }
int infiCombination_subseq(vector<int> &coins , int tar, int idx, string asf) 
{
        if (tar == 0 || idx >= coins.size()) 
        {
            if (tar == 0) 
            {
                cout << asf << " " ; 
                return 1;
            }
            return 0;
        }
 
        int count = 0;
        if (tar - coins[idx] >= 0)
        count += infiCombination_subseq(coins, tar - coins[idx], idx , asf + to_string(coins[idx]));
        count += infiCombination_subseq(coins, tar, idx + 1, asf);
 
        return count;
    }
int singleCombination_subseq(vector<int> &coins, int tar, int idx, string asf) 
{
        if (tar == 0 || idx >= coins.size()) 
        {
            if (tar == 0) 
            {
                cout << asf << " ";  
                return 1;
            }
            return 0;
        }
 
        int count = 0;
        if (tar - coins[idx] >= 0)
        count += singleCombination_subseq(coins, tar - coins[idx], idx + 1 , asf + to_string(coins[idx]));
        count += singleCombination_subseq(coins, tar, idx + 1, asf);
 
        return count;
}
int singlePermutaion_seq(vector<int> &coins ,vector<bool> & vis,int tar,int idx , string asf){
    if(tar == 0 || idx>= coins.size())
    {
        if(tar==0){
            cout << asf << " " ;
            return 1 ;
        }
        return 0 ;
    }
    int count = 0 ;
    if(tar-coins[idx] >= 0 && !vis[idx] ){
       vis[idx] = true ;  
    count += singlePermutaion_seq(coins,vis,tar-coins[idx],idx+1,asf+to_string(coins[idx]));
      vis[idx] = false ; 
    }
 
      if ( !vis[idx]){
            vis[idx] = true;
            count += singlePermutaion_seq(coins,vis,tar,idx+1,asf);
            vis[idx] = false;
        }
 
     return count ;
}
 
 
int main()
{
    vector<int> coins={1,1,1,1,1,1,1};
    int n = coins.size() ; 
    vector<bool> vis(n,false) ; 
    int tar=4;
     int ans1=infiPermutaion(coins,tar,"");
     cout<<endl;
    cout<<"Number of ways in infiPermutaion " <<ans1 << endl;
     cout << "---------------------------" << endl ;
     int ans2=infiCombination(coins,0,tar,"");
     cout<<endl;
     cout<<"Number of ways in infiCombination "<<ans2 << endl ;
     cout << "---------------------------" << endl ;
     int ans3 = singleCombination(coins,0,tar,"") ; 
     cout<<endl;
    cout<<"Number of ways in singleCombination "<<ans3 << endl;
    cout << "---------------------------" << endl ;
     int ans4 = singlePermutaion(coins,vis,0,tar,"") ;
    cout<<endl;
    cout<<"Number of ways in singlePermutaion "<<ans4 << endl;
    cout << "---------------------------" << endl ;
     int ans5 = infiPermutation_subseq(coins,tar,0,"") ;
    cout<<endl;
    cout<<"Number of ways in infiPermutation_subseq "<<ans5 << endl;
    cout << "---------------------------" << endl ;
     int ans6 = infiCombination_subseq(coins,tar,0,"") ;
    cout<<endl;
    cout<<"Number of ways in infiCombination_subseq "<<ans6<< endl;
    cout << "---------------------------" << endl ;
     int ans7 = singleCombination_subseq(coins,tar,0,"") ;
    cout<<endl;
    cout<<"Number of ways in singleCombination_subseq "<<ans7 << endl;
    cout << "---------------------------" << endl ;
    int ans8 = singlePermutaion_seq(coins,vis,tar,0,"") ;
    cout<<endl;
     cout<<"Number of ways in singlePermutaion_seq "<<ans8<< endl;
     cout << "---------------------------" << endl ;
 
}