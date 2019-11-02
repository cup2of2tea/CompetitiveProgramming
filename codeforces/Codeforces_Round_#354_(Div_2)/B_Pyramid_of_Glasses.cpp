#include <bits/stdc++.h>
 
using namespace std;
 
void simulate(vector<vector<double> > &pyra) {
	vector<pair<pair<int,int>,double> >dfs(1,make_pair(make_pair(0,0),1));
 
	while(dfs.size()) {
		int x = dfs.back().first.first;
		int y = dfs.back().first.second;
		double remaining = dfs.back().second;
        dfs.pop_back();
		double emptySpace = 1-pyra[x][y];
		double toFill = min(remaining,emptySpace);
		pyra[x][y] += toFill;
		remaining -= toFill;
		if(remaining && x+1 < pyra.size() ) {
			int x2 = x + 1;
			int y2 = y;
			dfs.push_back(make_pair(make_pair(x2,y2),remaining/2.));
			y2++;
			dfs.push_back(make_pair(make_pair(x2,y2),remaining/2.));
		}
	}
 
}
 
 
int main() {
	int n,t;
	cin>>n>>t;
	vector<vector<double> > pyrapyra(n);
	for(int c=0;c<n;c++) {
		pyrapyra[c].resize(c+1);
		for(int c2=0;c2<pyrapyra[c].size();c2++) pyrapyra[c][c2] = 0;
	}
	for(int c=0;c<t;c++) simulate(pyrapyra);
	int res = 0;
	for(int c=0;c<pyrapyra.size();c++) for(int c2=0;c2<pyrapyra[c].size();c2++) if(abs(1-pyrapyra[c][c2]) <= 1e-10) res++;
	cout<<res; 
 
}