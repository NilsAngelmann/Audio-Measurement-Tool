## Info regarding the corrected schematic

> [!IMPORTANT]
> This is only an updated schematic that does not include an updated pcb layout.

> [!TIP]
> This version should be used as a basis for all future revisions.

The following issues from the original version have been fixed in this update:
- [x] Supply voltage: 7 to 7.5 VDC rather than 7 to 12 VDC
- [ ] Switch SW1: Annotation flipped (should be output/mute/detect left to right) -> pcb layout (silkscreen)
- [ ] Polarity of electrolytic capacitors: No visible marking -> pcb layout (silkscreen)
- [ ] Test points: Only numbers -> pcb layout (silkscreen)
- [ ] Display footprint: Missing an unused pin -> only important for integtrated SD card reader
- [ ] DIP footprints: Too wide -> pcb layout
- [x] U10 (op amp): V+ and V- swapped
- [x] D5: wrong polarity
- [x] Clipping comparator: inputs swapped
- [x] Display SPI: MOSI and MISO swapped
- [ ] LED brightness -> adjust current-limiting resistors to taste
