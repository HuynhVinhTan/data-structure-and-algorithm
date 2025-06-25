#include <stdio.h>

int A[] = {0,4,1,3,2,16,9,10,14,8,7};
int length = 10;
int heap_size = 10;

void max_heapify(int i) {
	int l = 2*i;
	int r = 2*i+1;
	int largest = i;
	if (l<=heap_size && A[l]>A[largest])
		largest = l;
	if (r<=heap_size && A[r]>A[largest])
		largest = r;
	if (largest!=i) {
		int tmp = A[i];
		A[i] = A[largest];
		A[largest] = tmp;
		max_heapify(largest);
	}
}

void build_maxheap() {
	for (int i=length/2;i>=1;i--)
		max_heapify(i);
}

void heap_sort() {
	build_maxheap();
	for (int i=length; i>=2; i--)
	{
		int tmp = A[1];
		A[1] = A[i];
		A[i] = tmp;
		heap_size--;
		max_heapify(1);
	}
}

int main(){	
	heap_sort();
	for (int i=1;i<=length;i++)
		printf("%d ",A[i]);
	return 0;
}