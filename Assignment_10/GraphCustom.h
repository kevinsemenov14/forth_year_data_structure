#ifndef GRAPHCUSTOM_H_
#define GRAPHCUSTOM_H_

#include <queue>
#include <map>
#include <iostream>
#include <iomanip>
#include <tuple>

enum EdgeType
{
	EDGE_TYPE_NONE,
	EDGE_TYPE_DESTINATION,
	EDGE_TYPE_CROSS,
};

template<class Type>
class GraphCustom
{

	typedef std::tuple<Type, double, EdgeType> EdgeTuple;

	class Comparator
	{
		public:

		bool operator()(EdgeTuple tuple1, EdgeTuple tuple2)
		{
			if(std::get<1>(tuple1) >= std::get<1>(tuple2))
			{
				return true;
			}
			return false;
		}
	};

	typedef std::priority_queue<EdgeTuple, std::vector<EdgeTuple>, Comparator> EdgeQueue;

	struct NodeData
	{
		bool traversed = false;
		unsigned int level = 1;
		std::string name;
		EdgeQueue* pEdgeQueue = nullptr;
	};

	typedef std::map<
				Type,
				NodeData*>
			GraphData;

	typedef std::pair<Type, NodeData*> GraphDataPair;

public:
	//Constructor
	GraphCustom()
	{

	}

	//Virtual destructor
	virtual ~GraphCustom()
	{

	}

	/**************************************************************************
	 *AddNode adds an node to the map
	 *
	 **************************************************************************/
	void AddNode(Type node)
	{
		std::cout << "Adding node: " << node << "\n";

		if(mGraphData.find(node) == mGraphData.end())
		{
			NodeData* pNodeData = new NodeData;

			pNodeData->pEdgeQueue = new EdgeQueue;
			pNodeData->name = node;

			mGraphData.insert(GraphDataPair(node, pNodeData));

			std::cout << "Node successfully added.\n\n";
		}
		else
		{
			std::cout << "Node already exists!\n\n";
		}
	}

	/**************************************************************************
	 *AddEdge adds a adge to the list and to the map
	 *
	 **************************************************************************/
	void AddEdge(Type origin, Type dest, double value)
	{
		std::cout << "Adding edge: \norigin: " << origin << "\ndestination: " <<
				dest << "\n";

		if(origin != dest)
		{
			if(mGraphData.find(origin) != mGraphData.end())
			{
				if(mGraphData.find(dest) != mGraphData.end())
				{
					EdgeQueue* pCurEdgeQueue = mGraphData.find(origin)->second->pEdgeQueue;
					EdgeQueue curEdgeQueueCopy = *pCurEdgeQueue;

					bool found = false;

					while(!curEdgeQueueCopy.empty())
					{
						if(std::get<0>(curEdgeQueueCopy.top()) == dest)
						{
							found = true;
							break;
						}

						curEdgeQueueCopy.pop();
					}

					if(found)
					{
						std::cout << "Edge already exists!.\n\n";
					}
					else
					{
						mGraphData.find(origin)->second->pEdgeQueue->
								push(EdgeTuple(dest, value, EDGE_TYPE_NONE));

						std::cout << "Edge successfully added.\n\n";
					}
				}
				else
				{
					std::cout << "The destination node does not exist!\n\n";
				}
			}
			else
			{
				std::cout << "The origin node does not exist!\n\n";
			}
		}
		else
		{
			std::cout << "You cannot insert an origin and a dest with the "
					"same name!\n\n";
		}
	}

