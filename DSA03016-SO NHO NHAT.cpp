//Cho hai số nguyên dương S và D, trong đó S là tổng các chữ số và D là số các chữ số của một số. 
//Nhiệm vụ của bạn là tìm số nhỏ nhất thỏa mãn S và D? 
//Ví dụ với S = 9, D = 2 ta có số nhỏ nhất thỏa mãn S và D là 18.
//Input
//2
//9 2
//20 3
//Output
//18
//299
#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin >> t;
	while(t--){
		int m,s; cin >> s >> m;
	    int a=s/9;
	    if(s>9*m||s==0){
		    cout << "-1";
	    }
	    else{
		    if(s%9==0){
		        if(m==a){
			        int t=1;
			        while(t--){
				        for(int i=1;i<=a;i++){
					        cout << "9";
				        }
			        }
		        }
		        else{
			        cout << "1";
			        for(int i=1;i<=m-(a-1)-2;i++){
				        cout << "0";
			        }
			        cout << "8";
			        for(int i=1;i<a;i++){
				        cout << "9";
			        }
		        }
	        }
	        else{
		        if(m>a+1){
			        cout << "1";
			        for(int i=1;i<=m-2-a;i++){
				        cout << "0";
			        }
			        cout << s-a*9-1;
			        for(int i=1;i<=a;i++){
				        cout << "9";
			        }
		        }
		        else{
		    	    cout << s-a*9;
		    	    for(int i=1;i<=a;i++){
		    		    cout << "9";
				    }
			    }
	        }
	    }
	    cout << endl;
	}
}