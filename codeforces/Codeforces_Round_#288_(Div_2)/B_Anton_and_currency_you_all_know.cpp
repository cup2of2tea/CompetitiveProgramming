#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <iterator>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
 
using namespace std;
 
 
int main()
{
    ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    #define cin in
    ifstream in("input.txt");
#endif // ONLINE_JUDGE
 
    string s;
    cin>>s;
    int last = -1;
    for(int c=0;c<s.size()-1;c++)
    {
        if((s[c]-'0')%2==0)
        {
            if(s[c]<s[s.size()-1])
            {
                swap(s[c],s[s.size()-1]);
                cout<<s;
                return 0;
            }
            last = c;
        }
    }
    if(last==-1)
        cout<<-1;
    else{
        swap(s[s.size()-1],s[last]);
        cout<<s;
    }
 
}