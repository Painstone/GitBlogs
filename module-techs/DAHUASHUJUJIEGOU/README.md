# 《大话数据结构》 程杰 著

![](IMG_6195.jpg)

## 书评
这本书成书于《大话设计模式》之后，同为程杰所著。需要注意的是，清华大学出版社 还有一本《大话数据库》，这本不是程杰所著，不要弄混了（不要问我是怎么知道的）。

## 第 1 章 数据结构绪论

数据结构是一门研究非数值计算的程序设计问题中的操作对象，以及它们之间的关系和操作等相关问题的学科。

- 数据：是描述客观事物的符号，是计算机中可以操作的对象，是能被计算机识别，并输入给计算机处理的符号集合。
- 数据元素：是组成数据的、有一定存在意义的基本单位，在计算机中通常作为整体处理。也被称为记录。
- 数据项：一个数据元素可以由若干个数据项组成（数据项是数据不可分割的最下单位）。
- 数据对象：是性质相同的数据元素的集合，是数据的子集。
- 数据结构：是相互之间存在的一种或多种特定关系的数据元素的集合。

逻辑结构：集合结构、线性结构、树形结构、图形结构；    

物理结构：顺序存储结构、链式存储结构；

数据类型：是指一组性质相同的值的集合及定义在此集合上的一些操作的总称。

抽象数据类型（Abstract Data Type, ADT）：是指一个数学模型及定义在该模型上的一组操作。

## 第 2 章 算法

算法是解决特定问题求解步骤的描述，在计算机中表现为指令的有限序列，并且每条指令表示一个或多个操作。

算法的特性：输入、输出、有穷性、确定性和可行性。

算法设计的要求：

- 正确性：算法的正确性是指算法至少应该具有输入、输出和加工处理无歧义性、能正确反映问题的需求、能够得到问题的正确答案。
- 可读性：算法设计的另一目的是为了便于阅读、理解和交流。
- 健壮性：当输入不合法时，算法也能做出相关处理，而不是产生异常或莫名其妙的结果。

### 2.9 算法时间复杂度

定义：在进行算法分析时，语句的执行次数 T(N) 是关于问题规模 n 的函数，进而分析 T(n) 随 n 的变化情况并确定 T(n) 的数量级。算法的时间复杂度，也就是算法的时间量度，记作：T(n) = O(f(n))。它表示随问题规模 n 的增大，算法执行时间的增长率和 f(n) 的增长率相同，称作算法的渐进时间复杂度，简称为时间复杂度。其中 f(n) 是问题规模 n 的某个函数。

推到大 O 阶方法

1. 用常数 1 取代运行时间中的所有加法常数。
2. 在修改后的运行次数函数中，只保留最高阶项。
3. 如果最高阶项存在且不是 1 ，则去除与这个项相乘的常数。得到的结果就是大 O 阶。

常见的时间复杂度：

| 执行次数函数 | 阶 | 非正式术语 |
| - | - | - |
| 12 | O(1)| 常数阶 |
| 2n+3 | O(n)| 线性阶 |
| 3n²+2n+1 | O(n²)| 平方阶 |
| 5log₂n+20 | O(logn)| 对数阶 |
| 12 | O(nlogn) | nlogn 阶 |
| 6n³+2n²+3n+4 | O(n³) | 立方阶 |
| 2ⁿ | O(2ⁿ) | 指数阶 |

### 2.12 算法空间复杂度

算法的空间复杂度通过计算算法所需的存储空间实现，算法空间复杂度的计算公式记作：S(n)=O(f(n))，其中，n 为问题的规模，f(n) 为语句关于 n 所占存储空间的函数。

## 第 3 章 线性表

线性表（List）：零个或多个数据元素的有限序列。
### 3.4 线性表的顺序存储结构

线性表的顺序存储结构，指的是用一段地址连续的存储单元依次存储线性表的数据元素。

缺点：插入和删除时需要移动大量元素。

### 3.6 线性表的链式存储结构

### 3.x 单链表

### 3.12 静态链表

用数据描述的链表叫做静态链表（游标实现法）。

### 3.13 循环链表

将单链表中终端结点的指针端由空指针改为指向头结点，就使整个单链表形成一个环，这种头尾相接的单链表称为单循环链表，检查循环链表（circular linked list）。

### 3.14 双向链表

双向链表（double linked list）是在单链表的每个结点中，再设置一个指向其前驱结点的指针域。