	/**************************************************************************
	 *RemoveNode removes the node from the map
	 *
	 **************************************************************************/
	void RemoveNode(Type node)
	{
		std::cout << "Attempting to remove a node.\n";

		if(mGraphData.find(node) != mGraphData.end())
		{
			delete mGraphData.find(node)->second->pEdgeQueue;
			delete mGraphData.find(node)->second;

			mGraphData.erase(node);

			for(typename GraphData::iterator iter = mGraphData.begin();
							iter != mGraphData.end();
							iter++)
			{
				EdgeQueue curEdgeQueueCopy = *iter->second->pEdgeQueue;
				EdgeQueue* pNewEdgeQueue = new EdgeQueue;

				delete iter->second->pEdgeQueue;

				while(!curEdgeQueueCopy.empty())
				{
					if(std::get<0>(curEdgeQueueCopy.top()) != node)
					{
						pNewEdgeQueue->push(curEdgeQueueCopy.top());
					}

					curEdgeQueueCopy.pop();
				}

				iter->second->pEdgeQueue = pNewEdgeQueue;
			}

			std::cout << "Node removal successful.\n\n";
		}
		else
		{
			std::cout << "The node does not exist.\n\n";
		}
	}

	/**************************************************************************
	 * RemoveEdge paints the edge so that it will not be travled on agian
	 *
	 **************************************************************************/
	void RemoveEdge(Type origin, Type dest)
	{
		std::cout << "Attempting to remove an edge.\n";

		if(mGraphData.find(origin) != mGraphData.end())
		{
			if(mGraphData.find(dest) != mGraphData.end())
			{
				EdgeQueue curEdgeQueueCopy = *mGraphData.find(origin)->second->pEdgeQueue;
				EdgeQueue* pNewEdgeQueue = new EdgeQueue;

				delete mGraphData.find(origin)->second->pEdgeQueue;

				while(!curEdgeQueueCopy.empty())
				{
					if(std::get<0>(curEdgeQueueCopy.top()) != dest)
					{
						pNewEdgeQueue->push(curEdgeQueueCopy.top());
					}

					curEdgeQueueCopy.pop();
				}

				mGraphData.find(origin)->second->pEdgeQueue = pNewEdgeQueue;

				std::cout << "Edge deletion successful!\n\n";
			}
			else
			{
				std::cout << "The destination node does not exist!\n\n";
			}
		}
		else
		{
			std::cout << "The origin node does not exist!\n\n";
		}
	}

	/**************************************************************************
	 * FindClosestEdge fines the closes edge from the parent node and marks it
	 * true so it will not go back into it
	 *
	 **************************************************************************/
	void FindClosestEdge(Type curEdgeKey)
	{
		EdgeQueue curEdgeQueueCopy2 = *mGraphData.find(curEdgeKey)->second->pEdgeQueue;

		mGraphData.find(curEdgeKey)->second->traversed = true;

		while(!curEdgeQueueCopy2.empty())
		{
			EdgeTuple curEdge = curEdgeQueueCopy2.top();

			curEdgeQueueCopy2.pop();

			if(std::get<2>(curEdge) != EDGE_TYPE_DESTINATION &&
					mGraphData.find(std::get<0>(curEdge))->second->traversed == false)
			{
				std::get<2>(curEdge) = EDGE_TYPE_DESTINATION;

				EdgeQueue curEdgeQueueCopy = *mGraphData.find(curEdgeKey)->second->pEdgeQueue;
				EdgeQueue* newEdgeQueue = new EdgeQueue;

				delete mGraphData.find(curEdgeKey)->second->pEdgeQueue;

				while(!curEdgeQueueCopy.empty())
				{
					if(std::get<0>(curEdgeQueueCopy.top()) == std::get<0>(curEdge))
					{
						newEdgeQueue->push(curEdge);
					}
					else
					{
						newEdgeQueue->push(curEdgeQueueCopy.top());
					}

					curEdgeQueueCopy.pop();
				}

				mGraphData.find(curEdgeKey)->second->pEdgeQueue = newEdgeQueue;

				FindClosestEdge(std::get<0>(curEdge));
			}
		}
	}

