#ifndef CALC_H
#define CALC_H

#include <string>

struct Price {
  int hrn;
  short int kop;
  };

extern int totalhrn;
extern int totalkop;
void calculate1(const std::string& filename);
void calculate2(int& totalhrn, int& totalkop);
void calculate3(int& totalhrn, int& totalkop);
void consoloutput(int& totalhrn, int& totalkop);

#endif