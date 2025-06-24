//Xâu ký tự str được gọi là xâu AB nếu mỗi ký tự trong xâu hoặc là ký tự ‘A’ hoặc là ký tự ‘B’. 
//Ví dụ xâu str=”ABBABB” là xâu AB độ dài 6. 
//Nhiệm vụ của bạn là hãy liệt kê tất cả các xâu AB có độ dài n.
//Input:
//Dòng đầu tiên đưa vào số lượng test T.
//Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là một số tự nhiên n.
//T, n thỏa mãn ràng buộc: 1≤T≤10; 1≤n≤10.
//Output:
//Đưa ra kết quả mỗi test theo từng dòng. 
//Mỗi xâu cách nhau 1 khoảng trống.
//Input
//2
//2
//3
//Output
//AA AB BA BB
//AAA AAB ABA ABB BAA BAB BBA BBB
#include <bits/stdc++.h>
using namespace std;
void kt(int a[100], int n){
	for(int i=0;i<n;i++){
		a[i]=0;
	}
}
int sinh(int a[100], int n){
	int i=n-1;
	while(i>=0&&a[i]==1){
		a[i]=0;
		--i;
	}
	if(i==-1) return 0;
	else{
		a[i]=1;
		return 1;
	}
}
int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		int a[100];
		int x=1;
		kt(a,n);
		while(x){
			for(int i=0;i<n;i++){
				if(a[i]==0) cout << "A";
				else cout << "B";
			}
			cout << " ";
			if(sinh(a,n)) x=1;
			else x=0;
		}
		cout << endl;
	}
}