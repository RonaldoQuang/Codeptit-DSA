//Cho dãy số nguyên A[] gồm có N phần tử. 
//Nhiệm vụ của bạn là tìm dãy số B[] có tổng phần tử nhỏ nhất thỏa mãn tính chất A[i] / B[i] = A[i+1] / B[i+1] với mọi chỉ số i (0 ≤ i ≤ N-2).
//Phép chia trong bài toán này là phép chia nguyên (tức là chỉ lấy phần nguyên của kết quả: ví dụ 5/3 = 1).
//Input
//5 
//18 27 16 22 6
//Output
//25
#include <bits/stdc++.h> 
using namespace std;
int main(){ 
    int n; cin >> n;
    int a[n];
    int m=1e9;
    for(int i=0;i<n;i++){
    	cin >> a[i];
    	m=min(m,a[i]);
	}
	int min1=1e9, x;
	for(int i=m;i>=1;i--){
		int sum=0;
		for(int j=0;j<n;j++){
			if(a[j]/i!=a[j]/(i+1)){
				sum+=a[j]/(i+1)+1;
			}
			else{
				sum=0;
				break;
			}
		}
		if(sum!=0) min1=min(min1,sum);
	}
	cout << min1;
}