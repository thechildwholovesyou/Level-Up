// friends pairing 

// rec 
public:

    int countFriendsPairings_rec(int n)
    {
        if(n<=2) return n;
        
        int ans =countFriendsPairings_rec(n-1)+(n-1)*countFriendsPairings_rec(n-2);
        return ans;
    }
    int countFriendsPairings(int n) 
    { 
        // code here
        return countFriendsPairings_rec(n);
    }
};  

// memo 

public:

    int countFriendsPairings_rec(int n)
    {
        if(n<=2) return n;
        
        int ans =countFriendsPairings_rec(n-1)+(n-1)*countFriendsPairings_rec(n-2);
        return ans;
    }
    int countFriendsPairings(int n) 
    { 
        // code here
        return countFriendsPairings_rec(n);
    }
};  

