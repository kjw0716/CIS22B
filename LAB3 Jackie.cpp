#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
class Cargo
{
private:
    string uldtype;  /// unit load type, container or pallet
    string abbrev;   /// three letters AYF, PAG etc.
    string uldid;
    int aircraft;
    double weight;
    string destination;
public:
///constructor prototypes
    Cargo();  ///default constructor prototype, see below main

    Cargo(const string type);

///Copy constructor prototype (declaration), definition to follow main
    Cargo(const Cargo& );

///Destructor prototype using inline code (declaration/definition here)
    ~Cargo();

    /// Mutator (setters) prototypes
    void SetUldType(string);
    void SetAbbrev(string);
    void SetUldid(string);
    void SetAircraft(int);
    void SetWeight(double);
    void SetDestination(string);

    /// Accessor (getters) prototypes
    string getuldtype();
    string getabbrev();
    string getuldid();
    int GetAircraft();
    double GetWeight();
    string GetDestination();

    bool operator == (const Cargo& rhs) const;
}; /// End of class Cargo

void input(Cargo &);   /// Moved from class
void output(Cargo &);  /// Moved from class
double kilotopound(double kg);

int main()
{
    Cargo unit1; /// On the stack
    input(unit1);

    output(unit1);
    Cargo unit2(unit1); /// Call copy constructor
    output(unit2);
    if (unit1 ==unit2)
    {
        cout << "They are the same\n";
    }
    return 0;
}

/// Default constructor
Cargo::Cargo()
{
    uldtype = "none";
}

/// Constructor
Cargo::Cargo(const string type)
{
    uldtype = type;
}

/// Copy constructor, shallow copy (no pointer variables)
Cargo::Cargo(const Cargo & unit1)
{
    cout << "Copy constructor\n";
    uldtype = unit1.uldtype;
    abbrev = unit1.abbrev;
    uldid = unit1.uldid;
    aircraft = unit1.aircraft;
    weight = unit1.weight;
    destination = unit1.destination;
}

/// destructor
Cargo::~Cargo()
{
    cout << "Cargo destructor called\n";
}

/// Setters
void Cargo::SetUldType(string type)
{
    uldtype = type;
}
void Cargo::SetAbbrev(string abrv)
{
    abbrev = abrv;
}
void Cargo::SetUldid(string uld)
{
    uldid = uld; 
}
void Cargo::SetAircraft(int ac)
{
    aircraft = ac;
}
void Cargo::SetWeight(double wt)
{
    string unit;
    cout << "\nIs the weight in kilograms or pounds? (Enter 'kg' or 'lb'): ";
    cin >> unit;
    if (unit == "kg")
    {
        weight = kilotopound(wt);
    }
    else
    {
        weight = wt;
    }
}
void Cargo::SetDestination(string dest)
{
    destination = dest;
}

/// Getters
string Cargo::getuldtype()
{
    return uldtype;
}
string Cargo::getabbrev()
{
    return abbrev;
}
string Cargo::getuldid()
{
    return uldid;
}
int Cargo::GetAircraft()
{
    return aircraft;
}
double Cargo::GetWeight()
{
    return weight;
}
string Cargo::GetDestination()
{
    return destination;
}

/// Output
void output(Cargo & unit)
{
    cout << "============================================================" << endl;
    cout << setw(19) << left << "Unit Load Type" << " : " << unit.getuldtype() << endl;
    cout << setw(19) << left << "Unit Load Abbreviation" << " : " << unit.getabbrev() << endl;
    cout << setw(19) << left << "Unit Identifier" << " : " << unit.getabbrev() + unit.getuldid() << endl;
    cout << setw(19) << left << "Aircraft Type" << " : " << unit.GetAircraft() << endl;
    cout << setw(19) << left << "Unit Weight" << " : " << unit.GetWeight() << " pounds" << endl;
    cout << setw(19) << left << "Destination Code" << " : " << unit.GetDestination() << endl;
    cout << fixed << setprecision(2);
    cout << "============================================================" << endl;
    return;
}

/// Input
void input(Cargo & unit)
{
    /// Local variables for load from keyboard
    string type;
    string abrv;
    string uld;
    int ac;
    double wt;
    string dest;

    cout << "\nPlease input load information\n";
    cout << "unit type?  ";
    getline(cin, type);
    unit.SetUldType(type);

    cout << "\nPlease enter abbreviation: ";
    getline(cin, abrv);
    unit.SetAbbrev(abrv);

    cout << "\nPlease enter unit ID: ";
    getline(cin, uld);
    unit.SetUldid(uld);

    cout << "\nPlease enter aircraft type: ";
    cin >> ac;
    unit.SetAircraft(ac);
    cin.ignore();

    cout << "\nPlease enter unit weight: ";
    cin >> wt;
    unit.SetWeight(wt);
    cin.ignore();

    cout << "\nPlease enter destination code: ";
    getline(cin, dest);
    unit.SetDestination(dest);

    return;
}
bool Cargo::operator == (const Cargo& rhs) const
{
    return (uldtype == rhs.uldtype && abbrev == rhs.abbrev);
}
double kilotopound(double kg)
{
    return kg * 2.2;
}
/*
Please input load information
unit type?  COmbo Flat

Please enter abbreviation: CFE

Please enter unit ID: CFECFE340IB

Please enter aircraft type: 737

Please enter unit weight: 440.00 

Is the weight in kilograms or pounds? (Enter 'kg' or 'lb'): kg

Please enter destination code: DFW
============================================================
Unit Load Type      : COmbo Flat
Unit Load Abbreviation : CFE
Unit Identifier     : CFECFECFE340IB
Aircraft Type       : 737
Unit Weight         : 968 pounds
Destination Code    : DFW
============================================================
Copy constructor
============================================================
Unit Load Type      : COmbo Flat
Unit Load Abbreviation : CFE
Unit Identifier     : CFECFECFE340IB
Aircraft Type       : 737
Unit Weight         : 968.00 pounds
Destination Code    : DFW
============================================================
They are the same
Cargo destructor called
Cargo destructor called
*/