#include <bits/stdc++.h>

vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
	// Write your code here.
	for(int i=m-1;i>=0;i--){
		arr1[n+i] = arr1[i];
		arr1[i]=0;
	}
	int i=n,j=0;
	for(int k=0;k<m+n;k++){
		int current = (i < m + n && (j >= n || arr1[i] < arr2[j])) ? arr1[i++] : arr2[j++];
		arr1[k] = current;
	}
	return arr1;
}
