#include "Graph.h"

int main(int argc, char* argv[]) {
	Graph test(argv[1]);
	test.Draw_graph("input1.dot");
	test.Kraskal_alg(argv[2]);
	test.Draw_ostav("input2.dot");
	return 0;
}