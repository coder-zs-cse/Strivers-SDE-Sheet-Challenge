#include <bits/stdc++.h>

int subarraysXor(vector<int> &arr, int x)
{
    //    Write your code here.
    unordered_map<int,int> record;
    record[0] = 1;
    int current = 0;
    int output = 0; 
    for(int i=0;i<arr.size();i++){
        current ^= arr[i];
        auto check = record.find(current^x);
        if(check!=record.end()){
            output+=record[current^x];
        }
        record[current]++;
    }
    cout<<endl;
    return output;
    
}