	/**************************************************************************
	 *DFS depth first  searches all the map values and stores them into a queue
	 *
	 **************************************************************************/
	void DFS()
	{
		std::cout << "Starting Depth First Search (DFS). \n";
		int totalDist;
		//First, clear the edge paintings.
		PaintClear();

		//Find the path.
                FindClosestEdge("Atlanta");

		std::cout << "\nPath has been found! Outputting edges..\n";

		//Output destination edges:
		std::cout << "\n---Outputting the destination edges..--- \n";
		for(typename GraphData::iterator iter = mGraphData.begin();
						iter != mGraphData.end();
						iter++)
		{
			EdgeQueue curEdgeQueueCopy = *iter->second->pEdgeQueue;

			while(!curEdgeQueueCopy.empty())
			{
				if(std::get<2>(curEdgeQueueCopy.top()) == EDGE_TYPE_DESTINATION)
				{
					std::cout << std::setw(16) << std::left <<
						iter->first << " | " <<
						std::get<0>(curEdgeQueueCopy.top()) <<
						"\n";
				}

				curEdgeQueueCopy.pop();
			}
		}

		std::cout << "\n";

		//Output back edges:
		std::cout << "\n---Outputting the back edges..--- \n";
		for(typename GraphData::iterator iter = mGraphData.begin();
						iter != mGraphData.end();
						iter++)
		{
			EdgeQueue curEdgeQueueCopy = *iter->second->pEdgeQueue;

			while(!curEdgeQueueCopy.empty())
			{
				if(std::get<2>(curEdgeQueueCopy.top()) == EDGE_TYPE_NONE)
				{
					std::cout << std::setw(16);
					std::cout <<
						iter->first << " | " <<
						std::get<0>(curEdgeQueueCopy.top()) <<
						"\n";
				}

				curEdgeQueueCopy.pop();
			}
		}
		std::cout << "total distance: " << totalDist;
		std::cout << "\n\n";
	}

	/**************************************************************************
	 *BFS -breath first searches through the map and stores values into a queue
	 *
	 **************************************************************************/
	void BFS()
	{
                NodeData* pStartingNode = mGraphData.find("Atlanta")->second;
                int totalDist2;
		pStartingNode->level = 1;

		std::cout << "\nStarting Breadth First Search (DFS). \n";

		PaintClear();

		FindChildren(pStartingNode);

		FindCrossEdges();

		std::cout << "\nPerforming the BFS and outputting the nodes found..\n";

		//Output destination edges:
		std::cout << "---Outputting the destination edges..--- \n";
		for(typename GraphData::iterator iter = mGraphData.begin();
						iter != mGraphData.end();
						iter++)
		{
			EdgeQueue curEdgeQueueCopy = *iter->second->pEdgeQueue;

			while(!curEdgeQueueCopy.empty())
			{
				if(std::get<2>(curEdgeQueueCopy.top()) == EDGE_TYPE_DESTINATION)
				{
					std::cout << std::setw(16) << std::left <<
						iter->first << " | " <<
						std::get<0>(curEdgeQueueCopy.top()) <<
						"\n";
				}

				curEdgeQueueCopy.pop();
			}
		}

		std::cout << "\n";

		//Output cross edges:
		std::cout << "\n---Outputting the cross edges..--- \n";
		for(typename GraphData::iterator iter = mGraphData.begin();
						iter != mGraphData.end();
						iter++)
		{
			EdgeQueue curEdgeQueueCopy = *iter->second->pEdgeQueue;

			while(!curEdgeQueueCopy.empty())
			{
				if(std::get<2>(curEdgeQueueCopy.top()) == EDGE_TYPE_CROSS)
				{
					std::cout << std::setw(16);
					std::cout <<
						iter->first << " | " <<
						std::get<0>(curEdgeQueueCopy.top()) <<
						"\n";
				}

				curEdgeQueueCopy.pop();
			}
		}
		std::cout << "total distance: " << totalDist2;
	}

	/**************************************************************************
	 *Clear will be used in clear print. clears text from the screen
	 *
	 **************************************************************************/
	void Clear()
	{
		std::cout << "Clearing the whole graph..\n";

		for(typename GraphData::iterator iter = mGraphData.begin();
				iter != mGraphData.end();
				iter++)
		{
			delete iter->second->pEdgeQueue;
		}

		mGraphData.clear();

		std::cout << "Graph clearing successful!\n\n";
	}

private:

