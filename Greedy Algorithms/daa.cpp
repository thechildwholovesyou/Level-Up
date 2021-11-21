// N meetings in a room

#include<bits/stdc++.h>
using namespace std;

struct meeting{
    int start;
    int end;
    int pos;
};

bool comparator(struct meeting a,struct meeting b)
{
    if(a.end<b.end) return true;
    else if(a.end>b.end) return false;
    else if(a.pos<b.pos) return true;
    return false;
}
int getAns(vector<int>&s, vector<int>&e, int n)
{
    struct meeting meet[n];
    for(int i=0;i<n;i++)
    {
        meet[i].start=s[i];
        meet[i].end=e[i];
        meet[i].pos=i+1;
    }

    sort(meet,meet+n,comparator);

    vector<int> res;
    int limit=meet[0].end;
    res.push_back(meet[0].pos);

    for(int i=1;i<n;i++)
    {
        if(meet[i].start>limit)
        {
            limit=meet[i].end;
            res.push_back(meet[i].pos);
        }
    }
    return res.size();
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;

        vector<int> start,end;
        for(int i=0;i<n;i++)
        {
            int data;
            cin>>data;
            start.push_back(data);
        }
         for(int i=0;i<n;i++)
        {
            int data;
            cin>>data;
            end.push_back(data);
        }

        int ans=getAns(start,end,n);
        cout<<ans<<endl;
    }
    return 0;
}