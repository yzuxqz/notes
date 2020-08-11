#  JS基础

## 简单数据类型

### Undefined类型

- 只声明但未初始化或者未声名
- 只有一个值：undefined
- 用typeof检测返回undefined
- ==注意==：用typeof检测未声明的变量也会返回undefinded

### NUll类型

- 表示空对象指针，用于未来会保存对象的变量初始化
- 只有一个值：null
- 用typeof检测返回object
- ==注意==：undefined派生自null（null==undefined）

### Boolean类型

- 只有两个值：true和false
- 转型函数Boolean()

### Number类型

- 八进制最高位加0
- 十六进制最高位加0x
- ==注意==：在输出和进行算术运算时都会转换成十进制
- 浮点数在小数点后没有数或小数点后都为0时会被转为整型
- ==注意==：ECMAScript中浮点计算会有误差，因此不要去判断浮点数

#### 数值范围

- 超过Number.MAX_VALUE和Number.MAX_VALUE的数值会被转成 Infinity和-Infinity

#### NaN

- 任何涉及NaN的操作都会返回NaN
- NaN与任何值都不想等，包括NaN本身
- isNaN()用于测试传入的数值是否能转为数值，如果不能则返回true
- ==注意==：true能转化为1
- isNaN()也适用于对象，对象调用isNaN()函数时首先调用对象自己的valueOf()方法，以确定该方法的返回值是否可以转为数值。如果不能，再基于这个返回值调用tostring()方法，再次测试

#### 数值转换

##### Number()

- 可以用于任何数据类型
- Boolean值，true返回1，false返回0
- null值，返回0
- undefined值，返回NaN
- 字符串，除空的转为0，有额外字符的转为NaN，其他都转为十进制数
- ==注意==：不能转八进制，因为前导0会忽视

##### parseInt(,)

- 如果第一个字符不是数值或负号，则返回NaN。(空返回NaN)
- 直到解析到非数字字符（包括小数点）停止
- 能够解析八进制和十六进制，加上第二个参数，表示基数是多少进制

##### parseFloat()

- 可以解析第一个小数点
- 只能解析十进制数
- 如果传入的字符是整数，则也会返回整数

### String类型

- 转义字符
- 拼接字符串会很慢，字符串的不可变性

#### 转为字符串

##### toString()

- 除了null，undefined都有该方法
- 参数表示返回数值的进制

##### String()

- 如果值有toString()方法则调用toString()方法
- 如果值为null，返回 “null”
- 如果值为undefined，返回“undefined”

##### + ""

- 加一个空字符串，隐式类型转换



## JS对象

### 创建对象

- 字面量

  ```javascript
  var obj = {
              uname: 'xqz', //里面的属性方法采取键值对的形式
              sayHi: function () { //方法冒号后面跟的是一个匿名函数
                  console.log('hi');
              }
          }
  ```

- 利用Object()

  ```javascript
  var obj = new Object(); //一个空对象
          obj.uname = 'xqz';
          obj.sayHi = function () {
              console.log('Hi');
          };
  ```

- 构造函数

  ```javascript
   function Star(uname, age, sex) { //构造函数首字母大写
              this.name = uname;
              this.age = age;
              this.sex = sex;
              this.sing = function (songs) {
                  console.log(songs);
              }
          }
          var ldh = new Star('刘德华', 19, '男'); //构造函数不需要return
          ldh.sing('冰雨');
  ```

### 使用对象

- 使用属性

  obj.uname

  obj.['uname']

- 使用方法

  obj.sayHi();

### 遍历对象

```javascript
for (const key in ldh) {
           console.log(key);//输出属性名
           console.log(ldh[key]);//输出属性值
        }
```



## 内置对象

### Math对象

- 最大值

  Math.max()

- 绝对值

  Math.abs()

- 取整

  - 向下

    Math.floor()

  - 向上

    Math.ceil()

  - 四舍五入

    Math.round()

    ==注意==：负数中.5特殊，往大了取

- 随机数

  - 返回[0,1)之间的小数

    Math.random()

  - 返回两个数之间的随机整数

    ```javascript
    //返回两个数之间的随机整数，并且包含这两个数
            function getRandom(min, max) {
                return Math.floor(Math.random() * (max - min + 1)) + min;
            }
    ```



### 日期对象

- 返回系统当前时间
  		new Date()

- 返回自定义的时间

  - 参数为数字型

    new Date(2020,6,30)

    ==注意==：返回的月份比实际大1月

  - 参数为字符串型

    new Date(‘2020–6–30 8:23:45’);

- 年

  date.getFullYear()

- 月

  date.getMouth() + 1（0~11）

- 日

  date.getDate()

- 周几

  date.getDay()

- 时

  date.getHours()

- 分

  date,getMinutes()

- 秒

  date.getSeconds()

- 时间戳（毫秒）

  ==注意==：是距离1970年1月1日过了多少毫秒

  - date.valueof()

  - date.getTime()

  - +new Date()

  - Date.now()<!--H5新增-->									



### 数组对象

#### 创建数组

- 字面量

  ```javascript
   var arr = [1, 3, 3, 3]
  ```

- 利用new Array()

  ```javascript
  var arr1 = new Array(2); //长度为2的空数组
  var arr1 = new Array(2, 3); //等价于[2,3]表示里面有两个数组元素是2和3
  ```

#### 检测是否为数组

- arr instance of Array
- Array.isArray(arr)<!--H5新增-->	

#### 增

- 在末尾加,   返回新数组长度

  arr.push()

- 在开头加，返回新数组长度

  arr.unshift()

- 在指定位置加

  splice(开始索引，0，添加的元素) //返回删除的数组

#### 删

- 删末尾一个，返回删除的元素

  arr.pop()

- 删开头一个，返回删除的元素

  arr.shift()

- 删除并在删除位置添加

  splice(开始索引，删除个数，添加的元素)//返回删除的数组

#### 改

​	splice(开始索引，删除个数，添加的元素)//返回删除的数组

#### 查

根据元素找索引

```javascript
console.log(arr.indexOf('A')); //从前往后找 它只返回第一个满足条件的索引号 找不到则会返回-1
console.log(arr.lastIndexOf('A')); //从后往前找
```

findIndex(),返回一个索引

```javascript
//根据id从数组中查找元素的索引
this.books.findIndex(function (item) {
     return item.id == id;
})
```

#### 翻转

arr.reverse()

#### 排序

```javascript
//sort里面放一个函数实现排序
arr.sort(function (a, b) {
     return a - b;
});
console.log(arr);//a-b<0 升序
```

#### 合并

arr1.concat(arr2)

#### 数组转字符串

- arr.join(分隔符)  //默认逗号
- arr.toString()  //逗号分隔

#### 数组截取

arr.slice(开始索引，结束索引（不包含）)

#### 数组遍历

- array.filter(function(currentValue,index,arr), thisValue)//当前元素的值，当前元素的索引，当前元素属于的数组对象
  -  不会改变原始数组
  - 返回一个新数组

```javascript
 //根据id查询出要编辑的数据
                  this.books = this.books.filter(function(item){
                       return item.id==id;
                    });
```

- some(function(){})
  - 用于检测数组中的元素是否满足指定条件
  - some()方法会以此执行数组的每个元素：
    - ==如果有一个元素满足条件，则表达式返回true==，剩余的元素不再遍历
    - 如果没有满足体条件的元素，返回false

==注意==：不能对空数组进行检测

