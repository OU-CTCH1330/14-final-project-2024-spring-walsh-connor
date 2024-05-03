#include "contact.h"

using namespace ctch1330;

vector<string> ctch1330::contact_list =
{
    "Connor"
};

vector<string> ctch1330::menu_real = 
{
    "1. Add Contact",
    "2. Remove Contact",
    "3. Display Contacts",
    "4. Exit"
};

vector<string> ctch1330::menu_mock = {};

vector<string> ctch1330::GetMenuFromDatabase()
{
    return (rand() % 2) ?
    menu_real
    : menu_mock;
}