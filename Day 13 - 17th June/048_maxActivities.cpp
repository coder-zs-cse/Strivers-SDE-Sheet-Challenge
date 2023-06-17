#include<bits/stdc++.h>
int maximumActivities(vector<int> &start, vector<int> &finish) {
    // Write your code here.

    vector<pair<int,int>> record;
    int n = start.size();
    for(int i=0;i<n;i++){
        record.push_back(make_pair(start[i],finish[i]));
    }
    sort(record.begin(),record.end());
    int index = 0;
    int output = 1;

    for(int i=1;i<n;i++){
        if(record[i].first>=record[index].second){
            output++;
            index = i;
        }
        else{
            if(record[i].second<record[index].second){
                index = i;
            }
        }
    }
    return output;
}