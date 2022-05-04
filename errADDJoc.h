#pragma once
#include <iostream>
#include "IException.h"
using namespace std;

class errADDJoc : public IException
{
public:
    string print();
};
