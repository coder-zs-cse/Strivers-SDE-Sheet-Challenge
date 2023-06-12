#include <bits/stdc++.h> 
int uniqueSubstrings(string input)
{
    //Write your code here
    vector<int> lastIndex(26,-1);
    int output = 0;
    int left = 0;
    for(int i=0;i<input.length();i++){
        char current = input[i]-'a';
        if(lastIndex[current]!=-1){
            left = max(left,lastIndex[current]+1);
        }
        lastIndex[current] = i;
        output = max(output,i-left+1);
    }
    return output;
}