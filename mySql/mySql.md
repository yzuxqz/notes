# 概念

## DB

database数据库:保存一系列有组织的数据

## DBMS

Darabase Management System数据库管理系统。数据库是通过DBMS创建和操作的容器

## SQL

Structure Query Lannguage结构化查询语句：用来和数据库通信的语言

# 特点

![](D:\桌面\notes\mySql\assets\数据库特点.png)

# 启动

1. 右击计算机，管理，服务
2. ![](D:\桌面\notes\mySql\assets\数据库启动.png)

# 登录

mysql -h 主机名 -P 端口号（默认3306） -u 用户 -p密码

![](D:\桌面\notes\mySql\assets\数据库登录.png)

本机登录简写：

![](D:\桌面\notes\mySql\assets\数据库本机登录.png)

# 常见命令

登录数据库后使用

|                                                |                                    |
| ---------------------------------------------- | ---------------------------------- |
| show databases；                               | 显示数据库中的表                   |
| use 库名；                                     | 进入库                             |
| show tables；                                  | 显示进入的库中有哪些表             |
| show tables from 库名；                        | 直接显示库中的表，但是并没有进入库 |
| select database()；                            | 查看当前在那个库中                 |
| desc 表名；                                    | 查看表结构                         |
| create tables 表名(  列名 列类型，列名 列类型) | 创建表                             |
| select version()；                             | 查看服务器版本                     |

# 语法规范

1. 不区分大小写，但是建议关键字大写，表名，列名小写

2. 每条命令分号结尾

3. 可以缩进换行（不写分号回车就是换行）

4. 注释

   ​	单行注释：#注释文字 或者 -- 注释文字

   ​	多行注释：/ *注释文字*  /

# DQL

database query language

### 基础查询

1. select 查询列表 from 表名；

   ==特点==：

   1. 查询列表可以是：表中的字段，常量值，表达式，函数，查询的结果可以是一个虚拟的表格

#### 查询表中的单个字段

```mysql
SELECT 字段名 FROM 表名;
```

#### 查询表中的多个字段

```mysql
SELECT 字段名1,字段名2 FROM 表名;
```

#### 查询表中的所有字段

```mysql
SELECT * FROM 表名;
```

==注意==：

1. 在查询前 use 库名；
2. 反单引号用来区分关键字和字段

#### 查询常量

```mysql
SELECT 100;

SELECT "john";
```

#### 查询表达式

```mysql
SELECT 100*98;
```

#### 查询函数

```mysql
SELECT VERSION();
```

#### 起别名

1. 便于理解
2. 如果查询的字段有重名的情况，用别名可以区分开

使用AS:

```mysql
SELECT last_name ==AS== 姓,first_name ==AS== 名 FROM employees;
```

使用空格：

```mysql
SELECT last_name 姓,first_name 名 FROM employees;
```

==注意==：

1. 如果别名中有关键字，要加双引号

#### 去重

关键字 DISTINCT

```mysql
SELECT DISTINCT department_id FROM employees;
```

#### +号的作用

1. 只是运算符

2. 在运算时会将字符型转为数值型

   如果转换成功，则继续做加法

   如果转换失败，则字符型转为0，再做加法

3. 只要有null，结果为null

#### CONCAT

```mysql
SELECT	CONCAT(字段名1,字段名2) AS 姓名 FROM employees;
```

#### IFNULL

参数1：原来的字段名

参数2：如果字段值为null，修改为

```sql
SELECT	IFNULL(commission_pct,0) AS 奖金率,commission_pct
FROM employees;
```

### 条件查询

1. select 查询列表 from 表名 where 筛选条件

#### 分类

1. 按条件表达式筛选

   条件运算符：> < = != <> >= <=

2. 按逻辑表达式筛选

   逻辑运算符：&& || ！ and or not

3. 模糊查询

   like 

   between and 

   in  

   isnull

#### 按条件表达式筛选

