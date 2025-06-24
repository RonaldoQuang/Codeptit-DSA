//Cho dãy số A[] có N phần tử là các số nguyên, chỉ số tính từ 1.
//Với mỗi cặp vị trí L và R, hãy in ra tổng lớn nhất có thể của dãy con nào đó trong đoạn từ vị trí L đến vị trí R. 
//Chú ý: tính cả dãy con rỗng (không có phần tử nào).
//Input
//Dòng đầu ghi 2 số N và Q (không quá 100.000).
//Dòng tiếp theo ghi N số của dãy A[], các số có trị tuyệt đối không quá 100.000.
//Q dòng tiếp theo, mỗi dòng ghi một cặp số L, R (1 ≤ L ≤ R ≤ N).
//Output
//Ghi ra Q dòng, lần lượt là tổng lớn nhất tính được với mỗi cặp (L, R) tương ứng.
//Input
//5 2
//-1 2 -3 4 -5
//2 4
//3 3
//Output
//6
//0
#include <bits/stdc++.h> 
using namespace std; 
int main() { 
	int n, q; cin >> n >> q;
	int a[n+1], dp[n+1];
	for(int i=1;i<=n;i++) cin >> a[i];
	dp[0]=0;
	if(a[1]>0) dp[1]=a[1];
	else dp[1]=0;
	for(int i=2;i<=n;i++){
		dp[i]=dp[i-1];
		if(a[i]>0) dp[i]+=a[i];
	}
	while(q--){
		int l, r; cin >> l >> r;
		if(dp[r]-dp[l-1]>0) cout << dp[r]-dp[l-1] << endl;
		else cout << "0" << endl;
	}
}