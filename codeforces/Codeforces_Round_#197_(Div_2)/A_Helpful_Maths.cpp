#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
 
 
using namespace std;
 
int main()
{
#ifndef ONLINE_JUDGE
    #define cin in
    ifstream in("input.txt");
#endif // ONLINE_JUDGE
 
    string s;
    getline(cin,s);
    vector<int> v;
    for(int c=0;c<s.size();c+=2)
    {
        v.push_back(s[c]-'0');
    }
    sort(v.begin(),v.end());
    for(int c=0;c<v.size();c++)
    {
        cout<<v[c]<<(c+1<v.size()?"+":"");
    }
 
}