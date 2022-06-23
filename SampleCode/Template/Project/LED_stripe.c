
#include <stdio.h>
#include <string.h>
#include "ML51.h"
#include "LED_stripe.h"




bit trans_finish_flag = 0;
xdata unsigned char DataBuffer[LED_DATA_LEN] = {0};
unsigned char DemoState = state_Rainbow;

unsigned int Coloridx = 0;

#if defined (ENABLE_EXTRA_DEMO)
code unsigned char colorsFull[COLORTALBE_NUM][3] = 
{ 
	{	255	,	0	,	0	}	,
	{	254	,	1	,	0	}	,
	{	253	,	2	,	0	}	,
	{	252	,	3	,	0	}	,
	{	251	,	4	,	0	}	,
	{	250	,	5	,	0	}	,
	{	249	,	6	,	0	}	,
	{	248	,	7	,	0	}	,
	{	247	,	8	,	0	}	,
	{	246	,	9	,	0	}	,
	{	245	,	10	,	0	}	,
	{	244	,	11	,	0	}	,
	{	243	,	12	,	0	}	,
	{	242	,	13	,	0	}	,
	{	241	,	14	,	0	}	,
	{	240	,	15	,	0	}	,
	{	239	,	16	,	0	}	,
	{	238	,	17	,	0	}	,
	{	237	,	18	,	0	}	,
	{	236	,	19	,	0	}	,
	{	235	,	20	,	0	}	,
	{	234	,	21	,	0	}	,
	{	233	,	22	,	0	}	,
	{	232	,	23	,	0	}	,
	{	231	,	24	,	0	}	,
	{	230	,	25	,	0	}	,
	{	229	,	26	,	0	}	,
	{	228	,	27	,	0	}	,
	{	227	,	28	,	0	}	,
	{	226	,	29	,	0	}	,
	{	225	,	30	,	0	}	,
	{	224	,	31	,	0	}	,
	{	223	,	32	,	0	}	,
	{	222	,	33	,	0	}	,
	{	221	,	34	,	0	}	,
	{	220	,	35	,	0	}	,
	{	219	,	36	,	0	}	,
	{	218	,	37	,	0	}	,
	{	217	,	38	,	0	}	,
	{	216	,	39	,	0	}	,
	{	215	,	40	,	0	}	,
	{	214	,	41	,	0	}	,
	{	213	,	42	,	0	}	,
	{	212	,	43	,	0	}	,
	{	211	,	44	,	0	}	,
	{	210	,	45	,	0	}	,
	{	209	,	46	,	0	}	,
	{	208	,	47	,	0	}	,
	{	207	,	48	,	0	}	,
	{	206	,	49	,	0	}	,
	{	205	,	50	,	0	}	,
	{	204	,	51	,	0	}	,
	{	203	,	52	,	0	}	,
	{	202	,	53	,	0	}	,
	{	201	,	54	,	0	}	,
	{	200	,	55	,	0	}	,
	{	199	,	56	,	0	}	,
	{	198	,	57	,	0	}	,
	{	197	,	58	,	0	}	,
	{	196	,	59	,	0	}	,
	{	195	,	60	,	0	}	,
	{	194	,	61	,	0	}	,
	{	193	,	62	,	0	}	,
	{	192	,	63	,	0	}	,
	{	191	,	64	,	0	}	,
	{	190	,	65	,	0	}	,
	{	189	,	66	,	0	}	,
	{	188	,	67	,	0	}	,
	{	187	,	68	,	0	}	,
	{	186	,	69	,	0	}	,
	{	185	,	70	,	0	}	,
	{	184	,	71	,	0	}	,
	{	183	,	72	,	0	}	,
	{	182	,	73	,	0	}	,
	{	181	,	74	,	0	}	,
	{	180	,	75	,	0	}	,
	{	179	,	76	,	0	}	,
	{	178	,	77	,	0	}	,
	{	177	,	78	,	0	}	,
	{	176	,	79	,	0	}	,
	{	175	,	80	,	0	}	,
	{	174	,	81	,	0	}	,
	{	173	,	82	,	0	}	,
	{	172	,	83	,	0	}	,
	{	171	,	84	,	0	}	,
	{	170	,	85	,	0	}	,
	{	169	,	86	,	0	}	,
	{	168	,	87	,	0	}	,
	{	167	,	88	,	0	}	,
	{	166	,	89	,	0	}	,
	{	165	,	90	,	0	}	,
	{	164	,	91	,	0	}	,
	{	163	,	92	,	0	}	,
	{	162	,	93	,	0	}	,
	{	161	,	94	,	0	}	,
	{	160	,	95	,	0	}	,
	{	159	,	96	,	0	}	,
	{	158	,	97	,	0	}	,
	{	157	,	98	,	0	}	,
	{	156	,	99	,	0	}	,
	{	155	,	100	,	0	}	,
	{	154	,	101	,	0	}	,
	{	153	,	102	,	0	}	,
	{	152	,	103	,	0	}	,
	{	151	,	104	,	0	}	,
	{	150	,	105	,	0	}	,
	{	149	,	106	,	0	}	,
	{	148	,	107	,	0	}	,
	{	147	,	108	,	0	}	,
	{	146	,	109	,	0	}	,
	{	145	,	110	,	0	}	,
	{	144	,	111	,	0	}	,
	{	143	,	112	,	0	}	,
	{	142	,	113	,	0	}	,
	{	141	,	114	,	0	}	,
	{	140	,	115	,	0	}	,
	{	139	,	116	,	0	}	,
	{	138	,	117	,	0	}	,
	{	137	,	118	,	0	}	,
	{	136	,	119	,	0	}	,
	{	135	,	120	,	0	}	,
	{	134	,	121	,	0	}	,
	{	133	,	122	,	0	}	,
	{	132	,	123	,	0	}	,
	{	131	,	124	,	0	}	,
	{	130	,	125	,	0	}	,
	{	129	,	126	,	0	}	,
	{	128	,	127	,	0	}	,
	{	127	,	128	,	0	}	,
	{	126	,	129	,	0	}	,
	{	125	,	130	,	0	}	,
	{	124	,	131	,	0	}	,
	{	123	,	132	,	0	}	,
	{	122	,	133	,	0	}	,
	{	121	,	134	,	0	}	,
	{	120	,	135	,	0	}	,
	{	119	,	136	,	0	}	,
	{	118	,	137	,	0	}	,
	{	117	,	138	,	0	}	,
	{	116	,	139	,	0	}	,
	{	115	,	140	,	0	}	,
	{	114	,	141	,	0	}	,
	{	113	,	142	,	0	}	,
	{	112	,	143	,	0	}	,
	{	111	,	144	,	0	}	,
	{	110	,	145	,	0	}	,
	{	109	,	146	,	0	}	,
	{	108	,	147	,	0	}	,
	{	107	,	148	,	0	}	,
	{	106	,	149	,	0	}	,
	{	105	,	150	,	0	}	,
	{	104	,	151	,	0	}	,
	{	103	,	152	,	0	}	,
	{	102	,	153	,	0	}	,
	{	101	,	154	,	0	}	,
	{	100	,	155	,	0	}	,
	{	99	,	156	,	0	}	,
	{	98	,	157	,	0	}	,
	{	97	,	158	,	0	}	,
	{	96	,	159	,	0	}	,
	{	95	,	160	,	0	}	,
	{	94	,	161	,	0	}	,
	{	93	,	162	,	0	}	,
	{	92	,	163	,	0	}	,
	{	91	,	164	,	0	}	,
	{	90	,	165	,	0	}	,
	{	89	,	166	,	0	}	,
	{	88	,	167	,	0	}	,
	{	87	,	168	,	0	}	,
	{	86	,	169	,	0	}	,
	{	85	,	170	,	0	}	,
	{	84	,	171	,	0	}	,
	{	83	,	172	,	0	}	,
	{	82	,	173	,	0	}	,
	{	81	,	174	,	0	}	,
	{	80	,	175	,	0	}	,
	{	79	,	176	,	0	}	,
	{	78	,	177	,	0	}	,
	{	77	,	178	,	0	}	,
	{	76	,	179	,	0	}	,
	{	75	,	180	,	0	}	,
	{	74	,	181	,	0	}	,
	{	73	,	182	,	0	}	,
	{	72	,	183	,	0	}	,
	{	71	,	184	,	0	}	,
	{	70	,	185	,	0	}	,
	{	69	,	186	,	0	}	,
	{	68	,	187	,	0	}	,
	{	67	,	188	,	0	}	,
	{	66	,	189	,	0	}	,
	{	65	,	190	,	0	}	,
	{	64	,	191	,	0	}	,
	{	63	,	192	,	0	}	,
	{	62	,	193	,	0	}	,
	{	61	,	194	,	0	}	,
	{	60	,	195	,	0	}	,
	{	59	,	196	,	0	}	,
	{	58	,	197	,	0	}	,
	{	57	,	198	,	0	}	,
	{	56	,	199	,	0	}	,
	{	55	,	200	,	0	}	,
	{	54	,	201	,	0	}	,
	{	53	,	202	,	0	}	,
	{	52	,	203	,	0	}	,
	{	51	,	204	,	0	}	,
	{	50	,	205	,	0	}	,
	{	49	,	206	,	0	}	,
	{	48	,	207	,	0	}	,
	{	47	,	208	,	0	}	,
	{	46	,	209	,	0	}	,
	{	45	,	210	,	0	}	,
	{	44	,	211	,	0	}	,
	{	43	,	212	,	0	}	,
	{	42	,	213	,	0	}	,
	{	41	,	214	,	0	}	,
	{	40	,	215	,	0	}	,
	{	39	,	216	,	0	}	,
	{	38	,	217	,	0	}	,
	{	37	,	218	,	0	}	,
	{	36	,	219	,	0	}	,
	{	35	,	220	,	0	}	,
	{	34	,	221	,	0	}	,
	{	33	,	222	,	0	}	,
	{	32	,	223	,	0	}	,
	{	31	,	224	,	0	}	,
	{	30	,	225	,	0	}	,
	{	29	,	226	,	0	}	,
	{	28	,	227	,	0	}	,
	{	27	,	228	,	0	}	,
	{	26	,	229	,	0	}	,
	{	25	,	230	,	0	}	,
	{	24	,	231	,	0	}	,
	{	23	,	232	,	0	}	,
	{	22	,	233	,	0	}	,
	{	21	,	234	,	0	}	,
	{	20	,	235	,	0	}	,
	{	19	,	236	,	0	}	,
	{	18	,	237	,	0	}	,
	{	17	,	238	,	0	}	,
	{	16	,	239	,	0	}	,
	{	15	,	240	,	0	}	,
	{	14	,	241	,	0	}	,
	{	13	,	242	,	0	}	,
	{	12	,	243	,	0	}	,
	{	11	,	244	,	0	}	,
	{	10	,	245	,	0	}	,
	{	9	,	246	,	0	}	,
	{	8	,	247	,	0	}	,
	{	7	,	248	,	0	}	,
	{	6	,	249	,	0	}	,
	{	5	,	250	,	0	}	,
	{	4	,	251	,	0	}	,
	{	3	,	252	,	0	}	,
	{	2	,	253	,	0	}	,
	{	1	,	254	,	0	}	,
	{	0	,	255	,	0	}	,
	{	0	,	254	,	1	}	,
	{	0	,	253	,	2	}	,
	{	0	,	252	,	3	}	,
	{	0	,	251	,	4	}	,
	{	0	,	250	,	5	}	,
	{	0	,	249	,	6	}	,
	{	0	,	248	,	7	}	,
	{	0	,	247	,	8	}	,
	{	0	,	246	,	9	}	,
	{	0	,	245	,	10	}	,
	{	0	,	244	,	11	}	,
	{	0	,	243	,	12	}	,
	{	0	,	242	,	13	}	,
	{	0	,	241	,	14	}	,
	{	0	,	240	,	15	}	,
	{	0	,	239	,	16	}	,
	{	0	,	238	,	17	}	,
	{	0	,	237	,	18	}	,
	{	0	,	236	,	19	}	,
	{	0	,	235	,	20	}	,
	{	0	,	234	,	21	}	,
	{	0	,	233	,	22	}	,
	{	0	,	232	,	23	}	,
	{	0	,	231	,	24	}	,
	{	0	,	230	,	25	}	,
	{	0	,	229	,	26	}	,
	{	0	,	228	,	27	}	,
	{	0	,	227	,	28	}	,
	{	0	,	226	,	29	}	,
	{	0	,	225	,	30	}	,
	{	0	,	224	,	31	}	,
	{	0	,	223	,	32	}	,
	{	0	,	222	,	33	}	,
	{	0	,	221	,	34	}	,
	{	0	,	220	,	35	}	,
	{	0	,	219	,	36	}	,
	{	0	,	218	,	37	}	,
	{	0	,	217	,	38	}	,
	{	0	,	216	,	39	}	,
	{	0	,	215	,	40	}	,
	{	0	,	214	,	41	}	,
	{	0	,	213	,	42	}	,
	{	0	,	212	,	43	}	,
	{	0	,	211	,	44	}	,
	{	0	,	210	,	45	}	,
	{	0	,	209	,	46	}	,
	{	0	,	208	,	47	}	,
	{	0	,	207	,	48	}	,
	{	0	,	206	,	49	}	,
	{	0	,	205	,	50	}	,
	{	0	,	204	,	51	}	,
	{	0	,	203	,	52	}	,
	{	0	,	202	,	53	}	,
	{	0	,	201	,	54	}	,
	{	0	,	200	,	55	}	,
	{	0	,	199	,	56	}	,
	{	0	,	198	,	57	}	,
	{	0	,	197	,	58	}	,
	{	0	,	196	,	59	}	,
	{	0	,	195	,	60	}	,
	{	0	,	194	,	61	}	,
	{	0	,	193	,	62	}	,
	{	0	,	192	,	63	}	,
	{	0	,	191	,	64	}	,
	{	0	,	190	,	65	}	,
	{	0	,	189	,	66	}	,
	{	0	,	188	,	67	}	,
	{	0	,	187	,	68	}	,
	{	0	,	186	,	69	}	,
	{	0	,	185	,	70	}	,
	{	0	,	184	,	71	}	,
	{	0	,	183	,	72	}	,
	{	0	,	182	,	73	}	,
	{	0	,	181	,	74	}	,
	{	0	,	180	,	75	}	,
	{	0	,	179	,	76	}	,
	{	0	,	178	,	77	}	,
	{	0	,	177	,	78	}	,
	{	0	,	176	,	79	}	,
	{	0	,	175	,	80	}	,
	{	0	,	174	,	81	}	,
	{	0	,	173	,	82	}	,
	{	0	,	172	,	83	}	,
	{	0	,	171	,	84	}	,
	{	0	,	170	,	85	}	,
	{	0	,	169	,	86	}	,
	{	0	,	168	,	87	}	,
	{	0	,	167	,	88	}	,
	{	0	,	166	,	89	}	,
	{	0	,	165	,	90	}	,
	{	0	,	164	,	91	}	,
	{	0	,	163	,	92	}	,
	{	0	,	162	,	93	}	,
	{	0	,	161	,	94	}	,
	{	0	,	160	,	95	}	,
	{	0	,	159	,	96	}	,
	{	0	,	158	,	97	}	,
	{	0	,	157	,	98	}	,
	{	0	,	156	,	99	}	,
	{	0	,	155	,	100	}	,
	{	0	,	154	,	101	}	,
	{	0	,	153	,	102	}	,
	{	0	,	152	,	103	}	,
	{	0	,	151	,	104	}	,
	{	0	,	150	,	105	}	,
	{	0	,	149	,	106	}	,
	{	0	,	148	,	107	}	,
	{	0	,	147	,	108	}	,
	{	0	,	146	,	109	}	,
	{	0	,	145	,	110	}	,
	{	0	,	144	,	111	}	,
	{	0	,	143	,	112	}	,
	{	0	,	142	,	113	}	,
	{	0	,	141	,	114	}	,
	{	0	,	140	,	115	}	,
	{	0	,	139	,	116	}	,
	{	0	,	138	,	117	}	,
	{	0	,	137	,	118	}	,
	{	0	,	136	,	119	}	,
	{	0	,	135	,	120	}	,
	{	0	,	134	,	121	}	,
	{	0	,	133	,	122	}	,
	{	0	,	132	,	123	}	,
	{	0	,	131	,	124	}	,
	{	0	,	130	,	125	}	,
	{	0	,	129	,	126	}	,
	{	0	,	128	,	127	}	,
	{	0	,	127	,	128	}	,
	{	0	,	126	,	129	}	,
	{	0	,	125	,	130	}	,
	{	0	,	124	,	131	}	,
	{	0	,	123	,	132	}	,
	{	0	,	122	,	133	}	,
	{	0	,	121	,	134	}	,
	{	0	,	120	,	135	}	,
	{	0	,	119	,	136	}	,
	{	0	,	118	,	137	}	,
	{	0	,	117	,	138	}	,
	{	0	,	116	,	139	}	,
	{	0	,	115	,	140	}	,
	{	0	,	114	,	141	}	,
	{	0	,	113	,	142	}	,
	{	0	,	112	,	143	}	,
	{	0	,	111	,	144	}	,
	{	0	,	110	,	145	}	,
	{	0	,	109	,	146	}	,
	{	0	,	108	,	147	}	,
	{	0	,	107	,	148	}	,
	{	0	,	106	,	149	}	,
	{	0	,	105	,	150	}	,
	{	0	,	104	,	151	}	,
	{	0	,	103	,	152	}	,
	{	0	,	102	,	153	}	,
	{	0	,	101	,	154	}	,
	{	0	,	100	,	155	}	,
	{	0	,	99	,	156	}	,
	{	0	,	98	,	157	}	,
	{	0	,	97	,	158	}	,
	{	0	,	96	,	159	}	,
	{	0	,	95	,	160	}	,
	{	0	,	94	,	161	}	,
	{	0	,	93	,	162	}	,
	{	0	,	92	,	163	}	,
	{	0	,	91	,	164	}	,
	{	0	,	90	,	165	}	,
	{	0	,	89	,	166	}	,
	{	0	,	88	,	167	}	,
	{	0	,	87	,	168	}	,
	{	0	,	86	,	169	}	,
	{	0	,	85	,	170	}	,
	{	0	,	84	,	171	}	,
	{	0	,	83	,	172	}	,
	{	0	,	82	,	173	}	,
	{	0	,	81	,	174	}	,
	{	0	,	80	,	175	}	,
	{	0	,	79	,	176	}	,
	{	0	,	78	,	177	}	,
	{	0	,	77	,	178	}	,
	{	0	,	76	,	179	}	,
	{	0	,	75	,	180	}	,
	{	0	,	74	,	181	}	,
	{	0	,	73	,	182	}	,
	{	0	,	72	,	183	}	,
	{	0	,	71	,	184	}	,
	{	0	,	70	,	185	}	,
	{	0	,	69	,	186	}	,
	{	0	,	68	,	187	}	,
	{	0	,	67	,	188	}	,
	{	0	,	66	,	189	}	,
	{	0	,	65	,	190	}	,
	{	0	,	64	,	191	}	,
	{	0	,	63	,	192	}	,
	{	0	,	62	,	193	}	,
	{	0	,	61	,	194	}	,
	{	0	,	60	,	195	}	,
	{	0	,	59	,	196	}	,
	{	0	,	58	,	197	}	,
	{	0	,	57	,	198	}	,
	{	0	,	56	,	199	}	,
	{	0	,	55	,	200	}	,
	{	0	,	54	,	201	}	,
	{	0	,	53	,	202	}	,
	{	0	,	52	,	203	}	,
	{	0	,	51	,	204	}	,
	{	0	,	50	,	205	}	,
	{	0	,	49	,	206	}	,
	{	0	,	48	,	207	}	,
	{	0	,	47	,	208	}	,
	{	0	,	46	,	209	}	,
	{	0	,	45	,	210	}	,
	{	0	,	44	,	211	}	,
	{	0	,	43	,	212	}	,
	{	0	,	42	,	213	}	,
	{	0	,	41	,	214	}	,
	{	0	,	40	,	215	}	,
	{	0	,	39	,	216	}	,
	{	0	,	38	,	217	}	,
	{	0	,	37	,	218	}	,
	{	0	,	36	,	219	}	,
	{	0	,	35	,	220	}	,
	{	0	,	34	,	221	}	,
	{	0	,	33	,	222	}	,
	{	0	,	32	,	223	}	,
	{	0	,	31	,	224	}	,
	{	0	,	30	,	225	}	,
	{	0	,	29	,	226	}	,
	{	0	,	28	,	227	}	,
	{	0	,	27	,	228	}	,
	{	0	,	26	,	229	}	,
	{	0	,	25	,	230	}	,
	{	0	,	24	,	231	}	,
	{	0	,	23	,	232	}	,
	{	0	,	22	,	233	}	,
	{	0	,	21	,	234	}	,
	{	0	,	20	,	235	}	,
	{	0	,	19	,	236	}	,
	{	0	,	18	,	237	}	,
	{	0	,	17	,	238	}	,
	{	0	,	16	,	239	}	,
	{	0	,	15	,	240	}	,
	{	0	,	14	,	241	}	,
	{	0	,	13	,	242	}	,
	{	0	,	12	,	243	}	,
	{	0	,	11	,	244	}	,
	{	0	,	10	,	245	}	,
	{	0	,	9	,	246	}	,
	{	0	,	8	,	247	}	,
	{	0	,	7	,	248	}	,
	{	0	,	6	,	249	}	,
	{	0	,	5	,	250	}	,
	{	0	,	4	,	251	}	,
	{	0	,	3	,	252	}	,
	{	0	,	2	,	253	}	,
	{	0	,	1	,	254	}	,
	{	0	,	0	,	255	}	,
	{	1	,	0	,	254	}	,
	{	2	,	0	,	253	}	,
	{	3	,	0	,	252	}	,
	{	4	,	0	,	251	}	,
	{	5	,	0	,	250	}	,
	{	6	,	0	,	249	}	,
	{	7	,	0	,	248	}	,
	{	8	,	0	,	247	}	,
	{	9	,	0	,	246	}	,
	{	10	,	0	,	245	}	,
	{	11	,	0	,	244	}	,
	{	12	,	0	,	243	}	,
	{	13	,	0	,	242	}	,
	{	14	,	0	,	241	}	,
	{	15	,	0	,	240	}	,
	{	16	,	0	,	239	}	,
	{	17	,	0	,	238	}	,
	{	18	,	0	,	237	}	,
	{	19	,	0	,	236	}	,
	{	20	,	0	,	235	}	,
	{	21	,	0	,	234	}	,
	{	22	,	0	,	233	}	,
	{	23	,	0	,	232	}	,
	{	24	,	0	,	231	}	,
	{	25	,	0	,	230	}	,
	{	26	,	0	,	229	}	,
	{	27	,	0	,	228	}	,
	{	28	,	0	,	227	}	,
	{	29	,	0	,	226	}	,
	{	30	,	0	,	225	}	,
	{	31	,	0	,	224	}	,
	{	32	,	0	,	223	}	,
	{	33	,	0	,	222	}	,
	{	34	,	0	,	221	}	,
	{	35	,	0	,	220	}	,
	{	36	,	0	,	219	}	,
	{	37	,	0	,	218	}	,
	{	38	,	0	,	217	}	,
	{	39	,	0	,	216	}	,
	{	40	,	0	,	215	}	,
	{	41	,	0	,	214	}	,
	{	42	,	0	,	213	}	,
	{	43	,	0	,	212	}	,
	{	44	,	0	,	211	}	,
	{	45	,	0	,	210	}	,
	{	46	,	0	,	209	}	,
	{	47	,	0	,	208	}	,
	{	48	,	0	,	207	}	,
	{	49	,	0	,	206	}	,
	{	50	,	0	,	205	}	,
	{	51	,	0	,	204	}	,
	{	52	,	0	,	203	}	,
	{	53	,	0	,	202	}	,
	{	54	,	0	,	201	}	,
	{	55	,	0	,	200	}	,
	{	56	,	0	,	199	}	,
	{	57	,	0	,	198	}	,
	{	58	,	0	,	197	}	,
	{	59	,	0	,	196	}	,
	{	60	,	0	,	195	}	,
	{	61	,	0	,	194	}	,
	{	62	,	0	,	193	}	,
	{	63	,	0	,	192	}	,
	{	64	,	0	,	191	}	,
	{	65	,	0	,	190	}	,
	{	66	,	0	,	189	}	,
	{	67	,	0	,	188	}	,
	{	68	,	0	,	187	}	,
	{	69	,	0	,	186	}	,
	{	70	,	0	,	185	}	,
	{	71	,	0	,	184	}	,
	{	72	,	0	,	183	}	,
	{	73	,	0	,	182	}	,
	{	74	,	0	,	181	}	,
	{	75	,	0	,	180	}	,
	{	76	,	0	,	179	}	,
	{	77	,	0	,	178	}	,
	{	78	,	0	,	177	}	,
	{	79	,	0	,	176	}	,
	{	80	,	0	,	175	}	,
	{	81	,	0	,	174	}	,
	{	82	,	0	,	173	}	,
	{	83	,	0	,	172	}	,
	{	84	,	0	,	171	}	,
	{	85	,	0	,	170	}	,
	{	86	,	0	,	169	}	,
	{	87	,	0	,	168	}	,
	{	88	,	0	,	167	}	,
	{	89	,	0	,	166	}	,
	{	90	,	0	,	165	}	,
	{	91	,	0	,	164	}	,
	{	92	,	0	,	163	}	,
	{	93	,	0	,	162	}	,
	{	94	,	0	,	161	}	,
	{	95	,	0	,	160	}	,
	{	96	,	0	,	159	}	,
	{	97	,	0	,	158	}	,
	{	98	,	0	,	157	}	,
	{	99	,	0	,	156	}	,
	{	100	,	0	,	155	}	,
	{	101	,	0	,	154	}	,
	{	102	,	0	,	153	}	,
	{	103	,	0	,	152	}	,
	{	104	,	0	,	151	}	,
	{	105	,	0	,	150	}	,
	{	106	,	0	,	149	}	,
	{	107	,	0	,	148	}	,
	{	108	,	0	,	147	}	,
	{	109	,	0	,	146	}	,
	{	110	,	0	,	145	}	,
	{	111	,	0	,	144	}	,
	{	112	,	0	,	143	}	,
	{	113	,	0	,	142	}	,
	{	114	,	0	,	141	}	,
	{	115	,	0	,	140	}	,
	{	116	,	0	,	139	}	,
	{	117	,	0	,	138	}	,
	{	118	,	0	,	137	}	,
	{	119	,	0	,	136	}	,
	{	120	,	0	,	135	}	,
	{	121	,	0	,	134	}	,
	{	122	,	0	,	133	}	,
	{	123	,	0	,	132	}	,
	{	124	,	0	,	131	}	,
	{	125	,	0	,	130	}	,
	{	126	,	0	,	129	}	,
	{	127	,	0	,	128	}	,
	{	128	,	0	,	127	}	,
	{	129	,	0	,	126	}	,
	{	130	,	0	,	125	}	,
	{	131	,	0	,	124	}	,
	{	132	,	0	,	123	}	,
	{	133	,	0	,	122	}	,
	{	134	,	0	,	121	}	,
	{	135	,	0	,	120	}	,
	{	136	,	0	,	119	}	,
	{	137	,	0	,	118	}	,
	{	138	,	0	,	117	}	,
	{	139	,	0	,	116	}	,
	{	140	,	0	,	115	}	,
	{	141	,	0	,	114	}	,
	{	142	,	0	,	113	}	,
	{	143	,	0	,	112	}	,
	{	144	,	0	,	111	}	,
	{	145	,	0	,	110	}	,
	{	146	,	0	,	109	}	,
	{	147	,	0	,	108	}	,
	{	148	,	0	,	107	}	,
	{	149	,	0	,	106	}	,
	{	150	,	0	,	105	}	,
	{	151	,	0	,	104	}	,
	{	152	,	0	,	103	}	,
	{	153	,	0	,	102	}	,
	{	154	,	0	,	101	}	,
	{	155	,	0	,	100	}	,
	{	156	,	0	,	99	}	,
	{	157	,	0	,	98	}	,
	{	158	,	0	,	97	}	,
	{	159	,	0	,	96	}	,
	{	160	,	0	,	95	}	,
	{	161	,	0	,	94	}	,
	{	162	,	0	,	93	}	,
	{	163	,	0	,	92	}	,
	{	164	,	0	,	91	}	,
	{	165	,	0	,	90	}	,
	{	166	,	0	,	89	}	,
	{	167	,	0	,	88	}	,
	{	168	,	0	,	87	}	,
	{	169	,	0	,	86	}	,
	{	170	,	0	,	85	}	,
	{	171	,	0	,	84	}	,
	{	172	,	0	,	83	}	,
	{	173	,	0	,	82	}	,
	{	174	,	0	,	81	}	,
	{	175	,	0	,	80	}	,
	{	176	,	0	,	79	}	,
	{	177	,	0	,	78	}	,
	{	178	,	0	,	77	}	,
	{	179	,	0	,	76	}	,
	{	180	,	0	,	75	}	,
	{	181	,	0	,	74	}	,
	{	182	,	0	,	73	}	,
	{	183	,	0	,	72	}	,
	{	184	,	0	,	71	}	,
	{	185	,	0	,	70	}	,
	{	186	,	0	,	69	}	,
	{	187	,	0	,	68	}	,
	{	188	,	0	,	67	}	,
	{	189	,	0	,	66	}	,
	{	190	,	0	,	65	}	,
	{	191	,	0	,	64	}	,
	{	192	,	0	,	63	}	,
	{	193	,	0	,	62	}	,
	{	194	,	0	,	61	}	,
	{	195	,	0	,	60	}	,
	{	196	,	0	,	59	}	,
	{	197	,	0	,	58	}	,
	{	198	,	0	,	57	}	,
	{	199	,	0	,	56	}	,
	{	200	,	0	,	55	}	,
	{	201	,	0	,	54	}	,
	{	202	,	0	,	53	}	,
	{	203	,	0	,	52	}	,
	{	204	,	0	,	51	}	,
	{	205	,	0	,	50	}	,
	{	206	,	0	,	49	}	,
	{	207	,	0	,	48	}	,
	{	208	,	0	,	47	}	,
	{	209	,	0	,	46	}	,
	{	210	,	0	,	45	}	,
	{	211	,	0	,	44	}	,
	{	212	,	0	,	43	}	,
	{	213	,	0	,	42	}	,
	{	214	,	0	,	41	}	,
	{	215	,	0	,	40	}	,
	{	216	,	0	,	39	}	,
	{	217	,	0	,	38	}	,
	{	218	,	0	,	37	}	,
	{	219	,	0	,	36	}	,
	{	220	,	0	,	35	}	,
	{	221	,	0	,	34	}	,
	{	222	,	0	,	33	}	,
	{	223	,	0	,	32	}	,
	{	224	,	0	,	31	}	,
	{	225	,	0	,	30	}	,
	{	226	,	0	,	29	}	,
	{	227	,	0	,	28	}	,
	{	228	,	0	,	27	}	,
	{	229	,	0	,	26	}	,
	{	230	,	0	,	25	}	,
	{	231	,	0	,	24	}	,
	{	232	,	0	,	23	}	,
	{	233	,	0	,	22	}	,
	{	234	,	0	,	21	}	,
	{	235	,	0	,	20	}	,
	{	236	,	0	,	19	}	,
	{	237	,	0	,	18	}	,
	{	238	,	0	,	17	}	,
	{	239	,	0	,	16	}	,
	{	240	,	0	,	15	}	,
	{	241	,	0	,	14	}	,
	{	242	,	0	,	13	}	,
	{	243	,	0	,	12	}	,
	{	244	,	0	,	11	}	,
	{	245	,	0	,	10	}	,
	{	246	,	0	,	9	}	,
	{	247	,	0	,	8	}	,
	{	248	,	0	,	7	}	,
	{	249	,	0	,	6	}	,
	{	250	,	0	,	5	}	,
	{	251	,	0	,	4	}	,
	{	252	,	0	,	3	}	,
	{	253	,	0	,	2	}	,
	{	254	,	0	,	1	}	,
	{	255	,	0	,	0	}	,

};
#endif 

