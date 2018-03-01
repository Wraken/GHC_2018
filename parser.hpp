#ifndef PARSER_HPP_
#define PARSER_HPP_

#include <fstream>
#include <iostream>
#include <list>
#include <string>

struct Car {
  int x;
  int y;
  int id;
  std::list<int> RideDone;
  bool OnRide;
};

struct Ride {
  int startx;
  int starty;
  int endx;
  int endy;
  int earliest;
  int latest;
  bool Filed;
  int id;
};

class Parser {
public:
  Parser(std::string);
  ~Parser();
  int rows;
  int columns;
  int steps;
  std::list<Car> Cars;
  std::list<Ride> Rides;

private:
};

#endif
