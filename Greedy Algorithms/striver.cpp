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