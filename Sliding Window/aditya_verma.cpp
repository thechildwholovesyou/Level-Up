// https://practice.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1#
// Max Sum Subarray of size K 
class Solution{   
public:
    int maximumSumSubarray(int k, vector<int> &arr , int N){
        // code here 
        int maxi=INT_MIN;
        int i=0;
        int j=0;
        int sum=0;
        
        while(j<N)
        {
            sum+=arr[j];
            if(j-i+1<k)
                j++;
            else if(j-i+1==k)
            {
                maxi=max(maxi, sum);
                sum-=arr[i];
                i++;
                j++;
            }
        }
        return maxi;
    }
};

// First negative integer in every window of size k 
// https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1
// Time limit exceeded

vector<long long> printFirstNegativeInteger(long long int A[],long long int N, long long int k) {
    
    long long int i=0;
    long long int j=0;
    
    vector<long long >v;
    while(j<N)
    {
        if(j-i+1<k)
        {
            j++;
        }
        else if(j-i+1==k)
        {
            for(int p=i;p<=j;p++)
            {
                if(A[p]<0)
                {
                    v.push_back(A[p]);
                    break;
                }
                if(p==j and A[p]>0)
                    v.push_back(0);
            }
            i++;
            j++;
        }
    }
    return v;
    
 }