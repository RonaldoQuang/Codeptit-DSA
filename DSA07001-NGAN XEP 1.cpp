//Cho một ngăn xếp các số nguyên. 
//Các thao tác gồm 3 lệnh: push, pop và show. 
//Trong đó thao tác push kèm theo một giá trị cần thêm (không quá 1000). 
//Hãy viết chương trình ghi ra kết quả của các lệnh show.
//Nếu trong stack không còn gì thì in ra dòng “empty”
//Input
//push 3
//push 5
//show
//push 7
//show
//pop
//pop
//show
//Output
//3 5
//3 5 7
//3
#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    stack<int> st;
    vector<int> v;
    while(cin >> s){
    	if(s=="push"){
    		int x; cin >> x;
    		st.push(x);
    		v.push_back(x);
		}
		else if(s=="show"){
			if(st.empty()) cout << "empty" << endl;
			else{
				for(auto x:v){
					cout << x << " ";
				}
				cout << endl;
			}
		}
		else if(s=="pop"){
			st.pop();
			v.pop_back();
		}
	}
}