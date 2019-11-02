#include <iostream>
#include <vector>
#include <algorithm>
    using namespace std;
        
        class quadruplet
        {
                public:
                int speed;
                int ram;
                int hdd;
                int cost;
                quadruplet(){}
                quadruplet(int a,int b,int c,int d):speed(a),ram(b),hdd(c),cost(d){}
        };
        bool operator <(const quadruplet &a,const quadruplet &b)
        {
                return a.speed<b.speed&&a.ram<b.ram&&a.hdd<b.hdd;
        }
    int main()
    {
        
                int nb;
                cin>>nb;
                vector <quadruplet> v(nb);
                for(int c2=0;c2<nb;c2++)
                {
                        int a,b,c,d;
                        cin>>a>>b>>c>>d;
                        v[c2]=quadruplet(a,b,c,d);
                }
                int x;
                int mini=100000;
                for(int c=0;c<v.size();c++)
                {
                        for(int c2=0;c2<v.size();c2++)
                        {
                                if(c==c2)
                                        continue;
                                if(v[c]<v[c2])
                                        goto end;
                        }
                        if(v[c].cost<mini)
                        {
                                x=c;
                                mini=v[c].cost;
                        }
                        end:;
                }
cout<<x+1;
    }