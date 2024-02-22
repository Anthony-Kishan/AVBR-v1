# AVBR-v1
Project AVBR (Autonomous Versatile Balancing Robot) is a self-balancing robot controlled by Radios.
First of all thanks to  @Joop_Brokking  for this awesome project. His YABR (Your Arduino Balancing Robot) project inspired me and I tried to make one for myself.

I know this robot isn't autonomous, but this is 1% of my main project. I want to build an object detection autonomously controlled balancing robot that can be used as a versatile bot (Monitoring, and Inspection).

I used Joop Brokking's balancing robot project (YABR - Your Arduino Balancing Robot) as my guide: http://www.brokking.net/yabr_main.html

I used his code with some little modifications:
- I used the NRF24L01 radio transmission instead of the Bluetooth to Nunchuk
- I used the pin mappings of A4988 drivers with my CNC Shield whereas he used directly his DRV8825 drivers

And will try to implement GPS, Compass, and Camera for Autonomous operations and Object detection in the future.

Components:
1 X Arduino Uno
1 X Arduino Nano
1 X Joystick Module 2-Axis 5-Pin
1 X CNC shield
2 X A4988 Stepper Drivers
1 X MPU6050 Gyro/Accel
2 X NEMA17 1.3A stepper motors
2 X NRF24L01 2.4ghz radio with external antenna
2 X 100uf 50v Capacitors
2 X Wheels + 12mm hex coupler
