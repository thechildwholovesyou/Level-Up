#include<bits/stdc++.h>
using namespace std;

void display(vector<int> dp)
{
    for(int ele:dp)
        cout<<ele<<" ";
    cout<<endl;
}

void display2d(vector<vector<int>>dp)
{
    for(int i=0;i<dp.size();i++)
    {
        for(int j=0;j<dp[0].size();j++)
        {
            cout<<dp[i][j]<<" ";
        }
    }
}

// fibonacci recursion 
int fibo_rec(int n)
{
    if(n<=1) return n;
    int ans=fibo_rec(n-1)+fibo_rec(n-2);
    return ans;
}
// fibonacci memoization 

int fib_memo(int n,vector<int>dp)
{
    if(n<=1)
        return dp[n]=n;
    if(dp[n]!=0)
        return dp[n];
    int ans = fib_memo(n-1,dp)+fib_memo(n-2,dp);
    return dp[n]=ans;
}

// fibonacci tabulation 

// int fib_tabu(){

// }

// maze path recursion 

int mazePath_HVD(int sr,int sc,int er,int ec, string ans)
{
    if(sr==er and sc==ec)
    {
        cout<<ans<<endl;
        return 1;
    }

    int count=0;
    if(sc+1<=ec and sr+0<=er)
        count+=mazePath_HVD(sr,sc+1,er,ec,ans+"H");
    if(sr+1<=er and sc+0<=ec)
        count+=mazePath_HVD(sr+1,sc,er,ec,ans+"V");
    if(sr+1<=er and sc+1<=ec)
        count+=mazePath_HVD(sr+1,sc+1,er,ec,ans+"D");
}

// maze path memoization 

int mazePath_HVD_memo(int sr,int sc,int er,int ec,vector<vector<int>>&dp,vector<vector<int>>&dir)
{
    //  vector<vector<int>> dp(er+1);
     if(sr==er and sc==ec)
     {
         return dp[sr][sc]=1;
     }
     if(dp[sr][sc]!=0)
        return dp[sr][sc];

    int count=0;
    for(auto d:dir)
    {
        int r=sr+d[0];
        int c=sc+d[1];

        if(r>=0 and c>=0 and r<=er and c<=ec)
            count+=mazePath_HVD_memo(r,c,er,ec,dp,dir)
    }
    return dp[sr][sc]=count;
}




int main()
{
    int er=3,ec=3;
    vector<vector<int>> dp(er+1);
    vector<vector<int>> dir{{0,1},{1,0},{1,1}};
    int ans =mazePath_HVD_memo(0,0,er,ec,dp,dir);
    cout<<ans;
}
