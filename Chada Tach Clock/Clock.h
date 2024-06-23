//Linkhon Hasan
//5/24/2024

#ifndef CLOCK_H
#define CLOCK_H

#include <iostream>
#include <iomanip>
#include<ctime>

using namespace std;

class Clock
{
	private:
		int hours, minutes, seconds;

	public:

		//sets clock time to be current time
		void setTime() {
			time_t timeNow = time(0);
			tm ltm; 
			localtime_s(&ltm, &timeNow);
			hours = ltm.tm_hour;
			minutes = ltm.tm_min;
			seconds = ltm.tm_sec;
		}

		//member functions to add hours, minutes and seconds
		void addHours() {
			hours = (hours + 1) % 24;
		}

		void addMinutes() {
			minutes = (minutes + 1) % 60;
			if (minutes == 0) {
				addHours();
			}
		}

		void addSecond() {
			seconds = (seconds + 1) % 60;
			if (seconds == 0) {
				addMinutes();
			}
		}
		
		//displays the 12 hour format
		void get12HourFormat() const{
			string amORpm = "A M";

			int displayTime = hours;

			if (hours >= 12) {
				amORpm = "P M";

				if (hours > 12) {
					displayTime = hours - 12;
				}
				else {
					displayTime = hours;
				}
			}

			if (displayTime == 0) {
				displayTime = 12;
			}

			cout<<setfill('0')<<setw(2)<<displayTime<<":"
				<<setfill('0')<<setw(2)<<minutes << ":"
				<<setfill('0')<<setw(2)<<seconds<<" "<<amORpm;
		}

		//displays 24 hour format
		void get24HourFormat() const{
			cout<<setfill('0')<<setw(2)<<hours<<":"
				<<setfill('0')<<setw(2)<<minutes<<":"
				<<setfill('0')<<setw(2)<<seconds;
		}
};

#endif