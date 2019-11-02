    #include <iostream>
    #include <vector>
    #include <algorithm>
    using namespace std;
 
    string conversion(bool dx,int d)
    {
        if(!dx)
        {
            if(d==1)
                return "R";
            else if(d==-1)
                return "L";
            return "";
        }
        else
        {
            if(d==1)
                return "U";
            else if(d==-1)
                return "D";
            return "";
        }
    }
 
    int main()
    {
        string s1,s2;
        cin>>s1>>s2;
 
        vector<string> deroulement;
        while(s1[0]!=s2[0]||s1[1]!=s2[1])
        {
            int dx=0,dy=0;
            if(s1[0]>s2[0])
                dy=-1;
            if(s1[0]<s2[0])
                dy=1;
            if(s1[1]>s2[1])
                dx=-1;
            if(s1[1]<s2[1])
                dx=1;
            s1[0]+=dy;
            s1[1]+=dx;
            deroulement.push_back(conversion(false,dy)+conversion(true,dx));
        }
        cout<<deroulement.size()<<endl;
        for(int c=0;c<deroulement.size();c++)
            cout<<deroulement[c]<<endl;
    }