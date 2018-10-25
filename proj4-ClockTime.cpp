#include "proj4-ClockTime.h"

ClockTime::ClockTime()
: hour(0),
  minute(0),
  second(0),
  secondsPerTick(0),
  deltaTime(0) {
  recordStartTime();
}

ClockTime::ClockTime (int hour, int minute, int second, int secondsPerTick)
: hour(hour),
  minute(minute),
  second(second),
  secondsPerTick(secondsPerTick),
  deltaTime(0) {
  recordStartTime();
}

//The purpose of this method is to reset the time to the recorded
//start time.
void ClockTime::reset() {

	unsigned int temp = this->startTime;

	this->hour = temp / (MINUTES_PER_HOUR * SECONDS_PER_MINUTE);
	temp -= this->hour * (MINUTES_PER_HOUR * SECONDS_PER_MINUTE);

	this->minute = temp / SECONDS_PER_MINUTE;
	temp -= this->minute * SECONDS_PER_MINUTE;

	this->second = temp;
}

//The purpose of this method is to increment the clock time by the number
//of seconds by which the time is to advance per tick.
void ClockTime::tick() {

	this->deltaTime += this->secondsPerTick;

	//Compute the new time in terms of seconds.
	int seconds = this->hour * MINUTES_PER_HOUR * SECONDS_PER_MINUTE +
			      this->minute * SECONDS_PER_MINUTE                  +
				  this->second                                       +
				  this->secondsPerTick;

	//if the new time is greater than the number of seconds in a day, adjust
	//the new time to reflect the number of seconds past midnight.
	if (seconds > (HOURS_PER_DAY * MINUTES_PER_HOUR * SECONDS_PER_MINUTE)) {

		seconds -= (HOURS_PER_DAY * MINUTES_PER_HOUR * SECONDS_PER_MINUTE);
	}

	this->hour = seconds / (MINUTES_PER_HOUR * SECONDS_PER_MINUTE);
	seconds -= this->hour * (MINUTES_PER_HOUR * SECONDS_PER_MINUTE);

	this->minute = seconds / SECONDS_PER_MINUTE;
	seconds -= this->minute * SECONDS_PER_MINUTE;

	this->second = seconds;
}

//The purpose of this method is to display the values stored in
//an instance of simulation time.
ostream& ClockTime::display (ostream &out) const {

	out << right << setw(2) << setfill('0') << this->hour << ":"
		<< right << setw(2) << setfill('0') << this->minute << ":"
		<< right << setw(2) << setfill('0') << this->second << ":";

	return out;
}

//The purpose of this method is to compute and record the start time.
void ClockTime::recordStartTime() {

	this->startTime = this->hour * MINUTES_PER_HOUR * SECONDS_PER_MINUTE +
			          this->minute * SECONDS_PER_MINUTE +
					  this->second;
}
