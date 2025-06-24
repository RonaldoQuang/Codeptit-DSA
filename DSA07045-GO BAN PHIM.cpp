//Trong quá trình gõ một dòng văn bản, chúng ta thường sử dụng phím sang trái, sang phải hoặc xóa lùi (backspace). 
//Cho một dãy ký tự mô tả các thao tác gõ phím, trong đó:
//Ký tự ‘-’ mô tả phím backspace (xóa lùi). Ký tự ở phía trước con trỏ (nếu có) sẽ bị xóa.
//Ký tự ‘<’ mô tả phím di chuyển sang trái. Con trỏ sẽ sang trái 1 ký tự nếu có thể.
//Ký tự ‘>’ mô tả phím di chuyển sang phải. Con trỏ sẽ sang phải 1 ký tự nếu có thể.
//Các ký tự khác là các chữ cái Tiếng Anh (in hoa hoặc in thường). Bàn phím để ở chế độ Insert. 
//Tức là nếu con trỏ không ở cuối dòng thì khi chèn các ký tự sẽ đẩy các ký tự khác sang phải một vị trí.
//Hãy thử tính toán và viết ra kết quả tương ứng.
//Input
//CHO<->NCO<H>>>
//Output
//CONCHO
#include <bits/stdc++.h>
using namespace std;
int main(){
	string s, w=""; cin >> s;
	stack<char> st;
	for(int i=0;i<s.size();i++){
		if(s[i]=='<'){
			if(w!=""){
				st.push(w[w.size()-1]);
				w.pop_back();
			}
		}
		else if(s[i]=='>'){
			if(!st.empty()){
				w+=st.top();
				st.pop();
			}
		}
		else if(s[i]=='-'){
			if(w!="") w.pop_back();
		}
		else w+=s[i];
	}
	while(!st.empty()){
		w+=st.top();
		st.pop();
	}
	cout << w;
}