#include <bits/stdc++.h> 
vector<int> subsetSum(vector<int> &num)
{
    // Write your code here.
    vector<int> output;
    output.push_back(0);
    int n  = num.size();
    for(int i=0;i<n;i++){
        int sz = output.size();
        for(int j=0;j<sz;j++){
            output.push_back(output[j]+num[i]);
        }
    }
    sort(output.begin(),output.end());
    return output;
}