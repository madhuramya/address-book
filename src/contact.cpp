#include <algorithm>
#include <string>
#include <sstream>
#include <stdexcept>
#include <vector>
#include <String>
#include <QMessageBox>
#include <QString>
#include "contact.h"
#include "qtcontactform.h"

bool Contact::isValidToAdd() const
{
    /*
    Adding a new contact requires:
    -first name
    -last name
    -phone number
    */

    bool hasNames = !(firstName.empty() || lastName.empty());

    if(hasNames && !phoneNumber.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Contact::isEmpty() const
{
    if(firstName.empty() && 
        lastName.empty() &&
        phoneNumber.empty() && 
        address.empty() && 
        email.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Contact::isValidToemail() const
{

   //QMessageBox msgBox;


    if ((email.begin()=std::find(email.begin(), email.end(), '@')) != email.end() &&
          std::find(email.begin(), email.end(), '.') != email.end())
    {

        return true;

    }
    else
    {
         return false;

    }
}

