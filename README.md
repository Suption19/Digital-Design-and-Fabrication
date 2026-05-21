# Digital Design and Fabrication (inf175) - Portfolio

**Student Name:** Maik Bernert  
**Email:** Maik.bernert@uni-oldenburg.de 

## Portfolio Overview

This repository documents my progress, hands-on work, and learning process across 8 interactive exercises in the Digital Design and Fabrication (inf175) module at the University of Oldenburg. 

---

## 1. Electrical Circuits

### Goal
To build and test different manifestations of an LED control circuit, consecutively adding control functionality (simple circuit, switchable, dimmable) while observing and measuring voltages and currents to understand electrical characteristics.

### Process & Materials
*   **Materials Used:** Breadboard, Green LED, Resistors (100 Ω, 220 Ω, 1.0 kΩ, 4.7 kΩ), 1 kΩ potentiometer, 2-position switch, male-male jumper wires, laboratory power supply, multimeter.
*   **Process:** 

    **Task 1.1 - Simple LED Circuit:**
    Constructed a basic LED circuit with a 5V supply. I measured the voltage across the resistor (V1) and the LED (VLED) for different resistor values.
    
    | R1 [Ω] | Measured V1 [V] | Measured VLED [V] |
    |--------|-----------------|-------------------|
    | 220    | 2.0             | 2.8               |
    | 1000   | 2.5             | 2.49              |
    | 4700   | 2.7             | 2.31              |
    
    *Observation:* As the resistance of R1 increases, the voltage drop across the resistor ($V_1$) increases, while the voltage available to the LED ($V_{LED}$) and the current ($I_1$) decrease. This results in a visible decrease in the LED's brightness. The sum of $V_1$ and $V_{LED}$ consistently approximates the 5V supply voltage.

    **Task 1.2 - Switchable LED Circuit:**
    Added a 2-position switch to the circuit.
    
    *Observation:* The switch is a non-directional (non-polar) component; the circuit functions identically regardless of which direction the switch is connected. In contrast, the LED is directional (polar). Connecting the LED in the opposite direction (backwards) prevents it from lighting up because it only allows current to flow in one direction.

    **Task 1.3 - Dimmable LED Circuit:**
    Introduced a 1 kΩ potentiometer to control the LED's brightness.

    | Position            | VLED [V] | V2 (Potentiometer) [V] |
    |---------------------|----------|------------------------|
    | a) full brightness  | 3        | 3                |
    | b) dimmed           | 2.29  | 2.29                |
    | c) OFF              | 1.9  | 1.97                |
    | c) Complete off     | 0.3  | 0.4                |
    
    *Observation:* By rotating the potentiometer, we changed the resistance in the circuit, which redistributed the voltage drop. As $V_2$ (the voltage across the potentiometer) increases, $V_{LED}$ decreases. We observed that the LED does not dim linearly to zero; once $V_{LED}$ falls below a certain "threshold voltage" (approx. 1.9V for this green LED), the LED turns off completely because there is insufficient energy to overcome the semiconductor gap.  

### Visual Documentation

#### Task 1.1: Simple LED Circuit Setup
<img src="images/exercise_01/task1_1.jpeg" width="600" alt="Task 1.1 Simple Circuit">

#### Task 1.3: Dimmable LED Circuit - Potentiometer Control
<img src="images/exercise_01/Task1.3b.jpeg" width="600" alt="Task 1.3 Dimmable Circuit - Second Setup">

#### Task 1.3: Measure Values - Potentiometer Control
<img src="images/exercise_01/Task1.3.jpeg" width="600" alt="Task 1.3 Dimmable Circuit">

#### Task 1.3: Video - Potentiometer Brightness Adjustment
[View video: Potentiometer Adjustment](images/exercise_01/Task1.3Video.mp4)

### The 'Failure Log'
*   **What went wrong:** LED connected backwards on the first attempt - it didn't light up.
*   **How I managed it:** Checked LED polarity with the multimeter and reversed the connections.
*   **What I learned:** Always check component polarity before powering circuits, especially with LEDs. The longer leg is the positive terminal.

### Reflection
Adding the switch and potentiometer dramatically improved user control. The switch provides a simple on/off mechanism, while the potentiometer enables continuous brightness adjustment, making the circuit interactive and responsive to user input.

---

## 2. Transistor Switch Circuit

