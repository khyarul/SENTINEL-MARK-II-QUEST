EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 4 6
Title "Motor Driver + Extinguisher"
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L BTS7960:BTS7960B UM2
U 1 1 5F6105F5
P 4975 3450
F 0 "UM2" H 5475 3715 50  0000 C CNN
F 1 "BTS7960B" H 5475 3624 50  0000 C CNN
F 2 "Kicad Library:Infineon-BTS7960B-Level_A" H 4975 3850 50  0001 L CNN
F 3 "http://www.infineon.com/dgdl/BTS7960_Datasheet.pdf?folderId=db3a304412b407950112b408e8c90004&fileId=db3a304412b407950112b43945006d5d&location=en.Products.Automotive_ICs.Motor_Drivers__Automotive_.Integrated_High_Current_Motor_Drivers__NovalithIC____Trilith" H 4975 3950 50  0001 L CNN
F 4 "Manufacturer URL" H 4975 4050 50  0001 L CNN "Component Link 1 Description"
F 5 "http://www.infineon.com/" H 4975 4150 50  0001 L CNN "Component Link 1 URL"
F 6 "Package Specification" H 4975 4250 50  0001 L CNN "Component Link 3 Description"
F 7 "http://www.infineon.com/dgdl/BTS7970B_Datasheet.pdf?folderId=db3a304412b407950112b408e8c90004&fileId=db3a304412b407950112b43949b36d61&sId=db3a30433d68e984013d7db637dc5e6a" H 4975 4350 50  0001 L CNN "Component Link 3 URL"
F 8 "Rev. 1.1" H 4975 4450 50  0001 L CNN "Datasheet Version"
F 9 "false" H 4975 4550 50  0001 L CNN "Green"
F 10 "false" H 4975 4650 50  0001 L CNN "Halogen free"
F 11 "7 uA" H 4975 4750 50  0001 L CNN "Iq typ"
F 12 "Surface Mount" H 4975 4850 50  0001 L CNN "Mounting Technology"
F 13 "7-Pin Plastic Transistor Single Outline Package, 9.9 x 9.2 mm Body, 1.27 mm Pitch" H 4975 4950 50  0001 L CNN "Package Description"
F 14 "May-06" H 4975 5050 50  0001 L CNN "Package Version"
F 15 "IC" H 4975 5150 50  0001 L CNN "category"
F 16 "1433991" H 4975 5250 50  0001 L CNN "ciiva ids"
F 17 "2d41aec1d0b54c2a" H 4975 5350 50  0001 L CNN "library id"
F 18 "Infineon" H 4975 5450 50  0001 L CNN "manufacturer"
F 19 "P-TO-263-7-6" H 4975 5550 50  0001 L CNN "package"
F 20 "1409251876" H 4975 5650 50  0001 L CNN "release date"
F 21 "0F038138-080F-44BA-A129-3EB9BCBF95C1" H 4975 5750 50  0001 L CNN "vault revision"
F 22 "yes" H 4975 5850 50  0001 L CNN "imported"
	1    4975 3450
	-1   0    0    -1  
$EndComp
$Comp
L Device:R RM7
U 1 1 5F6135FA
P 5025 3650
F 0 "RM7" V 4925 3650 50  0000 C CNN
F 1 "10K" V 5025 3650 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 4955 3650 50  0001 C CNN
F 3 "~" H 5025 3650 50  0001 C CNN
	1    5025 3650
	0    -1   1    0   
$EndComp
Wire Wire Line
	4075 3450 4075 3550
$Comp
L Device:C CM2
U 1 1 5F614ED8
P 4875 4325
F 0 "CM2" H 4760 4371 50  0000 R CNN
F 1 "470nF" H 4760 4280 50  0000 R CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 4913 4175 50  0001 C CNN
F 3 "~" H 4875 4325 50  0001 C CNN
	1    4875 4325
	-1   0    0    -1  
$EndComp
Wire Wire Line
	4875 4050 4875 4175
$Comp
L power:GND #PWR0103
U 1 1 5F618142
P 4075 4050
F 0 "#PWR0103" H 4075 3800 50  0001 C CNN
F 1 "GND" H 4080 3877 50  0000 C CNN
F 2 "" H 4075 4050 50  0001 C CNN
F 3 "" H 4075 4050 50  0001 C CNN
	1    4075 4050
	-1   0    0    -1  
