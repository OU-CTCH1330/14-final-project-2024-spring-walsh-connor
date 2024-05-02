#include <iostream>

#include "../domain/inventory.h"

using namespace ctch1330;

int main()
{
	Inventory inventory;
	std::string output = inventory.GetInventory();
	std::cout << output << std::endl;
	return 0;
}

