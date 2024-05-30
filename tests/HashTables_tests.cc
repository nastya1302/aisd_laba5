#include <gtest/gtest.h>
#include <iostream>
#include <HashTables.h>

using namespace std;
using namespace nestea;

TEST(HashTable_tests, create_hash) {
	HashTable<int, int> ht;
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

TEST(HashTable_tests, deleted) {
	HashTable<int, int> ht(7);
	ht.insert(0, 1);
	ht.insert(1, 2);
	ht.insert(2, 3);
	ht.insert(3, 4);
	ht.insert(4, 5);
	ht.insert(5, 6);
	ht.erase(1);
	ht.print();
	cout << ht.get_count() << "\n";
}

TEST(HashTable_tests, search_elem) {
	HashTable<int, int> ht(7);
	ht.insert(0, 1);
	ht.insert(1, 2);
	ht.insert(2, 3);
	ht.insert(3, 4);
	ht.insert(4, 5);
	ht.insert(5, 6);
	EXPECT_FALSE(ht.search(6));
}

TEST(HashTable_tests, insert2) {
	HashTable<int, int> ht(7);
	ht.insert_or_assign(0, 1);
	ht.insert_or_assign(0, 2);
	ht.insert_or_assign(8, 3);
	ht.insert_or_assign(8, 4);
	ht.insert_or_assign(8, 5);
	ht.insert_or_assign(2, 6);
	ht.print();
	cout << ht.get_count() << "\n";
}

TEST(HashTable_tests, contains) {
	HashTable<int, int> ht(7);
	ht.insert_or_assign(0, 1);
	ht.insert_or_assign(0, 2);
	ht.insert_or_assign(8, 3);
	ht.insert_or_assign(8, 4);
	ht.insert_or_assign(8, 5);
	ht.insert_or_assign(2, 6);
	EXPECT_TRUE(ht.contains(6));
}

TEST(HashTable_tests, counts) {
	HashTable<int, int> ht(7);
	ht.insert(0, 1);
	ht.insert(0, 2);
	ht.insert(8, 3);
	ht.insert(8, 4);
	ht.insert(8, 5);
	ht.insert(2, 6);
	ht.print();
	int number = ht.counts(8);
	cout << number << "\n";
}