$EndComp
$Comp
L power:GND #PWR0104
U 1 1 5F619240
P 4875 4475
F 0 "#PWR0104" H 4875 4225 50  0001 C CNN
F 1 "GND" H 4880 4302 50  0000 C CNN
F 2 "" H 4875 4475 50  0001 C CNN
F 3 "" H 4875 4475 50  0001 C CNN
	1    4875 4475
	-1   0    0    -1  
$EndComp
$Comp
L Device:R RM8
U 1 1 5F61A127
P 5025 3850
F 0 "RM8" V 4925 3850 50  0000 C CNN
F 1 "SR" V 5025 3850 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 4955 3850 50  0001 C CNN
F 3 "~" H 5025 3850 50  0001 C CNN
	1    5025 3850
	0    -1   1    0   
$EndComp
$Comp
L power:GND #PWR0105
U 1 1 5F61BE6E
P 5175 3850
F 0 "#PWR0105" H 5175 3600 50  0001 C CNN
F 1 "GND" V 5180 3722 50  0000 R CNN
F 2 "" H 5175 3850 50  0001 C CNN
F 3 "" H 5175 3850 50  0001 C CNN
	1    5175 3850
	0    -1   1    0   
$EndComp
NoConn ~ 4075 3850
$Comp
L BTS7960:BTS7960B UM1
U 1 1 5F6218D6
P 2775 3450
F 0 "UM1" H 3275 3715 50  0000 C CNN
F 1 "BTS7960B" H 3275 3624 50  0000 C CNN
F 2 "Kicad Library:Infineon-BTS7960B-Level_A" H 2775 3850 50  0001 L CNN
F 3 "http://www.infineon.com/dgdl/BTS7960_Datasheet.pdf?folderId=db3a304412b407950112b408e8c90004&fileId=db3a304412b407950112b43945006d5d&location=en.Products.Automotive_ICs.Motor_Drivers__Automotive_.Integrated_High_Current_Motor_Drivers__NovalithIC____Trilith" H 2775 3950 50  0001 L CNN
F 4 "Manufacturer URL" H 2775 4050 50  0001 L CNN "Component Link 1 Description"
F 5 "http://www.infineon.com/" H 2775 4150 50  0001 L CNN "Component Link 1 URL"
F 6 "Package Specification" H 2775 4250 50  0001 L CNN "Component Link 3 Description"
F 7 "http://www.infineon.com/dgdl/BTS7970B_Datasheet.pdf?folderId=db3a304412b407950112b408e8c90004&fileId=db3a304412b407950112b43949b36d61&sId=db3a30433d68e984013d7db637dc5e6a" H 2775 4350 50  0001 L CNN "Component Link 3 URL"
F 8 "Rev. 1.1" H 2775 4450 50  0001 L CNN "Datasheet Version"
F 9 "false" H 2775 4550 50  0001 L CNN "Green"
F 10 "false" H 2775 4650 50  0001 L CNN "Halogen free"
F 11 "7 uA" H 2775 4750 50  0001 L CNN "Iq typ"
F 12 "Surface Mount" H 2775 4850 50  0001 L CNN "Mounting Technology"
F 13 "7-Pin Plastic Transistor Single Outline Package, 9.9 x 9.2 mm Body, 1.27 mm Pitch" H 2775 4950 50  0001 L CNN "Package Description"
F 14 "May-06" H 2775 5050 50  0001 L CNN "Package Version"
F 15 "IC" H 2775 5150 50  0001 L CNN "category"
F 16 "1433991" H 2775 5250 50  0001 L CNN "ciiva ids"
F 17 "2d41aec1d0b54c2a" H 2775 5350 50  0001 L CNN "library id"
F 18 "Infineon" H 2775 5450 50  0001 L CNN "manufacturer"
F 19 "P-TO-263-7-6" H 2775 5550 50  0001 L CNN "package"
F 20 "1409251876" H 2775 5650 50  0001 L CNN "release date"
F 21 "0F038138-080F-44BA-A129-3EB9BCBF95C1" H 2775 5750 50  0001 L CNN "vault revision"
F 22 "yes" H 2775 5850 50  0001 L CNN "imported"
	1    2775 3450
	1    0    0    -1  
$EndComp
$Comp
L Device:R RM2
U 1 1 5F6218E2
P 2725 3650
F 0 "RM2" V 2625 3650 50  0000 C CNN
F 1 "10K" V 2725 3650 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 2655 3650 50  0001 C CNN
F 3 "~" H 2725 3650 50  0001 C CNN
	1    2725 3650
	0    1    1    0   
