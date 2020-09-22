EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 2 5
Title "POWER SUPPLY"
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L MP2307:MP2307 U2
U 1 1 5F5ACF72
P 6700 3600
F 0 "U2" H 7500 3500 60  0000 C CNN
F 1 "MP2307" H 7500 3400 60  0000 C CNN
F 2 "Kicad Library:MP2307" H 7500 3840 60  0001 C CNN
F 3 "" H 6700 3600 60  0000 C CNN
	1    6700 3600
	1    0    0    -1  
$EndComp
$Comp
L Device:C C5
U 1 1 5F5ADFEC
P 6000 3850
F 0 "C5" H 5800 3875 50  0000 L CNN
F 1 "100nF" H 5675 3800 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 6038 3700 50  0001 C CNN
F 3 "~" H 6000 3850 50  0001 C CNN
	1    6000 3850
	1    0    0    -1  
$EndComp
Wire Wire Line
	8375 3800 8300 3800
$Comp
L Device:C C6
U 1 1 5F5B160F
P 6550 3600
F 0 "C6" V 6350 3600 50  0000 C CNN
F 1 "100nF" V 6425 3600 50  0000 C CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 6588 3450 50  0001 C CNN
F 3 "~" H 6550 3600 50  0001 C CNN
	1    6550 3600
	0    1    1    0   
$EndComp
Wire Wire Line
	6400 3600 6400 3800
Wire Wire Line
	6400 3800 6700 3800
$Comp
L power:GND #PWR06
U 1 1 5F5B2B2E
P 6700 3900
F 0 "#PWR06" H 6700 3650 50  0001 C CNN
F 1 "GND" H 6700 3750 50  0000 C CNN
F 2 "" H 6700 3900 50  0001 C CNN
F 3 "" H 6700 3900 50  0001 C CNN
	1    6700 3900
	1    0    0    -1  
$EndComp
$Comp
L Device:R R2
U 1 1 5F5AFE6E
P 6600 4300
F 0 "R2" H 6500 4250 50  0000 C CNN
F 1 "100K" V 6600 4300 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 6530 4300 50  0001 C CNN
F 3 "~" H 6600 4300 50  0001 C CNN
	1    6600 4300
	-1   0    0    1   
$EndComp
$Comp
L pspice:INDUCTOR L1
U 1 1 5F5D8D7A
P 6400 3025
F 0 "L1" V 6450 3325 50  0000 R CNN
F 1 "10uH/4A" V 6350 3450 50  0000 R CNN
F 2 "Inductor_SMD:L_7.3x7.3_H3.5" H 6400 3025 50  0001 C CNN
F 3 "~" H 6400 3025 50  0001 C CNN
	1    6400 3025
	0    -1   -1   0   
$EndComp
Wire Wire Line
	6400 3275 6400 3600
Connection ~ 6400 3600
$Comp
L Device:C C4
U 1 1 5F5DCA48
P 5550 3850
F 0 "C4" H 5350 3875 50  0000 L CNN
F 1 "22uF" H 5275 3800 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 5588 3700 50  0001 C CNN
F 3 "~" H 5550 3850 50  0001 C CNN
	1    5550 3850
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR04
U 1 1 5F5B3842
P 5775 4250
F 0 "#PWR04" H 5775 4000 50  0001 C CNN
F 1 "GND" H 5775 4100 50  0000 C CNN
F 2 "" H 5775 4250 50  0001 C CNN
F 3 "" H 5775 4250 50  0001 C CNN
	1    5775 4250
	1    0    0    -1  
$EndComp
$Comp
L Device:C C7
U 1 1 5F5DE97F
P 6600 2925
F 0 "C7" H 6715 2971 50  0000 L CNN
F 1 "33uF" H 6715 2880 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 6638 2775 50  0001 C CNN
F 3 "~" H 6600 2925 50  0001 C CNN
	1    6600 2925
	1    0    0    -1  
$EndComp
$Comp
L Device:C C8
U 1 1 5F5DEC4E
P 7050 2925
F 0 "C8" H 7165 2971 50  0000 L CNN
F 1 "33uF" H 7165 2880 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 7088 2775 50  0001 C CNN
F 3 "~" H 7050 2925 50  0001 C CNN
	1    7050 2925
	1    0    0    -1  
