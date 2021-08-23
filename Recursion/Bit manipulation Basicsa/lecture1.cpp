#include<bits/stdc++.h>
using namespace std;

int onToOff(int n,int k)
{
	return n=n&~(1<<k);
}
int offToOn(int n,int k)
{
    return ((1<<k)|n);
}

int countSetBits(int n)
{
    int count=0; 
    while(n)
    {
        count+=n&1;
        n=n>>1;
    }
    return count;
}

int main()
{
	int n=5;
	int k=3;

	int ans1=onToOff(n,k);
    int ans2=offToOn(n,k);
    int ans3=countSetBits(n);
	cout<<ans1<<endl;
    cout<<ans2<<endl;
    cout<<ans3<<endl;


}