### Goal
To understand and implement transistor switching and PWM (Pulse Width Modulation) control. Through hands-on work, explore how duty cycle affects perceived brightness and how frequency determines whether the LED strip appears to flicker or glow steadily.

### Process & Materials
*   **Materials Used:** Breadboard, NPN MOSFET IRLZ44N transistor, 12V LED Strip, Resistors (100 Ω, 10 kΩ), PWM Signal Generator, Power-supply USB module, 2-position switch, male-male and male-female jumper wires.
*   **Process:** 

    **Task 2.1 - Switchable LED Strip:**
    Constructed a circuit using an NPN MOSFET transistor to switch a 12V LED strip on/off using a 5V control signal. The transistor acts as a digital switch controlled by the gate voltage (VGS). A 10 kΩ pull-down resistor (Rpull) ensures the gate remains low when the switch is open, preventing floating state issues.
    
    *Observation:* The switch successfully controls the LED strip through the transistor. The transistor acts as a voltage-controlled switch, when VGS is high (5V), the transistor conducts and the LED strip lights up. When VGS is low (0V), the transistor blocks current and the LED strip turns off. The 100 Ω gate resistor (Rg) limits the gate current, protecting the transistor. Two separate power supplies (5V for control, 12V for load) with a common ground allow efficient control of high-power loads.

    **Task 2.2 - Dimmable LED Strip (PWM Control):**
    Replaced the simple switch with a PWM signal generator operating at 90 Hz frequency. Explored how duty cycle and frequency affect the LED strip's perceived brightness.

    **Part A: Duty Cycle Variation (f = 90 Hz)**
    
    | Duty Cycle (D) | Observation | Perceived Brightness |
    |---|---|---|
    | 2% | Very brief pulses | Extremely dim, barely visible |
    | 15% | Short pulses | Very dim |
    | 40% | Moderate pulses | Medium brightness |
    | 75% | Long pulses | Very bright |
    | 100% | Continuous conduction | Full brightness |
    
    *Observation:* The perceived brightness of the LED strip is directly proportional to the duty cycle at a fixed frequency. By varying the duty cycle from 2% to 100%, we can smoothly dim the LED strip from nearly off to full brightness. This works because the LED's persistence allows the human eye to perceive the average brightness rather than the individual on/off pulses.

    **Part B: Frequency Variation (D = 50%)**
    
    | Frequency (f) | Observation |
    |---|---|
    | 5 Hz | Visible flicker, distinct on/off pulses |
    | 25 Hz | Reduced flicker, slight visibility of pulsing |
    | 45 Hz | Minimal flicker, mostly steady appearance |
    | 100 Hz | No visible flicker, appears as steady light |
    
    *Observation:* At low frequencies (5 Hz), individual on/off pulses are easily visible and the LED strip appears to flicker. As frequency increases, the flicker becomes less noticeable. Above approximately 45 Hz, the human eye can no longer distinguish individual pulses due to the eye's integration time (typically 20-30 Hz fusion frequency), and the LED strip appears as a steady, continuous light at the average brightness level. This is the principle behind PWM dimming in lighting applications.

### Visual Documentation

#### Task 2.1: Transistor Switch Circuit with 12V LED Strip
<img src="images/exercise_01/Task2.1.jpeg" width="600" alt="Task 2.1 Switchable LED Strip">

#### Task 2.2: PWM Control at 90 Hz - Duty Cycle Variation
<img src="images/exercise_01/Task2.2a.jpeg" width="600" alt="Task 2.2 PWM at 90 Hz (Duty Cycle Variation)">

#### Task 2.2: Frequency Variation Test - Low Light Conditions
<img src="images/exercise_01/Task2.2bLowLight.jpeg" width="600" alt="Task 2.2 Frequency Variation (Low Light Test)">

#### Task 2.2: Video - PWM Frequency and Duty Cycle Adjustment
[View video: PWM Control Demonstration](images/exercise_01/Task2.2.mp4)

### The 'Failure Log'
*   **What went wrong:** Initially forgot to connect the common ground between the 5V and 12V supplies.
*   **How I managed it:** Checked all ground connections with the multimeter and ensured a single common ground point.
*   **What I learned:** The pull-down resistor is essential to prevent the gate from floating, and a shared ground is critical for proper circuit operation.

### Reflection
PWM control is superior to simple on/off switching because it allows smooth brightness adjustment without wasting energy as heat. By varying duty cycle, we achieve dimming by controlling the average power. For practical applications like LED lighting systems, PWM is ideal because it's efficient, provides smooth brightness control, and can operate at frequencies above the human perception threshold to eliminate visible flicker.

