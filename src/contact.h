#include <string>
#include <vector>

using namespace std;

namespace ctch1330
{
    void RenderMainMenu(vector<string> menu);
	void DisplayRoster(vector<string> roster);
	vector<string> AddStudent(vector<string> roster, int max_class_size);
	vector<string> DeleteStudent(vector<string> roster);
	void WaitForUser();
	int GetUserSelection(int max);
	void PrintInvalidFunctionSelectionWarning();
	void DispatchSelectedOperation(int user_selection);
	int GetUserInputWithinIntegerRange(int min, int max);
	tuple<bool, string> ValidateUserInputWithinIntegerRange(const int min, const int max, const int user_input);
	void PrintInvalidFunctionSelectionWarning(int max_function_count);

    extern vector<string> contact_list;
    extern vector<string> menu_real;
    extern vector<string> menu_mock;

    vector<string> GetMenuFromDatabase();
}