void Timer3_Delay(unsigned long u32SYSCLK,unsigned char u8TMDIV, unsigned int u16CNT, unsigned long u32DLYUnit)
{
    unsigned char TL3TMP,TH3TMP;  
  
    SFRS = 0;
    switch (u8TMDIV)
    {
      case 1:T3CON&=0xF8; break;
      case 2:T3CON&=0xF8;T3CON|=0x01; break;
      case 4:T3CON&=0xF8;T3CON|=0x02; break;
      case 8:T3CON&=0xF8;T3CON|=0x03; break;
      case 16:T3CON&=0xF8;T3CON|=0x04; break;
      case 32:T3CON&=0xF8;T3CON|=0x05; break;
      case 64:T3CON&=0xF8;T3CON|=0x06; break;
      case 128:T3CON&=0xF8;T3CON|=0x07; break;
    }
    TL3TMP = LOBYTE(65536-((u32SYSCLK/1000000)*u32DLYUnit/u8TMDIV));
    TH3TMP = HIBYTE(65536-((u32SYSCLK/1000000)*u32DLYUnit/u8TMDIV));
    while (u16CNT != 0)
    {
      clr_T3CON_TF3;
      RL3 = TL3TMP;
      RH3 = TH3TMP;
      set_T3CON_TR3;                                    //Trigger Timer3
      while (!(T3CON&SET_BIT4));                        //Check Timer3 Time-Out Flag
      clr_T3CON_TF3;
      clr_T3CON_TR3;                                    //Stop Timer3
      u16CNT --;
    }
}

