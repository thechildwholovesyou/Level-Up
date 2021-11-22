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

// job sequencing 
#include<bits/stdc++.h>
using namespace std;
struct Job{
    char id;
    int dead;
    int profit;
};
bool comparator(struct Job a, struct Job b){
    return (a.profit>b.profit);
}
int getAns(struct Job arr[],int n)
{
    sort(arr,arr+n,comparator);
    // find out the max deadline
    int maxi=arr[0].dead;
    for(int i=1;i<n;i++)
    {
        maxi=max(maxi,arr[i].dead);
    }
    // create an array to store the ordering of jobs
    vector<int>slot(maxi+1,-1);
    int cnt=0;
    int total_profit=0;
    for(int i=0;i<n;i++)
    {
        for(int j=arr[i].dead;j>0;j--)
        {
            if(slot[j]==-1)
            {
                slot[j]=i;
                cnt++;
                total_profit+=arr[i].profit;
                break;
            }
        }
    }
    return total_profit;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        struct Job arr[n];
        for(int i=0;i<n;i++)
        {
            char c;
            int d,p;
            cin>>c>>d>>p;
            arr[i].id=c;
            arr[i].dead=d;
            arr[i].profit=p;
        }
        int x=getAns(arr,n);
        cout<<x<<endl;
    }
    return 0;
}