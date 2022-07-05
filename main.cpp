#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main() {
    string input;
    cout << "==================================================" << endl;
    cout << "*   Welcome to Disease Cases Reporting System!   *" << endl;
    cout << "*   *******************************************  *" << endl;
    cout << "*                                                *" << endl;
    cout << "*   *******************************************  *" << endl;
    cout << "* It is developed by Mutoni Uwingeneye Denyse as practical  *" << endl;
    cout << "* evaluation for the end of Year 3 *" << endl;
    cout << "==================================================" << endl;
    cout << "Starting Time: Thu Apr 05 23:59:08 CAT 2022" << endl;
    cout << "Need a help? Type 'help' then press Enter key." << endl;
    cout << "Console > ";
    getline(cin, input);

    if (input == "help")
    {

        cout << "==================================================" << endl;
        cout << "*                   HELP MENU                    *" << endl;
        cout << "=================================================*" << endl;
        cout << "add <Location>                                            : Add a new location" << endl;
        cout << "delete <Location>                                         : Delete an existing location" << endl;
        cout << "record <Location> <disease> <cases>                       : Record a disease and its" << endl;
        cout << "list locations                                            : List all existing locations" << endl;
        cout << "list diseases                                             : List all existing DIseases in locations" << endl;
        cout << "where <disease>                                           : Find where disease exists" << endl;
        cout << "cases <locations> <disease>                               : FInd total cases of a given disease" << endl;
        cout << "help                                                      : Prints user manual" << endl;
        cout << "Exist                                                     : Exit the program" << endl;
    }
    

    // switch (input)
    // {
    // case "help":

    //     cout << "==================================================" << endl;
    //     cout << "*                   HELP MENU                    *" << endl;
    //     cout << "=================================================*" << endl;
    //     break;
    
    // default:
    //     break;
    // }
}