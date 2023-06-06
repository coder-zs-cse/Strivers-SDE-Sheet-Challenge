#include <bits/stdc++.h>

void setZeros(vector<vector<int>> &matrix)
{
	// Write your code here.
	int n = matrix.size();
	int m = matrix[0].size();
	bool firstRowZero=1;
	bool firstColZero=1;
	for(int i=0;i<n;i++) firstColZero &= matrix[i][0]!=0;
	for(int j=0;j<m;j++) firstRowZero &= matrix[0][j]!=0;

	for(int i=1;i<n;i++){
		for(int j=1;j<m;j++){
			if(matrix[i][j]==0){
				matrix[i][0] = 0;
				matrix[0][j] = 0;
			}
		}
	}
	for(int i=1;i<n;i++){
		if(matrix[i][0]==0){
			for(int j=0;j<m;j++) matrix[i][j] = 0;
		}
	}
	for(int j=1;j<m;j++){
		if(matrix[0][j]==0){
			for(int i=0;i<n;i++) matrix[i][j] = 0;
		}
	}
	if(!firstRowZero){
		for(int j=0;j<m;j++) matrix[0][j]=0;
	}
	if(!firstColZero){
		for(int i=0;i<n;i++) matrix[i][0]=0;
	}
	
}