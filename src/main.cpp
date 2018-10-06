#include "header/mouvements.h"
#include <Arduino.h>

using namespace std;

int main(){

  Serial.begin(9600);
  init();

  MeEncoderOnBoard M1;
  MeEncoderOnBoard M2;

  return 0;
}
