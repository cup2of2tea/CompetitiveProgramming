#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <ctime>
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
    string act = "";
    int prev = 0;
    long long res = 0;
    for(int c=0;c<s.size();c++)
    {
        act=act+s[c];
        if(act.size()>4)
            act=act.substr(1);
        if(act=="bear")
        {
            int deb = c-3;
            int droite = s.size()-(deb+4)+1;
            int gauche = deb-prev+1;
            res+=droite*gauche;
            prev = deb+1;
        }
    }
    cout<<res;
}