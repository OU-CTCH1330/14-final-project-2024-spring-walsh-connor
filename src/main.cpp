#include <iostream>
#include <string>
#include "contact.h"

using namespace ctch1330;

int main()
{
	cout << endl << "Contact Management System " << endl;

	while (true)
	{
		int user_selection = 0;
		vector<string> menu;

		try
		{
			menu = GetMenuFromDatabase();
			RenderMainMenu(menu);
		}
		catch(const exception& e)
		{
			cerr << e.what() << endl;
			continue;
		}		
		
		try
		{
			user_selection = GetUserSelection(menu.size());
		}
		catch(const runtime_error& e)
		{
			cerr << e.what() << endl;
			continue;
		}
		
		DispatchSelectedOperation(user_selection);

	}
	
	return 0;
}

