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
			int result = _size * std::fmod((key * A), 1);
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
			while (data[index].empty != true)
				index = fmod(index + i, this->size);
			data[index] = element;
			count++;
		}

		size_t get_count() const {
			return count;
		}

		void insert_or_assign(K _key, V _value) {
			V* c = search(_key);
			if (!c)
				insert(_key, _value);
			else
				*c = _value;
		}

		bool contains(V _value) {
			for (const auto& pair : data) {
				if (pair.value == _value)
					return true;
			}
			return false;
		}

		V* search(K _key) {
			size_t index = hash_function(_key, this->size);
			size_t i = 1;
			while (data[index].empty == false || data[index].deleted == true) {
				if (data[index].key == _key)
					return &data[index].value;
				index = fmod(index + i, this->size);
			}
			return nullptr;
		}

		bool erase(K _key) {
			if (search(_key) == nullptr)
				return false;
			else {
				size_t index = hash_function(_key, this->size);
				int i = 1;
				while (data[index].key != _key) {
					index = fmod(index + i, this->size);
				}
				data[index].key = 0;
				data[index].value = 0;
				data[index].empty = true;
				data[index].deleted = true;
				this->count--;
				return true;
			}
		}

		int counts(K _key) {
			int number = 0;
			for (const auto& pair : data) {
				if (pair.key == _key && pair.empty == false)
					number++;
			}
			return number;
		}
	};
}