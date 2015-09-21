//
//  uva11857.cpp
//  lab-paa
//
//  Created by Matheus Cassiano Candido on 9/13/15.
//  Copyright (c) 2015 Matheus Cassiano Candido. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#define MAX 100000

using namespace std;

class Edge {
    
public:
    int src;
    int dest;
    int weight;
    
public:
    Edge() {
        src = 0;
        dest = 0;
        weight = 0;
    }
    
    Edge(int src, int dest, int weight) {
        this->src = src;
        this->dest = dest;
        this->weight = weight;
    }
};

class EdgeComparator {
public:
    bool operator()(Edge& t1, Edge& t2) {
        return t1.weight > t2.weight;
    }
};

typedef vector<Edge> Vertex;

class Graph {
    
private:
    long V, E;
    Vertex list[MAX];

public:
    Graph() {
        clear();
    }
    
    void clear() {
        V = 0;
        E = 0;
        for (int i = 0; i < MAX; i++)
            list[i].clear();
    }
    
    void setV(int V) {
        this->V = V;
    }
    
    void addEdge(int src, int dest, int weight) {
        list[src].push_back(Edge(src, dest, weight));
        E += 1;
    }
    
    int getCarMinRange() {
        
        // arvore geradora de prim
        
        int max = -1;
        
        int visited[V];
        for (int i = 0; i < V; i++)
            visited[i] = false;
        
        priority_queue<Edge, vector<Edge>, EdgeComparator> pq;
        for (int i = 0; i < list[0].size(); i++)
            pq.push(list[i][i]);
        
        while(!pq.empty()) {
            Edge curr = pq.top();
            pq.pop();
            
            if(visited[curr.dest])
                continue;
            
            visited[curr.dest] = true;
            
            if(max < curr.weight)
                max = curr.weight;
            
            for(int i = 0; i < (int)list[curr.dest].size(); i++)
                pq.push(list[curr.dest][i]);

        }
        
        for(int i = 0; i < V; i++)
            if(!visited[i])
                return -1;
               
        return max;
    }
    
};

int main() {
    int n, m;
    
    while (scanf("%d %d", &n, &m) == 2){
        
        if (n == 0 && m == 0)
            break;
        
        Graph g;
        g.setV(n);
        
        for(int i = 0; i < m; i++) {
            int city1, city2, weight;
            scanf("%d %d %d",&city1, &city2, &weight);
            
            g.addEdge(city1, city2, weight);
            g.addEdge(city2, city1, weight);
        }
        
        int ans = g.getCarMinRange();
        
        if (ans == -1)
            printf("IMPOSSIBLE\n");
        else
            printf("%d\n", ans);
    }
    
    return 0;
}