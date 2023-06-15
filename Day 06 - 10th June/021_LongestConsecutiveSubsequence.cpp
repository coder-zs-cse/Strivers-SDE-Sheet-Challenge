// TC = NlogN MC = 1

#include <bits/stdc++.h>

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    // Write your code here.
    // cout<<"start"<<endl;
    vector<int> lcs;
    sort(arr.begin(),arr.end());
    int output = 1;
    int count = 1;
    for(int i=1;i<n;i++){
        if(arr[i]==arr[i-1]) continue;
        if(arr[i]==arr[i-1]+1){
            count++;
        }
        else count=1;
        output = max(output,count);
    }
    return output;

}


// TC = N MC = N

#include <bits/stdc++.h>

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    // Write your code here.
    // cout<<"start"<<endl;
    unordered_map<int,int> record;
    int output = 1;
    for(int i=0;i<n;i++){
        auto check = record.find(arr[i]);
        if(check!=record.end()) continue;
        auto check1 = record.find(arr[i]-1);
        auto check2 = record.find(arr[i]+1);
        if(check1!=record.end() && check2!=record.end()){
            int start1 = record[arr[i]-1];
            int end2 = record[arr[i]+1];
            record[start1] = end2;
            record[end2] = start1;
            output = max(output,end2-start1+1);
            record[arr[i]] = -1;
        }
        else if(check1!=record.end()){
            int start1 = record[arr[i]-1];
            record[start1] = arr[i];
            record[arr[i]] = start1;
            output = max(output,arr[i]-start1+1);
        }
        else if(check2!=record.end()){
            int end2 = record[arr[i]+1];
            record[end2] = arr[i];
            record[arr[i]] = end2;
            output = max(output,end2-arr[i]+1);
        }
        else{
            record[arr[i]] = arr[i];
        }
    }
    return output;

}