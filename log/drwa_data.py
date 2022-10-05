import numpy as np
import matplotlib.pyplot as plt

x_normal = []
x_uniform = []
x_exp = []
cnt = 0
with open("../datasets/test_normal.txt", 'r') as f:
    for line in f:
        a = line.split(" ")[0]
        x_normal.append(int(a))
        cnt += 1
        if cnt == 1000000:
            break
cnt = 0
with open("../datasets/test_exp.txt", 'r') as f:
    for line in f:
        a = line.split(" ")[0]
        x_exp.append(int(a))
        cnt += 1
        if cnt == 1000000:
            break
cnt = 0
with open("../datasets/test_uniform.txt", 'r') as f:
    for line in f:
        a = line.split(" ")[0]
        x_uniform.append(int(a))
        cnt += 1
        if cnt == 1000000:
            break

plt.figure(figsize=(15, 5))

plt.subplot(131)
plt.hist(x_normal, 100, histtype='step', density=True)
plt.title('Normal Distribution')

plt.subplot(132)
plt.hist(x_uniform, 100, histtype='step', density=True)
plt.title('Uniform Distribution')

plt.subplot(133)
plt.hist(x_exp, 100, histtype='step', density=True)
plt.title('Exponential Distribution')

plt.show()
