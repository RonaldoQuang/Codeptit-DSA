//Một xâu ký tự số chỉ bao gồm các chữ số 6 và 8 sẽ được gọi là “phát lộc” nếu thỏa mãn các điều kiện sau:
//Độ dài xâu ít nhất là 6
//Chữ số đầu tiên là chữ số 8, chữ số cuối cùng là chữ số 6
//Không có 2 chữ số 8 nào ở cạnh nhau
//Không có nhiều hơn 3 chữ số 6 ở cạnh nhau.
//Viết chương trình liệt kê các xâu ký tự phát lộc độ dài N theo thứ tự tăng dần.
//Input
//Chỉ có 1 dòng ghi số N (5 < N < 16).
//Output
//Ghi ra các xâu ký tự phát lộc độ dài N, mỗi xâu trên một dòng.
//Input
//6
//Output
//866686
//866866
//868666
//868686
#include <bits/stdc++.h>
using namespace std;
void kt(int a[100], int n){
	for(int i=0;i<n;i++){
		a[i]=6;
	}
}
int sinh(int a[100], int n){
	int i=n-1;
	while(i>=0&&a[i]==8){
		a[i]=6;
		--i;
	}
	if(i==-1) return 0;
	else{
		a[i]=8;
		return 1;
	}
}
int check(int a[100], int n){
	int cnt=0;
	if(a[0]==8&&a[n-1]==6){
		for(int i=0;i<n-1;i++){
			if(a[i]==8&&a[i]==a[i+1]||a[i]==6&&a[i]==a[i+1]&&a[i]==a[i+2]&&a[i]==a[i+3]){
				++cnt;
				break;
			}
		}
		if(cnt==0) return 1;
		else return 0;
	}
	else return 0;
}
int main(){
	int n; cin >> n;
	int a[100];
	int x=1;
	kt(a,n);
	while(x){
		if(check(a,n)){
			for(int i=0;i<n;i++){
			    cout << a[i];
		    }
		    cout << endl;
		}
		if(sinh(a,n)) x=1;
		else x=0;
	}
}