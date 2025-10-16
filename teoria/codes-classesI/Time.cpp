#include <iostream>
#include <iomanip>
#include <stdexcept> // for illegal_argument exception class
#include "Time.h" // include definition of class Time from Time.h

using namespace std;

Time::Time() : hour (0), minute (0), second (0) {} // init each data member to zero

//Time::Time(int h, int m, int s): hour(h), minute(m), second(s){};

Time::Time (int h, int m, int s) { // set new Time value using universal time
   if ( ( h >= 0 && h < 24 ) && ( m >= 0 && m < 60 ) && 
      ( s >= 0 && s < 60 ) ) { // validate hour, minute and second
      hour = h;
      minute = m;
      second = s;
   } else throw invalid_argument ("hour, minute and/or second was out of range" );
} // end function setTime

void Time::setTime (int h, int m, int s) { // set new Time value using universal time
   if ( ( h >= 0 && h < 24 ) && ( m >= 0 && m < 60 ) && 
      ( s >= 0 && s < 60 ) ) { // validate hour, minute and second
      hour = h;
      minute = m;
      second = s;
   } else throw invalid_argument ("hour, minute and/or second was out of range" );
} // end function setTime

void Time::printUniversal() const { // print Time in universal-time format (HH:MM:SS)
   cout << setfill( '0' ) << setw( 2 ) << hour << ":" 
      << setw( 2 ) << minute << ":" << setw( 2 ) << second;
} // end function printUniversal

void Time::printStandard() const { // print Time in standard-time format (HH:MM:SS AM or PM)
   cout << ( ( hour == 0 || hour == 12 ) ? 12 : hour % 12 ) << ":" 
      << setfill( '0' ) << setw( 2 ) << minute << ":" << setw( 2 )
      << second << ( hour < 12 ? " AM" : " PM" );
} // end function printStandard

int &Time::badSetHour(int hh) {
    hour = (hh >= 0 && hh < 24) ? hh : 0;
    return hour;
}

