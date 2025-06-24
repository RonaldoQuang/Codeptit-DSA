//Cho cây nhị phân, nhiệm vụ của bạn là kiểm tra xem cây nhị phân có phải là một cây đủ hay không (full binary tree)? 
//Một cây nhị phân được gọi là cây đủ nếu tất cả các node trung gian của nó đều có hai node con.
//Input
//2
//4
//1 2 L 1 3 R 2 4 L 2 5 R
//3
//1 2 L 1 3 R 2 4 L
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
void check(node a, int &ok){
	if((a->left==NULL&&a->right!=NULL)||(a->left!=NULL&&a->right==NULL)){
		ok=0;
		return;
	}
	else if(a->left!=NULL&&a->right!=NULL){
		check(a->left,ok);
		check(a->right,ok);
	}
}
int main(){
	int t; cin >> t;
	while(t--){
		int n, ok=1; cin >> n;
		node a=NULL;
		while(n--){
			int x, y; char z;
			cin >> x >> y >> z;
			if(a==NULL){
				a=new Node(x);
			}
			Insert(a,x,y,z);
		}
		check(a,ok);
		if(a==NULL) cout << "0" << endl;
		else{
			if(ok==1) cout << "1" << endl;
			else cout << "0" << endl;
		}
	}
}