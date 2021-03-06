#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class Model {
   
};

class Location: Model {
    public:
        int id;
        string name;
};

class Case: Model {
    public: 
        int id;
        int cases;
        string location_id;
        string disease_id;
};

class Disease: Model {
    public:
        int id;
        string name;

        Disease(int id, string name) {
            this->name = name;
        }
};
