#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 1e9;

struct Graph {
    int vertex_count{0};
    map<int, vector<pair<int, int>>> edges;

    void add_edge(int from, int to, int weight){
        edges[from].push_back({to, weight});
        edges[to].push_back({from, weight});
    }
};

Graph read_graph(int &v1, int &v2){
    Graph res;
    int edges_count;
    cin >> res.vertex_count >> edges_count;
    cin >> v1 >> v2;

    for(int i = 0; i < edges_count; ++i){
        int a, b, weight;
        cin >> a >> b >> weight;
        res.add_edge(a, b, weight);
    }

    return res;
}

pair<map<int, int>, map<int, int>> search_min_road(const Graph &graph, int begin){
    map<int, int> distant, prev;
    for(const auto &[v, garbage]: graph.edges){
        distant[v] = INF;
    }
    distant[begin] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, begin});

    while(!pq.empty()){
        auto [current_distance, vertex] = pq.top(); 
        pq.pop();
        if(current_distance > distant[vertex]){
            continue;
        }

        for(auto &[neighbour, weight]: graph.edges.at(vertex)){
            if(distant[vertex] + weight < distant[neighbour]){
                distant[neighbour] = distant[vertex] + weight;
                prev[neighbour] = vertex;
                pq.push({distant[neighbour], neighbour});
            }
        }
    }

    return {distant, prev};
}

vector<int> path(int from, int to, const map<int, int> &prev){
    vector<int> path;
    for(int v = to; v != from; v = prev.at(v)){
        path.push_back(v);
    }
    path.push_back(from);
    reverse(path.begin(), path.end());
    return path;
}

int main() {
    int v1, v2;
    Graph graph = read_graph(v1, v2);

    auto [distanc, prev] = search_min_road(graph, v1);

    cout << distanc[v2] << endl;

    vector<int> pat = path(v1, v2, prev);
    for(int vertex: pat){
        cout << vertex << " ";
    }
    return 0;
}