void setLED_delayus(unsigned int dly)
{
/*
	delay(100) : 14.84 us
	delay(200) : 29.37 us
	delay(300) : 43.97 us
	delay(400) : 58.5 us	
	delay(500) : 73.13 us	
	
	delay(1500) : 0.218 ms (218 us)
	delay(2000) : 0.291 ms (291 us)	
*/

	while( dly--);

	// Timer3_Delay(24000000,2,dly,1);

}

void setLED_delayms(unsigned int ms)
{
	// Timer3_Delay(24000000,16,ms,1000);

	uint16_t i = 0 ;
	for (i=0;i<ms;i++)
	{
		//setLED_delayus(MS_1MS);
		_delay_();
	}	
}

void WS2812C_DATA1(void)
{
	#if defined (ENABLE_SPI)
    // _push_(SFRS);
    SFRS=0;

	SPI0DR = WS_SPI_HIGH;
	// while (SPI0SR & SET_BIT1);
	while(!(SPI0SR & SET_BIT7));
	clr_SPI0SR_SPIF;

    // _pop_(SFRS);	

	#elif defined (ENABLE_GPIO_EMULATE)

	#if defined (ENABLE_DEBUG_WS2812_PROTOCOL)
	P02 = 1;	// debug	
	#endif

	LEDGPIO = 1;//set_LEDGPIO(1);
	nop;nop;nop;nop;nop;
	LEDGPIO = 1;//set_LEDGPIO(1);
	nop;nop;nop;nop;nop;
		
	LEDGPIO = 0;//set_LEDGPIO(0);
	nop;nop;nop;nop;nop;

	#if defined (ENABLE_DEBUG_WS2812_PROTOCOL)
	P02 = 0;	// debug	
	#endif

	#endif
}

