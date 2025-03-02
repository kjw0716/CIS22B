#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <stdexcept>
#include <sstream>

using namespace std;

class Cargo
{
private:
    string uldtype;  ///unit load type, container or pallet
    string abbrev;   ///three letters AYF, PAG etc.
    string uldid;
    int aircraft;
    double weight;
    string destination;

public:
///constructor prototypes
    Cargo();  ///default constructor prototype, see below main

    Cargo(const string type,
          const string abbrev,
          const string uldid,
          const int aircraft,
          const double weight,
          const string destination);

///Copy constructor prototype (declaration), definition to follow main
    Cargo(const Cargo& );

///Destructor prototype (definition), inline code
    ~Cargo();

///Mutator (setters) prototypes (declarations)
    void SetUldType(string);
    void SetAbbrev(string);
    void SetUldid(string);
    void SetAircraft(int);
    void SetWeight(double);
    void SetDestination(string);

///Accessor (getters) prototypes
    string getuldtype();
    string getabbrev();
    string getuldid();
    int getplane();
    double getwt();
    string getdest();
};
///end of Cargo class

void input();
void output(Cargo&);

int main()
{
    input();
return 0;
}
    Cargo::Cargo()
    {
        uldtype = "XXX";
        abbrev = "none";
        uldid = "none";
        aircraft = 700;
        weight = 0.00;
        destination = "none";
    }
    Cargo::Cargo(const string typ,
          const string abrv,
          const string uld,
          const int air,
          const double wt,
          const string dest)
          {
              uldtype = typ;
              abbrev = abrv;
              uldid = uld;
              aircraft = air;
              weight = wt;
              destination = dest;
          }


Cargo::Cargo(const Cargo &unit1)
{
    uldtype = unit1.uldtype;
    abbrev = unit1.abbrev;
    uldid = unit1.uldid;
    aircraft = unit1.aircraft;
    weight = unit1.weight;
    destination = unit1.destination;
}
    Cargo::~Cargo()
    {
        cout << "Cargo destructor called\n\n";
    }


///Setters
    void Cargo::SetUldType(string utype)
    {
        uldtype = utype;
    }
    void Cargo::SetAbbrev(string abrv)
    {
        abbrev = abrv;
    }
    void Cargo::SetUldid(string uld)
    {
        uldid = uld;
    }
    void Cargo::SetAircraft(int air)
    {
        aircraft = air;
    }
    void Cargo::SetWeight(double wt)
    {
        weight = wt;
    }
    void Cargo::SetDestination(string dest)
    {
        destination = dest;
    }

///getters
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
    int Cargo::getplane()
    {
        return aircraft;
    }
    double Cargo::getwt()
    {
        return weight;
    }
    string Cargo::getdest()
    {
        return destination;
    }

    void output(Cargo &unit)
    {
        cout << fixed << showpoint << setprecision(2);
        cout << "**************************************************\n";
        cout << setw(19) << "Unit load type: " << unit.getuldtype() << endl;
        cout << setw(19) << "Unit abbreviation: " << unit.getabbrev() << endl;
        cout << setw(19) << "Unit identifier: " << unit.getuldid() << endl;
        cout << setw(19) << "Unit airplane: " << unit.getplane() << endl;
        cout << setw(19) << "Unit weight: " << unit.getwt() << " pounds" << endl;
        cout << setw(19) << "Unit destination: " << unit.getdest() << endl;
        cout << "**************************************************\n";
    }

    void input()
    {
        string cargostring;
        string type1;
        string type2;
        string comp1 = "Combo";
        string comp2 = "Flat";
        string abrv;
        string uld;
        int plane;
        double weight;
        string dest;
        string datafile;
        ifstream inputFile;
        bool baddata;


///a try/throw/catch block would be appropriate here
        cout << "Opening file cardata4.txt. " << endl;
        getline(cin, datafile);
        inputFile.open(datafile);
        // If the open fails, send a message and exit
        if(!inputFile) ///if (!inputFile.is_open())
        {
            cout << "Error opening the file, file not found" << endl;
            exit(99); ///in cstdlib
            return;
        }
///**********************************************************************

///the data file has some lines with six items, some with seven items,
///input string parsing will take in one line and break it into six or
///seven items
///instead of simply terminating program on error, try/throw/catch
while(inputFile.peek() != EOF)
    {
        /// Before using getline, skip any leading whitespace
        while(inputFile.peek() == ' ')
            inputFile.get();
        while(getline(inputFile, cargostring))   ///read in one line
        {
            try{
            baddata = false;
            istringstream cargoISS(cargostring); ///place line in the input string stream
            cargoISS >> type1;

            if ((type1.compare("Combo")) == 0)///looking for Combo
                {
                    cargoISS >> type2 >> abrv >> uld >> plane >> weight >> dest;

                    if (!((type2.compare("Flat")) == 0))
                    {
                        baddata = true;
                        throw runtime_error(type1 +  " " + type2 + " Bad unit name\n");
                    }
                    type1 = type1 + " " + type2;///valid Combo Flat
                }
                else
                {
                   cargoISS >> abrv >> uld >> plane >> weight >> dest;///finish reading last of data
                }
            }
            catch (runtime_error &excpt){
                cout << excpt.what();
        }
            ///cout << type1 << ' ' << abrv << ' ' << uld << ' ' << plane << ' ' << weight << ' ' << dest << endl;
            if (baddata == false)
            {
            Cargo unit(type1, abrv, uld, plane, weight, dest);///using fully loaded constructor
            output(unit);///pass by ref (see output), not making a copy of object
            }
        }
        inputFile.close();///close the open data file, done with processing
        Cargo temp(type1, abrv, uld, plane, weight, dest);
    }
    }


