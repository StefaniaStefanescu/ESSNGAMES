#pragma once
#include <iostream>
#include "IException.h"
using namespace std;

class errInscriereScore : public IException
{
public:
    string print();
};