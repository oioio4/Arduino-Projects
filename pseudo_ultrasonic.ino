assign 3 leds to pins 3, 4, and 5
assign buzzer to pin 6
assign echo to pin 7
assign trig to pin 8
assign distance to long

Setup ()
  Serial.begin(9600)
  set pins 3, 4, 5, 6, and 8 to output
  set pin 7 to input

Loop ()
  If distance = some value
    Set pins 3, 4, 5, and 6 to high
    delay for 500 ms
  else
    Set pins 3, 4, 5, and 6 to low
    delay for 500 ms
    
