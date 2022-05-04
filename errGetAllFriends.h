#pragma once
#include <iostream>
#include "IException.h"
using namespace std;

class errGetAllFriends : public IException
{
public:
    string print();
};
