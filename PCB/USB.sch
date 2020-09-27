EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 5 5
Title "USB"
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Connector:USB_B_Mini J?
U 1 1 5F6C87FB
P 7025 3750
AR Path="/5F6C87FB" Ref="J?"  Part="1" 
AR Path="/5F584CC7/5F6C87FB" Ref="J?"  Part="1" 
AR Path="/5F6BB528/5F6C87FB" Ref="J11"  Part="1" 
F 0 "J11" H 6750 3775 50  0000 C CNN
F 1 "USB_B_Mini" H 6600 3875 50  0000 C CNN
F 2 "Connector_USB:USB_Mini-B_Lumberg_2486_01_Horizontal" H 7175 3700 50  0001 C CNN
F 3 "~" H 7175 3700 50  0001 C CNN
	1    7025 3750
	-1   0    0    -1  
$EndComp
$Comp
L Device:Ferrite_Bead FB?
U 1 1 5F6C8801
P 6725 3100
AR Path="/5F6C8801" Ref="FB?"  Part="1" 
AR Path="/5F584CC7/5F6C8801" Ref="FB?"  Part="1" 
AR Path="/5F6BB528/5F6C8801" Ref="FB5"  Part="1" 
F 0 "FB5" H 6500 3150 50  0000 C CNN
F 1 "1A" H 6525 3075 50  0000 C CNN
F 2 "Inductor_SMD:L_0805_2012Metric" V 6655 3100 50  0001 C CNN
F 3 "~" H 6725 3100 50  0001 C CNN
	1    6725 3100
	-1   0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5F6C8807
P 6450 3750
AR Path="/5F6C8807" Ref="R?"  Part="1" 
AR Path="/5F584CC7/5F6C8807" Ref="R?"  Part="1" 
AR Path="/5F6BB528/5F6C8807" Ref="R15"  Part="1" 
F 0 "R15" V 6375 3700 50  0000 L CNN
F 1 "0-22" V 6450 3650 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 6380 3750 50  0001 C CNN
F 3 "~" H 6450 3750 50  0001 C CNN
	1    6450 3750
	0    -1   1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 5F6C880D
P 6450 3850
AR Path="/5F6C880D" Ref="R?"  Part="1" 
AR Path="/5F584CC7/5F6C880D" Ref="R?"  Part="1" 
AR Path="/5F6BB528/5F6C880D" Ref="R16"  Part="1" 
F 0 "R16" V 6525 3800 50  0000 L CNN
F 1 "0-22" V 6450 3750 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 6380 3850 50  0001 C CNN
F 3 "~" H 6450 3850 50  0001 C CNN
	1    6450 3850
	0    -1   1    0   
$EndComp
Wire Wire Line
	7125 4150 7025 4150
$Comp
L power:GND #PWR?
U 1 1 5F6C8814
P 7125 4150
AR Path="/5F6C8814" Ref="#PWR?"  Part="1" 
AR Path="/5F584CC7/5F6C8814" Ref="#PWR?"  Part="1" 
AR Path="/5F6BB528/5F6C8814" Ref="#PWR032"  Part="1" 
F 0 "#PWR032" H 7125 3900 50  0001 C CNN
F 1 "GND" H 7130 3977 50  0000 C CNN
F 2 "" H 7125 4150 50  0001 C CNN
F 3 "" H 7125 4150 50  0001 C CNN
	1    7125 4150
	-1   0    0    -1  
$EndComp
Connection ~ 7125 4150
Wire Wire Line
	6725 3750 6600 3750
Wire Wire Line
	6725 3850 6600 3850
$Comp
L Device:C C?
U 1 1 5F6C881D
P 6175 4250
AR Path="/5F6C881D" Ref="C?"  Part="1" 
AR Path="/5F584CC7/5F6C881D" Ref="C?"  Part="1" 
AR Path="/5F6BB528/5F6C881D" Ref="C20"  Part="1" 
F 0 "C20" V 5975 4250 50  0000 C CNN
F 1 "33pF" V 6050 4250 50  0000 C CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 6213 4100 50  0001 C CNN
F 3 "~" H 6175 4250 50  0001 C CNN
	1    6175 4250
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 5F6C8823
P 5825 4250
AR Path="/5F6C8823" Ref="C?"  Part="1" 
AR Path="/5F584CC7/5F6C8823" Ref="C?"  Part="1" 
AR Path="/5F6BB528/5F6C8823" Ref="C19"  Part="1" 
F 0 "C19" V 5625 4250 50  0000 C CNN
F 1 "33pF" V 5700 4250 50  0000 C CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 5863 4100 50  0001 C CNN
F 3 "~" H 5825 4250 50  0001 C CNN
	1    5825 4250
	1    0    0    -1  
$EndComp
Wire Wire Line
	6175 4100 6175 3850
Wire Wire Line
	6175 3850 6300 3850
Wire Wire Line
	5825 4100 5825 3750
Wire Wire Line
	5825 4400 6000 4400
$Comp
L Device:C C?
U 1 1 5F6C882D
P 6875 2800
AR Path="/5F6C882D" Ref="C?"  Part="1" 
AR Path="/5F6BB528/5F6C882D" Ref="C21"  Part="1" 
F 0 "C21" V 6650 2750 50  0000 L CNN
F 1 "100nF" V 6725 2700 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 6913 2650 50  0001 C CNN
F 3 "~" H 6875 2800 50  0001 C CNN
	1    6875 2800
	0    1    1    0   