$EndComp
Wire Wire Line
	3675 3450 3675 3550
$Comp
L Device:C CM1
U 1 1 5F6218E9
P 2875 4325
F 0 "CM1" H 2990 4371 50  0000 L CNN
F 1 "470nF" H 2990 4280 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 2913 4175 50  0001 C CNN
F 3 "~" H 2875 4325 50  0001 C CNN
	1    2875 4325
	1    0    0    -1  
$EndComp
Wire Wire Line
	2875 4050 2875 4175
$Comp
L power:GND #PWR0106
U 1 1 5F6218F0
P 3675 4050
F 0 "#PWR0106" H 3675 3800 50  0001 C CNN
F 1 "GND" H 3680 3877 50  0000 C CNN
F 2 "" H 3675 4050 50  0001 C CNN
F 3 "" H 3675 4050 50  0001 C CNN
	1    3675 4050
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0107
U 1 1 5F6218F6
P 2875 4475
F 0 "#PWR0107" H 2875 4225 50  0001 C CNN
F 1 "GND" H 2880 4302 50  0000 C CNN
F 2 "" H 2875 4475 50  0001 C CNN
F 3 "" H 2875 4475 50  0001 C CNN
	1    2875 4475
	1    0    0    -1  
$EndComp
$Comp
L Device:R RM3
U 1 1 5F6218FC
P 2725 3850
F 0 "RM3" V 2625 3850 50  0000 C CNN
F 1 "SR" V 2725 3850 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 2655 3850 50  0001 C CNN
F 3 "~" H 2725 3850 50  0001 C CNN
	1    2725 3850
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0108
U 1 1 5F621902
P 2575 3850
F 0 "#PWR0108" H 2575 3600 50  0001 C CNN
F 1 "GND" V 2580 3722 50  0000 R CNN
F 2 "" H 2575 3850 50  0001 C CNN
F 3 "" H 2575 3850 50  0001 C CNN
	1    2575 3850
	0    1    1    0   
$EndComp
NoConn ~ 3675 3850
Text HLabel 5250 1675 0    50   Input ~ 0
12V
$Comp
L Device:D_Schottky_ALT DM3
U 1 1 5F626E2B
P 5400 1675
F 0 "DM3" H 5400 1500 50  0000 C CNN
F 1 "SS34" H 5400 1575 50  0000 C CNN
F 2 "Diode_SMD:D_SMA" H 5400 1675 50  0001 C CNN
F 3 "~" H 5400 1675 50  0001 C CNN
	1    5400 1675
	-1   0    0    1   
$EndComp
Text Label 2800 4050 2    50   ~ 0
VS
Text Label 4950 4050 0    50   ~ 0
VS
Wire Wire Line
	3825 3450 3675 3450
Connection ~ 3675 3450
Wire Wire Line
	3925 3450 4075 3450
Connection ~ 4075 3450
$Comp
L BTS7960:BTS7960B UM4
U 1 1 5F646082
P 8225 3450
F 0 "UM4" H 8725 3715 50  0000 C CNN
F 1 "BTS7960B" H 8725 3624 50  0000 C CNN
F 2 "Kicad Library:Infineon-BTS7960B-Level_A" H 8225 3850 50  0001 L CNN
F 3 "http://www.infineon.com/dgdl/BTS7960_Datasheet.pdf?folderId=db3a304412b407950112b408e8c90004&fileId=db3a304412b407950112b43945006d5d&location=en.Products.Automotive_ICs.Motor_Drivers__Automotive_.Integrated_High_Current_Motor_Drivers__NovalithIC____Trilith" H 8225 3950 50  0001 L CNN
F 4 "Manufacturer URL" H 8225 4050 50  0001 L CNN "Component Link 1 Description"
F 5 "http://www.infineon.com/" H 8225 4150 50  0001 L CNN "Component Link 1 URL"
F 6 "Package Specification" H 8225 4250 50  0001 L CNN "Component Link 3 Description"
F 7 "http://www.infineon.com/dgdl/BTS7970B_Datasheet.pdf?folderId=db3a304412b407950112b408e8c90004&fileId=db3a304412b407950112b43949b36d61&sId=db3a30433d68e984013d7db637dc5e6a" H 8225 4350 50  0001 L CNN "Component Link 3 URL"
F 8 "Rev. 1.1" H 8225 4450 50  0001 L CNN "Datasheet Version"
F 9 "false" H 8225 4550 50  0001 L CNN "Green"
F 10 "false" H 8225 4650 50  0001 L CNN "Halogen free"
F 11 "7 uA" H 8225 4750 50  0001 L CNN "Iq typ"
F 12 "Surface Mount" H 8225 4850 50  0001 L CNN "Mounting Technology"
F 13 "7-Pin Plastic Transistor Single Outline Package, 9.9 x 9.2 mm Body, 1.27 mm Pitch" H 8225 4950 50  0001 L CNN "Package Description"
F 14 "May-06" H 8225 5050 50  0001 L CNN "Package Version"
F 15 "IC" H 8225 5150 50  0001 L CNN "category"
F 16 "1433991" H 8225 5250 50  0001 L CNN "ciiva ids"
F 17 "2d41aec1d0b54c2a" H 8225 5350 50  0001 L CNN "library id"
F 18 "Infineon" H 8225 5450 50  0001 L CNN "manufacturer"
F 19 "P-TO-263-7-6" H 8225 5550 50  0001 L CNN "package"
F 20 "1409251876" H 8225 5650 50  0001 L CNN "release date"
F 21 "0F038138-080F-44BA-A129-3EB9BCBF95C1" H 8225 5750 50  0001 L CNN "vault revision"
F 22 "yes" H 8225 5850 50  0001 L CNN "imported"
	1    8225 3450
	-1   0    0    -1  
