bool isValid(int matrix[9][9],int i,int j,int value){
    for(int k=0;k<9;k++){
        if(matrix[k][j]==value) return false;
        if(matrix[i][k]==value) return false;
    }
    int xcor[5] = {-2,-1,0,1,2};
    int ycor[5] = {-2,-1,0,1,2};
    int leftx = 2-i%3;
    int lefty = 2-j%3;
    
    for(int k=leftx;k<leftx+3;k++){
        for(int l=lefty;l<lefty+3;l++){
            if(matrix[i+xcor[k]][j+ycor[l]]==value) return false;
        }
    }
    return true;
}
bool backTracking(int matrix[9][9],int i,int j){
    if(i==9) return true;
    if(j==9) return backTracking(matrix,i+1,0);
    if(matrix[i][j]!=0) return backTracking(matrix,i,j+1);
    for(int x=1;x<=9;x++){
        if(isValid(matrix,i,j,x)) {
            matrix[i][j] = x;
            if(backTracking(matrix,i,j+1)) return true;
            matrix[i][j] = 0;
        }
    }
    return false;
}
bool isItSudoku(int matrix[9][9]) {
    // Write your code here.
    return backTracking(matrix,0,0);
}
