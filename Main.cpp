/* 
 Write the Linked List implementation from last week in terms of classes instead of function
 and structures.
*/

#include <iostream>
#include "Products.h"

using namespace std;

int main()
{
	
		cout << " ----------------- Welcome to NT shop! -----------------\n\n";

		cout << "To add new product press  *1*\n";
		cout << "To sort products press  *2*\n";
		cout << "To display products press  *3*\n";
		cout << "To display average of product prices press  *4*\n";
		cout << "To search product press  *5*\n";
		cout << "To remove product press  *6*\n";
		cout << "Go to main menu  *7*\n\n";
		cout << "To exit press '0'\n";

		int choice = 0;
		Inventory inventory;

		while (true)
		{
			cin >> choice;
			switch (choice)
			{
			case 1: inventory.addProduct(&inventory);
				break;
			case 2: inventory.isEmpty(&inventory);
				break;
			case 3: inventory.displayProducts(&inventory);
				break;
			case 4: inventory.averageofPrice(&inventory);
				break;
			case 5: inventory.searchElement(&inventory);
				break;
			case 6: inventory.deleteElements(&inventory);
				break;
			case 7: cout << "To add new product press  *1*\n";
				cout << "To sort products press  *2*\n";
				cout << "To display products press  *3*\n";
				cout << "To display average of product prices press  *4*\n";
				cout << "To search product press  *5*\n";
				cout << "To remove product press  *6*\n";
				break;
			default: cout << "Goodbye!\n====== We hope to see you again soon! =) ======\n";
				cin.ignore();
				cin.get();
				return 0;
			}
			cout << endl;
			cout << "Go to main menu  *7* (press '0' to exit)\n";
		}

	cin.get();
	return 0;
}