#include "main.h"

// Global variables
int rev = 1;          // Used for reversing the movement of the bot
bool blue = true;     // What alliance colour we are in
bool usrCtrl = false; // See if the we have driver control

// Controller
Controller OLEANA(CONTROLLER_MASTER);

// Vision Sensor
Vision LOKI(18);

// Motors
// Drivetrain
// Red
Motor GFM(1, MOTOR_GEARSET_18, false); // The front motor of the green gear side
Motor GBM(2, MOTOR_GEARSET_18, false); // The back motor of the green gear side
// Green
Motor RBM(3, MOTOR_GEARSET_18, true); // The front motor of the red gear side
Motor RFM(6, MOTOR_GEARSET_18, true); // The back motor of the red gear side

// Shootingtrain
Motor CON(11, MOTOR_GEARSET_18, true); // Motor for the conveyor
Motor FWL(9, MOTOR_GEARSET_18, false); // Motor for the flywheel
Motor FWR(10, MOTOR_GEARSET_18, true); // Motor for the flywheel

// Widetrain
Motor GWM(18, MOTOR_GEARSET_18,
          false); // Green side's motor for the horizontal expansian
Motor RWM(19, MOTOR_GEARSET_18,
          false); // Red side's motor for the horizontal expansian
