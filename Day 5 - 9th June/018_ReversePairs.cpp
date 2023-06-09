#include <bits/stdc++.h> 
int compute(vector<int> &left,vector<int> &right,int &j,int &count,int i,int leftSize){
    count+= leftSize - (upper_bound(left.begin()+i,left.end(),2*right[j])-left.begin());
    return right[j++];
}
int merge(vector<int> &arr,int l,int mid,int r){
    int leftSize = mid-l+1;
    int rightSize = r-mid;
    vector<int> left (leftSize);
    vector<int> right(rightSize);

    for(int i=l;i<=r;i++){
        if(i-l<leftSize) left[i-l] = arr[i];
        else right[i-mid-1] = arr[i];
    }
    int i=0,j=0;
    int count = 0;
    for(int k = l;k<=r;k++){
        arr[k] = i<leftSize && (j>=rightSize || left[i]<right[j]) ? left[i++] : compute(left,right,j,count,i,leftSize);
    }
    return count;

}
// 5 4 3 2 1
int mergeSort(vector<int> &arr,int l,int r){
    int count = 0;
    if(l<r){
        int mid = l + (r-l)/2;
        count+=mergeSort(arr,l,mid);
        count+=mergeSort(arr,mid+1,r);
        count+=merge(arr,l,mid,r);
    }
    return count;
}
int reversePairs(vector<int> &arr, int n){
	int output  = mergeSort(arr,0,n-1);	
	return output;
}