$EndComp
$Comp
L Device:R R6
U 1 1 5F5B59D3
P 9025 4000
F 0 "R6" V 8925 4050 50  0000 R CNN
F 1 "10K" V 9025 4075 50  0000 R CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 8955 4000 50  0001 C CNN
F 3 "~" H 9025 4000 50  0001 C CNN
	1    9025 4000
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R5
U 1 1 5F5B5F51
P 8600 4150
F 0 "R5" H 8550 4100 50  0000 R CNN
F 1 "2K2" V 8600 4225 50  0000 R CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 8530 4150 50  0001 C CNN
F 3 "~" H 8600 4150 50  0001 C CNN
	1    8600 4150
	-1   0    0    1   
$EndComp
Wire Wire Line
	8300 4000 8600 4000
Connection ~ 8600 4000
$Comp
L power:GND #PWR09
U 1 1 5F5B7810
P 8600 4300
F 0 "#PWR09" H 8600 4050 50  0001 C CNN
F 1 "GND" H 8600 4150 50  0000 C CNN
F 2 "" H 8600 4300 50  0001 C CNN
F 3 "" H 8600 4300 50  0001 C CNN
	1    8600 4300
	1    0    0    -1  
$EndComp
Wire Wire Line
	7050 2775 6600 2775
Wire Wire Line
	6600 3075 6825 3075
$Comp
L power:GND #PWR07
U 1 1 5F5E6F9A
P 6825 3075
F 0 "#PWR07" H 6825 2825 50  0001 C CNN
F 1 "GND" H 6825 2925 50  0000 C CNN
F 2 "" H 6825 3075 50  0001 C CNN
F 3 "" H 6825 3075 50  0001 C CNN
	1    6825 3075
	1    0    0    -1  
$EndComp
Connection ~ 6825 3075
Wire Wire Line
	6825 3075 7050 3075
Text Label 7175 2775 0    50   ~ 0
5V
Wire Wire Line
	7175 2775 7050 2775
Connection ~ 7050 2775
Wire Wire Line
	8600 4000 8875 4000
$Comp
L Device:R R3
U 1 1 5F5EA2E6
P 6600 4600
F 0 "R3" H 6500 4550 50  0000 C CNN
F 1 "33K" V 6600 4600 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 6530 4600 50  0001 C CNN
F 3 "~" H 6600 4600 50  0001 C CNN
	1    6600 4600
	-1   0    0    1   
$EndComp
Text Notes 6875 4800 0    50   ~ 0
Otomatis shutdown bila:\nIN < 10.1V atau EN < 2.5V\nGanti R3 utk mengatur nilai\ntegangan shutdown
$Comp
L power:GND #PWR08
U 1 1 5F5EB0DA
P 8300 3400
F 0 "#PWR08" H 8300 3150 50  0001 C CNN
F 1 "GND" V 8300 3225 50  0000 C CNN
F 2 "" H 8300 3400 50  0001 C CNN
F 3 "" H 8300 3400 50  0001 C CNN
	1    8300 3400
	-1   0    0    1   
$EndComp
$Comp
L Device:C C9
U 1 1 5F5EB8CE
P 8525 3550
F 0 "C9" H 8375 3500 50  0000 C CNN
F 1 "100nF" H 8300 3575 50  0000 C CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 8563 3400 50  0001 C CNN
F 3 "~" H 8525 3550 50  0001 C CNN
	1    8525 3550
	-1   0    0    1   
$EndComp
$Comp
L Device:R R4
U 1 1 5F5ED02C
P 8600 3900
F 0 "R4" V 8525 3950 50  0000 R CNN
F 1 "6K8" V 8600 3975 50  0000 R CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 8530 3900 50  0001 C CNN
F 3 "~" H 8600 3900 50  0001 C CNN
	1    8600 3900
	0    1    1    0   
$EndComp
Wire Wire Line
	6600 4150 6600 3700
Connection ~ 6600 3700
Wire Wire Line
	6600 3700 6700 3700
Wire Wire Line
	6600 4450 8375 4450
Wire Wire Line
	8375 3800 8375 4450
Connection ~ 6600 4450
$Comp
L Device:D_Schottky_ALT D3
U 1 1 5F5F1FBD
P 6400 3950
F 0 "D3" V 6425 3775 50  0000 L CNN
F 1 "SS54" V 6500 3700 50  0000 L CNN
F 2 "Diode_SMD:D_SMA" H 6400 3950 50  0001 C CNN
F 3 "~" H 6400 3950 50  0001 C CNN
	1    6400 3950
	0    1    1    0   
