//Giả sử bạn cần viết N ký tự giống nhau lên màn hình. 
//Bạn chỉ được phép thực hiện ba thao tác dưới đây với chi phí thời gian khác nhau:
//Thao tác insert: chèn một ký tự với thời gian là X.
//Thao tác delete: loại bỏ ký tự cuối cùng với thời gian là Y.
//Thao tác copying: copy và paste tất cả các ký tự đã viết để số ký tự được nhân đôi với thời gian là Z.
//Hãy tìm thời gian ít nhất để có thể đưa ra màn hình N ký tự giống nhau. 
//Ví dụ với N = 9, X =1, Y = 2, Z =1 ta có kết quả là 5 bằng cách thực hiện: insert, insert, copying, copying, insert.
//Input
//2
//9
//1 2 1
//10
//2 5 4
//Output
//5
//14
#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin >> t;
	while(t--){
		int n, x, y, z; cin >> n >> x >> y >> z;
		int dp[n+1];
		dp[0]=0, dp[1]=x;
		for(int i=2;i<=n;i++){
			if(i%2==0){
				dp[i]=min(dp[i-1]+x,dp[i/2]+z);
			}
			else dp[i]=min({dp[i-1]+x,dp[(i-1)/2]+z+x,dp[(i+1)/2]+z+y});
		}
		cout << dp[n] << endl;
	}
}