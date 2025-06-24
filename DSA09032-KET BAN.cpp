//Trường học X có N sinh viên, trong đó có M cặp là bạn bè của nhau. 
//Bạn của bạn cũng là bạn, tức là nếu A là bạn của B, B là bạn của C thì A và C cũng là bạn bè của nhau.
//Các bạn hãy xác định xem số lượng sinh viên nhiều nhất trong một nhóm bạn là bao nhiêu?
//Input
//2
//3 2
//1 2
//2 3
//10 12
//1 2
//3 1
//3 4
//5 4
//3 5
//4 6
//5 2
//2 1
//7 1
//1 2
//9 10
//8 9
//Output
//3
//7
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
		int max1=0;
		for(int i=1;i<=n;i++){
			if(chuaxet[i]==1){
				max1=max(max1,BFS(a,chuaxet,i));
			}
		}
		cout << max1 << endl;				
	}	
}