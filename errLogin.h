#pragma once
#include <iostream>
#include "IException.h"
using namespace std;

class errLogin : public IException
{
public:
    string print();
};
