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
using namespace std;
 
typedef struct seg
{
    seg(){}
    seg(int a,int b):c0(a),c1(b){}
    int c0;
    int c1;
};
 
typedef struct node
{
    node(){}
    node(int s,int d,int c):x(s),y(d),cout(c){}
    int x;
    int y;
    int cout;
};
 
class comparer
{
    public:
        bool operator()(const node &n1,const node &n2)
        {
            return n1.cout<n2.cout;
        }
};
 
 
int main()
{
    int n,k;
    cin>>k>>n;
    vector<int> v(n);
    vector<bool> v2(n*k+1,false);
    for(int c=0;c<n;c++)
    {
        cin>>v[c];
        v2[v[c]]=true;
    }
 
    for(int c2=0;c2<n;c2++)
    {
        cout<<v[c2]<<" ";
        for(int c3=1;c3<k;c3++)
        {
            for(int c4=1;c4<=n*k;c4++)
            {
                if(!v2[c4])
                {
                    v2[c4]=true;
                    cout<<c4<<" ";
                    break;
                }
            }
        }
        cout<<endl;
    }
}