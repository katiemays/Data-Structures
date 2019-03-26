#ifndef DIRECTEDWEIGHTEDGRAPHTYPE_H
#define DIRECTEDWEIGHTEDGRAPHTYPE_H

#include <iostream>
using namespace std;

#include <queue>

#include "ItemType.h"

enum  MARK { DEFAULT, VISITED, QUEUED };

struct VertexType{
   
       ItemType item;
       MARK mark;        //default mark = DEFAULT; if visited, mark= VISITED; 
                        //if queued, mark = QUEUED;
	void InitializeVertex(ItemType i) 
	{
	   this->item = i;
	   this->mark = DEFAULT;
	}
	friend ostream &operator<<(ostream &output, const VertexType& it )
	{
      	   output<<it.item;
      	   return output;
   	}
     
};

class DirectedWeightedGraphType{

   public:

        DirectedWeightedGraphType();
        DirectedWeightedGraphType(int max);

        ~DirectedWeightedGraphType();

        bool IsEmpty() const;
	bool IsFull() const;

        void AddVertex(VertexType v);
        void AddEdge(VertexType v1, VertexType v2, int w);
  
        void DeleteVertex(VertexType v);
        void DeleteEdge(VertexType v1, VertexType v2);

        int GetWeight(VertexType v1, VertexType v2);

        bool EdgeExists(VertexType v1, VertexType v2);
        bool VertexExists(VertexType v);

        void MarkVertex(VertexType v, MARK m);//mark whether the vertex has been visited or queued

        void GetNeighbors(VertexType v, queue<VertexType>& nq);


	// NEW
	void MakeEmpty();
	VertexType GetVertex(int index);
	void FillEdges(); 
	void BFT(VertexType v);
	void PrintVertex(VertexType v);
	void PrintVertexArray() const;
	queue <VertexType> neighborQueue;
 	void ResetMarks();

   private:

        int numberOfVertices;
        int maxVertices;
        
        VertexType * vertices; //save all the vertices

        int edges[50][50];   //save all the edges

        int IndexIs(VertexType v);
};

#endif
