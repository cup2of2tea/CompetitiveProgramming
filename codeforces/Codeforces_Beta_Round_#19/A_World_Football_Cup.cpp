#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <map>
#include <cstdio>
 
 
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
 
int pgcd (int a,int b)
{
    if(a==0||b==0)
        return 0;
    if(a>b)
        swap(a,b);
    if(a==b||a==1)
        return a;
    return pgcd(a,b-a);
}
 
 
struct truc
{
    int nb_points;
    int goalaverage;
    int buts;
    string team;
};
 
bool tri(const truc &t1,const truc &t2)
{
    if(t1.nb_points!=t2.nb_points)
        return t1.nb_points>t2.nb_points;
    else if(t1.goalaverage!=t2.goalaverage)
        return t1.goalaverage>t2.goalaverage;
    return t1.buts>t2.buts;
}
 
int main()
{
 
    #ifdef LOCAL
    ifstream in("input.txt");
    #endif
    int nb_teams;
    cin>>nb_teams;
    vector<string> v(nb_teams);
    vector<truc> resultats(nb_teams);
    for(int c=0;c<v.size();c++) cin>>resultats[c].team;
    for(int c=0;c<v.size();c++) resultats[c].nb_points=resultats[c].goalaverage=resultats[c].buts=0;
    string s2;
    for(int c=0;c<nb_teams*(nb_teams-1)/2;c++)
    {
        string s;
        cin>>s;
        string s2;
        cin>>s2;
        int c2,c3;
        for(c2=0;s[c2]!='-';c2++);
        string team_1=s.substr(0,c2);
        string team_2=s.substr(c2+1);
        for(c2=0;s2[c2]!=':';c2++);
        int score_1;
        int score_2;
        stringstream ss;
        ss.clear();
        ss<<s2.substr(0,c2);
        ss>>score_1;
        ss.clear();
        ss<<s2.substr(c2+1);
        ss>>score_2;
        for(c2=0;resultats[c2].team!=team_1;c2++);
        for(c3=0;resultats[c3].team!=team_2;c3++);
        if(score_1>score_2)
            resultats[c2].nb_points+=3;
        else if(score_1<score_2)
            resultats[c3].nb_points+=3;
        else
        {
            resultats[c2].nb_points++;
            resultats[c3].nb_points++;
        }
        resultats[c2].goalaverage+=score_1-score_2;
        resultats[c3].goalaverage+=score_2-score_1;
        resultats[c2].buts+=score_1;
        resultats[c3].buts+=score_2;
    }
    sort(resultats.begin(),resultats.end(),tri);
    vector<string> lol;
    for(int c=0;c<nb_teams/2;c++)
       lol.push_back(resultats[c].team);
    sort(lol.begin(),lol.end());
    for(int c=0;c<lol.size();c++) cout<<lol[c]<<endl;
}