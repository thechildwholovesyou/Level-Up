#include<bits/stdc++.h>
using namespace std;

int mazePath(int sr,int sc,int er,int ec, string ans,vector<vector<int>> dir, vector<string> dirS)
{
    if(sr==er && sc==ec)
    {
        cout<<ans<<" ";
        return 1;
    }
    int count=0;
    for(int d=0;d<dir.size();d++)
    {
        int r=sr+dir[d][0];
        int c=sc+dir[d][1];

        if(r>=0 && c>=0 && r<=er && c<=ec)
        {
            count+=mazePath(r,c,er,ec,ans+dirS[d],dir,dirS);
        }
    }
    return count;
}

int main()
{
    vector<vector<int>> dir={{-1,0},{0,1},{1,0},{0,-1}};
    vector<string> dirS={"t","r","d","l"};
    int paths=mazePath(0,0,4,4,"",dir,dirS);
    cout<<paths;
}



// flood fill

#include<bits/stdc++.h>

using namespace std;

void floodfill(vector<vector<int>> &maze,int sr ,int sc ,  string ans, vector<vector<int>> &dir , vector<string> dirs ) {
    int n = maze.size() ;
    int m = maze[0].size() ;
    if(sr==n-1 && sc==m-1)
    { 
        cout << ans << endl ; 
        return ; 
    }
  maze[sr][sc] = 1 ; 
   for (int d = 0; d < dir.size(); d++)
   {
            int r = sr +  dir[d][0];
            int c = sc +  dir[d][1];

            if (r >= 0 && c >= 0 && r < maze.size() && c < maze[0].size()) {
                if (maze[r][c] == 0)
                    floodfill(maze,r,c,ans + dirs[d] , dir,dirs);
            }
        }

        maze[sr][sc] = 0;
  
}

int main() {
    int n, m;
    cin >> n >> m;
    vector < vector < int >> arr(n, vector < int > (m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];
            
     vector<vector<int>> dir  {{ -1, 0 }, { 0, -1 }, { 1, 0 }, { 0, 1 } }; 
      vector<string> dirs { "t", "l", "d", "r"};
      floodfill(arr,0,0,"",dir, dirs);
}