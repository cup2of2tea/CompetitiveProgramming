#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <map>
 
#ifdef LOCAL
#define cin in
#endif
 
#define FOREACH(i, n) for (typeof(n.begin()) i = n.begin(); i != n.end(); ++i)
#define MEMSET(p, c) memset(p, c, sizeof(p))
 
using namespace std;
 
template < class T,class T2 >
T2 fac(T n)
{
    return n<2?1:fac<T,T2>(n-1)*n;
}
 
template <class T>
T nb_combinaisons(T k,T n)
{
    if(n<k)
        return nb_combinaisons<T>(n,k);
    return fac<T,long long int>(n)/(fac<T,long long int>(n-k)*fac<T,long long int>(k));
}
 
string itoa_2(long long int n)
{
    string s;
    stringstream ss;
    ss<<n;
    ss>>s;
    while(s.size()!=9)
        s='0'+s;
    return s;
}
 
 
int main()
{
    #ifdef LOCAL
        ifstream in("input.txt");
    #endif
    string s;
    cin>>s;
    string resultat="";
    for(int c=0;c<s.size();c++)
    {
        if(s[c]>='A'&&s[c]<='Z')
            s[c]=s[c]-'A'+'a';
        if(s[c]=='a'||s[c]=='e'||s[c]=='i'||s[c]=='o'||s[c]=='u'||s[c]=='y')
            continue;
        resultat=resultat+".";
        resultat=resultat+((char)s[c]);
    }
    cout<<resultat;
}
 
 
 