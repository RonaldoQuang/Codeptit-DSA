//Cho N công việc. 
//Mỗi công việc được biểu diễn như một bộ 3 số nguyên dương <JobId, Deadline, Profit>
//Trong đó JobId là mã của việc, Deadline là thời gian kết thúc của việc, Profit là lợi nhuận đem lại nếu hoàn thành việc đó đúng hoặc trước thời gian. 
//Thời gian tối thiểu để hoàn thành mỗi công việc là 1 đơn vị thời gian. 
//Hãy cho biết lợi nhuận lớn nhất có thể thực hiện các việc với giả thiết mỗi việc được thực hiện đơn lẻ.
//Input
//2
//4
//1 4 20
//2 1 10
//3 1 40
//4 1 30
//5
//1 2 100
//2 1 19
//3 2 27
//4 1 25
//5 1 15
//Output
//2 60
//2 127
#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<int,int> a, pair<int,int> b){
	return a.second>b.second;
	if(a.second==b.second) return a.first>b.first;
}
int main(){
	int t; cin >> t;
	while(t--){
		int n ; cin >> n;
		pair<int,int> a[n];
		map<int,int> mp;
		for(int i=0;i<n;i++){
			int x; cin >> x >> a[i].first >> a[i].second;
		}
		sort(a,a+n,cmp);
		int cnt=0, sum=0;
		for(int i=0;i<n;i++){
			for(int j=a[i].first;j>=1;j--){
				if(mp[j]==0){
					++cnt;
					sum+=a[i].second;
					mp[j]=1;
					break;
				}
			}
		}
		cout << cnt << " " << sum << endl;
	}
}