### References
*   [Digital Design & Fabrication | Exercise 1 Lab Manual]

---

## 3. Microcontroller Basics: Building an Alarm Clock (Exercise 2)

### Goal
To build a fully functional digital alarm clock using an Arduino microcontroller, integrating various components step-by-step. The final setup includes an active buzzer, an I2C LCD display, a Real-Time Clock (RTC) module, push buttons for user input, and an ultrasonic distance sensor to track waving gestures for snooze and stop commands.

### Process & Materials
*   **Materials Used:** Arduino UNO, Breadboard, Active Buzzer, I2C LCD Display (16x2), DS1307 RTC Module, 4 Push Buttons, URM37 Ultrasonic Sensor, Jumper wires, USB cable.
*   **Process:** 

    1. **Sub-circuit 1: Connecting the Buzzer**
       * We connected the buzzer to the Arduino to create simple audible alerts. We ran into a Linux permission problem (`sudo chmod 666 /dev/ttyACM0`) initially when trying to interact with the port. 
       * Without proper resistance or delays, it made a very loud continuous beeping. We initially forgot to connect `VIN` and had a library commented out. We adjusted the source code to assign the buzzer to Pin 12 to test its functionality.

    2. **Sub-circuit 2: Adding the LCD Display**
       * We integrated an I2C 16x2 LCD display. First, we had to find the correct I2C hardware address for the display by running an I2C scanner sketch, which identified our display at address `0x27`.
       * Initially, nothing was displayed on the screen; the output only appeared in the IDE's Serial Monitor.
       * We discovered we needed to install specific libraries to make it function properly, namely `LiquidCrystal_I2C` for the display control and `Adafruit BusIO` for the underlying I2C abstraction. Once the address and libraries were properly set up, we could successfully print text strings to the LCD.

    3. **Sub-circuit 3: Integrating the Real-Time Clock (RTC)**
       * We added a DS1307 RTC module to maintain accurate time independent of the Arduino's power cycle. Because the RTC also uses I2C communication, it seamlessly shares the SDA and SCL lines with the LCD display via the breadboard. We included the `RTClib.h` library to read and process the time easily.
       * The module is powered by a coin cell battery. During our first setup, we uploaded the script to sync the module with the computer's real-time. Thanks to the battery backup, when re-powering or uploading subsequent iterations of the program, the current time was saved and accurately maintained automatically.

    4. **Sub-circuit 4: Using Push Buttons**
       * We integrated push buttons to act as our menu and control inputs. To handle the inputs cleanly and avoid hardware bouncing issues (where a physical press registers as multiple messy digital signals), we utilized the `<Button.h>` library for automatic software debouncing.
       * As an isolated trial test, we wired a single button and programmed a feedback loop: pressing the button successfully triggered the Arduino's built-in "L" LED (Pin 13) to light up. This confirmed our pin definitions and physical breadboard connections were completely functional before we linked them to the complex alarm menu system.

    5. **Final Project: The Complete Alarm Clock**
       * We combined everything into one main circuit utilizing the following button mapped logic:
         * **White Button** (Pin 3): Alarm On/Off Toggle
         * **Red Button** (Pin 2): Menu Toggle (Switching between Main Clock, Set Time, and Set Melody pages)
         * **Yellow Button** (Pin 4): Set Hour / Preview Melody / STOP Alarm
         * **Black Button** (Pin 5): Set Minute / Cycle Melodies / SNOOZE Alarm
       * **How it works:** The system operates using a state machine driven by menus. By default, it shows the current time provided by the RTC module. Pressing the Red button cycles through setting the alarm time and selecting between different melodies (e.g., Classic, Digital, Arpeggio), which can be previewed directly before saving.
       * When the target alarm time is reached, the buzzer starts playing the chosen melody. To interact with the ringing alarm conveniently without having to aim for a small push button, we integrated an ultrasonic sensor (Pins 9 and 10) pointing upwards.
       * We integrated distance logic for touchless control: the sensor measures the distance continuously (normally resting at around ~34 cm facing the ceiling). If a hand waves close to the sensor (dropping the distance reading to 2-5 cm), it triggers a state change to silently stop or snooze the alarm smoothly.

### Code Snippets & Test Scripts

