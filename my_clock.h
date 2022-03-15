#include <iostream>
using namespace std;

void print(int x)
{
    if (x < 10)
        cout << "0" << x;
    else
        cout << x;
}

class MyClock
{
private:
    int hours;
    int minutes;
    int seconds;
    bool AM;

public:
    MyClock(int seconds)
    {
        this->hours = 10;
        this->minutes = 11;
        this->seconds = seconds;
        this->AM = true;
    }
    MyClock(int minutes, int seconds)
    {
        this->hours = 22;
        this->minutes = minutes;
        this->seconds = seconds;
        this->AM = false;
    }
    MyClock(int hours, int minutes, int seconds)
    {
        this->hours = hours;
        this->minutes = minutes;
        this->seconds = seconds;
        if (hours < 12)
            this->AM = true;
        else
            this->AM = false;
    }

    void currentTime()
    {
        if (hours == 0 || hours == 12)
            cout << "12";
        else
            print(hours % 12);
        cout << ":";
        print(minutes);
        cout << ":";
        print(seconds);
        cout << " ";
        if (AM)
            cout << "AM" << endl;
        else
            cout << "PM" << endl;
    }

    int operator<(MyClock &myClock1)
    {
        if (this->hours % 12 < myClock1.hours % 12)
            return 1;
        else if (this->hours % 12 > myClock1.hours % 12)
            return 0;
        else if (this->minutes < myClock1.minutes)
            return 1;
        else if (this->minutes > myClock1.minutes)
            return 0;
        else if (this->seconds < myClock1.seconds)
            return 1;
        else if (this->seconds > myClock1.seconds)
            return 0;
        else
            return 0;
    }

    ~MyClock()
    {
        this->currentTime();
    }
};