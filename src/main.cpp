#include "assignment.hpp"

/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */
void on_center_button()
{
  static bool pressed = false;
  pressed = !pressed;
  if (pressed)
  {
    pros::lcd::set_text(10, "Current Draw is W.I.P.");
  }
  else
  {
    pros::lcd::clear_line(10);
  }
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize()
{
  lcd::initialize();
  lcd::set_text(1, "Team: 2976G ");
  lcd::set_text(2, "Name: Goonz");
  lcd::set_text(3, "School: Christchurch Boys' High School");
  lcd::set_text(4, "Made by: Phillip, Janzen, Blake, Frank, and Ethan");

  lcd::register_btn1_cb(on_center_button);
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {}

void reversed()
{
  rev = (rev == 1) ? -1 : 1;

  if (rev == -1) 
  {
  oleana.rumble("..");
  delay(50);
  oleana.print(0, 0, "Reversed");
  }

  if (rev == 1) 
  {
  oleana.rumble("-");
  delay(50);
  oleana.print(0, 0, "Normal");
  }
}

void opcontrol()
{
  while (true)
  {
    if (oleana.get_digital_new_press(DIGITAL_DOWN)) reversed();
    
    GFM.move(((oleana.get_analog(ANALOG_LEFT_Y) - oleana.get_analog(ANALOG_LEFT_X)) * rev) - oleana.get_analog(ANALOG_RIGHT_X));
    GBM.move(((oleana.get_analog(ANALOG_LEFT_Y) + oleana.get_analog(ANALOG_LEFT_X)) * rev) - oleana.get_analog(ANALOG_RIGHT_X));
    RFM.move(((oleana.get_analog(ANALOG_LEFT_Y) + oleana.get_analog(ANALOG_LEFT_X)) * rev) + oleana.get_analog(ANALOG_RIGHT_X));
    RBM.move(((oleana.get_analog(ANALOG_LEFT_Y) - oleana.get_analog(ANALOG_LEFT_X)) * rev) + oleana.get_analog(ANALOG_RIGHT_X));

  }
}
