#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>

int** get_ram(int size_ram)
{
	int** graph = static_cast<int**>(malloc(size_ram * sizeof(int*)));
	for (int index = 0; index < size_ram; index++) {
			graph[index] = static_cast<int*>(malloc(size_ram * sizeof(int)));
	}

	return graph;
}

void fill_array_of_adjacencies(std::ifstream& in,int** graph, const int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			in >> graph[i][j];
		}
	}
}

void print(int** graph,int size) {
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			std::cout << graph[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void free_object(int** graph)
{
	int size = sizeof(int**) - 1;
	for (int index = 0; index < size; index++)
	{
		free(graph[index]);
	}

	int t = 0;
	free(graph);
}

int index = 0;
void dfs(int** graph, bool* visited, int v, int size, int* order)
{
	visited[v] = true;
	for (int i = 0; i < size; i++)
	{
		if (graph[v][i] != 0 && !visited[i]) {
			dfs(graph, visited, i, size, order);
		}
	}
	order[index++] = v + 1;
}

void task_first_show(int** graph, int vertex)
{
	for (int i = 0; i < vertex; i++)
	{
		bool empty = true;
		std::cout << i << ": ";
		for (int j = 0; j < vertex; j++)
		{
			if (graph[i][j] != 0) {
				std::cout << j + 1 << " ";
				empty = false;
			}
		}
		if (empty)
			std::cout << "no" ;
		std::cout << "\n";
	}
}

int main()
{
	std::ifstream in("D:\\netology\\algoritm\\oGraph\\in.txt");
	if (!in.is_open()) {
		std::cout << "File could not be opened" << std::endl;
	}

	int vertexs{};
	in >> vertexs;


	//I used malloc for repeat material

	int** graph = get_ram(vertexs);
	fill_array_of_adjacencies(in, graph, vertexs);
	//print(graph, vertexs);
	std::cout << "Task #1" << std::endl;
	task_first_show(graph, vertexs);

	bool* visited = new bool[vertexs] {};



	int* order = new int[vertexs];

	int index = 0;
	for (int i = 0; i < vertexs; i++) {
		if (!visited[i]) {
			dfs(graph, visited, i, vertexs, order);
		}
	}


	std::cout << "\n\n" << " Task #2" << std::endl;

	std::reverse(&order[0], &order[vertexs]);
	for (int i = 0; i < vertexs; i++) {
		std::cout << order[i] << " ";
	}




	delete[] order;
	delete[] visited;
	free_object(graph);

	return 0;
}