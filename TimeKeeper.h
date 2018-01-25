/*
 * TimeKeeper.h
 *
 * Created: 11/1/2017 4:34:16 PM
 *  Author: orencollaco
 */ 

#include "AVR.h"

#ifndef TIMEKEEPER_H_
#define TIMEKEEPER_H_

const uint8_t MaxMonthDays[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

class TimeKeeper{
	private:
	
	uint8_t Hours, Minutes, Seconds, Day, Month, DayOfWeek;
	
	bool AM, old_AM;
	
	uint16_t Year;
	
	public: 
	
	void secondPassed();
	
	void setTime(uint8_t hour, uint8_t minutes, uint8_t seconds);
	
	void setDate(uint8_t DayofWeek, uint8_t day, uint8_t month, uint16_t year);
	
	void memberChanged();
	
	void setAM(bool Am);
	
	bool getAM();
	
	uint8_t getHours();
	
	uint8_t getMinutes();
	
	uint8_t getSeconds();
	
	uint8_t getDay();
	
	uint8_t getDayofWeekInNumber();
	
	uint8_t getMonth();
	
	uint16_t getYear();
	
	const char *getDayOfWeek();
	
	};





#endif /* TIMEKEEPER_H_ */