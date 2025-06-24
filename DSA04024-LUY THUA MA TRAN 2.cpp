//Cho ma trận vuông A kích thước N x N. 
//Nhiệm vụ của bạn là hãy tính ma trận X = A^K với K là số nguyên cho trước. 
//Sau đó, tính tổng các phần tử của cột cuối cùng. 
//Đáp số có thể rất lớn, hãy in ra kết quả theo modulo 109+7.
//Input
//2
//2 5
//1 1
//1 0
//3 1000000000
//1 2 3
//4 5 6
//7 8 9
//Output
//8
//581039956
#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
long long n, k;
long long a[100][100], d[100][100];
void mul(long long a[100][100], long long b[100][100]){
	long long c[100][100]={};
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++){
				c[i][j]+=a[i][k]*b[k][j];
				c[i][j]%=mod;
			}
		}
	}
	for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
        	a[i][j]=c[i][j];
        }
    }
		
}
void pow(long long a[100][100], long long k){
	if(k==1) return;
	pow(a,k/2);
	mul(a,a);
	if(k%2==1) mul(a,d);
}
int main(){
    int t; cin >> t;
    while(t--){
        cin >> n >> k;
        for(int i=0;i<n;i++){
        	for(int j=0;j<n;j++){
        		cin >> a[i][j];
        		d[i][j]=a[i][j];
			}
		}
		pow(a,k);
		long long sum=0;
		for(int i=0;i<n;i++){
			sum+=a[i][n-1];
			sum%=mod;
		}
		cout << sum << endl;
	}
}