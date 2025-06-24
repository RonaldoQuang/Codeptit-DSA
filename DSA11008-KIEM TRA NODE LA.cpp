//Cho cây nhị phân, nhiệm vụ của bạn là kiểm tra xem tất cả các node lá của cây có cùng một mức hay không? 
//Ví dụ với cây dưới đây sẽ cho ta kết quả là Yes.
//Input
//2
//2
//1 2 R 1 3 L
//4
//10 20 L 10 30 R 20 40 L 20 60 R
//Output
//1
//0
#include <bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	Node *left, *right;
	Node(int x){
		this->data=x;
		this->left=NULL;
		this->right=NULL;
	}
};
typedef struct Node* node;
void makeNode(node a, int x, int y, char z){
    if(z=='L'){
    	a->left=new Node(y);
	}	
	else a->right=new Node(y);
}
void Insert(node &a, int x, int y, char z){
	if(a==NULL) return;
	if(a->data==x) makeNode(a,x,y,z);
	else{
		Insert(a->left,x,y,z);
		Insert(a->right,x,y,z);
	}
}
int dem(node a){
	if(a==NULL) return 0;
	if(a->left==NULL&&a->right==NULL) return 1;
	else return dem(a->left)+dem(a->right);
}
int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		node a=NULL;
		while(n--){
			int x, y; char z;
			cin >> x >> y >> z;
			if(a==NULL){
				a=new Node(x);
			}
			Insert(a,x,y,z);
		}
		if(a==NULL) cout << 0 << endl;
		else{
			if(dem(a->left)==dem(a->right)) cout << 1 << endl;
			else cout << 0 << endl;
		}
	}
}