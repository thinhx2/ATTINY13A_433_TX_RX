// 433 MHz vysílač

// připojení knihovny
#include "VirtualWire_TX.h"
//#include <VirtualWire.h>
#define SIZE 4


void setup()
{
  // nastavení typu bezdrátové komunikace
  vw_set_ptt_inverted(true);
  // nastavení rychlosti přenosu v bitech za sekundu
  vw_setup(1000);
  // nastavení čísla datového pinu pro vysílač
  vw_set_tx_pin(8);
}

void loop()
{
  // vytvoření proměnných pro různé
  // druhy zpráv
  // proměnná zprava pro poslání textu
  //const char *zprava = "Cas od zapnuti: ";
  // proměnná s načtením počtu sekund od
  // připojení napájení
  //long cas = millis()/1000;
  // pracovní proměnná pro konverzi
  // čísla na text
  //char znaky [128];

  uint8_t msg[SIZE] = {1, 2, 3 , (millis()/1000)%256};
  // příkazy pro konverzi čísla na text,
  // čas převedený na text je uložen do
  // proměnné casZnaky
  //snprintf(znaky, sizeof(znaky), "%ld", cas);
  //char *casZnaky = znaky;
  // rozsvícení LED diody při odesílání (nepovinné)
  digitalWrite(13, true);
  // odeslání textu v proměnné zprava
  vw_send(msg, SIZE);
  // vyčkání na odeslání celé zprávy
  vw_wait_tx();
  // zhasnutí LED diody při odeslání (nepovinné)
  digitalWrite(13, false);
  // pauza mezi posláním zpráv
  delay(100);
  // obdobný kus kódu, který opět rozsvítí LED
  // diodu, zašle obsah proměnné casZnaky
  // a po odeslání LED diodu zhasne
  digitalWrite(13, true);
  vw_send(msg, SIZE);
  vw_wait_tx();
  digitalWrite(13, false);
  delay(900);
}
