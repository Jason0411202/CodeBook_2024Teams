#include <bits/stdc++.h>
using namespace std;
typedef long long int llt;
#define INF 0x3f3f3f3f3f3f3f3f

vector<vector<llt>> Floyd_Warshall(vector<vector<pair<llt, llt>>>& graph) //傳入 1-index 的圖
{
    vector<vector<llt>> ans(graph.size(), vector<llt> (graph.size(), INF));
    for(llt i=1;i<=graph.size()-1;i++) // 將邊的資訊傳遞給 ans
    {
        for(auto x: graph[i])
        {
            ans[i][x.first]=x.second;
        }
    }

    for(llt i=1;i<=graph.size()-1;i++) // 自己與自己的距離為 0
    {
        ans[i][i]=0;
    }

    for(llt k=1;k<=graph.size()-1;k++) // 用動態規劃找任兩點間的最短路
    {
        for(llt i=1;i<=graph.size()-1;i++)
        {
            for(llt j=1;j<=graph.size()-1;j++)
            {
                ans[i][j]=min(ans[i][j], ans[i][k]+ans[k][j]);
            }
        }
    }

    return ans; // 回傳一個二維陣列，代表任兩點間的最短路徑
}
