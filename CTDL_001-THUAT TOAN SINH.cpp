//Một xâu nhị phân độ dài n được gọi là thuận nghịch hay đối xứng nếu đảo ngược xâu nhị phân đó ta vẫn nhận được chính nó. 
//Cho số tự nhiên n (n nhập từ bàn phím). 
//Hãy viết chương trình liệt kê tất cả các xâu nhị phân thuận nghịch có độ dài n.  
//Hai phần tử khác nhau của xâu thuận nghịch được ghi cách nhau một khoảng trống.
//Input
//4
//Output
//0 0 0 0

//0 1 1 0

//1 0 0 1

//1 1 1 1
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
int check(int a[100], int n){
    for(int i=0;i<n/2;i++){
	if(a[i]!=a[n-1-i]) return 0;
    }
    return 1;
}
int main(){
    int n; cin >> n;
    int a[100];
    int x=1;
    kt(a,n);
    while(x){
	if(check(a,n)){
	    for(int i=0;i<n;i++){
		cout << a[i] << " ";
	    }
	    cout << endl << endl;
	}
	if(sinh(a,n)) x=1;
	else x=0;
    }
}
