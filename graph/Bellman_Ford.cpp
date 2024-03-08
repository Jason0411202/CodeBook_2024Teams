#include <bits/stdc++.h>
using namespace std;
typedef long long int llt;
#define INF 0x3f3f3f3f3f3f3f3f

vector<llt> Bellman_Ford(vector<pair<pair<llt, llt>, llt>>& edges, llt n, llt start) // 傳入邊集合(1-indexed)、點數、起點
{
    vector<llt> ans(n+1, INF);
    ans[start]=0;

    for(llt i=0;i<n-1;i++) // 跑 n-1 輪
    {
        for(llt j=0;j<edges.size();j++) // 每輪嘗試透過每條邊 relax
        {
            llt u=edges[j].first.first;
            llt v=edges[j].first.second;
            llt w=edges[j].second;                         // 當透過 uv 這條邊，能使得點 start 至點 v 的距離更短
            if(ans[u]!=INF) ans[v]=min(ans[v], ans[u]+w); // 且點 start 走的到點 u 時，更新其最短路徑
            // (如果只想找 start 能走到的負環，則這個 if 需要保留，否則不用)
        }
    }

    return ans; // 回傳 start 至其他點的最短距離
}