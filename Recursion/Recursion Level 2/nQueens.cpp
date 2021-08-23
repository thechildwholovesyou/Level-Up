#include<bits/stdc++.h>
using namespace std;

bool isSafeToPlace(vector<vector<bool>>& box,int sr,int sc)
{
	vector<vector<int>> dir={{0,-1},{-1,-1},{-1,0},{-1,1}};

	int n=box.size();
	int m=box[0].size();

	for(int d=0;d<dir.size();d++){
		for(int rad=1;rad<=n;rad++){
			int r=sr+rad*dir[d][0];
			int c=sc+rad*dir[d][1];

			if(r>=0 && c>=0 && r<n && c<m){
				if(box[r][c])
					return false;
				else
					break;
			}
		}
	}
    return true;
}

int ng=4;
int mg=4;

vector<bool> row(ng,false);
vector<bool> col(mg,false);
vector<bool> diag(ng+mg-1,false);
vector<bool> adiag(ng+mg-1,false);

// combination 

int nQueen_03_comb(vector<vector<bool>>&box, int bno, int tnq,string asf)
{
	if(tnq==0)
	{
		cout<<asf<<endl;
		return 1;
	}

	int count=0;

	int n=box.size();
	int m=box[0].size();
	for(int i=bno;i<n*m;i++)
	{
		int r=i/m;
		int c=i%m;
		
			if(!row[r] && !col[c] && !diag[r+c] && !adiag[r-c+m-1])
			{
                row[r]=col[c]=diag[r+c]=adiag[r-c+m-1]=true;
				count+=nQueen_03_comb(box,i+1,tnq-1,asf+"r"+to_string(r)+"c"+to_string(c));
                row[r]=col[c]=diag[r+c]=adiag[r-c+m-1]=false;
			}
		
	}
	return count;

}

// permutaion 

int nQueen_03_perm(vector<vector<bool>>&box, int tnq,string asf)
{
	if(tnq==0)
	{
		cout<<asf<<endl;
		return 1;
	}

	int count=0;

	int n=box.size();
	int m=box[0].size();
	for(int i=0;i<n*m;i++)
	{
		int r=i/m;
		int c=i%m;
		
			if(!row[r] && !col[c] && !diag[r+c] && !adiag[r-c+m-1])
			{
                row[r]=col[c]=diag[r+c]=adiag[r-c+m-1]=true;
				count+=nQueen_03_perm(box,tnq-1,asf+"r"+to_string(r)+"c"+to_string(c));
                row[r]=col[c]=diag[r+c]=adiag[r-c+m-1]=false;
			}
		
	}
	return count;

}

int main()
{
	
	int tnq=4;

	 vector<vector<bool>> box(4, vector<bool> (4, false)) ; 
	 int count=nQueen_03_comb(box,1,tnq,"");

	 cout<<endl<<count;

	

}