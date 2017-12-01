/**
 *  Micheál Carroll
 *  C00218621
 *  EX_11
 *  Date calculator
 */

#include <iostream>


//structure for day month and year
struct date
{
    int day;
    int mon;
    int year;
};
date tomdate(date toDate);
int chLeap(int year);
using namespace std;



//main  program
int main()
{
    // declaring 'struct' as 'date today'
    struct date today, tomorrow;
     cout << "Tommorow's date calculator --->  " << endl;
    //to get user to enter the dare
    cout << "\n\nPlease enter a day using two numbers: " << endl;
    cin >> today.day;// store date in today.day


    while(today.day<=0 || today.day>=32)
    {
        cout << "Enter a real day" << endl;
        cin >> today.day;
    }


    cout << "\n\nPlease enter a month using two numbers : " << endl;
    cin >> today.mon;


    while(today.mon<=0 || today.mon>=13)
    {
        cout << "Enter a real mon" << endl;
        cin >> today.mon;
    }

    /**< Promt the user */
    cout << "Please enter a year: " << endl;
    cin >> today.year;


    tomorrow = tomdate(today);// to call the function


    cout << "\n\nTomorrow's date will be the: " << tomorrow.day << "/" << tomorrow.mon << "/" << tomorrow.year << endl;
      // to dispaly tommeors date
    return 0;
}


date tomdate(date toDate)
{

    struct date tomDate;// passing a structure

    tomDate.day = 0;
    tomDate.mon = 0;
    tomDate.year = 0;



    if(toDate.day == 28 && toDate.mon == 2 && !chLeap(toDate.year))
    {

        toDate.day = 1;// to change dare to the 1/3/_
        toDate.mon = 3;
    }

    else if(toDate.day == 28 && toDate.mon == 2 && chLeap(toDate.year))
    {
        toDate.day = 29;
        toDate.mon = 2;

    }

    else if( (toDate.day == 29) && (toDate.mon == 2) && chLeap(toDate.year))
    {

        toDate.day = 1;
        toDate.mon = 3;
    }

    else if(toDate.day == 29 && toDate.mon == 2 && !chLeap(toDate.year))
    {
        cout << "Not a date" << endl;
        return tomDate;
    }
    //**< if the mon has 30days */
    else if(toDate.day == 30)
    {

        if(toDate.mon == 4 || toDate.mon == 6 || toDate.mon == 9 || toDate.mon == 11)
        {

            toDate.day = 1;
            toDate.mon = toDate.mon + 1;
        }

        else if(toDate.mon == 2)
        {
            cout << "not a date" << endl;
            return tomDate;
        }
        else
        {

            toDate.day = 31;
        }
    }

    else if(toDate.day == 31)
    {

        if(toDate.mon == 2)
        {
            cout << "not a date" << endl;
            return tomDate;
        }

        else if(toDate.mon == 4 || toDate.mon == 6 || toDate.mon == 9 || toDate.mon == 11)//the || means a logical or
        {
            cout << "not a date" << endl;
            return tomDate;
        }


        else if(toDate.mon != 12)//not equal to 12
        {

            toDate.day = 1;
            toDate.mon = toDate.mon + 1;
        }
        else
        {

            toDate.day = 1;
            toDate.mon = 1;
            toDate.year = toDate.year + 1;
        }
    }
    else
    {

        toDate.day = toDate.day + 1;// to add one day
    }

    tomDate.day = toDate.day;
    tomDate.mon = toDate.mon;
    tomDate.year = toDate.year;

    return tomDate;
}


int chLeap(int year)// to see it is a leap year or not
{
    if (year % 4 == 0)
    {
    if (year % 100 == 0)
    {
    if (year % 400 == 0)
    {
    return 1;
    }
    else
    return 0;
    }
    else
    {
    return 1;
    }
    }
    else
    return 0;
}
