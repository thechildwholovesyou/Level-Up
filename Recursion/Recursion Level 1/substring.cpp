#include<bits/stdc++.h>
using namespace std;

vector<string> subsequence(string s)
{
    if(s.size()==0){
        vector<string> v;
        v.push_back("");
        return v;
    }
    char ch=s[0];
    vector<string> ans=subsequence(s.substr(1));
    for(auto str: ans)
    {
        ans.push_back(str);
        ans.push_back(ch+str);
    }
    return ans;
}

int main()
{
    string s="abc";
    vector<string> ans=subsequence(s);
    for(auto ele : ans)
        cout<<ele<<" ";

    return 0;
    
}