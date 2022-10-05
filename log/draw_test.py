import numpy as np
import matplotlib.pyplot as plt

## 分析三种不同数据分布下
bf_normal_10_fault = [0.0501744,0.116561,0.218971,0.32535,0.412826,0.478414,0.526181,0.560741,0.585805,0.603946]
bf_normal_10_time = [12.453350,13.156952,12.776411,11.747227,10.907249,10.519753,10.491654,10.402070,10.158734,10.179031]
bf_normal_10_total_time = 112.792435

shbf_normal_10_fault = [0.0208427,0.0877189,0.198049,0.309726,0.400243,0.467821,0.517022,0.552683,0.57862,0.597468]
shbf_normal_10_time = [7.267720,7.474548,6.957137,6.317542,5.861423,5.656612,5.560432,5.541547,5.586621,5.514173]
shbf_normal_10_total_time = 61.737755

sbf_normal_10_fault = [0.0084226,0.0166854,0.0251601,0.0342685,0.0439226,0.0539316,0.0641078,0.0743501,0.0845913,0.094801]
sbf_normal_10_time = [15.517026,17.016041,17.581139,18.034737,18.532274,18.872499,19.079689,19.259996,19.472090,19.487074]
sbf_normal_10_total_time = 182.852570

bf_uniform_10_fault = [0.0466888,0.0983427,0.168508,0.23723,0.290739,0.327679,0.351164,0.364769,0.371412,0.373114]
bf_uniform_10_time = [11.665179,12.138787,11.726726,10.949106,10.328981,9.978875,9.794610,9.700789,9.628742,9.516160]
bf_uniform_10_total_time = 105.427963

shbf_uniform_10_fault = [0.0186727,0.0704773,0.147958,0.22177,0.278287,0.31727,0.342193,0.356855,0.36434,0.366722]
shbf_uniform_10_time = [6.652459,6.900276,6.583858,6.226213,5.724319,5.579433,5.492511,5.393309,5.376001,5.380808]
shbf_uniform_10_total_time = 59.309189

sbf_uniform_10_fault = [0.0084839,0.0179076,0.0297161,0.0448562,0.0627894,0.0825238,0.103184,0.124116,0.144846,0.165193]
sbf_uniform_10_time = [14.806804,16.115723,16.468330,16.990108,17.552555,17.646690,17.940037,18.093271,17.506777,17.578527]
sbf_uniform_10_total_time = 170.698822

bf_exp_10_fault = [0.0001741,0.0001174,9.12333e-05,7.68e-05,6.692e-05,5.96333e-05,5.38286e-05,4.93625e-05,4.56111e-05,4.263e-05]
bf_exp_10_time = [7.217769,7.136827,7.054571,7.049487,7.046354,7.046502,7.065167,7.067794,7.041849,7.048447]
bf_exp_10_total_time = 70.774765

shbf_exp_10_fault = [1.38e-05,1.205e-05,1.05333e-05,9.575e-06,8.8e-06,8.33333e-06,7.61429e-06,7.0625e-06,6.74444e-06,6.42e-06]
shbf_exp_10_time = [3.787614,3.690950,3.690582,3.685672,3.687377,3.675326,3.681273,3.670426,3.699837,3.696262]
shbf_exp_10_total_time = 36.965321

sbf_exp_10_fault = [0.0035862,0.00423185,0.00461113,0.00487573,0.00508804,0.00526667,0.00542531,0.00557393,0.00570731,0.00582776]
sbf_exp_10_time = [9.469579,9.462499,9.488126,9.477535,9.488874,9.485149,9.635351,9.506349,9.549648,9.584467]
sbf_exp_10_total_time = 95.147575

## 均匀分布下不同K值的影响
bf_uniform_2_fault = [0.0486792,0.089305,0.122068,0.14775,0.167478,0.182219,0.192927,0.20034,0.20513,0.207822]
bf_uniform_2_total_time = 31.498360
shbf_uniform_2_fault = [0.0161228,0.040139,0.0650049,0.0877742,0.107229,0.123261,0.135999,0.145791,0.153109,0.158312]
shbf_uniform_2_total_time = 31.254045
sbf_uniform_2_fault = [0.008536,0.017821,0.0277093,0.0380609,0.0487229,0.0595457,0.0704681,0.0813361,0.0920494,0.102605]
sbf_uniform_2_total_time = 52.601341

