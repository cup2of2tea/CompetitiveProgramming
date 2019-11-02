    #include <iostream>
    #include <vector>
    #include <algorithm>
    #include <fstream>
    #include <sstream>
    #include <cmath>
    #include <algorithm>
    #include <map>
    #define cin in
    #define cout out
 
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
 
int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");
    int n,m;
    cin>>n>>m;
    vector<int> A_B_C(3);
    vector<int> total_horizontal(n);
    vector<int> total_vertical(m);
    for(int c=0;c<n;c++) total_horizontal[c]=0;
    for(int c=0;c<m;c++) total_vertical[c]=0;
    for(int c=0;c<n;c++) for(int c2=0;c2<m;c2++){int a;cin>>a;total_horizontal[c]+=a;total_vertical[c2]+=a;}
    cin>>A_B_C[0]>>A_B_C[1]>>A_B_C[2];
    sort(A_B_C.begin(),A_B_C.end());
    int res=0;
    for(int c=2;c<n;c++)
        for(int c2=1;c2<c;c2++)
        {
            vector<int> tot(3);
            tot[0]=tot[1]=tot[2]=0;
            for(int c3=0;c3<c2;c3++)
                tot[0]+=total_horizontal[c3];
            for(int c3=c2;c3<c;c3++)
                tot[1]+=total_horizontal[c3];
            for(int c3=c;c3<n;c3++)
                tot[2]+=total_horizontal[c3];
            sort(tot.begin(),tot.end());
            if(tot[0]==A_B_C[0]&&tot[1]==A_B_C[1]&&tot[2]==A_B_C[2])
                res++;
        }
    for(int c=2;c<m;c++)
        for(int c2=1;c2<c;c2++)
        {
            vector<int> tot(3);
            tot[0]=tot[1]=tot[2]=0;
            for(int c3=0;c3<c2;c3++)
                tot[0]+=total_vertical[c3];
            for(int c3=c2;c3<c;c3++)
                tot[1]+=total_vertical[c3];
            for(int c3=c;c3<m;c3++)
                tot[2]+=total_vertical[c3];
            sort(tot.begin(),tot.end());
 
            if(tot[0]==A_B_C[0]&&tot[1]==A_B_C[1]&&tot[2]==A_B_C[2])
                res++;
        }
    cout<<res;
}