void detectF() {
  // Setup for mode
  digitalWrite(RELAY, LOW);  // Sine signal at output

  // Calibration
  tft.fillScreen(BLACK);
  tft.setTextColor(WHITE);
  tft.setCursor(15, 25);
  tft.print("ADJUST");
  tft.setCursor(20, 55);
  tft.print("LEVEL");
  tft.setCursor(3, 125);
  tft.print("Press ENTER");

  while (digitalRead(ENTER) == HIGH) {  //until ENTER pressed
    // wait
  }
  delay(15);  // debounce
  while (digitalRead(ENTER) == LOW) {
    // wait for button release
  }
  delay(debounce);  // debounce

  tft.fillScreen(BLACK);
  tft.setCursor(15, 25);
  tft.print("ADJUST");
  tft.setCursor(20, 55);
  tft.print("UPPER");
  tft.setCursor(20, 85);
  tft.print("LOWER");
  tft.setCursor(3, 125);
  tft.print("Press ENTER");

  while (digitalRead(ENTER) == HIGH) {  // until ENTER pressed
    // wait
  }
  delay(15);  // debounce
  while (digitalRead(ENTER) == LOW) {
    // wait for button release
  }
  delay(debounce);  // debounce

  digitalWrite(LED, HIGH);  // measurement active

  count = 0;  // reset counter

  duration = millis();  // start time

  attachInterrupt(digitalPinToInterrupt(DETECT), detectISR, RISING);  // use interrupt to detect error pulses

  while (digitalRead(ESC) == HIGH) {  // until ESC pressed

    if (count != prev_count || (millis() - lastUI) >= 250UL) {  // update display if necessary (at least every 250ms)
      tft.fillScreen(BLACK);
      tft.setCursor(10, 25);
      tft.print("Errors:");
      tft.setCursor(20, 55);
      tft.print(count);
      tft.setCursor(10, 95);
      tft.print("time in sec:");
      tft.setCursor(20, 125);
      tft.print((millis() - duration) / 1000);
      prev_count = count;
      lastUI = millis();
    }
  }
  delay(15);                         // debounce
  while (digitalRead(ESC) == LOW) {  // exit mode
    // wait for button release
  }
  delay(debounce);  // debounce
  detachInterrupt(digitalPinToInterrupt(DETECT));
  digitalWrite(LED, LOW);
  digitalWrite(RELAY, HIGH);
  mode = 0;  // back to menu
}


/*ISR: detect errors*/
void detectISR() {
  count++;
  while (digitalRead(DETECT) == HIGH) {
    // wait for end of error
  }
  delay(holdoff);  // prevent multiple detects per error
}
