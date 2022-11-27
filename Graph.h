#include <vector>
#include <string>
#ifndef GRAPH_H
#define GRAPH_H
struct Edge {
	int vertex_1;
	int vertex_2;
	int weight;
	int check;
};
class Graph {
private:
	int number_of_vertexes;
	int number_of_edges;
	int price = 0;
	std::vector<std::vector<Edge>> edges;
	std::vector<int> parent;
public:
	Graph(std::string EnStr);
	void Draw_graph(std::string filename);
	void Kraskal_alg(std::string ExStr);
	void Draw_ostav(std::string filename);
};
#endif
