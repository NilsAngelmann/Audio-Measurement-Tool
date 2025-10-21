void startup() {
  // Buttons -> input with internal pullup resistor
  pinMode(LEFT, INPUT_PULLUP);
  pinMode(ESC, INPUT_PULLUP);
  pinMode(ENTER, INPUT_PULLUP);
  pinMode(RIGHT, INPUT_PULLUP);

  // Burst Out -> test signal for latency measurement
  pinMode(BURST, OUTPUT);

  // Detect -> signal from comparator (error detection)
  pinMode(DETECT, INPUT);

  // Relay -> Burst / Sine
  pinMode(RELAY, OUTPUT);
  digitalWrite(RELAY, HIGH);

  // LED
  pinMode(LED, OUTPUT);
  digitalWrite(LED, HIGH);

  // Display -> show welcome text
  tft.initR(INITR_GREENTAB);
  tft.setRotation(3);
  tft.fillScreen(WHITE);
  tft.setTextColor(BLACK);
  tft.setFont(&FreeSansBold12pt7b);
  tft.setTextSize(1);
  tft.setCursor(20, 25);
  tft.print("FH Aachen");
  tft.setCursor(10, 55);
  tft.print("MusiUeINet");
  tft.setCursor(10, 85);
  tft.print("Messplatine");
  tft.setCursor(45, 115);
  tft.print("v 1.3");
  delay(3000);
  tft.fillScreen(BLACK);
  tft.setTextColor(WHITE, BLACK);
  digitalWrite(LED, LOW);
}
