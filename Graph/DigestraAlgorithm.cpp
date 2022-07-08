
#include <iostream>
using namespace std;
#include <limits.h>

#define V 3
//string hosp[V];
 int adjMatrix[V][V];
 
	string ShortDistance[V] = {"Islamabad", "Karachi", "Lahore"};
 void addEdges(int arr[][V], int i , int j,int w){
    //Undirected Graph
    arr[i][j] = w;
    arr[j][i] = w;
   
}
void initialize1(int arr[][V]){
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            arr[i][j] = 0;
        }
        
    }

}

int minDistance(int dist[], bool sptSet[])
{
   
    // Initialize min value
    int min = INT_MAX, min_index;
 
    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
 
    return min_index;
}

void printSolution(int dist[],int src)
{
    cout <<"Vertex \t Distance from Source" << endl;
    for (int i = 0; i < V; i++)
       // cout  << i << " \t\t"<<dist[i]<< endl;
       	cout<<"Shortest distance from "<<ShortDistance[src]<<" to "<<ShortDistance[i]<<" -> "<<dist[i]<<endl;
}

void dijkstra(int graph[V][V], int src)
{
    int dist[V]; 
    bool sptSet[V]; 
  
    for (int i = 0; i < V; i++){
        dist[i] = INT_MAX, sptSet[i] = false;
 
    
    dist[src] = 0;
    }

    for (int count = 0; count < V - 1; count++) {
       
        int u = minDistance(dist, sptSet);
 
    
        sptSet[u] = true;
 
        for (int v = 0; v < V; v++)
 
          
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }
  
    printSolution(dist,src);
}
 

int main()
{
 
    //initialize(adjMatrix);
//adjMatrix[V][V] = {"Islamabad","Karachi","Lahore"};
initialize1(adjMatrix);
addEdges(adjMatrix,0,1,2);
addEdges(adjMatrix,1,2,1);
addEdges(adjMatrix,0,2,4);
cout << "Dijkstra\n";
dijkstra(adjMatrix, 0);
 
    return 0;
}
 
