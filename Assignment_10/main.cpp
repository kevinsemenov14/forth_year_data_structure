/*******************************************************************************
 * Author:  kevin semenov
 * Professor: Jerry Lebowitz
 * Class: CS1D
 * Assignment # 11
 ******************************************************************************/

#include "GraphCustom.h"

/*******************************************************************************
 * Program Description:
 *
 * This program will perform a DFS and BFS starting at Seattle.
 * Each edge will be identified as either a discovery edge or
 * back edge. It will also output the total distance traveled
 * for both DFS and BFS.
 *
 ******************************************************************************/

/*******************************************************************************
 * Function: OutputHeading
 * -----------------------------------------------------------------------------
 * Definition: Outputs the heading for the project. Outputs the programmer's
 * name(s), Professor name, Class, the assignment/lab, date completed, and
 * date due.
 * -----------------------------------------------------------------------------
 * Parameters:
 * 	none.
 ******************************************************************************/
void OutputHeading();

void OutputHeading()
{
	std::cout << "/************************************************************"
			"*******************\n";
	std::cout << "* NAME(S)        : " << "Kevin Semenov" << "\n";
	std::cout << "* PROFESSOR      : " << "Jerry Lebowitz" << "\n";
	std::cout << "* CLASS          : " << "CS1D" << "\n";
	std::cout << "* ASSIGNMENT #   : " << "11" << "\n";
	std::cout << "* DATE COMPLETED : " << "17 April, 2017" << "\n";
	std::cout << "* DATE DUE       : " << "17 April, 2017" << "\n";
	std::cout << "*************************************************************"
			"*****************/\n\n";

	std:: cout << "This program will perform a DFS and BFS starting at Seattle.\n"
			 << "Each edge will be identified as either a discovery edge or\n"
			 << "back edge. It will also output the total distance traveled\n"
			 << "for both DFS and BFS.\n\n";
}

int main()
{
	GraphCustom<std::string> cityGraph;
	int totalDist;
	int totalDist2;
	//First, output the heading.
	OutputHeading();

	//Now, insert all the cities and edges to the graph.

	std::cout << "---Inserting all the cities and their edges "
			"into the graph.---\n\n";

	//Adding all the city nodes..
	cityGraph.AddNode("Seattle");
	cityGraph.AddNode("San Francisco");
	cityGraph.AddNode("Denver");
	cityGraph.AddNode("Chicago");
	cityGraph.AddNode("Los Angeles");
	cityGraph.AddNode("Kansas City");
	cityGraph.AddNode("Boston");
	cityGraph.AddNode("New York");
	cityGraph.AddNode("Dallas");
	cityGraph.AddNode("Atlanta");
	cityGraph.AddNode("Houston");
	cityGraph.AddNode("Miami");

	//Adding all the city edges..
	cityGraph.AddEdge("Seattle", "San Francisco", 807);
	cityGraph.AddEdge("Seattle", "Denver", 1331);
	cityGraph.AddEdge("San Francisco", "Los Angeles", 381);
	cityGraph.AddEdge("Denver", "Seattle", 1331);
	cityGraph.AddEdge("Denver", "Chicago", 1003);
	cityGraph.AddEdge("Chicago", "Seattle", 2097);
	cityGraph.AddEdge("Chicago", "Boston", 983);
	cityGraph.AddEdge("Los Angeles", "Denver", 1015);
	cityGraph.AddEdge("Kansas City", "Denver", 599);
	cityGraph.AddEdge("Kansas City", "Chicago", 533);
	cityGraph.AddEdge("Kansas City", "New York", 1260);
	cityGraph.AddEdge("Kansas City", "Atlanta", 864);
	cityGraph.AddEdge("Kansas City", "Los Angeles", 1663);
	cityGraph.AddEdge("Boston", "New York", 214);
	cityGraph.AddEdge("New York", "Atlanta", 888);
	cityGraph.AddEdge("New York", "Chicago", 787);
	cityGraph.AddEdge("Dallas", "Kansas City", 496);
	cityGraph.AddEdge("Dallas", "Atlanta", 864);
	cityGraph.AddEdge("Dallas", "Los Angeles", 1435);
	cityGraph.AddEdge("Atlanta", "Miami", 661);
	cityGraph.AddEdge("Atlanta", "Kansas City", 864);
	cityGraph.AddEdge("Houston", "Dallas", 239);
	cityGraph.AddEdge("Houston", "Atlanta", 810);
	cityGraph.AddEdge("Miami", "Houston", 1187);

	//Doing the DFS algorithm.
	cityGraph.DFS();
	std::cout << std::endl;

	//Doing the BFS algorithm.
	std::cout << std::endl;
	cityGraph.BFS();
	std::cout << std::endl;

	std::cout << std::endl;
	return 0;
}
