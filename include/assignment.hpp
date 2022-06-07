#include "main.h"

// Global variables
int rev = 1;

// Controller
Controller oleana(CONTROLLER_MASTER);

// Motors
// Drivetrain
Motor GFM(1, MOTOR_GEARSET_18, false);
Motor GBM(2, MOTOR_GEARSET_18, false);
Motor RBM(3, MOTOR_GEARSET_18, true);
Motor RFM(6, MOTOR_GEARSET_18, true);

// The Shootingtrain
Motor scoop(9, MOTOR_GEARSET_18, false);
Motor FW(10, MOTOR_GEARSET_36, false);