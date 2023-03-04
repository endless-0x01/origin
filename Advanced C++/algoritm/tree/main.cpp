#include <iostream>


struct Tree
{
private:
	int* data;
	int size;
public:
	Tree(int* arr, int size)
	{
		this->size = size;
		data = new int[this->size];
		for (int i = 0; i < size; i++)
		{
			data[i] = arr[i];
		}
	}

	~Tree() {
		delete[] data;
		data = nullptr;
	}
	const int get_size() {
		return size;
	}

	int root() {
		return data[0];
	}

	int from_index(int index) {
		return data[index];
	}

	int left_index(int parent_index) {
		return 2 * parent_index + 1;
	}

	int right_index(int parent_index) {
		return 2 * parent_index + 2;
	}

	int parent_index(int childe_index) {
		return (childe_index - 1) / 2;
	}

	bool chec_next_element(int index)
	{
		for (int i = 0; i < size; i++)
		{
			if (data[index] == data[i]) {
				return true;
			}
		}
		return false;
	}
};

void print_pyramid(Tree& tree) {
	
	std::cout << "Пирамида: " << std::endl;
	for (int i = 0, level = 1; i < tree.get_size(); i++, level++)
	{
		if (i == 0) {
			std::cout << i << " root " << tree.root() << std::endl;
		}

		std::cout << level << " left(" << tree.from_index(tree.parent_index(tree.left_index(i))) << ") " 
			<< tree.from_index(tree.left_index(i))	<< std::endl;

		if ((tree.from_index(tree.left_index(i)) == tree.from_index(tree.get_size() - 1)))
			break;

		std::cout << level << " right(" << tree.from_index(tree.parent_index(tree.right_index(i))) << ") "
			<< tree.from_index(tree.right_index(i)) << std::endl;

		if (tree.from_index(tree.right_index(i)) == tree.from_index(tree.get_size() - 1))
			break;
	
	}

}


void traver_tree(Tree& tree, const int size)
{
	int index{};
	int level = 0;

	std::cout << "Вы находитесь здесь: " <<
		 index << " root " << tree.root() << std::endl;

	bool end_tree = false;
	while (true)
	{

		std::string user_ch;
		std::cout << "Введите команду: ";
		std::cin >> user_ch;

		if (user_ch == "exit") {
			return;
		}
		else if (user_ch == "left")
		{
			if (tree.chec_next_element(tree.left_index(index))) {
				level++;
				std::cout << "OK" << std::endl;
				std::cout << "Вы находитесь здесь: ";
				std::cout << level << " left(" << tree.from_index(tree.parent_index(tree.left_index(index))) << ") "
					<< tree.from_index(tree.left_index(index)) << std::endl;
				index = tree.left_index(index);
			}
			else {
				std::cout << "Ошибка! Отсутствует правый потомок" << std::endl;
				continue;
			}
		}
		else if (user_ch == "right")
		{

			if (tree.chec_next_element(tree.right_index(index))) {
				level++;
				std::cout << "OK" << std::endl;
				std::cout << "Вы находитесь здесь: ";
				std::cout << level << " right(" << tree.from_index(tree.parent_index(tree.right_index(index))) << ") "
					<< tree.from_index(tree.right_index(index)) << std::endl;
				index = tree.right_index(index);
			}
			else {
				std::cout << "Ошибка! Отсутствует правый потомок" << std::endl;
				continue;
			}	

		}
		else if (user_ch == "up")
		{
			if (end_tree)
			{
				std::cout << "Ошибка! Отсутствует родитель" << std::endl;
			}
			else if (tree.from_index(tree.parent_index(index)) == tree.root()) {
				level = 0;
				std::cout << level << " root " << tree.root() << std::endl;
				end_tree = true;
			}
			else {
				--level;
				std::cout << "OK" << std::endl;
				index = tree.parent_index(index);
				std::cout << level << " right (" << tree.from_index(tree.parent_index(index)) << ") " << tree.from_index(index) << std::endl;
			}
		}
		else
		{
			std::cout << "Такой команды нет, всего доброго!" << std::endl;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "ru");

	int arr[] = { 1, 3 ,6, 5 ,9, 8 };
	const int size = sizeof(arr) / sizeof(int);

	std::cout << "Исходный массив: ";
	for (int i = 0; i < size; i++) {
		std::cout << arr[i] << ", ";
	}
	std::cout << std::endl;

	Tree tree(arr, size);
	print_pyramid(tree);
	traver_tree(tree, size);

	return 0;
}