#include <bits/stdc++.h> 
vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {
    // Write your code here.
	vector<vector<int>> record;
	int n  = start.size();
	for(int i=0;i<n;i++){
		record.push_back({start[i],end[i],i});
	}
	sort(record.begin(),record.end());
	vector<int> output;
	for(int i=0;i<n;i++){
		if(output.empty()){
			output.push_back(record[i][2]);
		}
		else{
			if(record[i][0]==start[output.back()]) continue;
		 	if(record[i][0]>end[output.back()]){
				output.push_back(record[i][2]);
			}
			else{
				if(record[i][1]<end[output.back()])
					output[output.size()-1] = record[i][2];
				else if(record[i][1]==end[output.back()]){
					if(record[i][2]<output.back()){
						output[output.size()-1] = record[i][2];
					}
				}
			}
		}
	}
	for(int i=0;i<output.size();i++) output[i]+=1;
	return output;
}

// 0 1 4 7 8
// 2 5 9 9 10
// 0 2 3 1 4