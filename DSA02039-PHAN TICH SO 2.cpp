//Cho số nguyên dương N. 
//Nhiệm vụ của bạn là hãy liệt kê tất cả các cách phân tích số tự nhiên N thành tổng các số tự nhiên nhỏ hơn hoặc bằng N. 
//Phép hoán vị của một cách được xem là giống nhau. 
//Ví dụ với N = 5 ta có kết quả là: (5), (4, 1), (3, 2), (3, 1, 1), (2, 2, 1), (2, 1, 1, 1), (1, 1, 1, 1, 1) .
//Input:
//Dòng đầu tiên đưa vào số lượng test T.
//Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là một số tự nhiên N được viết trên một dòng.
//T, n thỏa mãn ràng buộc: 1≤T, N≤10.
//Output:
//Dòng đầu tiên là số lượng cách phân tích thỏa mãn. 
//Dòng tiếp theo liệt kê đáp án theo mẫu ví dụ đã cho.
//Input
//2
//4
//5
//Output
//5
//(4) (3 1) (2 2) (2 1 1) (1 1 1 1)
//7
//(5) (4 1) (3 2) (3 1 1) (2 2 1) (2 1 1 1) (1 1 1 1 1)
#include<bits/stdc++.h>
using namespace std;
void kq(vector<int> v, string &s){
	s+="(";
	for(int i=0;i<v.size();i++){
		if(i<v.size()-1){
			s+=v[i]+'0';
			s+=" ";
		}
		else{
			s+=v[i]+'0';
			s+=")";
		}
	}
	s+=" ";
}
void Try(vector<int> v, string &s, int n, int i, int sum, int &cnt){
	for(int j=i;j>=1;j--){
		if(sum+j==n){
			++cnt;
			v.push_back(j);
			kq(v,s);
		}
		else if(sum+j<n){
			sum+=j;
			v.push_back(j);
			Try(v,s,n,j,sum,cnt);
			sum-=j;
		}
		if(sum+j<=n){
			v.pop_back();
		}
	}
}
int main(){
    int t; cin >> t;
    while(t--){
    	int n, cnt=1; cin >> n;
    	string s="";
    	s+="(";
    	if(n<10) s+=n+'0';
    	else s+=to_string(n);
    	s+=") ";
		for(int i=n-1;i>=1;i--){
			int sum=i;
			vector<int> v;
			v.push_back(i);
			Try(v,s,n,i,sum,cnt);
		}
		cout << cnt << endl;
		cout << s << endl;	
	}
	
}