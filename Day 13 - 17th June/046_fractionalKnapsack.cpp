#include <bits/stdc++.h> 
double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    // Write your code here.
    // ITEMS contains {weight, value} pairs.
    vector<pair<double,int>> unitValue(n);
    for(int i=0;i<n;i++){
        unitValue[i] = make_pair((double)items[i].second/items[i].first,i);
    }
    sort(unitValue.begin(),unitValue.end());
    double bag = 0;
    double output = 0;
    for(int i=n-1;i>=0;i--){
        int index = unitValue[i].second;
        if(bag+items[index].first<=w) {
            bag+=items[index].first;
            output+=items[index].second;
        }
        else{
            double currentValue = (double)((double)(w-bag)/(double)items[index].first)*items[index].second;
            output+=currentValue;
            break;
        }
    }
    return output;

    
}