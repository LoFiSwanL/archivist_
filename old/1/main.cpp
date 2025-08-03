#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct Graph {
    int vertex_count{0};
    std::vector<std::vector<int>> edges;
    int count = 0;
};

Graph read_graph(){
    Graph rs;
    cin >> rs.vertex_count;
    rs.edges.resize(rs.vertex_count + 1);
    for(int i = 0; i < rs.vertex_count; i++){
        for(int j = 0; j < rs.vertex_count; j++){
            int val;
            cin >> val;

            if(val == 1){
                rs.edges[i].push_back(j);
                rs.count++;
            }
        }
    }
    cout << "\n" << (rs.count / 2);
    
    return rs;
}

int main(){
    read_graph();
}