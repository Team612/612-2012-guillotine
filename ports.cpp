/* ports.cpp
 *
 * Copyright (c) 2011, 2012 Chantilly Robotics <chantilly612@gmail.com>
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

/*
 * This file contains tables for the electrical layout and setup of the
 * electrical components.  Keep the formatting in this file very easy to read
 * such that it is easy to maintain and quickly check if it is in sync with
 * the actual state of affairs on the electrical board!
 */

#include <RobotDrive.h>
#include <Jaguar.h>
#include <Joystick.h>
#include <Encoder.h>
#include <Ultrasonic.h>
#include <DigitalInput.h>
#include <Relay.h>
#include <Servo.h>
#include <AnalogChannel.h>
#include <Vision/AxisCamera.h>
#include "612.h"
#include "ports.h"
#include "joysmooth.h"

//just define & initialize all of the consts in ports.h

//slots table - in order to make sync with electrical easier.
const module_t slot1 = 1; //1st analog
const module_t slot2 = 1; //1st digital
const module_t slot3 = 1; //1st solenoid
const module_t slot4 = 0; //EMPTY
const module_t slot5 = 2; //2nd analog
const module_t slot6 = 2; //2nd digital
const module_t slot7 = 2; //2nd solenoid
const module_t slot8 = 0; //EMPTY

//camera IP address:
const char * cameraIP = "10.6.12.11"; //static IP, camera configured for connection to bridge
//const char * cameraIP = "192.168.0.90"; //static IP, camera configured for connection to cRIO

//PORTS TABLE

//PWMs                                    SLOT     PORT
Jaguar right_front_jag                  ( slot2,     1 );
Jaguar right_rear_jag                   ( slot2,     2 );
Jaguar left_front_jag                   ( slot2,     4 );
Jaguar left_rear_jag                    ( slot2,     3 );

//NOTE: Sica wants to use pots (potentiometers) for the angles, as those are
//absolute and don't need a zero switch.  If we do that they're seen as
//AnalogChannel s.  We'll want to write a quick wrapper class so we can get
//an angular offset, but we'll cross that bridge when we come to it.

//note: for two channel encoders, we need to specify a slot for both ports
//DIOs                                    SLOT     PORT
Encoder right_drive                     ( slot2,     1,
                                          slot2,     2 );
Encoder left_drive                      ( slot2,     4,
                                          slot2,     5 );
                                          
//note: since we rely on the default value of kInches for the 5th arg
//we should use Ultrasonic::GetRangeInches().

//AIOs                                    SLOT     PORT

//Relays                                  SLOT     PORT

//USBs (on driver station)                         PORT
Joystick left_joystick                             ( 1 );
Joystick right_joystick                            ( 2 );
Joystick gunner_joystick                           ( 3 );

//initialization of virtual devices:

//RobotDrive
RobotDrive drive (
    left_front_motor.jag,  //KEEP THIS ORDER (HERE)!  IT'S IMPORTANT!
    left_rear_motor.jag,   //LF, LR, RF, RR -- see documentation
    right_front_motor.jag, //for more details
    right_rear_motor.jag
);

//drive_jaguar                           JAGUAR&                 TYPE               REVERSE
drive_jaguar left_front_motor  =    { left_front_jag,  RobotDrive::kFrontLeftMotor,  false };
drive_jaguar left_rear_motor   =    { left_rear_jag,   RobotDrive::kRearLeftMotor,   false };
drive_jaguar right_front_motor =    { right_front_jag, RobotDrive::kFrontRightMotor, false };
drive_jaguar right_rear_motor  =    { right_rear_jag,  RobotDrive::kRearRightMotor,  false };
