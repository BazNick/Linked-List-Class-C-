#include "Products.h"

using namespace std;

Inventory::Inventory()
{
	_first = NULL;
}

void Inventory::allocateNewMemoryforProduct(Inventory* product, Node p)
{
	product->_products = new Node;
	product->_products->productName = p.productName;
	product->_products->price = p.price;
	product->_products->description = p.description;

	product->_products->next = NULL;
	if (product->_first == NULL)
	{
		product->_first = product->_products;
	}
	else
	{
		Node* temp = product->_first;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = product->_products;
	}
}

void Inventory::addProduct(Inventory* product)
{
	while (true)
	{
		Node p;

		cin.ignore();
		cout << "Enter name of product (to exit press '0'): ";
		getline(cin, p.productName);
		if (p.productName == "0")break;
		cout << "Enter price of product: ";
		cin >> p.price;
		cin.ignore();
		cout << "Enter description of product: ";
		getline(cin, p.description);

		allocateNewMemoryforProduct(product, p);
	}
}

void Inventory::displayProducts(Inventory* product)
{
	if (product->_first == NULL)
	{
		cout << "There are no products in the list\n";
	}
	Node* curr = product->_first;
	int productsCount = 0;
	while (curr != NULL)
	{
		cout << endl;
		cout << "Product " << (productsCount + 1) << ": " << curr->productName << endl;
		cout << "Price: " << curr->price << '$' << endl;
		cout << "Description: " << curr->description << endl;
		curr = curr->next;
		productsCount++;
	}
}

void Inventory::sortProducts(Inventory* product)
{
	Node* temp = product->_first;
	while (temp != NULL)
	{
		Node* temp2 = temp;
		while (temp2 != NULL)
		{
			if (temp->price > temp2->price)
			{
				swap(temp->price, temp2->price);
				swap(temp->productName, temp2->productName);
				swap(temp->description, temp2->description);
			}

			temp2 = temp2->next;
		}

		temp = temp->next;
	}
	cout << "Products has been sorted\n";
}

void Inventory::averageofPrice(Inventory* product)
{
	double sum = 0.0;
	double count = 0.0;

	Node* p = product->_first;
	while (p != NULL)
	{
		sum += p->price;
		p = p->next;
		count++;
	}
	cout << endl;
	if (sum > 0.0)
	{
		cout << "The average price of " << count << " products is:  " << (sum / count) << '$' << endl;
	}
	else
	{
		cout << "There are no product prices to display\n";
	}
}

void Inventory::deleteElements(Inventory* product)
{
	string name;
	// Если список пуст
	if (product->_first == NULL)
	{
		cout << "There are no products in the list\n";
	}
	else
	{
		cin.ignore();
		cout << "Enter name of product: ";
		getline(cin, name);
		Node* curr = product->_first;
		Node* temp = NULL;
		// Пройти список, чтобы найти продукт, который нам надо удалить
		while (curr != NULL)
		{
			if (curr->productName == name)
			{
				break;
			}
			else
			{
				temp = curr;
				curr = curr->next;
			}
		}
		// Если продукт с нужным именем не был найден
		if (curr == NULL)
		{
			cout << "Product " << name << " not found\n";
		}
		else
		{
			// Удалить первый элемент списка (удаление с начала)
			if (product->_first == curr)
			{
				product->_first = product->_first->next;
			}
			// Удалить последющие элементы (следующие за первым элементом)
			else
			{
				temp->next = curr->next;
			}
			delete curr;
			cout << "Product " << name << " was deleted\n";
		}
	}
}

void Inventory::searchElement(Inventory* product)
{
	Node* curr = product->_first;

	Node* search = NULL;
	string name;
	cin.ignore();
	cout << "Enter name of product: ";
	getline(cin, name);
	while (curr != NULL && curr->productName != name)
	{
		curr = curr->next;
	}
	if (curr != NULL)
	{
		search = curr;
		curr = curr->next;
		cout << "Product is found\n";
		cout << endl;
		cout << "Product: " << search->productName << endl;
		cout << "Price: " << search->price << '$' << endl;
		cout << "Description: " << search->description << endl;

	}
	else
	{
		cout << "Product does not found\n";
	}
}

bool Inventory::isEmpty(Inventory* product)
{
	if (product->_first == NULL)
	{
		cout << "There are no products in the list\n";
		return false;
	}
	else
	{
		sortProducts(product);
		return true;
	}
}

Inventory::~Inventory()
{
	while (_first != NULL)
	{
		_products = _first;
		_first = _first->next;
		delete _products;
	}
}