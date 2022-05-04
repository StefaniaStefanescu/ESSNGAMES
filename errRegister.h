#pragma once
#include <iostream>
#include "IException.h"
using namespace std;

class errRegister : public IException
{
public:
    string print();
};