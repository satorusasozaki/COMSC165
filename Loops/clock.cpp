// system_clock::to_time_t
#include <thread>
#include <iostream>
#include <ctime>
#include <ratio>
#include <chrono>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;
int main ()
{
  chrono::system_clock::time_point today = chrono::system_clock::now();
  time_t tt;
  tt = chrono::system_clock::to_time_t ( today );
  string t = ctime(&tt);
  string garbage;
  string clock;
  stringstream(t) >> garbage >> garbage >> garbage >> clock;

  int hours, minutes, seconds;
  char c;

  stringstream(clock) >> hours >> c >>minutes>> c >> seconds;

  for (; hours < 24; hours++) {
        for (; minutes < 60; minutes++ ) {
              for (; seconds < 60; seconds++) {
                    cout << "Time now: ";
                    cout  << setfill(' ')<< setw(2) << right << hours << ':';
                    cout  << setfill(' ')<< setw(2) << right << minutes << ':';
                    cout  << setfill(' ')<< setw(2) << right  << seconds<<'\r';
                    cout.flush();
                    this_thread::sleep_for (chrono::seconds(1));
              }
              seconds = 0;
        }
        minutes = 0;
  }
  return 0;
}
