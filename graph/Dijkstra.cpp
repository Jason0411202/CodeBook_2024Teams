#include <bits/stdc++.h>
using namespace std;
typedef long long int llt;
#define INF 0x3f3f3f3f3f3f3f3f

vector<llt> Dijkstra(vector<vector<pair<llt, llt>>>& graph, llt start) // graph 是 1-indexed, start 是起點
{
    vector<llt> ans(graph.size()+1, INF);
    ans[start]=0; // 起點的距離設成 0，其他設成 INF

    priority_queue<pair<llt, llt>, vector<pair<llt, llt>>, greater<pair<llt, llt>>> pq; // {與 start 的距離, nodeID}
    pq.push({0, start});

    while(!pq.empty())
    {
        auto Top=pq.top();
        pq.pop();

        if (Top.first>ans[Top.second]) continue; // 若當前的 Top 代表的更新與 start 的距離, 比當前答案還差的話, 直接跳過

        for(auto x: graph[Top.second]) // x: {相鄰點的 nodeID, 權重}
        {
            if(ans[Top.second]+x.second<ans[x.first]) // 若能透過 Top 代表的點找到到其他點更短的路徑，則更新之
            {
                ans[x.first]=ans[Top.second]+x.second;
                pq.push({ans[x.first], x.first});
            }
        }
    }

    return ans; // 回傳從 start 到各點的最短路徑陣列
}