void WS2812C_DATA0(void)
{
	#if defined (ENABLE_SPI)	
    // _push_(SFRS);
    SFRS=0;

	SPI0DR = WS_SPI_LOW;
	// while (SPI0SR & SET_BIT1);
	while(!(SPI0SR & SET_BIT7));
	clr_SPI0SR_SPIF;

    // _pop_(SFRS);

	#elif defined (ENABLE_GPIO_EMULATE)

	#if defined (ENABLE_DEBUG_WS2812_PROTOCOL)
	P02 = 1;	// debug	
	#endif

	LEDGPIO = 1;//set_LEDGPIO(1);
	nop;nop;nop;nop;nop;
			
	LEDGPIO = 0;//set_LEDGPIO(0);
	nop;nop;nop;nop;nop;	
	LEDGPIO = 0;//set_LEDGPIO(0);
	nop;nop;nop;nop;nop;

	#if defined (ENABLE_DEBUG_WS2812_PROTOCOL)
	P02 = 0;	// debug	
	#endif

	#endif		
}

void WS2812C_Send_1Byte(unsigned char wData)
{
	#if 1	// due to 8051 low performance 
	if(wData & 0x80) 
		WS2812C_DATA1(); 
	else 
		WS2812C_DATA0();   

	if(wData & 0x40) 
		WS2812C_DATA1(); 
	else 
		WS2812C_DATA0(); 

	if(wData & 0x20) 
		WS2812C_DATA1(); 
	else 
		WS2812C_DATA0();   

	if(wData & 0x10) 
		WS2812C_DATA1(); 
	else 
		WS2812C_DATA0();   

	if(wData & 0x08) 
		WS2812C_DATA1(); 
	else 
		WS2812C_DATA0();   

	if(wData & 0x04) 
		WS2812C_DATA1(); 
	else 
		WS2812C_DATA0();  

	if(wData & 0x02) 
		WS2812C_DATA1(); 
	else 
		WS2812C_DATA0();   

	if(wData & 0x01) 
		WS2812C_DATA1(); 
	else 
		WS2812C_DATA0();  

	#else
	unsigned char i = 0;

	for (i = 0; i < 8; i ++)
	{
		if (wData & 0x80)
		{
			WS2812C_DATA1();
		}
		else
		{
			WS2812C_DATA0();
		}
		wData <<= 1;	
	} 	
	#endif
}


