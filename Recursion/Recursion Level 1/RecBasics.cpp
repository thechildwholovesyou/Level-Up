#include<bits/stdc++.h>
using namespace std;

// void powerBtr(int a,int b)
// {

// }
void printArrayHelper(int arr[],int size,int i)
{
    if(i==size)
        return;
    cout<<arr[i]<<" ";
    printArrayHelper(arr,size,i+1);
}
void printArray(int* arr)
{
    int n=sizeof(arr)/sizeof(arr[0]);
    printArrayHelper(arr,n,0);
}
void printArrayRev(int arr[],int n)
{
    if(n==0) return;
    cout<<arr[n-1]<<" ";
    printArrayRev(arr,n-1);
}

int factorialHelper(int n)
{
    if(n==1 || n==0) return 1;

    return n*factorialHelper(n-1);
}
void factorial(int n)
{
    int ans=factorialHelper(n);
    cout<<ans;
}
int powerHelper(int a,int b)
{
   if(b==0) return 1;
   return (a* powerHelper(a,b-1));
}
void power(int a,int b)
{
    int ans=powerHelper( a, b);
    cout<<ans;
}
int maximum(int arr[],int n)
{
    if(n==1) return arr[n];
    return max(arr[n-1],maximum(arr,n-1));
}
int minimum(int arr[],int n)
{
    if(n==1) return arr[n];
    return min(arr[n-1],minimum(arr,n-1));
}
int findFirstIndexHelper(int arr[],int data,int low,int high)
{
    if(low==high) return 0;
    if(arr[low]==data) return low;

    findFirstIndexHelper(arr,data,low+1,high);

}
int findFirstIndex(int arr[],int data)
{
    int size=sizeof(arr)/sizeof(arr[0]);
    return findFirstIndexHelper(arr,data,0,size-1);
}

int findLastIndexHelper(int arr[],int data,int low,int high)
{
    if(low==high) return 0;
    if(arr[high]==data) return high;

    findLastIndexHelper(arr,data,low,high-1);

}
int findLastIndex(int arr[],int data)
{
    int size=sizeof(arr)/sizeof(arr[0]);
    return findLastIndexHelper(arr,data,0,size-1);
}
void printIncreasing(int a,int b)
{
    if(a==b) return;
    cout<<a<<" ";
    printIncreasing(a+1,b);
}
void printDecreasing(int a,int b)
{
    if(a==b) return;
    printIncreasing(a+1,b);
    cout<<a<<" ";
}
void printIncDec(int a,int b)
{
    if(a==b) return;
    cout<<a<<" ";
    printIncDec(a+1,b);
    cout<<a<<endl;
}

int main()
{

}