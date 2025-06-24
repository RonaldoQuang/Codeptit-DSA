//Cho hai mảng đã được sắp xếp A[] và B[] gồm N và N-1 phần tử. 
//Các phần tử của mảng A[] chỉ khác mảng B[] một phần tử duy nhất. 
//Hãy tìm vị trí của phần tử khác nhau giữa A[] và B[].
//Input
//2
//7
//2 4 6 8 9 10 12
//2 4 6 8 10 12
//6
//3 5 7 9 11 13
//3 5 7 11 13
//Output
//5
//4
#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		long long a[n], b[n];
		for(int i=0;i<n;i++){
			cin >> a[i];
		}
		for(int i=0;i<n-1;i++){
			cin >> b[i];
		}
		int x=-1;
		for(int i=0;i<n-1;i++){
			if(a[i]!=b[i]){
				x=i+1;
				break;
			}
		}
		cout << x << endl;
	}
}