```javascript
 //根据当前的id去更新数组中对应的数据
                        this.books.some((item) => { //箭头函数中的this指向定义这个函数的父级作用域中的this，也就是handle的this，指向vue实例
                            if (item.id == this.id) {
                                item.name = this.name;
                                //完成更新操作后需要中止some遍历
                                return true;
                            }
                        });
```





### 字符串对象

- string是简单数据类型，为什么有length属性？

  步骤：

  1. 创建基本类型的一个实例；
  2. 在实例上调用指定的方法；
  3. 销毁这个实例；

  ```javascript
  var str = "我是string基本类型的值";
  var new_str = new String("我是string基本类型的值");  // 包装处理
  var my_str = new_str.substring(5,8);
  new_str = null;   // 方法调用之后销毁实例
  
  var str2 = "xqz";
  str2.age = 21;
  console.log(str.age);   //undefined
  //可见，并非string调用了自身的方法，而是后台创建了一个基本包装类型String，从而进行下一步操作。
  //基本类型的“销毁性”致使我们不能为基本类型添加属性和方法。
  ```

- ==注意==：String,Number,Boolean都是基本包装类型

- 字符串的不可变性

  指的是里面的值不变，其实只是地址变了，内存中开辟了一个内存空间

  ```javascript
  var str2 = 'andy';
  str2 = 'red'; //str从andy指向red，但是andy仍然存在
  //因为我们字符串的不可变所以不要大量拼接字符串
  var str2 = '';
  for (var i = 0; i < 100; i++) { //如果i过大会很卡
  str += i;
  }
  console.log(str);
  ```

- ==注意==：字符串的所有方法都不改变自身，都返回一个新的字符串

#### 根据值找索引

```javascript
var str = '改革春风吹满地，春天来了';
console.log(str.indexOf('春'));
console.log(str.indexOf('春', 3)); //从索引号3的位置(包括3)往后找 lastindexof()同理
```

#### 根据索引找值

- 返回字符

  str.charAt()

  str[]<!--H5新增-->

- 返回ASCII值

  str.charCodeAt()

#### 合并

​	str1.concat(str2)

#### 截取

- str.substr(开始的索引，截取长度)  //如果只有一个参数且为负数，则是从后往前
- str.substring(开始索引，结束索引)  //结束索引不能为负数，负数会被转为0
- str.slice(开始索引，结束索引（不包含）) //可以接受负数，会将字符串长度与负数相加作为第二个参数
- 都是返回截取下来的字符串

#### 替换

​	str.replace(要替换，替换为)  //只会换一个

#### 大小写

​	toUpperCase()

​	toLowerCase()

#### 去除空格

​	str.trim()

#### 是否包含

​	str.includes()   //返回bool类型（es6）

#### 字符串转数组

​	str.split(以什么分隔符分割该字符串)  //返回一个数组

### arguments的使用

- arguments是函数的一个内置对象，只有function()才有，当不确定有几个参数传递时使用

- arguments是一个伪数组：可以通过索引访问，有length属性，但是没有数组的方法



## JS预解析

### 变量提升

只提升变量名，不提升赋值操作

### 函数提升

只提升函数声名，不调用函数

- 例题

  ```javascript
  	    f1();
          console.log(c);
          console.log(b);
          console.log(h);
  
          function f1() {
              var h = b = c = 9;
              //相当于 Var a=9;b=9;c=9;b和c直接赋值 没有var 当全局变量看
              //集体声明应该写成 var a=9，b=9,c=9;
              console.log(h);
              console.log(b);
              console.log(c);
          }
  
          //相当于
          function f1() {
              var h;
              h = 9;
              b = 9;
              c = 9;
              console.log(h);
              console.log(b);
              console.log(c);
          }
          f1();
          console.log(c);
          console.log(b);
          console.log(h);//此处报错，h没有声名，因为h的作用域只在f1函数中
  ```

# WebAPI

## DOM

### 节点操作

- nodeType
  1. 元素节点
  2. 属性节点
  3. 文本节点

- nodeName
- nodeValue

==注意==：节点操作主要操作元素节点

##### 元素节点和元素对象的区别

1.所谓元素，即html文档里面，所有的标签都可以称之为元素，比如说<p>、<tr>等，也就是说元素是个统称，一个文档里面有很多的元素。

2.所谓节点，是js为了对html文档进行操作，而开发的，即DOM，文档对象模型。即每个元素都可以称之为一个节点，节点是唯一的。比方来说，《p》标签，肯定是一个p标签元素，那如果通过js对它进行样式控制的时候，就必须获取（找到）到这个元素，称之为节点，如果有好多元素，可以获得第1个、第2个或者第n个。总之，元素是统称，节点是具有唯一性的。

##### 获取节点

| API                                | 说明                                                         |
| ---------------------------------- | ------------------------------------------------------------ |
| document.getElementById('')        | 根据id返回元素对象                                           |
| document.getElementByClassName('') | 根据类名返回元素对象                                         |
| document.getElementByTagName('')   | 根据标签名返回元素对象集合（伪数组），可以先获取父元素在获取子元素 |
| document.querySelector('')         | 根据css选择器返回第一个符合条件的元素对象                    |
| document.querySelectorAll('')      | 根据css选择器返回所有元素对象                                |
| document.body()                    | 获取body标签                                                 |
| document.documentElement           | 获取html标签                                                 |

==注意==：得到的多个都是伪数组

##### 获取父节点

| API             | 说明                         |
| --------------- | ---------------------------- |
| node.parentNode | 得到的是离元素最近的父级节点 |

##### 获取子节点

| API                                   | 说明                       |
| ------------------------------------- | -------------------------- |
| node.children                         | 得到所有子节点（元素节点） |
| node.children[0]                      | 得到子节点的第一个元素     |
| node.children[node.children.length-1] | 得到子节点的最后一个元素   |

##### 获取兄弟节点

| API                         | 说明                       |
| --------------------------- | -------------------------- |
| node.nextElementSibling     | 下一个兄弟节点（元素节点） |
| node.previousElementSibling | 上一个兄弟节点（元素节点） |

##### 创建节点

| API                                          | 说明         |
| -------------------------------------------- | ------------ |
| var child = document.createElement('标签名') | 创建一个节点 |
| element.innerHTML=''                         | 创建并且添加 |

##### 添加节点

| API                                                  | 说明                                   |
| ---------------------------------------------------- | -------------------------------------- |
| node.appendChild(child)                              | 添加到父节点（node）的子节点列表末尾   |
| node.insertBefore(child,指定元素（node.children[]）) | 添加到父节点（node）的指定的子节点之前 |

##### 删除节点

| API                     | 说明                   |
| ----------------------- | ---------------------- |
| node.removeChlid(child) | node是一个父节点       |
| node.remove()           | 删除自身节点及其子节点 |

##### 复制节点

| API                  | 说明           |
| -------------------- | -------------- |
| node.cloneNode()     | 只复制标签     |
| node.cloneNode(true) | 深拷贝，全复制 |

##### 替换节点

| API                         | 说明     |
| --------------------------- | -------- |
| node.replaceChild(new ,old) | 替换节点 |

### 元素操作

#### 操作元素内容

innerHTML和innerText的区别

- innerText不识别html标签，且会自动去除空格和换行

- innerHTML识别html标签，且保留空格和换行

- 这两个属性可读写，可以获取元素里面的内容

  ```javascript
          //innerText和inner HTML的区别
          //1.innerText 不识别HTML标签 去除空格和换行
          var div =document.querySelector('div');
          div.innerText='<strong>1</strong>';
          //2.innerHTML 识别HTML标签 （常用） 保留空格和换行
          div.innerHTML='<strong>1</strong>';
  
          //这两个属性可读写 可获取元素里的内容
          var p =document.querySelector('p');
          console.log(p.innerText);
          console.log(p.innerHTML);
  ```

