//Cho dãy số A[] có n phần tử là các số nguyên dương. 
//Hãy sắp xếp dãy số theo thuật toán sắp xếp nổi bọt. 
//Nhưng yêu cầu in ra lần lượt các bước chạy của thuật toán theo thứ tự ngược (bước cuối cùng in ra đầu tiên).
//Input
//1
//6
//4 1 3 9 8 5
//Output
//Buoc 2: 1 3 4 5 8 9
//Buoc 1: 1 3 4 8 5 9
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
int main(){
    int t; cin >> t;
    while(t--){
    	int n; cin >> n;
        int a[100];
        vector<int> v;
        for(int i=0;i<n;i++) cin >> a[i];
        int x=dem(a,n), cnt=1;
        while(x==0){
    	    for(int i=0;i<n-1;i++){
    		    if(a[i]>a[i+1]) swap(a[i],a[i+1]);
		    }
		    for(int i=0;i<n;i++) v.push_back(a[i]);
		    ++cnt;
		    x=dem(a,n);
	    }
	    for(int i=cnt-1;i>=1;i--){
	    	cout << "Buoc " << i << ": ";
			for(int j=(i-1)*n;j<=i*n-1;j++) cout << v[j] << " ";
			cout << endl;
		}
	}
}