<<<<<<< HEAD
ï»¿#include <iostream>
=======
#include <iostream>
>>>>>>> e84f42f40528f8d5014c3d70661dc0477122dab7
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
<<<<<<< HEAD
		std::cout << "ĞÑˆĞ¸Ğ±ĞºĞ° Ğ¾Ñ‚ĞºÑ€Ñ‹Ñ‚Ğ¸Ñ Ñ„Ğ°Ğ¹Ğ»Ğ°.\n";
=======
		std::cout << "Îøèáêà îòêğûòèÿ ôàéëà.\n";
>>>>>>> e84f42f40528f8d5014c3d70661dc0477122dab7
	}
	
	int vertexs{};
	in >> vertexs;

<<<<<<< HEAD
	std::cout << "ĞœĞ°Ñ‚Ñ€Ğ¸Ñ†Ğ° ÑĞ¼ĞµĞ¶Ğ½Ğ¾ÑÑ‚Ğ¸: \n";
=======
	std::cout << "Ìàòğèöà ñìåæíîñòè: \n";
>>>>>>> e84f42f40528f8d5014c3d70661dc0477122dab7
	int** graph = get_dynamic_arr(vertexs);
	fill_arr(in, vertexs, graph);
	print(vertexs, graph);


	bool* visited = new bool[vertexs] {};
	int start_v{};
<<<<<<< HEAD
	std::cout << "Ğ¡Ñ‚Ğ°Ñ€Ñ‚Ğ¾Ğ²Ğ°Ñ Ğ²ĞµÑ€ÑˆĞ¸Ğ½Ğ°: ";
=======
	std::cout << "Ñòàğòîâàÿ âåğøèíà: ";
>>>>>>> e84f42f40528f8d5014c3d70661dc0477122dab7
	std::cin >> start_v;
	dfs(graph, visited, start_v - 1, vertexs);

}