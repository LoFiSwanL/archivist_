#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Graph {
    int vertex_count{0};
    map<int, vector<int>> edges;
};

Graph read_graph(string filepath) {
    Graph res;
    ifstream file(filepath);
    if (!file.is_open()) {
        cout << "не вдалося відкрити файл" << endl;
        return res;
    }
    file >> res.vertex_count;
    int x, y;
    while (file >> x >> y) {
        res.edges[x].push_back(y);
        res.edges[y].push_back(x);
    }
    return res;
}

void dfs(int vertex, vector<bool>& visited, Graph& graph) {
    visited[vertex - 1] = true;
    for (int i : graph.edges[vertex]) {
        if (!visited[i - 1]) {
            dfs(i, visited, graph);
        }
    }
}

void dfs_with_parent(int vertex, vector<int>& visited, Graph& graph, int father) {
    visited[vertex - 1] = father;
    for (int i : graph.edges[vertex]) {
        if (visited[i - 1] == 0 && i != father) {
            dfs_with_parent(i, visited, graph, vertex);
        }
    }
}

bool path_exists(int source, int destination, Graph& graph) {
    vector<bool> visited(graph.vertex_count, false);
    dfs(source, visited, graph);
    return visited[destination - 1];
}

vector<int> path(int source, int destination, Graph& graph) {
    vector<int> path_from_source;
    vector<int> visited(graph.vertex_count, 0);
    dfs_with_parent(source, visited, graph, source);

    if (visited[destination - 1] == 0 && destination != source) {
        return path_from_source; // порожній — шляху немає
    }

    // від destination до source по батьківських вузлах
    path_from_source.push_back(destination);
    while (path_from_source.back() != source) {
        path_from_source.push_back(visited[path_from_source.back() - 1]);
    }

    reverse(path_from_source.begin(), path_from_source.end());
    return path_from_source;
}

typedef pair<int, int> vertex;
vector<string> read_maze(string filepath){
    ifstream file(filepath);
    if (!file.is_open()) {
        throw runtime_error("cant open file");
    }
    vector<string> Maze;
    string x;
    while(file >> x){
        Maze.push_back(x);
    }
    return Maze;
}

vector<vertex> moves{{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

bool is_There_Exit(const vector<string>& Maze){
    vertex start, finish;
    for(int j = 0; auto a: Maze){
        for(int i = 0; i < a.size(); ++i){
            if(a[i] == '@'){
                finish = {j, i};
            }
            if(a[i] == 'P'){
                start = {j, i};
            }
        }
        j++;
    }
    queue<vertex> que;
    int n, m;
    n = Maze.size();
    m = Maze[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    que.push(start);
    visited[start.first][start.second] = true;
    while(!que.empty()){
        vertex curr= que.front();
        que.pop();
        for(auto a: moves){
            vertex temp = {curr.first + a.first, curr.second + a.second};
            if(temp.first < n&& temp.first >= 0 && temp.second < m && temp.second >=0
                && Maze[temp.fisrt][temp.second] != '#' && visited[temp.first][temp.second] 
            )
        }
    }
}

int main(){
// int a, b;
//     cout << "Search from: ";
//     cin >> a;
//     cout << "Search to: ";
//     cin >> b;

//     Graph graph = read_graph("file.txt");

//     cout << path_exists(a, b, graph) << endl;

//     vector<int> our_path = path(a, b, graph);
//     for(auto i: our_path){
//         cout << i << " ";
//     }
//     cout << endl;

    auto m = read_maze("maze.txt");
    for(auto a: m){
        cout << a << endl;
    }
}