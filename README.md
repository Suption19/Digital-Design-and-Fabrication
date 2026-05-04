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
