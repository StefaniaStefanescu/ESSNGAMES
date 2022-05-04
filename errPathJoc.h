#pragma once
#include <iostream>
#include "IException.h"
using namespace std;

class errPathJoc : public IException
{
public:
    string print();
};