bf_uniform_4_fault = [0.046863,0.08731,0.123935,0.155984,0.18278,0.204159,0.220466,0.23235,0.240558,0.245708]
bf_uniform_4_total_time = 50.939747
shbf_uniform_4_fault = [0.01842,0.0515303,0.0892901,0.12503,0.155692,0.180522,0.199763,0.214021,0.224196,0.230979]
shbf_uniform_4_total_time = 37.733498
sbf_uniform_4_fault = [0.0084905,0.0176541,0.0275682,0.0383102,0.0498452,0.0619998,0.0746188,0.0875142,0.100479,0.113456]
sbf_uniform_4_total_time = 78.093987

bf_uniform_6_fault = [0.0465465,0.0883887,0.131817,0.173763,0.21021,0.239277,0.260982,0.276226,0.286267,0.292104]
bf_uniform_6_total_time = 68.909073
shbf_uniform_6_fault = [0.0182381,0.0556113,0.10345,0.150848,0.191643,0.223952,0.247986,0.264988,0.27635,0.283244]
shbf_uniform_6_total_time = 43.646214
sbf_uniform_6_fault = [0.0084838,0.0176606,0.0278996,0.0395779,0.0527218,0.067071,0.0822833,0.098015,0.113884,0.12978]
sbf_uniform_6_total_time = 107.684067

bf_uniform_8_fault = [0.0464994,0.0915893,0.145893,0.20078,0.247034,0.281858,0.30609,0.32176,0.33097,0.335313]
bf_uniform_8_total_time = 87.472832
shbf_uniform_8_fault = [0.0184021,0.0618335,0.123157,0.184055,0.234256,0.271623,0.29756,0.314439,0.32456,0.329598]
shbf_uniform_8_total_time = 50.897881
sbf_uniform_8_fault = [0.008482,0.0177286,0.0285372,0.0416424,0.0569482,0.0738892,0.0918747,0.11036,0.12887,0.14723]
sbf_uniform_8_total_time = 138.348267

bf_uniform_12_fault = [0.0468744,0.107277,0.195035,0.274697,0.331267,0.367146,0.388004,0.398599,0.402363,0.40147]
bf_uniform_12_total_time = 121.272774
shbf_uniform_12_fault = [0.0191599,0.0820161,0.177477,0.261765,0.321058,0.358687,0.380753,0.392264,0.396736,0.396405]
shbf_uniform_12_total_time = 63.658051
sbf_uniform_12_fault = [0.0084845,0.0181434,0.0311867,0.0484811,0.0688556,0.0909149,0.113646,0.136385,0.158642,0.180296]
sbf_uniform_12_total_time = 199.883728

bf_uniform_14_fault = [0.0472531,0.119809,0.225648,0.312529,0.368822,0.401779,0.419211,0.426629,0.427639,0.424405]
bf_uniform_14_total_time = 139.090561
shbf_uniform_14_fault = [0.0197928,0.0964623,0.209781,0.300812,0.35949,0.39403,0.412578,0.420827,0.422488,0.419772]
shbf_uniform_14_total_time = 71.033112
sbf_uniform_14_fault = [0.0084868,0.0184874,0.0330235,0.0525283,0.0751116,0.0991015,0.123436,0.147504,0.170881,0.193485]
sbf_uniform_14_total_time = 236.876572


# 1. 三种数据集分布 - FPR
plt.figure(figsize=(15,5))

plt.subplot(131)
plt.plot(bf_normal_10_fault, color='r', marker='o', linewidth=2, label='bloom filter')
plt.plot(shbf_normal_10_fault, color='g', marker='o', linewidth=2, label='shifting bloom filter')
plt.plot(sbf_normal_10_fault, color='b', marker='o', linewidth=2, label='spatial bloom filter')
plt.title('Normal Distribution')
plt.xlabel('Data x1e7')
plt.ylabel('FPR')
plt.legend()

plt.subplot(132)
plt.plot(bf_uniform_10_fault, color='r', marker='o', linewidth=2, label='bloom filter')
plt.plot(shbf_uniform_10_fault, color='g', marker='o', linewidth=2, label='shifting bloom filter')
plt.plot(sbf_uniform_10_fault, color='b', marker='o', linewidth=2, label='spatial bloom filter')
plt.title('Uniform Distribution')
plt.xlabel('Data x1e7')
plt.ylabel('FPR')
plt.legend()

plt.subplot(133)
plt.plot(bf_exp_10_fault, color='r', marker='o', linewidth=2, label='bloom filter')
plt.plot(shbf_exp_10_fault, color='g', marker='o', linewidth=2, label='shifting bloom filter')
plt.plot(sbf_exp_10_fault, color='b', marker='o', linewidth=2, label='spatial bloom filter')
plt.title('Exponential Distribution')
plt.xlabel('Data x1e7')
plt.ylabel('FPR')
plt.legend()

