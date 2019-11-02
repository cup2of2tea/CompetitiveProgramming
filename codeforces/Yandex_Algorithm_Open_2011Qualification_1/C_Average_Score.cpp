    #include <iostream>
    #include <vector>
    #include <algorithm>
 
    using namespace std;
 
    bool autre_tri(const pair<int,int> & a,const pair<int,int> & b)
    {
        if(a.first==b.first)
            return a.second<b.second;
        return a.first>b.first;
    }
 
    int main()
    {
        vector <pair<int,int> > truc;
        int nb_marks;
        int a,b;
        cin>>nb_marks>>a>>b;
        truc.resize(nb_marks);
        for(int c=0;c<nb_marks;c++)
        {
            cin>>truc[c].first;
            truc[c].second=c;
        }
        if(a>b)
            sort(truc.begin(),truc.end());
        else if(a<b)
            sort(truc.begin(),truc.end(),autre_tri);
        for(int c=0;c<a;c++)
            truc[truc[c].second].first=1;
        for(int c=a;c<nb_marks;c++)
            truc[truc[c].second].first=2;
        for(int c=0;c<nb_marks;c++)
            cout<<truc[c].first<<" ";
    }