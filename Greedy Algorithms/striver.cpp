// N meetings in one room
// https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1

class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    struct meeting{
        int start;
        int end;
        int pos;
    };
    static bool comparator(struct meeting m1, struct meeting m2)
    {
        if(m1.end < m2.end) return true;
        else if(m1.end>m2.end) return false;
        else if(m1.pos<m2.pos) return true;
        return false;
    }
    int maxMeetings(int s[], int e[], int n)
    {
        // Your code here
        struct meeting meet[n];
        for(int i=0;i<n;i++)
        {
            meet[i].start=s[i];
            meet[i].end=e[i];
            meet[i].pos=i+1;
        }
        
        sort(meet,meet+n,comparator);
        vector<int>res;
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
};

// Minimum Platforms
// https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1

class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	sort(arr,arr+n);
    	sort(dep,dep+n);
    	int i=1,j=0;
    	
    	int platform=1,res=1;
    	
    	while(i<n and j<n)
    	{
    	    if(arr[i]<=dep[j])
    	    {
    	        platform++;
    	        i++;
    	    }
    	    else if(arr[i]>dep[j])
    	    {
    	        platform--;
    	        j++;
    	    }
    	    res=max(res,platform);
    	}
    	return res;
    }
};

// Job Sequencing Problem
// https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1#

// struct Job 
// { 
//     int id;	 // Job Id 
//     int dead; // Deadline of job 
//     int profit; // Profit if job is over before or on deadline 
// };

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    static bool comparator(Job a,Job b)
    {
        return(a.profit > b.profit);
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
       
         vector<int> res;
        sort(arr,arr+n,comparator);
        
        // find out the max deadline
        int maxi=arr[0].dead;
        for(int i=1;i<n;i++){
            maxi=max(maxi,arr[i].dead);
        }
        // create an array to store the ordering of jobs
        vector<int> slot(maxi+1,-1);
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
        res.push_back(cnt);
        res.push_back(total_profit);
        return res;
    } 
};

// Greedy Algorithm to find Minimum number of Coins
// https://www.geeksforgeeks.org/greedy-algorithm-to-find-minimum-number-of-coins/

#include <bits/stdc++.h>
using namespace std;

// All denominations of Indian Currency
int deno[] = { 1, 2, 5, 10, 20,
			50, 100, 500, 1000 };
int n = sizeof(deno) / sizeof(deno[0]);

void findMin(int V)
{
	sort(deno, deno + n);

	// Initialize result
	vector<int> ans;

	// Traverse through all denomination
	for (int i = n - 1; i >= 0; i--) {

		// Find denominations
		while (V >= deno[i]) {
			V -= deno[i];
			ans.push_back(deno[i]);
		}
	}

	// Print result
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";
}

// Driver program
int main()
{
	int n = 93;
	cout << "Following is minimal"
		<< " number of change for " << n
		<< ": ";
	findMin(n);
	return 0;
}
