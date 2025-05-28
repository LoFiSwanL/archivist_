//Itsko Andrii K-16
//var 6

#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

struct Graph{
    map<string, vector<string>> edges;
    int vertex_count() const{
        return edges.size();
    }
};
Graph read_graph(string filepath) {
    Graph res;
    ifstream file(filepath);
    if (!file.is_open()) {
        cout << endl << "Cant open file" << endl;
        return res;
    }

    string x, y, z;
    string strings;
    while (getline(file, strings)) {
        istringstream str(strings);

        if(!(str >> x >> y)){
            cout << endl << "not 2 vertex in a row" << endl;
            return {};
        }
        if(str >> z){
            cout << endl << "more than 2 vertex in a row" << endl;
            return {};
        }
        res.edges[x].push_back(y);
        res.edges[y].push_back(x);
    }
    if(res.edges.empty()){
        cout << endl << "graph empty" << endl;
    }
    return res;
}
bool is_there_cycle(const string& start, Graph& graph, map<string, bool>& visited){
    map<string, string> parent;
    vector<string> dfs;
    dfs.push_back(start);
    visited[start] = true;
    bool is_cycled = false;

    while(!dfs.empty()){
        string curr = dfs.back();
        dfs.pop_back();
        for(const string& near: graph.edges[curr]){
            if(!visited[near]){
                visited[near] = true;
                parent[near] = curr;
                dfs.push_back(near);
            }
            else if(parent[curr] != near){
                is_cycled = true;
            }
        }
    }
    return is_cycled;
}
int count_with_cycles(Graph& graph){
    map<string, bool> visited;
    int count = 0;

    for(const auto& [vertex, garbage] : graph.edges){
        if(!visited[vertex] && is_there_cycle(vertex, graph, visited)){
            count++;
        }
    }
    return count;
}
void solve(const string& filepath){
    Graph graph = read_graph(filepath);
    if(graph.edges.empty()){
        return;
    }
    int res = count_with_cycles(graph);
    cout << endl << res << endl;
}


int main(int argc, char* argv[]){
    if(argc != 2){
        cerr << endl << "error count of arg" << endl;
        return 0;
    }
    string filepath = argv[1];
    solve(filepath);

    return 0;
}