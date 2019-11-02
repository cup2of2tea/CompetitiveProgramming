#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <map>
#include <cstdio>
#include <set>
#include <stack>
#include <ctime>
#include <climits>
#include <iterator>
#include <iomanip>
#define LOCAL
#ifdef ONLINE_JUDGE
#define COUT(s)
#undef LOCAL
#endif
#ifdef LOCAL
#define cin in
#define COUT(s) cout<<"-----"<<s<<endl;
#endif
 
#define FOREACH(i, n) for (typeof(n.begin()) i = n.begin(); i != n.end(); ++i)
#define MEMSET(p, c) memset(p, c, sizeof(p))
using namespace std;
 
unsigned int split(const std::string &txt, std::vector<std::string> &strs, char ch)
{
    unsigned int pos = txt.find( ch );
    unsigned int initialPos = 0;
    strs.clear();
 
    // Decompose statement
    while( pos != std::string::npos ) {
        strs.push_back( txt.substr( initialPos, pos - initialPos + 1 ) );
        initialPos = pos + 1;
 
        pos = txt.find( ch, initialPos );
    }
 
    // Add the last one
    strs.push_back( txt.substr( initialPos, std::min( pos, txt.size() ) - initialPos + 1 ) );
 
    return strs.size();
}
 
 
int main()
{
    #ifdef LOCAL
        ifstream in("input.txt");
        ofstream out("output.txt");
    #endif
    int n;
    cin>>n;
    for(int c=0;c<n;c++)
    {
        string s;
        cin>>s;
        vector<string> v;
        split(s,v,':');
        for(int c2=0;c2<v.size();c2++)
            while(v[c2][v[c2].size()-1]==':')
                v[c2]=v[c2].substr(0,v[c2].size()-1);
        for(int c2=0;c2<v.size();c2++)
            if(v[c2].size()==0)
            {
                v.erase(v.begin()+c2);
                c2--;
            }
        for(int c2=0;c2<v.size();c2++)
            while(v[c2].size()>0&&v[c2].size()<4)
                v[c2]='0'+v[c2];
        int nb_prec=0;
        for(int c2=0;c2<s.size();c2++)
            if(s[c2]==':')
            {
                if(c2+1<s.size()&&s[c2+1]==':')
                {
                    break;
                }
            }
            else if(c2==0||s[c2-1]==':')
                nb_prec++;
        for(int c2=0;c2<nb_prec;c2++)
            cout<<v[c2]<<(c2+1<8?":":"");
        for(int c2=0;c2<8-static_cast<int>(v.size());c2++)
            cout<<"0000"<<(c2+nb_prec+1<8?":":"");
        for(int c2=nb_prec;c2<v.size();c2++)
            cout<<v[c2]<<(c2+1<v.size()?":":"");
        cout<<endl;
    }
}