// void WS2812C_Send_1bit(unsigned char wData)
// {
// 	switch(wData)
// 	{
// 		case 0: 
// 			WS2812C_DATA0();				
// 			break;
// 		default:
// 			WS2812C_DATA1();
// 			break;
// 	}	
// }

void setLED_ResetPulse(unsigned char pos)	//target : 280us
{	
	if (pos == WS_RES_POS_FRONT)	//57 us
	{
		setLED_delayus(400);
	}
	else
	{
		setLED_delayus(MS_LED_LATCH);
	}

}

void setLED_Display(unsigned int DataCount)
{
	unsigned int i = 0;

	UNUSED(DataCount);

	setLED_ResetPulse(WS_RES_POS_FRONT);
	
	DISABLE_GLOBAL_INTERRUPT;
	trans_finish_flag = 1; 	
	for(i=0;i<(LED_NUM);i++)
	{
		WS2812C_Send_1Byte(DataBuffer[i*3]);
		WS2812C_Send_1Byte(DataBuffer[i*3+1]);
		WS2812C_Send_1Byte(DataBuffer[i*3+2]);		
	}
	trans_finish_flag = 0;
	ENABLE_GLOBAL_INTERRUPT;

	setLED_ResetPulse(WS_RES_POS_BACK);	   
}

