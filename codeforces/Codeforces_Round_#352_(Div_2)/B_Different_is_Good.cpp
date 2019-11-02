#include <bits/stdc++.h>
using namespace std;
 
 
int main() {
    int tmp;
    cin>>tmp;
	string s;
	cin>>s;
	if(s.size() > 26) {
		cout<<-1;
	} else {
		set<char> se;
		for(int c=0;c<s.size();c++) se.insert(s[c]);
		int decalage = s.size() - se.size();
		cout<<decalage;
	}
}