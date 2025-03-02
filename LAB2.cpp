//LAB 2 proagrammed by Jackie Wang email:junkaiwang0716@gmail.com
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Cargo
{
private:
    string uldtype;     /// unit load type, container or pallet
    string abbrev;      /// three letters AYF, PAG etc.
    string uldid;
    int aircraft;
    int weight;
    string destination;

public:
    /// Constructor prototypes
    Cargo(); /// Default constructor prototype
    Cargo(const string type, const string abrv, const string id, const int air, const int wt, const string dest);
    /// Destructor prototype
    ~Cargo();
    /// Mutator (setters) prototypes
    void SetUldType(string);
    void SetAbbrev(string);
    void SetUldId(string);
    void SetAircraft(int);
    void SetWeight(int);
    void SetDestination(string);

    /// Accessor (getters) prototypes
    string getuldtype() const;
    string getAbbrev() const;
    string getUldId() const;
    int getAircraft() const;
    int getWeight() const;
    string getDestination() const;

    void input(Cargo&);
    void output(Cargo&);
}; /// end of class Cargo

int main()
{
    Cargo* cPtr = new Cargo; /// Create Cargo object on the heap
    cPtr->output(*cPtr);
    delete cPtr;

    Cargo* dPtr = new Cargo;
    dPtr->input(*dPtr);
    dPtr->output(*dPtr);
    delete dPtr;

    return 0;
}

/// Default constructor
Cargo::Cargo()
{
    uldtype = "none";
    abbrev = "none";
    uldid = "none";
    aircraft = 0;
    weight = 0;
    destination = "none";
}

/// constructor
Cargo::Cargo(const string type, const string abrv, const string id, const int air, const int wt, const string dest)
{
    uldtype = type;
    abbrev = abrv;
    uldid = id;
    aircraft = air;
    weight = wt;
    destination = dest;
}

/// destructor
Cargo::~Cargo()
{
    cout << "Cargo destructor called\n";
}

/// setters 
void Cargo::SetUldType(string type)
{
    uldtype = type;
}

void Cargo::SetAbbrev(string abrv)
{
    abbrev = abrv;
}

void Cargo::SetUldId(string id)
{
    uldid = id;
}

void Cargo::SetAircraft(int air)
{
    aircraft = air;
}

void Cargo::SetWeight(int wt)
{
    weight = wt;
}

void Cargo::SetDestination(string dest)
{
    destination = dest;
}

/// getters 
string Cargo::getuldtype() const
{
    return uldtype;
}

string Cargo::getAbbrev() const
{
    return abbrev;
}

string Cargo::getUldId() const
{
    return uldid;
}

int Cargo::getAircraft() const
{
    return aircraft;
}

int Cargo::getWeight() const
{
    return weight;
}

string Cargo::getDestination() const
{
    return destination;
}

/// Output function
void Cargo::output(Cargo&)
{
    cout << setw(19) << "Unit load type: " << getuldtype() << endl;
    cout << setw(19) << "Unit load abbreviation: " << getAbbrev() << endl;
    cout << setw(19) << "Unit identifier: " << getUldId() << endl;
    cout << setw(19) << "Aircraft type: " << getAircraft() << endl;
    cout << setw(19) << "Unit weight: " << getWeight() << " pounds" << endl;
    cout << setw(19) << "Destination code: " << getDestination() << endl;
    cout << "________________________________________________________";
    return;
}

/// Input function
void Cargo::input(Cargo&)
{
    /// Local variables for input from keyboard
    string type, abrv, dest, id;
    int wt, air;

    cout << "\nPlease input load information\n";

    cout << "Container or Pallet? ";
    getline(cin, type);
    SetUldType(type);


    cout << "Abbreviation ? ";
    getline(cin, abrv);
    SetAbbrev(abrv);

    cout << "Unit ID ";
    getline(cin, id);
    SetUldId(id);

    cout << "Aircraft type ";
    cin >> air;
    SetAircraft(air);

    cout << "Weight";
    cin >> wt;
    SetWeight(wt);
    cin.ignore(); 

    cout << "Destination code: ";
    getline(cin, dest);
    SetDestination(dest);


    return;
}
/*
   Unit load type: none
Unit load abbreviation: none
  Unit identifier: none
    Aircraft type: 0
      Unit weight: 0 pounds
 Destination code: none
Cargo destructor called

Please input load information
Container or Pallet? Pallet
Abbreviation ? PMG
Unit ID PMG12345IB
Aircraft type 737
Weight1257
Destination code: SJC
________________________________________________________
   Unit load type: Pallet
Unit load abbreviation: PMG
  Unit identifier: PMG12345IB
    Aircraft type: 737
      Unit weight: 1257 pounds
 Destination code: SJC
*/