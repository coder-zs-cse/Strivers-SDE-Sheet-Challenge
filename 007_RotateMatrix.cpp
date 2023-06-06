#include <bits/stdc++.h>

void rotateMatrix(vector<vector<int>> &mat, int n, int m)
{
    // Write your code here
    if(n==1 || m==1) return ;
    int left = 0;
    int right = m-1;
    int up = 0;
    int down = n-1;
    int i=0,j=0;
    int prev;
    while(left<right && up<down){
        prev = mat[i][j];
        for(j=j+1;j<=right;j++){
            swap(prev,mat[i][j]);
        }
        j = right;
        up++;
        for(i=i+1;i<=down;i++){
            swap(prev,mat[i][j]);
        }
        i=down;
        right--;
        for(j=j-1;j>=left;j--){
            swap(prev,mat[i][j]);
        }
        j = left;
        down--;
        for(i=i-1;i>=up;i--){
            swap(prev,mat[i][j]);
        }
        mat[i][j] = prev;
        left++;
        i = up;
        j=left;
    }

}