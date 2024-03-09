#include <bits/stdc++.h>
using namespace std;
typedef long long int llt;

vector<llt> Topology_Sort(vector<vector<llt>> &graph) // 傳入一張 1-indexed graph
{
    vector<llt> indegree(graph.size(), 0);
    for(llt i=1;i<=graph.size()-1;i++) // 建立每個點的入度資訊
    {
        for(auto x: graph[i])
        {
            indegree[x]++;
        }
    }

    queue<llt> q; // 維護沒有前置工作，可以直接選取的點集合
    vector<llt> ans;
    for(llt i=1;i<=graph.size()-1;i++) // 將入度為 0 的那些點加入 queue 中
    {
        if(indegree[i]==0) q.push(i);
    }

    while(!q.empty())
    {
        llt Top=q.front(); // 選取某個點
        q.pop();

        ans.push_back(Top);
        for(auto &i:graph[Top]) // 將前置工作為 Top 的那些點的入度扣一
        {
            indegree[i]--;
            if(indegree[i]==0) // 當入度為 0 時，代表該點代表的工作現在可被選取，加入 queue 中
            {
                q.push(i);
            }
        }
    }

    return ans; // 回傳符合條件的任務先後順序，若陣列 size 小於 n，代表圖中有環
}