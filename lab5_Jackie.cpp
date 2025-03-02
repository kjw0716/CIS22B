///lab 5
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <vector>
#include <stdexcept>
#include <forward_list>
#include <sstream>

using namespace std;
const int MAXLOAD737 = 46000; ///max weight for 737
const int MAXLOAD767 = 116000; ///max weight for 767

class Cargo   ///now an abstract due to pure virtual function
{
protected: ///one difference from lab 4
    string uldtype;
    string abbrev;
    string uldid;
    int aircraft;
    double weight;
    string destination;

public:
    ///Default constructor prototype
    Cargo();

    ///Full constructor prototype
    Cargo(const string &uldtype,
          const string &abbrev,
          const string &uldid,
          const int &aircraft,
          const double &weight,
          const string &destination);

    ///Copy constructor prototype
    Cargo(const Cargo &unit);

    ///Destructor prototype
    ~Cargo();

    ///Mutator (setters) prototypes
    void setuldtype(string);
    void setabbrev(string);
    void setuldid(string);
    void setaircraft(int);
    void setweight(double);
    void setdestination(string);

    ///Accessor (getters) prototypes
    string getuldtype() const;
    string getabbrev() const;
    string getuldid() const;
    int getaircraft() const;
    double getweight() const;
    string getdestination() const;

    ///one difference from lab 4 Cargo class
    virtual void maxweight(double&, double, string) = 0;  ///to be overridden

}; ///end of Cargo class

class Boeing737 : public Cargo  ///derived from Cargo class
{
using Cargo::Cargo;///allows inheritance of constructors, destructor

private:
   int total737wt;
public:
    void maxweight(double&, double, string)override; ///overridden from Cargo class
};
class Boeing767 : public Cargo   ///derived from Cargo class
{
using Cargo::Cargo;

private:
    int total767wt;
public:
    void maxweight(double&, double, string)override;
};
///Prototypes go here
void output(Cargo&);
void input();
void checkPlane(string, int);
void checkType(string, string);
void checkAbrv(string, string, int);
void vectorprint(vector <Boeing737> vectorptr737, vector <Boeing767> vectorptr767);
void fllprint(forward_list<Boeing737> list737, forward_list<Boeing767> list767);

