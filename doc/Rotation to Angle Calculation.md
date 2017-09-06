# Rotation to angle calculation
According to the [Parallax doc sheet](https://www.parallax.com/sites/default/files/downloads/900-00008-Continuous-Rotation-Servo-Documentation-v2.2.pdf), the max speed at which the servomotor rotates is 50 rpm.
simple learns us that it takes 1.2 seconds at max speed to complete a 360° rotation.

In practice however the voltage provide to the servomotor is lower and the rpm ≈ 42.
After a couple measurements I found it takes closer to 1.365 seconds to complete one full rotation.  
Subsequently an angle of 1° = 3.791666 ms repeating.
