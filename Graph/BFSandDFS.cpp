
#include <iostream>
using namespace std;
#define V 3
int adjMatrix[V][V];
int visited1[V];
int visited2[V];
class Queue
{
public:
    int size;
    int front;
    int rear;
    int *q;

    Queue(int sze)
    {
        front = rear = -1;
        size = sze;
        q = new int[size];
    }

    bool isFull()
    {
        if (rear == size - 1)
        {
            return true;
        }
        return false;
    }

    bool isEmpty()
    {
        if (front == -1)
        {
            return true;
        }
        return false;
    }
    void enqueue(int x)
    {
        if (isFull())
        {
            cout << "No Space Available" << endl;
            return;
        }
        else
        {
            if (front == -1 && rear == -1)
            {
                rear++;
                front++;
            }
            else
            {
                rear++;
            }
            q[rear] = x;
        }
    }

    int deqeue()
    {
        if (isEmpty())
        {
            cout << "Already empty" << endl;
            return -1;
        }
        else
        {
            int x = q[rear];
            if (rear == front)
            {
                rear = front = -1;
            }
            else
            {
                rear--;
            }
            return x;
        }
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "No record to found..." << endl;
            return;
        }
        else
        {
            for (int i = 0; i < size; i++)
            {
                cout << q[i] << endl;
            }
        }
    }
};

//Initialize the Adjacncy Matrix to zero
void initialize(int arr[][V]){
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            arr[i][j] = 0;
        }
        
    }

}
//Add Edges in the graph
void addEdges(int arr[][V], int i , int j){
    //Undirected Graph
    arr[i][j] = 1;
    arr[j][i] = 1;
}
//Diplay Adjacency Matrix
void display(int arr[][V]){
    for (int i = 0; i < V; i++)
    {
        cout<<"Vertex: " << i << " Edges: ";
        for (int j = 0; j < V; j++)
        {
            cout<< arr[i][j] << " ";
        }
        cout<<endl;
    }
    
}
// Inittializing Visited Array
// void initilaization(){
//     for (int i = 0; i < V; i++)
//     {
//         visited[i] = 0;
//     }
// }

//BFS Implememntation
void BFS(int i){
    Queue q(100);
    cout<< i << " ";
    for (int k = 0; k < V; k++)
    {
        visited1[k] = 0;
    }
    visited1[i] = 1;
    //Enqueu i for exploration
    q.enqueue(i);
    while (!q.isEmpty())
    {
        int node = q.deqeue();
        for (int j = 0; j < V; j++)
        {
            if(adjMatrix[node][j] == 1 && visited1[j] == 0){
                cout << j << " ";
                visited1[j] = 1;
                q.enqueue(j);
            }
        }
    }
    
}
void dfs(int i){
    cout << i << " ";
    visited2[i] = 1;
    for (int j = 0; j < V; j++)
    {
    	//connected to it and not visited
        if(adjMatrix[i][j] == 1 && !(visited2[j]))
        {
            dfs(j);
        }
        
    }
    
}

int main()
{   
    //Initialize the MAtrix with 0
   initialize(adjMatrix);
addEdges(adjMatrix, 0, 1);
addEdges(adjMatrix, 0, 2);
addEdges(adjMatrix, 1, 0);
addEdges(adjMatrix, 1, 2);
addEdges(adjMatrix, 2, 0);
addEdges(adjMatrix, 2, 1);
    cout<< "BFS: ";
    BFS(0);
    cout<< endl;
    cout << "DFS: ";
    dfs(0);
    cout<< endl;
    display(adjMatrix);
    return 0;
}
