#include<bits/stdc++.h>
using namespace std;
struct MaxHeap{
private:
	vector<int> arr;
	int parent(int i){
		return (i-1)/2;
	}
	int left_child(int i){
		return (2*i+1);
	}
	int right_child(int i)
	{
		return (2*i+2);
	}
     bool compareTo(int x,int y){
        return arr[x] > arr[y];
    }
    // log n 
	void downHeapify(int i){
		int left=left_child(i);
		int right=right_child(i);

		int largest=i;
		if(left <arr.size() and compareTo(left,largest)){
			largest=left;
		}
		if(right <arr.size() and compareTo(right,largest))
		{
			largest=right;
		}

		if(largest!=i){
			swap(arr[i],arr[largest]);
			downHeapify(largest);
		}
	}

    // log n

	void upHeapify(int i){
		if( i and arr[parent(i)] < arr[i])
		{
			swap(arr[i],arr[parent(i)]);
			upHeapify(parent(i));
		}
	}

public:
	int size(){
		return arr.size();
	}

	bool isEmpty(){
		return size()==0;
	}
    // o(1)
	void push(int data){
		arr.push_back(data);
		int index=size()-1;
		upHeapify(index);
	}

    // log n 
	void pop(){
		if(size()==0){
			cout<<"Index out of bounds"<<endl;
		}
		// replace the root of the heap with the last element of vector
		arr[0]=arr.back();
		arr.pop_back();

		// call downheapify on the root node
		downHeapify(0);
	}


    // o(1) 
	int top(){
		if(size()==0){
			cout<<"Index out of bound"<<endl;
		}
		return arr.at(0);
	}
};

int main()
{
	MaxHeap pq;
	pq.push(3);
	pq.push(2);
	pq.push(15);

	 cout << "Size is " << pq.size() << endl;

	  cout << pq.top() << " ";
    pq.pop();
 
    cout << pq.top() << " ";
    pq.pop();
 
    pq.push(5);
    pq.push(4);
    pq.push(45);

    return 0;
}