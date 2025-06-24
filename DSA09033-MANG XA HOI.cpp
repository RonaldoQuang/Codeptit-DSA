//Tý đang xây dựng một mạng xã hội và mời các bạn của mình dùng thử. 
//Bạn của bạn cũng là bạn. 
//Vì vậy, Tý muốn mạng xã hội của mình là hoàn hảo, tức với mọi bộ ba X, Y, Z, nếu X kết bạn với Y, Y kết bạn với Z thì X và Z cũng phải là bạn bè của nhau trên mạng xã hội.
//Các bạn hãy xác định xem mạng xã hội hiện tại của Tý có là hoàn hảo hay không? 
//Nếu có hãy in ra “YES”, “NO” trong trường hợp ngược lại.
//Input
//3
//4 3
//1 3
//3 4
//1 4
//4 4
//3 1
//2 3
//3 4
//1 2
//10 4
//4 3
//5 10
//8 9
//1 2
//Output
//NO
//YES
//NO
#include <bits/stdc++.h>
using namespace std;
int BFS(vector<int> a[], int chuaxet[], int i){
	queue<int> q;
	q.push(i);
	chuaxet[i]=0;
	vector<int> v;
	v.push_back(i);
	while(!q.empty()){
		int s=q.front();
		q.pop();
		for(int i=0;i<a[s].size();i++){
			if(chuaxet[a[s][i]]){
				chuaxet[a[s][i]]=0;
				q.push(s);
				q.push(a[s][i]);
				v.push_back(a[s][i]);
			}
		}
	}
	return v.size();
}
int main(){
    int t; cin >> t;
    while(t--){
    	int n, k; cin >> n >> k;
    	int b[k+1], c[k+1], chuaxet[n+1], cnt=0;   	
    	for(int i=1;i<=k;i++){
    		cin >> b[i] >> c[i];
		}
		vector<int> a[n+10];
		for(int i=1;i<=k;i++){
			a[b[i]].push_back(c[i]);
			a[c[i]].push_back(b[i]);
		}
		for(int i=1;i<=n;i++){
			sort(a[i].begin(),a[i].end());
			chuaxet[i]=1;
		}
		if(BFS(a,chuaxet,1)==n) cout << "YES";
		else cout << "NO";
		cout << endl;				
	}	
}