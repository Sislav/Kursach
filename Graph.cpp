#include "Graph.h"
#include <iostream>
#include <cassert>
#include <functional>
#include <fstream>
using namespace std;
Graph::Graph(string EnStr) {
	edges.resize(100000);
	ifstream in;
	in.open(EnStr);
	if (in.is_open()) {
		char* znach = new char[100];
		while (!in.eof()) {
			char* end;
			in.getline(znach, 100);
			long v1, v2, w;
			v1 = strtol(znach, &end, 10);
			v2 = strtol(end, &end, 10);
			w = strtol(end, &end, 10);
			edges[w].push_back(Edge{ v1, v2, w, 0 });

		}
		delete[] znach;
	}
	else {
		cout << "File is not open";
		exit(-1);
	}
	in.close();
	number_of_vertexes = edges[0][0].vertex_1;
	number_of_edges= edges[0][0].vertex_2;
	auto it = edges.begin();
	edges.erase(it);
	parent.resize(1 + number_of_vertexes, -1);
}

void Graph::Draw_graph(string filename) {
	ofstream out;
	out.open(filename);
	if (out.is_open()) {
		out << "graph ER { ";
		for (auto& it : edges) {
			for (auto& it1 : it) {
				if (!it.empty()) {
					if (it1.check == 0) {
						out << "\" " << it1.vertex_1 << " \" -- \" " << it1.vertex_2 << " \" " << "[label = " << it1.weight << "]; ";
					}
					else {
						out << "\" " << it1.vertex_1 << " \" -- \" " << it1.vertex_2 << " \" " << "[label = " << it1.weight << " , color = green]; ";
					}
				}
			}
		}
	}
    else {
        cout << "File is not open";
        exit(-1);
    }
	out << "}";
	out.close();
	cout << "\x1B[32mFINISHED!\033[0m\t" << endl;
}

void Graph::Kraskal_alg(string ExStr) {
    function<int(int)> getRoot = [&](int v) 
    {
        if (parent[v] < 0)
        {
            return v;
        }
        else
        {
            int root = getRoot(parent[v]);
            parent[v] = root; 
            return root;
        }
    };
    function<bool(int, int)> join = [&](int a, int b)
    {
        a = getRoot(a);
        b = getRoot(b);
        if (a == b)
        {
            return false;
        }
        assert(parent[a] < 0);
        assert(parent[b] < 0);
        if (parent[a] < parent[b])
        {
            parent[a] += parent[b];
            parent[b] = a;
        }
        else
        {
            parent[b] += parent[a];
            parent[a] = b;
        }
        return true;
    };

    ofstream out;
    out.open(ExStr);
    if (out.is_open()) {
        while (out.is_open()) {
            for (auto& list : edges)
            {
                for (Edge& e : list)
                {
                    if (join(e.vertex_1, e.vertex_2))
                    {
                        e.check = 1;
                        out << e.vertex_1 << " " << e.vertex_2 << " " << endl;
                        price += e.weight;
                    }
                }
            }
            out << "The answer is: " << price << endl;
            out.close();
        }
    }
    else {
        cout << "File is not open";
        exit(-1);
    }

}

void Graph::Draw_ostav(string filename) {
    Draw_graph(filename);
}
