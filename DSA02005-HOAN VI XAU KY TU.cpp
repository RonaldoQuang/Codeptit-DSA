//Cho xâu ký tự S bao gồm các ký tự in hoa khác nhau. 
//Hãy đưa ra tất cả các hoán vị của xâu ký tự S. 
//Ví dụ S=”ABC” ta có kết quả {ABC ACB BAC BCA CAB CBA}.
//Input:
//Dòng đầu tiên đưa vào số lượng bộ test T.
//Những dòng tiếp theo đưa vào các bộ test. Mỗi bộ test là một xâu ký tự S được viết trên 1 dòng.
//T, S thỏa mãn ràng buộc: 1≤T≤10; 1≤length(S) ≤10;
//Output:
//Đưa ra kết quả mỗi test theo từng dòng.
//Input
//2
//AB
//ABC
//Output
//AB BA
//ABC ACB BAC BCA CAB CBA 
#include <bits/stdc++.h>
using namespace std;
void kq(int a[100], int n, string s){
	for(int i=1;i<=n;i++){
		cout << s[a[i]-1];
	}
	cout << " ";
}
void Try(int a[100], int b[100], int i, int n, string s){
	for(int j=1;j<=n;j++){
		if(b[j]==1){
			a[i]=j;
			b[j]=0;
			if(i==n){
				kq(a,n,s);
			}
			else Try(a,b,i+1,n,s);
			b[j]=1;
		}
	}
}
int main(){
	int t; cin >> t;
	while(t--){
		string s; cin >> s;
		int a[100], b[100];
		int n=s.size();
	    for(int i=1;i<=n;i++){
		    b[i]=1;
	    }
	    Try(a,b,1,n,s);
	    cout << endl;
	}
}