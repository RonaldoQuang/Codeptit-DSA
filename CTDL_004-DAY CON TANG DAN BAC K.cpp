//Cho dãy gồm N số phân biệt AN = {a1, a2, .., aN } và số tự nhiên K (K<=N<=100). 
//Ta gọi một dãy con tăng dần bậc K của dãy số AN là một dãy các số gồm K phần tử trong dãy đó thỏa mãn tính chất tăng dần. 
//Bài toán được đặt ra là in ra màn hình  số các dãy con tăng dần bậc K của dãy số AN.
//Dòng đầu tiên ghi lại hai số N và K tương ứng với số phần tử của dãy số và bậc của dãy con.
//Dòng kế tiếp : N số của dãy số AN, các số trong dãy không lớn hơn 100. 
//Input
//5 3
//2 5 15 10 20
//Output
//7
#include <bits/stdc++.h>
using namespace std;
int a[100], b[100], n, k, cnt=1, cnt1=0;
int dem(int x){
	int cnt=0;
	for(int i=x+1;i<=n;i++){
		if(a[i]>a[x]) ++cnt;
	}
	return cnt;
}
void Try(int i){
	b[i]=1;
	for(int j=i+1;j<=n;j++){
		if(a[j]>a[i]){
			++cnt;
			if(cnt%k==0){
				b[j]=1;
				++cnt1;
			}
			else{
			    Try(j);
			}
			b[j]=0;
			cnt-=1;
		}
	}
	b[i]=0;
}
int main(){
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		b[i]=0;
	}
	for(int i=1;i<=n-k+1;i++){
		if(dem(i)>=k-1) Try(i);
	}
	cout << cnt1;
}