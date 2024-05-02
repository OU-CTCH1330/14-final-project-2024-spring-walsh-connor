#include <iostream>
#include <string>
#include "contact_lib.cpp"

using namespace std;

int main()
{
	string menu;

	printMenu();
	cin >> menu;
	while (menu != "5")
	{
		if(menu == "1")
		{
			AddContact(contact_list);
			break;
		}
		else if(menu == "2")
		{
			RemoveContact(contact_list);
			break;
		}
		else if(menu == "3")
		{
			DisplayContacts(contact_list);
			break;
		}
		else if(menu == "4") 
		{
			cout << "Exiting..." << endl;
			exit(0);	
		}
		else
		{
			cout << "Invalid user selection" << endl;
			WaitForUser();
			break;
		}
	}
	return 0;
}

