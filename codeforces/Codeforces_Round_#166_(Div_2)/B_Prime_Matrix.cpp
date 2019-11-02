#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <istream>
#include <cmath>
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
 
 
vector<int> premiers;
 
void precompute()
{
    premiers.push_back(2);
    for(int c=3;c<100100;c+=2)
    {
        for(int c2=0;c2<premiers.size();c2++)
            if(c%premiers[c2]==0)
                goto fail;
        premiers.push_back(c);
        fail:;
    }
}
 
 
int main(int argc,char **argv)
{
#ifdef LOCAL
    ifstream in("input.txt");
    ofstream out("output.txt");
#endif
    int n,m;
    cin>>n>>m;
    vector<vector<int> > matrix(n,vector<int>(m));
    for(int c=0;c<n;c++)
        for(int c2=0;c2<m;c2++)
            cin>>matrix[c][c2];
    precompute();
    vector<int> row(n,0);
    vector<int> col(m,0);
    for(int c=0;c<n;c++)
        for(int c2=0;c2<m;c2++)
        {
            int gauche=0,droite=premiers.size();
            while(abs(gauche-droite)>1)
            {
                int mid=(gauche+droite)/2;
                if(premiers[mid]==matrix[c][c2])
                    gauche=droite=mid;
                else if(premiers[mid]>matrix[c][c2])
                    droite=mid;
                else gauche=mid;
            }
            matrix[c][c2]=(premiers[gauche]>=matrix[c][c2]?premiers[gauche]:premiers[droite])-matrix[c][c2];
            row[c]+=matrix[c][c2];
            col[c2]+=matrix[c][c2];
        }
    int mini=row[0];
    for(int c=0;c<n;c++)
        mini=min(row[c],mini);
    for(int c2=0;c2<m;c2++)
        mini=min(col[c2],mini);
    cout<<mini;
 
 
}