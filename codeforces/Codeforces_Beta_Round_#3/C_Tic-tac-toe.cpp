        #include <vector>
            #include <list>
            #include <map>
            #include <set>
            #include <deque>
            #include <stack>
            #include <bitset>
            #include <algorithm>
            #include <functional>
            #include <numeric>
            #include <utility>
            #include <sstream>
            #include <iostream>
            #include <iomanip>
            #include <cstdio>
            #include <cmath>
            #include <cstdlib>
            #include <ctime>
             
            using namespace std;
             
            string morpion[3];
           
            int main()
            {cin>>morpion[0]>>morpion[1]>>morpion[2];
                int nb_X=0,nb_O=0;
                for(int c=0;c<3;c++)
                    for(int c2=0;c2<3;c2++)
                        if('X'==morpion[c][c2])
                            nb_X++;
                        else if('0'==morpion[c][c2])
                            nb_O++;
                if(nb_O>nb_X||nb_X-1>nb_O)
                {
                    cout<<"illegal";
                    return 0;
                }
                int player_1=0,player_2=0;
                for(int c=0;c<3;c++)
                {
                    if(morpion[c][0]==morpion[c][1]&&morpion[c][0]==morpion[c][2])
                    {
                        if(morpion[c][0]=='0')
                            player_2++;
                        if(morpion[c][0]=='X')
                            player_1++;
                    }
                    if(morpion[0][c]==morpion[1][c]&&morpion[0][c]==morpion[2][c])
                    {
                        if(morpion[0][c]=='0')
                            player_2++;
                        if(morpion[0][c]=='X')
                            player_1++;
                    }
                }
                if(morpion[0][0]==morpion[1][1]&&morpion[1][1]==morpion[2][2])
                {
                    if(morpion[0][0]=='0')
                            player_2++;
                    if(morpion[0][0]=='X')
                            player_1++;
                }
                if(morpion[2][0]==morpion[1][1]&&morpion[1][1]==morpion[0][2])
                {
                    if(morpion[2][0]=='0')
                            player_2++;
                    if(morpion[2][0]=='X')
                            player_1++;
                }
                if(player_1>2||player_2>2||(player_1>0&&player_2>0))
                {
                    cout<<"illegal";
                    return 0;
                }
                if(player_1>0)
                {
                    if(nb_X==nb_O)
                        cout<<"illegal";
                    else
                        cout<<"the first player won";
                    return 0;
                }
                if(player_2>0)
                {
                    if(nb_X>nb_O)
                        cout<<"illegal";
                    else
                        cout<<"the second player won";
                    return 0;
                }
                else if(nb_X+nb_O==9)
                {
                    cout<<"draw";
                    return 0;
                }
                if(nb_X==nb_O)
                {
                    cout<<"first";
                    return 0;
                }
                cout<<"second";
            }