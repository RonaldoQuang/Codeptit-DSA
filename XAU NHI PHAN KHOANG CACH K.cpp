//Hãy liệt kê các xâu nhị phân có độ dài N nhưng cách nhau đúng K vị trí.
//Tức là nếu đánh số thứ tự từ 0 thì cần liệt kê các xâu tại vị trí 0, K, 2K, 3K, … trong 2N xâu theo thứ tự từ điển.
//Input
//4 3
//Output
//0000
//0011
//0110
//1001
//1100
//1111
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
int main(){
    int n, k, cnt=0; cin >> n >> k;
    int a[100], x=1;
    kt(a,n);
    while(x){
	if(cnt%k==0){
	for(int i=0;i<n;i++){
	    cout << a[i];
	}
	cout << endl;
	}
	if(sinh(a,n)){
	    ++cnt;
	    x=1;
	}
	else x=0;
    }
}
