//Cho mảng A[], B[] đều có N phần tử. 
//Nhiệm vụ của bạn là tìm giá trị nhỏ nhất của  biểu thức P = A[0]*B[0] + A[1]*B[1] + ..+A[N-1]*B[N-1] bằng cách tráo đổi vị trí các phần tử của cả mảng A[] và B[].
//Input
//2
//7
//1 6 3 4 5 2 7
//1 1 1 2 3 4 3
//7
//1 6 3 5 5 2 2
//0 1 9 0 1 2 3
//Output
//45
//27
#include <bits/stdc++.h> 
using namespace std;
long long sum(long long a[], long long b[], int n){
	long long sum=0;
	sort(a,a+n);
	sort(b,b+n);
	for(int i=0;i<n;i++) sum+=a[i]*b[n-1-i];
	return sum;
}
int main(){ 
    int t; cin >> t; 
    while(t--){ 
        int n; cin >> n;
        long long a[n], b[n];
        for(int i=0;i<n;i++) cin >> a[i];
        for(int i=0;i<n;i++) cin >> b[i];
        long long min1=1e18;
        min1=min(min1,sum(a,b,n));
        min1=min(min1,sum(b,a,n));
        cout << min1 << endl;
	} 	 
}