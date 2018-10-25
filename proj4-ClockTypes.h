/*
 * file: proj4-ClockTypes.h
 * author: Peter Tran
 * course: CSI 1440 Section 3
 * assignment: Project 4
 * due date: April 2, 2018
 * date modified: April 1
 */

#ifndef PROJ4_CLOCKTYPES_H_
#define PROJ4_CLOCKTYPES_H_

#include "proj4-ClockTime.h"
#include <sstream>

const int MAX_CLOCK_NAME = 30;

//pass these as the clock names
const char SUNDIAL_CLOCK_NAME[MAX_CLOCK_NAME] = "Sundial Clock";
const char ATOMIC_CLOCK_NAME[MAX_CLOCK_NAME] = "Atomic Clock";
const char CUCKOO_CLOCK_NAME[MAX_CLOCK_NAME] = "Cuckoo Clock";
const char GRANDFATHER_CLOCK_NAME[MAX_CLOCK_NAME] = "Grandfather Clock";
const char WRIST_CLOCK_NAME[MAX_CLOCK_NAME] = "Wrist Clock";

const double SUNDIAL_CLOCK_DRIFT = 0.0;
const double ATOMIC_CLOCK_DRIFT = 0.0;
const double CUCKOO_CLOCK_DRIFT = 0.000694444;
const double GRANDFATHER_CLOCK_DRIFT = 0.000347222;
const double WRIST_CLOCK_DRIFT = 0.000034722;

//pass these as the clock types
enum CLOCK_TYPE {NaturalClock, MechanicalClock, DigitalClock, QuantumClock};

class Clock
{
protected:
	CLOCK_TYPE type;
	double driftPerSecond;
	char *name;
	ClockTime clockTime;

public:
	//constructor
	Clock(CLOCK_TYPE const t, ClockTime const& initialTime,
		  double const dps, char const* const ch);
	//destructor
	virtual ~Clock();

	//Copy Constructor
	Clock(const Clock& that);

	//these are going to be inherited but they are going to be
	//overriden for each non-abstract class

	/**
	 * reset
	 *
	 * This function resets the hours, minutes, seconds, and start time back to 0
	 * but leacves delta time untouched
	 *
	 * Parameters:
	 * -none
	 *
	 * Output:
	 * return: void
	 * reference parameters: none
	 * stream: none
	 */
	virtual void reset() = 0;

	/**
	 * tick
	 *
	 * This function formats the time, and increment delta time
	 *
	 * Parameters:
	 * -none
	 *
	 * Output:
	 * return: void
	 * reference parameters: none
	 * stream: none
	 */
	virtual void tick() = 0;

	/**
	 * displayTime
	 *
	 * This function formats the data to be displayed neatly
	 *
	 * Parameters:
	 * n: the number on which to computer the factorial
	 *
	 * Output:
	 * return: ostream&
	 * reference parameters: ostream&
	 * stream: ostream&
	 */
	virtual ostream& displayTime(ostream&) const = 0;

	/**
	 * toString
	 *
	 * This function stores all the protected data members in a stringstream
	 * and it is useful for testing functions and displaying data
	 *
	 * Parameters:
	 * -none
	 *
	 * Output:
	 * return: string
	 * reference parameters: none
	 * stream: none
	 */
	virtual string toString() = 0;

	//these are going to be inherited by all the other classes
	//they are not going to be overriden though

	/**
	 * getName
	 *
	 * This function returns the name member variable of the object of which
	 * it was called.
	 *
	 * Parameters:
	 * -none
	 *
	 * Output:
	 * return: char const*
	 * reference parameters: none
	 * stream: none
	 */
	char const* const getName() const;

	/**
	 * getDriftPerSecond
	 *
	 * This function returns the drift per second of the object
	 *in which it was called
	 *
	 * Parameters:
	 * -none
	 *
	 * Output:
	 * return: double const
	 * reference parameters: none
	 * stream: none
	 */
	double const getDriftPerSecond() const;
};

class NaturalClock : public Clock
{
public:
	NaturalClock(CLOCK_TYPE const t, ClockTime const& initialTime,
			double const dps, char const* const ch) : Clock(t, initialTime, dps, ch) {}
	NaturalClock(const NaturalClock& other) : Clock(other) {}
	virtual ~NaturalClock() {}
	virtual void reset() = 0;
	virtual void tick() = 0;
	virtual ostream& displayTime(ostream&) const = 0;
	virtual string toString() = 0;
};

