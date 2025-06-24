//Cho hai đa thức P và Q được biểu diễn như một mảng bao gồm các hệ số của đa thức. 
//Ví dụ với P(x) = 5 + 0x^1 +10x^2 + 6x^3 được biểu diễn như mảng P[] ={5, 0, 10, 6}. 
//Hãy đưa ra đa thức R = P×Q theo các hệ số của R với cách biểu diễn như trên.
//Input
//2
//4 3
//1 0 3 2
//2 0 4
//5 4
//1 9 3 4 7
//4 0 2 5
//Output
//2 0 10 4 12 8
//4 36 14 39 79 23 34 35
#include <bits/stdc++.h>
using namespace std;
int main(){ 
    int t; cin >> t;
    while(t--){
    	int n, m; cin >> n >> m;
    	int a[n], b[m], dp[n+m-1];
    	memset(dp,0,sizeof(dp));
    	for(int &x:a) cin >> x;
    	for(int &x:b) cin >> x;
    	for(int i=0;i<n;i++){
    		for(int j=0;j<m;j++){
    			dp[i+j]+=a[i]*b[j];
			}
		}
		for(int i=0;i<n+m-1;i++){
			cout << dp[i] << " ";
		}
		cout << endl;
	}
}