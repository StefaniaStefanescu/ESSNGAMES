#pragma once
#include <iostream>
#include "IException.h"
using namespace std;

class errInsertChat : public IException
{
public:
    string print();
};
