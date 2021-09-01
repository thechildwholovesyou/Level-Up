// rec code 

class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       // base cond
       if(W==0 or n==0) return 0;
       
       int maxx=INT_MIN;
       
       if(wt[n-1]<=W)
       {
           maxx=max(val[n-1]+knapSack(W-wt[n-1],wt,val,n-1),knapSack(W,wt,val,n-1));
           return maxx;
       }
       else if(wt[n-1]>W)
        return knapSack(W,wt,val,n-1);
    }
};

// mem code

class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       // base cond
       if(W==0 or n==0) return 0;
       
       int maxx=INT_MIN;
       
       if(wt[n-1]<=W)
       {
           maxx=max(val[n-1]+knapSack(W-wt[n-1],wt,val,n-1),knapSack(W,wt,val,n-1));
           return maxx;
       }
       else if(wt[n-1]>W)
        return knapSack(W,wt,val,n-1);
    }
};

