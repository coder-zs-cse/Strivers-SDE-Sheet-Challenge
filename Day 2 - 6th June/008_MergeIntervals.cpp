#include <bits/stdc++.h> 
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    // Write your code here.
    sort(intervals.begin(),intervals.end());
    vector<vector<int>> finalIntervals;
    finalIntervals.push_back({intervals[0][0],intervals[0][1]});
    for(int i=1;i<intervals.size();i++){
        if(intervals[i][0]<=finalIntervals.back()[1]){
            int sz = finalIntervals.size();
            finalIntervals[sz-1][1] = max(finalIntervals[sz-1][1],intervals[i][1]);
        }
        else finalIntervals.push_back({intervals[i][0],intervals[i][1]});
    }
    return finalIntervals;
}
