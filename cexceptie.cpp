#include "cexceptie.h"

CExceptie::CExceptie()
{

}

void CExceptie::LoginError()
{
    QMessageBox::warning(0,"Oops","Error during login.");
}

void CExceptie::RegisterError()
{
    QMessageBox::warning(0,"Oops","Error during register.");
}

void CExceptie::WrongConfirmation()
{
    QMessageBox::warning(0,"Critical Error","You didn't write a good confirmaion for your password.");
}

void CExceptie::NotAbleToConnect()
{
    QMessageBox::critical(0,"Critical Error","There is no connection to the server");
}

void CExceptie::WaitedforToMuchTime()
{
     QMessageBox::critical(0,"Connection issue","The time for the server to respond has expired.");
}

void CExceptie::DisableConnection()
{
    QMessageBox::information(0,"End","The session was closed.");
}

void CExceptie::AddFriendError()
{
    QMessageBox::information(0,"OOPPS","The username you've searched is invalid.");
}

void CExceptie::DeleteFriendError()
{
    QMessageBox::information(0,"OOPPS","Couldn't perform the action.Try again later.");
}


