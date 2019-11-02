#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
 
int main() {
	int n;
	cin>>n;
	vector<pair<int,int> > v(n);
	for(int c=0;c<n;c++) {
		cin>>v[c].first;
		v[c].second = c+1;
	}
	sort(v.begin(),v.end());
	for(int c=0;c<v.size()/2;c++) {
		cout<<v[c].second<<" "<<v[v.size()-1-c].second<<endl;
	}
}