#pragma once
#include <iostream>
#include "IException.h"
using namespace std;

class errSelectChat : public IException
{
public:
    string print();
};
