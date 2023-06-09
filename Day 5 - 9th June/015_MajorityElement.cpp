#include <bits/stdc++.h>

int findMajorityElement(int arr[], int n) {
	// Write your code here.
	int votes = 1;
	int maj = arr[0];
	for(int i=1;i<n;i++){
		if(arr[i]!=maj) {
			if(votes) votes--;
			else {
				maj = arr[i];
				votes=1;
			}
		}
		else votes++;
	}
	votes = 0;
	for(int i=0;i<n;i++){
		if(arr[i]==maj) votes++;
	}
	return votes>n/2 ? maj:-1;
}