// Boolean Parenthesization
// https://practice.geeksforgeeks.org/problems/boolean-parenthesization5610/1
// rec code 
class Solution{
public:

    int countWays_rec(string s,int i,int j,bool isTrue)
    {
        if(i>j) return 0;
        if(i==j)
        {
            if(isTrue)
                return s[i]=true;
            else
                return s[i]=false;
        }
        
        // K loop 
        int ans =0;
        for(int k=i+1;k<=j-1;k+=2)
        {
            int lt=countWays_rec(s,i,k-1,true);
            int lf=countWays_rec(s,i,k-1,false);
            int rt=countWays_rec(s,k+1,j,true);
            int rf=countWays_rec(s,k+1,j,false);
            
            if(s[k]=='&')
            {
                if(isTrue)
                    ans+=lt*rt;
                else
                    ans+=lf*rt+lt*rt+lt*rt;
            }
            else if(s[k]=='|')
            {
                if(isTrue)
                    ans+=lt*rf+lf*rt+lt*rt;
                else
                    ans+=lf*rf;
            }
            else if(s[k]=='^')
            {
                if(isTrue)
                    ans+=lf*rt+rt*lf;
                else
                    ans+=lt*rt+rt*lt;
            }
        }
        return ans;
    }
    int countWays(int N, string S){
        // code here
        return countWays_rec(S,0,N-1,true);
        
    }
};