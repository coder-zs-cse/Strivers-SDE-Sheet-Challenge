#include <bits/stdc++.h> 
int jobScheduling(vector<vector<int>> &jobs)
{
    // Write your code here
    sort(jobs.begin(),jobs.end(),[](vector<int> &a,vector<int> &b){return a[1]>b[1];});
    int n = jobs.size();
    vector<int> assign(100000,-1);
    int output = 0;
    for(int i=0;i<n;i++){
        int j = jobs[i][0]-1;
        while(j>=0 && assign[j]==1){
            j--;
        }
        if(j>=0){
            output+=jobs[i][1];
            assign[j] = 1;
        }
    }
    return output;
}