#### 操作元素属性

##### 获取属性

###### 获取元素自带属性

| API            | 说明                                                         |
| -------------- | ------------------------------------------------------------ |
| element.属性名 | 常见元素自带的属性：src，href，title，alt等，表单元素自带的属性：type，value，disable等 |

- offset系列属性

  | offset系列属性       | 作用                                                         |
  | -------------------- | ------------------------------------------------------------ |
  | element.offsetParent | 返回最近一级的带有定位的父元素，没有则返回body==区别==element.parentNode返回最近一级父亲，不管有没有定位 |
  | element.offsetTop    | 返回元素相对带有定位父元素上方的偏移，没有则以body为准       |
  | element.oddsetLeft   | 返回元素相对带有定位父元素左边框的偏移                       |
  | element.offsetWidth  | 返回自身包括==边框，padding，内容区==的宽度，返回数值不带单位 |
  | element.offsetHeight | 返回自身包括边框，padding，内容区的宽度，返回数值不带单位    |

  ==offset与style的区别==

  | offset                                | style                            |
  | ------------------------------------- | -------------------------------- |
  | 可以得到任意样式表中的样式值          | 只能得到行内样式表中的样式值     |
  | 返回的数值没有单位                    | 返回带有单位的字符串             |
  | offsetWidth包括padding+border+width   | style.width不包括padding和border |
  | offsetWidth等属性是只读属性，不能赋值 | 可读可写                         |
  | 用于获取元素大小                      | 用于更改元素样式值               |

- client系列属性

  | client系列属性       | 作用                                                    |
  | -------------------- | ------------------------------------------------------- |
  | element.clientTop    | 返回元素上边框的大小                                    |
  | element.clientLeft   | 返回元素左边框的大小                                    |
  | element.clientWidth  | 返回自身包括==padding，内容区==的宽度，返回数值不带单位 |
  | element.clientHeight | 返回自身包括padding，内容区的宽度，返回数值不带单位     |

- scroll系列属性

  | scroll系列属性       | 作用                                                         |
  | -------------------- | ------------------------------------------------------------ |
  | element.scrollTop    | 返回被卷去的上侧距离（overflow：auto；滚动条），返回数值不带单位，有padding从内容离开padding算起，否则边框下沿开始计算 |
  | element.scrollLeft   | 返回被卷去的左侧距离，返回数值不带单位                       |
  | element.scrollWidth  | 返回自身不含边框的==实际宽度==（超出的也算进去），返回数值不带单位 |
  | element.clientHeight | 返回自身不含边框的==实际高度==（超出的也算进去），返回数值不带单位 |

==注意==：

1. 元素被卷去的头部距离：element.scrollTop获取
2. 页面被卷去的头部距离，window.pageYoffset获取

###### 获取元素自定义属性

element.getAttribute('属性名')

##### 设置属性

###### 设置元素自带属性

| API                  | 说明 |
| -------------------- | ---- |
| element.属性名 = ''; |      |

###### 设置元素自定义属性

| API                                  | 说明 |
| ------------------------------------ | ---- |
| element.setAttribute('属性名'，'值') |      |

==注意==：修改class属性时

1. 用element.==className=== '';
2. 用element.setAttribute('==class==','');

==注意==：H5规定自定义属性data开头作为属性名并且赋值：<div data-index='1'></div>

##### 移除属性

###### 移除元素自定义属性

| API                         | 说明 |
| --------------------------- | ---- |
| element.removeAttribute('') |      |

##### 判断是否有该属性

| API                    | 说明                                      |
| ---------------------- | ----------------------------------------- |
| element.hasAttribute() | 判断元素属性，而不是css样式表中的样式属性 |

#### 操作元素样式

##### 获取样式属性

| API                            | 说明                                              |
| ------------------------------ | ------------------------------------------------- |
| getComputedStyle(element).属性 | 可以获取css样式表的样式                           |
| element.style.样式名           | 只能获取行内样式（这里的style就是元素的一个属性） |

##### 设置样式属性

| API                       | 说明                                              |
| ------------------------- | ------------------------------------------------- |
| element.className=''      | 会覆盖原来的class                                 |
| element.style.样式名='值' | 只能获取行内样式（这里的style就是元素的一个属性） |



### 动画函数的封装

#### 动画函数原理

定义一个setInterval的定时器，函数里对元素的样式进行操作

```javascript
        var div = document.querySelector('div');
        var time = setInterval(function () {
            if (div.offsetLeft >= 400) {
                clearInterval(time);
            } else {
                div.style.left = div.offsetLeft + 1 + 'px';
            }
        }, 1)
```

#### 动画函数简单封装

```html
<body>
    <div></div>
    <span></span>
    <button>点击开炮</button>
    <script>
        var div = document.querySelector('div');
        var span = document.querySelector('span');
        var btn=document.querySelector('button');
        animate(div, 300);
        
        //obj目标元素，target目标位置
        function animate(obj, target) {
            //防止吧、鹔加快先清除以前的定时器
            clearInterval(obj.time);
            //给不同的元素指定不同的定时器
            obj.time = setInterval(function () {
                if (obj.offsetLeft >= target) {
                    clearInterval(obj.time);
                } else {
                    obj.style.left = obj.offsetLeft + 1 + 'px';
                }
            }, 1)
        };
        btn.addEventListener('click',function(){
            //bug:当不断点击按钮元素速度会越来越快
            //解决方案：元素只有一个定时器执行
            animate(span, 200);
        })
        console.dir(div);
    </script>
</body>
```

#### 缓动动画函数封装

```javascript
function animate(obj, target, callback) {
    //先清除以前的定时器
    clearInterval(obj.time);
    //给不同的元素指定不同的定时器
    obj.time = setInterval(function () {
        //把步长值,上下取整看正负值
        var x = (target - obj.offsetLeft) / 10;
        if (x >= 0) {
            x = Math.ceil(x);
        } else {
            x = Math.floor(x);
        }
        if (obj.offsetLeft == target) {
            clearInterval(obj.time);
            //回调函数
            // if (callback) {
            //     callback();
            // }
            callback && callback();//&&具有短路的功能
        } else {
            obj.style.left = obj.offsetLeft + x + 'px';
        }
    }, 15)
}
```

### 三种动态创建元素的区别

1. document.write()会导致文档流重绘

2. element.innerHTML = ''

   - 拼接字符串，很慢

     解决方法：存入数组中，一次性渲染，很快

     ```javascript
     var inner = document.querySelector('.inner');
             inner.innerHTML = '<a href="#">百度</a>';
             // 创建多个字符串拼接的时候特别慢效率低
             // 但是用数组的形式拼接是最快的
             var arr = [];
             var date1 = Date.now();
             for (var i = 0; i < 1000; i++) {
                 arr.push('<a href="#">9</a>');
             }
             inner.innerHTML = arr.join('');//数组转字符串
             var date2 = Date.now();
             console.log(date2 - date1);
     ```

3. var child  = document.createElement();

   node.appendChild(child);

   比2慢，比1快

### 事件

#### 鼠标事件

| 事件                     | 说明 |
| ------------------------ | ---- |
| onclick                  | 点击 |
| onmouseover/onmouseenter | 移入 |
| onmouseout               | 移出 |
| onmousedown              | 按下 |
| onmouseup                | 松开 |
| onmousemove              | 移动 |

==注意==：mouseover和mouseenter的区别：mouseenter不会冒泡,简单的说,它不会被它本身的子元素的状态影响到.但是mouseover就会被它的子元素影响到,在触发子元素的时候,mouseover会冒泡触发它的父元素.(想要阻止mouseover的冒泡事件就用mouseenter)

