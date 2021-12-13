// N meetings in a room 
#include<bits/stdc++.h>
using namespace std;

struct meeting{
    int pos;
    int start;
    int end;
};
bool cmp(struct meeting a,struct meeting b)
{
    if(a.end<b.end) return true;
    if(a.end>b.end) return false;
    if(a.pos<b.pos) return true;
    return false;
}
int main()
{
    int n;
    cin>>n;
    vector<int> s;
    for(int i=0;i<n;i++)
    {
        int data;
        cin>>data;
        s.push_back(data);
    }
    vector<int> e;
    for(int i=0;i<n;i++)
    {
        int data;
        cin>>data;
        e.push_back(data);
    }
    struct meeting  meet[n];
    for(int i=0;i<n;i++)
    {
        meet[i].pos=i+1;
        meet[i].start=s[i];
        meet[i].end=e[i];
    }
    sort(meet,meet+n,cmp);

    vector<int> res;
    int limit=meet[0].end;
    res.push_back(meet[0].pos);
    for(int i=1;i<n;i++)
    {
        if(meet[i].start>limit)
        {
            limit=meet[i].start;
            res.push_back(meet[i].pos);
        }
    }
    cout<<res.size();
    return 0;
}

// minimum no of platforms

#include<bits/stdc++.h>
using namespace std;

int get_ans(vector<int>&s, vector<int> &e)
{
    int n=s.size();
    sort(s.begin(),s.end());
    sort(e.begin(),e.end());

    int i=1;
    int j=0;
    int p=1;
    int maxi=1;
    while(i<n and j<n)
    {
        if(s[i]<=e[j])
        {
            p++;
            i++;
        }
        else if(s[i]>e[j])
        {
            p--;
            j++;
        }
        maxi=max(p,maxi);
    }
    return maxi;
}

int main()
{
    int n;
    cin>>n;
    vector<int> start;
    for(int i=0;i<n;i++)
    {
        int data;
        cin>>data;
        start.push_back(data);
    }
    vector<int> end;
    for(int i=0;i<n;i++)
    {
        int data;
        cin>>data;
        end.push_back(data);
    }

    int ans=get_ans(start,end);
    cout<<ans<<endl;
}

// Fractional Knapsack 

#include<bits/stdc++.h>
using namespace std;

struct Item{
    int v;
    int wt;
};
bool cmp(struct Item a,struct Item b)
{
    double r1=(double)a.v/ (double)a.wt;
    double r2=(double)b.v/(double)b.wt;
    return r1>r2;
}
int get_ans(vector<int>&values, vector<int>&weights,int W)
{
    int n=values.size();
    struct Item arr[n];
    for(int i=0;i<n;i++)
    {
        arr[i].v=values[i];
        arr[i].wt=weights[i];
    }
    sort(arr,arr+n,cmp);

    int currWeight=0;
    double finalValue =0.0;
    for(int i=0;i<n;i++)
    {
        if(currWeight+arr[i].wt<=W)
        {
            currWeight+=arr[i].wt;
            finalValue+=arr[i].v;
        }
        else
        {
            int remain=W-currWeight;
            finalValue+=(arr[i].v/(double)arr[i].wt)*(double)remain;
        }
    }
    return finalValue;

}

int main()
{
    int n;
    cin>>n;
    vector<int> values;
    for(int i=0;i<n;i++)
    {
        int data;
        cin>>data;
        values.push_back(data);
    }
    vector<int> weights;
    for(int i=0;i<n;i++)
    {
        int data;
        cin>>data;
        weights.push_back(data);
    }
    int W;
    cin>>W;
    int ans=get_ans(values,weights,W);
    cout<<ans<<endl;
}

// Job sequencing 
#include<bits/stdc++.h>
using namespace std;

struct Job{
    int id;
    int d;
    int p;
};
bool cmp(struct Job a,struct Job b)
{
    return a.p > b.p;
}

void get_ans(vector<int>&deadline, vector<int>&profit)
{
    int n=deadline.size();
    struct Job arr[n];
    for(int i=0;i<n;i++)
    {
        arr[i].id=i;
        arr[i].p=profit[i];
        arr[i].d=deadline[i];
    }
    sort(arr,arr+n,cmp); 
    int maxi=arr[0].d;
    for(int i=1;i<n;i++)
    {
        maxi=max(maxi,arr[i].d);
    }
    int currJobs=0, jobProfit=0;
    
    vector<int> slot(maxi+1,-1);
    for(int i=0;i<n;i++)
    {
        for(int j=arr[i].d;j>0;j--)
        {
            if(slot[j]==-1)
            {
                slot[j]=i;
                currJobs++;
                jobProfit+=arr[i].p;
                break;
            }
        }
    }
    cout<<jobProfit<<endl;
    cout<<currJobs<<endl;
}

int main()
{
    int n;
    cin>>n;
    vector<int> deadline;
    for(int i=0;i<n;i++)
    {
        int data;
        cin>>data;
        deadline.push_back(data);
    }
    vector<int> profit;
    for(int i=0;i<n;i++)
    {
        int data;
        cin>>data;
        profit.push_back(data);
    }
    
    get_ans(deadline,profit);
    return 0;
}

// subset sum
#include<bits/stdc++.h>
using namespace std;
bool helper(vector<int>&nums, int n,int target)
{
    if(n==0) return false;
    if(target==0) return true;
    if(nums[n-1]<=target)
    {
        bool a1=helper(nums,n-1,target-nums[n-1]);
        bool a2=helper(nums,n-1,target);
        return a1 || a2;
    }
    else
        return helper(nums,n-1,target);
}
int main()
{
    int n;
    cin>>n;
    vector<int> nums;
    for(int i=0;i<n;i++)
    {
        int data;
        cin>>data;
        nums.push_back(data);
    }
    int target;
    cin>>target;

    bool ans =helper(nums,nums.size(),target);
    cout<<ans;
}

// container with most water
class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0;
        int j=height.size()-1;
        int maxi=INT_MIN;
        while(i<=j)
        {
            int tempwater= min(height[i],height[j])*(j-i);
            maxi=max(tempwater,maxi);
            if(height[i]<height[j])
                i++;
            else
                j--;
        }
        return maxi;
    }
};

// topo sort 

class Solution
{
	public:
	//Function to return list containing vertices in Topological order.
	void topo_helper(int n,vector<int>graph[], vector<int>&vis, stack<int>&s, int src)
	{
	    vis[src]=1;
	    for(auto ele:graph[src])
	    {
	        if(!vis[ele])
	        {
	            topo_helper(n,graph,vis,s,ele);
	        }
	    }
	    s.push(src);
	}
	vector<int> topoSort(int V, vector<int> graph[]) 
	{
	    // code here
	    vector<int> vis(V+1,0);
	    stack<int> s;
	    vector<int> res;
	    for(int i=0;i<V;i++)
	    {
	        if(!vis[i])
	            topo_helper(V,graph,vis,s,i);
	    }
	    while(!s.empty())
	    {
	        int x=s.top();
	        s.pop();
	        res.push_back(x);
	    }
	    return res;
	}
};

