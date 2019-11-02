    #include <iostream>
    #include <vector>
    #include <algorithm>
    using namespace std;
    
    int main()
    {
        int counter = 1;
        int n;
        cin>>n;
        int res = 0;
        vector<int> zero;
        for(int c=0;c<n;c++)
        {
            int a,b;
            cin>>a>>b;
            if(b>0)
            {
                counter+=b-1;
                res+=a;
            }
            else zero.push_back(a);
        }
        sort(zero.rbegin(),zero.rend());
        for(int c=0;c<min(counter,(int)zero.size());c++)
        {
            res+=zero[c];
        }
        cout<<res;
    }