#include <bits/stdc++.h> 
void combine(string &s,vector<string> &output,string &current,int mask){
    int n = s.length();
    if(current.length()==n) {
        output.push_back(current);
        return;
    }
    for(int i=0;i<s.length();i++){
        if(1<<i & mask) continue;
        current.push_back(s[i]);
        combine(s,output,current,mask | (1<<i));
        current.pop_back();
    }
}
vector<string> findPermutations(string &s) {
    // Write your code here.
    vector<string> output;
    string current = "";
    combine(s,output,current,0);
    return output;
}