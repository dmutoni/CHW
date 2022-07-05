
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include "./helper.cpp"
#include <bits/stdc++.h>


using namespace std;

class Location
{
public:
    int id;
    string name;
};
class Disease
{
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

bool disease_exists(string name)
{
    vector<Disease> diseases = get_all_diseases();
    for (int i = 0; i < diseases.size(); i++)
    {
        if (diseases[i].name == name)
        {
            return true;
        }
    }
    return false;
}

bool location_exists(string name)
{
    vector<Location> locations = get_all_locations();
    for (int i = 0; i < locations.size(); i++)
    {
        if (locations[i].name == name)
        {
            return true;
        }
    }
    return false;
}

int get_latest_location_id()
{
    ifstream file("locations.txt", ios::in);
    if (is_locations_empty_file(file))
        return 0;
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

void add_location(string name)
{

    if (location_exists(name))
    {
        cout << "Sorry, location already exists" << endl;
        add_location(name);
    }

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

int get_latest_disease_id()
{
    ifstream file("diseases.txt", ios::in);
    if (is_disease_empty_file(file))
        return 0;
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

void add_disease(string name)
{
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
        case_instance.cases = stoi(fields[3]);
        case_instance.id = stoi(fields[0]);
        for (int i = 0; i < get_all_diseases().size(); i++)
        {
            if (get_all_diseases()[i].name == fields[2])
            {
                case_instance.disease = get_all_diseases()[i].name;
            }
        }
        for (int i = 0; i < get_all_locations().size(); i++)
        {
            if (get_all_locations()[i].name == fields[1])
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

void update_to_file_from_vector_locations(vector<Location> locations)
{
    ofstream temp_file("temp.txt", ios::out | ios::app);

    for (int i = 0; i < locations.size(); i++)
    {
        Location location = locations[i];
        temp_file << location.id << "," << location.name << endl;
    }
    remove("locations.txt");
    rename("temp.txt", "locations.txt");
    temp_file.close();
}

void update_to_file_from_vector_cases(vector<Case> cases)
{
    ofstream temp_file("temp.txt", ios::out | ios::app);

    for (int i = 0; i < cases.size(); i++)
    {
        Case case_instance = cases[i];
        temp_file << case_instance.id << "," << case_instance.location << case_instance.disease << case_instance.cases << endl;
    }
    remove("cases.txt");
    rename("temp.txt", "cases.txt");
    temp_file.close();
}

void add_case(string location, string disease, int cases)
{

    if (!disease_exists(disease))
    {
        add_disease(disease);
    }
    
    Case case_instance;
    ofstream file("cases.txt", ios::out | ios::app);
    case_instance.id = 2;
    case_instance.disease = disease;
    case_instance.location = location;
    case_instance.cases = cases;
    file << case_instance.id << "," << case_instance.location << "," << case_instance.disease << "," << case_instance.cases << endl;
    file.close();
}

void get_disease_occurrence(string disease)
{
    vector<Case> cases = get_all_cases();
    vector<string> locations;
    for (int i = 0; i < cases.size(); i++)
    {
        if (cases[i].disease == disease)
        {
            locations.push_back(cases[i].location);
        }
    }
    cout << "[";
    for (int i = 0; i < locations.size(); i++)
    {
        cout << locations[i] << " ";
    }
    cout << "]" << endl;
}
void get_case_per_location(string location, string disease)
{
    vector<Case> cases = get_all_cases();
    vector<string> locations;
    for (int i = 0; i < cases.size(); i++)
    {
        if (cases[i].location == location)
        {
            if (cases[i].disease == disease)
            {
                cout << "Cases of " << disease << " at " << location << " are: " << cases[i].cases << endl;
            }
        }
    }
}

void get_total_case_per_location_per_disease(string location, string disease)
{
    vector<Case> cases = get_all_cases();
    vector<string> locations;
    int total_cases = 0;
    for (int i = 0; i < cases.size(); i++)
    {
        if (cases[i].location == location)
        {
            if (cases[i].disease == disease)
            {
                total_cases += cases[i].cases;
            }
        }
    }
    cout << "Cases of " << disease << " at " << location << " are: " << total_cases << endl;
}

void get_total_case_per_disease(string disease)
{
    vector<Case> cases = get_all_cases();
    vector<string> locations;
    int total_cases = 0;
    for (int i = 0; i < cases.size(); i++)
    {
        if (cases[i].disease == disease)
        {
            total_cases += cases[i].cases;
        }
    }
    cout << "Total cases of "
         << "'" << disease << " = " << total_cases << endl;
}

int count_words_of_a_string(string sentence)
{
    int count = 0;
    for (int i = 0; i < sentence.length(); i++)
    {
        if (sentence[i] == ' ')
        {
            count++;
        }
    }
    return count + 1;
}

// function to return sorted vector<Disease>
vector<Disease> sort_diseases(vector<Disease> diseases)
{
    vector<Disease> sorted_diseases;
    for (int i = 0; i < diseases.size(); i++)
    {
        int max_index = i;
        for (int j = i + 1; j < diseases.size(); j++)
        {
            if (diseases[j].name < diseases[max_index].name)
            {
                max_index = j;
            }
        }
        Disease temp = diseases[i];
        diseases[i] = diseases[max_index];
        diseases[max_index] = temp;
    }
    return diseases;
}

void delete_location(string location_name)
{
    int count_location = 0;
    int count_cases = 0;
    vector<Location> locations = get_all_locations();

    for (int i = 0; i < locations.size(); i++)
    {
        Location location = locations[i];
        if (location.name == location_name)
        {
            locations.erase(locations.begin() + i);
            count_location++;
        }
    }
    if (count_location >= 1)
    {
        update_to_file_from_vector_locations(locations);
        vector<Case> cases = get_all_cases();

        for (int i = 0; i < cases.size(); i++)
        {
            Case case_instance = cases[i];
            if (case_instance.location == location_name)
            {
                cases.erase(cases.begin() + i);
                count_cases++;
            }
        }
        if (count_cases >= 1)
            update_to_file_from_vector_cases(cases);
        else
            cout << "Location not found" << endl;
    }
    else
        cout << "Location not found" << endl;
}
