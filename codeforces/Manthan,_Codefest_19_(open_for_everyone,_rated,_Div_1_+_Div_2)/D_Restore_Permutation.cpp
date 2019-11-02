#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <fstream>
#include <limits>
#include <queue>
#include <iomanip>
#include <cmath>
#include <set>
using namespace std;
typedef long long ll;
 
long long  getSum(long long  BITree[], long long  index)
{
    long long  sum = 0; // Iniialize result
 
    // index in BITree[] is 1 more than the index in arr[]
    index = index + 1;
 
    // Traverse ancestors of BITree[index]
    while (index>0)
    {
        // Add current element of BITree to sum
        sum += BITree[index];
 
        // Move index to parent node in getSum View
        index -= index & (-index);
    }
    return sum;
}
 
// Updates a node in Binary Index Tree (BITree) at given index
// in BITree. The given value 'val' is added to BITree[i] and
// all of its ancestors in tree.
void updateBIT(long long  BITree[], long long  n, long long  index, long long  val)
{
    // index in BITree[] is 1 more than the index in arr[]
    index = index + 1;
 
    // Traverse all ancestors and add 'val'
    while (index <= n)
    {
    // Add 'val' to current node of BI Tree
    BITree[index] += val;
 
    // Update index to that of parent in update View
    index += index & (-index);
    }
}
 
// Constructs and returns a Binary Indexed Tree for given
// array of size n.
long long  *constructBITree(vector<long long> &arr, long long  n)
{
    // Create and initialize BITree[] as 0
    long long  *BITree = new long long [n+1];
    for (int i=1; i<=n; i++)
        BITree[i] = 0;
 
    // Store the actual values in BITree[] using update()
    for (int i=0; i<n; i++)
        updateBIT(BITree, n, i, arr[i]);
 
    // Uncomment below lines to see contents of BITree[]
    //for (int i=1; i<=n; i++)
    //     cout << BITree[i] << " ";
 
    return BITree;
}
int main() {
    //  std::cout << "Maximum value for int: " << std::numeric_limits<int>::max() << '\n';
 
    ios_base::sync_with_stdio(false);
    int N;
    cin>>N;
    vector<long long> v(N);
    for(int c=0;c<N;c++) {
        cin>>v[c];
    }
    long long s = N*(N+1)/2;
 
    vector<long long> in(N);
    for(int c=0;c<N;c++) in[c]=c+1;
    reverse(v.begin(),v.end());
 
    long long *bitree = constructBITree(in, N);
 
    for(int c=0;c<N;c++) {
        int left = 0, right = N-1;
        while(left < right) {
            //cout<<left<<" "<<right<<endl;
            long long int mid = (left+right)/2;
 
            long long int s = getSum(bitree, mid);
            if(s <= v[c]) {
                left = mid+1;
            } else {
                right = mid;
            }
        }
        v[c] = left+1;
        updateBIT(bitree,N,left,-(left+1));
    }
    reverse(v.begin(),v.end());
    for(int c=0;c<N;c++) cout<<v[c]<<" ";
 
}