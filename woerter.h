/*
Written by Sebastian Prinz

Wortdefinitionen für die Wortuhr

Basierend auf folgender Verdrahtung
E 0		S 19	K 20	I 39	S 40	T 59	A 60	F 79	Ü 80	N 99	F 100
Z 1		E 18	H 21	N 38	Z 41	W 58	A 61	N 78	Z 81	I 98	G 101
D 2		R 17	E 22	I 37	V 42	I 57	E 62	R 77	T 82	E 97	L 102
V 3		O 16	R 23	F 36	U 43	N 56	K 63	N 76	A 83	C 96	H 103
H 4		A 15	L 24	B 35	A 44	E 55	L 64	F 75	Ü 84	N 95	F 104
E 5		I 14	N 25	S 34	X 45	Ä 54	M 65	Z 74	W 85	E 94	I 105
D 6		R 13	E 26	I 33	A 46	U 53	J 66	V 73	I 86	E 93	R 106
S 7		E 12	C 27	H 32	S 47	N 52	L 67	A 72	C 87	H 92	T 107
S 8		I 11	E 28	B 31	E 48	N 51	Z 68	W 71	Ö 88	L 91	F 108
Z 9		E 10	H 29	N 30	E 49	U 50	N 69	K 70	U 89	H 90	R 109

Minutenpunkte:
________
|112 113|
|       |
|111 110|
'''''''''
*/

#include <vector>

std::vector<int> de_vor   { 3,16,23 };
std::vector<int> de_nach   { 76,83,96,103 };
std::vector<int> de_esist   { 0,19,39,40,59 };
std::vector<int> de_uhr   { 89,90,109 };

std::vector<int> de_fuenf   { 79,80,99,100 };
std::vector<int> de_zehn   { 1,18,21,38 };
std::vector<int> de_viertel   { 42,57,62,77,82,97,102 };
std::vector<int> de_zwanzig   { 41,58,61,78,81,98,101 };
std::vector<int> de_halb   { 4,15,24,35 };
std::vector<int> de_dreiviertel  { 2,17,22,37,42,57,62,77,82,97,102 };

std::vector<int> de_h_ein   { 5,14,25 };
std::vector<int> de_h_eins   { 5,14,25,34 };
std::vector<int> de_h_zwei   { 74,85,94,105 };
std::vector<int> de_h_drei   { 6,13,26,33 };
std::vector<int> de_h_vier   { 73,86,93,106 };
std::vector<int> de_h_fuenf   { 75,84,95,104 };
std::vector<int> de_h_sechs   { 7,12,27,32,47 };
std::vector<int> de_h_sieben  { 8,11,28,31,48,51 };
std::vector<int> de_h_acht   { 72,87,92,107 };
std::vector<int> de_h_neun   { 30,49,50,69 };
std::vector<int> de_h_zehn   { 9,10,29,30 };
std::vector<int> de_h_elf   { 55,64,75 };
std::vector<int> de_h_zwoelf   { 68,71,88,91,108 };

std::vector<int> de_1   { 112 };
std::vector<int> de_2   { 113 };
std::vector<int> de_3   { 110 };
std::vector<int> de_4   { 111 };
std::vector<int> de_mp { 112, 113,110,111 };


std::vector<std::vector<int>> de_h{ de_h_eins, de_h_zwei,de_h_drei,de_h_vier, de_h_fuenf, de_h_sechs, de_h_sieben, de_h_acht, de_h_neun, de_h_zehn, de_h_elf, de_h_zwoelf };
