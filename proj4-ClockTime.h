#ifndef PROJ4_CLOCKTIME_H_
#define PROJ4_CLOCKTIME_H_

#include <iostream>
#include <iomanip>

using namespace std;

//Define a set of symbolic constants used to specify various values
//related to time keeping.
#define SECONDS_PER_MINUTE     60
#define MINUTES_PER_HOUR       60
#define HOURS_PER_DAY          24
//ClockTime is a concrete identity class used to keep track of current
//time as it is moving forward. Note that time cannot be regressed.

//Note: Copying an instance of this class is bit-wise.
class ClockTime {

private:
	int hour;
	int minute;
	int second;
	int secondsPerTick;
	unsigned int startTime;
	unsigned int deltaTime;

	void recordStartTime();

public:
	ClockTime();
	ClockTime(int hour, int minute, int second, int secondsPerTick);
	~ClockTime()
	{
		this->hour = this->minute = this->second = this->secondsPerTick = this->startTime = 0;
	}
	int const getHour() const { return this->hour; }
	int const getMinute() const { return this->minute; }
	int const getSecond() const { return this->second; }
	int const getSecondPerTick() const { return this->secondsPerTick; }

	unsigned int getStartTime () const { return this->startTime; }
	unsigned int getDeltaTime() const { return this->deltaTime; }

	void setTime (ClockTime const& initialTime)
	{
		this->hour = initialTime.hour;
		this->minute = initialTime.minute;
		this->second = initialTime.second;
		this->secondsPerTick = initialTime.secondsPerTick;
		this->deltaTime = 0;
	}

	void setTime (int hour, int minute, int second, int secondsPerTick)
	{
		this->hour = hour;
		this->minute = minute;
		this->second = second;
		this->secondsPerTick = secondsPerTick;
		this->deltaTime = 0;
	}
	void reset();
	void tick();
	ostream& display(ostream&) const;
};

#endif /* PROJ4_CLOCKTIME_H_ */