$EndComp
$Comp
L Device:R RM14
U 1 1 5F64608E
P 8275 3650
F 0 "RM14" V 8175 3650 50  0000 C CNN
F 1 "10K" V 8275 3650 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 8205 3650 50  0001 C CNN
F 3 "~" H 8275 3650 50  0001 C CNN
	1    8275 3650
	0    -1   1    0   
$EndComp
Wire Wire Line
	7325 3450 7325 3550
$Comp
L Device:C CM5
U 1 1 5F646095
P 8125 4325
F 0 "CM5" H 8010 4371 50  0000 R CNN
F 1 "470nF" H 8010 4280 50  0000 R CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 8163 4175 50  0001 C CNN
F 3 "~" H 8125 4325 50  0001 C CNN
	1    8125 4325
	-1   0    0    -1  
$EndComp
Wire Wire Line
	8125 4050 8125 4175
$Comp
L power:GND #PWR015
U 1 1 5F64609C
P 7325 4050
F 0 "#PWR015" H 7325 3800 50  0001 C CNN
F 1 "GND" H 7330 3877 50  0000 C CNN
F 2 "" H 7325 4050 50  0001 C CNN
F 3 "" H 7325 4050 50  0001 C CNN
	1    7325 4050
	-1   0    0    -1  
$EndComp
$Comp
L power:GND #PWR016
U 1 1 5F6460A2
P 8125 4475
F 0 "#PWR016" H 8125 4225 50  0001 C CNN
F 1 "GND" H 8130 4302 50  0000 C CNN
F 2 "" H 8125 4475 50  0001 C CNN
F 3 "" H 8125 4475 50  0001 C CNN
	1    8125 4475
	-1   0    0    -1  
$EndComp
$Comp
L Device:R RM15
U 1 1 5F6460A8
P 8275 3850
F 0 "RM15" V 8175 3850 50  0000 C CNN
F 1 "SR" V 8275 3850 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 8205 3850 50  0001 C CNN
F 3 "~" H 8275 3850 50  0001 C CNN
	1    8275 3850
	0    -1   1    0   
$EndComp
$Comp
L power:GND #PWR017
U 1 1 5F6460AE
P 8425 3850
F 0 "#PWR017" H 8425 3600 50  0001 C CNN
F 1 "GND" V 8430 3722 50  0000 R CNN
F 2 "" H 8425 3850 50  0001 C CNN
F 3 "" H 8425 3850 50  0001 C CNN
	1    8425 3850
	0    -1   1    0   
