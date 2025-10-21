void menuF() {
  // Setup for mode
  tft.fillScreen(BLACK);
  tft.setTextColor(WHITE);
  tft.setCursor(15, 25);
  tft.print("ERRORS");
  tft.setCursor(25, 55);
  tft.print("Press <-");
  tft.setCursor(15, 90);
  tft.print("LATENCY");
  tft.setCursor(25, 120);
  tft.print("Press ->");



  while (1) {
    if (digitalRead(LEFT) == LOW) {   // <-
      delay(15);  // debounce
      while (digitalRead(LEFT) == LOW) {
        // wait for button release
      }
      delay(debounce);  // debounce
      mode = 1;   // detect
      break;
    }

    if (digitalRead(RIGHT) == LOW) {    // ->
      delay(15);  // debounce
      while (digitalRead(RIGHT) == LOW) {
        // wait for button release
      }
      delay(debounce);  // debounce
      mode = 2;   // burst
      break;
    }
  }
}
