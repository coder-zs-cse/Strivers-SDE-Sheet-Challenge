#include <bits/stdc++.h> 

long long compute(long long *right,int &j,long long &count,int i,int leftSize){
    count+=leftSize-i;
    return right[j++];
}
long long merge(long long *arr,int l,int mid,int r){
    int leftSize = mid-l+1;
    int rightSize = r-mid;
    long long *left = new long long[leftSize];
    long long *right = new long long[rightSize];

    for(int i=l;i<=r;i++){
        if(i-l<leftSize) left[i-l] = arr[i];
        else right[i-mid-1] = arr[i];
    }
    int i=0,j=0;
    long long count = 0;
    for(int k = l;k<=r;k++){
        arr[k] = i<leftSize && (j>=rightSize || left[i]<right[j]) ? left[i++]:compute(right,j,count,i,leftSize);
    }
    return count;

}
// 5 4 3 2 1
long long mergeSort(long long *arr,int l,int r){
    long long count = 0;
    if(l<r){
        int mid = l + (r-l)/2;
        count+=mergeSort(arr,l,mid);
        count+=mergeSort(arr,mid+1,r);
        count+=merge(arr,l,mid,r);
    }
    return count;
}
long long getInversions(long long *arr, int n){
    // Write your code here.
    return mergeSort(arr,0,n-1);
    

}