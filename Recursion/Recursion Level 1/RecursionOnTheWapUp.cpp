#include<bits/stdc++.h>
using namespace std;


// get subsequence

int getSubsequence(string s, string ans)
{
    if(s.size()==0)
    {
        cout<<ans<<endl;
        return 1;
    }
    char ch=s[0];
    string ros=s.substr(1);

    int count=0;
    count+=getSubsequence(ros,ans);
    count+=getSubsequence(ros,ch+ans);

    return count;

}


// get subsequence using vector<string>
int getSubsequence(string s,string ans,vector<string> &res)
{
    if(s.size()==0)
    {
        res.push_back(ans);
        return 1;
    }
    char ch=s[0];
    string ros=s.substr(1);

    int count=0;
    count+=getSubsequence(ros,ans,res);
    count+=getSubsequence(ros,ch+ans,res);

    return count;
}


// nokia keypad problem --- using string 
string nokiaKeys[] = { ".;", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tu", "vwx", "yz" };

int getCombinations(string s,string ans)
{
    if(s.size()==0)
    {
        cout<<ans<<endl;
        return 1;
    }
    char ch=s[0];
    

    string code=nokiaKeys[ch-'0'];
    int count=0;
    for(int i=0;i<code.size();i++){
       
        count+=getCombinations(s.substr(1),code[i]+ans);
    }
    return count;
}

// nokia keypad problem --- using vector<string>

string nokiaKeys[] = { ".;", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tu", "vwx", "yz" };

int getCombinations(string s,string ans,vector<string>&res)
{
    if(s.size()==0){
        res.push_back(ans);
        return 1;
    }
    char ch=s[0];
    string code=nokiaKeys[ch-'0'];

    int count=0;
    for(int i=0;i<code.size();i++)
    {
        count+=getCombinations(s.substr(1),code[i]+ans,res);
    }
    return count;
}

// stairPath -- jump alllowed 1,2,3 -- using strings


int stairPath(int n,string ans)
{
    if(n==0)
    {
        cout<<ans<<endl;
        return 1;
    }
    
    int count=0;
    for(int i=1;i<=3 && n-i>=0 ;i++) // i=>jump
    {
        count+=stairPath(n-i,to_string(i)+ans);
    }
    return count;
}


// stairPath -- jumps allowed 1,2,3 --- using vector<string>

int stairPath(int n,string ans,vector<string> &res)
{
    if(n==0){
        res.push_back(ans);
        return 1;
    }
    int count=0;
    for(int i=1;i<=3 && n-i>=0;i++){
        count+=stairPath(n-i,to_string(i)+ans,res);
    }
    return count;
}

// boardPath -- 1 to 6 dice -- using strings

int boardPath(int n,string ans,vector<string> &res)
{
    if(n==0){
        res.push_back(ans);
        return 1;
    }
    int count=0;
    for(int dice=1;dice<=6 && n-dice>=0;dice++){
        count+=boardPath(n-dice,to_string(dice)+ans,res);
    }
    return count;
}

// boardPath -- 1to 6 dice -- using vector<string>

int boardPath(int n,string ans,vector<string>&res)
{
    if(n==0)
    {
        res.push_back(ans);
        return 1;
    }
    int count=0;
    for(int dice=1;dice<=6 && n-dice>=0;dice++)
    {
        count+=boardPath(n-dice,to_string(dice)+ans,res);
    }
    return count;
}


// mazePtah=> H V D moves allowed .. using strings


int mazePath_HVD(int sr,int sc,int er,int ec,string ans)
{
    if(sr==er && sc==ec)
    {
        cout<<ans<<endl;
        return 1;
    }
    int count=0;
    if(sc+1<=ec && sr+0<=er)
        count+=mazePath_HVD(sr,sc+1,er,ec,ans+"H");
    if(sr+1<=er && sc+0<=ec)
        count+=mazePath_HVD(sr+1,sc,er,ec,ans+"V");
    if(sr+1<=er && sc+1<=ec)
        count+=mazePath_HVD(sr+1,sc+1,er,ec,ans+"D");

    return count;
}

// mazePath => H V D moves allowed .. using vector<string>
int mazePath_HVD(int sr,int sc,int er,int ec, string ans,vector<string>&res)
{
    if(sr==er && sc==ec)
    {
        res.push_back(ans);
        return 1;
    }
    int count=0;
    if(sc+1<=ec && sr+0<=er)
        count+=mazePath_HVD(sr,sc+1,er,ec,ans+"H",res);
    if(sr+1<=er && sc+0<=sc)
        count+=mazePath_HVD(sr+1,sc,er,ec,ans+"V",res);
    if(sr+1<=er && sc+1<=ec)
        count+=mazePath_HVD(sr+1,sc+1,er,ec,ans+"D",res);
    
    return count;
}


// permuations of a string 

int permutation(string s,string ans,vector<string>&res)
{
    if(s.size()==0)
    {
        res.push_back(ans);
        return 1;
    }
    int count=0;
    for(int i=0;i<s.size();i++)
    {
        string ros=s.substr(0,i)+s.substr(i+1);
        count+=permutation(ros,ans+s[i],res);
    }
    return count;
}

// permutations without Duplicates 

int permutation(string s,string ans,vector<string>&res)
{
    if(s.size()==0)
    {
        res.push_back(ans);
        return 1;
    }
    int count=0;
    char prev='$';
    for(int i=0;i<s.size();i++)
    {
        if(s[i]!=prev)
        {
             string ros=s.substr(0,i)+s.substr(i+1);
            count+=permutation(ros,ans+s[i],res);
        }
        prev=s[i];
       
    }
    return count;
}



int main()
{
    string s;
    cin>>s;

    int ans=getSubsequence(s,"");
    cout<<"there are "<<ans<<" no of subsequences";
    return 0;
}