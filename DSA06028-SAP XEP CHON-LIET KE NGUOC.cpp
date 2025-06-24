//Cho dãy số A[] có n phần tử là các số nguyên dương. Hãy sắp xếp dãy số theo thuật toán sắp xếp chọn. 
//Nhưng yêu cầu in ra lần lượt các bước chạy của thuật toán theo thứ tự ngược (bước cuối cùng in ra đầu tiên).
//Input
//6
//5 8 3 9 1 4
//Output
//Buoc 5: 1 3 4 5 8 9
//Buoc 4: 1 3 4 5 9 8
//Buoc 3: 1 3 4 9 5 8
//Buoc 2: 1 3 8 9 5 4
//Buoc 1: 1 8 3 9 5 4
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    int a[100];
    vector<int> v;
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n-1;i++){
    	int min=i;
    	for(int j=i+1;j<n;j++){
    		if(a[j]<a[min]) min=j;
		}
		int temp=a[i];
    	a[i]=a[min];
    	a[min]=temp;
		for(int j=0;j<n;j++){
			v.push_back(a[j]);
		}
	}
	for(int i=n-1;i>=1;i--){
		cout << "Buoc " << i << ": ";
		for(int j=(i-1)*n;j<=i*n-1;j++) cout << v[j] << " ";
		cout << endl;
	}
}