$EndComp
NoConn ~ 7325 3850
$Comp
L BTS7960:BTS7960B UM3
U 1 1 5F6460C8
P 6025 3450
F 0 "UM3" H 6525 3715 50  0000 C CNN
F 1 "BTS7960B" H 6525 3624 50  0000 C CNN
F 2 "Kicad Library:Infineon-BTS7960B-Level_A" H 6025 3850 50  0001 L CNN
F 3 "http://www.infineon.com/dgdl/BTS7960_Datasheet.pdf?folderId=db3a304412b407950112b408e8c90004&fileId=db3a304412b407950112b43945006d5d&location=en.Products.Automotive_ICs.Motor_Drivers__Automotive_.Integrated_High_Current_Motor_Drivers__NovalithIC____Trilith" H 6025 3950 50  0001 L CNN
F 4 "Manufacturer URL" H 6025 4050 50  0001 L CNN "Component Link 1 Description"
F 5 "http://www.infineon.com/" H 6025 4150 50  0001 L CNN "Component Link 1 URL"
F 6 "Package Specification" H 6025 4250 50  0001 L CNN "Component Link 3 Description"
F 7 "http://www.infineon.com/dgdl/BTS7970B_Datasheet.pdf?folderId=db3a304412b407950112b408e8c90004&fileId=db3a304412b407950112b43949b36d61&sId=db3a30433d68e984013d7db637dc5e6a" H 6025 4350 50  0001 L CNN "Component Link 3 URL"
F 8 "Rev. 1.1" H 6025 4450 50  0001 L CNN "Datasheet Version"
F 9 "false" H 6025 4550 50  0001 L CNN "Green"
F 10 "false" H 6025 4650 50  0001 L CNN "Halogen free"
F 11 "7 uA" H 6025 4750 50  0001 L CNN "Iq typ"
F 12 "Surface Mount" H 6025 4850 50  0001 L CNN "Mounting Technology"
F 13 "7-Pin Plastic Transistor Single Outline Package, 9.9 x 9.2 mm Body, 1.27 mm Pitch" H 6025 4950 50  0001 L CNN "Package Description"
F 14 "May-06" H 6025 5050 50  0001 L CNN "Package Version"
F 15 "IC" H 6025 5150 50  0001 L CNN "category"
F 16 "1433991" H 6025 5250 50  0001 L CNN "ciiva ids"
F 17 "2d41aec1d0b54c2a" H 6025 5350 50  0001 L CNN "library id"
F 18 "Infineon" H 6025 5450 50  0001 L CNN "manufacturer"
F 19 "P-TO-263-7-6" H 6025 5550 50  0001 L CNN "package"
F 20 "1409251876" H 6025 5650 50  0001 L CNN "release date"
F 21 "0F038138-080F-44BA-A129-3EB9BCBF95C1" H 6025 5750 50  0001 L CNN "vault revision"
F 22 "yes" H 6025 5850 50  0001 L CNN "imported"
	1    6025 3450
	1    0    0    -1  
$EndComp
$Comp
L Device:R RM11
U 1 1 5F6460D4
P 5975 3650
F 0 "RM11" V 5875 3650 50  0000 C CNN
F 1 "10K" V 5975 3650 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 5905 3650 50  0001 C CNN
F 3 "~" H 5975 3650 50  0001 C CNN
	1    5975 3650
	0    1    1    0   
$EndComp
Wire Wire Line
	6925 3450 6925 3550
$Comp
L Device:C CM3
U 1 1 5F6460DB
P 6125 4325
F 0 "CM3" H 6240 4371 50  0000 L CNN
F 1 "470nF" H 6240 4280 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 6163 4175 50  0001 C CNN
F 3 "~" H 6125 4325 50  0001 C CNN
	1    6125 4325
	1    0    0    -1  
$EndComp
Wire Wire Line
	6125 4050 6125 4175
$Comp
L power:GND #PWR013
U 1 1 5F6460E2
P 6925 4050
F 0 "#PWR013" H 6925 3800 50  0001 C CNN
F 1 "GND" H 6930 3877 50  0000 C CNN
F 2 "" H 6925 4050 50  0001 C CNN
F 3 "" H 6925 4050 50  0001 C CNN
	1    6925 4050
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR011
U 1 1 5F6460E8
P 6125 4475
F 0 "#PWR011" H 6125 4225 50  0001 C CNN
F 1 "GND" H 6130 4302 50  0000 C CNN
F 2 "" H 6125 4475 50  0001 C CNN
F 3 "" H 6125 4475 50  0001 C CNN
	1    6125 4475
	1    0    0    -1  
