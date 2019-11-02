#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <map>
#include <cstdio>
#include <set>
#include <ctime>
#include <queue>
#include <climits>
#include <iomanip>
#include <iterator>
#include <stack>
#define LOCAL
#ifdef ONLINE_JUDGE
#undef LOCAL
#endif
 
#ifdef LOCAL
#define cin in
#endif
#define FOREACH(i, n) for (typeof(n.begin()) i = n.begin(); i != n.end(); ++i)
#define MEMSET(p, c) memset(p, c, sizeof(p))
 
 
using namespace std;
 
 
 
int main()
{
#ifdef LOCAL
    ifstream in("input.txt");
#endif
    int n;
    cin>>n;
    vector<int> v(n);
    stack<int> maxi_s;
    stack<int> mini_s;
    int maxi_droite=-1000000;
    int mini_droite=1000000;
    for(int c=0;c<n;c++)
    {
        cin>>v[c];
    }
    for(int c=n-1;c>=0;c--)
    {
        maxi_droite=max(maxi_droite,v[c]);
        mini_droite=min(mini_droite,v[c]);
        maxi_s.push(maxi_droite);
        mini_s.push(mini_droite);
    }
    int maxi_gauche=-1000000,mini_gauche=10000000;
    maxi_s.pop();
    mini_s.pop();
    for(int c=1;c<n-1;c++)
    {
        maxi_gauche=max(maxi_gauche,v[c-1]);
        mini_gauche=min(mini_gauche,v[c-1]);
        maxi_s.pop();
        mini_s.pop();
        maxi_droite=maxi_s.top();
        mini_droite=mini_s.top();
        if(maxi_gauche>v[c]&&maxi_droite>v[c])
        {
            int c2;
            for(c2=0;v[c2]!=maxi_gauche;c2++);
            cout<<"3\n"<<c2+1<<" "<<c+1<<" ";
            for(c2=v.size()-1;v[c2]!=maxi_droite;c2--);
            cout<<c2+1;
            return 0;
        }
        if(mini_droite<v[c]&&mini_gauche<v[c])
        {
            int c2;
            for(c2=0;v[c2]!=mini_gauche;c2++);
            cout<<"3\n"<<c2+1<<" "<<c+1<<" ";
            for(c2=v.size()-1;v[c2]!=mini_droite;c2--);
            cout<<c2+1;
            return 0;
        }
    }
    cout<<0;
}