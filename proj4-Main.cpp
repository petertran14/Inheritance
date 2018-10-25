/*
 * file: proj4-Main.cpp
 * author: Peter Tran
 * course: CSI 1440 Section 3
 * assignment: Project 4
 * due date: April 2, 2018
 * date modified: April 1
 */

#include "proj4-ClockTypes.h"
#include <vector>

const int WEEKS_PER_MONTH = 4;
const int SECONDS_PER_HOUR = 3600;
const int SECONDS_PER_DAY = 86400;
const int DAYS_PER_WEEK = 7;
const int MAX_CLOCK_TYPE = 5;

/*
 * getTime
 *
 * This function returns the days, hours, minutes, and seconds in string format
 *
 * return:
 * -string
 *
 * parameters:
 * -Clock*
 * ClockTime
 *
 * reference parameters
 * -none
 */

string getTime(Clock*, ClockTime);

int main()
{
	//An array of Clock pointer
	vector<Clock*> clocks(MAX_CLOCK_TYPE);

	//instantiate an object of clockTime and clock type to pass to the constructor
	//of each derived class
	ClockTime sTime(0, 0, 0, 1);
	CLOCK_TYPE type;

	for (int i = 0; i < MAX_CLOCK_TYPE; i++) {

		if (i == 0) {

			type = NaturalClock;
			clocks[i] = new SundialClock(type, sTime, SUNDIAL_CLOCK_DRIFT, SUNDIAL_CLOCK_NAME);
		}

		else if (i == 1) {

			type = MechanicalClock;
			clocks[i] = new CuckooClock(type, sTime, CUCKOO_CLOCK_DRIFT, CUCKOO_CLOCK_NAME);
		}

		else if (i == 2) {

			type = MechanicalClock;
			clocks[i] = new GrandfatherClock(type, sTime, GRANDFATHER_CLOCK_DRIFT, GRANDFATHER_CLOCK_NAME);
		}

		else if (i == 3) {

			type = DigitalClock;
			clocks[i] = new WristClock(type, sTime, WRIST_CLOCK_DRIFT, WRIST_CLOCK_NAME);
		}

		else {

			type = QuantumClock;
			clocks[i] = new AtomicClock(type, sTime, ATOMIC_CLOCK_DRIFT, ATOMIC_CLOCK_NAME);
		}

	}

	for (int week = 0; week < WEEKS_PER_MONTH; week++) {

		cout << "Week " << (week + 1) << ", ";

		cout << "Before Clock Runs: " << endl;

			for (int i = 0; i < MAX_CLOCK_TYPE; i++) {

				clocks[i]->displayTime(cout);
				cout << endl;
			}

			cout << endl;

		//get 7 days worth of data
		for (int days = 0; days < DAYS_PER_WEEK; days++) {

			cout << "Day " << (days + 1) << " Simulation" << endl;

			//tick 86400 times per day
			for (int i = 0; i < SECONDS_PER_DAY; i++) {

				//tick once per clock
				for (int cType = 0; cType < MAX_CLOCK_TYPE; cType++) {

					//this is for the display function
					clocks[cType]->tick();
				}

				//this is for the toString display
				sTime.tick();
			}

			cout << "After Clock Runs For An Additional Day: " << endl;

			//Display time before run per clock
			for (int cType = 0; cType < MAX_CLOCK_TYPE; cType++) {

				//this is for the display function
				clocks[cType]->displayTime(cout);
				cout << endl;
				clocks[cType]->reset();
			}

			sTime.reset();

			//this is for space
			cout << endl;
		}

		//Give the weekly summary
		if (week != 3) {

			cout << "Weekly Summary: Approximate Time Elapsed Including Drift: " << endl;
		}

		else {

			cout << "Monthly Summary: " << endl;
		}

		for (int i = 0; i < MAX_CLOCK_TYPE; i++) {

			cout << clocks[i]->getName() << ": " << getTime(clocks[i], sTime) << endl;
		}

		cout << endl;
	}

	//delete the clock pointers in the vector
	for (int i = 0; i < MAX_CLOCK_TYPE; i++) {

		delete clocks[i];
		clocks[i] = NULL;
	}

	return 0;
}

string getTime(Clock* time, ClockTime support) {

	ostringstream os;
	int days = 0, hours = 0, minutes = 0, seconds = 0;
	int total = support.getDeltaTime() + (support.getDeltaTime() * time->getDriftPerSecond());

	//Modulus 29 so we can hold the final day 28
	days = (total / SECONDS_PER_DAY) % 29;
	hours = (total / SECONDS_PER_HOUR) % 24;
	minutes = (total / SECONDS_PER_MINUTE) % 60;
	seconds = total % 60;

	os << days << " day(s), " << hours << " hour(s), " << minutes << " minute(s), " << seconds << " second(s).";

	return os.str();
}
