EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L igorkelvin:SDCard_Module A4
U 1 1 5FB19464
P 7500 3500
F 0 "A4" H 8128 3596 50  0000 L CNN
F 1 "SDCard_Module" H 8128 3505 50  0000 L CNN
F 2 "" H 7450 4200 50  0001 C CNN
F 3 "" H 7450 4200 50  0001 C CNN
	1    7500 3500
	1    0    0    -1  
$EndComp
$Comp
L igorkelvin:DS3231_Module A3
U 1 1 5FB1770C
P 7500 2500
F 0 "A3" H 8078 2601 50  0000 L CNN
F 1 "DS3231_Module" H 8078 2510 50  0000 L CNN
F 2 "" H 6500 2700 50  0001 C CNN
F 3 "" H 6500 2700 50  0001 C CNN
	1    7500 2500
	1    0    0    -1  
$EndComp
Text Label 4500 2600 2    50   ~ 0
SCL
Wire Wire Line
	4500 2600 4600 2600
Text Label 4500 2300 2    50   ~ 0
SDA
Wire Wire Line
	4500 2300 4600 2300
Text Label 4500 1300 2    50   ~ 0
3V3
Wire Wire Line
	4500 1300 4600 1300
Text Label 4500 1400 2    50   ~ 0
GND
Wire Wire Line
	4500 1400 4600 1400
Text Label 6100 1300 0    50   ~ 0
5V
Wire Wire Line
	6100 1300 6000 1300
Text Label 6900 1300 2    50   ~ 0
5V
Wire Wire Line
	6900 1300 7000 1300
Text Label 6100 1400 0    50   ~ 0
GND
Wire Wire Line
	6100 1400 6000 1400
Text Label 6900 1400 2    50   ~ 0
GND
Wire Wire Line
	6900 1400 7000 1400
$Comp
L senseair_s8_module:SenseAir_S8_Module A5
U 1 1 5FB1BDE1
P 7600 1500
F 0 "A5" H 7600 1965 50  0000 C CNN
F 1 "SenseAir_S8_Module" H 7600 1874 50  0000 C CNN
F 2 "" H 7600 1400 50  0001 C CNN
F 3 "" H 7600 1400 50  0001 C CNN
	1    7600 1500
	1    0    0    -1  
$EndComp
NoConn ~ 7000 1500
NoConn ~ 7000 1600
NoConn ~ 8200 1600
NoConn ~ 8200 1300
NoConn ~ 6800 2200
NoConn ~ 6800 2300
NoConn ~ 3900 3700
Text Label 6700 2600 2    50   ~ 0
3V3
Wire Wire Line
	6800 2600 6700 2600
Text Label 6700 2700 2    50   ~ 0
GND
Wire Wire Line
	6700 2700 6800 2700
Text Label 6700 2500 2    50   ~ 0
SDA
Wire Wire Line
	6700 2500 6800 2500
Wire Wire Line
	6700 2400 6800 2400
Text Label 6700 2400 2    50   ~ 0
SCL
Wire Wire Line
	6700 3300 6600 3300
Text Label 6600 3200 2    50   ~ 0
GND
Wire Wire Line
	6600 3200 6700 3200
Wire Wire Line
	6700 3600 6600 3600
Wire Wire Line
	6600 3700 6700 3700
Wire Wire Line
	6600 3500 6700 3500
Wire Wire Line
	6600 3400 6700 3400
Wire Wire Line
	3900 3000 4000 3000
Text Label 4000 3100 0    50   ~ 0
GND
Wire Wire Line
	4000 3100 3900 3100
$Comp
L winsen_zh06_module:Winsen_ZH06_Module A1
U 1 1 5FB091C1
P 3300 3400
F 0 "A1" H 3828 3496 50  0000 L CNN
F 1 "Winsen_ZH06_Module" H 3828 3405 50  0000 L CNN
F 2 "" H 3300 4000 50  0001 C CNN
F 3 "" H 3300 4000 50  0001 C CNN
	1    3300 3400
	-1   0    0    -1  
$EndComp
Text Label 4000 3000 0    50   ~ 0
5V
Text Label 6600 3400 2    50   ~ 0
MISO
Text Label 6600 3500 2    50   ~ 0
MOSI
Text Label 6600 3600 2    50   ~ 0
SCK
Text Label 6600 3700 2    50   ~ 0
CS
Wire Wire Line
	3900 1600 3800 1600
Wire Wire Line
	3900 1400 3800 1400
Text Label 3900 1400 0    50   ~ 0
GND
Wire Wire Line
	3800 1300 3900 1300
Text Label 3900 1300 0    50   ~ 0
3V3
$Comp
L bme280_module:BME280_Module A2
U 1 1 5FB154D9
P 3450 1450
F 0 "A2" H 3728 1501 50  0000 L CNN
F 1 "BME280_Module" H 3728 1410 50  0000 L CNN
F 2 "" H 3400 1400 50  0001 C CNN
F 3 "" H 3400 1400 50  0001 C CNN
	1    3450 1450
	-1   0    0    -1  
$EndComp
$Comp
L Device:R_US R2
U 1 1 5FB92941
P 3300 2350
F 0 "R2" H 3368 2396 50  0000 L CNN
F 1 "10K" H 3368 2305 50  0000 L CNN
F 2 "" V 3340 2340 50  0001 C CNN
F 3 "~" H 3300 2350 50  0001 C CNN
	1    3300 2350
	1    0    0    -1  
$EndComp
Text Label 1300 1400 2    50   ~ 0
3V3
Text Label 1300 1500 2    50   ~ 0
GND
Text Label 1800 1400 0    50   ~ 0
5V
Wire Wire Line
	1800 1400 1700 1400
