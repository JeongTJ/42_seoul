#include "BitcoinExchange.hpp"
#include <iostream>
#include <sstream>
#include <iomanip>

/* *************** */
/* BitcoinExchange */
/* *************** */

BitcoinExchange::BitcoinExchange(const char* inputFile) {
	databaseStream.open(DATABASE);
	if (!databaseStream.is_open())
		throw FileNotOpenException();
	inputStream.open(inputFile);
	if (!inputStream.is_open())
		throw FileNotOpenException();
	fillDatabase();
}

BitcoinExchange::~BitcoinExchange() {
	databaseStream.close();
	inputStream.close();
}

void BitcoinExchange::fillDatabase() {
	Date date;
	char comma;
	double value;
	std::string firstLine;

	getline(databaseStream, firstLine);
	if (firstLine != DATABASE_FIRST_LINE)
		throw InvalidDataBaseFile();

	while (!databaseStream.eof()) {
		databaseStream >> date >> comma >> value;
		if (!databaseStream.fail()) {
			if (comma == ',' && database.find(date) == database.end())
				database[date] = value;
			else {
				databaseStream.setstate(std::ifstream::failbit);
				throw DuplicateDatesException();
			}
		} else if (!databaseStream.eof() && databaseStream.fail())
			throw InvalidDataBaseFile();
	}
}

void BitcoinExchange::print() {
	for (std::map<Date, double>::iterator it = database.begin(); it != database.end(); it++)
		std::cout << (it->first) << " - " << (it->second) << std::endl;
}

void BitcoinExchange::run() {
	Date date;
	char char_or;
	double value;
	std::map<Date, double>::iterator databaseValueIt;
	std::string line;
	std::istringstream iss;

	getline(inputStream, line);
	if (line != INPUT_FIRST_LINE)
		throw InvalidInputFile();

	while (!inputStream.eof()) {
		getline(inputStream, line);
		if (line.empty())
			continue;
		iss.clear();
		iss.str(line);
		iss >> date >> char_or >> value;
		if (char_or != '|' || iss.fail())
			std::cerr << "Error: bad input => " << line << std::endl;
		else if (!iss.eof() || value < 0)
			std::cerr << "Error: not a positive number." << std::endl;
		else if (1000 < value)
			std::cerr << "Error: too large a number." << std::endl;
		else {
			databaseValueIt = database.lower_bound(date);
			if (databaseValueIt != database.begin()) {
				if (databaseValueIt == database.end() || databaseValueIt->first != date)
					databaseValueIt--;
				std::cout << date << " => " << value << " = " << value * databaseValueIt->second << std::endl;
			} else if (databaseValueIt == database.begin()) {
				if (databaseValueIt->first == date)
					std::cout << date << " => " << value << " = " << value * databaseValueIt->second << std::endl;
				else
					std::cerr << "Error: date is too far in the past" << std::endl;
			}
		}
	}
}

/* **** */
/* Date */
/* **** */


BitcoinExchange::Date::Date(): year(1), month(1), day(1) {

}

BitcoinExchange::Date::Date(int y, int m, int d): year(y), month(m), day(d) {

}

BitcoinExchange::Date::~Date() {

}

BitcoinExchange::Date::Date(const Date& other): year(other.year), month(other.month), day(other.day) {

}

BitcoinExchange::Date& BitcoinExchange::Date::operator=(const Date& other) {
	if (this == &other)
		return *this;
	this->year = other.year;
	this->month = other.month;
	this->day = other.day;
	return *this;
}

bool BitcoinExchange::Date::operator==(const Date& other) const {
	return this->year == other.year && this->month == other.month && this->day == other.day;
}

bool BitcoinExchange::Date::operator!=(const Date& other) const {
	return !(*this == other);
}

bool BitcoinExchange::Date::operator<=(const Date& other) const {
	return *this < other || *this == other;
}

