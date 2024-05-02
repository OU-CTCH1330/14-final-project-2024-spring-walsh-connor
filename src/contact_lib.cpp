#include <iostream>
#include <limits>
#include "contact.h"
#include "contact_data.cpp"

using namespace std;

int GetUserInputWithinIntegerRange(int min, int max)
	{
		int index_of_student_selected_for_deletion = 0;
		
		bool keep_polling_user = true;
		while ( keep_polling_user )
		{
			cin.clear();
			cin.ignore();
			cin >> index_of_student_selected_for_deletion;

			const auto [is_valid, validation_message] = ValidateUserInputWithinIntegerRange(min, max, index_of_student_selected_for_deletion);

			if (!is_valid) 
			{
				cout << endl << validation_message << endl;
			}
			
			keep_polling_user = !is_valid;
		}
		return index_of_student_selected_for_deletion;
	}
tuple<bool, string> ValidateUserInputWithinIntegerRange(const int min, const int max, const int user_input)
{
	// function contains two bugs. they need to be identified and fixed for unit tests to pass. 	
	// next line would be a good place to put a break point
	if 
	( 
		!cin
		|| user_input < min // error1
		|| user_input > max 
	)
	{
		return {false, "Please enter integer within the range of current roster"};  // error2
	}
	else 
	{
		return {true, ""};
	}
}
void WaitForUser()
	{
		cout << endl << "Please press enter to continue..." << endl;
		cin.get();
		cin.ignore(std::numeric_limits<streamsize>::max(), '\n' );	
	}

void printMenu()
{
	cout << "Contact Management System" << endl;
	cout << "1.) - Add a new contact" << endl;
	cout << "2.) - Remove existing contact" << endl;
	cout << "3.) - View Contacts" << endl;
	cout << "4.) - Quit" << endl;
	cout << endl;
	cout << "Choose an option:  " << endl;
}

void DisplayContacts(vector<string> contact_list)
{
    int contact_list_size = contact_list.size();

		cout << endl << "Contacts:" << endl << endl;

		for (int i = 0; i < contact_list.size(); i++)
		{
			cout << i+1 << ". " << contact_list[i] << endl;
		}

		WaitForUser();
		return;
}
vector<string> AddContact(vector<string> contact_list)
{
    string contact = "";

    contact_list.push_back(contact);
    cout << "Contact information has been saved." << endl;
	WaitForUser();

    return contact_list;
}

vector<string> RemoveContact(vector<string> contact_list)
{
    cout << endl << "Please enter index of student to be deleted" << endl;
    int index_of_student_selected_for_deletion = GetUserInputWithinIntegerRange(1, contact_list.size()+1);

    contact_list.erase( contact_list.begin() + index_of_student_selected_for_deletion - 1 );
	cout << endl << "Student information deleted, please press any character to continue" << endl;	
	WaitForUser();
	return contact_list;
}