	/**************************************************************************
	 *PaintClear - clears the output on the screen
	 *
	 **************************************************************************/
	void PaintClear()
	{
		std::cout << "Re-painting the graph's edges to none-types..\n";
		for(typename GraphData::iterator iter = mGraphData.begin();
				iter != mGraphData.end();
				iter++)
		{
			EdgeQueue curEdgeQueueCopy = *iter->second->pEdgeQueue;
			EdgeQueue* pNewEdgeQueue = new EdgeQueue;

			delete iter->second->pEdgeQueue;
			iter->second->traversed = false;

			while(!curEdgeQueueCopy.empty())
			{
				EdgeTuple curEdgeTuple = curEdgeQueueCopy.top();

				std::get<2>(curEdgeTuple) = EDGE_TYPE_NONE;

				pNewEdgeQueue->push(curEdgeTuple);

				curEdgeQueueCopy.pop();
			}

			iter->second->pEdgeQueue = pNewEdgeQueue;
		}
	}

	/**************************************************************************
	 *FindChildren - finds the children of the starting city of the map and
	 * stroes it into a queue
	 *
	 **************************************************************************/
	void FindChildren(NodeData* currentNode)
	{
		EdgeQueue curEdgeQueueCopy = *currentNode->pEdgeQueue;

		if(!BFSNodes.empty())
		{
			BFSNodes.pop();
		}

		currentNode->traversed = true;

		while(!curEdgeQueueCopy.empty())
		{
			if(!mGraphData.find(std::get<0>(curEdgeQueueCopy.top()))->second->traversed)
			{
				EdgeTuple curEdge = curEdgeQueueCopy.top();
				NodeData* pNextNode = mGraphData.find(std::get<0>(curEdgeQueueCopy.top()))->second;

				pNextNode->traversed = true;
				pNextNode->level = currentNode->level + 1;

				BFSNodes.push(pNextNode);

				std::get<2>(curEdge) = EDGE_TYPE_DESTINATION;

				EdgeQueue curEdgeQueueCopy2 = *currentNode->pEdgeQueue;
				EdgeQueue* newEdgeQueue = new EdgeQueue;

				delete currentNode->pEdgeQueue;

				while(!curEdgeQueueCopy2.empty())
				{
					if(std::get<0>(curEdgeQueueCopy2.top()) == std::get<0>(curEdge))
					{
						newEdgeQueue->push(curEdge);
					}
					else
					{
						newEdgeQueue->push(curEdgeQueueCopy2.top());
					}

					curEdgeQueueCopy2.pop();
				}

				currentNode->pEdgeQueue = newEdgeQueue;
			}

			curEdgeQueueCopy.pop();
		}

		std::cout << "Level: " << currentNode->level << " " <<
				currentNode->name << "\n";

		if(!BFSNodes.empty())
		{
			FindChildren(BFSNodes.front());
		}
	}

	/**************************************************************************
	 *FindCrossEdges - finds all cross edges inside the map and stores them into
	 * a  queue
	 *
	 **************************************************************************/
	void FindCrossEdges()
	{
		//Iterate through every node in the
		for(typename GraphData::iterator iter = mGraphData.begin();
				iter != mGraphData.end();
				iter++)
		{
			NodeData* pCurNode = iter->second;
			EdgeQueue edgeQueueCopy = *pCurNode->pEdgeQueue;
			EdgeQueue* newEdgeQueue = new EdgeQueue;

			delete pCurNode->pEdgeQueue;

			while(!edgeQueueCopy.empty())
			{
				EdgeTuple curEdge = edgeQueueCopy.top();

				edgeQueueCopy.pop();

				//A cross edge was found if the levels match.
				if(pCurNode->level == mGraphData.find(std::get<0>(curEdge))->second->level)
				{
					std::get<2>(curEdge) = EDGE_TYPE_CROSS;
				}

				newEdgeQueue->push(curEdge);
			}

			pCurNode->pEdgeQueue = newEdgeQueue;
		}
	}

private:
	GraphData mGraphData; // a map
	std::queue<NodeData*> BFSNodes; // normal queue
};

#endif /* GRAPHCUSTOM_H_ */