int main()
{
    input();
    return 0;
}
    Cargo::Cargo()
    {
        uldtype = "XXX";
        abbrev = " ";
        uldid = "xxxxxIB";
        aircraft = 700;
        weight = 0.0;
        destination = "NONE";
    }
    Cargo::Cargo(const string &uld,
                 const string &abrv,
                 const string &id,
                 const int &craft,
                 const double &wt,
                 const string &dest)
    {
        uldtype = uld;
        abbrev = abrv;
        uldid = id;
        aircraft = craft;
        weight = wt;
        destination = dest;
    }

    Cargo::Cargo(const Cargo &unit1)
{
    uldtype=unit1.uldtype;
    abbrev=unit1.abbrev;
    uldid=unit1.uldid;
    aircraft=unit1.aircraft;
    weight=unit1.weight;
    destination=unit1.destination;
}
    Cargo::~Cargo()
    {
        //cout << "Cargo destructor called\n\n";
    }
    void Cargo::setuldtype(string type)
    {
        uldtype = type;
    }
    void Cargo::setabbrev(string abrv)
    {
        abbrev = abrv;
    }
    void Cargo::setuldid(string id)
    {
        uldid = id;
    }
    void Cargo::setaircraft(int air)
    {
        aircraft = air;
    }
    void Cargo::setweight(double wt)
    {
        weight = wt;
    }
    void Cargo::setdestination(string dest)
    {
        destination = dest;
    }
    string Cargo::getuldtype() const
    {
        return uldtype;
    }
    string Cargo::getabbrev() const
    {
        return abbrev;
    }
    string Cargo::getuldid() const
    {
        return uldid;
    }
    int Cargo::getaircraft() const
    {
        return aircraft;
    }
    double Cargo::getweight() const
    {
        return weight;
    }
    string Cargo::getdestination() const
    {
        return destination;
    }
    ///weight checker goes here
    void load737(vector<Boeing737> &vectorptr737,
                 forward_list<Boeing737> &mylist737,
                 const string type,
                 const string abrv,
                 const string id,
                 const int craft,
                 const double wt,
                 const string dest,
                 double &totwt737)  ///added for use by maxweight, note not const so can be changed
    {
        Boeing737 unitobj737(type,abrv,id,craft,wt,dest);
        unitobj737.maxweight(totwt737, wt, id);
        vectorptr737.push_back(unitobj737);
        mylist737.push_front(unitobj737);
    }

    ///overridden from Cargo class
    void load767(vector<Boeing767> &vectorptr767,
                 forward_list<Boeing767> &mylist767,
                 const string type,
                 const string abrv,
                 const string id,
                 const int craft,
                 const double wt,
                 const string dest,
                 double &totwt767)
    {
    Boeing767 unitobj767(type,abrv,id,craft,wt,dest);
        unitobj767.maxweight(totwt767, wt, id);
        vectorptr767.push_back(unitobj767);
        mylist767.push_front(unitobj767);

    }
    ///overridden from Cargo class
    void Boeing737::maxweight(double &totwt737, double wt, string id){
        if (totwt737 > MAXLOAD737){
            totwt737 -= wt; ///remove if overweight
            throw runtime_error(id + " too heavy for 737, removed\n\n");
        }
    }
    ///overridden from Cargo class
    void Boeing767::maxweight(double &totwt767, double wt, string id){
        if (totwt767 > MAXLOAD767){
            totwt767 -= wt; ///remove if overweight
            throw runtime_error(id + " too heavy for 767, removed\n\n");
        }
    }
    void output(Cargo& unit)
    {
        cout << fixed << showpoint << setprecision(2);
        cout << "***********************************************************\n";
        cout << setw(19) << "Unit load type: " << unit.getuldtype() << endl;
        cout << setw(19) << "Unit abbreviation: " << unit.getabbrev() << endl;
        cout << setw(19) << "Unit identifier: " << unit.getuldid() << endl;
        cout << setw(19) << "Aircraft type: " << unit.getaircraft() << endl;
        cout << setw(19) << "Unit weight: " << unit.getweight() << " pounds" << endl;
        cout << setw(19) << "Destination code: " << unit.getdestination() << endl;
        cout << "***********************************************************\n";
    }
    void input()
    {
        string cargostring;
        string type1;
        string type2;
        string abrv;
        string uld;
        int plane;
        double weight;
        string dest;
        string datafile;
        ifstream inputFile;
        double totwt737 = 0;
        double totwt767 = 0;
        int i = 0;
        vector<Boeing737> vectorptr737;
        vector<Boeing767> vectorptr767;
        forward_list<Boeing737> mylist737;
        forward_list<Boeing767> mylist767;
///******************************************************************
        do{
        try{
            inputFile.clear();
            cout << "\nWhat's the name of your data file?\n";
            getline(cin,datafile);
            cout << "datafile is " << datafile << endl;
            inputFile.open(datafile);
            if (!inputFile)
                throw runtime_error(datafile + " Bad filename\n\n");
            cout << datafile + " open\n";
            }
        catch(runtime_error &excpt){
            cout << datafile << " " << excpt.what();
        }
        }
        while(!inputFile);
///************************************************************************
        while(getline(inputFile, cargostring))   ///read in one line
        {
            istringstream cargoISS(cargostring); ///place line in the input string stream

            cargoISS >> type1;
            if ((type1.compare("Combo")) == 0)///looking for Combo             ///is there a better way to do this
                {
                    cargoISS >> type2 >> abrv >> uld >> plane >> weight >> dest;

                    type1 = type1 + " " + type2;///valid Combo Flat
                }
                else
                {
                   cargoISS >> abrv >> uld >> plane >> weight >> dest;///finish reading last of data
                }
            try{
            checkType(uld, type1);///check for Container, Pallet or Combo Flat
            checkPlane(uld, plane);///737 or 767
            if (plane == 737){
                checkAbrv(uld, abrv, plane);
                totwt737 += weight;
                load737(vectorptr737,mylist737,type1,abrv,uld,plane,weight,dest,totwt737);
            }
            if (plane == 767){
                checkAbrv(uld, abrv, plane);
                totwt767 += weight;
                load767(vectorptr767,mylist767,type1,abrv,uld,plane,weight,dest,totwt767);
            }
            }
        catch(runtime_error &excpt){
            cout << excpt.what();
        }
    }
        inputFile.close();
        vectorprint(vectorptr737, vectorptr767);

        for (Boeing737& out737 : mylist737){
                cout << "737 List Unit# " << ++i << endl;
                output(out737);
    }
        i = 1;
        for (auto out767 : mylist767){
                cout << "767 List Unit# " << ++i << endl;
                output(out767);
    }
        cout << "total weight for 737 load is " << totwt737 << endl;
        cout << "total weight for 767 load is " << totwt767 << endl;

    }///end of input

    void checkType(string uld, string type1){
        if (type1 != "Container" && type1 != "Pallet" && type1 != "Combo Flat")
            throw runtime_error (uld + " " + type1 + " incorrect type, rejected load\n\n");
    }

    void checkPlane(string uld,int air){
    if (air != 737 && air != 767){
        throw runtime_error(to_string(air) + " invalid aircraft type\n\n");
    }
    }

    void checkAbrv(string uld, string abrv, int plane){
        if (plane == 737){
       if (abrv != "AYF" &&
            abrv != "AYK" &&
            abrv != "AAA" &&
            abrv != "AYY" &&
            abrv != "PAG" &&
            abrv != "PMC" &&
            abrv != "PLA" &&
            abrv != "CFE" &&
            abrv != "CFK" &&
            abrv != "CFM")
            {throw runtime_error( uld + " " + abrv + " bad type for 737\n\n");}
        
        }
        if (plane == 767){ 
        if (abrv != "AKE" &&
            abrv != "APE" &&
            abrv != "AKC" &&
            abrv != "AQP" &&
            abrv != "AQF" &&
            abrv != "AAP" &&
            abrv != "P1P" &&
            abrv != "P6P" &&
            abrv != "CFQ" &&
            abrv != "CFX" &&
            abrv != "CFP")
         {
         throw runtime_error(uld + " " + abrv + " bad type for 767\n\n");
         }
        }
    }
    void vectorprint(vector <Boeing737> vectorptr737, vector <Boeing767> vectorptr767) {
    for (size_t i = 0; i < vectorptr737.size(); i++)
        {
           cout << "\n737 unit number " << i + 1 << endl;
           output(vectorptr737[i]);
        }

    for (size_t i = 0; i < vectorptr767.size(); i++)
        {
           cout << "\n767 unit number " << i + 1 << endl;
           output(vectorptr767[i]);
           }
    }
    void fllprint(forward_list<Boeing737> mylist737, forward_list<Boeing767> mylist767)
    {
    int i = 0;

    for (auto& out737 : mylist737){
                cout << "737 Unit# " << ++i << endl;
                output(out737);
    }
    i = 0;
    for (auto& out767 : mylist767){
                cout << "767 Unit# " << ++i << endl;
                output(out767);
    }
    }
