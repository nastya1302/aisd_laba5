#pragma once
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

namespace nestea {

	template<typename K, typename V>
	struct Pair {
		K key;
		V value;
		bool empty;
		bool deleted;

		Pair() {
			key = 0;
			value = 0;
			empty = true;
			deleted = false;
		}
		Pair(K _key, V _value) {
			key = _key;
			value = _value;
			empty = false;
			deleted = false;
		}
	}; 

	template<typename K, typename V>
	class HashTable {
	private:
		size_t size;
		size_t count;
		vector<Pair<K, V>> data;
		void clear() {
			data.clear();
			count = 0;
		}

	public:
		int hash_function(const K& key, size_t _size) {
			double A = (sqrt(5) - 1) / 2;
			double result = _size * std::fmod((key * A), 1);
			return result;
		}

		HashTable(): data(10), size(10), count(0) {}

		HashTable(size_t _size) {
			data.resize(_size);
			size = _size;
			count = 0;
		}

		HashTable(const HashTable<K, V>& other) : data(other.data), size(other.size), count(other.count) {}

		~HashTable() {
			this->clear();
		}

		HashTable<K, V>& operator=(const HashTable<K, V>& other) {
			if (this != &other) {
				data = other.data;
				size = other.size;
				count = other.count;
			}
			return *this;
		}

		void print() {
			for (const auto& pair : data)
				cout << pair.key << " : " << pair.value << "\n";
		}

		void insert(K _key, V _value) {
			if (count == size)
				throw std::invalid_argument("HashTable::The hash table is full");
			size_t index = hash_function(_key, this->size);
			Pair<K, V> element(_key, _value);
			int i = 1;
			while (data[index].empty != true) {
				index = fmod(index + i, this->size);
			}
			data[index] = element;
			count++;
		}

		size_t get_count() const {
			return count;
		}

		void insert_or_assign(K _key, V _value);
		bool contains(V _value);
		V* search(K _key) {}
		bool erase(K _key);
	};
}