#### 键盘事件

| 事件       | 说明                                                  |
| ---------- | ----------------------------------------------------- |
| onkeyup    | 松开，不区分大小写                                    |
| onkeydown  | 会在文字还没进入文本框前就添加事件，不区分大小写      |
| onkeypress | 不识别功能按键，如ctrl。区分大小写，触发比onkeydown慢 |

#### 表单事件

| 事件     | 说明                                                  |
| -------- | ----------------------------------------------------- |
| onfocus  | 获得焦点，无冒泡                                      |
| onblur   | 失去焦点，无冒泡                                      |
| onchange | 在元素值改变时触发，适用于input，textarea，select元素 |
| onselect | 在文本框内容被选中时触发，适用于单选框，多选框        |

#### 编辑事件

| 事件          | 说明                                               |
| ------------- | -------------------------------------------------- |
| oncopy        | 在拷贝时触发                                       |
| onselect      | 在文本框内容选中时触发，return false让用户无法选中 |
| oncontentmenu | 鼠标右击触发，用e.preventDefault()来禁止鼠标右键   |

#### 页面事件

| 事件           | 说明                             |
| -------------- | -------------------------------- |
| onload         | 等待文档流加载完成后触发         |
| onbeforeunload | 即将离开页面（刷新或关闭）时触发 |

#### 传统事件

##### 注册

element.事件类型 = function(){}

##### 删除

element.事件类型 = null

#### 事件监听器

##### 区别传统

相比传统的onclick=function(){}，addEventListener可以让同一元素同一事件可以注册多个监听器，按注册顺序依此执行，而传统的只能写一个，如果写了多个以最后一个为准

##### 注册

