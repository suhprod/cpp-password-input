
/**
    OPEN-SOURCE LIBRARY - edit and improve,
    BY Shabbir ul Hassan,
    JAN 2012
**/

/*

Created By: SUH Productions!

This is a simple data-type for easing users task for inputing
password in a program. It disallows actual characters from appearing
on the screen and puts '*' character on screen so that it does not show
the actual password for security and safety of the program!!!

Regards,
Shabbir ul Hassan.

*/

#ifndef PASSWORD_H
#define PASSWORD_H

#include <iostream> //for error messeges
using namespace std;
#include <conio.h> //for 'getch' & for 'putch'
#include <string>  //for string data-type!

class PasswordString
{
    string password;
    int limit;  /// for the limit of password!

    void setPassword(string p) { password=p; }

    public:

    /// Constructor...overloaded if u want limited length (should be greater than 0) password!
    PasswordString(unsigned int l)
    {
        password="";
        if(l>0)
        {limit=l;}
        else
        {
            cout<<"\nWrong Limit Entered for Password!...It should be greater than 0\nSo, Default Limit of 50 added!";
            limit=50;
        }
    }

    /// Default Constructor!
    PasswordString()
    {
        password="";
        limit=50;
    }

    const string getPassword(){ return password;} /// Returns original Password!
    const unsigned int getLimit() { return limit; }
    void clearPassword(){ password=""; } /// Clears the password!
    unsigned int getPasswordsize(){return password.length();}

    void setLimit(int l) /// Only sets limit if password is already empty!
    {
        if(this->getPassword().length()==0)
        limit=l;
        else
        cout<<"\nPassword entered already...cannot change its limit now\nFirst clear password!";
    }
    void showPassword(char style='*') ///Shows masked-password in STYLE!!! :P
    {
        for(unsigned int i=0;i<password.length();i++)
        cout<<style;
    }

    /// OVERLOADED OPERATORS ///

    bool operator == (PasswordString& b) /// checks the equality of password!
    {
        if(password==b.getPassword())
            return true;
        return false;
    }
    void operator = (PasswordString& b)
    {
        limit=b.getLimit();
        password=b.getPassword();
    }

    friend istream& operator >>(istream& in, PasswordString& big) ///Simple input method for password - through cin!
    {
        char* str=new char[(big.getLimit()*3)];
        for(unsigned int z=0;z<big.getLimit();z++) str[z]=0;
        int i=0,ch=0;
        int chk=0;
        while(int(str[i])!=13)
        {
            ch=getch();
            if(ch==13)
            {
                break;
            }
            else if(ch==8)
            {
                if(chk>0)
                {
                    putch('\b');
                    putch(NULL);
                    putch('\b');
                    chk--;
                    i--;
                    continue;
                }
            }
            if(ch!=8)
            {
                str[i]=ch;
                ch='*';
                putch(ch);
                chk++;
                i++;
            }
        }
        int indd=big.getLimit()*3;
        char* fpass=new char[indd];
        for(int y=0;y<indd;y++) fpass[y]=0;
        int s=0;
        while(s!=i)
        {
            fpass[s]=str[s];
            s++;
        }
        big.setPassword(fpass);
        if(big.getPassword().length()>big.getLimit())
        {
            cout<<"\nLimit exceeded for password...";
            big.clearPassword();
        }
        else if(big.getPassword().length()==0)
        {
            cout<<"\nNo Password Entered!";
        }
        delete []str;
        delete []fpass;
        return in;
    }
};

#endif /// PASSWORD_H
