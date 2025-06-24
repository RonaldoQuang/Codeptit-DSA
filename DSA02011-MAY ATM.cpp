//Một máy ATM hiện có n (n ≤ 30) tờ tiền có giá trị t[1], t[2], …, t[n]. 
//Hãy tìm cách trả ít tờ nhất với số tiền đúng bằng S (các tờ tiền có giá trị bất kỳ và có thể bằng nhau, mỗi tờ tiền chỉ được dùng một lần).
//Input: Dòng đầu tiên ghi số bộ test T (T<10). Mỗi bộ test gồm 2 số nguyên n và S (S ≤ 109). Dòng thứ hai chứa n số nguyên t[1], t[2], …, t[n] (t[i] ≤ 109)
//Output: Với mỗi bộ test ghi ra số tờ tiền ít nhất phải trả.
//Nếu không thể tìm được kết quả, in ra -1.
//Input
//1
//3 5
//1 4 5
//Output
//1
#include <bits/stdc++.h>
using namespace std;
void Try(int a[100], int n, int N, int i, int sum, int &cnt, int &dem){
	if(dem==1) return;
	for(int j=1;j>=0;j--){
		sum+=j*a[i];
		cnt+=j;
		if(sum==N){
			dem=1;
			cout << cnt << endl;
			return;
		}
		if(sum<N&&i<n-1){
			Try(a,n,N,i+1,sum,cnt,dem);
		}
		sum-=j*a[i];
		cnt-=j;
	}
}
int main(){
	int t; cin >> t;
	while(t--){
		int a[100], n, N; cin >> n >> N;
		int sum=0, cnt=0, dem=0;
		for(int i=0;i<n;i++) cin >> a[i];
		sort(a,a+n,greater<>());
		Try(a,n,N,0,sum,cnt,dem);
		if(dem==0) cout << "-1" << endl;
	}
}