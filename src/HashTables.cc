#include <iostream>
#include <vector>
#include <random>
#include <HashTables.h>

using namespace std;
using namespace nestea;

int random_value(int from, int to) {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> segment(from, to);
	return segment(gen);
}

HashTable<int, int> count_elements(int *mas, size_t size_mas, int from, int to) {
	HashTable<int, int> elements(size_mas);
	for (int i = 0; i < size_mas; i++) {
		elements.insert(mas[i], 0);
	}
	vector<int> copy_elements;
	for (int i = from; i < to; i++) {
		size_t count = elements.counts(i);
		if (count > 1) {
			copy_elements.push_back(i);
			copy_elements.push_back(count);
		}
	}
	HashTable<int, int> hash_copy_elements(copy_elements.size() / 2);
	for (int i = 0; i < copy_elements.size(); i += 2) {
		hash_copy_elements.insert(copy_elements[i], copy_elements[i + 1]);
	}
	return hash_copy_elements;
}

int main() {
	int mas[10];
	size_t size_mas = 10;
	int from = 0;
	int to = 10;
	for (int i = 0; i < size_mas; i++)
		mas[i] = random_value(from, to);
	for (const auto& i : mas)
		cout << i << " ";
	cout << "\n";
	HashTable<int, int> hash_copy_elements = count_elements(mas, size_mas, from, to);
	cout << "\n";
	hash_copy_elements.print();
	return 0;
}