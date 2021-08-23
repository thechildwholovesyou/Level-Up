#include<bits/stdc++.h>
using namespace std;


// get subsequence 
vector<string> getSS(string s)
{
    if(s.size()==0)
    {
        vector<string> base;
        base.push_back("");
        return base;
    }
    char ch=s[0];
    vector<string> recAns=getSS(s.substr(1));
    vector<string> myAns;
    for(auto str: recAns)
    {
        myAns.push_back(str);
        myAns.push_back(ch+str);
    }
    return myAns;
}

// stair paths 
vector<string> getStairPaths(int n)
{
    if(n==0 || n==1){
        vector<string> base;
        base.push_back("");
        return base;
    }
    vector<string> myAns;

    for(int i=1;i<=3 && n-i>=0; i++)
    {
        vector<string> recAns=getStairPaths(n-i);
        for(auto str: recAns)
        {
            myAns.push_back(to_string(i)+str);
        }

    }
    return  myAns;

}

// board paths

vector<string> getBaordPaths(int n)
{
    if(n==0 || n==1){
        vector<string> base;
        base.push_back("");
        return base;
    }
    vector<string> myAns;

    for(int dice=1;dice<=6 && n-dice>=0; dice++)
    {
        vector<string> recAns=getBaordPaths(n-dice);
        for(auto str: recAns)
        {
            myAns.push_back(to_string(dice)+str);
        }

    }
    return  myAns;

}

// maze paths : Horizontal Vertical And Diagonal moves are allowed

vector<string> getMazePaths(int sr,int sc,int er,int ec)
{
    if(sr==er and sc==ec)
    {
        vector<string> base;
        base.push_back("");
        return base;
    }
    vector<string> myAns;
    if(sc+1<=ec){
        vector<string> horizontal=getMazePaths(sr,sc+1,er,ec);
        for( auto str: horizontal){
            myAns.push_back("H"+str);
        }
    }
    if(sr+1<=er and sc+1<=ec)
    {
        vector<string> diagonal=getMazePaths(sr+1,sc+1,er,ec);
        for(auto str: diagonal){
            myAns.push_back("D"+str);
        }
    }
    if(sr+1<=er)
    {
        vector<string> vertical=getMazePaths(sr+1,sc,er,ec);
        for( auto str: vertical){
            myAns.push_back("V"+str);
        }
    }
    return myAns;
}

// NOKIA KEYPAD PROBLEM : GET COMBINATION 

string nokiaKeys[] = { ".;", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tu", "vwx", "yz" };

vector<string> getCombinations(string s)
{
    if(s.size()==0)
    {
        vector<string> base;
        base.push_back("");
        return base;
    }
    char ch=s[0];
    string code=nokiaKeys[ch-'0'];
    
    vector<string> recAns=getCombinations(s.substr(1));
    vector<string> myAns;

    for(int i=0;i<code.size();i++)
    {
        for(auto str: recAns)
        {
            myAns.push_back(code[i]+str);
        }
    }
    return myAns;
}


int main()
{
    string s;
    cin>>s;

    vector<string> ans=getSS(s);
    for(auto ele: ans)
        cout<<ele<<" ";

    return 0;
}