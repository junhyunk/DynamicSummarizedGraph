#include "Graph.h"
#include "GraphLoader.hpp"
#include "DynamicSummarization.h"
#include "Experiment.hpp"
#include "random.hpp"
#include "debug.hpp"

int main()
{
	string filename = "dataset/facebook_combined.txt";

	//memory leak üũ �ڵ�
	/*debug::memory_bomb mb;
	{
		Graph* graph = readGraph(filename);
		Graph* sm_graph = readSummarizedGraph(filename);
		delete graph;
		delete sm_graph;
	}
	mb.leakCheck();*/

	//prev test code
	/*int s, t;
	for (int i = 0; i < 1000; i++)
	{
		s = random::Int(0, 4000);
		t = random::Int(0, 4000);
		DynamicSummarization::addEdge(sm_graph, graph, s, t);
	}*/



	{
		debug::time_bomb tb;
		Graph* graph = readGraph(filename);
		Graph* sm_graph = readSummarizedGraph(filename);

		DynamicSummarization::addEdgeAndSummarize(*sm_graph, *graph, 21, 101);

		delete graph;
		delete sm_graph;
	}
	cout << endl;




	return 0;
}