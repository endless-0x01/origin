#include <iostream>
#include <fstream>
#include <vector>

int** get_dynamic_arr(const int vertex)
{
	int** arr = new int* [vertex];
	for (int i = 0; i < vertex; i++) {
		arr[i] = new int[vertex];
	}

	return arr;
}

void fill_arr(std::ifstream& stream, const int vertex, int** arr) {

	for (int i = 0; !stream.eof(); i++) {
		for (int j = 0; j < vertex; j++) {
			stream >> arr[i][j];
		}
	}
}

void print(const int vertex, int** arr) {

	for (int i = 0; i < vertex; i++) {
		for (int j = 0; j < vertex; j++) {
			std::cout << arr[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void dfs(int** graph, bool* visited, int v, int vertexs)
{
	std::cout << v + 1 << " ";
	visited[v] = true;
	for (int i = 0; i <= vertexs; i++)
	{
		if ((graph[v][i] != 0) && (!visited[i])) {
			dfs(graph, visited, i, vertexs);
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Ru");

	std::ifstream in("D:\\netology\\algoritm\\Graph\\input.txt");

	if (!in.is_open()) {
		std::cout << "Ошибка открытия файла.\n";
	}
	
	int vertexs{};
	in >> vertexs;

	std::cout << "Матрица смежности: \n";
	int** graph = get_dynamic_arr(vertexs);
	fill_arr(in, vertexs, graph);
	print(vertexs, graph);


	bool* visited = new bool[vertexs] {};
	int start_v{};
	std::cout << "Стартовая вершина: ";
	std::cin >> start_v;
	dfs(graph, visited, start_v - 1, vertexs);

}