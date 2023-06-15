#include <bits/stdc++.h>

int LongestSubsetWithZeroSum(vector < int > arr) {

  // Write your code here
  int sum = 0 ;
  unordered_map<int,int> record;
  record[0] = -1;
  int output = 0;
  for(int i=0;i<arr.size();i++){
    sum+=arr[i];
    auto check = record.find(sum);
    if(check!=record.end()){
      output = max(output,i-record[sum]);
    }
    else record[sum] = i;

  }
  return output;

}