void setLED_BufferClear(void)
{
	memset(DataBuffer,0x00,LED_DATA_LEN);
}

void setLED_Color(unsigned char DeviceNumber ,unsigned char RED, unsigned char GREEN, unsigned char BLUE)	// Output a colour Format: GGRRBB	
{

	DataBuffer[DeviceNumber*3]   = GREEN;
	DataBuffer[DeviceNumber*3+1] = RED;
	DataBuffer[DeviceNumber*3+2] = BLUE;

}

void setLED_ColorWipe(unsigned char RED, unsigned char GREEN, unsigned char BLUE) 
{
	unsigned char index = 0 ;

	for (index = 0; index < LED_NUM; index++)
	{
		setLED_Color(index, RED, GREEN, BLUE);
	}

	setLED_Display(LED_DATA_LEN);
}


void setLED_ColorIdxChange(void)
{
	static unsigned char flag = 1;

	if (flag)		//reverse color index
	{
		if ( Coloridx >= (COLORTALBE_NUM-1))
		{
			flag = 0;
			Coloridx = COLORTALBE_NUM-1;
		}
		else
		{
			Coloridx++;
		}
	}
	else
	{
		if (Coloridx <= 0)
		{
			flag = 1;
			Coloridx = 0;	
		}
		else
		{
			Coloridx--;
		}
	}
	
}

//https://github.com/fduignan/NucleoF042_SingleWS2812B/blob/master/main.c
void _stripEffect_Rainbow(unsigned char* RED, unsigned char* GREEN, unsigned char* BLUE)	
{   
	// Cycle through the colours of the rainbow (non-uniform brightness however)
	// Inspired by : http://academe.co.uk/2012/04/arduino-cycling-through-colours-of-the-rainbow/
	
	static unsigned char Red = 255;
	static unsigned char Green = 0;
	static unsigned char Blue = 0;
	static unsigned char State = 0;
	switch (State)
	{
		case 0:{
			Green++;
			if (Green == 255)
				State = 1;
			break;
		}
		case 1:{
			Red--;
			if (Red == 0)
				State = 2;
			break;
		}
		case 2:{
			Blue++;
			if (Blue == 255)
				State = 3;			
			break;
		}
		case 3:{
			Green--;
			if (Green == 0)
				State = 4;
			break;
		}
		case 4:{
			Red++;
			if (Red == 255)
				State = 5;
			break;
		}
		case 5:{
			Blue --;
			if (Blue == 0)
				State = 0;
			break;
		}		
	}

	*GREEN = Green;
	*RED = Red;
	*BLUE = Blue;	
//	return (Green << 16) + (Red << 8) + Blue;


}

unsigned char _stripEffect_Wheel(unsigned char WheelPos , unsigned char* RED, unsigned char* GREEN, unsigned char* BLUE) 
{
	WheelPos = 255 - WheelPos;
	if(WheelPos < 85) 
	{
		*GREEN = 0;
		*RED = 255 - WheelPos * 3;
		*BLUE = WheelPos * 3;
		return 0;
		
//		return PACK_RGB(255 - WheelPos * 3, 0, WheelPos * 3);
	}
	if(WheelPos < 170) 
	{
		WheelPos -= 85;

		*GREEN = WheelPos * 3;
		*RED = 0;
		*BLUE = 255 - WheelPos * 3;
		return 0;
		
//		return PACK_RGB(0, WheelPos * 3, 255 - WheelPos * 3);
	}
	
	WheelPos -= 170;

	*GREEN = 255 - WheelPos * 3;
	*RED = WheelPos * 3;
	*BLUE = 0;
	return 0;
	
//	return PACK_RGB(WheelPos * 3, 255 - WheelPos * 3, 0);
}

