
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include "./helper.cpp"
#include "./location_service.h"
#include "./disease_service.h"

using namespace std;

class Case
{
public:
    int id;
    int cases;
    string location;
    string disease;
};

bool is_case_empty_file(std::ifstream &pFile)
{
    return pFile.peek() == std::ifstream::traits_type::eof();
}
vector<Case> get_all_cases()
{
    ifstream file("cases.txt", ios::in);
    vector<Case> cases;
    string line;
    while (getline(file, line))
    {
        stringstream ss(line);
        vector<string> fields;
        string field;
        while (getline(ss, field, ','))
        {
            fields.push_back(field);
        }
        Case case_instance;
        case_instance.id = stoi(fields[0]);
        case_instance.cases = stoi(fields[1]);
        for (int i = 0; i < get_all_diseases().size(); i++)
        {
            if (get_all_diseases()[i].name == cases[i].disease)
            {
                case_instance.disease = get_all_diseases()[i].name;
            }
        }
        for (int i = 0; i < get_all_locations().size(); i++)
        {
            if (get_all_locations()[i].name == cases[i].location)
            {
                case_instance.location = get_all_locations()[i].name;
            }
        }
        cases.push_back(case_instance);
    }
    file.close();
    return cases;
}
int get_latest_case_id()
{
    ifstream file("cases.txt", ios::in);
    if (is_case_empty_file(file))
        return 0;
    vector<Case> cases = get_all_cases();
    return cases.back().id;
}

void print_cases(vector<Case> cases)
{
    for (int i = 0; i < cases.size(); i++)
    {
        cout << "Cases of " << cases[i].disease << " at " << cases[i].location << " are: " << cases[i].cases << endl;
    }
}

void add_case(string location, string disease, int cases)
{
    Case case_instance;
    ofstream file("cases.txt", ios::out | ios::app);

    case_instance.id = get_latest_case_id() + 1;
    case_instance.disease = disease;
    case_instance.location = location;
    case_instance.cases = cases;
    file.close();
}