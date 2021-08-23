#include<bits/stdc++.h>
using namespace std;

int queenCombination1D_sub(int tnb,int bno,int tnq,int qpsf,string ans)
{
	if(qpsf>tnq || bno>tnb){
		if(qpsf>tnq){
			cout<<ans<<endl;
			return 1;
		}
		return 0;
	}
	int count=0;
	count+=queenCombination1D_sub(tnb,bno+1,tnq,qpsf+1,ans+"b"+to_string(bno)+"q"+to_string(qpsf));
	count+=queenCombination1D_sub(tnb,bno+1,tnq,qpsf,ans);

	return count;
}

int queenPermutation1D_sub(int tnb,int tnq,int bno,int qpsf,vector<bool>&vis,string ans)
{
    if(qpsf> tnq || bno>tnb)
    {
        if(qpsf>tnq){
            cout<<ans<<endl;
            return 1;
        }
        return 0;
    }

    int count=0;
    if(!vis[bno])
    {
        vis[bno]=true;
        count+=queenPermutation1D_sub(tnb,tnq,1,qpsf+1,vis,ans+"b"+to_string(bno)+"q"+to_string(qpsf));
        vis[bno]=false;
    }
    count+=queenPermutation1D_sub(tnb,tnq,bno+1,qpsf,vis,ans);

    return count;
}


int queenCombination2D(vector<vector<bool>> box,int bno,int tnq,string ans)
{
    if(tnq==0){
        cout<<ans<<endl;
        return 1;
    }
    int count=0;
    int n=box.size();
    int m=box[0].size();

    for(int i=bno;i<n*m;i++)
    {
        int r=i/m;
        int c=i%m;

        count+=queenCombination2D(box,i+1,tnq-1,ans+"r"+to_string(r)+"c"+to_string(c));
    }
    return count;
}

int queenPermutation2D_sub(vector<vector<bool>>&box,int bno,int tnq,string ans)
{
    int n=box.size();
    int m=box[0].size();

    int tnb=n*m-1;
    if(tnq==0 || bno> tnb)
    {
        if(tnq==0){
            cout<<ans<<endl;
            return 1;
        }
        return 0;
    }
    int count=0;
    int r=bno/n;
    int c=bno%m;
    if(!box[r][c])
    {
        box[r][c]=true;
        count+=queenPermutation2D_sub(box,1,tnq-1,ans+"r"+to_string(r)+"c"+to_string(c));
        box[r][c]=false;
    }
    count+=queenPermutation2D_sub(box,bno+1,tnq,ans);

    return count;
}

// int queenPermutation2D_sub(int tnb,int tnq,int bno,int qpsf,vector<vector<bool>>&vis,string ans)
// {
//     if(qpsf> tnq || bno>tnb)
//     {
//         if(qpsf>tnq){
//             cout<<ans<<endl;
//             return 1;
//         }
//         return 0;
//     }

//     int count=0;
//     if(!vis[bno])
//     {
//         vis[bno]=true;
//         count+=queenPermutation1D_sub(tnb,tnq,1,qpsf+1,vis,ans+"b"+to_string(bno)+"q"+to_string(qpsf));
//         vis[bno]=false;
//     }
//     count+=queenPermutation1D_sub(tnb,tnq,bno+1,qpsf,vis,ans);

//     return count;
// }

int main()
{
	int q=4;
	int boxes=7;

    // vector<bool>vis(boxes+1);
	// int count=queenCombination1D_sub(boxes,1,q,1,"");
    // int count2=queenPermutation1D_sub(boxes,q,1,1,vis,"");
    vector<vector<bool>> box2d(4,vector<bool> (4, false)) ; 
    //int count3=queenCombination2D(box2d,1,q,"");
    int count4=queenPermutation2D_sub(box2d,1,q,"");
    cout<<count4<<endl;
	cout<<endl;
	// cout<<count;
    // cout<<endl;
    // cout<<count2<<endl;
    //cout<<count3<<endl;
	return 0;

}