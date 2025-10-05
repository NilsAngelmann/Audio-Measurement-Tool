void burstF() {
  // Calibration
  tft.fillScreen(BLACK);
  tft.setTextColor(WHITE);
  tft.setCursor(15, 25);
  tft.print("ADJUST");
  tft.setCursor(20, 55);
  tft.print("LEVEL");
  tft.setCursor(10, 85);
  tft.print("CLIP LED!");
  tft.setCursor(3, 125);
  tft.print("Press ENTER");
  analogWrite(BURST, 127);  // Continious signal to set levels

  while (digitalRead(ENTER) == HIGH) { //until ENTER pressed
    // wait
  }
  delay(15);  // debounce
  while (digitalRead(ENTER) == LOW) {
    // wait for button release
  }
  delay(debounce);  // debounce

  digitalWrite(LED, HIGH);
  tft.fillScreen(BLACK);
  tft.setCursor(5, 25);
  tft.print("Calibration");
  tft.setCursor(15, 65);
  tft.print("wait...");
  delay(1000);
  baseline = analogRead(DC);  // calibrate for expected signal level
  analogWrite(BURST, 0);
  digitalWrite(LED, LOW);
  delay(1000);

  byte i = 0;

  while (digitalRead(ESC) == HIGH) {  // until ESC pressed
    i = (i + 1) % 10;

    digitalWrite(LED, HIGH);
    duration = millis();
    analogWrite(BURST, 127);
    while (analogRead(DC) < (baseline - 25)) {
      // wait for "echo"
    }
    latency[i] = millis() - duration - OFFSET;
    analogWrite(BURST, 0);
    digitalWrite(LED, LOW);

    avgLatency = 0;
    for (int e = 0; e < 10; e++) {
      avgLatency += latency[e];
    }
    avgLatency /= 10;

    tft.fillScreen(BLACK);
    tft.setCursor(10, 25);
    tft.print("LATENCY:");
    tft.setCursor(15, 55);
    tft.print(latency[i]);
    tft.setCursor(70, 55);
    tft.print("ms");
    tft.setCursor(10, 95);
    tft.print("AVG-10:");
    tft.setCursor(25, 125);
    tft.print(avgLatency);
    tft.setCursor(70, 125);
    tft.print("ms");

    delay(500);
  }
  delay(15);  // debounce
  while (digitalRead(ESC) == LOW) {
    // wait for button release
  }
  delay(debounce);  // debounce
  mode = 0;   // Back to the main menu
}
