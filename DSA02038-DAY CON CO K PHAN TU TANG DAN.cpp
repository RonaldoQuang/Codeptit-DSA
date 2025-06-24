//Cho dãy số A[] có N phần tử là các số nguyên dương khác nhau từng đôi một và một số K < N.
//Hãy liệt kê tất cả các dãy con khác nhau có K phần tử của A[], mỗi dãy đều được sắp xếp theo thứ tự tăng dần.
//Các dãy con được liệt kê lần lượt theo thứ tự từ điển.
//Input
//Dòng đầu ghi số bộ test, mỗi test có 2 dòng:
//Dòng đầu ghi hai số N và K (2 < K < N <15)
//Dòng thứ 2 ghi N số của dãy A[], các số đều nguyên dương, nhỏ hơn 100 và khác nhau từng đôi một.
//Output
//Với mỗi test, liệt kê tất cả các dãy con thỏa mãn, mỗi dãy con trên một dòng. 
//Input
//1
//4 3
//3 2 5 4
//Output
//2 3 4
//2 3 5
//2 4 5
//3 4 5
#include <bits/stdc++.h>
using namespace std;
void kq(int a[100], int b[100], int n){
	for(int i=1;i<=n;i++){
		if(b[i]==1){
            cout << a[i] << " ";
		}
	}
	cout << endl;
}
void Try(int a[100], int b[100], int n, int k, int i, int cnt){
	b[i]=1;
	for(int j=i+1;j<=n;j++){
		++cnt;
		if(cnt%k==0){
			b[j]=1;
			kq(a,b,n);
		}
		else{
			Try(a,b,n,k,j,cnt);
		}
		b[j]=0;
		cnt-=1;
	}
	b[i]=0;
}
int main(){
	int t; cin >> t;
	while(t--){
		int a[100], b[100], n, k, cnt=1; cin >> n >> k;
	    for(int i=1;i<=n;i++){
		    cin >> a[i];
		    b[i]=0;
	    }
	    sort(a+1,a+n+1);
	    for(int i=1;i<=n-k+1;i++){
		    Try(a,b,n,k,i,cnt);
	    }
	}
}