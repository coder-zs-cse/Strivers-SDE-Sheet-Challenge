#include <bits/stdc++.h> 
int findMinimumCoins(int amount) 
{
    // Write your code here
    vector<int> denom = {1,2,5,10,20,50,100,500,1000};
    int value = amount;
    int index = denom.size()-1;
    int output = 0;
    while(value){
        output+= value/denom[index];
        value%=denom[index];
        index--;
    }
    return output;
}
