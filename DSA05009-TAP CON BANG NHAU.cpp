//Cho tập các số A[] = (a1, a2, .., an). 
//Hãy kiểm tra xem ta có thể chia tập A[] thành hai tập con sao cho tổng các phần tử của hai tập con bằng nhau hay không. 
//Đưa ra YES nếu có thể thực hiện được, ngược lại đưa ra NO.
//Input
//2
//4
//1 5 11 5
//3
//1 3 5
//Output
//YES
//NO
#include <bits/stdc++.h>
using namespace std;
int main() {
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		int a[n+1];
		int sum=0;
		for(int i=1;i<=n;i++){
			cin >> a[i];
			sum+=a[i];
		}
		if(sum%2==1) cout << "NO" << endl;
		else{
			int f[sum+1];
			memset(f,0,sizeof(f));
		    f[0]=1;
			for(int i=1;i<=n;i++){
				for(int j=sum;j>=1;j--){
					if(j>=a[i]&&f[j-a[i]]==1){
						f[j]=1;
					}
				}
			}
			if(f[sum/2]==1) cout << "YES" << endl;
			else cout << "NO" << endl;
		}
	}		
}