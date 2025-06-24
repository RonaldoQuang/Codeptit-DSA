//Cho mảng A[]  gồm n phần tử. 
//Nhiệm vụ của bạn là tìm phần tử gần nhất phía bên phải có số lần xuất hiện lớn hơn phần tử hiện tại. 
//Nếu không có phần tử nào có số lần xuất hiện lớn hơn phần tử hiện tại hãy đưa ra -1.

//Ví dụ với dãy A[] = {1, 1, 2, 3, 4, 2, 1 }, ta nhận được kết quả ans[] = {-1, -1, 1, 2, 2, 1, -1} 
//Vì số lần xuất hiện mỗi phần tử trong mảng là F = {3, 3, 2, 1, 1, 2, 3} 
//Vì vậy phần tử A[0] = 1 có số lần xuất hiện là 3 và không có phần tử nào xuất hiện nhiều hơn 3 nên ans[0] = -1
//Tương tự như vậy với A[2]=2 tồn tại A[6] =1 có số lần xuất hiện là 3 nên ans[2] = 1.
//Input
//1
//7
//1 1 2 3 4 2 1
//Output
//-1 -1 1 2 2 1 -1
#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		int a[n], b[n];
		stack<int> st;
		map<int,int> mp;
		for(int i=0;i<n;i++){
			cin >> a[i];
			mp[a[i]]++;
		}
		for(int i=0;i<n;i++){
			if(st.empty()) st.push(i);
			else{
				while(!st.empty()&&mp[a[st.top()]]<mp[a[i]]){
					b[st.top()]=a[i];
					st.pop();
				}
				st.push(i);
			}
		}
		while(!st.empty()){
			b[st.top()]=-1;
			st.pop();
		}
		for(int i=0;i<n;i++){
			cout << b[i] << " ";
		}
		cout << endl;
	}
}