$EndComp
$Comp
L Device:R RM12
U 1 1 5F6460EE
P 5975 3850
F 0 "RM12" V 5875 3850 50  0000 C CNN
F 1 "SR" V 5975 3850 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 5905 3850 50  0001 C CNN
F 3 "~" H 5975 3850 50  0001 C CNN
	1    5975 3850
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0109
U 1 1 5F6460F4
P 5825 3850
F 0 "#PWR0109" H 5825 3600 50  0001 C CNN
F 1 "GND" V 5830 3722 50  0000 R CNN
F 2 "" H 5825 3850 50  0001 C CNN
F 3 "" H 5825 3850 50  0001 C CNN
	1    5825 3850
	0    1    1    0   
$EndComp
NoConn ~ 6925 3850
Text Label 6050 4050 2    50   ~ 0
VS
Text Label 8200 4050 0    50   ~ 0
VS
Wire Wire Line
	7075 3450 6925 3450
Connection ~ 6925 3450
Connection ~ 7325 3450
$Comp
L Device:CP CM4
U 1 1 5F66120F
P 5625 1825
F 0 "CM4" H 5740 1871 50  0000 L CNN
F 1 "100uF" H 5740 1780 50  0000 L CNN
F 2 "Capacitor_SMD:CP_Elec_6.3x7.7" H 5663 1675 50  0001 C CNN
F 3 "~" H 5625 1825 50  0001 C CNN
	1    5625 1825
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR012
U 1 1 5F661B8F
P 5625 1975
F 0 "#PWR012" H 5625 1725 50  0001 C CNN
F 1 "GND" H 5625 1825 50  0000 C CNN
F 2 "" H 5625 1975 50  0001 C CNN
F 3 "" H 5625 1975 50  0001 C CNN
	1    5625 1975
	1    0    0    -1  
$EndComp
Text Label 5700 1675 0    50   ~ 0
VS
Wire Wire Line
	5700 1675 5625 1675
Text Label 2575 3650 2    50   ~ 0
3.3V
Text Label 5175 3650 0    50   ~ 0
3.3V
Text Label 5825 3650 2    50   ~ 0
3.3V
Text Label 8425 3650 0    50   ~ 0
3.3V
Text Label 2850 2550 0    50   ~ 0
3.3V
Text HLabel 2550 2550 0    50   Input ~ 0
3.3V
Text HLabel 5175 3450 2    50   Input ~ 0
PWML
Text HLabel 2575 3450 0    50   Input ~ 0
DIRL
Text HLabel 5825 3450 0    50   Input ~ 0
PWMR
Text HLabel 8425 3450 2    50   Input ~ 0
DIRR
Wire Wire Line
	2550 2550 2850 2550
$Comp
L power:GND #PWR0110
U 1 1 5F6DE66B
P 3725 2875
F 0 "#PWR0110" H 3725 2625 50  0001 C CNN
F 1 "GND" H 3730 2702 50  0000 C CNN
F 2 "" H 3725 2875 50  0001 C CNN
F 3 "" H 3725 2875 50  0001 C CNN
	1    3725 2875
	1    0    0    -1  
$EndComp
Text Label 3625 2875 3    50   ~ 0
3.3V
Wire Wire Line
	3625 2875 3625 2725
Wire Wire Line
	3725 2725 3725 2875
Wire Wire Line
	3525 2725 3525 2875
Wire Wire Line
	3425 2725 3425 2875
Wire Wire Line
	3825 2725 3825 3450
Wire Wire Line
	3925 2725 3925 3450
$Comp
L power:GND #PWR014
U 1 1 5F6E7498
P 7275 2875
F 0 "#PWR014" H 7275 2625 50  0001 C CNN
F 1 "GND" H 7280 2702 50  0000 C CNN
F 2 "" H 7275 2875 50  0001 C CNN
F 3 "" H 7275 2875 50  0001 C CNN
	1    7275 2875
	-1   0    0    -1  
$EndComp
Text Label 7375 2875 3    50   ~ 0
3.3V
Wire Wire Line
	7375 2875 7375 2725
Wire Wire Line
	7275 2725 7275 2875
Wire Wire Line
	7475 2725 7475 2875
Wire Wire Line
	7575 2725 7575 2875
Text HLabel 3525 2875 3    50   Output ~ 0
ENC1_L
Text HLabel 3425 2875 3    50   Output ~ 0
ENC2_L
Text HLabel 7575 2875 3    50   Output ~ 0
ENC1_R
Text HLabel 7475 2875 3    50   Output ~ 0
ENC2_R
Wire Notes Line
	2275 2425 8725 2425
Wire Notes Line
	8725 2425 8725 4700