$EndComp
$Comp
L Device:C C10
U 1 1 5F5F536F
P 8925 3750
F 0 "C10" H 8775 3725 50  0000 C CNN
F 1 "3.9nF" H 8725 3800 50  0000 C CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 8963 3600 50  0001 C CNN
F 3 "~" H 8925 3750 50  0001 C CNN
	1    8925 3750
	-1   0    0    1   
$EndComp
Wire Wire Line
	8300 3900 8450 3900
Wire Wire Line
	8750 3900 8925 3900
Wire Wire Line
	8300 3700 8525 3700
Wire Wire Line
	8525 3400 8925 3400
Wire Wire Line
	8925 3400 8925 3600
Wire Wire Line
	8300 3600 8300 3400
Wire Wire Line
	8525 3400 8300 3400
Connection ~ 8525 3400
Connection ~ 8300 3400
Wire Wire Line
	9175 4000 9300 4000
Wire Wire Line
	6400 2775 6600 2775
Connection ~ 6600 2775
$Comp
L power:GND #PWR05
U 1 1 5F5EE350
P 6600 4750
F 0 "#PWR05" H 6600 4500 50  0001 C CNN
F 1 "GND" H 6600 4600 50  0000 C CNN
F 2 "" H 6600 4750 50  0001 C CNN
F 3 "" H 6600 4750 50  0001 C CNN
	1    6600 4750
	1    0    0    -1  
$EndComp
Text Label 4575 3700 0    50   ~ 0
12V
$Comp
L power:GND #PWR01
U 1 1 5F621368
P 3450 3700
F 0 "#PWR01" H 3450 3450 50  0001 C CNN
F 1 "GND" H 3450 3550 50  0000 C CNN
F 2 "" H 3450 3700 50  0001 C CNN
F 3 "" H 3450 3700 50  0001 C CNN
	1    3450 3700
	1    0    0    -1  
$EndComp
Wire Wire Line
	5125 3700 5550 3700
Connection ~ 5550 3700
Wire Wire Line
	5550 3700 6000 3700
Connection ~ 6000 3700
Wire Wire Line
	6000 3700 6600 3700
Wire Wire Line
	5125 4000 5125 4250
Wire Wire Line
	5550 4000 5550 4250
Connection ~ 5550 4250
Wire Wire Line
	5550 4250 5775 4250
Wire Wire Line
	6000 4000 6000 4250
Connection ~ 6000 4250
Wire Wire Line
	6000 4250 6400 4250
Connection ~ 5775 4250
Wire Wire Line
	5775 4250 6000 4250
Wire Wire Line
	5125 4250 5550 4250
Connection ~ 6400 3800
Wire Wire Line
	6400 4250 6400 4100
Wire Wire Line
	3450 3600 3600 3600
Text Notes 4000 4100 0    50   ~ 0
3A Fuse Trace:\n1.4mm width\n1oz thickness
Wire Notes Line
	5325 4525 3225 4525
Wire Notes Line
	5325 5375 5325 4525
Wire Notes Line
	3225 5375 5325 5375
Wire Notes Line
	3225 4525 3225 5375
Text Label 5125 4875 0    50   ~ 0
3.3V
Connection ~ 4900 4875
Wire Wire Line
	4900 4875 5125 4875
Wire Wire Line
	3425 4875 3350 4875
$Comp
L power:GND #PWR02
U 1 1 5F60CECA
P 4450 5175
F 0 "#PWR02" H 4450 4925 50  0001 C CNN
F 1 "GND" H 4450 5025 50  0000 C CNN
F 2 "" H 4450 5175 50  0001 C CNN
F 3 "" H 4450 5175 50  0001 C CNN
	1    4450 5175
	1    0    0    -1  
$EndComp
Wire Wire Line
	4450 5175 4900 5175
Connection ~ 4450 5175
Wire Wire Line
	3850 5175 4450 5175
Wire Wire Line
	4750 4875 4900 4875
$Comp
L Device:C C2
U 1 1 5F60AC0D
P 4900 5025
F 0 "C2" H 5015 5071 50  0000 L CNN
F 1 "22uF" H 5015 4980 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 4938 4875 50  0001 C CNN
F 3 "~" H 4900 5025 50  0001 C CNN
	1    4900 5025
	1    0    0    -1  
