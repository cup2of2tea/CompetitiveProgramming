#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main()
{
    map<char,int> m,m2;
    string s1,s2;
    cin>>s1>>s2;
    for(int c=0;c<s1.size();c++) m[s1[c]]++;
    for(int c=0;c<s2.size();c++) m2[s2[c]]++;
    int res = 0;
    for(map<char,int>::iterator it = m2.begin();it!=m2.end();it++)
    {
        if(m[it->first]==0)
        {
            cout<<-1;
            return 0;
        }
        res += min(m[it->first],it->second);
    }
    cout<<res;
}