Wire Notes Line
	8725 4700 2275 4700
Wire Notes Line
	2275 2425 2275 4700
Text Notes 4875 2600 0    79   ~ 16
MAIN MOTOR DRIVER
$Comp
L Transistor_FET:AO3401A QM2
U 1 1 5F6B49E6
P 3825 1550
F 0 "QM2" H 4100 1525 50  0000 C CNN
F 1 "AO3401" H 4150 1600 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 4025 1475 50  0001 L CIN
F 3 "http://www.aosmd.com/pdfs/datasheet/AO3401A.pdf" H 3825 1550 50  0001 L CNN
	1    3825 1550
	1    0    0    1   
$EndComp
$Comp
L Device:D_Zener_ALT DM1
U 1 1 5F6B663F
P 3550 1400
F 0 "DM1" V 3450 1450 50  0000 L CNN
F 1 "5.1V" V 3525 1450 50  0000 L CNN
F 2 "Diode_SMD:D_SOD-123" H 3550 1400 50  0001 C CNN
F 3 "~" H 3550 1400 50  0001 C CNN
	1    3550 1400
	0    1    1    0   
$EndComp
$Comp
L Device:R RM5
U 1 1 5F6B7674
P 3375 1400
F 0 "RM5" H 3500 1350 50  0000 C CNN
F 1 "10K" V 3375 1400 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 3305 1400 50  0001 C CNN
F 3 "~" H 3375 1400 50  0001 C CNN
	1    3375 1400
	-1   0    0    1   
$EndComp
Wire Wire Line
	3375 1250 3550 1250
Wire Wire Line
	3375 1550 3550 1550
Connection ~ 3550 1550
Wire Wire Line
	3550 1550 3625 1550
Wire Wire Line
	3550 1250 3925 1250
Wire Wire Line
	3925 1250 3925 1350
Connection ~ 3550 1250
$Comp
L Device:D_Schottky_ALT DM2
U 1 1 5F6C0767
P 3925 1900
F 0 "DM2" V 3875 1725 50  0000 C CNN
F 1 "SS14" V 3950 1750 50  0000 C CNN
F 2 "Diode_SMD:D_SMA" H 3925 1900 50  0001 C CNN
F 3 "~" H 3925 1900 50  0001 C CNN
	1    3925 1900
	0    1    1    0   
$EndComp
$Comp
L Transistor_BJT:MMBT3904 QM1
U 1 1 5F6C245E
P 3275 1850
F 0 "QM1" H 3050 1925 50  0000 L CNN
F 1 "MMBT3904" H 2975 2000 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 3475 1775 50  0001 L CIN
F 3 "https://www.fairchildsemi.com/datasheets/2N/2N3904.pdf" H 3275 1850 50  0001 L CNN
	1    3275 1850
	1    0    0    -1  
$EndComp
Connection ~ 3375 1550
Wire Wire Line
	3375 1550 3375 1650
$Comp
L power:GND #PWR0111
U 1 1 5F6C640B
P 3675 2050
F 0 "#PWR0111" H 3675 1800 50  0001 C CNN
F 1 "GND" H 3680 1877 50  0000 C CNN
F 2 "" H 3675 2050 50  0001 C CNN
F 3 "" H 3675 2050 50  0001 C CNN
	1    3675 2050
	-1   0    0    -1  
$EndComp
Connection ~ 3675 2050
Wire Wire Line
	3675 2050 3925 2050
Wire Wire Line
	3375 2050 3675 2050
$Comp
L Connector_Generic:Conn_01x02 JM2
U 1 1 5F6C7D65
P 4350 1850
F 0 "JM2" H 4430 1842 50  0000 L CNN
F 1 "EXT" H 4430 1751 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 4350 1850 50  0001 C CNN
F 3 "~" H 4350 1850 50  0001 C CNN
	1    4350 1850
	1    0    0    -1  
$EndComp
Wire Wire Line
	3925 1750 4075 1750
Wire Wire Line
	4150 1750 4150 1850
Connection ~ 3925 1750
Wire Wire Line
	3925 2050 4075 2050
Wire Wire Line
	4150 2050 4150 1950
Connection ~ 3925 2050
$Comp
L Device:R RM4
U 1 1 5F6CBC80
P 2850 1850
F 0 "RM4" V 2925 1825 50  0000 C CNN
F 1 "10K" V 2850 1850 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 2780 1850 50  0001 C CNN
F 3 "~" H 2850 1850 50  0001 C CNN
	1    2850 1850
	0    1    1    0   