## 第 4 章 栈与队列

栈（stack）是限定仅在表尾进行插入和删除操作的线性表。

### 4.10 队列的定义

队列（queue）是只允许在一端进行插入操作，而在另一端进行删除操作的线性表。

## 第 5 章 串

串（string）是由零个或多个字符组成的有限序列，又名字符串。

### 5.7 KMP 模式匹配算法


## 第 6 章 树

### 6.2 树的定义

树（Tree）是 n（n>=0）个结点的有限集。n=0 时称为空树。在任意一棵非空树中：

（1）有且仅有一个特定的称为根（Root）的结点；

（2）当 n>1 时，其余结点可分为 m（m>0）个互不相交的有限集 T1、T2、······、Tm，其中每一个集合本身又是一棵树，并且称为根的子树（SubTree）。


### 6.4 孩子兄弟表示法

### 6.5 二叉树的定义

二叉树（Binary Tree）是 n（n>=0）个结点的有限集合，该集合或者为空集（称为空二叉树），或者由一个根结点和两课互不相交的、分别称为根结点的左子树和右子树的二叉树组成。

- 斜树：所有的结点都只有左子树的二叉树叫左斜树。所有结点都是只有右子树的二叉树叫右斜树。（线性表）
- 满二叉树：在一棵二叉树中，如果所有分支结点都存在左子树和右子树，并且所有叶子都在同一层上，这样的二叉树称为满二叉树。
- 完全二叉树：对一棵具有 n 个结点的二叉树按层序编号，如果编号为 i（1<=i<=n）的结点与同样深度的满二叉树中编号为 i 的结点在二叉树中位置完全相同，则这棵二叉树称为完全二叉树。

### 6.6 二叉树的性质

- 在二叉树的第 i 层上至多有 2^(i-1)个结点（i>=1）。
- 深度为 k 的二叉树至多有 2^k-1 个结点（k>=1）。


### 6.8 遍历二叉树

- 前序遍历：规则是若二叉树为空，则空操作返回，否则先访问根结点，然后前序遍历左子树，再前序遍历右子树。
- 中序遍历：规则是若树为空，则空操作返回，否则从根结点开始（注意并不是先访问根结点），中序遍历根结点的左子树，然后是访问根结点，最后中序遍历右子树。
- 后序遍历：规则是若树为空，则空操作返回，否则从左到右先叶子后结点的方式遍历访问左右子树，最后是访问根结点。
- 层次遍历：规则是若树为空，则空操作返回，否则从树的第一层，也就是根结点开始访问，从上而下逐层遍历，在同一层中，按从左到右的顺序对结点逐个访问。

### 6.10 线索二叉树

## 第 7 章 图

图（Graph）是由顶点的有穷非空集合和顶点之间边的集合组成，通常表示为：G(V,E)，其中，G 表示一个图，V 是图 G 中顶点的集合，E 是图 G 中边的集合。

### 7.4 图的存储结构

邻接矩阵

邻接链表

### 7.5 图的遍历

深度优先遍历

广度优先遍历

### 7.6 最小生成树

普里姆（Prim）算法

克鲁斯卡尔（Kruskal）算法

### 7.7 最短路径

迪杰斯特拉（Dijkstra）算法

弗洛伊德（Floyd）算法

### 7.8 拓扑排序


## 第 8 章 查找


## 第 9 章 排序

| 排序方法 | 平均情况 | 最好情况 | 最坏情况 | 辅助空间 | 稳定性 |
| - | - | - | - | - | - |
| 冒泡排序 | O(n²) | O(n) | O(n²) | O(1) | 稳定 |
| 简单选择排序 | O(n²) | O(n²) | O(n²) | O(1) | 稳定 |
| 直接插入排序 | O(n²) | O(n) | O(n²) | O(1) | 稳定 |
| 希尔排序 | O(nlogn)~O(n²) | O(n^1.3) | O(n²) | O(1) | 不稳定 |
| 堆排序 | O(nlogn) | O(nlogn) | O(nlogn) | O(1) | 不稳定 |
| 归并排序 | O(nlogn) | O(nlogn) | O(nlogn) | O(n) | 稳定 |
| 快速排序 | O(nlogn) | O(nlogn) | O(n²) | O(nlogn)~O(n) | 不稳定 |

### 冒泡排序

### 简单选择排序

### 直接插入排序

### 希尔排序

### 堆排序

### 归并排序

### 快速排序


