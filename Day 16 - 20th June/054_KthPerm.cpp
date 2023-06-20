int getKth(vector<int> &taken,int k){
    k+=1;
    for(int i=0;i<taken.size();i++){
        if(taken[i]==0) k--;
        if(k==0){
            taken[i] = 1;
            return i+1;
        }
    }
    return -1;
}
string kthPermutation(int n, int k) {
    // Write your code here.
    vector<int> taken(n,0);
    vector<int> perm(n+1,1);
    for(int i=1;i<n;i++){
        perm[i] = i*perm[i-1];
    }
    k-=1;
    string output  = "";
    for(int i=0;i<n;i++){
        int index = k/perm[n-i-1];
        k-=perm[n-i-1]*index;
        output+=to_string(getKth(taken,index));
    }
    return output;
}
