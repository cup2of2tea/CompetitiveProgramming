    #include <iostream>
    #include <string>
    #include <vector>
    using namespace std;
     
    int main()
    {
            string code;
            getline(cin,code);
            vector <string> combi(10);
            for(int c=0;c<10;c++)
                    getline(cin,combi[c]);
            for(int c=0;c<8;c++)
            {
                    string s=code.substr(c*10,10);
                    for(int c2=0;c2<10;c2++)
                            if(combi[c2]==s)
                            {
                                    cout<<c2;
                                    break;
                            }
            }
    }