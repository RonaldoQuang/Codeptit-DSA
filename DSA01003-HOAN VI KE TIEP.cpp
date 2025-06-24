//Cho số tự nhiên N và một hoán vị X[] của 1, 2, .., N. 
//Nhiệm vụ của bạn là đưa ra hoán vị tiếp theo của X[]. Ví dụ N=5, X[] = {1, 2, 3, 4, 5} thì hoán vị tiếp theo của X[] là {1, 2, 3, 5, 4}.
//Input:
//Dòng đầu tiên đưa vào số lượng test T.
//Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai dòng: dòng thứ nhất là số N; dòng tiếp theo đưa vào hoán vị X[] của 1, 2, .., N.
//T, N, X[] thỏa mãn ràng buộc: 1≤T≤100; 1≤ N≤103.
//Output:
//Đưa ra kết quả mỗi test theo từng dòng.
#include <bits/stdc++.h>
using namespace std;
int main(){
    int t; cin >> t;
    while(t--){
    	int n; cin >> n;
    	int a[n+1];
    	for(int i=1;i<=n;i++){
    		cin >> a[i];
		}
		int i=n-1;
		while(i>=1){
			if(a[i]<a[i+1]){
				auto it=lower_bound(a+i+1,a+n+1,a[i])-a;
				int temp=a[i];
				a[i]=a[it];
				a[it]=temp;
				sort(a+i+1,a+n+1);
				break;
			}
			else{
				i--;
			}
		}
		if(i>=1){
			for(int j=1;j<=n;j++){
				cout << a[j] << " ";
			}
		}
		else{
			for(int j=1;j<=n;j++){
				cout << j << " ";
			}
		}
		cout << endl;
	}
}