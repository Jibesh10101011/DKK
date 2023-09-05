#include<bits/stdc++.h>
#define pr pair<int,int>
using namespace std;
bool comparator(pr p1,pr p2)
{
    return p1.first>p2.first;
}
void f1() {
    priority_queue<pr,vector<pr>,greater<pr>>pq;
    pq.emplace(1,0);
    pq.emplace(2,0);
    pq.emplace(3,0);
    pq.emplace(4,0);
    pq.emplace(5,0);
    pq.emplace(6,0);
    while(!pq.empty())
    {
        cout<<pq.top().first<<" "<<pq.top().second<<endl;
        pq.pop();
    }
}
int main()
{
  f1();
  return 0;
}