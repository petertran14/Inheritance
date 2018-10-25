/*
 * file: proj4-ClockTypes.cpp
 * author: Peter Tran
 * course: CSI 1440 Section 3
 * assignment: Project 4
 * due date: April 2, 2018
 * date modified: April 1
 */

#include "proj4-ClockTypes.h"

Clock::Clock(CLOCK_TYPE const t, ClockTime const& initialTime,
		  double const dps, char const* const ch)
{
	type = t;
	clockTime = initialTime;
	driftPerSecond = dps;
	name = new char[MAX_CLOCK_NAME];

	int count = 0;
	while (ch[count] != '\0') {

		name[count] = ch[count];
		count++;
	}

	name[count] = '\0';
}

Clock::~Clock() {

	delete [] name;
	name = NULL;
	//cout << "Deleted" << endl;
}

Clock::Clock(const Clock& that) {

	this->type = that.type;
	this->driftPerSecond = that.driftPerSecond;
	this->clockTime = that.clockTime;

	int size = 1;
	while (that.name[size] != '\0') {

		size++;
	}

	this->name = new char[size];

	for (int i = 0; i < size; i++) {

		this->name[i] = that.name[i];
	}
}

char const* const Clock::getName() const {

	return name;
}

double const Clock::getDriftPerSecond() const {

	return driftPerSecond;
}

SundialClock& SundialClock::operator=(const SundialClock& that) {
	if (this != &that) {

		this->type = that.type;
		this->driftPerSecond = that.driftPerSecond;
		this->clockTime = that.clockTime;

		delete [] this->name;

		int size = 0;
		while (that.name[size] != '\0') {

			size++;
		}

		this->name = new char[size];

		for (int i = 0; i < size; i++) {

			this->name[i] = that.name[i];
		}
	}

	return *this;
}

ostream& SundialClock::displayTime(ostream& out) const {

	int count = 0;
	while (this->name[count] != '\0') {

		out << this->name[count];
		count++;
	}

	//part of the natural clock base class
	if (this->type == 0) {

		out << "-Natural's Clock Time:";
	}

	else if (this->type == 1)  {

		out << "-Mechanical's Clock Time:";
	}

	else if (this->type == 2)  {

		out << "-Digital's Clock Time:";
	}

	else if (this->type == 3)  {

		out << "-Quantum's Clock Time:";
	}

	out << "[";
	clockTime.display(out);
	out << "]";

	out << "-> " << "total drift = "
		<< getDriftPerSecond() * clockTime.getDeltaTime() << " seconds";

	return out;
}

string SundialClock::toString() {

	ostringstream os;

	os << "Derived Clock Type Number: " << this->type;

	os << "\n" << "Derived From: ";

	os << "Natural Clock";

	os << "\nName: ";

		int count = 0;
		while (name[count] != '\0') {

			os << name[count];
			count++;
		}

	os << "\nClock Drift: " << this->driftPerSecond << "\n";

	return os.str();
}

void SundialClock::reset() {

	clockTime.reset();
}

void SundialClock::tick() {

	this->clockTime.tick();
}

WristClock& WristClock::operator=(const WristClock& that)
{
	if (this != &that) {

		this->type = that.type;
		this->driftPerSecond = that.driftPerSecond;
		this->clockTime = that.clockTime;

		delete [] this->name;

		int size = 0;
		while (that.name[size] != '\0') {

			size++;
		}

		this->name = new char[size];

		for (int i = 0; i < size; i++) {

			this->name[i] = that.name[i];
		}
	}

	return *this;
}

void WristClock::reset() {

	clockTime.reset();
}

void WristClock::tick() {

	this->clockTime.tick();
}

ostream& WristClock::displayTime(ostream& out) const {

	int count = 0;
	while (this->name[count] != '\0') {

		out << this->name[count];
		count++;
	}

	//part of the natural clock base class
	if (this->type == 0) {

		out << "-Natural's Clock Time:";
	}

	else if (this->type == 1)  {

		out << "-Mechanical's Clock Time:";
	}

	else if (this->type == 2)  {

		out << "-Digital's Clock Time:";
	}

	else if (this->type == 3)  {

		out << "-Quantum's Clock Time:";
	}

	out << "[";
	clockTime.display(out);
	out << "]";

	out << "-> " << "total drift = "
		<< getDriftPerSecond() * clockTime.getDeltaTime() << " seconds";

	return out;
}

string WristClock::toString() {

	ostringstream os;

	os << "Derived Clock Type Number: " << this->type;

	os << "\n" << "Derived From: ";

	os << "Digital Clock";

	os << "\nName: ";

		int count = 0;
		while (name[count] != '\0') {

			os << name[count];
			count++;
		}

	os << "\nClock Drift: " << this->driftPerSecond << "\n";

	return os.str();
}

AtomicClock&  AtomicClock::operator=(const AtomicClock& that) {

	if (this != &that) {

		this->type = that.type;
		this->driftPerSecond = that.driftPerSecond;
		this->clockTime = that.clockTime;

		delete [] this->name;

		int size = 0;
		while (that.name[size] != '\0') {

			size++;
		}

		this->name = new char[size];

		for (int i = 0; i < size; i++) {

			this->name[i] = that.name[i];
		}
	}

	return *this;
}

