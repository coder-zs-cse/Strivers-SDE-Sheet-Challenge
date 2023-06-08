#include <bits/stdc++.h>
long long power(int x,int n,int m){
	if(n==0) return 1;
	if(n==1) return x;
	long long half = power(x,n/2,m);
	half = (half*half)%m;
	if(n&1) half = (half*x)%m;
	return half;
	
	
}
int modularExponentiation(int x, int n, int m) {
	// Write your code here.
	return power(x,n,m)%m;
}