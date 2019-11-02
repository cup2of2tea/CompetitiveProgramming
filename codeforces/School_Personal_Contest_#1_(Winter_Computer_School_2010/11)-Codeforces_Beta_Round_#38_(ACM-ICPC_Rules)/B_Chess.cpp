#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main()
{
    vector<string> board(8);
    for(int c=0;c<8;c++)
        board[c]="........";
    string s[2];
    cin>>s[0]>>s[1];
    s[0][1]--;
    s[1][1]--;
    for(int c=0;c<2;c++)
        board[s[c][0]-'a'][s[c][1]-'0']='X';
    int dx[8]={1,-1,1,-1,2,-2,2,-2};
    int dy[8]={2,2,-2,-2,1,1,-1,-1};
    for(int c=0;c<8;c++)
        board[s[0][0]-'a'][c]=board[c][s[0][1]-'0']='X';
    for(int c=0;c<8;c++)
    {
        for(int c2=0;c2<2;c2++)
        {
           int x2= s[c2][0]-'a'+dx[c];
           int y2= s[c2][1]-'0'+dy[c];
           if(x2>=0&&y2>=0&&x2<8&&y2<8)
            board[x2][y2]='X';
        }
    }
    int total=0;
    for(int c=0;c<8;c++)
        for(int c2=0;c2<8;c2++)
            if(board[c][c2]=='.')
                total++;
    cout<<total;
}