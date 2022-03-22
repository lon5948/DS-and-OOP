#include <iostream>
using namespace std;

void Mergesort(int*,int,int);
void Merge(int*,int,int,int);

int main(){
    int size;
    while(1){
    	cin >> size;
    	if(size==0){
    		break;
		}
    	int arr[size];
    	for(int i=0;i<size;i++){
       	 cin >> arr[i];
   	    }
    
   		Mergesort(arr,0,size-1);
    
    	for(int i=0;i<size;i++){
        	cout << arr[i] << " ";
    	}
    	cout << endl;
	}
    return 0;
} 

void Mergesort(int *arr,int left,int right){
    int middle;
    if(right>left){
        middle = (left+right)/2;
        Mergesort(arr,left,middle);
        Mergesort(arr,middle+1,right);
        Merge(arr,left,middle,right);
    }
}

void Merge(int *arr,int left,int middle,int right){
    int lsize = middle-left+1;
    int rsize = right-middle; 
    int L[lsize],R[rsize];
    
    for(int i=0;i<lsize;i++){
        L[i] = arr[left+i];
    }
    for(int i=0;i<rsize;i++){
        R[i] = arr[middle+1+i];
    }
    
    int i=0,j=0;
    for(int k=left;k<=right;k++){
        if(i<lsize && j<rsize){
            if(L[i]<=R[j]){
                arr[k] = L[i];
                i++;
            }
            else{
                arr[k] = R[j];
                j++;
            }
        }    
        else if(i<lsize){
            arr[k] = L[i];
            i++;
        }
        else if(j<rsize){
            arr[k] = R[j];
            j++;
        }
    }
}
