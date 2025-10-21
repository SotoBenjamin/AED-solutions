#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct Heap_Sort{
	T* arr = nullptr; // array
	int N = 0; //size of heap
	int n = 0; //tamaño del array
	Heap_Sort(vector<T>& A){
		//1 indexed
        A.insert(A.begin(),0); // 1 elemento
		build_max_heap(A);
        heap_sort();
        A.erase(A.begin());
    }
	
	int left(int i){
		return 2*i;
	}
	
	int right(int i){
		return 2*i + 1;
	}
	
    void heap_sort(){
        for(int i = n ; i >= 2 ; i--){
			swap(arr[1],arr[N]);
			N--;
			max_heapify_down(1);
		}
    }

	void build_max_heap(vector<T> & A){
		arr = A.data(); //
		n = A.size() - 1;
		N = n;
		for(int i = N/2 ; i >= 1 ; i--){
			max_heapify_down(i);
		}
	}
	
	void max_heapify_down(int i){
		int l = left(i);
		int r = right(i);
		int largest = i;
		if(l <= N && arr[l] > arr[largest]) largest = l;
		if(r <= N && arr[r] > arr[largest]) largest = r;
		if(largest != i){
			swap(arr[i],arr[largest]);
			max_heapify_down(largest);
		}
	}
};

int main(){
	
	return 0;
}
