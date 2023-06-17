int longestSubSeg(vector<int> &arr , int n, int k){
    // Write your code here.
    int window = 0;
    int left = 0;
    for(int i=0;i<n;i++){
        if(arr[i]==0){
            while(k<=0) {
                if(arr[left]==0) k++;
                left++;
            }
            k--;
        }
        window = max(window,i-left+1);
    }
    return window;
}