plt.show()


# 2. 三种数据集分布 - 时间
size = 3
# 返回size个0-1的随机数
a = [bf_normal_10_total_time, bf_uniform_10_total_time, bf_exp_10_total_time]
b = [shbf_normal_10_total_time, shbf_uniform_10_total_time, shbf_exp_10_total_time]
c = [sbf_normal_10_total_time, sbf_uniform_10_total_time, sbf_exp_10_total_time]
x = np.arange(size)
x_labels = ["Normal Distribution", "Uniform Distribution", "Exponential Distribution"]
# 有a/b/c三种类型的数据，n设置为3
total_width, n = 0.6, 3
# 每种类型的柱状图宽度
width = total_width / n
# 重新设置x轴的坐标
x = x - (total_width - width) / 2
# 画柱状图
plt.bar(x, a, width=width, label="bloom filter")
plt.bar(x + width, b, width=width, label="shifting bloom filter")
plt.bar(x + 2*width, c, width=width, label="spatial bloom filter")
for i, j in zip(x, a):
    plt.text(i, j + 0.01, "%.1f" % j, ha="center", va="bottom", fontsize=10)
for i, j in zip(x + width, b):
    plt.text(i, j + 0.01, "%.1f" % j, ha="center", va="bottom", fontsize=10)
for i, j in zip(x + 2 * width, c):
    plt.text(i, j + 0.01, "%.1f" % j, ha="center", va="bottom", fontsize=10)
plt.title('Total Time Analysis')
plt.xticks(x+width, x_labels)
plt.ylabel('Total Time (s)')
plt.legend()
plt.show()


# 3. 不同 K 的 FPR曲线图
plt.figure(figsize=(10, 5))
x = [2, 4, 6, 8, 10, 12, 14]
bf_uniform_fault = [bf_uniform_2_fault[1], bf_uniform_4_fault[1], bf_uniform_6_fault[1], bf_uniform_8_fault[1], bf_uniform_10_fault[1], bf_uniform_12_fault[1], bf_uniform_14_fault[1]]
shbf_uniform_fault = [shbf_uniform_2_fault[1], shbf_uniform_4_fault[1], shbf_uniform_6_fault[1], shbf_uniform_8_fault[1], shbf_uniform_10_fault[1], shbf_uniform_12_fault[1], shbf_uniform_14_fault[1]]
sbf_uniform_fault = [sbf_uniform_2_fault[1], sbf_uniform_4_fault[1], sbf_uniform_6_fault[1], sbf_uniform_8_fault[1], sbf_uniform_10_fault[1], sbf_uniform_12_fault[1], sbf_uniform_14_fault[1]]

plt.subplot(121)
plt.plot(x, bf_uniform_fault, color='r', marker='o', linewidth=2, label='bloom filter')
plt.plot(x, shbf_uniform_fault, color='g', marker='o', linewidth=2, label='shifting bloom filter')
plt.plot(x, sbf_uniform_fault, color='b', marker='o', linewidth=2, label='spatial bloom filter')
plt.title('The FPR effect of K under Uniform Distribution')
plt.xlabel('K')
plt.ylabel('FPR')
plt.legend()

bf_uniform_time = [bf_uniform_2_total_time, bf_uniform_4_total_time, bf_uniform_6_total_time, bf_uniform_8_total_time, bf_uniform_10_total_time, bf_uniform_12_total_time, bf_uniform_14_total_time]
shbf_uniform_time = [shbf_uniform_2_total_time, shbf_uniform_4_total_time, shbf_uniform_6_total_time, shbf_uniform_8_total_time, shbf_uniform_10_total_time, shbf_uniform_12_total_time, shbf_uniform_14_total_time]
sbf_uniform_time = [sbf_uniform_2_total_time, sbf_uniform_4_total_time, sbf_uniform_6_total_time, sbf_uniform_8_total_time, sbf_uniform_10_total_time, sbf_uniform_12_total_time, sbf_uniform_14_total_time]

plt.subplot(122)
plt.plot(x, bf_uniform_time, color='r', marker='o', linewidth=2, label='bloom filter')
plt.plot(x, shbf_uniform_time, color='g', marker='o', linewidth=2, label='shifting bloom filter')
plt.plot(x, sbf_uniform_time, color='b', marker='o', linewidth=2, label='spatial bloom filter')
plt.title('The Time effect of K under Uniform Distribution')
plt.xlabel('K')
plt.ylabel('Time (s)')
plt.legend()

plt.show()