#pragma once
#include "Point.hpp"

class Line
{
    private:
        double m_d_p1;
        double m_d_p2;
    
    public:
        Line(Point, Point);

        double p1(){ return m_d_p1};
        double p2(){ return m_d_p2};
        double length(){return m_d_p1.distance_to_point(m_d_p2)};
        double distance_to_point(){}


}