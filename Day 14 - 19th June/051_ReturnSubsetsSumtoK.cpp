#include<bits/stdc++.h>
vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    // Write your code here.
    unordered_map<int,vector<vector<int>>> record;
    record[0] = {{}};
    for(int i=0;i<n;i++){
        unordered_map<int,vector<vector<int>>> temp;
        for(auto it:record){
            int newsum = it.first + arr[i];
            vector<vector<int>> current = it.second;
            for(int j=0;j<current.size();j++){
                current[j].push_back(arr[i]);
                temp[newsum].push_back(current[j]);
            }
        }
        for(auto it:temp){
            for(auto curr:it.second){
                record[it.first].push_back(curr);
            }
        }
    }
    return record[k];
}