$EndComp
Wire Wire Line
	6725 3250 6725 3550
Wire Wire Line
	6725 2800 6725 2950
$Comp
L power:GND #PWR?
U 1 1 5F6C8835
P 6000 4400
AR Path="/5F6C8835" Ref="#PWR?"  Part="1" 
AR Path="/5F584CC7/5F6C8835" Ref="#PWR?"  Part="1" 
AR Path="/5F6BB528/5F6C8835" Ref="#PWR030"  Part="1" 
F 0 "#PWR030" H 6000 4150 50  0001 C CNN
F 1 "GND" H 6005 4227 50  0000 C CNN
F 2 "" H 6000 4400 50  0001 C CNN
F 3 "" H 6000 4400 50  0001 C CNN
	1    6000 4400
	1    0    0    -1  
$EndComp
Connection ~ 6000 4400
Wire Wire Line
	6000 4400 6175 4400
$Comp
L power:GND #PWR?
U 1 1 5F6C883D
P 7025 2800
AR Path="/5F6C883D" Ref="#PWR?"  Part="1" 
AR Path="/5F584CC7/5F6C883D" Ref="#PWR?"  Part="1" 
AR Path="/5F6BB528/5F6C883D" Ref="#PWR031"  Part="1" 
F 0 "#PWR031" H 7025 2550 50  0001 C CNN
F 1 "GND" H 7030 2627 50  0000 C CNN
F 2 "" H 7025 2800 50  0001 C CNN
F 3 "" H 7025 2800 50  0001 C CNN
	1    7025 2800
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R?
U 1 1 5F6C8843
P 5825 3275
AR Path="/5F6C8843" Ref="R?"  Part="1" 
AR Path="/5F6BB528/5F6C8843" Ref="R14"  Part="1" 
F 0 "R14" H 5875 3325 50  0000 L CNN
F 1 "1K5" V 5825 3200 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 5755 3275 50  0001 C CNN
F 3 "~" H 5825 3275 50  0001 C CNN
	1    5825 3275
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5F6C8849
P 5375 2925
AR Path="/5F6C8849" Ref="R?"  Part="1" 
AR Path="/5F6BB528/5F6C8849" Ref="R13"  Part="1" 
F 0 "R13" V 5300 2925 50  0000 C CNN
F 1 "1K" V 5375 2925 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 5305 2925 50  0001 C CNN
F 3 "~" H 5375 2925 50  0001 C CNN
	1    5375 2925
	0    1    1    0   
$EndComp
Connection ~ 5825 3750
$Comp
L Transistor_BJT:MMBT3906 Q?
U 1 1 5F6C886E
P 5725 2925
AR Path="/5F6C886E" Ref="Q?"  Part="1" 
AR Path="/5F6BB528/5F6C886E" Ref="Q2"  Part="1" 
F 0 "Q2" H 5916 2879 50  0000 L CNN
F 1 "MMBT3906" H 5916 2970 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 5925 2850 50  0001 L CIN
F 3 "https://www.fairchildsemi.com/datasheets/2N/2N3906.pdf" H 5725 2925 50  0001 L CNN
	1    5725 2925
	1    0    0    1   
$EndComp
Wire Wire Line
	5825 3750 6300 3750
Wire Wire Line
	4625 3750 5825 3750
Wire Wire Line
	6175 3850 4625 3850
Connection ~ 6175 3850
Wire Wire Line
	5225 2925 4625 2925
$Comp
L Jumper:SolderJumper_2_Open JP?
U 1 1 5F6C887D
P 5825 3600
AR Path="/5F6C887D" Ref="JP?"  Part="1" 
AR Path="/5F6BB528/5F6C887D" Ref="JP2"  Part="1" 
F 0 "JP2" V 5779 3668 50  0000 L CNN
F 1 "DISC" V 5870 3668 50  0000 L CNN
F 2 "Jumper:SolderJumper-2_P1.3mm_Open_RoundedPad1.0x1.5mm" H 5825 3600 50  0001 C CNN
F 3 "~" H 5825 3600 50  0001 C CNN
	1    5825 3600
	0    1    1    0   
$EndComp
Wire Wire Line
	5825 3425 5825 3450
Text HLabel 4625 2925 0    50   Input ~ 0
DISC
Text HLabel 5825 2625 0    50   Input ~ 0
3.3V
Text HLabel 6375 2800 0    50   Output ~ 0
Vusb
Wire Wire Line
	5825 2625 5825 2725
Wire Wire Line
	6375 2800 6425 2800
Text HLabel 4625 3750 0    50   Input ~ 0
USBD+
Text HLabel 4625 3850 0    50   Output ~ 0
USBD-
$Comp
L Device:D_Schottky_ALT D5
U 1 1 5F6E12D8
P 6575 2800
F 0 "D5" H 6575 3016 50  0000 C CNN
F 1 "SS14" H 6575 2925 50  0000 C CNN
F 2 "Diode_SMD:D_SMA" H 6575 2800 50  0001 C CNN
F 3 "~" H 6575 2800 50  0001 C CNN
	1    6575 2800
	1    0    0    -1  
$EndComp
Connection ~ 6725 2800
Text Label 6600 3750 0    50   ~ 0
D+
Text Label 6600 3850 0    50   ~ 0
D-
$EndSCHEMATC
