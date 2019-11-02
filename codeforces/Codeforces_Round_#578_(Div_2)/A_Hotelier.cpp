#include <iostream>
#include <map>
#include <vector>
#include <fstream>
 
using namespace std;
 
int main() {
    int N;
    cin>>N;
    string s;
    cin>>s;
    vector<int> v(10,0);
    for(int c=0;c<s.size();c++) {
        int c2;
        if(s[c] == 'L') {
 
            for(c2=0;c2<10&&v[c2]==1;c2++);
            v[c2] = 1;
        } else if(s[c] == 'R') {
            for(c2=9;c2>=0&&v[c2]==1;c2--);
            v[c2] = 1;
        } else {
            v[s[c]-'0']=0;
        }
    }
    for(int c=0;c<10;c++) cout<<v[c];
}