| API                                                      | 说明                                                         |
| -------------------------------------------------------- | ------------------------------------------------------------ |
| element.addEventListener(''",function(e){},[true/false]) | 第一个参数事件类型，不用加on,第三个参数默认false，冒泡阶段,true，捕获阶段 |

##### 删除

| API事件                                              | 说明                                                         |
| ---------------------------------------------------- | ------------------------------------------------------------ |
| element.removeEventListener(''",函数名,[true/false]) | 第一个参数事件类型，不用加on,第三个参数默认false，冒泡阶段,true，捕获阶段 |

#### 事件对象

##### 事件对象属性

| 属性     | 说明                                                         |
| -------- | ------------------------------------------------------------ |
| e.type   | 事件类型                                                     |
| e.target | 真正触发事件的那个元素（事件委托：ul和li利用冒泡只需给ul添加点击事件，用e.target获取点击的li） |

##### 事件对象方法

| 方法                | 说明         |
| ------------------- | ------------ |
| e.preventDefault()  | 阻止默认行为 |
| e.stopPropagation() | 阻止事件冒泡 |

##### 鼠标事件对象

| 属性        | 说明                                               |
| ----------- | -------------------------------------------------- |
| e.pageX/Y   | 相对于文档页面（图片跟随鼠标移动，图片要绝对定位） |
| e.clientX/Y | 相对于浏览器的可视窗口                             |
| e.screenX/Y | 相对于电脑屏幕                                     |

##### 键盘事件对象

| 属性       | 说明              |
| ---------- | ----------------- |
| e.altKey   |                   |
| e.ctrlKey  |                   |
| e.shiftKey | 是否按下shift     |
| e.keyCode  | 键盘输入的ascll码 |

##### DOM事件流

传统和监听器一般都是得到冒泡阶段，把addEventListener第三个参数改为true则能得到捕获阶段

###### 捕获阶段

document=>html=>body=>father=>son（如果father有监听事件，先执行father的，再执行son的）

###### 冒泡阶段

于捕获相反

==注意==：onblur，onfocus，onmouseenter，onmousemove没有冒泡

##### 事件委托

原理：将事件监听器设置在父节点上，利用冒泡原理影响每个子节点，用e.target获取按下的那个元素

```html
<body>
    <ul>
        <li>2342</li>
        <li>2342</li>
        <li>2342</li>
        <li>2342</li>
        <li>2342</li>
    </ul>
    <script>
        var ul = document.querySelector('ul');
        ul.addEventListener('click', function (e) {
            //排他
            for (var i = 0; i < ul.children.length; i++) {
                ul.children[i].style.backgroundColor = '';
            }
            //得到你点击的小li
            e.target.style.backgroundColor = 'pink'
        })
    </script>
</body>
```

## BOM

Window对象是浏览器的顶级对象

1. 它是JS访问浏览器窗口的一个接口
2. 它是一个全局对象。定义在作用域中的变量，函数会变成window对象的属性和方法

==注意==：window下的一个特殊属性：window.name

### window属性

#### location属性

location是一个对象，用于获取或设置窗体的URL，并且可以用于解析

- 属性

  | 属性                   | 说明                                                  |
  | ---------------------- | ----------------------------------------------------- |
  | window.location.href   | 返回当前页面的URL                                     |
  | location.host          | 返回主机域名                                          |
  | location.port          | 返回端口号                                            |
  | location.pathname      | 返回路径                                              |
  | location.hash          | 返回片段 #后面的内容 常见于链接 锚点                  |
  | window.lacation.search | 返回参数：？键=值（var arr=substr（1）.split（“=”）） |
  |                        |                                                       |

- 方法

  | 方法      | 说明                                                         |
  | --------- | ------------------------------------------------------------ |
  | assign()  | 与改变href属性一样可以跳转页面，可以后退                     |
  | replace() | 替换当前页，不记录历史，无法后退                             |
  | reload()  | 重新加载页面，若参数为true会强制刷新，相当于浏览器上的刷新按钮 |

```html
    <script>
        var btn=document.querySelector('button');
        btn.addEventListener('click',function(){
            location.assign('案例/login.html');
            location.replace('案例/login.html');
            location.reload();
        })
    </script>
```

#### navigator属性 

包含有关浏览器的信息，常用window.navigator.userAgent,返回由客户机发送服务器的user-agent头部的值

#### histroy属性

| 方法      | 说明                          |
| --------- | ----------------------------- |
| back()    | 后退，相当于浏览器上的按钮    |
| forward() | 前进                          |
| go(1/-1)  | 1前进一个页面，-1后退一个页面 |

#### 其他常见属性

| 属性                     | 说明                                |
| ------------------------ | ----------------------------------- |
| window.page（Y/X）offset | 获取页面卷去的头部/左侧             |
| window.scroll(x,y)       | x,y不加单位，滚定至文档中的特定位置 |
| window.innerWidth        | 返回窗口宽度，无单位                |

### window事件

| 事件                                                         | 说明                                          |
| ------------------------------------------------------------ | --------------------------------------------- |
| window.onload=funtion(){}/window.addEventListenter('load',function(){}) | 在文档内容（css，js，html）全部加载完成后触发 |
| window.onDOMContentLoaded                                    | 在DOM加载完成后就触发                         |
| window.onresize                                              | 调整窗口大小时触发                            |

### 定时器

#### setTimeout

- 创建

  会返回一个定时器ID给变量

  var time = window.setTimeout(回调函数，[延迟的毫秒数])//在定时器到期后执行回调函数，==只调用一次==

- 清除

  clearTimeout(定时器ID)

#### setInterval

- 创建

  var time = window.setInterval(回调函数，[延迟的毫秒数])//每隔延迟的时间就调用一次，==会重复调用==

- 清除

  clearInterval(定时器ID)

### this指向问题

1. 在全局作用域，定时器，普通函数中this指向window，==注意==：箭头函数中的this指向上下文对象
2. 方法中的this指向调用者
3. 构造函数中的this指向实例

### JS执行对列

同步任务在主线程执行，形成一个执行栈。当有异步任务时，如ajax，DOM待触发事件，定时器。放入异步进程处理，触发后放入任务队列（异步队列），等待主线程执行完毕后，通过事件循环机制来任务队列中取出任务执行

<img src="D:\桌面\notes\JavaScript\assets\JS执行队列.png" style="zoom:150%;" />

# JS高级

## 类和对象

- 关键字：class

  注意:类中所有函数不需要加function关键字，多个方法间不加逗号分隔.

- 方法中的this指向：方法的调用者

### 构造器

- 关键字：constructor()

- 作用:用于传递参数，返回实例对象，new生成对象实例时自动调用。

  注意：如果未定义会自动创建一个constructor()

- this指向：实例对象

```html
 <script>
        class Star {
            constructor(uname, age) {
                this.uname = uname;
                this.age = age;
            }
            sing(song) {
                console.log(this.uname + song);
            }
        }
        var ldh = new Star('刘德华', 18);
        var zxy = new Star('张学友')
        console.log(ldh.uname + ldh.age);
        ldh.sing('冰雨')
    </script>
```

注意：

this的指向问题

```html
<body>
    <button>
        唱歌
    </button>
    <script>
        var that;
        class Father {
            //构造器里面的this指向实例对象
            constructor(uname, age) {
                that = this;
                this.uname = uname;
                this.age = age;
                // this.sing();
                this.btn = document.querySelector('button');
                this.btn.onclick = this.sing;//因为这个按钮调用了这个函数
            }
            //这个方法里的this 指向的是btn 这个按钮
            sing() {
                // console.log(this.uname);
                console.log(that.uname); //that 里面存储的是constructor里面的this
            }
        }
        var father = new Father('刘德华');
    </script>
</body>
```

## 类的继承

### 关键字

- ### entends

- 注意：ES6中类没有变量提升，必须先定义类，才能实例化

### 继承属性

调用父类构造函数：

- 关键字：super(x,y)

注意：在constructor中调用，且必须在子元素的this之前调用

```html
    <script>
        class Father {
            constructor(x, y) {
                this.x = x;
                this.y = y;
            }
            sum() {
                console.log(this.x + this.y);
            }
            money() {
                console.log(100);
            }
        }
        class Son extends Father {
            constructor(x, y) {
                super(x, y);
            }
        }
        var son = new Son(1, 2);
        son.money();
        son.sum();
    </script>
```

### 继承方法

- 子类实例会自动继承父类的方法

- 在子类中调用父类方法：
  - 关键字：super.父类方法名()

```html
    <script>
        class Father {
            say() {
                return '我是爸爸'
            }
        }
        class Son extends Father{
            say() {
                console.log(super.say()+'的儿子'); 
            }
        }
        var son = new Son();
        son.say();
```

- ### 扩展子类的方法

```html
    <script>
        class Father {
            constructor(x, y) {
                this.x = x;
                this.y = y;
            }
            sum() {
                console.log(this.x + this.y);

            }
        }
        class Son extends Father {
            constructor(x, y) {
                super(x, y);
                this.x = x;
                this.y = y;
            }
            sub() {
                console.log(this.x - this.y);
            }
        }
        var son = new Son(3, 1);
        son.sum();
        son.sub();
    </script>
```

## 构造函数和对象

1. 利用构造函数创建对象，首字母要大写（之前还有利用new Object(), 字面量的方法创建对象）

2. 通过this添加实例成员和实例方法

3. 构造函数名.属性名 || 方法名，添加静态成员和静态方法

   ==注意==：静态成员和方法只能通过构造函数来访问

   ```javascript
           function Star(uname, age) {
               this.uname = uname;//实例成员
               this.age = age;
               this.sing = function () {
                   console.log('我会唱歌');
               }
           }
           var ldh = new Star('刘德华', 13);
           Star.sex = '男';//静态成员
           Star.dance = function () {
               console.log('dance');
           }//静态方法
           console.log(Star.sex);
   ```


### 构造函数原型：prototype（原型对象）

- 构造函数通过原型分配的函数是所有对象所共享的

- 每一个构造函数都有一个prototype属性，这个属性就是一个对象，它所拥有的所有属性和方法，都会被构造函数所拥有，包函constructor指回构造函数，和proto属性指向父级的prototype

- 每一个实例对象也都有一个_proto_属性，也就是对象原型，指向构造函数的prototype

  注意：一般公共的属性定义到构造函数里面，公共的方法放入原型对象中

```javascript
        function Star(uname, age) {
            this.uname = uname;
            this.age = age;
        }
        //Star.prototype被对象赋值覆盖了，所以没有了constructor属性
        Star.prototype = {
            constructor: Star,//重新将构造器指回构造函数
            sing: function () {
                console.log('我会唱歌');
            },
            movie: function () {
                console.log('我演电影');
            }
        }
```

### 对象原型：_proto_

- 每个实例对象都会有一个属性proto向构造函数的prototype，但最终又通过prototype里的constructor指回构造函数
- 每一个构造函数的prototype（原型对象）中也有一个proto属性，指向父级构造函数的prototype

### 方法查找规则

1. 先看实例对象身上有没有a方法
2. 如果没有，通过proto指向去构造函数的prototype里找有没有
3. 如果没有，通过prototype执向父级构造函数的prototype里找有没有，直到找到object为止

### constructor

- proto中有一个constructor，最终通过prototype指回构造函数

- prototype中有一个constructor，指回构造函数

  注意：如果prototype被覆盖了，需要重新将constructor：构造函数名（重新指回构造函数）

### 原型链

![](D:\桌面\notes\JavaScript\assets\原型链.png)

```java
        function Star(uname, age) {
            this.uname = uname;
            this.age = age;
        }
        //Star.prototype被对象赋值覆盖了，所以没有了constructor属性
        Star.prototype = {
            constructor: Star,
            sing: function () {
                console.log('我会唱歌');
            },
            movie: function () {
                console.log('我演电影');
            }
        }
        var ldh = new Star('刘德华', 12);
        console.log(Star.prototype);
        console.log(Star.prototype.__proto__ === Object.prototype);
        console.log(Object.prototype.__proto__);
```

### 成员查找机制

1. 当访问一个对象的属性（包括方法时），首先查找这个对象自身有没有该属性
2. 如果没有就查找它的原型（也就是proto指向的prototype原型对象）
3. 如果还没有就查找原型对象的原型
4. 以此类推直到Object为止（null）
5. proto对象原型的意义就在于为对象成员查找机制提供一个方向路线

### this指向

1. 在构造函数中，里面的this指向的是实例对象
2. prototype中的this也指向实例对象，因为实例对象调用原型对象里面的方法

```javascript
        var that;

        function Star(uname, age) {
            this.uname = uname;
            this.age = age;
        }
        //Star.prototype被对象赋值覆盖了，所以没有了constructor属性
        Star.prototype = {
            constructor: Star,
            sing: function () {
                that = this;
                console.log('我会唱歌');
            },
            movie: function () {
                console.log('我演电影');
            }
        }
        var ldh = new Star('刘德华','12');
        ldh.sing();
        console.log(that === ldh);//true
        console.log(Star);
```

## 改变this指向

### this指向的4种形式

1. 一般函数，this指向全局对象window
2. 在严格模式下，为undefined
3. 对象的方法里调用，this指向调用该方法的对象
4. 构造函数里的this，指向创建出来的实例
5. 箭头函数中this指向上下文

### call

- 第一个参数：改变this指向
- 第二个参数：实参
- 使用时候会自动执行函数

### apply

- 第一个参数：改变this指向，在函数运行时才会改变this指向
- 第二个参数：数组（里面为实参）
- 使用时候会自动执行函数
- 主要应用：Math.max.apply(Math,arr)//这里this的指向还是Math不过可以比较数组中的最大值

### bind

- 第一个参数：改变this指向
- 第二个参数之后：实参
- 返回值为一个新的函数
- 使用的时候需要手动调用下返回 的新函数（==不会自动执行==）

## 原型继承

### 继承属性

通过构造函数+原型对象模拟实现继承，称为组合继承

**原理**：同call()把父类型的this改为子类型的this

```javascript
        //通过借用父构造函数来继承属性
        //1。父构造函数
        function Father(uname, age) {
            //this指向父构造函数的对象实例
            this.uname = uname;
            this.age = age;
        }
        //2.子构造函数
        function Son(uname, age) {
            //this指向子构造函数的对象实例
            Father.call(this, uname, age);
        }
        var ldh = new Son('刘德华', 12);
        console.log(ldh);
```

### 继承方法

**原理**：创建一个父类的实例，让子类的原型对象执向这个实例所在的内存空间，但是子类的prototype里的constructor被覆盖了，需要重新指向子类构造函数，这样就能通过父类实例的中的proto找到父类中的方法，且在子类中添加自己的私有方法也不会影响父类。

```javascript
        //通过借用父构造函数来继承属性
        //1。父构造函数
        function Father(uname, age) {
            //this指向父构造函数的对象实例
            console.log(this);
            this.uname = uname;
            this.age = age;
        }
        Father.prototype.money = function () {
            console.log(100000);
        }
        //2.子构造函数
        function Son(uname, age) {
            //this指向子构造函数的对象实例
            Father.call(this, uname, age);
        }
        //Son.prototype = Father.prototype;
        Son.prototype = new Father();
        Son.prototype.exam = function () {
            console.log('孩子要考试');
        }
        // var zxy = new Father('张学友', 12)
        var ldh = new Son('刘德华', 12);
        console.log(ldh);
        // console.log(zxy);
```

### 扩展内置对象

```javascript
        Array.prototype.sum = function () {
            var sum = 0;
            for (var i = 0; i < this.length; i++) {
                sum += this[i];
            }
            return sum;
        }
        var arr1 = new Array(11, 22, 33);
        console.log(arr1.sum());
```

## ES6中新增方法

### 数组方法

#### 遍历：forEach()

array.forEach(function(currentValue,index,arr))遍历每个元素，将每个元素的返回值给回调函数

- currentValue：数组当前项的值
- index：数组当前项的索引
- arr：数组对象本身

**注意**：如果return false会阻止函数继续向下执行，但不会结束遍历，会继续遍历下一个元素，无返回值

```javascript
        var arr = ['red', 'green', 'blue', 'pink'];
        arr.forEach(function (value) {
            if (value == 'green') {
                console.log('找到');
                return false;
            }
            console.log(11);           
        })
```

#### 筛选：filter()

array.filter(function(currentValue,index,arr))会返回一个新的数组，新数组中是通过检查指定数组中符合条件的所有元素，主要用于筛选数组

**注意**：直接返回新数组

```javascript
        var arr = [23, 13, 545, 52];
        var newArr = arr.filter(function (value, index, array) {
            return value >= 20;
        })
        console.log(newArr);//[23,545,52]
```

#### 检测数组中是否有满足条件的元素：some()

array.some(function(currentValue,index,arr))用于查找数组中是否有满足条件的元素

**注意**：

- 返回的是布尔值，找到返回true且找到后不会再继续执行，找不到返回false。

```javascript
        var arr = [3, 2, 3, 5, 5, 4, 23, 55, 45, 435, 3, 4524, 5, 245, 2, 52];
        var arr1 = arr.some(function (value, index, array) {
            return value >= 20;
        });
        console.log(arr1);//true
```

**区别**：foreach和filter不会终止迭代，some检测到符合要求的元素后会停止，且返回值三者不同

#### map()

map() 方法返回一个新数组，其结果是该数组中的每个元素都调用一个提供的函数后返回的结果。

```javascript
var array1 = [1,4,9,16];
const map1 = array1.map(x => x *2);
console.log(map1);
```

### 字符串方法

#### trim()

删除字符串两边的空格，不影响原字符串，==返回一个新的字符串==（防止用户输入空格）

### 对象方法

#### Object.keys()

- 用于获取对象自身所有的属性

- 返回由属性名组成的数组

```javascript
        var obj = {
            id: 1,
            pname: '小米',
            price: 1999,
            num: 2000
        }
        var arr = Object.keys(obj);
        console.log(arr);
```

#### Object.defineProperty()

- 定义对象中新属性或修改原有的属性
- obj：目标对象
- prop：要增加或修改的属性名字
- descriptor：增加或修改的属性所持有的特性
  1. value：设置属性的值，默认为undefined
  2. writable：值是否可以重写，默认为false，遍历时就无法遍历出来
  3. enumerable：目标属性是否可以被枚举，默认为false也遍历不出来
  4. configurable：目标属性是否可以别删除或者再次修改特性，默认false

```javascript
        Object.defineProperty(obj, 'num', {
            value: 20000,
            writable: false,
            enumerable: false,
            configurable: false
        })
        delete obj.num;
        console.log(obj);
```

## 函数

### 定义

1. 命名函数

   function fn(){ }

2. 匿名函数

   var fun = function() {}

3. new Function('参数1'，‘参数2’，‘函数体’)

   var f = new function();

   ==注意==：所有函数都是function的实例

![](D:\桌面\notes\JavaScript\assets\function.png)

### 调用方式和this指向

1. 普通函数

   fn();//实际上是windows.fn()

   this指向windows

2. 对象的方法

   obj.xxx();

   this指向对象

3. 构造函数里的方法

   function xxx(){}

   new xxx();

   this指向实例，包括构造函数的prototype原型对象里的this也指向实例

4. 事件函数

   btn.onclick=function(){}

   this执向调用者btn

5. 定时器函数

   setInterval(function(){},1000)//实际上是windows.setInterval

   this指向window，只能用bind(this)改变this指向，因为call和apply是立即执行。

6. 立即执行函数

   (function(){})()或者(function (){} ())

   this 指向windows

## 高阶函数

它接收函数作为参数，将函数的返回值作为输出

```javascript
/** 
 * 数值转换
 * @param {Number} val 要被处理的数值
 * @param {Function} fn 处理输入的val
 * @return {Number || String}
 */
const toConvert = function(val, fn) {
    return fn(val);
};

const addUnitW = function(val) {
    return val + 'W';
};

toConvert(123.1, Math.ceil); // 124
toConvert(123.1, addUnitW); // "123.1W"
```

另外，JS的回调函数同样是以实参形式传入其他函数中，这也是高阶函数（在函数式编程中回调函数被称为 lambda表达式）:

```javascript
[1, 2, 3, 4, 5].map(d => d ** 2); // [1, 4, 9, 16, 25]

// 以上，等同于：
const square = d => d ** 2;
[1, 2, 3, 4, 5].map(square); // [1, 4, 9, 16, 25]
```

## 严格模式

为脚本开启‘use strict’写在script标签第一行

为函数开启写在函数体第一行

### 特点

1. 变量必须先声名

   ==区别：==标准模式中

   ​			a=2||this.a=2是给window对象的一个属性，可以用delete删除

   ​			var a=2也是给window对象一个属性，但是不能用delete删除

2. 全局作用域中this是undefined，而不是windows对象

3. 构造函数不加new调用（不创建实例）的话会报错，因为严格模式中this为undefined，要new之后this才有指向的实例对象，标准模式中构造函数没有实例对象，它的this也是指向window对象的

   ==注意：==定时器的this还是指向window

4. 参数不能同名 

## 闭包

### 变量作用域

 - 局部变量
 - 全局变量
 - 当函数执行完毕，本作用域内的局部变量就会自动销毁
### 闭包的定义
指有权访问另一个函数作用域中变量的函数

### 闭包的作用
在函数a执行完毕并返回后，闭包使得Js的垃圾回收机不会回收a所占用的资源，因为a的内部函数b需要依赖a中的变量，从而延伸了变量的作用范围。

###### demo

```javascript
function fn() {
            var num = 10;
            return function fun() {
                console.log(num);
            };
        }
        //fn外面的作用域访问fn()内部的局部变量
        fn()();//10
```
### 闭包的例子

###### 获取ul中li的索引号

 - 最初的方法


```javascript
var lis = document.querySelector('.nav').querySelectorAll('li');
        for (var i = 0; i < lis.length; i++) {
            lis[i].setAttribute('index', i);
            lis[i].addEventListener('click', function () {
                console.log(this.getAttribute('index'));
            })
        }//在循环的同时给每个li添加自定义属性index，需要时再读取属性值
```

 - 利用闭包

```javascript
for (var i = 0; i < lis.length; i++) {
            //创建了4个立即执行函数
            (function (num) {
                lis[num].onclick = function () {
                    console.log(num);
                }func
            })(i)
        }
```
 这里面的闭包指的是匿名函数，通过(i)把值保存到了num中。每个点击事件都有一个局部变量num，num保存的是相应的i值。

 - 错误写法


```javascript
for (var i = 0; i < lis.length; i++) {
            lis[i].addEventListener('click', function () {
                console.log(i);
            })
        }//无论点击哪个li都输出4
```
每个li标签的onclick事件执行时，本身onclick绑定的function的作用域中没有变量i，i为undefined,则解析引擎会寻找父级作用域，发现父级作用域中有i，且for循环绑定事件结束后，i已经赋值为4，所以每个li标签的onclick事件执行时，log的都是父作用域中的i，也就是4。

###### 经典例子

```javascript
function fn() {
            var num = 3;
            return function () {
                var n = 0;
                console.log(++n);
                console.log(++num);
            }
        }
        fn()();// 1 4
        fn()();//1 4
        
        var f1 = fn();
        f1();//1 4
        f1();//1 5

        
```
直接调用fn函数，此时fn执行完后，就连同它的变量num一同销毁，但是如果将fn的返回值赋给f1，这时候相当于f1=function(){var n = 0};并且匿名函数内部引用这fn里面的变量num，所以变量num无法被销毁，而变量n在调用完后会销毁，在每次调用时新建，于是最后只剩下num，所以再次调用时num是在4的基础上+1。
### 定时器中的闭包函数

```javascript
		//3秒后同时打印所有li元素的内容
        var lis = document.querySelector('.nav').querySelectorAll('li');
        for (var i = 0; i < lis.length; i++) {
            (function (a) {
                setTimeout(function () {
                    console.log(lis[a].innerHTML);
                }, 3000)
            })(i);
        }
        
        //每隔3秒打印一个li元素的内容
        var lis = document.querySelector('.nav').querySelectorAll('li');
        for (var i = 0; i < lis.length; i++) {
            (function (a) {
                setTimeout(function () {
                    console.log(lis[a].innerHTML);
                }, a*3000)
            })(i);
        }
```

### 闭包的缺点
因为闭包会使得Js的垃圾回收机不会回收占用的资源，滥用闭包会造成内存泄露，所以在必要时，我们要及时释放这个闭包函数
### Let的出现
将上面的错误写法中的var改为let，let会产生块级作用域

```javascript
for (let i = 0; i < lis.length; i++) {
            lis[i].addEventListener('click', function () {
                console.log(i);
            })
        }//点击li输出相应的索引
```

## 递归

函数内部自己调用自己，作用和循环一样

注意：防止发生栈溢出，所以要加退出条件return

```html
<script>
        var data = [{
            id: 1,
            gname: '家电',
            goods: [{
                id: 11,
                gname: '冰箱',
                niubi: [{
                    id: 111,
                    gname: 'haha'
                }]
            }, {
                id: 12,
                ganme: '洗衣机'
            }]
        }, {
            id: 2,
            gname: '服饰'
        }]
        //输入id号返回数据对象
        // 1.利用forrach遍历
        function getid(json, id) {
            var o = {};
            json.forEach(function (value, index, json) {
                // console.log(value);
                if (value.id == id) {
                    // console.log(value);
                    o = value;
                    // 2.想要得到里层的数据 11 12
                    //里面应该有goods数组，且长度不为0
                } else if (value.goods && value.goods.length > 0) {
                    o = getid(value.goods, id);
                } else if (value.niubi && value.niubi.length > 0) {
                    o = getid(value.niubi, id);
                }


            });
            return o;
        };

        console.log(getid(data, 1));
        console.log(getid(data, 2));
        console.log(getid(data, 12));
        console.log(getid(data, 111));
    </script>
```

## 浅拷贝和深拷贝

- 浅拷贝只是拷贝一层，更深层次的对象级别的只拷贝引用（修改数据会修改原来的）

  ```javascript
  var obj1 = {
         name: 'zs',
         age: 18,
         sex: '男',
         dog: {
           name: '金毛',
           age: 2,
           yellow: '黄色'
         }
       }
  
       var obj2 = {};
  
  function copy(o1, o2) {
        for (var key in o1) {
          o2[key] = o1[key];
        }
      }
      copy(obj1, obj2);
  
      // 修改obj1中的成员
      obj1.name = 'xxxx';
      obj1.dog.name = '大黄';
  
      console.dir(obj2);
  // name 属性深拷贝,不改变;dog对象浅拷贝, dog.name 随之发生改变
  ```

  ES6语法糖：Object.assign(new,old)

- 深拷贝拷贝多层，每一级的数据都会拷贝

  ```javascript
          //深拷贝
          function deepcopy(newer, old) {
              for (var k in old) {
                  //判断属性值属于声明类型
                  // 1.获取
                  var item = old[k];
  
                  // 2.判断是否为数组
                  if (item instanceof Array) {
                      newer[k] = [];
                      deepcopy(newer[k], item)
                  } else if (item instanceof Object) {
                      // 3.是否为对象
                      newer[k] = {};
                      deepcopy(newer[k], item);
                  } else {
                      // 4.属于简单数据类型
                      newer[k] = item;
                  }
  
              }
          }
          deepcopy(b, obj);
          console.log(b);
          b.msg.age = 30;
          console.log(obj);
  ```

  ==注意==:先判断数组再判断对象，因为数组也属于对象，如果对象中没有function和RegExp且为json对象可以先用

  JSON.stringify转为字符串再用JSON.parse转为新的对象

## 正则

### 创建

- 利用RegExp对象创建

  ```javascript
  var regexp = new RegExp(/.../);///../里面不加引号
  ```

- 利用字面量创建

  ```
  var regexp = /.../
  ```

### 检测

test()  符合规范返回true，不符合规范返回false

### 特殊字符

#### 边界符

- ^：行首文本以谁开始

- &：行尾文本以谁结束

  /^abc$/

#### 字符类

- []

  ```
  /[abc]/
  表示包含有a或b或c得=的一个或多个
  /^[abc]$/
  表示有且仅有其中一个
  ```

#### 量词符

用于设定每个模式出现的次数

| 量词  | 说明                       |
| ----- | -------------------------- |
| *     | 重复0次或更多次            |
| +     | 重复一次或更多次           |
| ？    | 重复0次或一次              |
| {n}   | 重复n次                    |
| {n,}  | 重复n次或更多次            |
| {n,m} | 重复n次到m次（中间无空格） |

```javascript
/^a*$/
/^a{3,8}$/
/^abc{3}$/
/^[abc]{3}$/     //[]内的单个内容可以重复三次
/^(abc){3}$/     //()内的重复三次
```

### 正则中的预定义类

| 预定义类 | 说明                                                         |
| -------- | ------------------------------------------------------------ |
| \d       | 匹配0-9之间的任一数字                                        |
| \D       | 匹配0-9以外的字符，相当于/[^0-9]/                            |
| \w       | 匹配任意的字母，数字和下划线，相当于/[A-Za-z0-9_]/           |
| \W       | 除了所有字母，数字和下划线以外的字符，相当于/[^A-Za-z0-9_]/  |
| \s       | 匹配空格（包括换行符，制表符，空格符等），相当于[\t\r\\n\v\f] |
| \S       | 匹配非空格的字符，相当于/[^\t\r\n\v\f]/                      |

### 正则中的替换

- replace(//,'')只替换第一个，加上/g全局替换

  ```javascript
          btn.onclick = function () {
              div.innerHTML = text.value.replace(/激情|gay/g, '**');
          }
  ```

### 修饰符

- /g：全局匹配
- /i：忽略大小写
- /gi：全局匹配且忽略大小写

## ES6



### let

1. 产生块级作用域

2. for循环中防止i变成全局变量

3. let无变量提升（js预解析会把var和function（）{}提到最前面）

4. 暂时性死区

   ```javascript
           var tmp = 123;
           if (true) {
                   tmp = 'avd';
                   // let tmp;如果在if中需要用一样的变量名，用let声名
               }
               console.log(tmp);
   ```

   ```html
       <script>
           let arr = [];
           for (let i = 0; i < 2; i++) {
               arr[i] = function () {
                   console.log(i);
               }
           }
           arr[0]();
           arr[1]();
           //每次循环都会产生一个块级作用域，每个块级作用域中的变量都是不同的，函数执行时输出的是自己的上一级（循环产生的块级作用域）作用域下的i值
       </script>
   ```

### const

1. 用来声名常量，值无法更改

2. 也具有块级作用域，不存在变量提升

   ```javascript
           if (true) {
               const a = 10;
               if(true){
                   const a=20;
                   console.log(a);
               }
               console.log(a);
           }
   ```

3. 必须赋初始值

4. 赋值后的内存地址不能修改，但是复杂数据类型内的值可以改

   ```javascript
   const arr=[100,100];
   arr[0]='a';//这里没有修改内存地址，所以是可以修改的
   arr=['a',100];//这里修改了内存地址，所以是无法修改的
   ```

### 解构赋值

如果解构后无值则为undefined

```javascript
        //数组解构
        let [a, b, c] = [1, 2, 3];
        console.log(a);
        let person = {
            name: 'xuqianzhou',
            age: 13
        };

        let {
            name,
            age
        } = person;
        console.log(name);
```

### 箭头函数

- 不能使用argunments来获取参数

- 函数体只有一句可以省略大括号

- 只有一个参数可以省略括号

- 箭头函数不绑定this关键字，箭头函数中的this指向的是函数定义位置上下文的this

  ```javascript
      <script>
          const add = (a, b) => {
              console.log(a + b);
          }
          add(1, 3);
  
          const obj = {
              name: 'zhangsan'
          }
  
          function fn() {
              console.log(this);
              return () => {
                  console.log(this);//这里两个this相同
  
              }
          }
          const fun = fn.call(obj);
          fun();
      </script>
  ```

  注意：

  ```javascript
          var age = 100;
          var obj = {
              age: 20,
              say: () => {
                  console.log(this);//这里的this指向window
                  alert(this.age);
              }
          }
          obj.say();
  ```

### 剩余参数

- 将不定数量的参数表示为一个数组

  ```javascript
        const sum = (num, ...arr) => {
              console.log(num);
              console.log(arr);
              let total = 0;
              arr.forEach(item => total += item);
              return total;//50
          };
         console.log( sum(10, 20, 30));
  ```

- 可以配合解构使用

  ```javascript
  var obj={xxx,xxx,xxx};
  let {s1,...s2}=obj;//s1是obj对象中的第一个数据，剩下的在s2数组中
  ```

### Array的扩展方法

#### 扩展运算符

将数组或对象转为用逗号分隔的参数序列，其实就是和剩余参数一个相反的过程，这里用逗号拆开，剩余参数是合并为一个数组

```javascript
let arr=[1,2,3];
log(...arr)//1 2 3(逗号被log当作参数分隔符)
```

- 可以用于合并数组

  ```javascript
  arr1=[1,2,3];
  arr2=[4,5,6];
  arr3=[...arr1,...arr2];
  //或者
  arr1.push(...arr2);
  ```

- 可以将伪数组转为真正的数组

  ```javascript
  //方法一：
  arr2=[...arr1];//arr1是伪数组；
  //方法二：
  let arr2=Array.form(arr1,item=>item+1);//将arr1伪数组转为真正的数组，并且每个数组元素加1
  ```

#### Array.form()

将伪数组转为数组且对元素进行加工

#### Array.find()

用于找出第一个符合条件的数组成员，如果没有找到则返回==undefined==

```javascript
let arr[{
id:1,
name:'张三'
},{
id:2,
name:'李四'
}]；
let target = arr.find((item,index)=>item.id==2);//函数用于返回查找的条件
```

#### Array.findindex()

用于找出第一个符合条件的数组成员的==位置==，如果没有返回==-1==

```javascript
let arr=[1,5,9,15];
let index=arr.findindex((value,index)=>value>9);//函数用于返回查找的条件
log(index);//2
```

#### Array.includes()

表示某个数组是否包含给定的值，返回布尔值

```javascript
arr=[1,2,3];
arr.includes(2);//true
```

### String的扩展方法

#### 模板字符串

- 可以解析变量

  ```javascript
  `hello,my name is${变量名}`
  ```

- 可以换行

- 可以调用函数

  ```javascript
  const sayhello = function(){
  return....;
  }
  let agree = `hello,my name is ${sayhello()}`
  ```

#### startsWith()

是否以某字符开头，返回布尔值

startsWith('Hello')

#### endsWith()

是否以某字符结尾，返回布尔值

endsWith('!')

#### repeat()

将原字符重复n次，返回一个新的字符串

str.repeat(3);

### set数据结构

- 类似于数组，但是成员不能重复,会自动去重

  ```javascript
  const s = new Set();
  const s = new Set([1,2,3,4,4])//可以接收数组初始化，会自动去重4
  ```

- 数据数量

  s.size();

- 可以用于数组去重

  ```javascript
  var arr = [1,2,3,4,4];
  const s = new Set(str);
  var arr = [...s];//这里用扩展运损符将s用逗号分隔开
  ```

#### 实例方法

- add(value):添加某个值，返回Set结构本身
- delete(value):删除某个值，返回布尔值，表示是否和删除成功
- has(value):返回布尔值，表示该值是否为set的成员
- clear():清除所有成员，没有返回值

#### Set遍历

和数组一样有foreach方法，无返回值

##### s.forEach(value=>log(value))