$EndComp
Wire Wire Line
	3000 1850 3075 1850
Text HLabel 2700 1850 0    50   Input ~ 0
PWM_EXT
Text Label 4025 1250 0    50   ~ 0
VS
Wire Wire Line
	3925 1250 4025 1250
Connection ~ 3925 1250
Wire Wire Line
	2875 4050 2800 4050
Connection ~ 2875 4050
Connection ~ 4875 4050
Wire Wire Line
	4875 4050 4950 4050
Wire Wire Line
	6125 4050 6050 4050
Connection ~ 6125 4050
Wire Wire Line
	8125 4050 8200 4050
Connection ~ 8125 4050
Wire Notes Line
	4600 2275 2275 2275
Wire Notes Line
	2275 2275 2275 1150
Wire Notes Line
	2275 1150 4600 1150
Wire Notes Line
	4600 1150 4600 2275
Text Notes 2300 1300 0    79   ~ 16
EXTINGUISHER
$Comp
L Device:R RM13
U 1 1 5F646088
P 8275 3450
F 0 "RM13" V 8175 3450 50  0000 C CNN
F 1 "10K" V 8275 3450 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 8205 3450 50  0001 C CNN
F 3 "~" H 8275 3450 50  0001 C CNN
	1    8275 3450
	0    -1   1    0   
$EndComp
$Comp
L Device:R RM10
U 1 1 5F6460CE
P 5975 3450
F 0 "RM10" V 5875 3450 50  0000 C CNN
F 1 "10K" V 5975 3450 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 5905 3450 50  0001 C CNN
F 3 "~" H 5975 3450 50  0001 C CNN
	1    5975 3450
	0    1    1    0   
$EndComp
$Comp
L Device:R RM6
U 1 1 5F612360
P 5025 3450
F 0 "RM6" V 4925 3450 50  0000 C CNN
F 1 "10K" V 5025 3450 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 4955 3450 50  0001 C CNN
F 3 "~" H 5025 3450 50  0001 C CNN
	1    5025 3450
	0    -1   1    0   
$EndComp
$Comp
L Device:R RM1
U 1 1 5F6218DC
P 2725 3450
F 0 "RM1" V 2625 3450 50  0000 C CNN
F 1 "10K" V 2725 3450 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 2655 3450 50  0001 C CNN
F 3 "~" H 2725 3450 50  0001 C CNN
	1    2725 3450
	0    1    1    0   
$EndComp
Wire Wire Line
	5550 1675 5625 1675
Connection ~ 5625 1675
Wire Wire Line
	7175 3450 7325 3450
Wire Wire Line
	7175 2725 7175 3450
Wire Wire Line
	7075 2725 7075 3450
$Comp
L Connector_Generic:Conn_01x06 JM1
U 1 1 5F6DB938
P 3625 2525
F 0 "JM1" V 3589 2137 50  0000 R CNN
F 1 "M1" V 3498 2137 50  0000 R CNN
F 2 "Connector_JST:JST_PH_S6B-PH-K_1x06_P2.00mm_Horizontal" H 3625 2525 50  0001 C CNN
F 3 "~" H 3625 2525 50  0001 C CNN
	1    3625 2525
	0    -1   -1   0   
$EndComp
$Comp
L Connector_Generic:Conn_01x06 JM3
U 1 1 5F6E7492
P 7275 2525
F 0 "JM3" V 7239 2805 50  0000 L CNN
F 1 "M2" V 7148 2805 50  0000 L CNN
F 2 "Connector_JST:JST_PH_S6B-PH-K_1x06_P2.00mm_Horizontal" H 7275 2525 50  0001 C CNN
F 3 "~" H 7275 2525 50  0001 C CNN
	1    7275 2525
	0    -1   -1   0   
$EndComp
$Comp
L Device:C CM6
U 1 1 5F759601
P 4075 1900
F 0 "CM6" H 4025 1675 50  0000 L CNN
F 1 "100nF" H 4025 1600 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 4113 1750 50  0001 C CNN
F 3 "~" H 4075 1900 50  0001 C CNN
	1    4075 1900
	1    0    0    -1  
$EndComp
Connection ~ 4075 1750
Wire Wire Line
	4075 1750 4150 1750
Connection ~ 4075 2050
Wire Wire Line
	4075 2050 4150 2050
$EndSCHEMATC
