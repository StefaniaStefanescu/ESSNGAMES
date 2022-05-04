#pragma once
#include <iostream>
#include "IException.h"
using namespace std;

class errTop : public IException
{
public:
    string print();
};
