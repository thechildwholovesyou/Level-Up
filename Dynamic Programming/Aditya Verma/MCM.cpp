// Matrix Chain Multiplication 
// https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1
// rec code

class Solution{
public:

    int solve_rec(int arr[],int i,int j)
    {
        // base condition 
        if(i>=j) return 0;
        
        int mini = INT_MAX;
        
        for(int k=i;k<=j-1;k++)
        {
            int tempAns = solve_rec(arr,i,k)+solve_rec(arr,k+1,j) + (arr[i-1]*arr[k]*arr[j]);
            
            mini=min(tempAns, mini);
        }
        return mini;
        
    }
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        
        return solve_rec(arr,1,N-1);
        
    }
};
