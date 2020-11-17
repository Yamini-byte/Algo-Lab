#include <iostream>
using namespace std;

void merge(int arr[], int start, int mid, int end){
    int start2=mid+1;
    
    if(arr[mid]<=arr[start2]){
        return;
    }
    
    while(start<=mid && start2<=end){
        if(arr[start2]>=arr[start]){
            start++;
        }
        
        else{
            int value=arr[start2];
            int index=start2;
            
            while(index!=start){
                arr[index]=arr[index-1];
                index--;
            }
            
            arr[start]=value;
            
            start++;
            mid++;
            start2++;
        }
    }
}

void mergeSort(int arr[], int l, int r){
    
    if(l<r){
      int mid=l+(r-l)/2;  
      
      mergeSort(arr,l,mid);
      mergeSort(arr,mid+1,r);
      
      merge(arr,l,mid,r);
    }
}

void printArray(int arr[], int size){
    int i;
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}

int main() {
	int arr[]={3,41,52,26,38,57,9,49};
	
	int arr_size= sizeof(arr)/sizeof(arr[0]);
	
	mergeSort(arr,0,arr_size-1);
	
	printArray(arr,arr_size);
	
	return 0;
}
