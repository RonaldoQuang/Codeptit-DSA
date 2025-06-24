//Hoàng yêu thích các số may mắn. 
//Ta biết rằng một số là số may mắn nếu biểu diễn thập phân của nó chỉ chứa các chữ số may mắn là 4 và 7. 
//Ví dụ, các số 47, 744, 4 là số may mắn và 5, 17, 467 không phải. 
//Hoàng muốn tìm số may mắn bé nhất có tổng các chữ số bằng n. 
//Hãy giúp anh ấy
//Input
//2
//11
//10
//Output
//47
//-1
#include<bits/stdc++.h>
using namespace std;
int main(){ 
    int t; cin >> t; 
	while(t--){ 
	    int n, x; cin >> n;
	    if(n%7==0){
	    	for(int i=1;i<=n/7;i++){
	    		cout << "7";
			}
		}
		else{
			if(n%7==1){
				x=n/7-1;
				if(x>=0){
					for(int i=1;i<=2;i++) cout << "4";
					for(int i=1;i<=x;i++) cout << "7";
				}
				else{
					if(n%4==0){
						for(int i=1;i<=n/4;i++) cout << "4";
					}
					else cout << "-1";
				}
			}
			else if(n%7==2){
				x=n/7-2;
				if(x>=0){
					for(int i=1;i<=4;i++) cout << "4";
					for(int i=1;i<=x;i++) cout << "7";
				}
				else{
					if(n%4==0){
						for(int i=1;i<=n/4;i++) cout << "4";
					}
					else cout << "-1";
				}
			}
			else if(n%7==3){
				x=n/7-3;
				if(x>=0){
					for(int i=1;i<=6;i++) cout << "4";
					for(int i=1;i<=x;i++) cout << "7";
				}
				else{
					if(n%4==0){
						for(int i=1;i<=n/4;i++) cout << "4";
					}
					else cout << "-1";
				}
			}
			else if(n%7==4){
				cout << "4";
				for(int i=1;i<=n/7;i++) cout << "7";
			}
			else if(n%7==5){
				x=n/7-1;
				if(x>=0){
					for(int i=1;i<=3;i++) cout << "4";
					for(int i=1;i<=x;i++) cout << "7";
				}
				else{
					if(n%4==0){
						for(int i=1;i<=n/4;i++) cout << "4";
					}
					else cout << "-1";
				}
			}
			else{
				x=n/7-2;
				if(x>=0){
					for(int i=1;i<=5;i++) cout << "4";
					for(int i=1;i<=x;i++) cout << "7";
				}
				else{
					if(n%4==0){
						for(int i=1;i<=n/4;i++) cout << "4";
					}
					else cout << "-1";
				}
			}
		}
		cout << endl;
	} 
}