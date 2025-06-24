//Cho dãy số A[] có n phần tử là các số nguyên dương. 
//Hãy sắp xếp dãy số theo thuật toán sắp xếp đổi chỗ trực tiếp. Nhưng yêu cầu in ra lần lượt các bước chạy của thuật toán theo thứ tự ngược (bước cuối cùng in ra đầu tiên).
//Input
//1
//6
//5 8 3 9 1 4
//Output
//Buoc 5: 1 3 4 5 8 9
//Buoc 4: 1 3 4 5 9 8
//Buoc 3: 1 3 4 9 8 5
//Buoc 2: 1 3 8 9 5 4
//Buoc 1: 1 8 5 9 3 4
#include <bits/stdc++.h>
using namespace std;
int dem(int a[100], int n){
	int cnt=0;
	for(int i=0;i<n-1;i++){
		if(a[i]>a[i+1]){
			++cnt;
			break;
		}
	}
	if(cnt==0) return 1;
	else return 0;
}
int main() {
    int t; cin >> t;
    while(t--){
    	int n; cin >> n;
    	int a[100], k;
    	vector<int> v;
    	for(int i=0;i<n;i++) cin >> a[i];
    	for(int i=0;i<n-1;i++){
    		for(int j=i+1;j<n;j++){
    			if(a[i]>a[j]){
    				int temp=a[i];
    				a[i]=a[j];
    				a[j]=temp;
				}
			}
			if(dem(a,n)==1){
				k=i+1;
				for(int j=0;j<n;j++){
					v.push_back(a[j]);
				}
				break;
			}
			else{
				for(int j=0;j<n;j++){
					v.push_back(a[j]);
				}
			}
		}
		for(int i=k;i>=1;i--){
			cout << "Buoc " << i << ": ";
			for(int j=(i-1)*n;j<=i*n-1;j++) cout << v[j] << " ";
			cout << endl;
		}
	}
}