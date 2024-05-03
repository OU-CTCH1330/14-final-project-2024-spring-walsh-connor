#include <iostream>
#include <limits>
#include <tuple>
#include "contact.h"

namespace ctch1330
{
    void RenderMainMenu(vector<string> menu) 
	{	
		if ( menu.empty() )
		{
			throw runtime_error( "Database error, could not retrieve Menu functionality data" );
		}
		
		cout << endl << "Main menu:" << endl << endl;

		for (string menu_item : menu)
		{
			cout << menu_item << endl;
		}


		return;
	}

    tuple<bool, string> ValidateUserInputWithinIntegerRange(const int min, const int max, const int user_input)
    {
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
            string new_entry = "";

			cout << endl << "Please enter student information" << endl;

			cin >> new_entry;
			
			contact_list.push_back(new_entry); 
			cout << "Student information has been saved." << endl;
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

    void PrintInvalidFunctionSelectionWarning(int max_function_count)
    {
	    cerr << endl << "Please select integer from the list of offered functions, 1 to " << max_function_count << endl;
	    cin.clear();
	    cin.ignore();
	    return;
    }
    int GetUserSelection(int max)
    {
	    int user_selection = 0;
	    cout << endl << "Please select the operation" << endl;	
	    cin >> user_selection;

	    if 
	    ( 
		    !cin 
		    || user_selection < 1 
		    || user_selection > max 
	    ) 
	    {
		    PrintInvalidFunctionSelectionWarning( max );
		    throw runtime_error("Invalid functionality selection");
	    }
		
	    return user_selection;
    }
    void DispatchSelectedOperation(int user_selection)
    {
		    switch (user_selection)
		    {
			    case 1:
				    contact_list = AddContact(contact_list);
				    break;

			    case 2:
				    contact_list = RemoveContact(contact_list);	
				    break;

			    case 3:
				    DisplayContacts(contact_list);
				    break;

			    case 4:
				    cout << "Exiting..." << endl; 
				    exit(0);

			    default:
				    cout << "Invalid user selection" << endl;
				    WaitForUser();
				    break;
		    }
    }
}
