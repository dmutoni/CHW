#include <iostream>
#include <string>
#include <vector>
// #include "./models.h"
#include "./all_services.h"
#include <sstream>

using namespace std;

void displayHelpMenu()
{
    string input;
    cout << "====================================================================================================" << endl;
    cout << "*                   HELP MENU                                                                      *" << endl;
    cout << "===================================================================================================*" << endl;
    cout << "add <Location>                                            : Add a new location" << endl;
    cout << "delete <Location>                                         : Delete an existing location" << endl;
    cout << "record <Location> <disease> <cases>                       : Record a disease and its" << endl;
    cout << "list locations                                            : List all existing locations" << endl;
    cout << "list diseases                                             : List all existing DIseases in locations" << endl;
    cout << "where <disease>                                           : Find where disease exists" << endl;
    cout << "cases <locations> <disease>                               : FInd total cases of a given disease" << endl;
    cout << "help                                                      : Prints user manual" << endl;
    cout << "Exist                                                     : Exit the program" << endl;
    cout << "Console > ";
    getline(cin, input);
    if (input == "list locations")
    {
        vector<Location> locations = get_all_locations();
        print_locations(locations);
    }
    else if (input == "list diseases")
    {
        vector<Disease> diseases = get_all_diseases();
        print_diseases(diseases);
    }
    else if (input == "exit")
    {
        cout << "Exiting the program..." << endl;
        exit(0);
    }
    else if (input.find("add") != std::string::npos)
    {
        stringstream ss(input);
        vector<string> fields;
        string field;

        while (getline(ss, field, ' '))
        {
            fields.push_back(field);
        }

        string location = fields[1];
        add_location(location);
    }
    else if (input.find("record") != std::string::npos)
    {
        stringstream ss(input);
        vector<string> fields;
        string field;

        while (getline(ss, field, ' '))
        {
            fields.push_back(field);
        }

        string location = fields[1];
        string disease = fields[2];
        int cases = stoi(fields[3]);
        cout << "Recording " << cases << " cases of " << disease << " in " << location << endl;
        add_case(location, disease, cases);
    }
    else if (input.find("where") != std::string::npos)
    {
        stringstream ss(input);
        vector<string> fields;
        string field;

        while (getline(ss, field, ' '))
        {
            fields.push_back(field);
        }

        string location = fields[1];
        get_disease_occurrence(location);
    }
    else if (input.find("cases") != std::string::npos)
    {
        stringstream ss(input);
        vector<string> fields;
        string field;
        if (count_words_of_a_string(input) == 2)
        {
            while (getline(ss, field, ' '))
            {
                fields.push_back(field);
            }

            string location = fields[1];
            get_total_case_per_disease(location);
        } else if(count_words_of_a_string(input) == 3)
        {
            while (getline(ss, field, ' '))
            {
                fields.push_back(field);
            }

            string location = fields[1];
            string disease = fields[2];
            get_total_case_per_location_per_disease(location, disease);
        }
    }
    else if (input.find("delete") != std::string::npos)
    {
        stringstream ss(input);
        vector<string> fields;
        string field;

        while (getline(ss, field, ' '))
        {
            fields.push_back(field);
        }

        string location = fields[1];
        delete_location(location);
    }
    else
    {
        cout << "Invalid input" << endl;
        displayHelpMenu();
    }
}

int main()
{
    string input;
    cout << endl;
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
        displayHelpMenu();
    }
}