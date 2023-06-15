#include <bits/stdc++.h>
bool checkMaj(vector<int>  &arr,int maj){
    int votes = 0;
    int n = arr.size();
    for(int i=0;i<n;i++){
        if(arr[i]==maj) votes++;
    }
    if(votes>n/3) return true;
    return false;
}

vector<int> majorityElementII(vector<int> &arr)
{
    // Write your code here.
    int maj1=-1,maj2=-1;
    int vot1 = 0, vot2 = 0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]==maj1){
            vot1++;
        }
        else if(arr[i]==maj2){
            vot2++;
        }
        else if(maj1==-1 || vot1==0){
            maj1 = arr[i];
            vot1 = 1;
        }
        else if(maj2==-1 || vot2==0){
            maj2 = arr[i];
            vot2 = 1;
        }
        else{
            vot1--;
            vot2--;
        }
    }
    vector<int> output;
    if(checkMaj(arr,maj1)) output.push_back(maj1);
    if(checkMaj(arr,maj2)) output.push_back(maj2);
    return output;

}