

#include "measurements.hpp"
#include <iostream>


namespace {

    std::vector<std::uint32_t> meas = 
    {
        199,
        227,
        229,
        230,
        233,
        228,
        231,
        226,
        237,
        259,
        262,
        265,
        266,
        265,
        269,
        276,
        278,
        279,
        281,
        287,
        305,
        316,
        314,
        320,
        313,
        314,
        315,
        329,
        346,
        357,
        370,
        369,
        360,
        384,
        383,
        401,
        402,
        403,
        404,
        403,
        406,
        408,
        406,
        401,
        393,
        395,
        416,
        418,
        408,
        411,
        412,
        416,
        417,
        404,
        421,
        436,
        437,
        436,
        420,
        388,
        405,
        403,
        371,
        376,
        378,
        374,
        378,
        377,
        403,
        411,
        444,
        424,
        417,
        416,
        419,
        436,
        415,
        413,
        429,
        446,
        462,
        463,
        464,
        467,
        466,
        475,
        483,
        478,
        487,
        488,
        469,
        470,
        472,
        473,
        460,
        463,
        465,
        477,
        487,
        508,
        506,
        509,
        512,
        513,
        519,
        525,
        531,
        498,
        506,
        504,
        506,
        507,
        509,
        510,
        512,
        537,
        553,
        536,
        533,
        524,
        525,
        526,
        527,
        530,
        531,
        533,
        537,
        538,
        537,
        539,
        544,
        552,
        550,
        576,
        560,
        556,
        561,
        552,
        560,
        572,
        573,
        572,
        571,
        573,
        578,
        581,
        582,
        578,
        541,
        546,
        537,
        545,
        556,
        565,
        566,
        571,
        561,
        573,
        579,
        578,
        581,
        600,
        603,
        604,
        597,
        598,
        599,
        598,
        599,
        580,
        585,
        586,
        596,
        597,
        602,
        593,
        598,
        599,
        604,
        608,
        609,
        616,
        615,
        613,
        622,
        625,
        620,
        632,
        636,
        628,
        633,
        640,
        621,
        620,
        638,
        646,
        647,
        648,
        647,
        654,
        655,
        663,
        652,
        664,
        668,
        669,
        668,
        663,
        667,
        659,
        658,
        666,
        670,
        685,
        703,
        706,
        705,
        706,
        727,
        730,
        729,
        735,
        743,
        749,
        750,
        751,
        756,
        774,
        776,
        767,
        778,
        777,
        790,
        791,
        794,
        798,
        801,
        804,
        812,
        818,
        819,
        818,
        821,
        825,
        818,
        829,
        832,
        835,
        849,
        848,
        863,
        859,
        863,
        871,
        870,
        869,
        873,
        875,
        878,
        874,
        896,
        903,
        890,
        891,
        905,
        912,
        913,
        911,
        917,
        941,
        943,
        944,
        940,
        943,
        945,
        947,
        948,
        953,
        930,
        932,
        933,
        948,
        936,
        937,
        941,
        947,
        952,
        957,
        951,
        953,
        954,
        958,
        979,
        982,
        971,
        974,
        979,
        984,
        988,
        989,
        986,
        987,
        992,
        998,
        1013,
        1024,
        1022,
        1023,
        1014,
        1019,
        1042,
        1048,
        1047,
        1060,
        1056,
        1067,
        1054,
        1053,
        1061,
        1063,
        1068,
        1074,
        1104,
        1105,
        1107,
        1119,
        1126,
        1127,
        1129,
        1143,
        1145,
        1146,
        1151,
        1159,
        1183,
        1185,
        1192,
        1183,
        1185,
        1182,
        1180,
        1198,
        1215,
        1221,
        1224,
        1227,
        1230,
        1262,
        1289,
        1291,
        1294,
        1297,
        1300,
        1303,
        1321,
        1323,
        1329,
        1331,
        1341,
        1362,
        1369,
        1370,
        1388,
        1389,
        1393,
        1407,
        1386,
        1380,
        1381,
        1378,
        1398,
        1402,
        1399,
        1422,
        1433,
        1449,
        1451,
        1449,
        1462,
        1454,
        1455,
        1452,
        1471,
        1472,
        1487,
        1477,
        1459,
        1463,
        1461,
        1463,
        1473,
        1489,
        1482,
        1516,
        1527,
        1521,
        1522,
        1527,
        1529,
        1531,
        1538,
        1550,
        1553,
        1548,
        1549,
        1545,
        1548,
        1543,
        1546,
        1549,
        1572,
        1576,
        1581,
        1575,
        1584,
        1602,
        1604,
        1605,
        1606,
        1611,
        1610,
        1623,
        1618,
        1614,
        1622,
        1613,
        1608,
        1611,
        1638,
        1632,
        1643,
        1649,
        1652,
        1655,
        1652,
        1653,
        1654,
        1658,
        1659,
        1661,
        1667,
        1695,
        1710,
        1719,
        1726,
        1727,
        1725,
        1726,
        1736,
        1741,
        1763,
        1752,
        1769,
        1770,
        1767,
        1768,
        1769,
        1771,
        1799,
        1798,
        1810,
        1813,
        1816,
        1826,
        1837,
        1842,
        1841,
        1848,
        1853,
        1823,
        1836,
        1835,
        1837,
        1836,
        1839,
        1838,
        1840,
        1841,
        1839,
        1843,
        1844,
        1862,
        1873,
        1877,
        1880,
        1882,
        1881,
        1895,
        1891,
        1896,
        1899,
        1893,
        1894,
        1892,
        1894,
        1895,
        1921,
        1920,
        1922,
        1928,
        1925,
        1933,
        1943,
        1942,
        1936,
        1941,
        1919,
        1912,
        1914,
        1922,
        1918,
        1934,
        1932,
        1946,
        1949,
        1955,
        1964,
        1974,
        1977,
        1978,
        1983,
        1984,
        1986,
        1990,
        2005,
        2022,
        2026,
        2032,
        2031,
        2029,
        2031,
        2035,
        2041,
        2042,
        2043,
        2053,
        2054,
        2058,
        2062,
        2063,
        2055,
        2049,
        2021,
        2022,
        2054,
        2052,
        2084,
        2076,
        2079,
        2090,
        2088,
        2093,
        2095,
        2093,
        2091,
        2089,
        2095,
        2096,
        2102,
        2127,
        2129,
        2132,
        2117,
        2125,
        2131,
        2132,
        2126,
        2134,
        2140,
        2137,
        2138,
        2136,
        2137,
        2141,
        2153,
        2152,
        2170,
        2177,
        2147,
        2159,
        2161,
        2160,
        2173,
        2176,
        2194,
        2205,
        2206,
        2213,
        2231,
        2232,
        2242,
        2243,
        2217,
        2224,
        2225,
        2230,
        2226,
        2214,
        2212,
        2227,
        2230,
        2237,
        2238,
        2241,
        2264,
        2283,
        2288,
        2308,
        2309,
        2311,
        2312,
        2314,
        2316,
        2317,
        2318,
        2321,
        2326,
        2324,
        2325,
        2321,
        2324,
        2322,
        2325,
        2327,
        2335,
        2369,
        2370,
        2374,
        2375,
        2344,
        2347,
        2348,
        2341,
        2346,
        2355,
        2356,
        2371,
        2368,
        2370,
        2375,
        2378,
        2379,
        2370,
        2363,
        2365,
        2366,
        2363,
        2364,
        2372,
        2374,
        2392,
        2399,
        2397,
        2384,
        2400,
        2401,
        2402,
        2401,
        2400,
        2402,
        2412,
        2422,
        2423,
        2426,
        2424,
        2425,
        2421,
        2422,
        2440,
        2441,
        2451,
        2442,
        2443,
        2444,
        2446,
        2451,
        2452,
        2450,
        2458,
        2457,
        2490,
        2496,
        2506,
        2507,
        2508,
        2511,
        2531,
        2536,
        2537,
        2539,
        2529,
        2530,
        2561,
        2562,
        2592,
        2595,
        2584,
        2601,
        2603,
        2589,
        2586,
        2588,
        2586,
        2596,
        2613,
        2616,
        2618,
        2621,
        2629,
        2637,
        2638,
        2619,
        2621,
        2619,
        2631,
        2621,
        2619,
        2624,
        2628,
        2634,
        2636,
        2637,
        2626,
        2632,
        2623,
        2630,
        2629,
        2630,
        2633,
        2620,
        2629,
        2635,
        2614,
        2617,
        2612,
        2613,
        2609,
        2601,
        2604,
        2611,
        2602,
        2607,
        2611,
        2639,
        2646,
        2647,
        2618,
        2613,
        2614,
        2635,
        2642,
        2649,
        2653,
        2652,
        2628,
        2629,
        2631,
        2636,
        2639,
        2649,
        2665,
        2667,
        2666,
        2665,
        2668,
        2672,
        2673,
        2675,
        2693,
        2694,
        2696,
        2701,
        2702,
        2703,
        2700,
        2716,
        2718,
        2719,
        2718,
        2719,
        2722,
        2723,
        2715,
        2726,
        2737,
        2757,
        2758,
        2759,
        2762,
        2760,
        2765,
        2759,
        2763,
        2764,
        2774,
        2785,
        2786,
        2802,
        2803,
        2802,
        2824,
        2833,
        2834,
        2830,
        2832,
        2842,
        2828,
        2829,
        2836,
        2838,
        2813,
        2811,
        2798,
        2799,
        2796,
        2805,
        2808,
        2807,
        2811,
        2812,
        2811,
        2812,
        2793,
        2787,
        2802,
        2805,
        2804,
        2822,
        2825,
        2837,
        2835,
        2842,
        2838,
        2849,
        2840,
        2841,
        2853,
        2854,
        2863,
        2877,
        2886,
        2864,
        2866,
        2846,
        2860,
        2840,
        2842,
        2844,
        2866,
        2867,
        2870,
        2856,
        2860,
        2861,
        2860,
        2872,
        2877,
        2881,
        2883,
        2881,
        2883,
        2880,
        2881,
        2882,
        2880,
        2902,
        2903,
        2904,
        2937,
        2939,
        2938,
        2945,
        2954,
        2950,
        2966,
        2967,
        2976,
        2980,
        2982,
        2976,
        2986,
        2997,
        2996,
        2994,
        3004,
        3007,
        3008,
        3016,
        3014,
        3054,
        3078,
        3095,
        3114,
        3115,
        3120,
        3107,
        3109,
        3124,
        3140,
        3144,
        3150,
        3163,
        3165,
        3164,
        3158,
        3172,
        3175,
        3174,
        3184,
        3188,
        3198,
        3193,
        3224,
        3226,
        3227,
        3252,
        3273,
        3280,
        3289,
        3291,
        3290,
        3291,
        3279,
        3281,
        3282,
        3281,
        3298,
        3302,
        3289,
        3304,
        3295,
        3312,
        3314,
        3327,
        3328,
        3337,
        3348,
        3349,
        3340,
        3348,
        3351,
        3350,
        3351,
        3350,
        3345,
        3339,
        3343,
        3344,
        3329,
        3354,
        3356,
        3358,
        3363,
        3365,
        3373,
        3376,
        3383,
        3384,
        3388,
        3389,
        3390,
        3397,
        3398,
        3401,
        3409,
        3411,
        3412,
        3411,
        3418,
        3428,
        3430,
        3432,
        3418,
        3410,
        3418,
        3424,
        3425,
        3426,
        3430,
        3439,
        3441,
        3422,
        3423,
        3425,
        3426,
        3428,
        3429,
        3436,
        3448,
        3447,
        3443,
        3445,
        3468,
        3482,
        3483,
        3499,
        3506,
        3513,
        3518,
        3523,
        3524,
        3525,
        3529,
        3532,
        3529,
        3565,
        3577,
        3576,
        3577,
        3576,
        3539,
        3557,
        3554,
        3563,
        3562,
        3564,
        3565,
        3586,
        3583,
        3590,
        3589,
        3580,
        3581,
        3574,
        3599,
        3597,
        3609,
        3610,
        3611,
        3614,
        3613,
        3611,
        3612,
        3611,
        3598,
        3596,
        3597,
        3585,
        3568,
        3569,
        3550,
        3561,
        3563,
        3551,
        3552,
        3555,
        3553,
        3554,
        3553,
        3552,
        3555,
        3557,
        3560,
        3585,
        3591,
        3604,
        3609,
        3640,
        3641,
        3645,
        3644,
        3643,
        3646,
        3644,
        3664,
        3653,
        3660,
        3667,
        3664,
        3665,
        3668,
        3670,
        3649,
        3640,
        3639,
        3647,
        3654,
        3650,
        3648,
        3654,
        3651,
        3652,
        3653,
        3654,
        3655,
        3671,
        3660,
        3671,
        3675,
        3679,
        3680,
        3681,
        3686,
        3690,
        3691,
        3693,
        3695,
        3698,
        3697,
        3699,
        3708,
        3712,
        3714,
        3712,
        3711,
        3716,
        3731,
        3732,
        3736,
        3753,
        3755,
        3756,
        3767,
        3747,
        3746,
        3733,
        3711,
        3722,
        3718,
        3721,
        3722,
        3723,
        3724,
        3727,
        3731,
        3732,
        3741,
        3743,
        3750,
        3751,
        3738,
        3741,
        3739,
        3740,
        3756,
        3755,
        3751,
        3750,
        3755,
        3757,
        3773,
        3778,
        3781,
        3782,
        3768,
        3772,
        3766,
        3770,
        3778,
        3792,
        3798,
        3801,
        3803,
        3801,
        3812,
        3833,
        3873,
        3868,
        3865,
        3866,
        3906,
        3910,
        3897,
        3907,
        3910,
        3898,
        3914,
        3917,
        3908,
        3912,
        3920,
        3934,
        3930,
        3934,
        3935,
        3937,
        3942,
        3943,
        3948,
        3964,
        3978,
        3985,
        3986,
        3993,
        3995,
        4014,
        4021,
        4024,
        4025,
        4024,
        4027,
        4028,
        4043,
        4047,
        4049,
        4036,
        4039,
        4038,
        4037,
        4045,
        4040,
        4041,
        4043,
        4035,
        4046,
        4063,
        4054,
        4055,
        4064,
        4067,
        4060,
        4061,
        4062,
        4069,
        4070,
        4063,
        4064,
        4077,
        4065,
        4074,
        4076,
        4078,
        4091,
        4100,
        4104,
        4105,
        4106,
        4107,
        4115,
        4110,
        4112,
        4113,
        4114,
        4115,
        4092,
        4093,
        4107,
        4109,
        4108,
        4112,
        4143,
        4144,
        4145,
        4146,
        4145,
        4144,
        4126,
        4130,
        4134,
        4149,
        4151,
        4161,
        4162,
        4160,
        4146,
        4170,
        4188,
        4196,
        4194,
        4193,
        4196,
        4197,
        4198,
        4200,
        4205,
        4218,
        4228,
        4216,
        4224,
        4226,
        4241,
        4245,
        4247,
        4251,
        4245,
        4244,
        4266,
        4259,
        4262,
        4269,
        4270,
        4275,
        4281,
        4298,
        4305,
        4309,
        4311,
        4325,
        4328,
        4346,
        4347,
        4357,
        4360,
        4359,
        4357,
        4391,
        4396,
        4391,
        4397,
        4395,
        4405,
        4410,
        4412,
        4433,
        4420,
        4421,
        4422,
        4423,
        4431,
        4437,
        4447,
        4451,
        4458,
        4457,
        4458,
        4456,
        4455,
        4458,
        4460,
        4431,
        4432,
        4431,
        4441,
        4444,
        4436,
        4408,
        4406,
        4414,
        4415,
        4413,
        4422,
        4449,
        4430,
        4428,
        4397,
        4395,
        4396,
        4398,
        4396,
        4399,
        4406,
        4413,
        4422,
        4421,
        4429,
        4431,
        4430,
        4462,
        4460,
        4480,
        4482,
        4486,
        4484,
        4483,
        4497,
        4493,
        4496,
        4506,
        4504,
        4497,
        4498,
        4503,
        4513,
        4525,
        4533,
        4547,
        4560,
        4561,
        4563,
        4562,
        4572,
        4571,
        4575,
        4557,
        4561,
        4562,
        4550,
        4552,
        4543,
        4537,
        4534,
        4542,
        4561,
        4563,
        4562,
        4583,
        4582,
        4591,
        4592,
        4597,
        4601,
        4599,
        4600,
        4610,
        4601,
        4612,
        4630,
        4616,
        4619,
        4623,
        4624,
        4636,
        4638,
        4645,
        4651,
        4655,
        4660,
        4659,
        4658,
        4657,
        4658,
        4661,
        4670,
        4665,
        4656,
        4664,
        4666,
        4667,
        4669,
        4696,
        4701,
        4712,
        4711,
        4719,
        4679,
        4680,
        4686,
        4684,
        4685,
        4689,
        4682,
        4686,
        4688,
        4687,
        4688,
        4687,
        4693,
        4672,
        4670,
        4667,
        4673,
        4643,
        4644,
        4653,
        4668,
        4669,
        4672,
        4685,
        4663,
        4665,
        4672,
        4696,
        4698,
        4701,
        4699,
        4687,
        4690,
        4687,
        4684,
        4685,
        4687,
        4689,
        4685,
        4692,
        4690,
        4696,
        4702,
        4703,
        4704,
        4717,
        4718,
        4719,
        4711,
        4717,
        4719,
        4726,
        4722,
        4736,
        4735,
        4739,
        4748,
        4741,
        4738,
        4736,
        4737,
        4736,
        4740,
        4748,
        4749,
        4757,
        4760,
        4768,
        4754,
        4756,
        4772,
        4773,
        4775,
        4770,
        4766,
        4769,
        4762,
        4771,
        4773,
        4775,
        4776,
        4778,
        4782,
        4770,
        4763,
        4765,
        4764,
        4765,
        4764,
        4777,
        4780,
        4786,
        4797,
        4803,
        4812,
        4811,
        4818,
        4823,
        4820,
        4821,
        4831,
        4834,
        4862,
        4865,
        4856,
        4857,
        4863,
        4860,
        4861,
        4858,
        4846,
        4848,
        4852,
        4853,
        4854,
        4856,
        4832,
        4833,
        4832,
        4830,
        4826,
        4833,
        4851,
        4852,
        4855,
        4856,
        4857,
        4852,
        4854,
        4860,
        4863,
        4887,
        4878,
        4879,
        4880,
        4893,
        4888,
        4891,
        4892,
        4896,
        4897,
        4900,
        4905,
        4903,
        4909,
        4927,
        4942,
        4946,
        4952,
        4970,
        4971,
        4987,
        4990,
        4991,
        4990,
        4989,
        4988,
        4989,
        4995,
        4996,
        5004,
        5003,
        5005,
        5009,
        4997,
        4981,
        4977,
        4979,
        4982,
        4984,
        4994,
        5005,
        5009,
        5008,
        5036,
        5034,
        5033,
        5030,
        5032,
        5034,
        5030,
        5031,
        5034,
        5070,
        5072,
        5071,
        5073,
        5077,
        5078,
        5070,
        5084,
        5085,
        5091,
        5071,
        5080,
        5075,
        5070,
        5067,
        5072,
        5075,
        5082,
        5085,
        5091,
        5104,
        5120,
        5123,
        5122,
        5105,
        5120,
        5128,
        5116,
        5118,
        5122,
        5120,
        5140,
        5142,
        5145,
        5148,
        5152,
        5153,
        5154,
        5157,
        5172,
        5179,
        5177,
        5185,
        5191,
        5200,
        5201,
        5207,
        5205,
        5206,
        5198,
        5205,
        5186,
        5188,
        5197,
        5194,
        5203,
        5204,
        5205,
        5208,
        5214,
        5220,
        5219,
        5224,
        5227,
        5241,
        5233,
        5253,
        5283,
        5287,
        5291,
        5289,
        5296,
        5297,
        5294,
        5288,
        5289,
        5290,
        5278,
        5290,
        5288,
        5294,
        5295,
        5294,
        5292,
        5289,
        5299,
        5283,
        5285,
        5290,
        5289,
        5291,
        5302,
        5304,
        5305,
        5315,
        5316,
        5323,
        5337,
        5341,
        5345,
        5346,
        5358,
        5361,
        5367,
        5348,
        5354,
        5344,
        5339,
        5342,
        5341,
        5354,
        5356,
        5355,
        5354,
        5355,
        5356,
        5342,
        5348,
        5350,
        5351,
        5355,
        5378,
        5380,
        5404,
        5405,
        5407,
        5417,
        5419,
        5411,
        5412,
        5413,
        5416,
        5420,
        5391,
        5377,
        5386,
        5387,
        5390,
        5383,
        5385,
        5384,
        5390,
        5389,
        5390,
        5409,
        5414,
        5424,
        5427,
        5428,
        5430,
        5443,
        5435,
        5430,
        5427,
        5428,
        5422,
        5452,
        5460,
        5464,
        5465,
        5472,
        5473,
        5481,
        5480,
        5481,
        5482,
        5483,
        5493,
        5495,
        5492,
        5501,
        5517,
        5519,
        5527,
        5532,
        5529,
        5532,
        5542,
        5532,
        5550,
        5551,
        5560,
        5543,
        5549,
        5555,
        5554,
        5555,
        5552,
        5562,
        5563,
        5564,
        5566,
        5568,
        5571,
        5549,
        5556,
        5557,
        5563,
        5564,
        5567,
        5563,
        5570,
        5559,
        5580,
        5585,
        5568,
        5569,
        5562,
        5578,
        5579,
        5565,
        5567,
        5583,
        5584,
        5592,
        5590,
        5593,
        5595,
        5594,
        5597,
        5582,
        5588,
        5594,
        5596,
        5598,
        5597,
        5595,
        5605,
        5593,
        5590,
        5599,
        5603,
        5597,
        5632,
        5621,
        5624,
        5628,
        5634,
        5662,
        5663,
        5666,
        5674,
        5678,
        5677,
        5678,
        5679,
        5680,
        5681,
        5687,
        5690,
        5685,
        5684,
        5683,
        5689,
        5690,
        5691,
        5689,
        5694,
        5698,
        5701,
        5698,
        5733,
        5757,
        5767,
        5794,
        5812,
        5804,
        5802,
        5810,
        5826,
        5856,
        5855,
        5860,
        5861,
        5846,
        5865,
        5885,
        5874,
        5883,
        5888,
        5892,
        5894,
        5877,
        5840,
        5841,
        5814,
        5815,
        5818,
        5821,
        5822,
        5819,
        5818,
        5842,
        5849,
        5850,
        5851,
        5854,
        5856,
        5854,
        5851,
        5864,
        5866,
        5867,
        5871,
        5874,
        5879,
        5888,
        5886,
        5890,
        5894,
        5889,
        5875,
        5863,
        5847,
        5857,
        5853,
        5858,
        5859,
        5862,
        5867,
        5862,
        5866,
        5874,
        5875,
        5894,
        5897,
        5877,
        5886,
        5887,
        5891,
        5881,
        5886,
        5885,
        5886,
        5887,
        5888,
        5892,
        5891,
        5903,
        5902,
        5901,
        5902,
        5903,
        5908,
        5905,
        5912,
        5914,
        5920,
        5927,
        5916,
        5917,
        5918,
        5921,
        5931,
        5939,
        5942,
        5943,
        5949,
        5962,
        5990,
        5985,
        5982,
        5980,
        5979,
        5990,
        5995,
        6012,
        6029,
        6038,
        6050,
        6051,
        6057,
        6052,
        6061,
        6060,
        6050,
        6058,
        6059,
        6060,
        6064,
        6065,
        6092,
        6091,
        6090,
        6089,
        6085,
        6101,
        6107,
        6110,
        6109,
        6120,
        6117,
        6110,

    };
}

int main (void)
{

    std::cout << "The following measurements are larger than the previous: " << measurements::getNumberOfIncreases(::meas) << std::endl;
    std::cout << "The following window measurments are larger than the previous: " << measurements::getNumberOfIncreasesWindow(::meas) << std::endl;

    return 0;
}