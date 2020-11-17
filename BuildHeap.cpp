#include <stdio.h>


void MaxHeapify(int A[], int i, int size){
    int largest,temp;
    int left=(2*i)+1;
    int right=(2*i)+2;
    
    if(left<=size && A[left]>A[i]){
        largest=left;
    }
    else
        largest=i;
    if(right<=size && A[right]>A[largest])
        largest=right;
    if(largest!=i){
        temp=A[i];
        A[i]=A[largest];
        A[largest]=temp;
        
        MaxHeapify(A,largest,size);
    }
    
}

void BuildMaxHeap(int arr[],int size){
    int i;
    int startIndex=(size/2)-1;
    
    for(i=startIndex;i>=0;i--){
        MaxHeapify(arr,i,size);
    }
}

void printHeap(int arr[], int n) 
{ 
    int i;
    printf("Array representation of Heap is:\n"); 
  
    for (i = 0; i < n; i++) 
        //cout << arr[i] << " ";
        printf("%d ", arr[i]);
    //cout << "\n";
    printf("\n");
} 


int main() {
    
    //clrscr();
    
	int A[]={8,13,9,5,12,15,7,4,0,6,2,1};
	
	int size= sizeof(A)/sizeof(A[0]);
	
	BuildMaxHeap(A,size);
	
	printHeap(A,size);
	
	//heapExtractMax(A,size);
	
	return 0;
}
