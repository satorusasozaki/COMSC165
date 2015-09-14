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

void displayTime(int totalSeconds) {

    for (totalSeconds; ;totalSeconds++) {
        int hours = totalSeconds / (60 * 60);
        int minutes = (totalSeconds - hours * 60 * 60) / 60;
        int seconds = totalSeconds - hours * 60 * 60 - minutes * 60;
        cout << "Time now: ";
        cout  << setfill(' ')<< setw(2) << right << hours << ':';
        cout  << setfill(' ')<< setw(2) << right << minutes << ':';
        cout  << setfill(' ')<< setw(2) << right  << seconds<<'\r';
        cout.flush();
        this_thread::sleep_for (chrono::seconds(1));

    }


}

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

    int totalSeconds = (hours * 60 * 60) + (minutes * 60) + seconds;

    displayTime(totalSeconds);

    return 0;

}