$EndComp
$Comp
L Device:Ferrite_Bead FB1
U 1 1 5F609984
P 3575 4875
F 0 "FB1" V 3301 4875 50  0000 C CNN
F 1 "1A" V 3392 4875 50  0000 C CNN
F 2 "Inductor_SMD:L_0805_2012Metric" V 3505 4875 50  0001 C CNN
F 3 "~" H 3575 4875 50  0001 C CNN
	1    3575 4875
	0    1    1    0   
$EndComp
Connection ~ 3850 4875
Wire Wire Line
	3725 4875 3850 4875
Wire Wire Line
	3850 4875 4150 4875
$Comp
L Device:C C1
U 1 1 5F607013
P 3850 5025
F 0 "C1" H 3965 5071 50  0000 L CNN
F 1 "100nF" H 3965 4980 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 3888 4875 50  0001 C CNN
F 3 "~" H 3850 5025 50  0001 C CNN
	1    3850 5025
	1    0    0    -1  
$EndComp
$Comp
L Regulator_Linear:LD1117S33TR_SOT223 U1
U 1 1 5F605D15
P 4450 4875
F 0 "U1" H 4450 5117 50  0000 C CNN
F 1 "LD1117S33TR" H 4450 5026 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-223-3_TabPin2" H 4450 5075 50  0001 C CNN
F 3 "http://www.st.com/st-web-ui/static/active/en/resource/technical/document/datasheet/CD00000544.pdf" H 4550 4625 50  0001 C CNN
	1    4450 4875
	1    0    0    -1  
$EndComp
Wire Wire Line
	4000 3700 4075 3700
Wire Wire Line
	4075 3700 4075 3825
Wire Wire Line
	4075 3825 4150 3825
Wire Wire Line
	4150 3825 4150 3575
Wire Wire Line
	4150 3575 4225 3575
Wire Wire Line
	4225 3575 4225 3825
Wire Wire Line
	4225 3825 4300 3825
Wire Wire Line
	4300 3825 4300 3575
Wire Wire Line
	4300 3575 4375 3575
Wire Wire Line
	4375 3575 4375 3825
Wire Wire Line
	4375 3825 4450 3825
Wire Wire Line
	4450 3825 4450 3700
Wire Wire Line
	4450 3700 4575 3700
$Comp
L Connector_Generic:Conn_01x02 J1
U 1 1 5F61FDC3
P 3250 3700
F 0 "J1" H 3168 3375 50  0000 C CNN
F 1 "POWER" H 3168 3466 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 3250 3700 50  0001 C CNN
F 3 "~" H 3250 3700 50  0001 C CNN
	1    3250 3700
	-1   0    0    1   
$EndComp
Text Label 3350 4875 2    50   ~ 0
5V
Text Label 9300 4000 0    50   ~ 0
5V
Text HLabel 6025 5175 2    50   Output ~ 0
3.3V
Text HLabel 6025 5050 2    50   UnSpc ~ 0
5V
Text HLabel 6025 4925 2    50   Output ~ 0
12V
Wire Wire Line
	5875 5175 6025 5175
Wire Wire Line
	5875 5050 6025 5050
Wire Wire Line
	5875 4925 6025 4925
Text Label 5875 4925 2    50   ~ 0
12V
Text Label 5875 5175 2    50   ~ 0
3.3V
Text Label 5875 5050 2    50   ~ 0
5V
Wire Notes Line
	6275 4825 5650 4825
Wire Notes Line
	6275 5250 6275 4825
Wire Notes Line
	5650 4825 5650 5250
Wire Notes Line
	5650 5250 6275 5250
$Comp
L Device:C C3
U 1 1 5F5DCE64
P 5125 3850
F 0 "C3" H 4925 3875 50  0000 L CNN
F 1 "22uF" H 4850 3800 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 5163 3700 50  0001 C CNN
F 3 "~" H 5125 3850 50  0001 C CNN
	1    5125 3850
	1    0    0    -1  
