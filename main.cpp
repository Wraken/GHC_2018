#include "parser.hpp"

int main() {
  Parser p = Parser("a.in");

  std::cout << p.rows << " " << p.columns << " " << p.steps << '\n';
  for (std::list<Ride>::iterator it = p.Rides.begin(); it != p.Rides.end();
       it++) {
    std::cout << it->startx << " " << it->starty << " " << it->endx << " "
              << it->endy << " " << it->earliest << " " << it->latest << '\n';
  }
}
