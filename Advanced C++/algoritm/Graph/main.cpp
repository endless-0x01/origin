#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

int** get_dynamic_arr(const int vertex)
{
	int** arr = new int* [vertex];
	for (int i = 0; i < vertex; i++) {
		arr[i] = new int[vertex];
	}

	return arr;
}

void fill_arr(std::ifstream& stream, const int vertex, int** arr) {

	for (int i = 0; i < vertex; i++) {
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

void bfs(const std::vector<std::vector<int>>& vec, int start_v, bool* visited)
{
	std::queue<int> q;
	q.push(start_v + 1);
	visited[0] = true;
	int last_inf{};

	for (int level = last_inf;  q.size() != vec.size(); level = last_inf)
	{
		for (int v = 0; v < vec[level].size(); v++)
		{
			if (!visited[vec[level][v] - 1])
			{
				visited[vec[level][v] - 1] = true;
				q.push(vec[level][v]);
				last_inf = q.back() - 1;
			}
		}
	}
	std::cout << "Порядок обхода вершин: \n";
	while (!q.empty()) {
		std::cout << q.front() << " ";
		q.pop();
	}
}

enum class bypassmode {
	in_wide = 1,
	in_depth,
	in_ograph
};

int count_ribs(int* graph, int size)
{
	int count{};
	for (int i = 0; i < size; i++)
	{
		if (graph[i]) {
			count++;
		}
	}
	return count;
}

void for_vec_func(std::vector<std::vector<int>>& vec, int** graph)
{
	int arr[] = { 1,2,3,4,5,6,7 };

	for (int i = 0; i < vec.size(); i++)
	{
		int ribs = count_ribs(graph[i], vec.size());
		for (int j = 0; j < vec.size(); j++)
		{
			if (graph[i][j] != 0)
			{
				vec[i].push_back(arr[j]);
			}
		}
		vec[i].resize(ribs);
	}
}


void ograph(int** graph, int size)
{
	std::cout << "Текстовый вид орграфа: " << std::endl;
	for (int i = 0; i < size; i++)
	{
		bool empty_g = true;
		int v = 0;
		std::cout << i + 1 << ": ";
		for (int j = 0; j < size; j++)
		{
			v++;
			if (graph[i][j] == 1) {
				std::cout << v << " ";
				empty_g = false;
			}
		}
		if (empty_g) {
			std::cout << "нет" << std::endl;
		}
		else {
			std::cout << "\n";
		}
	}
}



void print_v(std::vector<std::vector<int>> vec)
{
	for (auto& t : vec) {
		for (auto& i : t) {
			std::cout << i << " ";
		}
		std::cout << "\n";
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

	std::cout << "Выберите режим обхода 1 - в ширину, 2 - в глубину, 3 - орграф: ";
	int mode{};
	std::cin >> mode;
	switch (static_cast<bypassmode>(mode))
	{
	case bypassmode::in_wide: {
		std::vector<std::vector<int>> vec;
		vec.resize(vertexs);
		for_vec_func(vec, graph);
		bfs(vec, start_v - 1, visited);
		break;
	}
	case bypassmode::in_depth: {
		int start_v{};
		std::cout << "Стартовая вершина: ";
		std::cin >> start_v;
		dfs(graph, visited, start_v - 1, vertexs);
		break;
	}
	case bypassmode::in_ograph:
		ograph(graph, vertexs);
		break;
	default:
		break;
	}


}