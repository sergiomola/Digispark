#include "DigiKeyboard.h"

void setup() {
  

}


void loop() {

  
  DigiKeyboard.sendKeyStroke(0);

  DigiKeyboard.delay(3000);

  DigiKeyboard.sendKeyStroke(KEY_M , MOD_GUI_LEFT); 

  DigiKeyboard.delay(200);

  DigiKeyboard.sendKeyStroke(0 , MOD_GUI_LEFT); 

  DigiKeyboard.delay(500);

  DigiKeyboard.println("Teams");

  DigiKeyboard.sendKeyStroke(KEY_ENTER);

  DigiKeyboard.delay(1000);

  DigiKeyboard.sendKeyStroke(KEY_N , MOD_CONTROL_LEFT);

  DigiKeyboard.delay(1000);

  DigiKeyboard.println("Sergio Diez");

  DigiKeyboard.delay(1000);

  DigiKeyboard.sendKeyStroke(KEY_ENTER);

  DigiKeyboard.delay(1000);

  DigiKeyboard.sendKeyStroke(KEY_X, MOD_SHIFT_LEFT | MOD_CONTROL_LEFT);
  
  DigiKeyboard.print("```");
  DigiKeyboard.sendKeyStroke(KEY_SPACE);
  DigiKeyboard.sendKeyStroke(KEY_SPACE);
  DigiKeyboard.sendKeyStroke(KEY_SPACE);
  DigiKeyboard.sendKeyStroke(KEY_SPACE);
  DigiKeyboard.delay(100);
  DigiKeyboard.println("Te vigilo");
  DigiKeyboard.delay(100);
  DigiKeyboard.println("   _.---.._             _.---...__");
  DigiKeyboard.println(".-'   /\   \          .'  /\     /");
  DigiKeyboard.println("`.   (  )   \        /   (  )   /");
  DigiKeyboard.println("  `.  \/   .'\      /`.   \/  .'");
  DigiKeyboard.println("    ``---''   )    (   ``---''");
  DigiKeyboard.println("            .';.--.;`.");
  DigiKeyboard.println("          .' /_...._\ `.");
  DigiKeyboard.println("        .'   `.a  a.'   `.");
  DigiKeyboard.println("       (        \/        )");
  DigiKeyboard.println("        `.___..-'`-..___.'");
  DigiKeyboard.println("           \          /");
  DigiKeyboard.println("            `-.____.-'");

  DigiKeyboard.sendKeyStroke(KEY_X, MOD_SHIFT_LEFT | MOD_CONTROL_LEFT);

  DigiKeyboard.delay(1000);

  DigiKeyboard.sendKeyStroke(KEY_ENTER, MOD_CONTROL_LEFT);

  DigiKeyboard.delay(1000);

  DigiKeyboard.sendKeyStroke(0);

  for (;;) {
    /*Stops the digispark from running the scipt again*/
  }

}