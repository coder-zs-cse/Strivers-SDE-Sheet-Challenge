#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	// Write your code here 
	int twice, missing;
	for(int i=0;i<n;i++){
		if(arr[abs(arr[i])-1]<0) twice = abs(arr[i]);
		else{
			arr[abs(arr[i])-1] *=-1;
		}
	}
	for(int i=0;i<n;i++){
		if(arr[i]>0) missing = i+1;
	}
	return make_pair(missing,twice);
}

/*
Arr size: N
Numbers in range [1,N]
R in range [1,N] which appears twice
M in range [1,N] which is missing

{ -6,4,-3,-5,-5,-1 }
{ 0,1,2,3,4,5 }

*/