#include <bits/stdc++.h>

vector<vector<long long int>> printPascal(int n) 
{
  // Write your code here.
  vector<vector<long long>> output;
  output.push_back({1});
  for(int i=1;i<n;i++){
    vector<long long> current;
    current.push_back(1);
    for(int j=0;j<output[i-1].size()-1;j++){
      current.push_back(output[i-1][j]+output[i-1][j+1]);
    }
    current.push_back(1);
    output.push_back(current);
  }
  return output;
}
