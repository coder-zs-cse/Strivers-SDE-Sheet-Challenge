#include <bits/stdc++.h>

vector<vector<int>> pairSum(vector<int> &arr, int s){
   // Write your code here.
   vector<vector<int>> output;
   unordered_map<int,int> freq;
   for(auto num:arr){
      int count = freq[s-num];
      for(int i=0;i<count;i++){
         output.push_back({min(s-num,num),max(num,s-num)});
      }
      freq[num]++;
   }
   sort(output.begin(),output.end());
   return output;
}