void getFromAToB(unsigned int time, unsigned int steps, 
		unsigned char redA,	unsigned char greenA, unsigned char blueA, 
		unsigned char redB, unsigned char greenB, unsigned char blueB) 
{
	unsigned int i = 0;
	signed int deltaRed, deltaGreen, deltaBlue;

	deltaRed = ((signed long) redB - (signed long) redA) / (signed long) steps;
	deltaGreen = ((signed long) greenB - (signed long) greenA) / (signed long) steps;
	deltaBlue = ((signed long) blueB - (signed long) blueA) / (signed long) steps;

	for (i = 0; i < steps; i++) 
	{
		setLED_ColorWipe(redA + i * deltaRed, greenA + i * deltaGreen,	+blueA + i * deltaBlue);
	
		setLED_delayus(time / steps);
	}
}

void getCircularRing(unsigned int time, unsigned char red, unsigned char green,unsigned char blue) 
{
	unsigned char index = 0 ;

	for (index = 0; index < LED_NUM; index++) 
	{
		setLED_ColorWipe(0, 0, 0);
		
		setLED_Color(index, red, green, blue);

    	setLED_Display(LED_DATA_LEN);

		setLED_delayms(time);
	}
}

// the interval should be in the 300-1000 range for best visual effect
void getHeartBeat(unsigned int time, unsigned char red, unsigned char green,unsigned char blue) 
{
	unsigned char redInc, greenInc, blueInc;
	unsigned char maxRed, maxGreen, maxBlue;

	unsigned char index = 0 ;
	unsigned char beatcnt = 35 ;
	
	redInc = red / HEARTBEAT_STEPS;
	greenInc = green / HEARTBEAT_STEPS;
	blueInc = blue / HEARTBEAT_STEPS;

	maxRed = redInc * (HEARTBEAT_STEPS - 1);
	maxGreen = greenInc * (HEARTBEAT_STEPS - 1);
	maxBlue = blueInc * (HEARTBEAT_STEPS - 1);

	setLED_ColorWipe(0, 0, 0);

	// first stroke
	for (index = 0; index < HEARTBEAT_STEPS; index++) 
	{
		setLED_ColorWipe(index * redInc, index * greenInc, index * blueInc);
	
		setLED_delayus(time / (beatcnt+15));	//50
	}
	for (index = 0; index < HEARTBEAT_STEPS; index++) 
	{
		setLED_ColorWipe(maxRed - index * redInc, maxGreen - index * greenInc,maxBlue - index * blueInc);
		
		setLED_delayus(time / (beatcnt+10));	//45
	}
	
	// second stroke
	for (index = 0; index < HEARTBEAT_STEPS; index++) 
	{
		setLED_ColorWipe(index * redInc, index * greenInc, index * blueInc);
		
		setLED_delayus(time / (beatcnt+5));	//40
	}
	for (index = 0; index < HEARTBEAT_STEPS; index++) 
	{
		setLED_ColorWipe(maxRed - index * redInc, maxGreen - index * greenInc,maxBlue - index * blueInc);
		
		setLED_delayus(time / (beatcnt));	//35
	}
	// relax..
	setLED_delayms(time);

}

#if defined (ENABLE_EXTRA_DEMO)
void getAllColors(unsigned int time) 
{
	unsigned int index = 0 ;
	unsigned char led = 0;

	for (index = 0;index < COLORTALBE_NUM;index++)
	{
		#if 1
		for (led = 0; led < LED_NUM; led++)
		{
			setLED_Color(led,colorsFull[index][0],colorsFull[index][1],colorsFull[index][2]);			
		}
	
		#else
		for (led = 0; led < LED_NUM; led++)
		{
			setLED_Color(led,colorsFull[index + led][0],colorsFull[index + led][1],colorsFull[index + led][2]);
			
		}
	
		if ((index + led) >= COLORTALBE_NUM)
			index = 0;
		#endif

		setLED_Display(LED_DATA_LEN);
		
		setLED_delayms(time);
	}
}

void getColorWheel(unsigned int time) 
{
	unsigned int index = 0 ;
	unsigned char led = 0, colorIndex = 0;

	for (led = 0; led < LED_NUM; led++) 
	{
		colorIndex = (index + led * (COLORTALBE_NUM / LED_NUM)) % COLORTALBE_NUM;
		
		setLED_Color(led, colorsFull[colorIndex][0],	colorsFull[colorIndex][1], colorsFull[colorIndex][2]);

		setLED_Display(LED_DATA_LEN);

		setLED_delayms(time);	

		index += (COLORTALBE_NUM / LED_NUM);
		index %= COLORTALBE_NUM;		
	}
}
#endif /*ENABLE_EXTRA_DEMO*/

void getPatternMove(unsigned int time, unsigned int parts, unsigned char red,unsigned char green, unsigned char blue) 
{
	unsigned char index = 0 ;
	unsigned int indexStep;
	unsigned int i;

	indexStep = LED_NUM / parts;

	setLED_ColorWipe(0, 0, 0);

	for (index = 0; index < LED_NUM; index++) 
	{
		setLED_ColorWipe(0, 0, 0);
		
		for (i = 0; i < parts; i++)
		{
			setLED_Color(index + i * indexStep, red, green, blue);
		}

		setLED_Display(LED_DATA_LEN);
		
		setLED_delayms(time);
	}	
}

void getFullEmpty(unsigned int time, unsigned char red, unsigned char green,unsigned char blue) 
{
	unsigned char index = 0 ;

	setLED_ColorWipe(0, 0, 0);

	for (index = 0; index < LED_NUM; index++) 
	{
		setLED_Color(index, red, green, blue);

		setLED_Display(LED_DATA_LEN);
		
		setLED_delayms(time);
	}

	for (index = 0; index < LED_NUM; index++) 
	{
		setLED_Color(index,0, 0, 0);

		setLED_Display(LED_DATA_LEN);
		
		setLED_delayms(time);
	}
}

void getAlternateColors(unsigned int time, unsigned int steps,
		unsigned char redA, unsigned char greenA, unsigned char blueA, 
		unsigned char redB, unsigned char greenB, unsigned char blueB) 
{
	unsigned int i = 0;
	signed long  deltaRed, deltaGreen, deltaBlue;

	deltaRed = ((signed long) redB - (signed long) redA) / steps;
	deltaGreen = ((signed long) greenB - (signed long) greenA) / steps;
	deltaBlue = ((signed long) blueB - (signed long) blueA) / steps;

	for (i = 0; i < steps; i++) 
	{
		setLED_ColorWipe(redA + i * deltaRed, greenA + i * deltaGreen,	+blueA + i * deltaBlue);

		setLED_delayus(time / steps);
	}
	for (i = steps - 1; i > 0; i--) 
	{
		setLED_ColorWipe(redA + i * deltaRed, greenA + i * deltaGreen,	+blueA + i * deltaBlue);
		
		setLED_delayus(time / steps);
	}
}


void getRGBSequence(unsigned int time) 
{
	static unsigned char intensity = 0;
	static unsigned char sign = 0;

    unsigned char i = 0;
    if (sign) 
	{
        intensity++;
        if (intensity == 255) 
            sign = 0; 
    }
    else 
	{
        intensity--;
        if (intensity == 0)
            sign = 1;
    }

    for (i = 0; i < LED_NUM; i++) 
	{
        setLED_Color(i, intensity*((i%3)%2),intensity*(((i+1)%3)%2),intensity*(((i+2)%3)%2));

	    setLED_Display(LED_DATA_LEN);
		
	    setLED_delayus(time);			
    }

}

