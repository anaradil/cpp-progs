#include <vector>
#include <iostream>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>

using namespace std;

struct node {
	int key;
	node *left;
	node *right;
};

class binTree {
	public:
		binTree();

		void insert(int key);
		node *search(int key);
		void destroy_tree();
		void print_preorder();
		void print_postorder();
		void print_postorder_onestack();
		void print_inorder();
		void print_levelorder();
		bool isBalanced();
		int length();

	private:
		void destroy_tree(node *leaf);
		void insert(int key, node *leaf);
		node *search(int key, node *leaf);
		void print_preorder(node *leaf);
		void print_postorder(node *leaf);
		void print_postorder_onestack(node *leaf);
		void print_inorder(node *leaf);
		void print_levelorder(node *leaf);
		bool isBalanced(node *leaf);
		int findHeight(node *leaf);
		int length(node *leaf);
		node *root;
};

binTree::binTree() {
	root = NULL;
}
void binTree::destroy_tree(node *leaf) {
	if(leaf != NULL){
		binTree::destroy_tree(leaf->left);
		binTree::destroy_tree(leaf->right);
		delete leaf;
	}
}

void binTree::insert(int key, node *leaf) {
	if(key < leaf->key) {
		if(leaf->left != NULL)
			binTree::insert(key, leaf->left);
		else {
			leaf->left = new node;
			leaf->left->key = key;
			leaf->left->left = NULL;
			leaf->left->right = NULL;
		}
	} else if(key >= leaf->key) {
		if(leaf->right != NULL)
			binTree::insert(key, leaf->right);
		else {
			leaf->right = new node;
			leaf->right->key = key;
			leaf->right->left = NULL;
			leaf->right->right = NULL;
		}
	}
}

node *binTree::search(int key, node *leaf) {
	if(leaf != NULL) {
		if(key == leaf->key)
			return leaf;
		if(key < leaf->key)
			return binTree::search(key, leaf->left);
		else
			return binTree::search(key, leaf->right);
	} else
		return NULL;
}

void binTree::insert(int key) {
	if(root != NULL)
		binTree::insert(key, root);
	else {
		root = new node;
		root->key = key;
		root->left = NULL;
		root->right = NULL;
	}
}

node *binTree::search(int key) {
	return binTree::search(key,root);
}

void binTree::destroy_tree() {
	binTree::destroy_tree(root);
}

void binTree::print_preorder() {
		binTree::print_preorder(root);
}
	
void binTree::print_preorder(node *leaf) {
	if(leaf != NULL) {
		cout << leaf->key << endl;
	}
	stack<node *> st;
	while(leaf != NULL) {
		if(leaf->right != NULL)
			st.push(root->right);
		if(leaf->left != NULL)
			st.push(root->left);
		if(st.size() == 0)
			break;
		cout << st.top()->key << endl;
		leaf = st.top();
		st.pop();
	}
}

int binTree::length(node *leaf) {

        int count = 1;
        if(leaf->left != NULL)
            count+=binTree::length(leaf->left);
        if(leaf->right != NULL)
            count+=binTree::length(leaf->right);
        return count;
}

int binTree::length() {
	if(root != NULL)
		return binTree::length(root);
	else
		return 0;
}

void binTree::print_postorder() {
	binTree::print_postorder(root);
}

void binTree::print_postorder(node *leaf) {
	stack<node *> st1;
	stack<int> st2;
	if(leaf != NULL)
		st1.push(leaf);
	while(!st1.empty()) {
		node *cur = st1.top();
		st1.pop();
		st2.push(cur->key);
		if(cur->left != NULL)
			st1.push(cur->left);
		if(cur->right != NULL)
			st1.push(cur->right);
	}
	for(int i = 0; i < 6; i++){
		cout << st2.top() << endl;
		st2.pop();
	}
}

void binTree::print_postorder_onestack() {
	if(root != NULL)
		binTree::print_postorder_onestack(root);
}

void binTree::print_postorder_onestack(node *leaf) {
	node *cur = leaf;
	stack<node *> st;
	while(cur != NULL || !st.empty()) {
		if(cur != NULL) {
			st.push(cur);
			cur = cur->left;
		} else {
			node *temp = st.top()->right;
			if(temp == NULL) {
				cout << st.top()->key << endl;
				temp = st.top();
				st.pop();
				while(!st.empty() && temp == st.top()->right) {
					cout << st.top()->key << endl;
					temp = st.top();
					st.pop();
				}
			} else {
				cur = temp;
			}
		}
	}
}

void binTree::print_inorder() {
	if(root != NULL)
		binTree::print_inorder(root);
}

void binTree::print_inorder(node *leaf) {
	stack<node *> st;
	while(!st.empty() || leaf != NULL) {
		if(leaf != NULL) {
			st.push(leaf);
			leaf = leaf->left;
		} else {
			cout << st.top()->key << endl;
			leaf = st.top()->right;
			st.pop();
		}
	}
}

int binTree::findHeight(node *leaf) {
	if(leaf == NULL)
		return -1;
	int lHeight = binTree::findHeight(leaf->left);
	int rHeight = binTree::findHeight(leaf->right);

	return max(lHeight,rHeight)+1;
} 

bool binTree::isBalanced(){
	if(root != NULL)
		binTree::isBalanced(root);
}

bool binTree::isBalanced(node *leaf) {
	if(leaf == NULL)
		return true;
	int l = binTree::findHeight(leaf->left);
	int r = binTree::findHeight(leaf->right);
	if(abs(l-r) <= 1 && binTree::isBalanced(leaf->left) && binTree::isBalanced(leaf->right))
		return true;
	return false;
}

void binTree::print_levelorder() {
	binTree::print_levelorder(root);
}

void binTree::print_levelorder(node *leaf) {

	vector<vector<int>> res;
	if(leaf != NULL) {
		deque<node *> q;
		q.push_back(leaf);
		int iter = 0;
		while(true) {
			vector<int> temp;
			int size = q.size();
			if(size == 0)
				break;
			for(int i = 0; i < size; i++) {
				if(iter % 2 == 0) {
					node *t = q.front();
					q.pop_front();
					temp.push_back(t->key);
					if(t->left != NULL)
						q.push_back(t->left);
					if(t->right != NULL)
						q.push_back(t->right);
				} else {
					node *t = q.back();
					q.pop_back();
					temp.push_back(t->key);
					if(t->right != NULL)
						q.push_front(t->right);
					if(t->left != NULL)
						q.push_front(t->left);
				}
				
			}

			iter++;
			if(!temp.empty())
				res.push_back(temp);
		}

	for(int i = 0; i < res.size(); i++) {
		cout << "[";
		for(int j = 0; j < res[i].size(); j++) {
			cout << res[i][j] << ", ";
		}
		cout << "] " << endl;
	}
	}
}


int main() {
	binTree b;
	b.insert(3);
	b.insert(5);
	b.insert(1);
	b.insert(0);
	b.insert(4);
	b.insert(2);
	b.insert(7);
	b.insert(6);
	b.insert(9);
	b.print_levelorder();
	return 0;
}