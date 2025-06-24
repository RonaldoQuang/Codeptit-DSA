//Cho hai số N, K và một tập con K phần tử X[] =(X1, X2,.., XK) của 1, 2, .., N. 
//Nhiệm vụ của bạn là hãy đưa ra tập con K phần tử trước đó của X[]. 
//Ví dụ N=5, K=3, X[] ={2, 3, 5} thì tập con trước đó của X[] là {2, 3, 4}. Chú ý nếu tập con trong input là đầu tiên thì trước đó là tập con cuối cùng.
//Input:
//Dòng đầu tiên đưa vào số lượng test T.
//Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai dòng: dòng thứ nhất là hai số N và K; dòng tiếp theo đưa vào K phần tử của X[] là một tập con K phần tử của 1, 2, .., N.
//T, K, N, X[] thỏa mãn ràng buộc: 1≤T≤100; 1≤K≤N≤103.
//Output:
//Đưa ra kết quả mỗi test theo từng dòng.
//Input
//2
//5 3
//2 3 5
//5 3
//1 2 3
//Output
//2 3 4
//3 4 5
#include<bits/stdc++.h>
using namespace std;
int main(){ 
    int t; cin >> t; 
	while(t--){ 
	    int n, k; cin >> n >> k; 
		int a[k+1]; 
		a[0]=-7;
		for(int i=1;i<=k;i++) cin >> a[i];
		int x;
		for(int i=k;i>=1;i--){
			if(a[i-1]+1!=a[i]){
				x=i;
				break;
			}
		}
		if(x==1&&a[x]==1){
			for(int i=1;i<=k;i++){
				cout << n-k+i << " ";
			}
			cout << endl;
		}
		else{
			a[x]-=1;
			for(int i=1;i<=x;i++) cout << a[i] << " ";
			for(int i=x+1;i<=k;i++) cout << n-k+i << " ";
			cout << endl;
		}
	} 
}