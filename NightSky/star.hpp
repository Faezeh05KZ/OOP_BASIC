#ifndef STAR_HPP
#define STAR_HPP

class Star 
{
    public:

        Star(int x, int y, int brightness);
        int get_x() const { return x ; }
        int get_y() const { return y ; }
        int get_brightness() const { return Brightness ; }

    private:

        int x ;
        int y ;
        int Brightness ;

};

#endif