```mysql
SELECT * FROM employees WHERE salary>12000;

SELECT last_name,`department_id` FROM employees WHERE `department_id`<>90;
```

#### 按逻辑表达式筛选

作用：用于连接条件表达式

```mysql
SELECT last_name,salary,commission_pct FROM employees WHERE salary>=10000 AND salary<=20000;

SELECT last_name,salary,commission_pct FROM employees WHERE `department_id`<90 OR `department_id`>110 OR salary>15000;
//相当于
SELECT last_name,salary,commission_pct FROM employees WHERE NOT(`department_id`>=90 AND `department_id`<=110) OR salary>15000;
```

### 模糊查询

#### like

一般和通配符搭配式使用，通配符：

1. % ：任意多个字符，包含0个字符
2. _：任意单个字符，一个下划线表示一个字符

```mysql
#员工名字包含字符a
SELECT * FROM employees WHERE last_name LIKE '%a%';
#员工名中第三个字符为a，第五个字符为a
SELECT last_name,salary FROM employees WHERE last_name LIKE '__e_a%'
#员工名中第二个字符为下划线的
SELECT last_name FROM employees WHERE last_name LIKE '_\_%';
```

==注意==：

1. 如果查询的字符为下划线，要转义下划线

#### between and

1. 提高语句的简洁度
2. 包含临界值
3. 两个临界值不能换顺序

```mysql
#员工编号100-120
SELECT * FROM employees WHERE `employee_id`>=100 AND `employee_id`<=120;

SELECT * FROM employees WHERE `employee_id` BETWEEN 100 AND 120;
```

#### in

1. 用于判断某字段的值是否属于in列表中的某一项
2. 特点：
   1. 使用in比使用or提高了语句简洁度
   2. in列表的值类型必须统一或兼容
   3. 不能使用通配符

```mysql
#工种编号是 IT_	PROG，AD_VP其中一个的员工信息
SELECT last_name,job_id FROM employees WHERE job_id IN('IT_PROT','AD_VP');
```

#### is null

只能判断null值

```mysql
#没有奖金的员工
SELECT last_name,commission_pct FROM employees WHERE commission_pct IS NULL;

#有将金
IS NOT NULL
```

#### 安全等于

<=>

不仅仅能查null值，包括其他的值

```mysql
#没有奖金的员工
SELECT last_name,commission_pct FROM employees WHERE commission_pct <=>NULL;
```

### 排序查询

1. order by可以支持单个字段，多个字段，表达式，函数，别名
2. asc代表升序，desc代表降序，如果不写，默认是升序
3. order by子句一般是放在查询语句的最后面，limit子句除外

```mysql
#排序查询
SELECT * FROM employees ORDER BY salary DESC;
#DESC是从高到低
#ASC是从低到高，如果不写默认是升序
```

#### 按表达式排序

```mysql
SELECT * ,salary*12*(1+IFNULL(commission_pct,0)) AS 年薪 FROM employees ORDER BY salary*12*(1+IFNULL(commission_pct,0)) DESC;
```

#### 按别名排序

```mysql
SELECT * ,salary*12*(1+IFNULL(commission_pct,0)) AS 年薪 FROM employees ORDER BY 年薪 DESC;
```

#### 按函数排序

```mysql
#根据姓名字节长度进行排序
SELECT LENGTH(`last_name`) AS 字节长度,`last_name`,`salary` FROM employees ORDER BY LENGTH(last_name) DESC;
```

#### 排序多个字段

```mysql
#多个字段排序
SELECT* FROM employees ORDER BY salary ASC,`employee_id` DESC;
```

# DML

# MySQL函数

## 单行函数

### 字符函数

