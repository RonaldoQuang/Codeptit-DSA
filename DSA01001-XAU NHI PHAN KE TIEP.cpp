//Cho xâu nhị phân X[], nhiệm vụ của bạn là hãy đưa ra xâu nhị phân tiếp theo của X[]. 
//Ví dụ X[] =”010101” thì xâu nhị phân tiếp theo của X[] là “010110”.
//Input:
//Dòng đầu tiên đưa vào số lượng test T.
//Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là một xâu nhi phân X.
//T, X[] thỏa mãn ràng buộc: 1≤T≤100; 1≤length(X)≤103.
//Output:
//Đưa ra kết quả mỗi test theo từng dòng.
//Input
//010101
//111111
//Output
//010110
//000000
#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin >> t;
	while(t--){
		string s; cin >> s;
		int i=s.size()-1;
		while(i>=0&&s[i]=='1'){
			s[i]='0';
			i--;
		}
		if(i>=0) s[i]='1';
		cout << s << endl;
	}
}