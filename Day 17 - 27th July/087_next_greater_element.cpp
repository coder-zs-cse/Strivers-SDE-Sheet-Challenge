#include <bits/stdc++.h> 

vector<int> nextGreater(vector<int> &arr, int n) {
    // Write your code here
    vector<int> output(n,-1);
    stack<int> record;
    for(int i=0;i<n;i++){
        while(!record.empty() && arr[i]>arr[record.top()]){
            int index = record.top();
            record.pop();
            output[index] = arr[i];
        }
        record.push(i);
    }
    return output;
}