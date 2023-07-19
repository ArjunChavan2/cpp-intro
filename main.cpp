#include <iostream>
#include <cmath>
#include <vector>
#include <array>
#include "Point.hpp"
using namespace std;
int add(int x, int y){
  return x + y;
}
int subtract(int x, int y){  
  return x - y;
}

int multiply(int x, int y){
  return x * y;
}

int divide(int x, int y){
  return x / y;
}

class Circle{
  public:
    int radius;
  int setRadius(int radius){
    this->radius = radius;
    return 0;
  };
  double area(){
    return M_PI * this->radius * this->radius;
  };

};

class Point{
  private:
    double x,y;
  public:
  Point(double, double){
  };
  double get_x(){
    return x;};
  double get_y(){
    return y;};
  void set_x(double new_x){
    x = new_x;};
  void set_y(double y){
    y = new_y;};
  double distance_to_origin(){
    return sqrt(pow(x,2) + pow(y,2));
  };
  double distance_to_point(Point &other){
    return sqrt(pow(this->x - other.get_x(),2) + pow(this->y - other.get_y(),2));
  };
  /*double distance_to_line(Line l){
    Point p(this->x,this->y);
    return l.distance_to_point(p);
  };*/
};

class Line{
  public:
    Point p1,p2;
  
  Line(Point, Point)
  {
  }
  double length(){
    return p1.distance_to_point(p2);
  }
  double distance_to_point(Point p1){
    double slope = (p2.get_y()-p1.get_y()) / (p2.get_x()-p1.get_x());
    double y_int = p2.get_y() - slope * p2.get_x();
    double d = abs(-1 * slope * p1.get_x() + p1.get_y() - y_int) / sqrt(pow(slope,2) + 1);
    return d;
  };
};

class Triangle{
  public:
    Point p1,p2,p3;
  Triangle(Point p1, Point p2, Point p3){
    this->p1 = p1;
    this->p2 = p2;
    this->p3 = p3;
  };
  Point get_p1(){
    return p1;};
  Point get_p2(){
    return p2;};
  void set_p1(Point p1){
    this->p1 = p1;};
  void set_p2(Point){
    this->p2 = p2;};
  void get_p3(){
    return p3;};
  Point set_p3(){
    return p3;};
  double area(){
    return abs(p1.get_x() * p2.get_y() + p2.get_x() * p3.get_y() + p3.get_x() * p1.get_y() - p1.get_y() * p2.get_x() - p2.get_y() * p3.get_x() - p3.get_y() * p1.get_x());
  };
};

class Polygon{
  public:
    std::vector<Point> points;
  Polygon(vector<Points> points){this->points = points;};
  double area(){
    double areaTot = 0;
    for (int i = 1; i < points.size()-1; i++){
      Triangle temp(points[0],points[i],points[i+1]);
      areaTot += temp.area();
    };
    return areaTot;
  };
  double perimeter(){
    double perimeterTot = 0;
    for(int j = 0; j < points.size(); j++){
      Line temp(points[j],points[j+1]);
      perimeterTot += temp.length();
    };
    return perimeterTot;
  };
};

class AUV{
  public:
    std::string name;
    Point position;
    double depth;
    double heading;
    array<double,3> speed;
    double angular_speed;
  
  AUV(string name, Point position, double depth, double heading, array<double,3> speed, double angular_speed){
    this->name = name;
    this->position = position;
    this->depth = depth;
    this->heading = heading;
    this->speed = speed;
    this->angular_speed = angular_speed;
  };
  int step(double dt){
    if(dt <= 0)
      return 0;
    //Point newPos(position.get_x() + speed[0] * dt, position.get_y() + speed[1]);
    position.set_x(position.get_x() + speed[0] * dt);
    position.set_y(position.get_y() + speed[1] * dt);

    depth += speed[2] * dt;
    return 1;
  };
  int apply_acceleration(array<double,3> acceleration,double dt){
    if(acceleration.size() != 3 || dt <= 0)
      return 0;
    speed[0] = acceleration[0] * dt + speed[0];
    speed[1] = acceleration[1] * dt + speed[1];
    speed[2] = acceleration[2] * dt + speed[2];
    step(dt);
    return 1;
  };
  int apply_angular_acceleration(double angular_acceleration, double dt){
    if (dt <= 0)
      return 0;
    angular_speed += angular_acceleration * dt;
    heading += angular_speed * dt;
    return 1;
  };
};
int main()
{
  std::cout << "Arjun Chavan" << std::endl;
  std::cout << "Autonomous Underwater Vehicle Challenge" << std::endl;

  /* Practice
  int x = 5;
  int y = 7;
  int z = add(x,y);
  int w = multiply(multiply(x,y),z);
  int v = divide(x,y);
  std::cout << "The sum of " << x << " and " << y << " is " << z << std::endl;
  std::cout << "The product of " << x << " and " << y << " and " << z <<" is " << w << std::endl;
  std::cout << "The quotient of " << x << " and " << y <<" is " << v << std::endl;

  Circle cir;
  cir.setRadius(11);
  std::cout << cir.area() << std::endl;

  return 0;
  */

  //Problem 1:
  Point p1(11,-12);
  Point p2(11,0);
  std::cout << "Point at (" << p1.get_x() << ", " << p1.get_y() << ")"<< std::endl;
  Line l1(p1,p2);
  std::cout << "Line distance: " << l1.length() << std::endl;
  Point p3(11,5);
  cout << "Distance to point: " << l1.distance_to_point(p3) << endl; 
}