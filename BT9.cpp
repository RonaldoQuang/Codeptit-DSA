//Cho một dãy nhị phân có N phần tử. 
//Ban đầu cả dãy có giá trị toàn 0. 
//Mỗi bước với hai giá trị x và y (1 ≤ x ≤ y ≤ N), bạn sẽ thay đổi tất cả các bit từ vị trí x đến vị trí y (nếu đang là 1 thì thành 0 và ngược lại).
//Hãy cho biết sau Q lần thực hiện các truy vấn với 2 cặp số x, y thì trạng thái cuối cùng của dãy nhị phân là gì.
//Input
//3 2
//1 2
//1 3
//Output
//0 0 1
#include <bits/stdc++.h>
using namespace std;
int n, q;
long long dp[100005];
int main(){
	cin >> n >> q;
	while(q--){
		int x, y; cin >> x >> y;
		dp[x]++;
		dp[y+1]--;
	}
	for(int i=1;i<=n;i++) dp[i]+=dp[i-1];
	for(int i=1;i<=n;i++) cout << dp[i]%2 << " ";
}