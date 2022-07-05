
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include "./helper.cpp"

using namespace std;

class Disease {
    public:
        int id;
        string name;
};

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