/*
What's the name of your data file?
D:\lab5data.txt
datafile is D:\lab5data.txt
D:\lab5data.txt open
AAA23409AA AAA bad type for 767

APE89023DL Box incorrect type, rejected load

P1P77889UA too heavy for 767, removed

PAG88779DL POG bad type for 737

CKE22557UA Combo Box incorrect type, rejected load

707 invalid aircraft type

PLA55689AA too heavy for 737, removed


737 unit number 1
***********************************************************
   Unit load type: Pallet
Unit abbreviation: PAG
  Unit identifier: PAG45982IB
    Aircraft type: 737
      Unit weight: 4978.00 pounds
 Destination code: OAK
***********************************************************

737 unit number 2
***********************************************************
   Unit load type: Container
Unit abbreviation: AAA
  Unit identifier: AAA45658IB
    Aircraft type: 737
      Unit weight: 6232.00 pounds
 Destination code: SEA
***********************************************************

737 unit number 3
***********************************************************
   Unit load type: Pallet
Unit abbreviation: PLA
  Unit identifier: PLA32144AA
    Aircraft type: 737
      Unit weight: 18234.00 pounds
 Destination code: LAS
***********************************************************

737 unit number 4
***********************************************************
   Unit load type: Pallet
Unit abbreviation: PLA
  Unit identifier: PLA99821AA
    Aircraft type: 737
      Unit weight: 11258.00 pounds
 Destination code: LAS
***********************************************************

767 unit number 1
***********************************************************
   Unit load type: Combo Flat
Unit abbreviation: CFQ
  Unit identifier: CFQ88995SW
    Aircraft type: 767
      Unit weight: 1000.00 pounds
 Destination code: MIA
***********************************************************

767 unit number 2
***********************************************************
   Unit load type: Container
Unit abbreviation: AQF
  Unit identifier: AQF66231LU
    Aircraft type: 767
      Unit weight: 15698.00 pounds
 Destination code: ORD
***********************************************************
737 List Unit# 1
***********************************************************
   Unit load type: Pallet
Unit abbreviation: PLA
  Unit identifier: PLA99821AA
    Aircraft type: 737
      Unit weight: 11258.00 pounds
 Destination code: LAS
***********************************************************
737 List Unit# 2
***********************************************************
   Unit load type: Pallet
Unit abbreviation: PLA
  Unit identifier: PLA32144AA
    Aircraft type: 737
      Unit weight: 18234.00 pounds
 Destination code: LAS
***********************************************************
737 List Unit# 3
***********************************************************
   Unit load type: Container
Unit abbreviation: AAA
  Unit identifier: AAA45658IB
    Aircraft type: 737
      Unit weight: 6232.00 pounds
 Destination code: SEA
***********************************************************
737 List Unit# 4
***********************************************************
   Unit load type: Pallet
Unit abbreviation: PAG
  Unit identifier: PAG45982IB
    Aircraft type: 737
      Unit weight: 4978.00 pounds
 Destination code: OAK
***********************************************************
767 List Unit# 2
***********************************************************
   Unit load type: Container
Unit abbreviation: AQF
  Unit identifier: AQF66231LU
    Aircraft type: 767
      Unit weight: 15698.00 pounds
 Destination code: ORD
***********************************************************
767 List Unit# 3
***********************************************************
   Unit load type: Combo Flat
Unit abbreviation: CFQ
  Unit identifier: CFQ88995SW
    Aircraft type: 767
      Unit weight: 1000.00 pounds
 Destination code: MIA
***********************************************************
total weight for 737 load is 40702.00
total weight for 767 load is 16698.00
*/