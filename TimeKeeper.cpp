/*
 * TimeKeeper.cpp
 *
 * Created: 11/1/2017 4:34:38 PM
 *  Author: orencollaco
 */ 

#include "TimeKeeper.h"

uint8_t TimeKeeper::getDay(){
	return Day;
}

uint8_t TimeKeeper::getDayofWeekInNumber(){
	return DayOfWeek;	
}

uint8_t TimeKeeper::getMonth(){
	return Month;
}

uint16_t TimeKeeper::getYear(){
	return Year;
}

uint8_t TimeKeeper::getHours(){
	return Hours;
}

uint8_t TimeKeeper::getMinutes(){
	return Minutes;
}

uint8_t TimeKeeper::getSeconds(){
	return Seconds;
}

void TimeKeeper::setAM(bool am){
	AM = am;
}

bool TimeKeeper::getAM(){
	return AM;
} 

void TimeKeeper::setTime(uint8_t hours, uint8_t minutes, uint8_t seconds){
	Hours = hours;
	Minutes = minutes;
	Seconds = seconds;
	memberChanged();
}

void TimeKeeper::setDate(uint8_t dayofweek, uint8_t day, uint8_t month, uint16_t year){
	DayOfWeek = dayofweek;
	Day = day;
	Month = month;
	Year = year;
	memberChanged();	
}


const char* TimeKeeper::getDayOfWeek(){
	switch(DayOfWeek){
		case 1:
		return "Mon";
		break;
		case 2:
		return "Tue";
		break;
		case 3:
		return "Wed";
		break;
		case 4:
		return "Thu";
		break;
		case 5:
		return "Fri";
		break;
		case 6:
		return "Sat";
		break;
		case 7:
		return "Sun";
		break;
	}
	return "Undefined";
}

void TimeKeeper::memberChanged(){
	if(Seconds > 59){
		if(Hours == 11 && Minutes == 59){
			if(!AM){
				Day += 1;
				DayOfWeek += 1;
			}
			AM ^= 1;
		}
		Minutes += 1;
		Seconds = 0;
	}
	if(Minutes > 59){
		Hours += 1;
		Minutes = 0;
	}
	if(Hours > 12){
		Hours = 1;
	}
	
	if(Hours == 0){
		Hours = 12;
	}
	if(DayOfWeek > 7){
		DayOfWeek = 1;
	}
	if(Day > MaxMonthDays[Month]){
		Month += 1;
		Day = 1;
	}
	if(Month > 12){
		Month = 1;
		Year += 1;
	}
}

void TimeKeeper::secondPassed(){
	Seconds += 1;
	memberChanged();
}