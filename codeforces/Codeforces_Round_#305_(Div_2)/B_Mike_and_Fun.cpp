#include <bits/stdc++.h>
using namespace std;
 
 
 
int main()
{
    int n,m,q;
    cin>>n>>m>>q;
    vector<vector<int> > board(n,vector<int>(m));
    for(int c=0;c<board.size();c++)
        for(int c2=0;c2<board[c].size();c2++)
            cin>>board[c][c2];
 
    vector<int> scores(n,0);
    for(int c=0;c<board.size();c++)
    {
        int act = 0;
        for(int c2=0;c2<board[c].size();c2++)
            if(board[c][c2] == 1) scores[c] = max(scores[c],++act);
            else act=0;
    }
 
    for(int c=0;c<q;c++)
    {
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        board[a][b] = !board[a][b];
        int act = 0;
        scores[a] = 0;
        for(int c2=0;c2<board[a].size();c2++)
            if(board[a][c2] == 1)   scores[a] = max(scores[a],++act);
            else act=0;
 
        cout<<(*max_element(scores.begin(),scores.end()))<<endl;
    }
}