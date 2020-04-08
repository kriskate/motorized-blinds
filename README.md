# roller-blinds

## components
- [x] D1 mini (esp8266)
- [x] SX1509 (gpio expander)
- [x] ST7789 display
- [x] 3x ULN2003 + 28BYJ-48 (stepper driver and motor)
- [x] small temperature sensor
- [x] 12v power source
- [x] mini-360 (DC-DC stepdown module)
- [ ] 2x push button
- [x] 1x 220v on/off button
- [x] rgb led and 0.25W 470Ω resistor

## roadmap:
### configuration
- [ ] WifiManager (connect ESP to a pre-scanned WI-FI network)
- [ ] WebServer + html (display motor controls and misc config)
- [ ] Motor control via Websockets
  - [ ] up/ down/ stop/ counter-rotate
  - [ ] config min/ max
- [ ] FS json config
- [ ] push button to reset esp
- [ ] mqtt for HA integration
### periheralps
- [ ] rgb led
- [ ] display output
  - [ ] current position
  - [ ] error log
  - [ ] pushbutton to activate; delay to power down display
- [ ] sound module (clap for up/down)
- [ ] temperature module 
  - [ ] show temperature on display
  - [ ] auto-up if low temperature
