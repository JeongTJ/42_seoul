#pragma once
#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <fstream>
# define DATABASE "data.csv"
# define DATABASE_FIRST_LINE "date,exchange_rate"
# define INPUT_FIRST_LINE "date | value"

class BitcoinExchange {
	public:
		class Date {
			public:
				Date();
				Date(int y, int m, int d);
				~Date();
				Date(const Date& other);
				Date& operator=(const Date& other);
				bool operator==(const Date& other) const;
				bool operator!=(const Date& other) const;
				bool operator<=(const Date& other) const;
				bool operator>=(const Date& other) const;
				bool operator<(const Date& other) const;
				bool operator>(const Date& other) const;
				void setYear(int y);
				void setMonth(int m);
				void setDay(int d);
				int getYear() const;
				int getMonth() const;
				int getDay() const;
			private:
				class InvalidYear: public std::exception {
					public:
						InvalidYear(void);
						~InvalidYear() throw();
						InvalidYear(const InvalidYear& other);
						InvalidYear& operator=(const InvalidYear& other);
						const char* what(void) const throw();
				};
				class InvalidMonth: public std::exception {
					public:
						InvalidMonth(void);
						~InvalidMonth() throw();
						InvalidMonth(const InvalidMonth& other);
						InvalidMonth& operator=(const InvalidMonth& other);
						const char* what(void) const throw();
				};
				class InvalidDay: public std::exception {
					public:
						InvalidDay(void);
						~InvalidDay() throw();
						InvalidDay(const InvalidDay& other);
						InvalidDay& operator=(const InvalidDay& other);
						const char* what(void) const throw();
				};
				int isLeapYear() const;
				int year;
				int month;
				int day;
		};
		BitcoinExchange(const char* inputFile);
		~BitcoinExchange();
		void print();
		void run();

	private:
		class FileNotOpenException: public std::exception {
			public:
				FileNotOpenException(void);
				~FileNotOpenException() throw();
				FileNotOpenException(const FileNotOpenException& other);
				FileNotOpenException& operator=(const FileNotOpenException& other);
				const char* what(void) const throw();
		};
		class DuplicateDatesException: public std::exception {
			public:
				DuplicateDatesException(void);
				~DuplicateDatesException() throw();
				DuplicateDatesException(const DuplicateDatesException& other);
				DuplicateDatesException& operator=(const DuplicateDatesException& other);
				const char* what(void) const throw();
		};
		class InvalidDataBaseFile: public std::exception {
			public:
				InvalidDataBaseFile(void);
				~InvalidDataBaseFile() throw();
				InvalidDataBaseFile(const InvalidDataBaseFile& other);
				InvalidDataBaseFile& operator=(const InvalidDataBaseFile& other);
				const char* what(void) const throw();
		};
		class InvalidInputFile: public std::exception {
			public:
				InvalidInputFile(void);
				~InvalidInputFile() throw();
				InvalidInputFile(const InvalidInputFile& other);
				InvalidInputFile& operator=(const InvalidInputFile& other);
				const char* what(void) const throw();
		};
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);

		void fillDatabase();

		std::map<Date, double> database;
		std::ifstream databaseStream;
		std::ifstream inputStream;
};

std::istream& operator>>(std::istream& ifs, BitcoinExchange::Date& date);
std::ostream& operator<<(std::ostream& os, const BitcoinExchange::Date& date);

#endif
