#include <bits/stdc++.h>

string fourSum(vector<int> arr, int target, int n) {
    // Write your code here.
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int k = j+1;
            int l = n-1;
            int sum = arr[i]+arr[j];
            while(k<l){
                if(sum+arr[k]+arr[l]>target) l--;
                else if(sum+arr[k]+arr[l]<target) k++;
                else return "Yes";
            }
        }
    }
    return "No";
}
