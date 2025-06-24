//Cho mảng A[] gồm n phần tử. 
//Nhiệm vụ của bạn là đưa ra mảng đã được sắp xếp bao gồm các chữ số của mỗi phần tử trong A[]. 
//Ví dụ A[] = {110, 111, 112, 113, 114 }ta có kết quả là {0, 1, 2, 3, 4}.
//Input
//2
//3
//131 11 48
//4
//111 222 333 446
//Output
//1 3 4 8
//1 2 3 4 6
#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		string a[n];
		int b[10];
		memset(b,0,sizeof(b));
		for(int i=0;i<n;i++){
			cin >> a[i];
			for(char x:a[i]) b[x-'0']=1;
		}
		for(int i=0;i<10;i++){
			if(b[i]==1) cout << i << " ";
		}
		cout << endl;
	}
}