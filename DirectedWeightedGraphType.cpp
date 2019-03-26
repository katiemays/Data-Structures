/********************************************************
 * File : DirectedWeightedGraphType.cpp
 * Date : 11/24/18
 * Description : Impelementation file of DirectedWeightedGraphType class
 ********************************************************/

#include "DirectedWeightedGraphType.h"
#include <new>

DirectedWeightedGraphType::DirectedWeightedGraphType()
{
   numberOfVertices = 0;
   maxVertices = 50;
   int edges[50][50] = {-1}; //not initalialized to 0 because 0 is valid, -1 is not. array is empty
   vertices = new VertexType [maxVertices];
}

DirectedWeightedGraphType::DirectedWeightedGraphType(int max)
{
   numberOfVertices = 0;
   maxVertices = max;
   int edges[50][50] = {-1}; //not initalialized to 0 because 0 is valid, -1 is not. array is empty
   vertices = new VertexType [maxVertices];
}

DirectedWeightedGraphType::~DirectedWeightedGraphType()
{
   MakeEmpty();
}

void DirectedWeightedGraphType::MakeEmpty()
{
   delete vertices;

   numberOfVertices = 0;
   maxVertices = 50;
   int edges[50][50] = {-1}; //not initalialized to 0 because 0 is valid, -1 is not. array is empty
}

bool DirectedWeightedGraphType::IsEmpty() const
{
   return (numberOfVertices == 0);
}

bool DirectedWeightedGraphType::IsFull() const
{
   return (numberOfVertices == maxVertices);
}

void DirectedWeightedGraphType::AddVertex(VertexType v)
{
   vertices[numberOfVertices].item = v.item;
   vertices[numberOfVertices].mark = v.mark;
   numberOfVertices += 1;
}


//Add an edge from v1 to v2 with weight w. v1 and v2 must be 
////in the graph before the adding.
void DirectedWeightedGraphType::AddEdge(VertexType v1, VertexType v2, int w)
{
   int row, col;
   if (IndexIs(v1) != -1)
      row = IndexIs(v1);
   if (IndexIs(v2) != -1)
      col = IndexIs(v2);
   else
   {
      std::cout <<"Vertex is not in the graph" << endl;
      return;
   }
   edges[row][col] = w;
}
//Delete a vertex, also delete edges connecting this vertex if there are some. //The vertex must be in the graph before the deleleting.
void DirectedWeightedGraphType::DeleteVertex(VertexType v)
{
   int index = IndexIs(v);

   vertices[index].item = vertices[numberOfVertices-1].item;
   vertices[index].mark = vertices[numberOfVertices-1].mark;
 
   for (int i=0; i<numberOfVertices; i++)
   {
	// moving edges to their new place
	edges[index][i] = edges[numberOfVertices-1][i];
	edges[i][index] = edges[i][numberOfVertices-1];
	
	// reseting the moved vertex's edges
     	edges[numberOfVertices-1][i] = -1; 
	edges[i][numberOfVertices-1] = -1;
   }
   numberOfVertices--;
}

//Delete an edge from v1 to v2. The edge must be in the graph //before deleting.
void DirectedWeightedGraphType::DeleteEdge(VertexType v1, VertexType v2)
{
   int row, col;

   row = IndexIs(v1);
   col = IndexIs(v2);

   edges[row][col] = 0;
}

//Find the weight of an edge connecting v1 and v2.
int DirectedWeightedGraphType::GetWeight(VertexType v1, VertexType v2)
{
   if (VertexExists(v1) && VertexExists(v2))
   {   
   	int row, col;
   	row = IndexIs(v1);
   	col = IndexIs(v2);
     	return edges[row][col];
   }
   else
	return -1;
}

//Find whether there is a vertex v.
bool DirectedWeightedGraphType::VertexExists(VertexType v)
{
   for (int i=0; i<numberOfVertices; i++)
   {
 	if ((vertices[i].item).ComparedTo(v.item) == EQUAL)
	   return true;
   }
   return false;
}

//Find whether there is an edge from v1 to v2.
bool DirectedWeightedGraphType::EdgeExists(VertexType v1, VertexType v2)
{
   int row, col;
   row = IndexIs(v1);
   col = IndexIs(v2);

   if (edges[row][col] > 0)
     	return true;
   else
	return false;
}

int DirectedWeightedGraphType::IndexIs(VertexType v)
{
   for (int i=0; i<numberOfVertices; i++)
   {
	if ((vertices[i].item).ComparedTo(v.item) == EQUAL)
           return i;
   }
   return -1;
}

//uses index to return vertex
VertexType DirectedWeightedGraphType::GetVertex(int index)
{
   return vertices[index]; 
}

//When vertices have all been added, call this function to initialize the needed edges to 0
//private
void DirectedWeightedGraphType::FillEdges()
{
   for (int i=0; i<numberOfVertices; i++)
   {
	for (int j=0; i<numberOfVertices; i++)
	   edges[i][j] = 0;
   }
}

void DirectedWeightedGraphType::MarkVertex(VertexType v, MARK m)
{
   int index = IndexIs(v);

   vertices[index].mark = m;

   //std::cout << "Changed Vertices[" << index << "] mark to " << m << endl; 
}

void DirectedWeightedGraphType::GetNeighbors(VertexType v, queue<VertexType>& nq)
{
   // first we mark the vertex we are visiting
   MarkVertex(v, VISITED);
   int index = IndexIs(v);  
   // prevent from popping the first time  
   if (!nq.empty())
   {
	std::cout << nq.front() << " ";
	nq.pop();
   }
	
   for (int col=0; col<numberOfVertices; col++)
   {
	if (edges[index][col] == -1)
	{
	   std::cout << "Error, cannot be done" << endl;
	   return;
	}
     	else if (edges[index][col] > 0 && vertices[col].mark == DEFAULT)
 	{
	   nq.push(vertices[col]);
	   MarkVertex(vertices[col], QUEUED); // mark the neighbor vertices of the visited vertex as queued
	}
   }
  
}

void DirectedWeightedGraphType::PrintVertexArray() const 
{ 
   std::cout << "Vertices: ";
   for (int i=0; i<numberOfVertices; i++)
      	std::cout <<  vertices[i].item << " "; 
   std::cout << endl;
}

void DirectedWeightedGraphType::BFT(VertexType v)
{
   std::cout << "BFT: ";
   // Begin at one vertex, user's choice
   GetNeighbors(v, neighborQueue);
   if (VertexExists(v)) std::cout << v << " ";

   while (!neighborQueue.empty())
   {
      	GetNeighbors(neighborQueue.front(), neighborQueue);
   } 
   std::cout << endl;
}

// resets all marks to default
void DirectedWeightedGraphType::ResetMarks()
{
   for (int i=0; i<numberOfVertices; i++)
      vertices[i].mark = DEFAULT;
}
