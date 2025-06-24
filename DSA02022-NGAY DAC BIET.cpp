//Hôm nay là ngày 22/02/2022. Một ngày đặc biệt. 
//Chỉ có hai chữ số là 0 và 2. 
//Đồng thời viết xuôi viết ngược tám chữ số ta đều được cùng một kết quả.
//Nhiệm vụ của bạn trong ngày đặc biệt này là hãy liệt kê hết tất cả các ngày hợp lệ chỉ có 2 chữ số 0 và 2.
//Một số chú ý:
//Luôn có đủ 8 chữ số của ngảy tháng năm và hai dấu gạch chéo.
//Ngày và tháng có thể có chữ số 0 ở đầu nhưng với năm thì không được phép. 
//Tức là ta chỉ tính các ngày bắt đầu từ năm 2000 trở về sau.
//Bài toán không có dữ liệu vào. 
//Bạn chỉ cần liệt kê kết quả gồm tất cả các ngày tháng hợp lệ. Coi dãy ký tự ngày tháng là một xâu ký tự. 
//Hãy liệt kê theo đúng thứ tự từ điển tăng dần.
#include <bits/stdc++.h>
using namespace std;
int a[100];
void kq(){
	string s1="",s2="",s3="";
	int cnt=0;
	for(int i=1;i<=2;i++){
		s1+=a[i]+'0';
	}
	if(s1!="00"){
		for(int i=3;i<=4;i++){
			s2+=a[i]+'0';
		}
		if(s2=="02"){
			if(a[5]!=0){
				for(int i=5;i<=8;i++){
					s3+=a[i]+'0';
				}
			}
			else ++cnt;
		}
		else ++cnt;
	}
	else ++cnt;
	if(cnt==0) cout << s1 << "/" << s2 << "/" << s3 << endl;
}
void Try(int i){
	for(int j=0;j<=2;j+=2){
		a[i]=j;
		if(i==8){
			kq();
		}
		else Try(i+1);
	}
}
int main(){
	Try(1);
}