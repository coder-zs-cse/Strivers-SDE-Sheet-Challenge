#include <bits/stdc++.h> 
vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
	// Write your code here.
	sort(arr.begin(),arr.end());
	vector<vector<int>> output;
	for(int i=0;i<n-2;i++){
		if(i!=0) while(arr[i]==arr[i-1]) i++;
		int left = i+1;
		int right = n-1;
		while(left<right){
			if(arr[i]+arr[left]+arr[right]==K) {
				output.push_back({arr[i],arr[left],arr[right]});
				left++;
				while(arr[left]==arr[left-1]) left++;
				right--;
				while(arr[right]==arr[right+1]) right--;
			}
			else if(arr[i]+arr[left]+arr[right]>K) right--;
			else left++;
		}
	}
	return output;
}