$EndComp
$Comp
L Transistor_FET:AO3401A QM?
U 1 1 5F686A99
P 5200 2425
AR Path="/5F60FE64/5F686A99" Ref="QM?"  Part="1" 
AR Path="/5F592C3C/5F686A99" Ref="Q1"  Part="1" 
F 0 "Q1" V 5500 2425 50  0000 C CNN
F 1 "AO3401" V 5425 2425 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 5400 2350 50  0001 L CIN
F 3 "http://www.aosmd.com/pdfs/datasheet/AO3401A.pdf" H 5200 2425 50  0001 L CNN
	1    5200 2425
	0    -1   -1   0   
$EndComp
$Comp
L Device:R RM?
U 1 1 5F686AA0
P 5200 2775
AR Path="/5F60FE64/5F686AA0" Ref="RM?"  Part="1" 
AR Path="/5F592C3C/5F686AA0" Ref="R1"  Part="1" 
F 0 "R1" V 5100 2775 50  0000 C CNN
F 1 "10K" V 5200 2775 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 5130 2775 50  0001 C CNN
F 3 "~" H 5200 2775 50  0001 C CNN
	1    5200 2775
	-1   0    0    1   
$EndComp
$Comp
L Device:D_Zener_ALT DM?
U 1 1 5F686AA6
P 5475 2475
AR Path="/5F60FE64/5F686AA6" Ref="DM?"  Part="1" 
AR Path="/5F592C3C/5F686AA6" Ref="D2"  Part="1" 
F 0 "D2" V 5429 2554 50  0000 L CNN
F 1 "5.1V" V 5520 2554 50  0000 L CNN
F 2 "Diode_SMD:D_SOD-123" H 5475 2475 50  0001 C CNN
F 3 "~" H 5475 2475 50  0001 C CNN
	1    5475 2475
	0    1    1    0   
$EndComp
Wire Wire Line
	5475 2625 5200 2625
Connection ~ 5200 2625
Wire Wire Line
	5400 2325 5475 2325
Text Label 5725 2325 0    50   ~ 0
Vin
$Comp
L power:GND #PWR?
U 1 1 5F686AB0
P 5200 2925
AR Path="/5F60FE64/5F686AB0" Ref="#PWR?"  Part="1" 
AR Path="/5F592C3C/5F686AB0" Ref="#PWR03"  Part="1" 
F 0 "#PWR03" H 5200 2675 50  0001 C CNN
F 1 "GND" H 5200 2775 50  0000 C CNN
F 2 "" H 5200 2925 50  0001 C CNN
F 3 "" H 5200 2925 50  0001 C CNN
	1    5200 2925
	1    0    0    -1  
$EndComp
Wire Notes Line
	3950 3125 3950 2075
Text Notes 3975 2175 0    50   ~ 10
A
Text Notes 4725 2175 0    50   ~ 10
B
Text Notes 3975 2050 0    50   ~ 0
Reverse polarity protection, choose one: A or B
Wire Wire Line
	5725 2325 5475 2325
Connection ~ 5475 2325
Wire Notes Line
	5850 2075 5850 3125
Wire Notes Line
	5850 3125 3950 3125
Wire Notes Line
	3950 2075 5850 2075
$Comp
L Device:D_Schottky_ALT D1
U 1 1 5F68F386
P 4325 2725
F 0 "D1" H 4325 2509 50  0000 C CNN
F 1 "SS34" H 4325 2600 50  0000 C CNN
F 2 "Diode_SMD:D_SMA" H 4325 2725 50  0001 C CNN
F 3 "~" H 4325 2725 50  0001 C CNN
	1    4325 2725
	-1   0    0    1   
$EndComp
Text Label 4175 2725 2    50   ~ 0
12V
Text Label 4475 2725 0    50   ~ 0
Vin
Text Label 5125 3700 2    50   ~ 0
Vin
Text Label 5000 2325 2    50   ~ 0
12V
Wire Notes Line
	4850 3650 4850 3425
Wire Notes Line
	4850 3425 4700 3425
Wire Notes Line
	4700 2075 4700 3425
$Comp
L Switch:SW_SPDT S1
U 1 1 5F6168FF
P 3800 3600
F 0 "S1" H 3800 3885 50  0000 C CNN
F 1 "ON-OFF" H 3800 3794 50  0000 C CNN
F 2 "Kicad Library:switch_slide_2.54" H 3800 3600 50  0001 C CNN
F 3 "~" H 3800 3600 50  0001 C CNN
	1    3800 3600
	1    0    0    -1  
$EndComp
$EndSCHEMATC