During the development process, isolated test scripts were created to verify individual hardware components before merging them into the complex final alarm clock software:

*   **[Hardware Integration Test](Exercise/exercise_02/button_test.ino):** A simple script we wrote to verify the LCD screen, internal pull-up buttons, and buzzer connectivity simultaneously. It prints real-time button statuses to the LCD and triggers a quick beep when pressed.
*   **[Ultrasonic Sensor Test](Exercise/exercise_02/ultrasonic_test.ino):** A standalone script created because the waving functionality initially failed due to pulse logic. It triggers the URM37 sensor, outputs distance measurements to the Serial Monitor, and successfully turns on the onboard LED (Pin 13) when an object (e.g., a hand) is within 20 cm.

**Final Alarm Clock Highlights: Distance Logic**
A section showing state variables and the distance-fetching logic out of the core final script:
```cpp
// State Variables
bool isAlarmSet = false;
bool isRinging = false;
bool didItRingToday = false;
short unsigned int AlarmHH = 12; 
short unsigned int AlarmMM = 0;  
int menuPage = 0; 
int selectedMelody = 0; 

// ... URM37 DISTANCE LOGIC ...
int getDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long duration = pulseIn(echoPin, HIGH);
  return duration * 0.034 / 2;
}
```

### Visual Documentation

#### Sub-circuit 1: Connecting the Buzzer
<img src="images/exercise_02/task2_1_buzzer.jpeg" width="600" alt="Sub-circuit 1 Buzzer">

#### Sub-circuit 2: LCD Integration
<img src="images/exercise_02/task2_2_lcd.jpeg" width="600" alt="Sub-circuit 2 LCD">

#### Sub-circuit 3: Real Time Clock Setup
<img src="images/exercise_02/task2_3_rtc.jpeg" width="600" alt="Sub-circuit 3 RTC">

#### Final Assembly Video
[View video: Final Alarm Clock Project](images/exercise_02/final_alarm_clock.mp4)

### The 'Failure Log'
*   **What went wrong:** Initially, the device did not connect to the port on Linux, requiring local overrides. We also missed out on `VIN` for our buzzer, and didn't use a resistor which caused intense loud beeping. Lastly, the waving function didn't work at first integration.
*   **How I managed it:** Systematically debugging components: moving the buzzer pin, installing missing `Adafruit BusIO` library components for the LCD to fire, and adding isolated test scripts (like the ultrasonic distance tester) before merging into the main codebase.
*   **What I learned:** Breaking down complex hardware setups into independent, testable sub-circuits (inputs, logic, outputs) vastly accelerates the diagnostics process. Utilizing standard modular libraries like `Adafruit BusIO` makes managing protocols like I2C significantly easier once correctly configured.

---

## 4. Sensors and Actuators: Smart Sleep Pillow (Exercise 3)

### Goal
To build a system utilizing sensors and actuators; specifically, an automated Pillow that inflates and deflates. 

### Process & Materials
*   **Materials Used:** Arduino, Breadboard, MOSFET Modules, 2 DC Air Pumps (ZR370), 1 Air Valve (FA0520E), LDR (Light-Dependent Resistor), Inflatable Pouch/Pillow, Silicone Tubing.
*   **Process:** 

    1. **Testing MOSFET Modules:** First, we established basic control sequences for our high-power components. We configured Pin 9 to govern two MOSFETs (controlling the first pump and the air valve simultaneously) and Pin 8 to control the single MOSFET hooked up to the secondary side-connected air pump. We alternated testing their on and off states.
    
    2. **Pneumatic Cycle Configuration:** Once basic control was established, we developed an independent 3-pin pneumatic cycle. This involved separating the control of the inflate pump (Pin 9), the valve (Pin 10), and the deflate pump (Pin 8). We programmed continuous cycles representing four distinct phases:
       * **Inflate Phase:** Connecting the inflate pump to the pillow while the valve is deactivated to let air flow in.
       * **Hold Phase:** Keeping the valve activated to trap the air inside.
       * **Deflate Phase:** Opening the exhaust path by keeping the valve activated while running the deflate pump.
       * **Rest Phase:** Powering everything down briefly.
       
    3. **Final Smart Sleep Pillow:** We integrated an analog LDR light sensor on Pin A0 to automate this mechanism based on room darkness. We monitored real-time light thresholds using the serial monitor to calibrate the system. We established `400` as our `DARKNESS_THRESHOLD`. 
       * **"Good Night" mode:** When the light drops below 400, the pillow triggers the valve and inflate pump to fill the pillow so the user can sleep comfortably.
       * **"Good Morning" mode:** When ambient light returns to 400 or above, the system triggers the opening of the valve and activates the deflate pump to wake the user up by deflating the pillow.

