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
