#pragma once
#include <iostream>
using namespace std;

class IException
{
public: virtual string print() = 0;
      class Factory
      {
      public:
          static IException* err_Register();
          static IException* err_Login();
          static IException* err_ADDFriend();
          static IException* err_DeleteFriend();
          static IException* err_GetAllFriends();
          static IException* err_AllTops();
          static IException* err_Top();
          static IException* err_JocDescriere();
          static IException* err_InscriereScore();
          static IException* err_InsertChat();
          static IException* err_SelectChat();
          static IException* err_PathJoc();
          static IException* err_SchimbaParola();
          static IException* err_DenumiriJoc();
          static IException* err_ADDJoc();
      };
};