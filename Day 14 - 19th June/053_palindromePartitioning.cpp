#include <bits/stdc++.h> 
vector<vector<string>> partition(string &s) 
{
    // Write your code here.
    int n = s.length();
    if(n==0) return {{}};
    vector<vector<vector<string>>> dp(n);
    for(int i=0;i<n;i++){
        
        string current(1,s[i]);

        for(int j=0;i-j>=0 && i+j<n;j++){
            if(s[i-j]!=s[i+j]) break;
            if(j!=0) current = string(1,s[i-j]) + current + string(1,s[i+j]);
            vector<vector<string>> prev={{}};
            if(i-j-1>=0) prev = dp[i-j-1];
            for(auto it:prev){
                it.push_back(current);
                dp[i+j].push_back(it);
            }
        }

        current = "";
        
        for(int j=0;i-j>=0 && i+j+1<n;j++){
            if(s[i-j]!=s[i+j+1]) break;
            current = string(1,s[i-j]) + current + string(1,s[i+j+1]);
            vector<vector<string>> prev={{}};
            if(i-j-1>=0) prev = dp[i-j-1];
            for(auto it:prev){
                it.push_back(current);
                dp[i+j+1].push_back(it);
            }
        }

    }
    return dp[n-1];
}