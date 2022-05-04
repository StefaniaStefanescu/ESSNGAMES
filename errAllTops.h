#pragma once
#include <iostream>
#include "IException.h"
using namespace std;

class errAllTops : public IException
{
public:
    string print();
};
