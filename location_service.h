
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include "./helper.cpp"

using namespace std;

class Model {
   
};

class Location: Model {
    public:
        int id;
        string name;
};

// class Case: Model {
//     public: 
//         int id;
//         int cases;
//         Location location;
//         Disease disease;
// };

// class Disease: Model {
//     public:
//         int id;
//         string name;

//         Disease(int id, string name) {
//             this->name = name;
//         }
// };


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


int get_latest_id()
{
    ifstream file("locations.txt", ios::in);
    if (is_empty_file(file)) return 0;
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
    location.id = get_latest_id() + 1, name;
    location.name = name;
    file << location.id << "," << location.name << endl;
    cout << "Location " << name << " is successfully added!" << endl;
    file.close();
}
