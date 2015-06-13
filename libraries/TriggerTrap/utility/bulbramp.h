/************************************************************************************
 * 	
 * 	Name    : Triggertrap BulbRamp.h                         
 * 	Author  : Noah Shibley / NoMi Design                         
 * 	Date    : July 10th 2011                                    
 * 	Version : 0.1                                              
 * 	Notes   : BulbRamp interval trigger          
 * 
 * 			Code for Triggertrap device (TTv1) and Triggertrap Shield (TT-k)                      
 * 
 * 	Copyright (c) 2011 NoMi Design (http://n0m1.com) All right reserved.
 * 
 * 	This file is part of Triggertrap. See Triggertrap.com for more information.
 * 
 * 		    Triggertrap is free software: you can redistribute it and/or modify
 * 		    it under the terms of the GNU General Public License as published by
 * 		    the Free Software Foundation, either version 3 of the License, or
 * 		    (at your option) any later version.
 * 
 * 		    Triggertrap is distributed in the hope that it will be useful,
 * 		    but WITHOUT ANY WARRANTY; without even the implied warranty of
 * 		    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * 		    GNU General Public License for more details.
 * 
 * 		    You should have received a copy of the GNU General Public License
 * 		    along with Triggertrap.  If not, see <http://www.gnu.org/licenses/>.
 * 
 ***********************************************************************************/

#ifndef BULBRAMP_H
#define BULBRAMP_H

//#include "globals.h"
#include "trigger.h"
#include <TTSleep.h>
#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"    // for digitalRead, digitalWrite, pinMode, delayMicroseconds
#else
#include "WProgram.h"
#endif

class BulbRamp : public Trigger{

public:


	BulbRamp();

/***********************************************************
 * 
 * begin
 *
 *  pass in the a reference to the sleep object, for sleeping during timelapse
 * 
 ***********************************************************/
void begin(Sleep& sleep){ sleep_ = &sleep; }

/***********************************************************
 * 
 * trigger
 *
 *  returns true or false based on whether its time to take a picture
 * 
 ***********************************************************/
boolean trigger();
	
/***********************************************************
 * 
 * delayFirstShot
 *
 *  set the delay for the first shot in a bulbRamp sequence
 * 
 ***********************************************************/	
boolean delayFirstShot();

/***********************************************************
 * 
 * batteryPower
 *
 *  returns true or false based on whether or not the TT is plugged in
 * 
 ***********************************************************/
boolean batteryPower();
	
/***********************************************************
 * 
 * countDown
 *
 *  returns remaining time till trigger
 * 
 ***********************************************************/
	unsigned long countDown(); 

/***********************************************************
 * 
 * countDownInt
 *
 *  returns remaining time till trigger in ints
 * 
 ***********************************************************/

	unsigned int countDownInt();

/***********************************************************
 * 
 * incSetting
 *
 *  increment the value of the selected option setting
 * 
 ***********************************************************/
	void incSetting(char buffer[],int inc);

/***********************************************************
 * 
 * decSetting
 *
 *  decrement the value of the selected option setting
 * 
 ***********************************************************/
	void decSetting(char buffer[],int dec);
	
/***********************************************************
 * 
 * getModeMenu
 *
 *  Gets the Mode menu title for this trigger 
 * 
 ***********************************************************/	
	void getModeMenu(char buffer[]);

 /***********************************************************
 * 
 * getOptionMenu
 *
 *  Overrides the getOptionMenu in trigger with new menu set, for different options
 * 
 ***********************************************************/
	void getOptionMenu(char buffer[]);

/***********************************************************
 * 
 * getActiveMessage
 *
 *  The message to print on the LCD while TT is active
 * 
 ***********************************************************/
	void getActiveMessage(char buffer[]);

private:

/***********************************************************
 * 
 * startTimer
 *
 *  sets the start time when the start button is pressed
 * 
 ***********************************************************/
	void startTimer();

/***********************************************************
 * 
 * incDecFraction
 *
 *  inc and dec a fractional amount
 * 
 ***********************************************************/
	void incDecFraction(int optionConst, boolean incDec, int inc, char buffer[]);

/***********************************************************
 * 
 * setIntervalLimits
 *
 *  set the limits to match the start and end
 * 
 ***********************************************************/
	void setIntervalLimits();

/***********************************************************
 * 
 * fractionToString
 *
 *  convert number to string for printing on LCD
 * 
 ***********************************************************/
	void fractionToString(int optionConst, int fraction, char buffer[]);

   	
 	Sleep *sleep_;
	int startExposure; //value for start exposure
	int endExposure;  //value for end exposure
	unsigned int msValue;  //bulb exposure time in milliseconds
	int fractionIndex; //index for the fraction array
	int longExposure; //not necessarily the same as start/stop
	unsigned int startDuration;
	unsigned int elapsedDuration;

};

#endif

