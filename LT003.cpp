//Lớp học Cấu trúc dữ liệu & giải thuật có N sinh viên, trong đó có một số nhóm sinh viên chơi thân với nhau. 
//Nếu X và Y là bạn, Y và Z là bạn, theo tính chất bắc cầu, X và Z cũng là bạn.
//Để tránh việc trao đổi bài, các thầy cô đã sắp xếp phòng thi cho các bạn sinh viên sao cho không có bất kì 2 sinh viên nào là bạn của nhau ở cùng một phòng. 
//Các bạn hãy thử tính xem các thầy cô cần sử dụng ít nhất bao nhiêu phòng thi?
//Input: 
//Dòng đầu tiên chứa hai số nguyên N và M (N, M ≤ 200000).
//M dòng tiếp theo, mỗi dòng gồm 2 số nguyên A[i] và B[i], cho biết A[i] và B[i] là bạn của nhau (A[i] khác B[i]).
//Output: 
//In ra một số nguyên duy nhất là số phòng thi tìm được.
//Input
//5 3
//1 2
//3 4
//5 1
//Output
//3
#include <bits/stdc++.h>
using namespace std;
int n, m, MAX=-1e9;
int vs[200001];
vector<int> a[200001];
void dfs(int i, int &cnt){
	vs[i]=1;
	for(int j=0;j<a[i].size();j++){
		if(!vs[a[i][j]]){
			++cnt;
			dfs(a[i][j],cnt);
		}
	}
}
int main(){	
    cin >> n >> m;
    while(m--){
    	int x, y; cin >> x >> y;
    	a[x].push_back(y);
    	a[y].push_back(x);
	}
	memset(vs,0,sizeof(vs));
	for(int i=1;i<=n;i++){
		int cnt=1;
		if(!vs[i]){
			dfs(i,cnt);
			MAX=max(MAX,cnt);
		}
	}
	cout << MAX;
}