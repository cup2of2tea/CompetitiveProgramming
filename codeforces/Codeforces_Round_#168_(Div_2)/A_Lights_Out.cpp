#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <istream>
#include <algorithm>
#include <queue>
#include <map>
#include <list>
#include <cstdio>
#include <set>
#include <iomanip>
#include <stack>
#include <ctime>
#include <climits>
#include <iterator>
#define LOCAL
#ifdef ONLINE_JUDGE
#define COUT(s)
#undef LOCAL
#endif
#ifdef LOCAL
#define cin in
#define COUT(s) cout<<"-----"<<s<<"-----"<<endl;
#endif
using namespace std;
 
 
int main(int argc,char **argv)
{
#ifdef LOCAL
    ifstream in("input.txt");
    ofstream out("output.txt");
#endif
    vector<string > res(3,"111");
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
    for(int c=0;c<3;c++)
    {
        for(int c2=0;c2<3;c2++)
        {
            int z;
            cin>>z;
            z%=2;
            for(int c3=0;c3<z;c3++)
            {
                res[c][c2]=(res[c][c2]=='0'?'1':'0');
                for(int c4=0;c4<4;c4++)
                {
                    int x2=c+dx[c4];
                    int y2=c2+dy[c4];
                    if(x2>=0&&y2>=0&&x2<3&&y2<3) res[x2][y2]=(res[x2][y2]=='0'?'1':'0');
                }
            }
        }
    }
    for(int c=0;c<3;c++) cout<<res[c]<<endl;
}