bool BitcoinExchange::Date::operator>=(const Date& other) const {
	return *this > other || *this == other;
}

bool BitcoinExchange::Date::operator<(const Date& other) const {
	if (this->year != other.year)
		return this->year < other.year;
	if (this->month != other.month)
		return this->month < other.month;
	return this->day < other.day;
}

bool BitcoinExchange::Date::operator>(const Date& other) const {
	if (this->year != other.year)
		return this->year > other.year;
	if (this->month != other.month)
		return this->month > other.month;
	return this->day > other.day;
}

void BitcoinExchange::Date::setYear(int y) {
	if (!(1 <= y && y <= 9999))
		throw InvalidYear();
	this->year = y;
}

void BitcoinExchange::Date::setMonth(int m) {
	if (!(1 <= m && m <= 12))
		throw InvalidMonth();
	this->month = m;
}

void BitcoinExchange::Date::setDay(int d) {
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		if (!(1 <= d && d <= 31))
			throw InvalidDay();
	if (month == 4 || month == 6 || month == 9 || month == 11)
		if (!(1 <= d && d <= 30))
			throw InvalidDay();
	if (month == 2)
		if (!(1 <= d && d <= 28 + isLeapYear()))
			throw InvalidDay();
	this->day = d;
}

int BitcoinExchange::Date::getYear() const {
	return this->year;
}

int BitcoinExchange::Date::getMonth() const {
	return this->month;
}

int BitcoinExchange::Date::getDay() const {
	return this->day;
}

int BitcoinExchange::Date::isLeapYear() const {
	if (year % 400 == 0)
		return 1;
	if (year % 100 == 0)
		return 0;
	if (year % 4 == 0)
		return 1;
	return 0;
}

/* *********** */
/* InvalidYear */
/* *********** */

BitcoinExchange::Date::InvalidYear::InvalidYear(void) {

}

BitcoinExchange::Date::InvalidYear::~InvalidYear() throw() {

}

BitcoinExchange::Date::InvalidYear::InvalidYear(const InvalidYear& other): std::exception(other) {

}

BitcoinExchange::Date::InvalidYear& BitcoinExchange::Date::InvalidYear::operator=(const InvalidYear& other) {
	if (this == &other)
		return *this;
	return *this;
}

const char* BitcoinExchange::Date::InvalidYear::what(void) const throw() {
	return "BitcoinExchange::Date::InvalidYear";
}


/* ************ */
/* InvalidMonth */
/* ************ */

BitcoinExchange::Date::InvalidMonth::InvalidMonth(void) {

}

BitcoinExchange::Date::InvalidMonth::~InvalidMonth() throw() {

}

BitcoinExchange::Date::InvalidMonth::InvalidMonth(const InvalidMonth& other): std::exception(other) {

}

BitcoinExchange::Date::InvalidMonth& BitcoinExchange::Date::InvalidMonth::operator=(const InvalidMonth& other) {
	if (this == &other)
		return *this;
	return *this;
}

const char* BitcoinExchange::Date::InvalidMonth::what(void) const throw() {
	return "BitcoinExchange::Date::InvalidMonth";
}


/* ********** */
/* InvalidDay */
/* ********** */

BitcoinExchange::Date::InvalidDay::InvalidDay(void) {

}

BitcoinExchange::Date::InvalidDay::~InvalidDay() throw() {

}

BitcoinExchange::Date::InvalidDay::InvalidDay(const InvalidDay& other): std::exception(other) {

}

BitcoinExchange::Date::InvalidDay& BitcoinExchange::Date::InvalidDay::operator=(const InvalidDay& other) {
	if (this == &other)
		return *this;
	return *this;
}

const char* BitcoinExchange::Date::InvalidDay::what(void) const throw() {
	return "BitcoinExchange::Date::InvalidDay";
}


/* ****************** */
/* stream overloading */
/* ****************** */

