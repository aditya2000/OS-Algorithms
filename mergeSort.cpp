#include <iostream>
using namespace std;

void merge(int arr[], int first, int last, int mid) {
	int n1 = mid - first + 1;
	int n2 = last - mid;
	
	int L[n1], R[n2];
	
	for(int i=0; i<n1; i++) {
		L[i] = arr[first+i];
	}
	
	for(int i=0; i<n2; i++) {
		R[i] = arr[mid+1+j];
	}
	
	int i=0, j=0, k=l;
	while(i<n1 && j<n2) {
		if(L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		} else {
			arr[k] = R[j];
			j++;
		}
		
		k++;
	}
	while(i<n1) {
		arr[k] = L[i];
		i++;
		k++;
	}
	
	while(i<n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}

void mergeSort(int arr[], int first, int last) {
	if(first < last) {
		int mid = first + (last - first)/2;
		
		mergeSort(arr, first, mid);
		mergeSort(arr, mid+1, last);
		
		merge(arr, first, last, mid);
	}
}

int main() {
	
}
