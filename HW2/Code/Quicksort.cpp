#include <iostream> 
#include <time.h>
using namespace std;

void Quicksort(int*,int,int);
void Swap(int*,int*);
int Partition(int*,int,int);

int main(){
	int size;
	while(1){
		cin >> size;
		if(size==0)
			break;
		int arr[size];
		for(int i=0;i<size;i++){
			cin >> arr[i];
		}
		
		Quicksort(arr,0,size-1);
	
		for(int i=0;i<size;i++){
			cout << arr[i] << " ";
		}
		cout << endl;
	}

	return 0;
}

void Quicksort(int *arr,int front,int end){
	int pivot;
	if (front < end){
		pivot = Partition(arr,front,end);
		Quicksort(arr,front,pivot-1);
		Quicksort(arr,pivot+1,end);
	}
}

void Swap(int *a,int *b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int Partition(int *arr,int front,int end){
	int pivot,a;
	pivot = end;
	a = front-1;
	for(int i=front;i<=end;i++){
		if (arr[i] <= arr[pivot]){
			a++;
			Swap(&arr[a],&arr[i]);
		}
	}
	return a;
}
