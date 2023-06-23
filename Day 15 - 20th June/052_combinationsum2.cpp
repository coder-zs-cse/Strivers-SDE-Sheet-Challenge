#include<bits/stdc++.h>
void combine(vector<int> &arr,int index,vector<vector<int>> &output,vector<int> &current,int target){
	if(target<0) return;
	if(target==0){
		output.push_back(current);
		return;
	}
	int n = arr.size();
	for(int i=index;i<n;i++){
		if(i>index && arr[i]==arr[i-1]) continue;
		current.push_back(arr[i]);
		combine(arr,i+1,output,current,target-arr[i]);
		current.pop_back();
	}
}
vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target)
{
	// Write your code here.
	vector<int> current;
	vector<vector<int>> output;
	sort(arr.begin(),arr.end());
	combine(arr,0,output,current,target);
	return output;
}
