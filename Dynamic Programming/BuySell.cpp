// 121. Best Time to Buy and Sell Stock
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0 or prices.size()==1) return 0;
        int currMin=prices[0];
        int ans =0;
        for(int i=1;i<prices.size();i++)
        {
            if(prices[i]<currMin)
                currMin=prices[i];
            ans=max(ans, prices[i]-currMin);
        }
        return ans;
    }
};