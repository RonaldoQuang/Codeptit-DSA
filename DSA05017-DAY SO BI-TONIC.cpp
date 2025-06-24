//Một dãy số được gọi là Bi-tonic nếu nó được chia thành hai dãy đầu tăng dần và dãy tiếp theo giảm dần. 
//Nhiệm vụ của bạn là tìm tổng lớn nhất dãy con Bi-tonic của dãy số A[]. 
//Ví dụ với dãy A[] = {1, 15, 51, 45, 33, 100, 12, 18, 9} ta có kết quả là 194 tương ứng với dãy Bi-tonic {1, 15, 51, 100, 18, 9}.
//Input
//2
//6
//80 60 30 40 20 10
//9
//1 15 51 45 33 100 12 18 9
//Output
//210
//194
#include <bits/stdc++.h> 
using namespace std; 
int main(){ 
    int t; cin >> t; 
    while(t--){ 
        int n; cin >> n; 
        int a[n+1], b[n+1];
        for(int i=1;i<=n;i++){
        	cin >> a[i];
        	b[n+1-i]=a[i];
		}
        int dp1[n+1], dp2[n+1], max1=-1e9;;
        dp1[1]=a[1], dp2[1]=b[1];
        for(int i=2;i<=n;i++){
        	dp1[i]=a[i];
        	for(int j=1;j<i;j++){
        		if(a[j]<a[i]) dp1[i]=max(dp1[i],dp1[j]+a[i]);
			}
		}
		for(int i=2;i<=n;i++){
        	dp2[i]=b[i];
        	for(int j=1;j<i;j++){
        		if(b[j]<b[i]) dp2[i]=max(dp2[i],dp2[j]+b[i]);
			}
		}
		for(int i=1;i<=n;i++){
			max1=max(max1,dp1[i]+dp2[n+1-i]-a[i]);
		}
		cout << max1 << endl;
	} 	 
}