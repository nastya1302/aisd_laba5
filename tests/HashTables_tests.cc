#include <gtest/gtest.h>
#include <iostream>
#include <HashTables.h>

using namespace std;
using namespace nestea;

TEST(HashTable_tests, create_hash) {
	HashTable<int, int> ht(5);
	ht.print();
}

TEST(HashTable_tests, insert) {
	HashTable<int, int> ht(7);
	ht.insert(0, 1);
	ht.insert(0, 2);
	ht.insert(8, 3);
	ht.insert(8, 4);
	ht.insert(8, 5);
	ht.insert(2, 6);
	ht.print();
	cout << ht.get_count() << "\n";
}

TEST(HashTable_tests, equality1) {
	HashTable<int, int> ht0(10);
	ht0.insert(0, 1);
	ht0.insert(0, 2);
	ht0.insert(8, 3);
	ht0.insert(8, 4);
	ht0.insert(8, 5);
	ht0.insert(2, 6);
	HashTable<int, int> ht1 = ht0;
	cout << "Hash table 1: \n";
	ht0.print();
	cout << "Hash table 2: \n";
	ht1.print();
}

TEST(HashTable_tests, equality2) {
	HashTable<int, int> ht0;
	ht0.insert(0, 1);
	ht0.insert(0, 2);
	ht0.insert(8, 3);
	ht0.insert(8, 4);
	ht0.insert(8, 5);
	ht0.insert(2, 6);
	HashTable<int, int> ht1;
	ht1.insert(0, 1);
	ht1.insert(0, 2);
	ht1.insert(8, 3);
	ht1.insert(8, 4);
	ht1.insert(8, 5);
	ht1.insert(5, 6);
	ht1 = ht0;
	cout << "Hash table 1: \n";
	ht0.print();
	cout << "Hash table 2: \n";
	ht1.print();
}