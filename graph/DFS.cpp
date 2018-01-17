#include<iostream>
#include<vector>
#include<list>

class Graph{
public:
    Graph(int n);

    void DFS(int n); //from source vertex n
    void connect();
    void connect(const std::vector<std::list<int> > &g);
    void broadcast();//broadcast discover and finish time

private:
    int vNum=0; //vertex number
    std::vector<bool> visited; //record whether a vertex is visited
    std::vector<std::list<int> > graph;
    std::vector<int> d; // discover time
    std::vector<int> f; // finish time
    void Visit(int n,int &time);

};

Graph::Graph(int n){
    vNum=n;
    visited.assign(n,false);
    d.assign(n,0);
    f.assign(n,0);
}

void Graph::connect(){
    graph.clear();
    std::cout<<"Vertex Number: "<<vNum<<std::endl;
    for(int i=0;i<vNum;i++)
    {
        std::cout<<"Vertex: "<<i<<std::endl;
        std::list<int> l;
        int n;
        while(std::cin>>n && n<vNum)
            l.push_back(n);

        graph.push_back(l);
    }
}

void Graph::connect(const std::vector<std::list<int> > &g){
    graph.clear();
    graph=g;
    vNum=g.size();
    d.clear();
    d.assign(vNum,0);
    f.clear();
    f.assign(vNum,0);
    visited.clear();
    visited.assign(vNum,false);
}

void Graph::DFS(int n){
    int time=0;
    Visit(n,time);
    for(int i=0;i<vNum;i++)
    {
        if(visited[i]==false)
            Visit(i,time);
    }
}

void Graph::Visit(int n,int &time){  //visit vertex n
    std::cout<<n<<" ";
    time=time+1;
    d[n]=time;
    visited[n]=true;
    std::list<int>::iterator it;
    for(it=graph[n].begin();it!=graph[n].end();it++)
    {
        if(visited[*it]==false)
            Visit(*it,time);
    }
    time=time+1;
    f[n]=time;
}

void Graph::broadcast(){
    for(int i=0;i<vNum;i++){
        std::cout<<d[i]<<" "<<f[i]<<std::endl;
    }
}

int main(){
    Graph G(9);
    std::vector<std::list<int> > g={{1,5},{0},{4,5},{5},{2},{0,2,3},{7,8},{6},{6}};
    G.connect(g);
    G.DFS(1);
    std::cout<<std::endl;
    G.broadcast();

    Graph G2(9);
    G2.connect();
    int n;
    std::cout<<"DFS from Vertex: "<<std::endl;
    std::cin>>n;
    G2.DFS(n);
    std::cout<<std::endl;
    G2.broadcast();
    return 0;
}
