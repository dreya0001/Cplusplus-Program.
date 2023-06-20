/* Name: Andreya Colvin
   Date: May 18th, 2023
   Class: CS210*/
// creating a clock that is 12 hour and 24 hour
#include <iostream>
#include <iomanip>
#include <ctime>
#include <vector>

using namespace std;

class Clock {
private:
	int hour;
	int minute;
	int second;
	bool is24HourFormat;

public:
	Clock(bool format24Hour = true) : is24HourFormat(format24Hour) {
		setCurrentTime(); // Set time to current time
	}
	int getHour() const {
		return hour;
	}
	int getMinute() const {
		return minute;
	}
	int getSecond() const {
		return second;
	}
	void setCurrentTime() {
		time_t currentTime = time(0); // Get current time
		struct tm * now = localtime(&currentTime); // Convert to local time

		hour = now->tm_hour; // current hour
		minute = now->tm_min; // current minute
		second = now->tm_sec; // current second
	}
	void setTime(int h, int m, int s) {
		if (is24HourFormat) {
			if (h < 0 || h > 23 || m < 0 || m > 59 || s < 0 || s > 59) {
				cout << "Invalid Time" << endl; // invalid time
				return;
			}
		}
		else {
			if (h < 0 || h > 12 || m < 0 || m > 59 || s < 0 || s > 59) {
				cout << "Invalid Time" << endl; // invalid time
				return;

			}
		}
		hour = h; // set new hour
		minute = m; // set new mintute
		second = s; // set new second
	}
	void toggleFormat() {
		is24HourFormat = !is24HourFormat; // toggle 12 - 24 format
	}
	void displayTime() {
		cout << "----" << endl;
		if (is24HourFormat) {
			cout << "24-Hour Clock: ";
			cout << setfill('0') << setw(2) << hour << ":" << setw(2) << minute << ":" << setw(2) << second << endl;
		} else {
			cout << "12-Hour Clock: ";
			int displayHour = hour % 12; // convet hour to 12-hour format
			if (displayHour == 0)
				displayHour = 12;
			cout << setfill('0') << setw(2) << displayHour << ":" << setw(2) << minute << ":" << setw(2) << second;
			if (hour < 12)
				cout << " AM" << endl; // display hours for AM (morning)
			else
				cout << " PM" << endl; // display hours for PM (afternoon)
		}
		cout << "----" << endl;
	}
};
int main() {
	Clock clock24(true); //Clock with 24 hour format
	Clock clock12(false); //Clock with 12 hour format

	int choice = 0;
	int hours, minutes, seconds;

	while (choice != 6) {
		cout << "Menu: " << endl;
		cout << "1. Set Time" << endl;
		cout << "2. Add Hour" << endl;
		cout << "3. Add Minute" << endl;
		cout << "4. Add Second" << endl;
		cout << "5. Display Time" << endl;
		cout << "6. Exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
			cout << "Enter the time (hh:mm:ss): ";
			cin >> hours >> minutes >> seconds;
			clock24.setTime(hours, minutes, seconds);
			clock12.setTime(hours, minutes, seconds);
			break;
		case 2:
			cout << "Enter the number of hours to add: ";
			cin >> hours;
			clock24.setTime((clock24.getHour() + hours) % 24, clock24.getMinute(), clock24.getSecond());
			clock12.setTime((clock12.getHour() + hours) % 12, clock12.getMinute(), clock12.getSecond());
			break;
		case 3:
			cout << "Enter the number of minutes to add: ";
			cin >> minutes;
			clock24.setTime(clock24.getHour(), (clock24.getMinute() + minutes) % 60, clock24.getSecond());
			clock12.setTime(clock12.getHour(), (clock12.getMinute() + minutes) % 60, clock12.getSecond());
			break;
		case 4:
			cout << "Enter the number of seconds to add: ";
			cin >> seconds;
			clock24.setTime(clock24.getHour(), clock24.getMinute(), (clock24.getSecond() + seconds) % 60);
			clock12.setTime(clock12.getHour(), clock12.getMinute(), (clock12.getSecond() + seconds) % 60);
			break;
		case 5:
			cout << "24-Hour Format:" << endl;
			clock24.displayTime();
			cout << "12-Hour Format:" << endl;
			clock12.displayTime();
			break;
		case 6:
			cout << "Exiting the program" << endl;
			break;
		default:
			cout << "Invalid choice!" << endl;
			break;
		}
	}
	return 0;
}
