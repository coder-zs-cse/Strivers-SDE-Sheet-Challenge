#include <bits/stdc++.h> 
vector<int> nextPermutation(vector<int> &permutation, int n)
{
    //  Write your code here.
    if(n==1) return permutation;
    int disc = 0;
    for(int i=n-1;i>0;i--){
        if(permutation[i]>permutation[i-1]){
            disc = i;
            break;
        }
    }
    if(disc!=0){
        
        int swappingInt = permutation[disc-1];
        int maxi = disc;
        for(int i=disc+1;i<n;i++){
          if (permutation[i] > swappingInt) {
            maxi = permutation[disc] < permutation[i] ? disc : i;
          }
        }
        swap(permutation[disc - 1], permutation[maxi]);
    }
    sort(permutation.begin()+disc,permutation.end());
    return permutation;

}