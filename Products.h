#pragma once
#ifndef PRODUCTS_H
#define PRODUCTS_H

#include <iostream>
#include <string>

using namespace std;

struct Node
{
	string productName;
	double price;
	string description;

	Node* next;
};

class Inventory
{
	Node* _first;
	Node* _products;

public:

	Inventory();
	~Inventory();

	void displayProducts(Inventory* product);
	void allocateNewMemoryforProduct(Inventory* product, Node p);
	void addProduct(Inventory* product);
	void sortProducts(Inventory* product);
	void averageofPrice(Inventory* product);
	void deleteElements(Inventory* product);
	void searchElement(Inventory* product);
	bool isEmpty(Inventory* product);
};


#endif