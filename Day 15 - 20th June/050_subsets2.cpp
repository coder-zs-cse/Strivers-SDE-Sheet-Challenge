#include <bits/stdc++.h> 
void combine(vector<int> &arr,int index,vector<vector<int>> &output,vector<int> &current){
	int n = arr.size();
	if(index==n){
		output.push_back(current);
		return;
	}
    output.push_back(current);
	for(int i=index;i<n;i++){
		if(i>index && arr[i]==arr[i-1]) continue;
		current.push_back(arr[i]);
		combine(arr,i+1,output,current);
		current.pop_back();
	}
}
vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    // Write your code here.
    vector<int> current;
	vector<vector<int>> output;
	sort(arr.begin(),arr.end());
	combine(arr,0,output,current);
	return output;
}