#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;
struct node{
	int seven, thirteen, sum;
	node(){
		seven = thirteen = sum = 0;
	}
	node(int seven, int thirteen, int sum) : seven(seven), thirteen(thirteen), sum(sum) {}
};

node operator +(const node &a, const node &b){
	return node(a.seven + b.seven, a.thirteen + b.thirteen, a.sum + b.sum);
}

int v[N];
node st[4 * N];
int lazy[4 * N][2];
#define inf 1e9 + 7
int n;

void propagate(int id, int l, int r){
	if(lazy[id][0] == -inf && lazy[id][1] == -inf) return;

	if(lazy[id][0] != -inf){
		st[id].sum = st[id].sum - (st[id].seven * 7 - lazy[id][0] * st[id].seven);
		if(lazy[id][0] == 13) st[id].thirteen += st[id].seven;
		st[id].seven = 0;

	}
	if(lazy[id][1] != -inf){
		st[id].sum = st[id].sum - (st[id].thirteen * 13 - lazy[id][1] * st[id].thirteen);
		if(lazy[id][1] == 7) st[id].seven += st[id].thirteen;
		st[id].thirteen = 0;
	}

	if(l != r){
		if(lazy[id * 2][0] == -inf) lazy[id * 2][0] = lazy[id][0];
		if(lazy[id * 2 + 1][0] == -inf) lazy[id * 2 + 1][0] = lazy[id][0];
		if(lazy[id * 2][1] == -inf) lazy[id * 2][1] = lazy[id][1];		
		if(lazy[id * 2 + 1][1] == -inf) lazy[id * 2 + 1][1] = lazy[id][1];		
	}

	lazy[id][0] = lazy[id][1] = -inf;
}

node query(int id, int l, int r, int i, int j){
	propagate(id,l,r);
	if(l > j || r < i) return node(0,0,0);
	if(l >= i && r <= j) return st[id];	
	int mid = (l + r) >> 1;

	node a = query(id * 2, l, mid, i, j);
	node b = query(id * 2 + 1, mid + 1, r, i, j);
	return a + b;
}

void build(int id, int l, int r){
	if(l == r){
		int thirteen, seven; thirteen = seven = 0;
		if(v[l] == 13) thirteen++;
		else if(v[l] == 7) seven++;
		st[id] = node(seven, thirteen, v[l]);
		return;
	}

	int mid = (l + r) >> 1;
	build(id * 2, l, mid);
	build(id * 2 + 1, mid + 1, r);

	st[id] = st[id * 2] + st[id * 2 + 1];
}

void printSons(int id, int l, int r){
	propagate(id,l,r);
	if(l == r){
		cout << st[id].sum << " ";
		return;
	}
	int mid = (l + r) >> 1;
	printSons(id * 2, l, mid);
	printSons(id * 2 + 1, mid + 1, r);
}

void update(int id, int l, int r, int i, int j, int valor){
	propagate(id,l,r);
	if(l > j || r < i) return;
	if(l == i && r == j) {
		if(valor == 7 && st[id].sum != 7) st[id].seven++;
		else if(valor == 13 && st[id].sum != 13) st[id].thirteen++;
		if(st[id].sum == 7 && valor != 7) st[id].seven--;
		else if(st[id].sum == 13 && valor != 13) st[id].thirteen--;
		st[id].sum = valor;
		return;
	}	

	int mid = (l + r) >> 1;
	update(id * 2, l, mid, i, j, valor);
	update(id * 2 + 1, mid + 1, r, i, j, valor);

	st[id] = st[id * 2] + st[id * 2 + 1];
}

void update2(int id, int l, int r, int i, int j, int change, int valor){
	propagate(id,l,r);
	if(l > j || r < i) return;
	if(l >= i && r <= j) {
		if(change == 7 && valor != 7) {
			lazy[id][0] = valor;
			propagate(id,l,r);
		}
		else if(change == 13 && valor != 13) {
			lazy[id][1] = valor;
			propagate(id,l,r);
		}
		return;
	}	

	int mid = (l + r) >> 1;
	update2(id * 2, l, mid, i, j, change,valor);
	update2(id * 2 + 1, mid + 1, r, i, j, change, valor);

	st[id] = st[id * 2] + st[id * 2 + 1];	
}

int main()	
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	while(cin >> n){
		for(int i = 0; i <= 4 * n; i++) {
			lazy[i][0] = lazy[i][1] = -inf;
			st[i] = node(0,0,0);
		}

		for(int i = 0; i < n; i++) cin >> v[i];
		build(1,0,n-1);
		int q;
		cin >> q;
		while(q--){
			int op;
			cin >> op;

			if(op == 1){
				int i,V;
				cin >> i >> V;
				i--;
				update(1,0,n-1,i,i,V);
			}
			else if(op == 2){
				int i, j, z, V;
				cin >> i >> j >> z >> V;
				i--; j--;
				update2(1,0,n-1,i,j,z,V);
			}
			else {
				int i, j;
				cin >> i >> j;
				i--; j--;
				cout << query(1,0,n-1,i,j).sum << endl;
			}
		}
	}
	
	return 0;
}