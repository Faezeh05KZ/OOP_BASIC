#include "gps.hpp"
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

GPS::GPS(double lat, double lon)
{

    if (lat < -90 || lat > 90 )
    {
        throw invalid_argument (" Latitude must be between -90 and 90  ! ");
    }
    
    if (lon < -180 || lon > 180 )
    {
        throw invalid_argument (" Longitude must be between -180 and 180  !");
    }

    Latitude  = lat ;
    Longitude = lon ;
}

GPS::~GPS()
{

    cout << "Last position: " << convert () << endl ;
}

string GPS:: convert() const
{
    stringstream ss;
    ss << "Latitude: " << Latitude  << "degree ," << " Longitude: " << Longitude << "degree";
    return ss.str();
}

bool GPS:: save_location (const string& NameofFile , const vector<GPS>& locations)
{
    ofstream located( NameofFile ) ;
    if (!located.is_open())
    {
        cout << " Couldn't open file to save !!!" << endl;
        return false ;
    }

    for (const GPS& loc : locations)
    {
        located << loc.get_latitude() << endl << loc.get_longitude() << endl ;
    }

    located.close() ;
    cout << "Location saved successfully!" << endl ;
    return true;
}

bool GPS::load (const string& NameofFile , vector<GPS>& locations)
{
    ifstream file(NameofFile );
    if (!file.is_open())
    {
        cout << " Couldn't open file to load " << endl ;
        return false;
    }

    locations.clear() ;
    string length ;

    while (getline(file, length))
    {
        double latitude , longitude;

        stringstream(length ) >> latitude ;

        if (!getline(file , length ))
        {
            cout << " Error " << endl ;
            break;
        }
        stringstream(length ) >> longitude ;

        try
        {
            GPS loc(latitude, longitude) ;
            locations.push_back(loc) ;
        }
        
        catch (const invalid_argument& e)
        {
            cout << " Error loading location  " << e.what() << endl ;
        }
    }

    file.close();

    cout << " Locations loaded from  successfully!" << endl ;
    return true;
}