void getTheaterChaseRainbow(unsigned int time) 
{
	unsigned int j = 0;
	unsigned char q = 0; 
	unsigned int i=0;
	unsigned char red , green, blue = 0;
	
	for (j=0; j < 256; j++) 
	{     // cycle all 256 colors in the wheel
		for (q=0; q < 3; q++) 
		{
			for (i=0; i < LED_NUM ; i=i+3) 
			{				
				_stripEffect_Wheel(( (i+j) % 255),&red,&green,&blue);
				setLED_Color(i+q, red,green,blue);
			
//				setLED_Color(i+q, 
//					UNPACK_R(_stripEffect_Wheel( (i+j) % 255)),
//					UNPACK_G(_stripEffect_Wheel( (i+j) % 255)),
//					UNPACK_B(_stripEffect_Wheel( (i+j) % 255)));    //turn every third pixel on
			}
			setLED_Display(LED_DATA_LEN);

			setLED_delayms(time);

			for (i=0; i < LED_NUM ; i=i+3) 
			{
				setLED_Color(i+q, 0 , 0 , 0);        //turn every third pixel off
			}
		}
	}
}

void getTheaterChase(unsigned int time ,unsigned char RED, unsigned char GREEN, unsigned char BLUE) 
{
	unsigned int j = 0;
	unsigned int q = 0;
	unsigned int i = 0;

	for (j=0; j<10; j++) 
	{  //do 10 cycles of chasing
		for (q=0; q < 3; q++) 
		{
			for (i=0; i < LED_NUM; i=i+3) 
			{
				setLED_Color(i+q, RED,GREEN,BLUE);    //turn every third pixel on
			}
			setLED_Display(LED_DATA_LEN);

			setLED_delayms(time);

			for (i=0; i < LED_NUM; i=i+3) 
			{
				setLED_Color(i+q, 0 , 0 , 0);        //turn every third pixel off
			}
		}
	}
}


void getRainbowCycle(unsigned char cycle , unsigned int time) 
{
	unsigned int i = 0, j = 0;
	unsigned char red , green, blue = 0;
	
	for(j=0; j<256*cycle; j++) 
	{ 
		// 5 cycles of all colors on wheel
		for(i=0; i< LED_NUM; i++) 
		{
			_stripEffect_Wheel((((i * 256 / LED_NUM) + j) & 255),&red,&green,&blue);
			setLED_Color(i,red,green,blue);
		
//			setLED_Color(i, 
//				UNPACK_R(_stripEffect_Wheel(((i * 256 / LED_NUM) + j) & 255)),
//				UNPACK_G(_stripEffect_Wheel(((i * 256 / LED_NUM) + j) & 255)),
//				UNPACK_B(_stripEffect_Wheel(((i * 256 / LED_NUM) + j) & 255)));
		}
		
		setLED_Display(LED_DATA_LEN);

		setLED_delayms(time);
	}
}

void getRainbow(unsigned int time)
{
	unsigned char i = 0;
	unsigned char red , green, blue = 0;

	for (i=0;i<LED_NUM;i++)
	{
		_stripEffect_Rainbow(&red,&green,&blue);
		setLED_Color(i,red,green,blue); // Output a colour Format: GGRRBB							
	}
	
	// Now send out the bits to the SPI bus
	setLED_Display(LED_DATA_LEN);  	

	setLED_delayms(time);	
}

void getBreathing(unsigned int time)
{
//	unsigned char i = 0;
	unsigned int j = 0;
	static unsigned char flag = 1;
	unsigned char led = 0;
	unsigned int index = 0 ;
	unsigned char red,green,blue = 0;

	red = colorsFull[index][0];
	green = colorsFull[index][1];
	blue = colorsFull[index][2];
	
	if (flag)
	{
		for (led = 0; led < LED_NUM; led++)
		{
			setLED_Color(led,red,green,blue);			
		}
		setLED_Display(LED_DATA_LEN);
		setLED_delayms(time);	
		flag = 0;
	}
	else
	{
		for (j=0xFF;j>0x7F;j--)
		{
			setLED_ColorWipe(j,j,j);
			setLED_delayms(time);
		}
		flag = 1;
	}

	if ((index++) > COLORTALBE_NUM)
	{
		index = 0;
	}
	
}

void StateMachine(void)
{
//	if (DemoState++ >= state_Max)
//	{
//		DemoState = state_Default+1;
//	}
//	DemoState = 0;	//quick test

	switch(DemoState)
	{
		case state_Rainbow:
			getRainbow(50);
			setLED_delayms(48);	
			break;

		case state_RainbowCycle:
			getRainbowCycle(2 ,10);	//(5 , 1000);
//			setLED_delayms(120);
			break;

		case state_TheaterChase:
			getTheaterChase(30,colorsFull[Coloridx][0], colorsFull[Coloridx][1], colorsFull[Coloridx][2]);
//			getTheaterChase(60,0x00,0xFF,0x00);
//			getTheaterChase(60,0x00,0x00,0xFF);
//			setLED_delayms(120);

			setLED_ColorIdxChange();
			break;

		case state_TheaterChaseRainbow:
			getTheaterChaseRainbow(1);
			setLED_delayms(240);
			break;

		case state_RGBSequence:
			getRGBSequence(60);

			break;
		
		case state_AlternateColors:
			getAlternateColors(128*500, 128, colorsFull[Coloridx][0], colorsFull[Coloridx][1], colorsFull[Coloridx][2], colorsFull[Coloridx][0], colorsFull[Coloridx][1], colorsFull[Coloridx][2]);

			setLED_ColorIdxChange();
			break;

		case state_FullEmpty:
			getFullEmpty(30, colorsFull[Coloridx][0], colorsFull[Coloridx][1], colorsFull[Coloridx][2]);

			setLED_ColorIdxChange();
			break;
		
		case state_PatternMove:
			getPatternMove(50, 10, colorsFull[Coloridx][0], colorsFull[Coloridx][1], colorsFull[Coloridx][2]);

			setLED_ColorIdxChange();
			break;

		#if defined (ENABLE_EXTRA_DEMO)
		case state_ColorWheel:
			getColorWheel(60);
			
			setLED_ColorWipe(0, 0, 0);
			setLED_delayms(120);
			break;

		case state_AllColors:
			getAllColors(10);	
			break;
		#endif	/*ENABLE_EXTRA_DEMO*/

		case state_HeartBeat:
			getHeartBeat(900, colorsFull[Coloridx][0], colorsFull[Coloridx][1], colorsFull[Coloridx][2]);

			setLED_ColorIdxChange();
			break;	

		case state_CircularRing:
			getCircularRing(30, colorsFull[Coloridx][0], colorsFull[Coloridx][1], colorsFull[Coloridx][2]);
	
			setLED_ColorIdxChange();
			break;	
		
		case state_FromAToB:
			getFromAToB(512, 16, colorsFull[Coloridx][0], colorsFull[Coloridx][1], colorsFull[Coloridx][2], colorsFull[Coloridx][0], colorsFull[Coloridx][1], colorsFull[Coloridx][2]);
		
			setLED_ColorIdxChange();
			break;	
			
	}

//	setLED_delayms(DEMO_MS);
}


