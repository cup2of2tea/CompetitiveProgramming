#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;
 
 
int main() {
	int N;
	cin>>N;
	string s;
	cin>>s;
	map<char,int> m;
	set<char> all;
	int act = 0;
 
	for(int c=0;c<s.size();c++) {
		all.insert(s[c]);
	}
 
 
	int mini = 1e9;
 
	int c2 = 0;
 
	for(int c=0;c<s.size();c++) {
		m[s[c]]++;
		if(m[s[c]] == 1) {
			act ++;
		}
		
 
		while(m[s[c2]] > 1) {
			m[s[c2]]--;
			c2 ++;
		}
		if(act >= all.size()) {
			mini = min(mini,c-c2+1);
		}
	}
	cout<<mini<<endl;
}