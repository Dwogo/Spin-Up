#include "assignment.hpp"

void rollerSwitch() {
  bool switched = false;
  while (!switched) 
  {
    // LOKi
  }
}

void initialize() {
  lcd::initialize();
  lcd::set_text(1, "Team: 2976G ");
  lcd::set_text(2, "Name: Goonz");
  lcd::set_text(3, "School: Christchurch Boys' High School");
  lcd::set_text(4, "Made by: Phillip, Janzen, Blake, Frank, and Ethan");
  lcd::set_text(5, "Emotional Support: JC");
}

void disabled() { lcd::set_text(6, "The robot is now crippled"); }

void competition_initialize() {}

void autonomous() {}

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

void opcontrol() {
  while (true) {
    if (OLEANA.get_digital_new_press(DIGITAL_DOWN)) reversed();
    if (OLEANA.get_digital_new_press(DIGITAL_UP)) rollerSwitch();

    GFM.move(((OLEANA.get_analog(ANALOG_LEFT_Y) - OLEANA.get_analog(ANALOG_LEFT_X)) * rev) - OLEANA.get_analog(ANALOG_RIGHT_X));
    GBM.move(((OLEANA.get_analog(ANALOG_LEFT_Y) + OLEANA.get_analog(ANALOG_LEFT_X)) * rev) - OLEANA.get_analog(ANALOG_RIGHT_X));
    RFM.move(((OLEANA.get_analog(ANALOG_LEFT_Y) + OLEANA.get_analog(ANALOG_LEFT_X)) * rev) + OLEANA.get_analog(ANALOG_RIGHT_X));
    RBM.move(((OLEANA.get_analog(ANALOG_LEFT_Y) - OLEANA.get_analog(ANALOG_LEFT_X)) * rev) + OLEANA.get_analog(ANALOG_RIGHT_X));

    if (OLEANA.get_digital(DIGITAL_R2)) {
      FW.move(127);
      CON.move(127);
    } else if (OLEANA.get_digital(DIGITAL_R1)) {
      FW.move(0);
      CON.move(127);
    } else if (OLEANA.get_digital(DIGITAL_LEFT)) {
      CON.move(-127);
    } else {
      FW.move(0);
      CON.move(0);
    }
  }
}
