#include <iostream>
#include <vector>
 
using namespace std;
 
int main()
{
  vector<string> board(8);
  for(int c=0;c<8;c++) cin>>board[c];
  
  vector<int> presence(8,0);
  for(int c=0;c<8;c++)
    for(int c2=0;c2<8;c2++)
      if(board[c][c2] == 'B') presence[c2]|=1;
      else if(board[c][c2] == 'W') presence[c2]|=2;
  int B = 9,W =9;
  for(int c=0;c<8;c++)
    for(int c2=0;c2<8;c2++){
      if(board[c][c2]=='B' && c != 7){
    for(int c3=c+1;c3<8;c3++) if(board[c3][c2] != '.') goto nop;
    B = min(B,7-c);
      }
      else if(board[c][c2]=='W' && c != 0){
    for(int c3=0;c3<c;c3++) if(board[c3][c2] != '.') goto nop;
    W = min(c,W);
      }
      nop:;
      }
  if(W <= B){
    cout<<"A";
  } else {
    cout<<"B";
  }
}