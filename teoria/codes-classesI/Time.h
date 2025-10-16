#ifndef TIME_H
#define TIME_H

class Time {
public:
   Time(); // constructor
   Time(int, int, int);
   void setTime (int, int, int); // set hour, minute and second
   void printUniversal () const; // print time in univ. format
   void printStandard () const; // print time in stand. format
    int &badSetHour(int);
private:
   int hour; // 0 - 23 (24-hour clock format)
   unsigned int minute; // 0 - 59
   unsigned int second; // 0 - 59
}; // end class Time

#endif