class MechanicalClock : public Clock
{
public:
	MechanicalClock(CLOCK_TYPE const t, ClockTime const& initialTime,
			double const dps, char const* const ch) : Clock(t, initialTime, dps, ch) {}
	MechanicalClock(const MechanicalClock& other) : Clock(other) {}
	virtual ~MechanicalClock() {}
	virtual void reset() = 0;
	virtual void tick() = 0;
	virtual ostream& displayTime(ostream&) const = 0;
	virtual string toString() = 0;
};

class DigitalClock : public Clock
{
public:
	DigitalClock(CLOCK_TYPE const t, ClockTime const& initialTime,
			double const dps, char const* const ch) : Clock(t, initialTime, dps, ch) {}
	DigitalClock(const DigitalClock& other) : Clock(other) {}
	virtual ~DigitalClock() {}
	virtual void reset() = 0;
	virtual void tick() = 0;
	virtual ostream& displayTime(ostream&) const = 0;
	virtual string toString() = 0;
};

class QuantumClock : public Clock
{
public:
	QuantumClock(CLOCK_TYPE const t, ClockTime const& initialTime,
			double const dps, char const* const ch) : Clock(t, initialTime, dps, ch) {}
	QuantumClock(const QuantumClock& other) : Clock(other) {}
	virtual ~QuantumClock() {}
	virtual void reset() = 0;
	virtual void tick() = 0;
	virtual ostream& displayTime(ostream&) const = 0;
	virtual string toString() = 0;
};

class SundialClock : public NaturalClock
{
public:
	//Big 4, constructor, destructor, and copy constructor is passed and called
	//through the hierarchy. The assignment operator overload requires we return
	//information relevant to this class so we can't do that.
	SundialClock(CLOCK_TYPE const t, ClockTime const& initialTime,
				double const dps, char const* const ch) : NaturalClock(t, initialTime, dps, ch) {}
	virtual ~SundialClock() {}
	SundialClock& operator=(const SundialClock& that);
	SundialClock (const SundialClock& that) : NaturalClock(that) {}

	void reset();
	void tick();
	ostream& displayTime(ostream& out) const;
	string toString();
};

class WristClock : public DigitalClock
{
public:
	WristClock(CLOCK_TYPE const t, ClockTime const& initialTime,
			   double const dps, char const* const ch) : DigitalClock(t, initialTime, dps, ch) {};
	virtual ~WristClock() {}
	WristClock(const WristClock& that) : DigitalClock(that) {}
	WristClock& operator=(const WristClock& that);

	void reset();
	void tick();
	ostream& displayTime(ostream& out) const;
	string toString();
};

class AtomicClock : public QuantumClock
{
public:
	AtomicClock(CLOCK_TYPE const t, ClockTime const& initialTime,
			double const dps, char const* const ch) : QuantumClock(t, initialTime, dps, ch) {};
	AtomicClock(const AtomicClock& other) : QuantumClock(other) {}
	virtual ~AtomicClock() {}
	AtomicClock& operator=(const AtomicClock& that);

	void reset();
	void tick();
	ostream& displayTime(ostream& out) const;
	string toString();
};

class CuckooClock : public MechanicalClock
{
public:
	CuckooClock(CLOCK_TYPE const t, ClockTime const& initialTime,
				double const dps, char const* const ch) : MechanicalClock(t, initialTime, dps, ch) {};
	CuckooClock(const CuckooClock& other) : MechanicalClock(other) {}
	virtual ~CuckooClock() {}
	CuckooClock& operator=(const CuckooClock& that);

	void reset();
	void tick();
	ostream& displayTime(ostream& out) const;
	string toString();
};

class GrandfatherClock : public MechanicalClock
{
public:
	GrandfatherClock(CLOCK_TYPE const t, ClockTime const& initialTime,
			double const dps, char const* const ch) : MechanicalClock(t, initialTime, dps, ch) {};
	GrandfatherClock(const GrandfatherClock& other) : MechanicalClock(other) {}
	virtual ~GrandfatherClock() {}
	GrandfatherClock& operator=(const GrandfatherClock& that);

	void reset();
	void tick();
	ostream& displayTime(ostream& out) const;
	string toString();

};

#endif /* PROJ4_CLOCKTYPES_H_ */
