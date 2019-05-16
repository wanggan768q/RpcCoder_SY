#ifndef __ALLMODULENAMES_H
#define __ALLMODULENAMES_H
#include <map>
#include <string>
using namespace std;
extern map<int,string> ModuleValue;
void InitModuleValue();
string GetModuleValue(int);

#endif