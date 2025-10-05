void detectF() {
  // Setup for mode
  digitalWrite(RELAY, LOW); // continous sine signal at output

  // Calibration
  tft.fillScreen(BLACK);
  tft.setTextColor(WHITE);
  tft.setCursor(15, 25);
  tft.print("ADJUST");
  tft.setCursor(20, 55);
  tft.print("LEVEL");
  tft.setCursor(3, 125);
  tft.print("Press ENTER");

  while (digitalRead(ENTER) == HIGH) { //until ENTER pressed
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

  while (digitalRead(ENTER) == HIGH) { //until ENTER pressed
    // wait
  }
  delay(15);  // debounce
  while (digitalRead(ENTER) == LOW) {
    // wait for button release
  }
  delay(debounce);  // debounce

  digitalWrite(LED, HIGH);

  count = 0;  // reset counter

  duration = millis();  // Start time

  attachInterrupt(digitalPinToInterrupt(DETECT), detectISR, RISING);

  while (digitalRead(ESC) == HIGH) {  // until ESC pressed

    if (count != prev_count) {  // Update display if necessary
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
    }
  }
  delay(15);  // debounce
  while (digitalRead(ESC) == LOW) {
    // wait for button release
  }
  delay(debounce);  // debounce
  detachInterrupt(digitalPinToInterrupt(DETECT));
  digitalWrite(LED, LOW);
  digitalWrite(RELAY, HIGH);
  mode = 0;   // Back to the main menu
}

void detectISR() {
  count++;
  while (digitalRead(DETECT) == HIGH) {
    // wait for end of error
  }
  delay(holdoff);   // prevent multiple detects per error
}
