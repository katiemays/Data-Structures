#include "ItemType.h"
#include "DirectedWeightedGraphType.h"
#include <stdlib.h>

int main() {
    DirectedWeightedGraphType graph;
    ItemType x, y;
    VertexType v, z;
    char point = '1';
    char point2;
    int index;

    // cout << graph; // overload << operator 
    for (int i=0; i<7; i++)
    {
       x.Initialize(point);
       v.InitializeVertex(x);
      
        if (!graph.IsFull())
 	   graph.AddVertex(v);
	else
	{
	   cout << "Vertex array is full, vertex " << i << " was not added" << endl;
	   break;
	}
       point++;
    }

    graph.FillEdges();

    // adding edges for vertex[0] 
    graph.AddEdge(graph.GetVertex(0), graph.GetVertex(1), 100);
    graph.AddEdge(graph.GetVertex(0), graph.GetVertex(2), 50); 
    graph.AddEdge(graph.GetVertex(0), graph.GetVertex(3), 150); 

    // adding edges for vertex[2]
    graph.AddEdge(graph.GetVertex(2), graph.GetVertex(0), 10); 
    graph.AddEdge(graph.GetVertex(2), graph.GetVertex(6), 50); 

    // adding edges for vertex[3]
    graph.AddEdge(graph.GetVertex(3), graph.GetVertex(4), 200);
    graph.AddEdge(graph.GetVertex(3), graph.GetVertex(5), 100);
 
    // adding edges for vertex[4]
    graph.AddEdge(graph.GetVertex(4), graph.GetVertex(5), 100); 

    // adding edges for vertex[6]
    graph.AddEdge(graph.GetVertex(6), graph.GetVertex(5), 30); 

    graph.PrintVertexArray();

    cout << "Check to see if a vertex exists: ";
    cin >> point;
    x.Initialize(point);
    v.InitializeVertex(x);
    if (graph.VertexExists(v))
	cout << "Yes." << endl;
    else
	cout << "No." << endl;
 
    cout << "Check to see if an edge exists, 	enter v1: ";
    cin  >> point;
    x.Initialize(point);
    v.InitializeVertex(x);
    cout << "					enter v2: ";
    cin  >> point2;
    y.Initialize(point2);
    z.InitializeVertex(y);
    if (graph.EdgeExists(v,z))
	cout << "Yes." << endl;
    else
	cout << "No." << endl;
    cout << "The weight from " << point << " to " << point2 << " is " << graph.GetWeight(v,z) << endl;

    // Breadth First Traversal 
    // ask the user what vertex they want to start at
    cout << "Which vertex would you like to start the Breadth First Traversal? ";
    cin  >> point;
    x.Initialize(point);
    v.InitializeVertex(x);
    cout << "Ok, starting with vertex " << v << "..." <<  endl;
    graph.BFT(v);    
    cout << endl;

    graph.ResetMarks();

    cout << "If the edge from 1 to 4 was deleted..." << endl;
    graph.DeleteEdge(graph.GetVertex(0), graph.GetVertex(3));
    graph.BFT(v);
    cout << endl;

    cout << "If the vertex 4 was deleted..." << endl;
    graph.DeleteVertex(graph.GetVertex(3));
    graph.PrintVertexArray();

    cout << endl;
    return 0;
}

