#pragma once
#include <iostream>
#include "IException.h"
using namespace std;

class errJocDescriere : public IException
{
public:
    string print();
};
