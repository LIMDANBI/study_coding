#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* leftchild;
    Node* rightchild;
};

void postorder(Node* node) {
	if (node->leftchild != NULL)
		postorder(node->leftchild);
	if (node->rightchild != NULL)
		postorder(node->rightchild);
	cout << node->data << '\n';
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int data; cin >> data;
    Node* root = new Node();
    root->data = data; root->leftchild=NULL; root->rightchild=NULL;

    while (cin>>data) {
        if(data==EOF) break;
        Node* node = new Node();
        node->data = data; node->leftchild=NULL; node->rightchild = NULL;
        
        Node* tmp = root;
        while (1) {
            if(data <= tmp->data){
                if(tmp->leftchild == NULL) {
                    tmp->leftchild = node;
                    break;
                }
                else tmp = tmp->leftchild;
            }
            else{
                if(tmp->rightchild == NULL) {
                    tmp->rightchild = node;
                    break;
                }
                else tmp = tmp->rightchild;
            }
        }
    }
    postorder(root);
}