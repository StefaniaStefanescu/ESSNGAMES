#include "cexceptie.h"

CExceptie::CExceptie()
{

}

void CExceptie::LoginError()
{
    QMessageBox msgBox;
    msgBox.setText("Error during login.");
    msgBox.exec();
}

void CExceptie::RegisterError()
{
    QMessageBox msgBox;
    msgBox.setText("Error during register.");
    msgBox.exec();
}

void CExceptie::WrongConfirmation()
{
    QMessageBox msgBox;
    msgBox.setText("Error:: wrong password confirmation.");
    msgBox.exec();
}

void CExceptie::NotAbleToConnect()
{
    QMessageBox msgBox;
    msgBox.setText("There is no connection to the server");
    msgBox.exec();
}

void CExceptie::WaitedforToMuchTime()
{
    QMessageBox msgBox;
    msgBox.setText("The time for the server to respond has expired.");
    msgBox.exec();
}

void CExceptie::DisableConnection()
{
    QMessageBox msgBox;
    msgBox.setText("The session was closed.");
    msgBox.exec();
}

