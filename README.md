# awesome-bloom-filters

The implement of three kinds of **Bloom Filter**

- Bloom Filter
- Shifting Bloom Filter
- Spatial Bloom Filter


# 一、简介

## 1.1 Bloom Filter


## 1.2 Shifting Bloom Filter

> 论文: A Shifting Bloom Filter Framework for Set Queries
> 
> 文中提出的 ShBF 可以适用于三种集合查询方式: 成员查询、关联查询、多重查询。本项目主要实现了成员查询方式, 即判断元素是否存在在集合中。


对于数据集中的元素，我们需要存储两种信息:
- 存在性信息: 元素是否存在在集合中
- 额外信息: 计数器或者元素所在的集合

**1.构建阶段**

我们设置一个数组 B 包含 m 位, 初始化时所有位为 0。对于元素 e, 通过设置 k 个位置的值为 1 来记录信息。对于这 k 个位置, 我们设置 k/2 个位置存储<u>存在性信息</u>, 设置 k/2 个位置存储<u>额外信息</u>。通过给定偏差的方式, 在记录存在性信息的同时记录额外信息，偏差定义为如下:

$$
o(.) = h_{\frac{k}{2}+1}(.) \% (\bar{w} - 1) + 1
$$

其中, $h(.)$ 为输出符合均匀分布的哈希函数, $\bar{w}$ 是机器字长 $w$ 的函数, 将在后面介绍取值问题。由于需要在原有数据上进行偏移, 因此数组 B 的长度为 $m + max(offset) = m + o(.) = m + \bar{w}$。

对于元素 e, 我们如图所示设置如下值为 1,:

$$
B[h_1(e) \% m] = B[h_2(e) \% m] = ... = B[h_{\frac{k}{2}}(e) \% m] = \\
B[h_1(e) \% m + o(e)] = B[h_2(e) \% m + o(e)] = ... = B[h_{\frac{k}{2}}(e) \% m + o(e)] = 1
$$

![Shifting Bloom Filter](./img/ShBF.png)


**2.查询阶段**

在构建阶段一共对 k 个位置进行赋值, 因此对于一个元素 e, 计算其在这 k 个位置的值, 如果都为 1, 则该元素在集合中, 否则不在集合中。

**3.参数选择**

我们选择合适的 $\bar{w}$ 参数, 使得可以在一次内存访问操作中, 同时获取 $B[h_i(e)\% m]$ 和 $B[h_i(e)\% m + o(e)]$, 因此 $\bar{w} \le w + 1 - j, 1 \le j \le 8$, 选择 $\bar{w} \le w - 7$。

**4.优势**

ShBF 的 FPR 与有 k 个哈希函数的 BF 十分接近, 但是其性能却是 BF 的两倍。因为

- 计算成本减少了一半, 因为哈希函数的数量减少了一半。
- 内存访问次数减少了一半, ShBF 一次获取 2 个 bit, 而 BF 一次获取 1 个 bit。


## 1.3 Spatial Bloom Filter