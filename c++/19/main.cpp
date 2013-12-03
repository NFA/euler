/**
 * projecteuler.net
 * Problem 19
 *
 * You are given the following information, but you may prefer to do some
 * research for yourself.
 *
 * 1 Jan 1900 was a Monday.
 * Thirty days has September,
 * April, June and November.
 * All the rest have thirty-one,
 * Saving February alone,
 * Which has twenty-eight, rain or shine.
 * And on leap years, twenty-nine.
 * A leap year occurs on any year evenly divisible by 4, but not on a century
 * unless it is divisible by 400.
 * How many Sundays fell on the first of the month during the twentieth century
 * (1 Jan 1901 to 31 Dec 2000)?
 */
#include <iostream>

class Time {
public:
  Time() {
    days = 1;
    weekday = Monday;
    month = January;
    year = 1900;

    sundays_on_first_of_the_month = 0;
  }

  enum { Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday };
  enum { January, February, March, April, May, June,
              July, August, September, October, November, December };

  int weekday;
  int month;

  int days;
  int year;

  int sundays_on_first_of_the_month;

  Time &operator++() {
    days += 1;
    switch (weekday) {
      case Sunday: weekday = Monday; break;
      default: weekday += 1; break;
    }
    if (days > get_days_in_month()) {
      switch (month) {
        case December: month = January; year += 1; break;
        default: month += 1; break;
      }
      days = 1;
    }
    check_condition();
    return *this;
  }

  int get_days_in_month() {
    switch (month) {
      case September: case April: case June: case November:
        return 30; break;
      case February:
        if (is_leap_year()) return 29;
        else return 28;
        break;
      default: return 31; break;
    }
  }
  bool is_leap_year() {
    if (year % 100 == 0 && year % 400 != 0) return false;
    return year % 4 == 0;
  }
  void check_condition() {
    if (days == 1 && weekday == Sunday && year > 1900) {
      //std::cout << *this << std::endl;
      sundays_on_first_of_the_month += 1;
    }
  }
private:
  friend std::ostream& operator<<(std::ostream& out, const Time& tim);
};

std::ostream& operator<<(std::ostream& out, const Time& tim) {
  switch (tim.weekday) {
    case Time::Monday: out << "Monday"; break;
    case Time::Tuesday: out << "Tuesday"; break;
    case Time::Wednesday: out << "Wednesday"; break;
    case Time::Thursday: out << "Thursday"; break;
    case Time::Friday: out << "Friday"; break;
    case Time::Saturday: out << "Saturday"; break;
    case Time::Sunday: out << "Sunday"; break;
    default: out << "Unknown"; break;
  }
  out << " " << tim.days << " of ";
  switch (tim.month) {
    case Time::January: out << "January"; break;
    case Time::February: out << "February"; break;
    case Time::March: out << "March"; break;
    case Time::April: out << "April"; break;
    case Time::May: out << "May"; break;
    case Time::June: out << "June"; break;
    case Time::July: out << "July"; break;
    case Time::August: out << "August"; break;
    case Time::September: out << "September"; break;
    case Time::October: out << "October"; break;
    case Time::November: out << "November"; break;
    case Time::December: out << "December"; break;
    default: out << "Unknown"; break;
  }
  out << ", " << tim.year;
  return out;
}


int main(int argc, char *argv[]) {
  Time epoch;
  while (true) {
    ++epoch;
    if (epoch.year == 2000 && epoch.month == Time::December && epoch.days == 31)
      break;
  }
  std::cout << epoch.sundays_on_first_of_the_month << std::endl;
  return 0;
}
