void burstF() {
  // Setup for mode
  digitalWrite(RELAY, HIGH);  // burst signal at output

  // Calibration
  tft.fillScreen(BLACK);
  tft.setTextColor(WHITE);
  tft.setCursor(10, 25);
  tft.print("Connect");
  tft.setCursor(10, 50);
  tft.print("Audio");
  tft.setCursor(10, 75);
  tft.print("Interface");
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

  analogWrite(BURST, 127);  // test signal: PWM with 50% duty cycle
  digitalWrite(LED, HIGH);
  tft.fillScreen(BLACK);
  tft.setCursor(10, 25);
  tft.print("Calibrating");
  tft.setCursor(10, 50);
  tft.print("Level:");
  tft.setCursor(10, 75);
  tft.print("Adjust Gain");
  tft.setCursor(10, 100);
  tft.print("-> Clip LED");
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

  analogWrite(BURST, 0);
  delay(500);
  int baseline_low = analogRead(DC);  // measure input level without signal -> noise floor
  Serial.print("Baseline Low: ");
  Serial.println(baseline_low);
  analogWrite(BURST, 127);
  delay(500);
  int baseline_high = analogRead(DC);  // measure input signal with signal present
  Serial.print("Baseline High: ");
  Serial.println(baseline_high);
  analogWrite(BURST, 0);
  int baseline = (baseline_high - baseline_low) * 0.1 + baseline_low;  // set treshold 10% above noise floor
  Serial.print("-> Baseline: ");
  Serial.println(baseline);
  digitalWrite(LED, LOW);
  delay(250);

  int i = 0;
  while (digitalRead(ESC) == HIGH) {  // until ESC pressed -> exit mode
    i = (i + 1) % 10;

    digitalWrite(LED, HIGH);
    analogWrite(BURST, 127);
    duration = micros();
    while (analogRead(DC) < baseline) {  // 10% of envelope
      // wait for "echo"
    }
    latency[i] = micros() - duration - offset;  // actual latency measurement
    analogWrite(BURST, 0);
    digitalWrite(LED, LOW);
    if (latency[i] > 500000) {  // more than 500ms are unrealistic -> overflow
      latency[i] = 500000;
    }

    Serial.print("Delay: ");
    Serial.print(latency[i] / 1000);
    Serial.println(" ms");

    avgLatency = 0;
    for (int e = 0; e < 10; e++) {
      avgLatency += latency[e];
    }
    float avgLatencyi = avgLatency * 0.0001f;  // convert to millisceconds for display

    float latencyi = latency[i] * 0.001f;  // convert to millisceconds for display

    tft.fillScreen(BLACK);
    tft.setCursor(10, 25);
    tft.print("LATENCY:");
    tft.setCursor(15, 50);
    tft.print(latencyi, 1);
    tft.setCursor(80, 50);
    tft.print("ms");
    tft.setCursor(10, 90);
    tft.print("AVG-10:");
    tft.setCursor(15, 115);
    tft.print(avgLatencyi, 1);
    tft.setCursor(80, 115);
    tft.print("ms");

    delay(500);
  }
  delay(15);  // debounce
  while (digitalRead(ESC) == LOW) {
    // wait for button release
  }
  delay(debounce);  // debounce
  mode = 0;         // Back to menu
}
