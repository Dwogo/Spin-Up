#include "assignment.h"
#include "pros/llemu.hpp"
#include "pros/misc.h"
#include "pros/vision.h"

void colorSwitch() {
  bool switched = true;
  while (!switched) {
    vision_object_s_t col = LOKI.get_by_size(0);
    lcd::set_text(8, col.signature);
    switched = true;
    delay(20);
  }
}

void conCtrl() {
  while (true) {
    if (OLEANA.get_digital(DIGITAL_A)) {
      colorSwitch();
      // Only if we are able to drive
    } else if (usrCtrl) {
      // Controlling the Conveyor and Flywheel Motors
      if (OLEANA.get_digital(DIGITAL_R2)) {
        FWL.move(127);
        FWR.move(127);
        CON.move(127);
      } else if (OLEANA.get_digital(DIGITAL_R1)) {
        FWL.move(0);
        FWR.move(0);
        CON.move(127);
      } else if (OLEANA.get_digital(DIGITAL_LEFT)) {
        CON.move(-127);
      } else {
        FWL.move(0);
        FWR.move(0);
        CON.move(0);
      }
    }
    delay(20);
  }
}

// Print out the current draw of the drivetrain motors
void motorCurrents() {

  lcd::clear();

  lcd::set_text(0, "GFM current: " + GFM.get_current_draw());
  lcd::set_text(1, "GBM current: " + GBM.get_current_draw());
  lcd::set_text(2, "RFM current: " + RFM.get_current_draw());
  lcd::set_text(3, "RBM current: " + RBM.get_current_draw());
}

void initialize() {
  lcd::initialize();

  // Printing credits on the Brain Lcd
  lcd::set_text(0, "Team: 2976G ");
  lcd::set_text(1, "Name: Goonz");
  lcd::set_text(2, "School: Christchurch Boys' High School");
  lcd::set_text(3, "Made by: Phillip, Janzen, Blake, Frank, and Ethan");
  lcd::set_text(4, "Emotional Support: JC");

  // Registering the left most button on the lcd to the motorCurrent function
  lcd::register_btn0_cb(motorCurrents);
}

// When the robot cant do anything so we say it's crippled
void disabled() { lcd::set_text(6, "The robot is now crippled"); }

// Function to reverse the movement on the field
void reversed() {
  rev = (rev == 1) ? -1 : 1;

  if (rev == -1) {
    OLEANA.rumble("..");
    delay(50);
    OLEANA.print(0, 0, "Reversed");
  }

  if (rev == 1) {
    OLEANA.rumble("-");
    delay(50);
    OLEANA.print(0, 0, "Normal");
  }
}

// Driver control
void opcontrol() {
  usrCtrl = true;
  Task conveyor(conCtrl);

  while (true) {

    // Call the reversed function
    if (OLEANA.get_digital_new_press(DIGITAL_DOWN))
      reversed();

    // Call the function to print the current draw of the drivetrain
    if (OLEANA.get_digital_new_press(DIGITAL_X))
      motorCurrents();

    // Move the Motors: Move on the plane with the left joystick and rotate with
    // the right joystick
    GFM.move(((OLEANA.get_analog(ANALOG_LEFT_Y) -
               OLEANA.get_analog(ANALOG_LEFT_X)) * // Movement on plane
              rev) - // Reversing the movement on plone
             OLEANA.get_analog(ANALOG_RIGHT_X)); // Rotation
    GBM.move(((OLEANA.get_analog(ANALOG_LEFT_Y) +
               OLEANA.get_analog(ANALOG_LEFT_X)) * // Movement on plane
              rev) - // Reversing the movement on plone
             OLEANA.get_analog(ANALOG_RIGHT_X)); // Rotation
    RFM.move(((OLEANA.get_analog(ANALOG_LEFT_Y) +
               OLEANA.get_analog(ANALOG_LEFT_X)) * // Movement on plane
              rev) + // Reversing the movement on plone
             OLEANA.get_analog(ANALOG_RIGHT_X)); // Rotation
    RBM.move(((OLEANA.get_analog(ANALOG_LEFT_Y) -
               OLEANA.get_analog(ANALOG_LEFT_X)) * // Movement on plane
              rev) + // Reversing the movement on plone
             OLEANA.get_analog(ANALOG_RIGHT_X)); // Rotation

    delay(20);
  }
}
