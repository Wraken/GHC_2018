#include "parser.hpp"

Parser::Parser(std::string filename) {

  std::ifstream in(filename);

  if (!in) {
    std::cout << "Could not open file" << '\n';
    exit(0);
  }
  std::string line;

  std::getline(in, line);
  std::string delimiter = " ";

  size_t pos = 0;
  std::string token;
  int i = 0;
  while ((pos = line.find(delimiter)) != std::string::npos) {
    token = line.substr(0, pos);
    if (i == 0) {
      this->rows = atoi(token.c_str());
    } else if (i == 1) {
      this->columns = atoi(token.c_str());
    }
    if (i == 2) {
      int y = atoi(token.c_str());
      int x = 0;
      while (x < y) {
        Car c;
        c.x = 0;
        c.y = 0;
        c.id = 0;
        c.OnRide = false;
        this->Cars.push_back(c);
        x++;
      }
    }
    line.erase(0, pos + delimiter.length());
    i++;
  }
  this->steps = atoi(line.c_str());
  int nb = 0;
  while (std::getline(in, line)) {
    int i = 0;
    Ride r;
    r.Filed = false;
    while ((pos = line.find(delimiter)) != std::string::npos) {
      token = line.substr(0, pos);
      if (i == 0) {
        r.startx = atoi(token.c_str());
      } else if (i == 1) {
        r.starty = atoi(token.c_str());
      }
      if (i == 2) {
        r.endx = atoi(token.c_str());
      }
      if (i == 3) {
        r.endy = atoi(token.c_str());
      }
      if (i == 4) {
        r.earliest = atoi(token.c_str());
      }
      line.erase(0, pos + delimiter.length());
      i++;
    }
    r.latest = atoi(line.c_str());
    r.id = nb;
    this->Rides.push_back(r);
    nb++;
  }
}

Parser::~Parser() {}
