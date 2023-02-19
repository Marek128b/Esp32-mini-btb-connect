# Esp32-mini-btb-connect

**table of content**
- [Esp32-mini-btb-connect](#esp32-mini-btb-connect)
  - [Debugging Prozess](#debugging-prozess)
    - [Debugging Checklist](#debugging-checklist)
    - [Debugging Protocol](#debugging-protocol)
  - [Description](#description)
  - [Schematic](#schematic)
  - [PCB](#pcb)
    - [3D-Layout](#3d-layout)
  - [BOM](#bom)

## Debugging Prozess
### Debugging Checklist
- [x] checking chip working crystal oszillator
- [x] checking voltage converter 5V - 3V3
- [ ] checking power supply
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
![](img/Schematic_ESP32%20pico%20dual%20core%20mini%20btb%20connect_2022-12-20.svg)
___

## PCB
<img src="img/PCB_PCB_ESP32%20pico%20dual%20core%20mini%20btb%20connect_2022-12-20.svg" alt="." width="50%"/>

### 3D-Layout
<img src="img\PCB-3D-top.PNG" alt="." width="50%"/>
<img src="img\PCB-3D-bottom.PNG" alt="." width="50%"/>

___

## BOM
|ID|Name|Designator|Footprint|Quantity|Manufacturer Part|Manufacturer|Supplier|Supplier Part|Price|Pins|Resistance (Ohms)|
|---|---|---|---|---|---|---|---|---|---|---|---|
|1|Huaxin|ANT1|ANT-SMD_L5.2-W2.0|1|RFANT5220110A2T|Huaxin S&T|LCSC|C201761|0.024|2||
|2|680pF|C1|C0603|1|GCM1885C2A681JA16D|muRata(村田)|LCSC|C126581|0.003|2||
|3|620pF|C2|C0603|1|CC0603JRNPO9BN621|YAGEO(国巨)|LCSC|C325470|0.001|2||
|4|33pF|C3|C4|C0603|2|GQM1875C2E330JB12D|muRata(村田)|LCSC|C913596|0.054|2||
|5|10uF|C5|C6|C0603|2|LMK107BJ106MALTD|TAIYO YUDEN|LCSC|C18800|0.002|2||
|6|YXT-BB10-10S-02|CN1|CN2|CN3|CN4|CONN-SMD_YXT-BB10-10S-02|4|YXT-BB10-10S-02|YXT(益鑫通）|LCSC|C2763962|0.011|14||
|7|B2B-XH-A (LF)(SN)|CN5|CONN-TH_B2B-XH-A-LF-SN|1|B2B-XH-A(LF)(SN)|JST|LCSC|C158012|0.006|2||
|8|BAT60AE6327H|D1|SOD-323_L1.8-W1.3-LS2.5-RD|1|BAT60AE6327H|Infineon Technologies|LCSC|C520634|0.038|2||
|9|LED-0603_R|LED1|LED4|LED5|LED0603_RED|3|19-217/R6C-AL1M2VY/3T|EVERLIGHT(台湾亿光)|LCSC|C72044|0.003|2||
|10|WS2812B-2020|LED2|LED-SMD_4P-L2.0-W2.0-TL_WS2812B-2020|1|WS2812B-2020|worldsemi|LCSC|C965555|0.015|4||
|11|CJ3139K_C2890149|PMOS|SOT-23-3_L2.9-W1.3-P1.90-LS2.4-BR|1|CJ3139K|CJ（江苏长电/长晶）|LCSC|C2890149|0.006|3||
|12|S8050_C444723|Q1|Q2|SOT-23_L2.9-W1.3-P1.90-LS2.4-BR|2|S8050|Slkor(萨科微)|LCSC|C444723|0.002|3||
|13|100mΩ|R1|R2|R0603|2|0603WAJ010KT5E|UNI-ROYAL(厚声)|LCSC|C247025||2|0.1|
|14|5kΩ|R3|R4|R7|R10|R11|R0603|5|RTT035001FTP|RALEC|LCSC|C166926||2|5K|
|15|2K|R5|R0603|1|RC0603FR-072KL|YAGEO|LCSC|C105576||2||
|16|10kΩ|R6|R0603|1|FRC0603J103TS|FOJAN(富捷)|LCSC|C2930027||2||
|17|12kΩ|R8|R9|R13|R14|R0603|4|AR03BTDX1202|Viking Tech|LCSC|C319891|0.005|2|12K|
|18|73412-0110|RF1|ANT-SMD_73412-0110|1|734120110|MOLEX|LCSC|C434806|0.058|4||
|19|TS-1088-AR02016|SW1|SW2|SW-SMD_L4.0-W2.9-LS5.0|2|TS-1088-AR02016|XUNPU(讯普)|LCSC|C720477|0.008|2||
|20|ESP32-PICO-V3-02|U1|QFN-48_L7.0-W7.0-P0.50-TL-EP5.1|1|ESP32-PICO-V3-02|ESPRESSIF 乐鑫|LCSC|C908392|0.903|49||
|21|SKY13323-378LF|U2|DFN-6_L1.0-W1.0-P0.35-BL-EP0.15|1|SKY13323-378LF|Skyworks Solutions|LCSC|C150867|0.053|6||
|22|CH340E|U3|MSOP-10_L3.0-W3.0-P0.50-LS5.0-BL|1|CH340E|WCH|LCSC|C99652|0.092|10||
|23|ME4054BM5G-N|U5|TSOT-23-5_L2.9-W1.6-P0.95-LS2.8-BL|1|ME4054BM5G-N|MICRONE(Nanjing Micro One Elec)|LCSC|C478383|0.008|5||
|24|ZL6205A33TS5|U6|TSOT-23-5_L2.9-W1.6-P0.95-LS2.8-BL|1|ZL6205A33TS5|ZLG Zhiyuan Elec|LCSC|C485900|0.033|5||
|25|KH-TYPE-C-16P|USB1|USB-C-SMD_KH-TYPE-C-16P|1|KH-TYPE-C-16P|kinghelm(金航标)|LCSC|C709357|0.013|20||

___
