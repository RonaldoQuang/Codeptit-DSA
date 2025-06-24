//Cho hai dãy số thực A[] và B[] đều có N phần tử, các giá trị là số thực và không quá 100.
//Hãy tính độ dài dài nhất của dãy các vị trí (không cần liên tiếp) thỏa mãn cả hai điều kiện:
//Nếu xét các vị trí đó trên dãy A[] thì dãy con thu được thỏa mãn tính chất tăng dần (giá trị bằng nhau không được tính vào dãy tăng).
//Nếu xét các vị trí đó trên dãy B[] thì dãy con thu được thỏa mãn tính chất giảm dần (giá trị bằng nhau không được tính vào dãy giảm).
//Input
//3
//2
//1.0 1.0
//1.5 0.0
//3
//1.0 1.0
//1.0 1.0
//1.0 1.0
//6
//1.5 9.0
//2.0 2.0
//2.5 6.0
//3.0 5.0
//4.0 2.0
//10.0 5.5
//Output
//2
//1
//4
#include <bits/stdc++.h>
using namespace std;
int main(){ 
    int t; cin >> t;
    while(t--){
    	int n; cin >> n;
        float a[n], b[n], dp[n];
        for(int i=0;i<n;i++){
    	    cin >> a[i] >> b[i];
	    }
	    float max1=1;
	    for(int i=0;i<n;i++) dp[i]=1;
	    for(int i=1;i<n;i++){
		    for(int j=0;j<i;j++){
		    	if(a[j]<a[i]&&b[j]>b[i]) dp[i]=max(dp[i],dp[j]+1);
			}
			max1=max(max1,dp[i]);
	    }
	    cout << max1 << endl;
	}
}