
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include "./helper.cpp"

using namespace std;

class Location {
    public:
        int id;
        string name;
};
class Disease {
    public:
        int id;
        string name;
};

class Case
{
public:
    int id;
    int cases;
    string location;
    string disease;
};


bool is_locations_empty_file(std::ifstream &pFile)
{
    return pFile.peek() == std::ifstream::traits_type::eof();
}

vector<Location> get_all_locations()
{
    ifstream file("locations.txt", ios::in);
    vector<Location> locations;
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
        Location location;
        location.id = stoi(fields[0]);
        location.name = fields[1];
        locations.push_back(location);
    }
    file.close();
    return locations;
}


int get_latest_location_id()
{
    ifstream file("locations.txt", ios::in);
    if (is_locations_empty_file(file)) return 0;
    vector<Location> locations = get_all_locations();
    return locations.back().id;
}

void print_locations(vector<Location> locations)
{
    for (int i = 0; i < locations.size(); i++)
    {
        cout << locations[i].name << endl;
    }
}

void add_location(string name) {
    Location location;
    ofstream file("locations.txt", ios::out | ios::app);
    cout << "reading file..." << endl;
    location.id = get_latest_location_id() + 1, name;
    location.name = name;
    file << location.id << "," << location.name << endl;
    cout << "Location " << name << " is successfully added!" << endl;
    file.close();
}

bool is_disease_empty_file(std::ifstream &pFile)
{
    return pFile.peek() == std::ifstream::traits_type::eof();
}

vector<Disease> get_all_diseases()
{
    ifstream file("diseases.txt", ios::in);
    vector<Disease> diseases;
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
        Disease disease;
        disease.id = stoi(fields[0]);
        disease.name = fields[1];
        diseases.push_back(disease);
    }
    file.close();
    return diseases;
}


int get_latest_disease_id()
{
    ifstream file("diseases.txt", ios::in);
    if (is_disease_empty_file(file)) return 0;
    vector<Disease> diseases = get_all_diseases();
    return diseases.back().id;
}

void print_diseases(vector<Disease> diseases)
{
    for (int i = 0; i < diseases.size(); i++)
    {
        cout << diseases[i].name << endl;
    }
}

void add_disease(string name) {
    Disease disease;
    ofstream file("diseases.txt", ios::out | ios::app);
    cout << "reading file..." << endl;
    disease.id = get_latest_disease_id() + 1, name;
    disease.name = name;
    file << disease.id << "," << disease.name << endl;
    cout << "Disease " << name << " is successfully added!" << endl;
    file.close();
}


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
    file << case_instance.id << "," << case_instance.location << "," << case_instance.disease << "," << case_instance.cases << endl;
    file.close();
}