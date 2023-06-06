#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    // Write your code here.
    int output = 0;
    int lower = INT_MAX;
    int higher = 0;
    for(int i=0;i<prices.size();i++){
        if(prices[i]<lower){
            lower = prices[i];
            higher = 0;
        }
        else if(prices[i]>higher){
            higher = prices[i];
        }
        output = max(output,higher-lower);
    }
    return output;
}