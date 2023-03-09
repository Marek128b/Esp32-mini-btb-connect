# Esp32-mini-btb-connect V1.1

**table of content**
- [Esp32-mini-btb-connect V1.1](#esp32-mini-btb-connect-v11)
  - [Debugging Prozess](#debugging-prozess)
    - [Debugging Checklist](#debugging-checklist)
    - [Debugging Protocol](#debugging-protocol)
  - [Description](#description)
  - [Schematic](#schematic)
    - [Power-Circuit Description](#power-circuit-description)
  - [PCB](#pcb)
    - [3D-Layout](#3d-layout)
    - [Bottom-PCB Description](#bottom-pcb-description)
    - [Pinout](#pinout)

## Debugging Prozess
### Debugging Checklist
- [x] checking chip working crystal oszillator
- [x] checking voltage converter 5V - 3V3
- [x] checking power supply
- [ ] checking usb to serial CH340E
- [ ] testing uploading
- [ ] testing WiFi and Bluetooth
- [x] testing on board LEDs PWM WS2812
- [ ] testing battery charcher 

### Debugging Protocol
**31.01.2023:**
I got the First Blink Programm uploaded with an external USB to UART adapter an external Power using an AMS1117-3.3 and electrolytic capasitors. The First Problem i got was that the VS-Code with the PlatformIO plugin didn't recognize the denky_d4-ESP32-pico-V3-02 module. To fix that i had to reinstall the Espressif 32 boards from the Platforms tab, i just hit uninstall on the Espressif 32 and went to the EMBEDDED tab to search for the Espressif 32 and click install. And that fixed the Problem. The next Problem was that the Programming didn't work but that was due to a design error in the first version design of this product. i fixed that by connecting on the back side of the board the CN2 connector pins IO32 and IO33 to a 40MHz crystal and two load capacitors with a value of 12pF and a pin of the crystal to ground. <br>

**02.02.2023:**
I got the linear Dropout Regulator working now, the Error was that on the board the EN Pin was tied to GND istead of VCC (5V). This would have never aktivated the Regulator. BYP- Capacitor not strictly needed for operation but it's better to have a small 10nF capacitor connected to it and Ground. <br>


**18.02.2023:**
The led test programm got uploaded using an FTDI usb to serial adapter. this also worked without the 40Mhz crystal because the esp32-pico-v3-02 chip is a SoC and therefor doesn't need an external crystal to work so i just cut the wires to the crystal. The usb uart wires had to be resoldered as they got lose and the programm wouldn't upload anymore. I wrote a tiny library for the esp which makes working without the delay() function easier. <br>
___

## Description
With this project you are able to connect one Esp32 microcontroller with internal 8MB FLASH and 2MB SRAM to any project you would like. This PCB has two onboard Buttons for Boot-mode and Resetting. It has two Power LEDs and one LED on GPIO2. It also has an adressable WS2812 RGB LED on GPIO5. The board has a 2.4GHz onboard antenna as well as an external antenna connector that can be switched between by setting one or the other GPIO to HIGH. This Project has a circuit for charching a LiPo/LiIon Battery and automatically switching between Battery and USB power.
___

## Schematic
![Schematic](img/Schematic_ESP32%20pico%20dual%20core%20mini%20btb%20connect_2023-03-07.svg)

### Power-Circuit Description
The power get's switched automatically using the N-Channnel MOSFET (Q3). The gate of the MOSFET gets normally pulled Low via a 10k Ohm resistor. If there is no USB voltage (+5V) the MOSFET switches the power so that the Battery Voltage (Vbat) can pass through to the Voltage Regulator which regulates it's output voltage to 3V3. If however USB Voltage (+5V) is present the MOSFET switches off and the USB Voltage goes through the Diode (D1) and proceedes to go to the Voltage Regulator.
___

## PCB
<img src="img\PCB_PCB_ESP32 pico dual core mini btb connect_2023-03-07.svg" alt="PCB" width="75%"/>

### 3D-Layout
<img src="img\ESP32-pico-btb-connect-3D-top.png" alt="PCB Top" width="75%"/>
<img src="img\Screenshot 2023-03-07 141211.png" alt="PCB Bottom" width="75%"/>

### Bottom-PCB Description
The Bottom side of the PCB has 4 slim Board to Board connector's which transport USB power, 3V3 regulated voltage as well as Digital ans Analog Pin functions to any daughter board. There are some extra 1mm pads to quickly test and Programm this Mainboard using a special made programmer and test-software.

### Pinout

CN1|Pin Nr.|GPIO|Function|
|--|-------|----|--------|
|   |1|IO14| H_SCK|
|   |2|IO12|H_MISO|
|   |3|IO13|H_MOSI|
|   |4|**3V3**|**POWER**|
|   |5|**+5V**|**POWER**|
|   |6|IO4|
|   |7|IO0|
|   |8|IO2|
|   |9|IO15|H_CS|
|   |10|**GND**|**Power**|

CN2|Pin Nr.|GPIO|Function|
|--|-------|----|--------|
|   |1|IO15|
|   |2|I36|Input only|
|   |3|I37|Input only|
|   |4|**3V3**|**POWER**|
|   |5|**+5V**|**POWER**|
|   |6|IO26|
|   |7|IO27|
|   |8|IO34|
|   |9|IO35|
|   |10|**GND**|**POWER**|

CN3|Pin Nr.|GPIO|Function|
|--|-------|----|--------|
|  |1      |IO21|SDA|
|  |2      |IO1|TX|
|  |3      |IO3|RX|
|  |4      |IO33|
|  |5      |IO22|SCL|
|  |6      |IO19|
|  |7      |I38|Input only|
|  |8      |I39|Input only|
|  |9      |EN | EN|
|  |10     |**GND**|**POWER**|

CN4|Pin Nr.|GPIO|Function|
|--|-------|----|--------|
|   |1|IO11|
|   |2|IO10|
|   |3|IO9|
|   |4|IO32|
|   |5|IO20|
|   |6|IO5|
|   |7|IO8|
|   |8|IO7|
|   |9|IO6|
|   |10|**GND**|**POWER**|
