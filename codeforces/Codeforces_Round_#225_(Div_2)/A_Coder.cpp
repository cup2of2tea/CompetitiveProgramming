#include <iostream>
#include <vector>
using namespace std;
 
int main()
{int n;
    cin>>n;
    vector<string> v(n);
    
    int dx[2]={-1,0};
    int dy[2]={0,-1};
    int res = 0;
    for(int c=0;c<n;c++)
    {
        v[c].resize(n);
        for(int c2=0;c2<n;c2++)
        {
            for(int c3=0;c3<2;c3++)
            {
                int x2= c+dx[c3];
                int y2= c2+dy[c3];
                if(min(x2,y2)>=0&&max(x2,y2)<n&&v[x2][y2]=='C')
                {
                    v[c][c2]='.';
                    break;
                }
                if(c3==1){res++; v[c][c2]='C';}
            }
       }
   }
   cout<<res<<endl;
   for(int c=0;c<n;c++) cout<<v[c]<<endl;
}