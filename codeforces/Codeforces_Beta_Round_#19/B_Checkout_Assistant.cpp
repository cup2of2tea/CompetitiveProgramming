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
       int n;
       cin>>n;
       vector<vector<long long int > >  v(n+1);
       for(int c=0;c<v.size();c++) v[c].resize(n+1);
       for(int c=0;c<v.size();c++) for(int c2=0;c2<v.size();c2++) v[c][c2]=n*1000000000ll;
       v[0][0]=0;
       for(int c=0;c<n;c++)
       {
            int time,money;
            cin>>time>>money;
           for(int c2=0;c2<n+1;c2++)
            {
                int attente=min(time+c2+1,n);
                v[c+1][attente]=min(v[c+1][attente],v[c][c2]+money);
                v[c+1][c2]=min(v[c+1][c2],v[c][c2]);
            }
       }
       cout<<v[n][n];
 
    }