Wire Wire Line
	1700 1400 1700 1200
Wire Wire Line
	1400 1400 1400 1200
Wire Wire Line
	1300 1500 1400 1500
Wire Wire Line
	1400 1500 1400 1800
$Comp
L power:GNDREF #PWR02
U 1 1 5FBA23F0
P 1400 1800
F 0 "#PWR02" H 1400 1550 50  0001 C CNN
F 1 "GNDREF" H 1405 1627 50  0000 C CNN
F 2 "" H 1400 1800 50  0001 C CNN
F 3 "" H 1400 1800 50  0001 C CNN
	1    1400 1800
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR03
U 1 1 5FBA2BB8
P 1700 1200
F 0 "#PWR03" H 1700 1050 50  0001 C CNN
F 1 "+5V" H 1715 1373 50  0000 C CNN
F 2 "" H 1700 1200 50  0001 C CNN
F 3 "" H 1700 1200 50  0001 C CNN
	1    1700 1200
	-1   0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR01
U 1 1 5FBA337C
P 1400 1200
F 0 "#PWR01" H 1400 1050 50  0001 C CNN
F 1 "+3V3" H 1415 1373 50  0000 C CNN
F 2 "" H 1400 1200 50  0001 C CNN
F 3 "" H 1400 1200 50  0001 C CNN
	1    1400 1200
	1    0    0    -1  
$EndComp
Wire Wire Line
	1300 1400 1400 1400
$Comp
L power:GNDREF #PWR04
U 1 1 5FBB86D6
P 3300 2600
F 0 "#PWR04" H 3300 2350 50  0001 C CNN
F 1 "GNDREF" H 3305 2427 50  0000 C CNN
F 2 "" H 3300 2600 50  0001 C CNN
F 3 "" H 3300 2600 50  0001 C CNN
	1    3300 2600
	1    0    0    -1  
$EndComp
Wire Wire Line
	3300 2600 3300 2500
Wire Wire Line
	3300 2200 3300 2100
$Comp
L Device:R_PHOTO R1
U 1 1 5FB14BF4
P 3050 2100
F 0 "R1" H 3120 2146 50  0000 L CNN
F 1 "R_PHOTO" H 3120 2055 50  0000 L CNN
F 2 "" V 3100 1850 50  0001 L CNN
F 3 "~" H 3050 2050 50  0001 C CNN
	1    3050 2100
	0    1    1    0   
$EndComp
Wire Wire Line
	3300 2100 3200 2100
Text Label 2800 2100 2    50   ~ 0
5V
Wire Wire Line
	2900 2100 2800 2100
Text Label 3700 2100 0    50   ~ 0
LDR
Wire Wire Line
	3300 2100 3700 2100
Connection ~ 3300 2100
Text Label 6600 3300 2    50   ~ 0
5V
Text Label 4500 2700 2    50   ~ 0
MOSI
Text Label 3900 1600 0    50   ~ 0
SDA
Wire Wire Line
	3900 1500 3800 1500
Text Label 3900 1500 0    50   ~ 0
SCL
Wire Wire Line
	4500 2700 4600 2700
Text Label 4500 2200 2    50   ~ 0
MISO
Wire Wire Line
	4500 2200 4600 2200
Text Label 4500 2100 2    50   ~ 0
SCK
Wire Wire Line
	4500 2100 4600 2100
Text Label 4500 2000 2    50   ~ 0
CS
Wire Wire Line
	4500 2000 4600 2000
Text Label 6100 2400 0    50   ~ 0
LDR
Text Label 4000 3300 0    50   ~ 0
TX2
Text Label 4500 1900 2    50   ~ 0
TX2
Wire Wire Line
	4500 1900 4600 1900
Wire Wire Line
	4000 3300 3900 3300
Text Label 4000 3400 0    50   ~ 0
RX2
Wire Wire Line
	4000 3400 3900 3400
Text Label 4500 1800 2    50   ~ 0
RX2
Wire Wire Line
	4500 1800 4600 1800
Text Label 6100 1500 0    50   ~ 0
RXS
Wire Wire Line
	6100 1500 6000 1500
Text Label 8300 1500 0    50   ~ 0
RXS
Wire Wire Line
	8300 1500 8200 1500
Text Label 6100 1900 0    50   ~ 0
TXS
Wire Wire Line
	6100 1900 6000 1900
Text Label 8300 1400 0    50   ~ 0
TXS
Wire Wire Line
	8200 1400 8300 1400
Text Label 6100 1800 0    50   ~ 0
CAL
Wire Wire Line
	6100 1800 6000 1800
Text Label 8300 1700 0    50   ~ 0
CAL
Wire Wire Line
	8300 1700 8200 1700
$Comp
L esp32_devkit_v1:ESP32_DEVKIT_V1 U1
U 1 1 5FB13BB6
P 5300 2000
F 0 "U1" H 5300 3215 50  0000 C CNN
F 1 "ESP32_DEVKIT_V1" H 5300 3124 50  0000 C CNN
F 2 "" H 5300 2100 50  0001 C CNN
F 3 "" H 5300 2100 50  0001 C CNN
	1    5300 2000
	1    0    0    -1  
$EndComp
NoConn ~ 4600 1500
NoConn ~ 4600 1600
NoConn ~ 4600 2400
NoConn ~ 4600 2500
NoConn ~ 6000 2700
NoConn ~ 6000 2600
NoConn ~ 6000 2500
NoConn ~ 6000 2300
NoConn ~ 6000 2200
NoConn ~ 6000 2000
NoConn ~ 6000 1700
NoConn ~ 6000 1600
Wire Wire Line
	6000 2400 6100 2400
NoConn ~ 4600 1700
NoConn ~ 6000 2100
$EndSCHEMATC