std::istream& operator>>(std::istream& databaseStream, BitcoinExchange::Date& date) {
	int year, month, day;
	char dash1, dash2;

	if (databaseStream >> year >> dash1 >> month >> dash2 >> day) {
		try {
			date.setYear(year);
			date.setMonth(month);
			date.setDay(day);
		} catch (std::exception& e) {
			databaseStream.setstate(std::istream::failbit);
		}
		if (dash1 != '-' || dash2 != '-')
			databaseStream.setstate(std::istream::failbit);
	} else {
		databaseStream.setstate(std::istream::failbit);
	}
	return databaseStream;
}

std::ostream& operator<<(std::ostream& os, const BitcoinExchange::Date& date) {
	os << std::setfill('0') << std::setw(4) << std::right << date.getYear();
	os << "-";
	os << std::setfill('0') << std::setw(2) << std::right << date.getMonth();
	os << "-";
	os << std::setfill('0') << std::setw(2) << std::right << date.getDay();
	return os;
}

/* ******************** */
/* FileNotOpenException */
/* ******************** */

BitcoinExchange::FileNotOpenException::FileNotOpenException(void) {

}

BitcoinExchange::FileNotOpenException::~FileNotOpenException() throw() {

}

BitcoinExchange::FileNotOpenException::FileNotOpenException(const FileNotOpenException& other): std::exception(other) {

}

BitcoinExchange::FileNotOpenException& BitcoinExchange::FileNotOpenException::operator=(const FileNotOpenException& other) {
	if (this == &other)
		return *this;
	return *this;
}


const char* BitcoinExchange::FileNotOpenException::what(void) const throw() {
	return "BitcoinExchange::FileNotOpenException";
}


/* *********************** */
/* DuplicateDatesException */
/* *********************** */

BitcoinExchange::DuplicateDatesException::DuplicateDatesException(void) {

}

BitcoinExchange::DuplicateDatesException::~DuplicateDatesException() throw() {

}

BitcoinExchange::DuplicateDatesException::DuplicateDatesException(const DuplicateDatesException& other): std::exception(other) {

}

BitcoinExchange::DuplicateDatesException& BitcoinExchange::DuplicateDatesException::operator=(const DuplicateDatesException& other) {
	if (this == &other)
		return *this;
	return *this;
}

const char* BitcoinExchange::DuplicateDatesException::what(void) const throw() {
	return "BitcoinExchange::DuplicateDatesException";
}

/* ******************* */
/* InvalidDataBaseFile */
/* ******************* */

BitcoinExchange::InvalidDataBaseFile::InvalidDataBaseFile(void) {

}

BitcoinExchange::InvalidDataBaseFile::~InvalidDataBaseFile() throw() {

}

BitcoinExchange::InvalidDataBaseFile::InvalidDataBaseFile(const InvalidDataBaseFile& other): std::exception(other) {

}

BitcoinExchange::InvalidDataBaseFile& BitcoinExchange::InvalidDataBaseFile::operator=(const InvalidDataBaseFile& other) {
	if (this == &other)
		return *this;
	return *this;
}

const char* BitcoinExchange::InvalidDataBaseFile::what(void) const throw() {
	return "BitcoinExchange::InvalidDataBaseFile";
}

/* **************** */
/* InvalidInputFile */
/* **************** */

BitcoinExchange::InvalidInputFile::InvalidInputFile(void) {

}

BitcoinExchange::InvalidInputFile::~InvalidInputFile() throw() {

}

BitcoinExchange::InvalidInputFile::InvalidInputFile(const InvalidInputFile& other): std::exception(other) {

}

BitcoinExchange::InvalidInputFile& BitcoinExchange::InvalidInputFile::operator=(const InvalidInputFile& other) {
	if (this == &other)
		return *this;
	return *this;
}

const char* BitcoinExchange::InvalidInputFile::what(void) const throw() {
	return "BitcoinExchange::InvalidInputFile";
}
