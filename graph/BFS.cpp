#include<iostream>
#include<vector>
#include<list>
#include<queue>

class Graph{
public:
    Graph(int n);

    void BFS(int v);
    void connect();
    void connect(const std::vector<std::list<int> > &g);
private:
    int vNum;
    std::vector<std::list<int> > graph;
    std::vector<bool> visited;
};

Graph::Graph(int n){
    vNum=n;
    visited.assign(n,false);
}

void Graph::connect(const std::vector<std::list<int> > &g){
    vNum=g.size();
    visited.clear();
    visited.assign(g.size(),false);
    graph.clear();
    graph=g;
}

void Graph::connect(){
    graph.clear();
    std::cout<<"The vertex number: "<<vNum<<std::endl;
    for(int i=0;i<vNum;i++){
        std::cout<<"Vertex "<<i<<std::endl;
        std::list<int> l;
        int n;
        while(std::cin>>n&&n<vNum)
            l.push_back(n);
        graph.push_back(l);
    }
}

void Graph::BFS(int v){
    std::cout<<v<<" ";
    std::queue<int> q;
    visited[v]=true;
    q.push(v);
    std::list<int>::iterator it;
    while(!q.empty()){
        int f=q.front();
        q.pop();
        for(it=graph[f].begin();it!=graph[f].end();it++){
            if(visited[*it]==false){
               q.push(*it);
               visited[*it]=true;
               std::cout<<*it<<" ";
            }
        }
        
    }
}

int main(){
    Graph a(3);
    std::vector<std::list<int> > v={{2,3},{5},{0,4},{0},{2,5},{1,4}};
    a.connect(v);
    a.BFS(1);
    std::cout<<std::endl;

    Graph b(5);
    b.connect();
    int n;
    std::cout<<"BFS from vertex: "<<std::endl;
    std::cin>>n;
    b.BFS(n);

    return 0;
}
