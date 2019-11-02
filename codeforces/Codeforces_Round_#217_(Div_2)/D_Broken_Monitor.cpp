#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <iterator>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
 
using namespace std;
 
 
 
int main()
{
 
    ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    #define cin in
    ifstream in("input.txt");
#endif // ONLINE_JUDGE
    int n,m;
    cin>>n>>m;
    vector<string> board(n);
    for(int c=0;c<n;c++) cin>>board[c];
 
    set<int> x;
    set<int> y;
    for(int c=0;c<n;c++)
    {
        for(int c2=0;c2<board[c].size();c2++)
        {
            if(board[c][c2]=='w')
            {
                x.insert(c);
                y.insert(c2);
            }
        }
    }
    set<int>::iterator itx = x.end();
    itx--;
    set<int>::iterator ity = y.end();
    ity--;
    int minix=(*x.begin()),maxix=(*itx),miniy=(*y.begin()),maxiy=(*ity);
    int dim = max(maxix-minix,maxiy-miniy);
    int xdeb=-1,ydeb=-1,xfin=-1,yfin=-1;
    if(dim==maxix-minix)
    {
        xdeb=minix;
        xfin=maxix;
        ydeb=max(maxiy-dim,0);
        yfin=ydeb+dim;
        if(yfin>=m)
        {
            cout<<-1;
            return 0;
        }
         for(int c=0;c<board.size();c++)
            for(int c2=0;c2<board[c].size();c2++)
            {
                if(board[c][c2]=='w')
                {
                    if((c==xdeb||c==xfin)&&(c2>=ydeb&&c2<=yfin))
                        continue;
                    if((c>=xdeb&&c<=xfin)&&(c2==ydeb||c2==yfin))
                        continue;
                    goto nop1;
 
                }
            }
        goto cool;
        nop1:
        xdeb=minix;
        xfin=maxix;
        yfin=min(miniy+dim,m-1);
        ydeb=yfin-dim;
 
        if(yfin<0)
        {
            cout<<-1;
            return 0;
        }
         for(int c=0;c<board.size();c++)
            for(int c2=0;c2<board[c].size();c2++)
            {
                if(board[c][c2]=='w')
                {
                    if((c==xdeb||c==xfin)&&(c2>=ydeb&&c2<=yfin))
                        continue;
                    if((c>=xdeb&&c<=xfin)&&(c2==ydeb||c2==yfin))
                        continue;
                    cout<<-1;
                    return 0;
 
                }
            }
 
    }
    else
    {
 
        ydeb=miniy;
        yfin=maxiy;
        xdeb=max(maxix-dim,0);
        xfin=xdeb+dim;
        if(xfin>=n)
        {
            cout<<-1;
            return 0;
        }
        for(int c=0;c<board.size();c++)
            for(int c2=0;c2<board[c].size();c2++)
            {
                if(board[c][c2]=='w')
                {
                    if((c==xdeb||c==xfin)&&(c2>=ydeb&&c2<=yfin))
                        continue;
                    if((c>=xdeb&&c<=xfin)&&(c2==ydeb||c2==yfin))
                        continue;
                    goto nop2;
 
                }
            }
        goto cool;
        nop2:
        ydeb=miniy;
        yfin=maxiy;
        xfin=min(minix+dim,n-1);
        xdeb=xfin-dim;
 
 
        if(xdeb<0)
        {
            cout<<-1;
            return 0;
        }
         for(int c=0;c<board.size();c++)
            for(int c2=0;c2<board[c].size();c2++)
            {
                if(board[c][c2]=='w')
                {
                    if((c==xdeb||c==xfin)&&(c2>=ydeb&&c2<=yfin))
                        continue;
                    if((c>=xdeb&&c<=xfin)&&(c2==ydeb||c2==yfin))
                        continue;
                    cout<<-1;
                    return 0;
 
                }
            }
    }
    cool:
 
    for(int c=xdeb;c<=xfin;c++)
    {
        if(board[c][ydeb]!='w') board[c][ydeb]='+';
        if(board[c][yfin]!='w') board[c][yfin]='+';
    }
    for(int c=ydeb;c<=yfin;c++)
    {
        if(board[xdeb][c]!='w') board[xdeb][c]='+';
        if(board[xfin][c]!='w') board[xfin][c]='+';
    }
    for(int c=0;c<n;c++) cout<<board[c]<<endl;
}
 