|                                   |                          |
| --------------------------------- | ------------------------ |
| length(字段名)                    | 获取字段的长度           |
| concat(字段名1，字段名2)          | 连接字段                 |
| upper(字段名)                     | 大写                     |
| lower(字段名)                     | 小写                     |
| substr(字段名，索引)              | 截取                     |
| instr（字段名，子串字段）         | 返回子串第一次出现的索引 |
| trim（x from 字段名）             | 去除首尾字符             |
| lpad（字段，指定长度，指定字符）  | 用指定字符填充指定长度   |
| replace（字段，要替换的，替换为） |                          |
| ifnull(字段名，若为空替换为)      | 判断为空，替换为         |

```mysql
#字符函数
#upper,lower
SELECT	CONCAT(UPPER(last_name),LOWER(first_name)) AS 姓名 FROM employees;

#substr,substring
注意：索引从1开始
#截取索引处后面所有字符
SELECT SUBSTR('李莫愁爱上了陆展元',7) AS out_put;
#截取指定长度的字符
SELECT	SUBSTR('李莫愁爱上了陆展元',1,3) AS out_put;

#姓名首字母大写，其他字符小写，然后_拼接
SELECT CONCAT(UPPER(SUBSTR(`last_name`,1,1)),'_',LOWER(SUBSTR(`last_name`,2)))	 FROM employees;

#instr 返回子串第一次出现的索引，如果找不到返回0
SELECT INSTR('杨不悔爱上了殷六侠','殷六侠') AS out_put;

#trim 去除首位字符
SELECT LENGTH(TRIM('    张翠删      ')) AS out_put;
SELECT TRIM('a' FROM 'aaaaaaa张aaaaaaaaa翠山aaaaaaaaaaaaaa') AS out_put;

#lpad 用指定的字符实现左填充指定长度
SELECT LPAD('殷素素',10,'*') AS out_put;
#rpad
SELECT RPAD('殷素素',10,'*') AS out_put;

#replace 替换
SELECT REPLACE('aaabbbccc','a','d') AS out_put;
```

### 数学函数

|                     |                          |
| ------------------- | ------------------------ |
| round               | 四舍五入                 |
| cell                | 向上取整                 |
| floor               | 向下取整                 |
| truncate（1.65，1） | 截断，小数点后保留多少位 |
| MOD(字段1，字段2)   | 取余                     |

### 日期函数

|             |                      |
| ----------- | -------------------- |
| now         | 当前日期和时间       |
| curdate     | 日期                 |
| curtime     | 时间                 |
| year        | 年                   |
| month       | 月                   |
| monthname   | 月的英文             |
| str_to_date | 字符转为指定格式日期 |
| date_format | 日期抓为字符         |

![](D:\桌面\notes\mySql\assets\日期函数.png)

![](D:\桌面\notes\mySql\assets\日期函数格式符.png)

```mysql
#日期函数
#日期加时间
SELECT NOW();
#日期
SELECT CURDATE();
#时间
SELECT CURTIME();
#获取指定的部分，年，月，日，小时，分钟，秒
SELECT	YEAR(NOW()) AS 年;
SELECT YEAR('1998-1-1') AS 年;
SELECT MONTH(NOW()) AS 月;
SELECT MONTHNAME(NOW()) AS 月;
#str_to_date 将字符通过指定的格式转换成日期
SELECT STR_TO_DATE('1999-3-2','%Y-%c-%d') AS out_put;
#查询入职日期为1992-4-3的员工信息
SELECT * FROM employees WHERE hiredate = '1992-4-3';
SELECT * FROM employees WHERE hiredate = STR_TO_DATE('4-3 1992','%c-%d %Y');

#date_format 将日期转换成字符
SELECT	DATE_FORMAT(NOW(),'%y年%m月%d日') AS out_put;
#查询有将金的员工名和入职日期
SELECT last_name,DATE_FORMAT(hiredate,'%m月%d日 %y年') AS 入职日期
FROM employees
WHERE commission_pct IS NOT NULL;

```

### 其他函数

### 流程控制函数

## 分组函数

|      |      |
| ---- | ---- |
|      |      |
|      |      |
|      |      |

