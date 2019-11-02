#include <stdio.h>  
#include <queue>  
#include <map>  
#include <algorithm>  
#include <iostream>  
using namespace std;  
char seq[50005];  
int cost[50005];  
int reve[50005];  
typedef pair<int,int> pii;  
struct inode  
{  
    int val;  
    int offset;  
    inode()  
        :   val(0),  
            offset(0)  
    {}  
    ~inode()  
    {}  
    static const int base;  
} itree[1<<17];  
  
const int inode::base = (1<<16);  
  
void setVal(int n,int v)  
{  
    //assert(n>=inode::base);  
    itree[n].val = v;  
    n>>=1;  
    while (n)   
    {  
        itree[n].val = min(itree[n*2].val,itree[n*2+1].val) + itree[n].offset;  
        n>>=1;  
    }  
}  
void addOffset(int n,int o)  
{  
    itree[n].val += o;  
    itree[n].offset += o;  
    n>>=1;  
    while (n)  
    {  
        itree[n].val = min(itree[n*2].val,itree[n*2+1].val) + itree[n].offset;  
        n>>=1;  
    }  
}  
void addOffset(int s,int e,int o)  
{  
    e--;  
    while (s<e)  
    {  
        if (s%2 == 1) { addOffset(s,o); s++; }  
        if (e%2 == 0) { addOffset(e,o); e--; }  
        if (s<e)  
        {  
            s>>=1;  
            e>>=1;  
        }  
        else break;  
    }  
    if (s==e) addOffset(s,o);  
}  
  
#ifdef local  
#define debug(x) x  
#else  
#define debug(x)   
#endif  
  
  
int main()  
{  
    long long ret=0;  
    scanf("%s",seq);  
    for (int q=0;seq[q];++q)  
    {  
        if (seq[q]=='?')  
        {  
            int costOpen,costClose;  
            scanf("%d %d",&costOpen,&costClose);  
            if (costOpen < costClose)    { seq[q]='('; cost[q]=costClose-costOpen; ret+=costOpen;  }  
            else                        { seq[q]=')'; cost[q]=costOpen-costClose; ret+=costClose; }  
            reve[q]=1;  
        }  
        else  
        {  
            reve[q]=0;  
        }  
    }  
    {  
        debug(printf("solve A:%s\n",seq));  
        //remove negatives!  
        //closer ) -> opener (  
        priority_queue<pii> pq;  
        int curDepth = 0;  
        for (int q=0;seq[q];++q)  
        {  
            if (seq[q]=='(') curDepth++;  
            else   
            {  
                if (reve[q])  
                    pq.push( pii(-cost[q],q) );  
                curDepth--;  
            }  
            if (curDepth<0)  
            {  
                debug(printf("%s , id:%d is negative\n", seq, q) );  
                if (pq.empty())  
                {  
                    ret=-1;  
                    break;  
                }  
                else  
                {  
                    int icost = - pq.top().first;  
                    int index = pq.top().second;  
                    pq.pop();  
                    seq[index] = '(';  
                    cost[index] = -cost[index];  
                    ret += icost;  
                    curDepth += 2;  
                    debug(printf("reverse %d => %s\n",index,seq));  
                }  
            }  
        }  
    }  
    if (ret>=0)  
    {  
        debug(printf("solve B:%s\n",seq));  
        //remove positive tail!8  
        //opener ( -> closer ) between 0-zone & tail  
        priority_queue<pii> pq;  
        int curDepth = 0;  
        int safeZone = 0;  
        for (int q=0;q<inode::base;++q) setVal(inode::base+q,987654321);  
        for (int q=0;seq[q];++q)  
        {  
            if (seq[q]==')') curDepth--;  
            else  
            {  
                if (reve[q])  
                    pq.push( pii(-cost[q],q) );  
                curDepth++;  
            }  
            setVal(inode::base+q,curDepth);  
            if (curDepth==0) safeZone=q;  
        }  
        debug(printf("depth:%d pq:%d\n",curDepth,pq.size()));  
        while (curDepth>0 && !pq.empty())  
        {  
            debug(printf("lastDepth:%d Seq:%s Safer:%s\n",curDepth,seq,seq+safeZone));  
            int icost = -pq.top().first;  
            int index = pq.top().second;  
            pq.pop();  
            if (index<safeZone)   
            {  
                debug(printf("%d is not in safezone.\n",index));  
                continue;  
            }  
            //safe test  
            addOffset(inode::base+index,inode::base*2,-2);  
            if (itree[1].val < 0) //fail  
            {  
                debug(printf("skip %d - it makes Root Val Negative : %d ",index,itree[1].val));  
                addOffset(inode::base+index,inode::base*2,2);  
                debug(printf("recovered : %d\n",itree[1].val));  
                continue;  
            }  
            debug(printf("%d is good Choice!\n",index));  
            if (itree[1].val == 0) //new-Zero-zone  
            {  
                int cur = 1;  
                while (cur<inode::base)  
                {  
                    if (itree[cur*2+1].val <= itree[cur*2].val) cur=cur*2+1;  
                    else                                        cur=cur*2;  
                }  
                safeZone = cur - inode::base;  
            }  
            seq[index]=')';  
            cost[index]=-cost[index];  
            curDepth-=2;  
            ret+=icost;  
        }  
        if (curDepth!=0) ret=-1;  
    }  
    if (ret>=0)  
    {  
        cout << ret << endl << seq << endl;  
    }  
    else   
    {  
        cout << ret << endl;  
    }  
}  