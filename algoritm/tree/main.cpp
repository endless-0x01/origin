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


int main()
{
	setlocale(LC_ALL, "ru");

	int arr[] = { 94, 67, 18, 44, 55, 12, 6, 42 };
	const int size = sizeof(arr) / sizeof(int);

	std::cout << "Исходный массив: ";
	for (int i = 0; i < size; i++) {
		std::cout << arr[i] << ", ";
	}
	std::cout << std::endl;

	Tree tree(arr, size);
	print_pyramid(tree);


	return 0;
}