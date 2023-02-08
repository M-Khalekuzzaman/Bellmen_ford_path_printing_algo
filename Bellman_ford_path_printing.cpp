#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const long long INF = 1e18;
vector< pair<int,int> >adj_list[N];
long long d[N],parent_node[N];

int main()
{
    int n,m;
    cin>>n>>m;

    for(int i = 1; i<=n; i++)
    {
        d[i] = INF;
    }

    for(int i = 0; i<m; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;

        adj_list[u].push_back({v,w});
    }
    int src = 1,dst = 5;
    d[src] = 0;

    bool cycle_exists = false;
    int last_update_node = -1;

    for(int i = 1; i<=n; i++)
    {
        for(int node = 1; node<=n; node++)
        {
            for(pair<int,int>adj_node : adj_list[node])
            {
                int u = node;
                int v = adj_node.first;
                int w = adj_node.second;

                if(d[u] + w < d[v])
                {
                    d[v] = d[u] + w;
                    parent_node[v] = u;
                    if(i == n)
                    {
                        cycle_exists = true;
                        last_update_node = v;
                    }

                }
            }
        }
    }
    stack<int>path_print;
    if(cycle_exists == false)
    {
        path_print.push(dst);
        while(dst != src)
        {
            int x = parent_node[dst];
            path_print.push(x);
            dst = x;
        }
        while(!path_print.empty())
        {
            cout<<path_print.top()<<" -> ";
            path_print.pop();
        }
    }
    else
    {
        cout<<"YES"<<endl;
        int selected_node = last_update_node;
        for(int i = 1; i<=n-1; i++)
        {
            selected_node = parent_node[selected_node];

        }
        vector<int>cycle;
        int first_node = selected_node;
        cycle.push_back(selected_node);
        while(true)
        {
            selected_node = parent_node[selected_node];
            cycle.push_back(selected_node);
            if(selected_node == first_node)
            {
                break;
            }
        }
        reverse(cycle.begin(),cycle.end());
        for(int node : cycle)
        {
            cout<<node<<" -> ";
        }
    }


    return 0;
}
