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

 // optimised

 vector<long long> printFirstNegativeInteger(long long int arr[],
                                            long long int N, long long int k) {

    list<int>l;
   vector<long long>v;
   int i=0,j=0;
   while(j<N)
   {    
       if(arr[j]<0)
       l.push_back(arr[j]);
       if(j-i+1<k)
       j++;
       else if(j-i+1==k)
       {
          
          
          if(l.size()!=0)
          v.push_back(l.front());
          else
          v.push_back(0);
          if(l.front()==arr[i] && l.size()>0)
          l.pop_front();
         i++;j++;
           
       }
   }
       return v;
       
   }


// Count Occurences of Anagrams 
// https://practice.geeksforgeeks.org/problems/count-occurences-of-anagrams5839/1
// brute 

class Solution{
public:
    
    bool helper(unordered_map<char, int >m1, unordered_map<char, int >m2)
    {
        for(int i=0;i<m1.size();i++)
        {
            if(m1[i]!=m2[i]) return false;
        }
        return true;
    }

	int search(string pat, string txt) {
	    // code here
	    int k=pat.size();
	    sort(pat.begin(),pat.end());
	    unordered_map<char,int> m;
	    for(auto ele:pat)
	        m[ele]++;
	       
	   int i=0;
	   int j=0;
	   int cnt=0;
	   while(j<txt.size())
	   {
	       if(j-i+1<k)
	        {
	            j++;
	        }
	       else if(j-i+1==k)
	       {
	           string temp="";
	           for(int p=i;p<=j;p++)
	                temp+=txt[p];
	               
	           sort(temp.begin(),temp.end());
	           unordered_map<char,int> t;
	           for(auto ele:temp)
	           {
	               t[ele]++;
	           }
	           
	           if(helper(m,t)) cnt++;
	           i++;
	           j++;
	       }
	   }
	   return cnt;
	}

};