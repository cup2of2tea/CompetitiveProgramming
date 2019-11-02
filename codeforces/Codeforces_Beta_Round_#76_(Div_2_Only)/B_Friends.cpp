    #include <iostream>
    #include <string>
    #include <vector>
    using namespace std;
     
    int main()
    {
            bool matrice_connaissance[5][5];
            for(int c=0;c<5;c++)
            for(int c2=0;c2<5;c2++)
            matrice_connaissance[c][c2]=false;
            int nb_liens;
            std::cin>>nb_liens;
            for(int c=0;c<nb_liens;c++)
            {
                    int a,b;
                    std::cin>>a>>b;
                    matrice_connaissance[a-1][b-1]=matrice_connaissance[b-1][a-1]=true;
            }
            for(int c2=0;c2<5;c2++)
                    {
                            int total=0;
                            for(int c3=0;c3<5;c3++)
                            {
                                    if(c2==c3)
                                            continue;
                                            for(int c4=0;c4<5;c4++)
                                            {
                                                    if(c4==c2||c4==c3)
                                                            continue;
                                                    if(matrice_connaissance[c3][c4]==matrice_connaissance[c2][c3]&&matrice_connaissance[c2][c3]==matrice_connaissance[c2][c4])
                                                    {
                                                            cout<<"WIN";
                                                            return 0;
                                                    }
                                            }
                            }
                    }
            cout<<"FAIL";
                                           
                           
                   
    }