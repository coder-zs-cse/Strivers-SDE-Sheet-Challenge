bool canBePlaced(vector<int> &board,int i,int j,int n){
    for(int k=1;i-k>=0;k++){
        if(board[(i-k)*n+j]==1) return false;
    }
    for(int k=1;i-k>=0 && j+k<n;k++){
        if(board[(i-k)*n+(j+k)]==1) return false; 
    }
    for(int k=1;i-k>=0 && j-k>=0;k++){
        if(board[(i-k)*n+(j-k)]==1) return false; 
    }
    return true;
}
void backTracking(vector<int> &board,int i,int n,vector<vector<int>> &output){
    if(i==n){
        output.push_back(board);
        return;
    }
    for(int j=0;j<n;j++){
        if(canBePlaced(board,i,j,n)){
            board[i*n+j] = 1;
            backTracking(board, i+1, n, output);
            board[i*n+j] = 0;
        }
    }
}
vector<vector<int>> solveNQueens(int n) {
    // Write your code here.
    vector<int> board(n*n,0);
    vector<vector<int>> output;
    backTracking(board, 0, n, output);
    return output;
}