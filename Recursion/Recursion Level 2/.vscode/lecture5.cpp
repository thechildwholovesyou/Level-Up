// word break 
#include<bits/stdc++.h>
using namespace std;

int wordBreak(string s,string ans, unordered_set<string> dict)
{
    if(s.size()==0)
    {
        cout<<ans<<endl;
        return 1;
    }
    int count=0;
    for(int i=0;i<s.size();i++)
    {
        string pword=s.substr(0,i);
        if(dict.find(pword)!=dict.end())
        {
            count+=wordBreak(s.substr(i+1),ans+pword+" ",dict);
        }
    }
    return count;
}

int main()
{
     unordered_set <string> dict;
     int n;
     cin>>n;
     while(n--)
     {
         string str;
         cin>>str;
         dict.insert(str);
     }
     string s;
     cin>>s;

     int count=wordBreak(s,"",dict);

     cout<<count;
     return 0;

}

// 
#include<bits/stdc++.h>
using namespace std;

 string maxx="";

void helper(string s,int k, int ii)
{
	if(k==0) return;
	for(int i=ii;i<s.size();i++)
	{
		int idx=-1; 
		char maxCh='0';
		for(int j=i+1;j<s.size();j++)
		{
			if(s[i]<s[j] && maxCh<s[j])
			{
				idx=j;
				maxCh=s[j];
			}
		}
		if(idx!=-1)
		{
			for(int j=idx;j<s.size();j++)
			{
				if(s[j]==maxCh)
				{
					swap(s[i],s[j]);
                    string temp=s;
					if(temp>maxx)
						maxx=temp;
					helper(temp,k-1,i+1);
				}
			}
		}
	}
	
}

int main()
{
	string str;
	cin>>str;

	int k;
	cin>>k;

	helper(str,k,0);
    cout<<maxx<<endl;

	return 0;
}