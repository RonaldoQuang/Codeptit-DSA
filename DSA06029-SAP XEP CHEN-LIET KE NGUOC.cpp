//Cho dãy số A[] có n phần tử là các số nguyên dương. 
//Hãy sắp xếp dãy số theo thuật toán sắp xếp chèn. 
//Nhưng yêu cầu in ra lần lượt các bước chạy của thuật toán theo thứ tự ngược (bước cuối cùng in ra đầu tiên).
//Input
//6
//5 8 3 9 1 4
//Output
//Buoc 5: 1 3 4 5 8 9
//Buoc 4: 1 3 5 8 9
//Buoc 3: 3 5 8 9
//Buoc 2: 3 5 8
//Buoc 1: 5 8
//Buoc 0: 5
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    int a[100];
    vector<int> v;
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++){
    	sort(a,a+i+1);
    	for(int j=0;j<=i;j++){
    		v.push_back(a[j]);
		}
	}
	int x=v.size();
	for(int i=n-1;i>=0;i--){
		cout << "Buoc " << i << ": ";
		for(int j=x-i-1;j<=x-1;j++){
			cout << v[j] << " ";
		}
		cout << endl;
		x-=i+1;
	}
}