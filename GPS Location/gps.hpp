#ifndef GPS_HPP
#define GPS_HPP

#include <string>
#include <vector>

class GPS 
{
    
    public:
    GPS(double lat, double lon) ;
    ~GPS() ;
    
    double get_latitude  () const  { return Latitude ; }
    double get_longitude () const { return Longitude ; }
    std::string convert() const;
    

    static bool save_location (const std::string& NameofFile , const std::vector <GPS>& locations) ;
    static bool load (const std::string& NameofFile , std::vector <GPS>& locations ) ;

    private: 

        double Latitude ; 
        double Longitude ; 
};

#endif