### Code Snippets & Logic Highlights

The logic centers around an `isInflated` boolean tracking state to prevent the system from constantly triggering the pumps on every loop iteration as long as it's dark or bright.

**Final Light-Activated Logic:**
```cpp
  // 1. Read Light Level
  int lightLevel = analogRead(LDR_PIN);
  
  // 2. Logic: It gets dark -> Inflate the pillow
  if (lightLevel < DARKNESS_THRESHOLD && isInflated == false) {
    digitalWrite(VALVE_PIN, HIGH);
    digitalWrite(INFLATE_PUMP_PIN, HIGH);
    delay(INFLATE_TIME);
    
    digitalWrite(INFLATE_PUMP_PIN, LOW);
    isInflated = true; 
  }
  
  // 3. Logic: It gets bright -> Deflate the pillow
  else if (lightLevel >= DARKNESS_THRESHOLD && isInflated == true) {
    digitalWrite(VALVE_PIN, HIGH);
    digitalWrite(DEFLATE_PUMP_PIN, HIGH);
    delay(DEFLATE_TIME);
    digitalWrite(VALVE_PIN, LOW);
    
    digitalWrite(DEFLATE_PUMP_PIN, LOW);
    isInflated = false;
  }
```

### Visual Documentation

#### Initial Hardware Setup
<img src="images/exercise_03/Inital_Build.jpeg" width="600" alt="Initial Build Setup for the Smart Sleep Pillow">

#### Prototype Testing & Light Trigger Logic
[View video: Testing MOSFETs with Light Trigger](images/exercise_03/Test_Mos_Light.mp4)

#### Pneumatic Component Cycle Test
[View video: Inflate and Deflate Cycle (4 Seconds)](images/exercise_03/Inflate_Deflate_4_Sek.mp4)

#### Light Sensor Calibration & Debugging
[View video: Debugging Light Values Output](images/exercise_03/Debug_Light_Values.mp4)

The final project was an automated "Smart Sleep Pillow" that inflates and deflates depending on ambient light levels. To measure the light, we utilized a **Photo cell (CdS photoresistor)** placed in a voltage divider with a fixed resistor, allowing us to read values using `analogRead()`. 

**Sensor Characteristics:**
*   **Resistance:** As light increases, its resistance decreases (ranging from several MΩ in total darkness down to ~1 kΩ in bright light).
*   **Usage:** They are low cost, easy to use, and perfect for light-activated triggers like automatic night lights or ambient light adjustments.
*   **Limitations:** Because each CdS cell varies significantly in its exact resistance (up to 50% variance), they aren't suitable for precise lux measurements, only for detecting relative light changes (bright vs. dark).

**System Behavior:**
*   **Nighttime (Dark):** The system detects the drop in light and inflates the pillow, making it bigger so the person can sleep comfortably.
*   **Morning (Bright):** When the sun rises, the sensor detects the increased light and deflates the pillow, making it smaller to naturally encourage the person to wake up and stand up.

#### Final Assembly Execution
[View video: Final Result - Smart Sleep Pillow](images/exercise_03/Final_result_light_sensor.mp4)

### The 'Failure Log'
*   **What went wrong:** Initially, we ran into problems with the pneumatic tubing system, we had connected the air valve on incorrectly, blocking the exhaust path. Because of this, it was physically unable to deflate the air out of the pillow, even when the software sent the correct commands. Additionally, finding reliable light thresholds caused early failures ([Failure_Light_Sensor.mp4](images/exercise_03/Failure_Light_Sensor.mp4)).
*   **How I managed it:** We re-routed the silicone tubing so the air pump accurately pulled air through the opened valve path instead of fighting a closed airway. For the light sensor, we added serial monitoring for the `analogRead(LDR_PIN)` values to debug the ambient parameters until we settled on a threshold limit of 400.
*   **What I learned:** Pneumatic routing requires an understanding of standard valve states (normally-open vs. normally-closed) and pathway directions. Just because the software triggers correctly doesn't mean the physical hardware is capable of executing it. Furthermore, environmentally dependent sensors always require manual real-world threshold calibration rather than relying on guessed fixed numbers.