void AtomicClock::reset() {

	clockTime.reset();
}

void AtomicClock::tick() {

	this->clockTime.tick();
}

ostream& AtomicClock::displayTime(ostream& out) const {

	int count = 0;
	while (this->name[count] != '\0') {

		out << this->name[count];
		count++;
	}

	//part of the natural clock base class
	if (this->type == 0) {

		out << "-Natural's Clock Time:";
	}

	else if (this->type == 1)  {

		out << "-Mechanical's Clock Time:";
	}

	else if (this->type == 2)  {

		out << "-Digital's Clock Time:";
	}

	else if (this->type == 3)  {

		out << "-Quantum's Clock Time:";
	}

	out << "[";
	clockTime.display(out);
	out << "]";

	out << "-> " << "total drift = "
		<< getDriftPerSecond() * clockTime.getDeltaTime() << " seconds";

	return out;
}

string AtomicClock::toString() {

	ostringstream os;

	os << "Derived Clock Type Number: " << this->type;

	os << "\n" << "Derived From: ";

	os << "Quantum Clock";

	os << "\nName: ";

		int count = 0;
		while (name[count] != '\0') {

			os << name[count];
			count++;
		}

	os << "\nClock Drift: " << this->driftPerSecond << "\n";

	return os.str();
}

CuckooClock& CuckooClock::operator=(const CuckooClock& that) {

	if (this != &that) {

		this->type = that.type;
		this->driftPerSecond = that.driftPerSecond;
		this->clockTime = that.clockTime;

		delete [] this->name;

		int size = 0;
		while (that.name[size] != '\0') {

			size++;
		}

		this->name = new char[size];

		for (int i = 0; i < size; i++) {

			this->name[i] = that.name[i];
		}
	}

	return *this;
}

void CuckooClock::reset() {

	clockTime.reset();
}

void CuckooClock::tick() {

	this->clockTime.tick();
}

ostream& CuckooClock::displayTime(ostream& out) const {

	int count = 0;
	while (this->name[count] != '\0') {

		out << this->name[count];
		count++;
	}

	//part of the natural clock base class
	if (this->type == 0) {

		out << "-Natural's Clock Time:";
	}

	else if (this->type == 1)  {

		out << "-Mechanical's Clock Time:";
	}

	else if (this->type == 2)  {

		out << "-Digital's Clock Time:";
	}

	else if (this->type == 3)  {

		out << "-Quantum's Clock Time:";
	}

	out << "[";
	clockTime.display(out);
	out << "]";

	out << "-> " << "total drift = "
		<< getDriftPerSecond() * clockTime.getDeltaTime() << " seconds";

	return out;
}

string CuckooClock::toString() {

	ostringstream os;

	os << "Derived Clock Type Number: " << this->type;

	os << "\n" << "Derived From: ";

	os << "Mechanical Clock";

	os << "\nName: ";

		int count = 0;
		while (name[count] != '\0') {

			os << name[count];
			count++;
		}

	os << "\nClock Drift: " << this->driftPerSecond << "\n";

	return os.str();
}

GrandfatherClock& GrandfatherClock::operator=(const GrandfatherClock& that) {

	if (this != &that) {

		this->type = that.type;
		this->driftPerSecond = that.driftPerSecond;
		this->clockTime = that.clockTime;

		delete [] this->name;

		int size = 0;
		while (that.name[size] != '\0') {

			size++;
		}

		this->name = new char[size];

		for (int i = 0; i < size; i++) {

			this->name[i] = that.name[i];
		}
	}

	return *this;
}

void GrandfatherClock::reset() {

	clockTime.reset();
}

void GrandfatherClock::tick() {

	this->clockTime.tick();
}

ostream& GrandfatherClock::displayTime(ostream& out) const {

	int count = 0;
	while (this->name[count] != '\0') {

		out << this->name[count];
		count++;
	}

	//part of the natural clock base class
	if (this->type == 0) {

		out << "-Natural's Clock Time:";
	}

	else if (this->type == 1)  {

		out << "-Mechanical's Clock Time:";
	}

	else if (this->type == 2)  {

		out << "-Digital's Clock Time:";
	}

	else if (this->type == 3)  {

		out << "-Quantum's Clock Time:";
	}

	out << "[";
	clockTime.display(out);
	out << "]";

	out << "-> " << "total drift = "
		<< getDriftPerSecond() * clockTime.getDeltaTime() << " seconds";

	return out;
}

string GrandfatherClock::toString() {

	ostringstream os;

	os << "Derived Clock Type Number: " << this->type;

	os << "\n" << "Derived From: ";

	os << "Mechanical Clock";

	os << "\nName: ";

		int count = 0;
		while (name[count] != '\0') {

			os << name[count];
			count++;
		}

	os << "\nClock Drift: " << this->driftPerSecond << "\n";

	return os.str();
}
