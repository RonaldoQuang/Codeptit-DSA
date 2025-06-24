//Hãy in ra tất cả các xâu nhị phân độ dài N, có K bit 1 theo thứ tự từ điển tăng dần.
//Input: Dòng đầu tiên là số lượng bộ test T (T ≤ 20). 
//Mỗi test gồm 2 số nguyên N, K (1 ≤ K ≤ N ≤ 16).
//Output:  Với mỗi test, in ra đáp án tìm được, mỗi xâu in ra trên một dòng.
//Input
//2
//4 2
//3 2
//Output
//0011
//0101
//0110
//1001
//1010
//1100
//011
//101
//110
#include <bits/stdc++.h>
using namespace std;
void kt(int a[100], int n){
	for(int i=0;i<n;i++){
		a[i]=0;
	}
}
int sinh(int a[100], int n){
	int i=n-1;
	while(i>=0&&a[i]==1){
		a[i]=0;
		--i;
	}
	if(i==-1) return 0;
	else{
		a[i]=1;
		return 1;
	}
}
int check(int a[100], int n, int k){
	int cnt=0;
	for(int i=0;i<n;i++){
		if(a[i]==1) ++cnt;
	}
	if(cnt==k) return 1;
	else return 0;
}
int main(){
	int t; cin >> t;
	while(t--){
		int n, k; cin >> n >> k;
	    int a[100];
	    int x=1;
	    kt(a,n);
	    while(x){
		    if(check(a,n,k)){
			    for(int i=0;i<n;i++){
			        cout << a[i];
		        }
		        cout << endl;
		    }
		    if(sinh(a,n)) x=1;
		    else x=0;
	    }
	}
}