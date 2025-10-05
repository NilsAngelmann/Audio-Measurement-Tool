## Info regarding the original version of the PCB from 2022

> [!CAUTION]
> This is the original version that includes several errors!

> [!WARNING]
> It is not advised to use this version as is!

- Supply voltage: 7 to 7.5 VDC rather than 7 to 12 VDC
- Switch SW1: Annotation flipped - should be output/mute/detect (left to right)
- Polarity of electrolytic capacitors: No visible marking - use GND plane as reference
- Test points: Only numbers - crossreference schematic for functions
- Display footprint: Missing an unused pin - ignore
- DIP footprints: Too wide - bend legs slightly appart, do not use sockets
- U10 (op amp): V+ and V- swapped - bend legs up and connect using wire
- D5: wrong polarity - solder in with opposing polarity
- Clipping comparator: inputs swapped - turn LED around and connect anode to +5V
- Display SPI: MOSI and MISO swapped - bridge both Arduino pins (MISO is not needed)
- LED brightness: depending on the used LEDs adjust their current-limiting resistors
