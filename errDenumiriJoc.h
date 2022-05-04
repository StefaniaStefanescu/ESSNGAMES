#pragma once
#include <iostream>
#include "IException.h"
using namespace std;

class errDenumiriJoc : public IException
{
public:
    string print();
};
