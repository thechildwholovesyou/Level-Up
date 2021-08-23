

// All Palindromic Permutations ... Portal

#include<bits/stdc++.h>
using namespace std;

int getPermutations(string s,string ans,vector<string>&res)
{
	if(s.size()==0)
	{
		res.push_back(ans);
		return 1;
	}
	int count=0;

	for(int i=0;i<s.size();i++)
	{
		string ros=s.substr(0,1)+s.substr(i+1);
		count+=getPermutations(ros,ans+s[i],res);
	}
	return count;
}

bool checkPalindrome(string s)
{
	int i=0;
	int j=s.size()-1;

	while(i<j)
	{
		if(s[i++]!=s[j--]) return false;
	}
	return true;
}

int main()
{
	string s;
	cin>>s;

	vector<string> res;
	int ans=getPermutations(s,"",res);
	
	vector<string> fAns;
	for(auto ele:res)
	{
		if(checkPalindrome(ele))
			fAns.push_back(ele);
	}

	for(auto ele: fAns)
		cout<<ele<<endl;

	return 0;
}

// All Palindromic Partitions ... PORTAL 


#include<bits/stdc++.h>
using namespace std;



bool isPalindrome(string s)
{
	int i=0;
	int j=s.size()-1;

	while(i<j)
	{
		if(s[i++]!=s[j--]) return false;
	}
	return true;
}

int helper(string s,string ans,vector<string>&res)
{
	if(s.size()==0)
	{
		res.push_back(ans);
		return 1;
	}
    int count=0;
	for(int i=0;i<s.size();i++)
	{
		string prefix=s.substr(0,i+1);
		string ros=s.substr(i+1);

		if(isPalindrome(prefix))
		{
			ans+=prefix;
            string temp+="("+prefix+")";
			count+=helper(ros,temp,res);
			ans="";
		}
	}
	return count;
}
int main()
{
	string s;
	cin>>s;

	vector<string> ans;

	int res=helper(s,"",ans);

	for(auto ele: ans)
		cout<<ele<<endl;

	return 0;
}