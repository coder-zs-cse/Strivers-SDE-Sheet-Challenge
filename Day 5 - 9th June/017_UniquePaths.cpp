#include <bits/stdc++.h> 
int uniquePaths(int m, int n) {
	// Write your code here.
	vector<int> record(n,0);
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(i==0 && j==0) record[j]=1;
			else if(i==0){
				record[j] = record[j-1];
			}
			else if(j==0){
				record[j] = record[j];
			}
			else{
				record[j] = record[j] + record[j-1];
			}
		}

	}
	return record[n-1];
}