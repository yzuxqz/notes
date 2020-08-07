

# 基础概念

JDK：java开发环境，java开发工具

1. javac：编译成.class字节码文件
2. java：运行.class文件

JRE：java运行环境，Java核心类库

JVM：java虚拟机，跨平台兼容

关系：JVM>>JRE>>JVM

# 常用DOS指令

| 指令                  | 说明                  |
| --------------------- | --------------------- |
| d:                    | 切换盘符              |
| cd/cd..               | 切换文件夹/进入上一级 |
| dir                   | 文件列表              |
| md                    | 创建文件夹            |
| rd                    | 删除空文件夹          |
| del                   | 删除文件              |
| echo 内容>文件名.后缀 | 创建文件              |
| chcp                  | jdk编码格式           |

# 基本语法

## 关键字

- 电脑语言中事先定义，有特别意义的标识符
- 小写

## 保留字

- 特殊的关键字，无语义，未被java语言使用

## 标识符

- 由字母，数字，_，$组成

- 数字不能开头

- 不能使用关键字和保留字，但可以包含

- 区分大小写

- 不能包含空格

## 命名规范

- 包名：小写

- 类名，接口名：大驼峰命名（首字母大写） 

- 变量名&&方法名：小驼峰命名（首字母小写）

- 常量名：所有字母大写，_连接

## 注释

单行：//

多行：/* */

文本：/** */

## 变量

变量概念：在内存中的一个存储区域，可以在同一类型范围内变换值，内存存储的最小单元

==注意==：先声明（数据类型 变量名 = 值），后使用，仅在自身作用域有效，不能重名

## 数据类型

### 基本数据类型

| 类型    | 占用存储空间                              | 范围         |
| ------- | ----------------------------------------- | ------------ |
| byte    | 1字节=8bit（bit是计算机中最小的存储单位） | -128-127     |
| short   | 2字节                                     | -2^15-2^15   |
| int     | 4字节                                     | -2^31-2^31-1 |
| long    | 8字节（加L）                              | -2^63-2^63-1 |
| float   | 4字节（加F）                              | 小数点后7位  |
| double  | 8字节（默认浮点类型）                     | 小数点后14位 |
| char    | 1字节（单引号）                           | 单个字符     |
| boolean |                                           | true/false   |

### 引用数据类型

| 类型   | 说明     |
| ------ | -------- |
| String | 多个字符 |

### 数据类型转换

#### 自动类型转换

不同数据类型运算时，取数范围小的类型会自动转为取数范围大的类型

![](D:\桌面\notes\java\assets\自动数据类型转换.png)

==注意==：

1. byte，short类型做运算，结果自动转为int类型
2. char类型在与数值类型做运算时取得AscII码值做运算，结果为int类型

#### 强制类型转换

将取数范围大的数据类型转为取数范围小的数据类型

float a = (float) 2.9；

==注意==：会损失精度

#### String类型转数值类型

int  i = Integer.parseInt(str)；

## 运算符

### 算术运算符

| 算术运算符 |      | 说明                                     |      |
| ---------- | ---- | ---------------------------------------- | ---- |
| +          |      | 加（字符串拼接）                         |      |
| -          |      | 减                                       |      |
| *          |      | 乘                                       |      |
| /          |      | 取整                                     |      |
| %          |      | 取余                                     |      |
| ++         |      | 自增（后缀：先赋值，再自增，前缀：相反） |      |
| --         |      | 自减（后缀：先赋值，再自减，前缀：相反） |      |

### 赋值运算符

| 赋值运算符 | 说明            |
| ---------- | --------------- |
| =          | 赋值            |
| +=         | i+=2相当于i=i+2 |
| -=         |                 |
| *=         |                 |
| /=         |                 |

### 比较运算符

| 比较运算符 | 说明 |
| ---------- | ---- |
| ==         | 相等 |
| !=         | 不等 |
| </<=       |      |
| >/>=       |      |

### 逻辑运算符

| 逻辑运算符 | 说明                          |
| ---------- | ----------------------------- |
| &          | 左边为flase会继续执行右边     |
| &&         | 短路，左边为false不会执行右边 |
| \|         | 左边为true会继续执行右边      |
| \|\|       | 短路，左边为true不会执行右边  |
| !          | 非                            |
| ^          | 异或，相同为false，不同为true |

### 位运算符

二进制

1. 正数

- 源码，反码，补码相同

1. 负数

- 反码：符号位不变，源码取反

- 补码：符号位不变，源码取反加一

| 位运算符 | 说明                                                         |
| -------- | ------------------------------------------------------------ |
| <<       | 左移x位(<<x),相当于原数*2^x                                  |
| >>       | 右移x位(<<x),相当于原数/2^x ，==注意==：高位为0补0，高位为1补1 |
| >>>      | 无符号右移，无论最高位是什么都补0                            |
| &        | 二进制各个位相与                                             |
| \|       | 二进制各个位相或                                             |
| ^        | 二进制各个位相异或                                           |
| ~        | 非                                                           |

区别逻辑运算符：位运算符操作数值，逻辑运算符操作布尔值

### 三元运算符

条件表达式 ？语句1（表达式为true）：语句2（表达式为false）;

==注意==：必须根据返回值类型接收结果

## Scanner工具类

1. 导入jar包

   java.util.Scanner;

2. 创建Scanner实例

   new Scanner(System.in);

3. 使用Scanner类中的方法

   next(),nextInt(),nextDouble(),next().charAt(0)
   

## 流程控制语句

### 流程分支语句

- if else

```java
if(){
}else if(){
}else{
}
```

- switch case

```java
switch(表达式){
	case 常量1:语句1;
        break;
	case 常量2:语句2;
        break;
	case 常量3:语句3;
        break;
    default:语句4;
        break;
}
```

​		==注意==：表达式的类型只能是byte，short，int，char，String

​					 当没有break关键字时，匹配条件之后的代码都会去执行

### 循环控制语句

####  for

```java
for(初始;条件(布尔表达式);代代){
语句;
}
```

#### break

用于switch：结束当前switch

用于循环：结束循环，不继续下一次循环

#### continue

跳出本次循环，继续下一次循环

#### while

```java
初始
while(条件){
迭代
语句
}
```

​	随机数：

1. java.util.Random
2. new Random.nextInt(范围);

##### do while

```
初始
do{
迭代
语句
}while(条件)
```

==区别==：先执行再判断，至少会执行一次

## 数组

1. 数组是引用数据类型，数组元素不一定
2. 数组的长度一旦确定，就不能更改
3. 数组的创建会在内存开辟一连串连续的空间
4. 数组引用的是连续内存空间的首地址

### 一维数组

#### 声名和初始化

```java
//1.静态初始化：声名与初始化同时进行
int[] arr = new int[]{1,2,3}
//或者
int[] arr = {1,2,3}//类型推断
//2.动态初始化
String[] arr = new String[3];
double[] arr6 = new double[3];
```

#### 添加和获取元素

```java
//通过下标添加
arr6[0]=12.3;
arr6[3]=12;//编译通过，运行出错，索引越界
```

#### 遍历数组

```java
for(int i=0;i<arr.length;i++){
    System.out.println(arr[i]);
}
```

#### 数组元素的默认初始值

##### 基本数据类型

- 整形：0

- 浮点型：0.0

- char：0（ASCII码值）
- boolean：false

##### 引用数据类型

- null

#### 数组的内存解析


