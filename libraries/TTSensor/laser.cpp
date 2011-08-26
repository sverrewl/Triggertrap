/************************************************************************************
 * 	
 * 	Name    : Trigger Trap laser.h                         
 * 	Author  : Noah Shibley, NoMi Design                         
 * 	Date    : July 10th 2011                                    
 * 	Version : 0.1                                              
 * 	Notes   : The laser break beam sensor. Sub class of Sensor, inherits all Sensor functions           
 * 
 * 	 Copyright (c) 2011 NoMi Design All right reserved.
 * 
 *     
 *
 * 
 * 	This file is part of Trigger Trap.
 * 
 * 		    Trigger Trap is free software: you can redistribute it and/or modify
 * 		    it under the terms of the GNU General Public License as published by
 * 		    the Free Software Foundation, either version 3 of the License, or
 * 		    (at your option) any later version.
 * 
 * 		    Trigger Trap is distributed in the hope that it will be useful,
 * 		    but WITHOUT ANY WARRANTY; without even the implied warranty of
 * 		    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * 		    GNU General Public License for more details.
 * 
 * 		    You should have received a copy of the GNU General Public License
 * 		    along with Trigger Trap.  If not, see <http://www.gnu.org/licenses/>.
 * 
 ***********************************************************************************/

#include "laser.h"

const int LASER_SENSOR = A0; 			// A0 = Analong in - Laser Sensor
int const MAKE_LASER_MODE = 0;
int const BREAK_LASER_MODE = 1;
int const CHANGE_LASER_MODE = 2;

   //Menu Sensor Strings

   //Mode Menu Listing
   const prog_char laserMenu[] PROGMEM= {"Laser"};

  Laser::Laser() 
  {
    triggerState_ = 0; //off
//    threshold_ = 0; 
//	delay_ = 0;
//	type_ = 0;
	setOption(TRIG_TYPE,0);
	setOption(1,0);
	setOption(2,0);
	select_ = 0; 
	max_delay_ = 600; //10minutes 
    sensorPin_ = LASER_SENSOR;
  }

  boolean Laser::trigger()
  {
    boolean laserStatus = false;

	resetShutter(); //10 millisec delay, between high and low

    switch (option(TRIG_TYPE))
    {
    case MAKE_LASER_MODE:

      laserStatus = high();
      break;
    case BREAK_LASER_MODE:

      laserStatus = low();
      break;
    case CHANGE_LASER_MODE:

      laserStatus = change();
      break;
    default: //no default option
      break;
    }

    return triggerState_;
  }

  //to change the behavior of these functions for laser, edit here
  //Or add a new function here, to customize laser sensor
  /*
	boolean high()
   	{
   	
   	}
   	*/

  /*
	boolean low()
   	{
   	
   	}
   	*/
  /*
	boolean change()
   	{
   	
   	}
   	*/

  

void Laser::getModeMenu(char buffer[])
{
	 strcpy_P(buffer, laserMenu); 
	
}

