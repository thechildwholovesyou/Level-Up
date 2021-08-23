#include<bits/stdc++.h>
using namespace std;

   int queenCombination1D(int tnb, int bno, int tnq, int qpsf, string asf) {
        if (qpsf > tnq) {
            cout << asf << " " << endl ; 
            return 1;
        }

        int count = 0;
        for (int b = bno; b <= tnb; b++) {
            count += queenCombination1D(tnb, b + 1, tnq, qpsf + 1, asf + "b" + to_string(b) + "q" + to_string(qpsf)+ " ");
        }
        return count;
    }


int queenPermutation1D(int tnb, int tnq, int qpsf, vector<bool> &vis, string asf) {
        if (qpsf > tnq) {
             cout << asf << " " << endl ; 
            return 1;
        }

        int count = 0;
        for (int b = 1; b <= tnb; b++) {
            if (!vis[b]) {
                vis[b] = true;
                count += queenPermutation1D(tnb, tnq, qpsf + 1, vis, asf + "b" + to_string(b) + "q" + to_string(qpsf) + " ");
                vis[b] = false;
            }
        }
        return count;
    }
 int queenCombination2D(vector<vector<bool>> &box2d , int bno, int tnq, string asf) {
        if (tnq == 0) {
           cout << asf << " " << endl ; 
            return 1;
        }

        int count = 0;
        int n = box2d.size(), m = box2d[0].size();
        for (int b = bno; b < n * m; b++) {
            int r = b / m;
            int c = b % m;
            count += queenCombination2D(box2d, b + 1, tnq - 1, asf + "(" + to_string(r) + "," + to_string(c) + ") ");
        }
        return count;
    }

int queenPermutation2D(vector<vector<bool>> &box2d , int tnq, string asf) {
        if (tnq == 0) {
            cout << asf << " " << endl ; 
            return 1;
        }

        int count = 0;
        int n = box2d.size(), m = box2d[0].size();
        for (int b = 0; b < n * m; b++) {
            int r = b / m;
            int c = b % m;
            if (!box2d[r][c]) {
                box2d[r][c] = true;
                count += queenPermutation2D(box2d, tnq - 1, asf + "(" + to_string(r) + "," + to_string(c) + ") ");
                box2d[r][c] = false;
            }
        }
        return count;
    }
int main()
{
    int q=2;
    int boxes=7;
     vector<bool> vis(boxes+1,false) ; 
   // int count=queenCombination1D(q,boxes,1,1,"");
   //int count1 =  queenPermutation1D(boxes, q, 1,vis,"") ; 
   int n = 2 ; int m = 2 ;  // n == row m==column 
   vector<vector<bool>> box2d(n, vector<bool> (m, false)) ; 
//    int count2 =  queenCombination2D(box2d,1,q,"") ; 
int count3 = queenPermutation2D(box2d,q,"") ;

    cout<<endl;
    cout<<count3;
}