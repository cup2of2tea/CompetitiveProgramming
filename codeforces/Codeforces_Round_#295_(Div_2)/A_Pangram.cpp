#include <iostream>
#include <vector>
using namespace std;
 
int main()
{
    int trash;
    cin>>trash;
    string s;
    cin>>s;
    vector<int> v(26,0);
    for(int c=0;c<s.size();c++){
        if(s[c]>='A'&&s[c]<='Z') {
            v[s[c]-'A'] ++;
        } else {
            v[s[c]-'a'] ++;
        }
    }
    for(int c=0;c<26;c++) if(v[c]==0) {cout<<"NO";return 0;}
    cout<<"YES";
}