## 1d.介绍js的基本数据类型

```
undefined，Null，Boolend，Number，String，还有Symbol类型 代表创建后独一无二不可变的数据类型，它的出现主要解决可能出现的全局变量冲突问题。
```

## 2.JS有几种数据类型的值?你能画一下他们的内存图吗

```
JS中有两种类型的值，一种是数据类型，一种是复杂数据类型。
基本数据类型：undefined，null，number，string，symbol，boolean。
复杂数据类型：指的是Object类型，所有其他的如Array，Data等数据类型都可以理解为Object类型的子类。
两种类型间的主要存储位置不同，基本数据类型的值直接保存在栈中，而复杂数据类型的值保存在堆中。通过使用栈中所对应的指针来获取堆中的值。
```

## 3.什么是堆？什么是栈？他们之间有什么区别和联系？

```
堆和栈的概念存在于数据结构中和操作系统内存中。
在数据结构中，栈中数据数据是先进后出。而堆是一个优先队列，是按优先队列来进行排序的，优先级可以按照大小快规定。完全二叉树是堆的一种表现方式。
在操作系统中，内存被分为栈区和堆区。
	栈区内存由编译器自动分配释放，存放函数的参数值，局部变量的值等。其操作方式类似于数据结中的栈。
	堆区的内存一般由程序员分配释放，如果程序员不释放，程序结束时可能由垃圾回收机制回收(引用计数法和标记清除法)
```

## 4.内部属性[[class]]是什么？

```
所有typeof返回为"Object"的对象(加数值)都包含一个内部属性[[class]](我们可以把它当作一个内部的分类,而非传统的面向对象意义上的类)。这个属性无法直接访问，一般通过Object.prototype.toString(...)来查看。例如：
Object.prototype.toString.call([1,2,3]);
//"[object Array]"
Object.prototype.toString.call(/regex-literal/i);
//"[object RegExp]"
```

## 5.介绍js有哪些内置对象

```
js中的内置对象主要指的是在程序执行前存在全局作用域的由js定义的一些全局值属性，函数和用来实体化其他对象的构造函数对象。一般我们经常用到的如全局变量值NaN,undefined，全局函数如parseInt() parseFloat() 用来实体化对象的构造函数如Date,Object等，还有提供数学计算的单位内置对象如Math对象。
```

## 6.undefined和undeclared的区别？

```
已在作用域中但是还没有赋值的变量，是undefined。还没有在作用域中声明过的变量，是undeclared的。
对于underclared变量的引用，浏览器会报引用错误，如ReferenceError: b is not defined。但是我们可以使用typeof的安全防范机制来避免错误，因为对于undeclared(或者 not defined)变量，typeof会返回"undefined"。
```

## 7.null和undefined的区别？

```
JavaScript的最初版本是这样区分的：null是一个表示"无"的对象，转为数值时为0；undefined是一个表示"无"的原始值，转为数值时为NaN。

null表示"没有对象"，即该处不应该有值。
undefined表示"缺少值"，就是此处应该有一个值，但是还没有定义。

undefined代表的含义是未定义，null代表的含义是空对象。一般变量声明了还没有定义返回undefined,null主要用于赋值给一些可能会返回对象的变量，作为初始值。

当我们对两种类型使用typeof进行判断的时候，Null类型化会返回"object"，这是一个历史遗留的问题。当我们使用双等号对两种的值进行比较会返回true，使用三等好时会返回false。
```

## 8.如何获取安全的undefined值？

```
因为undefined是一个标识符，所以可以被当成变量来使用和赋值，但是这样会影响undefined的正常判断。
表达式void__没有返回值，因为返回的结构是undefined。void 并不改变表达式的结果，只是让表达式不返回值
```

## 9.说几条写javascript的基本规范？

```
1.一个函数作用域中所有的变量声明应该尽量提到函数首部，用一个var声明，不允许出现两个联系的var声明，声明时如果变量没有值，应该给该对象类型的初始值，便于他人阅读代码时，能够一目了然的知道变量对于的类型值。
2.代码中出现地址，时间等字符串时需要使用常量代替。
3.在进行比较的时候，尽量使用'===','!=='代替'==','!='。
4.不要在内置对象的原型上添加方法，如Array，Date。
5.switch语句必须带有default分支。
6.for循环必须有大括号。
7.if语句必须有大括号。
```

## 10.JavaScript原型，原型链？有什么特点？

```
	在js中我们是使用构造函数来创建一个对象的，每一个构造函数的内部都有一个prototype属性值，这个属性值是一个对象，这个对象包含了可以由该构造函数的所有实例共享的属性和方法。当我们使用构造函数新建一个对象后，在这个对象的内部包含一个指针指向构造函数的prototype属性对应的值，在ES5中这个指针被称作为对象的原型。一般来说我们是不应该能够获取这个值的，但是现在浏览器中都实现了__proto__属性来让我们访问这个属性，但是我们最好不要使用这个属性，因为它不是规范中规定的，es5中新添加了一个Object.getprototypeof()方法，我们可以通过这个属性来获取对象的原型。  
	当我们访问一个对象的属性时，如果这个对象内部不存在这个属性，那么它就会去它的原型对象里找这个属性，这个原型对象又会由自己的原型，于是就这样一直找下去，也就是原型链的概念。原型链的尽头一般来说是object.prototype所有这就是我们新建对象为什么能够使用toString()等方法的原型。
特点:
	javascript对象是通过引用来传递的。我们创建的每个新对象实体中并没有一份属于自己的原型符本。当我们修改原型时，与之相关的对象也会继承这一改变。(contruct:star)。
```

## 11.js获取原型的方法

```
p.__proto__
p.construct.prototype
Object.getprototypeof(p)
```

## 12.在js中不同进制数字的表达方式

```
1.以0x,OX开头的十六进制
2.以0,0O,0o开头的为八进制
3.以0B,0b开头的二进制格式
```

## 13.js中整数的安全范围是多少？

```
安全整数指的是，在这个范围内的整数转化为二进制存储的时候不会出现精度丢失，能够被"安全"呈现的最大整数时2^53-1。即9007199254740991,在ES6中被定义为Number.MAX_SAFE_INTEGER。最小整数是-9007199254740991，在ES6中被定义为 Number.MIN_SAFE_INTEGER。如果某次计算的结果得到了一个超过JS数值范围的值，那么这个值会被自动转换为特殊的Infinity值。如果某次计算返回了正的或者负的Infinity值，那么该值将无法参与下一次的计算。判断一个数是不是有穷，可以使用isFinite函数来判断。
```

## 14.typeof NaN结果时什么？

```
NaN意指"不是一个数值"(Not a Number)，NaN是一个"警戒值"(sentinel value，有特殊用途的常规值),用于指出数字类型中的错误情况。即"执行数学运算没有成功，这是失败后返回的结果"。
typeof NaN //"number"
NaN是一个特殊值，它和自身不相等，是唯一一个非自反(自反，reflexive，即 x===x不成立的)的值，而NaN!=NaN为true
```

## 15.isNaN和Number.isNaN函数的区别?

```
	函数isNaN接收参数后，会尝试将这个参数转换为数字，任何不能被转化为数值的值都会返回true，因此非数值的参数传入也会返回true，会影响NaN的判断。
	函数Number.isNaN会首先判断传入的参数是否为数字，如果是数字再执行是否为NaN，这种方法对于NaN的判断更为准确。
	console.log(isNaN('测试')) //true
	console.log(Number.isNaN('测试')) //false
```

## 16.Array构造函数只有一个参数值时的表现？

```
	Array构造函数只带一个数字参数的时候，该参数会被作为数组的预设长度(length),而非只充当数组中的一个元素。这样创建出来的就是一个空数组，只不过它的length属性被设置成了指定的值。
	构造函数Array(..)不要求必须带new关键字。不带时，它会自动补上。
```

## 17.其他值到字符串的转换规则

```
规范的9.8节中定义了抽象操作ToString，它是负责非字符串到字符串的强制类型转换。
1.Null和undefined类型，null转换成"null",undefined转换成"undefined"。
2.Boolean类型，true转换成"true"，false转换为"false"。
3.Number类型的值直接转换，不过那些极小和极大的数字会只用指数形式。
4.Symbol类型的值直接转换，但是只允许显示强制类型，使用隐式强制类型转换会产生错误。
5.对于普通对象来说，除非自定义toString()方法,否则会调用toString()(object.prototype.toString())来返回内部属性[[class]]的值，如"[object Object]"。如果对象有自己的toString()方法，字符串化时就会调用该方法并使用其返回值。
```

## 18.其他值转到数字值的转换规则。

```
有使我们需要将非数字值当作数字来使用，比如数学运算。为此ES5规范再9.3节定义了抽象操作ToNumber。
1.undefined类型的值转换成NaN。 ！
2.nunll类型的值转换为0。 ！
3.Boolean类型的值,true转换为1，false转换为0。
4.String类型的值转换如同使用Number()函数进行转换,如果返回的是非数字的基本类型值,则再遵循以上规则将其强制转换为数字。
5.symbol类型不能转换成数字，会报错。
6.对象(包括数组)会首先被转换为相应的基本数据类型，如果返回的是非数字的基本类型，则再遵循以上规则将其强制转换为数字。为了将值转换成相应的基本类型值，抽象操作ToPrimitive会首先(通过内部操作DefaultValue)检查该值是否有valueof()方法。如果有并且返回基本值类型，就使用该值进行强制类型转换。如果没有就使用toString()返回值(如果存在)来进行强制类型转换。
如果valueof()和toString()均不返回基本类型值，会产生TypeError错误。
```

## 19.其他值转到布尔类型的值的转换规则？

```
以下这些是假值:
	1.undefined
	2.null
	3.false
	4.+0,-0和NaN
	5.""
假值的布尔强制类型结果为false。从逻辑上说，假值列表以外的都应该是真值。
```

## 20.{}和[]的valueOf和toSting 的结果是什么？

```
{}的valueOf结果为{},toString 的值为"[object Object]"
[]的valueOf结果为[],toString 的值为""
```

## 21.什么是假值对象？

```
浏览器在某些特定情况下,在常规js语法基础上自己创建了一些外来值，这些就是"假值对象"。假值对象看起来和普通对象并无二致(都有属性，等等)，但将它们强制类型转换为布尔型时结果为false最常见的例子是document.all，它是一个类数组对象，包含了页面上的所有元素，由DOM(而不是JS引擎)提供给JS程序的。
```

## 22.~操作符的作用？

```
~返回2的补码，并且~会将数字转换成32位整数，因此我们可以使用~来进行取整操作。
~x大致等同于-(x+1)。
```

## 23.解析字符串中的数字和将字符串强制类型转换成数字的返回结果都是数字，它们之间的区别是什么？

```
解析允许字符串(如parseInt())中含有非数字字符串，解析按从左到右的顺序，如果遇到非数字数字字符。而转换(如Number()不允许出现非数字字符，否则会失败并返回Null。
```

## 24.+操作符什么时候用于字符串的拼接？

```
如果+的其中一个操作时字符串，则实行字符串拼接，否则执行数字加法。那么对于除了加法的运算符来说，只要其中一方是数字，那么另一方就会被转为数字。
```

## 25.什么情况下会发生布尔值的隐式强制类型转换？

```
1.if(..)语句中打的条件判断表达式。
2.for(..;..;..)语句中条件判断表达式(第二个)。
3.while(..)和do..while(..)循环中的条件判断表达式。
4.? : 中的条件判断表达式。
5.逻辑运算符 || 和 &&左边的操作数。
```

## 26.||和&&操作符的返回值？

```
	||和 && 首先会对第一个操作数执行判断，如果不是布尔值就先进行ToBoolean强制类型转换，然后再执行条件判断。
	对于||来说，如果条件判断结果为true就返回第一个操作数的值，如果条件判断结果时false就返回第二操作数的值。
	对于&&来说，如果条件判断结果为ture就返回第二个操作数的值，如果为false就返回第一个操作数的值
```

## 27.Symbol 值的强类型转换？

```
Symbol不允许强类型转换为数字，但是可以被强类型转换为布尔值(true)
```

## 28.==操作符的强制类型转换规则？

```
1.字符串和数字进行比较 字符串转成数组进行比较。
2.布尔型和其他类型进行比较，先将布尔型转化成数字后再进行比较。
3.null和undefined之间的相等比较，返回值为true。其他值和它们进行比较都返回假值。
4.对象和非对象之间进行比较，对象先调用ToPrimitive抽象操作后，再进行比较。
5.如果一个操作值时NaN，则相等比较返回false(NaN本身也不等NaN)，是唯一一个非自反的值。
6.如果两个操作值都是对象，则比较它们是不是指向同一个对象，如果是同一个对象则返回true，否则返回false。
```

## 29.如何将字符串转化成数字，例如'12.3b'？

```
1.使用Number(),前提是字符串里面不包含不合法字符。
2.使用parseInt()方法,parseInt()函数可解析一个字符串，并返回一个整数，还可以设置要解析的数字的基数。当基数的值为0，或没有设置该参数时，parseInt()会按照string来判断数字的基数。
3.使用parseFloat()方法,该函数解析一个字符串参数返回一个浮点数。
4.使用+操作符的隐式转换。
```

## 30.如何将浮点数左边的每三位添加一个逗号，如12000000.11转化成12.000.000.11？

```js
function format(number){
	return number && number.replace(/(?!^)(?=(\d{3})+\.)/g,",") 
}
```

## 31.常用正则表达式

```js
（1）匹配 16 进制颜色值 var regex = /#([0-9a-fA-F]{6}|[0-9a-fA-F]{3})/g; 
（2）匹配日期，如 yyyy-mm-dd 格式 var regex = /^[0-9]{4}-(0[1-9]|1[0-2])-(0[1-9]|[12][0-9]|3[01])$/; 
（3）匹配 qq 号 var regex = /^[1-9][0-9]{4,10}$/g; 
（4）手机号码正则 var regex = /^1[34578]\d{9}$/g; 
（5）用户名正则 var regex = /^[a-zA-Z\$][a-zA-Z0-9_\$]{4,16}$/;
```

## 32.生成随机数的各种方法？

### 一.随机浮点数生成

1.生成[0,1)范围内的随机数(大于等于0,小于1)

```js
Math.random()
```

2.生成[n,m)范围内的随机数(大于等于n,小于m)

```
Math.random()*(m-n)+n
```

3.生成[n,m]、(n,m)、(n,m]范围内的随机数

```js
/* [n,m]*/
function fullClose(n,m)
{
	var result=Math.random()*(m-n+1)+n;
    while(result>m)
    {
    	result=Math.random()*(m-n+1)+n;
    }
    return result;
}

/* (n,m) */
function fullOpen(n,m){
    var result=Math.random()*(m-n)+n;
    while(result==n)
    {
       result=Math.random()*(m-n)+n;
    }
    return result;
}
/*(n,m]*/
function leftOpen(n,m)
{
   	var result=Math.random()*(m-n+1)+n-1;
    
}
```

### 二、随机整数的生成

要生成随机整数，我们还需要借助如下两个方法：

- **Math.round(num)**：将 **num** 四舍五入取整
- **Math.floor(num)**：将 **num** 向下取整，即返回 **num** 的整数部分。当然我们也可以使用 **parseInt()** 方法代替。
- Math.ceil()  向上取整。

1，随机生成 0、1 这两个整数

```
Math.round(Math.random())
```

2.生成[0,n)范围内随机的整数(大于等于0，小于n)

```
Math.floor(Math.random()*n)
```

3.生成[1,n]范围内的随机整数(大于等于1,小于n)

```
Math.floor(Math.random()*n)+1;
```

4.生成[min,max]范围内的随机整数(大于等于min,)

```
Math.floor(Math.random()*(max-min+1)+min
```

## 33.如何实现数组的随机排序？

1.使用数组sort方法对数组元素随机排序，让Math.random()出来的数与0.5比较，如果大于就返回1交换位置，如果小于就返回-1，不交换位置

```css
function randomSort(a,b){
	return Math,random()>0.5?-1:1;
}
缺点:每个元素被派到新数组的位置不是随机的，原因是sort()方法是依次比较的。
```

2.随机从原数组抽取一个元素，加入到新数组

```js
function randomSort(arr){
	var result=[];
	while(arr.length>0)
	{
		var randomIndex=Math.floor(Math.random()*arr.length);
		result.push(arr[randomIndex]);
		arr.splice(randomIndex,1);
	}
	return result;
}
```

3.随机交换数组内的元素()

```js
function randomSort(arr){
	var index,randomIndex,temp,ken=arr.length;
	for(index=0;index<len;index++)
	{
		randomIndex=Math.floor(Math.random()*(len-index)+index);
		temp=arr[index];
		arr[index]=arr[randomIndex];
		arr[randomIndex]=temp;
	}
	return arr;
}
```

4.es6

```js
function randomSort(array) 
{ 
	let length = array.length;
	if (!Array.isArray(array) || length <= 1) return; 
	for (let index = 0; index < length - 1; index++) 
	{ 
		let randomIndex = Math.floor(Math.random() * (length - index)) + index; 
		[array[index], array[randomIndex]] = [array[randomIndex],array[index]];
    }
	return array; 
}
```

## 34.原型继承

```js
/*
继承:子类继承父类中的属性和方法(目的是让子类的实例能够调用父类的属性和方法)。
方案一:原型继承
	让父类的属性和方法在子类实例的原型链上
	child.prototype=new Parent()
	child.prototype.constructor=child
特点:
	1.不像其他语言中的继承一样(子类继承父类，会把父类的属性和方法拷贝一份到子类中，供子类的实例调取使用)，它是把父类的原型放到子类实例的原型链上，实例想调用这些方法，是基于__proto__原型链查找机制完成的。
	2.子类可以重写父类上的方法(这样会导致父类其他实例也受到影响)
	3.父类中私有或者共有的属性方法，最后都会变成子类中公有的属性和方法。
*/
function A(X){
    this.x=x;
}
A.prototype.getX=function(){
    console.log(this.x);
}

function B(y){
    this.y=y;
}
B.prototype=new A(200);
B.prototype.constructor=B;
B.prototype.getY=function(){
    console.log(this.Y);
}
let b1=new B(100);
```

[![GeIlKx.jpg](https://s1.ax1x.com/2020/03/30/GeIlKx.jpg)](https://imgchr.com/i/GeIlKx)

## 35.CALL继承和寄生组合继承

```
/*
	call继承的特点:
		child方法中把parent当作普通函数执行，让parent中的this指向child的实例，相当于给child的实例设置了私有的属性和方法
		1.只能继承父类私有的属性和方法。(因为是把parent当作普通函数执行，和其原型中的属性和方法没有关系)
		2.父类私有变成子类私有的
*/
function A(X){
    this.x=x;
}
A.prototype.getX=function(){
    console.log(this.x);
}

function B(y){
	//=> this:B的实例b1
	A.call(this,200);// => b1.x=200
    this.y=y;
}
B.prototype.getY=function(){
    console.log(this.Y);
}
let b1=new B(100);
```

**寄生组合继承**

```
/*
	寄生组合继承:call继承+类似于原型继承
	特点:父类私有共有的分别是子类实例的私有和公有属性方法(推荐)
*/
function A(X){
    this.x=x;
}
A.prototype.getX=function(){
    console.log(this.x);
}
function B(y){
	//=> this:B的实例b1
	A.call(this,200);// => b1.x=200
    this.y=y;
}
// =>Object.create(obj):创建一个空对象__proto__指向obj
B.prototype=Object.cearte(A.prototype);// B的原型对象(通过调用.__proto__)指向A的原型对象
B.prototype.getY=function(){
    console.log(this.Y);
}
let b1=new B(100);
```

[![Ge7NiF.jpg](https://s1.ax1x.com/2020/03/30/Ge7NiF.jpg)](https://imgchr.com/i/Ge7NiF)

## 36.Object.create()和new Object()的区别

1.创建对象的方式不同

new Object() 通过构造函数来创建对象, 添加的属性是在自身实例下。
Object.create() es6创建对象的另一种方式，可以理解为继承一个对象, 添加的属性是在原型下。

```
// new Object() 方式创建
var a = {  rep : 'apple' }
var b = new Object(a)
console.log(b) // {rep: "apple"}
console.log(b.__proto__) // {}
console.log(b.rep) // {rep: "apple"}

// Object.create() 方式创建
var a = { rep: 'apple' }
var b = Object.create(a)
console.log(b)  // {}
console.log(b.__proto__) // {rep: "apple"}
console.log(b.rep) // {rep: "apple"}
```

Object.create()方法创建的对象时，属性是在原型下面的，也可以直接访问 b.rep // {rep: "apple"} ,此时这个值不是吧b自身的，是它通过原型链**proto**来访问到b的值。

2.创建空对象时不同

![img](https://upload-images.jianshu.io/upload_images/7513201-a06bc354493335e4.png?imageMogr2/auto-orient/strip|imageView2/2/format/webp)

当用构造函数或对象字面量方法创建空对象时，对象时有原型属性的，即有`_proto_`;
当用Object.create()方法创建空对象时，对象是没有原型属性的。

3.Object.create()是es6新语法 存在兼容性问题， 我们可以进行重写

描述：该方法创建一个新对象，使用现有的对象来提供新创建的对象的`__proto__`；
 格式：Object.create(proto[, propertiesObject])
 用法：如果用传统的方法要给一个对象的原型上添加属性和方法，是通过 `__proto__` 实现的

```
var proto = {
    y: 20,
    z: 40,
    showNum(){}
};
var o = Object.create(proto);
```

![img](https://upload-images.jianshu.io/upload_images/7513201-a3d597f848465865.png?imageMogr2/auto-orient/strip|imageView2/2/format/webp)

如果是不用Object,create()方法，我们是如何给对象原型添加属性和方法的？
------ 通过构造函数或者类，例如：

```js
//创建一个构造函数或者类
var People = function(){}
People.prototype.y = 20
People.prototype.showNum = function() {}
//通过构造函数创建实例
var p = new People();
console.log(p.__proto__ === People.prototype) // true
```

![img](https://upload-images.jianshu.io/upload_images/7513201-63cefaeb389a5307.png?imageMogr2/auto-orient/strip|imageView2/2/format/webp)

4.重写create方法

```
Object.creat=function(obj){
	let oo={};
	oo.__proto__=obj; //ie浏览器禁用了
	return oo;
}

Object.creat=function(obj){
	function Fn(){};
	Fn.prototype=obj;
	return new Fn();// 实例里面的存在__proto__ (原型)
}
```

## 37.ES6中的继承

```
//ES6中基于class创造出来的类不能当作普通函数执行
//不允许重定向原型的指向 Object.creat(A.prototype);
class A{
	construct(x){
		this.x=x;
	}
	getX(){
		console.log(this.x);
	}
}
A.prototype.lx=100;// class里面不允许写类型

// 原理类似于寄生组合 B.prototype.__proto__=A.prototype
class B extends A{
	// 子类只要继承父类，可以不写constructor 一旦写了，则在construct中的第一句话必须是super();
	// 不写constructor，浏览器会自己默认创建
	// constructor(...args){super(...args)}
	constructor(y){
		super(200);// =>A.call(this,200)把父类当作普通方法去执行，给方法传递参数，让方法中的this是子类的实例
		this.y=y;
	}
	getY(){
		console.log(this.y);
	}
}
```

## 38.JS的作用域链

```
作用域的作用是保证对执行环境有权访问的变量和函数的有效方法问，通过作用域链，我们可以访问到外层变量和函数。作用域的查找是由内到外。(当我们查找一个变量时,如果当前环境变量中没有找到，我们可以沿着作用域链往后查找)。作用域链的创建过程跟执行上下文的建立有关....
```

## 39.谈谈this对象的理解

```
this是执行上下文的一个属性，它指向最后依次调用这个方法的对象。在实际开发中，this的指向是可以通过四种模式来判断的。
1.函数调用模式，直接作为函数调用的时候，this指向全局变量。
2.方法调用模式，如果一个函数作为一个对象的方法进行调用，this指向这个对象。
3.构造器调用模式，如果一个函数用new调用时，函数执行前会新建一个对象，this指向这个新建对象。
4.apply，call和bind调用模式，这三种方法都可以实显示的指定调用函数的this指向。
这四种方式，使用构造器调用模式的优先级最高，然后是apply，call，bind调用模式，然后是方法是调用模式，然后是函数调用模式。

在某些情况下，优势也会带来劣势。当要求动态上下文的时候，你就不能使用箭头函数，比如：定义方法，用构造器创建对象，处理时间时用 this 获取目标。
```

## 39.1什么时候不能使用this对象

```
1.获取DOM对象：
let domObj = document.getElementId('xx')
domObj.addEventListener('click', () => { console.log( this ) }, false)
根据上面的this指向可知，如果改为箭头函数，其内部this会变成window，而不是domObj，因此不推荐使用箭头函数。
2.对象内部声明方法时，不建议使用箭头函数，因为this会指向外面的函数而不是调用它的那个对象
let obj = { 
     fn: () => {  console.log(this) }  // window
}
3.在构造函数的pretotype上添加方法不建议使用箭头函数:
Array.prototype.add = () => { console.log(this) }  // window
4.Vue的生命周期钩子函数:
其默认指向当前vm组件，如果使用箭头函数声明，则会改变其指向。
```

## 40.eval是做什么的？

```
它的功能是把对应的字符串解析成js代码并运行。eval可以将一个JSON字符串转化成JSON对象 相当于JSON.parse();
应该避免使用eval，不安全，非常耗性能(2次，一次解析成js语句，一次执行)。
```

## 41.什么是Dom和BOM？

```
DOM指的是文档对象模型，它指的是把文档当作一个对象来对待，这个对象主要定以了处理网页内容的方法和接口。
BOM指的是浏览器对象模型，它指的是把浏览器当作一个对象来对象，这个对象主要定义了与浏览器进行交合的法和接口。BOM的核心是window，而window对象具有双重角色，它既是通过js访问浏览器的窗口的一个接口，又是一个全局对象。这意味着在网页中定义的任何对象，变量和函数，都作为全局对象上的一个属性或方法存在。window对象含有location对象，navigator对象，scrren对象等子对象，并且DOM的最根本的document对象也是BOM的window对象的子对象
```

## 42.写一个通用的事件监听器函数。

```js
const EventUtils={
    // 视能立分别用dom0||dom2||IE方式 来绑定事件
    // 添加事件
	addEvent:function(ele,type,handler){
		if(ele.addEventListener)
		{
			ele.addEventListener(type,handler);
		}else if(ele.attachEvent){
			ele.attachEvent('on'+type,handler);
		}else{
			ele['on'+type]=handler;
		}
	},
    // 移除事件
    removeEvent:function(ele,type.handler){
        if(removeEventListener){
            ele.removeEventListener(type,handler,false);
        }else if(ele.detachEvent){
            ele.detachEvent('on'+type,handler);
        }else{
            ele['on'+type]=handler;
        }
    },
    // 获取事件目标
    getTarget:function(ele){
        return ele.target||ele.srcElement;
    },
    // 获取event对象的引用，取到事件的所有信息，确保随时能使用event
    getEvent:function(ele){
		return ele||window.ele;
    },
    //阻止事件(主要是事件冒泡，因为IE不支持事件捕获)
    stopPropagation:function(event){
        if(event.stopProgapation){
            event.stopPropagation();
        }else(event.cancelBubble){
            event.cancelBubble=true;
        }
    },
    // 取消事件的默认行为
    preventDefault:function(event){
        if(event.preventDefault){
            event.preventDefault();
        }else{
			event.returnValue=false;
        }
    }
}
```

## 43.事件是什么，IE和火狐的事件处理机制有什么区别？如何防止冒泡？

```
1.事件是用户操作页面发生的交互动作，如click/move，事件除了用户触发的动作外，还可以是文档加载，窗口大小滚动和大小调整。事件被封装成一个event对象，包含了该事件发生时的所有相关信息(event的属性)以及可以对事件进行的操作(event)。
2.事件处理机制：IE支持冒泡，firefox同时支持两种事件模式，事件冒泡和事件捕获。
3.event.stopPropagation()或者ie下的event.cancelBubble=true;
```

## 44.三种事件模型是什么？

```
事件是用户操作网页时发生的交互动作或者网页本身的一些操作。
1.DOM0级模型，这种模型不会传播，所以没有事件流的概念，但是现在有的浏览器支持以冒泡的方式实现，它可以在网页中直接定义监听函数，也可以通过js属性来指定监听函数。这种方法时所有浏览器都兼容的。
2.IE事件模型，在该事件模型中，一次事件共有两个过程，事件处理阶段，和事件冒泡阶段。事件处理阶段首先执行元素绑定的监听事件。然后是事件冒泡阶段，冒泡指的是事件从目标元素冒泡到document，依次检查经过的点是否绑定了监听函数，如果有则执行。这种模型听歌attachEvent来监听函数，可以添加多个监听函数，会按顺序依次执行。
3.DOM2级事件模型，在该事件模型中，一个事件共有三个过程，第一个过程是事件捕获阶段。捕获指的是事件从document一直向下传播到目标元素，依次检查经过的节点是否绑定了事件监听函数，如果有则执行。后面两个阶段和IE事件模型的两个阶段相同。这种事件模型，事件绑定的函数时addEventListener,其中第三个参数可以指定函数是否捕获阶段执行
```

## 45.事件委托是什么？

```
事件委托是利用事件冒泡机制。因为事件在冒泡过程中会上传到父节点，并且父节点可以通过事件对象获取到目标节点，因此可以把子节点的监听函数定义到父节点上，由父节点的监听函数统一处理多个子元素的事情。这种方式叫做事件代理。
使用事件代理我们我们可以不必要为每一个元素都绑定一个监听事件，这样减少了内存上的消耗，并且使用事件代理我们还可以实现事件的动态绑定，比如说新增了一个子节点，我们并不需要单独的为它添加一个监听事件，它所发生的事件会交给父元素中的监听函数来处理。
```

## 46.["1", "2", "3"].map(parseInt) 答案是多少？

```
parseInt() 函数能解析一个字符串，并返回一个整数，需要两个参数 (val, radix)，其中 radix 表示要解析的数字的基 数。（该值介于 2 ~ 36 之间，并且字符串中的数字不能大于 radix 才能正确返回数字结果值）。
此处 map 传了 3 个参数 (element, index, array)，默认第三个参数被忽略掉，因此三次传入 的参数分别为 "1-0", "2-1", "3-2"
第一次：parseInt("1",0)    //第二参数为0相当于默认的方法，所以得到了1
第二次：parseInt("2",1)    //由于第二参数为1小于2了，所以得到了NaN
第三次：parseInt("3",2)    //虽然第二参数2符合条件，但是参数一3并不能当成二进制解释，所以得到了NaN
```

## 47.什么是闭包，为什么要用它？

```
闭包是指有权访问另一个函数作用域中变量的函数，创建闭包最常见的方式就是在一个函数内创建另一个函数可以访问当前函数的局部变量。
闭包有两个常用用途。
1.是我们在函数外部访问函数内部的变量。
2.让这些变量始终保存在内存中。
形成的条件：
    1.函数嵌套
    2.内部函数引用外部函数的局部变量
闭包的优点
    延迟外部函数局部变量的生命周期
闭包的缺点
    容易造成内存泄漏
注意点：
    1.合理的使用闭包
    2.用完闭包要即使清除(销毁)
```

## 48.JS代码中的"use strict";是什么意思？使用它区别是什么？

```
use strict是es5添加的(严格)运行模式，这种模式使得JS在更严格的模式下运行。
设置"严格模式"的目的，主要有以下几个:
	- 消除JS语法的一些不合理，不谨慎指出，减少一些怪异行为；
	- 消除代码运行的一些不安全之处，保证代码运行的安全。
	- 提高编程效率，提高运行速度
	- 为未来新版本的JS做好铺垫。
区别：
	1.禁止使用with语句。
	2.禁止this关键字指向全局对象。
	3.对象不能有重名属性。
	
回答：
	use strict指的是严格运行模式，在这种模式对js的使用添加了一些限制。比如说禁止this指向全局变量，还有禁止使用with语句等。设置严格模式的目的，主要为了清除代码使用中的一些不安全的使用方法，也是为消除JS语法本身的一些不合理的地方，从此来减少一些运行时的怪异的行为。同时使用严格模式能提高编译的效率，从而提高代码的运行速度。
	我认为严格模式代表了js一种更合理，更安全，更谨慎的发展方向。
```

## 49.如何判断一个对象是否属于某个类？

```
1.使用instanceof运算符来判断构造函数的prototype属性是否出现在对象的原型链中的任何位置。
2.通过对象的constructor属性来判断，对象的constructor属性指向该对象的构造函数，但是这种方法是不是很安全，因为constructor属性可以被重写。

function cat(){}
var b = new cat();
if(b instanceof cat){
    console.log("a是cat")
}
if(b.constructor==cat){
    console.log("a是cat")
}

3.如果需要判断的时某个内置的引用类型的话，可以使用Object.prorotype.toString()方法来打印对象的[[class]]属性来判断。
```

## 50.instanceof的作用

```
instanceof 运算符用于判断构造函数的prototype属性是否出现在对象的原型链中的任何位置。
实现:
	function myInstanceof(left,right){
		let proto=Object.getPrototypeOf(left), //获取对象的原型
		prototype=right.prototype //获取构造函数的prototype对象
		//判断构造函数prototype是否在对象的原型链上
		while(true)
		{
			if(!proto) return false;
			if(proto===prototype) return true;
			proto=Object.getPrototypeOf(proto);
		}
	}
```

## 51.new操作符具体干了什么呢？如何实现

```js
1.首先创建了一个新的空对象。
2.设置原型，将对象的原型设置为函数的prototype对象。
3.让函数的this指向这个对象，执行构造函数的代码(为这个新对象添加属性)。
4.判断函数的返回值类型，如果是值类型，返回创建的对象，如果是引用类型，就返回这个引用类型的对象。
实现：
// 创造一个对象
// 将构造函数的作用域赋给新对象 this执行新创建的对象
// 执行构造函数中的代码
// 判断:如果传入的对象的类型是值类型，则返回创建的对象；如果是引用类型则返回引用类型对象
function New() {
    var obj = {};
    // obj = Object.create(Constroctor.prototype);
    var Constroctor = [].shift.call(arguments);
    var result = Constroctor.apply(obj, arguments);
    obj.__proto__ = Constroctor.prototype;
    return typeof result === 'object' ? result : obj;
}
function person(name, age) {
    this.name = name;
    this.age = age;
}
var c = New(person, 'zs', 12);
var d = New(Object);
console.log(c);
console.log(d);
```

## 52.JS中，有一个函数，执行时对象查找时，永远不会去查找原型，这个函数是？

```
hasOwnProperty
所有继承了Object的对象都会继承到hasownProperty方法，这个方法可以用来检测一个对象是否含有自身属性，和in运算符不同，该方法会忽略原型链上继承的属性。
```

## 53.对于JSON的了解？

```
JSON是一种数据交换格式，基于文本，优于轻量，用于交换数据。
JSON可以表示数组，布尔值，字符串，null，数组(值得有序序列)，以及由这些值(或数组，对象)所组成得数组(字符串与值得映射)。
JSON使用JS语法，但是JSON格式仅仅是一个文本，文本可以被任何编程语言读取及作为数据格式传输
```

**回答**

```
	JSON是一种基本文本的轻量级的数据交换格式。它可以被任何编程语言读取和作为数据格式来传递。
	在项目开发中，我们使用JSON作为前后端交换的方式。在前端我们通过一个符合JSON格式的数据结果序列化为JSON字符串传递到后端，后端通过JSON格式的字符串解析后生成对应的数据结构，以此来实现前后端数据的一个传递。
	因为JSON的语法是基于JS的，因此很容易JS中的对象弄混，但是我们应该注意的是JSON和JS中的对象不是一回事，JSON中对象格式更加严格，比如JSON中属性值不能为函数，不能出现NAN这样的函数值等，因此大多数JS对象不符合JSON对象的格式。
	在JS中提供两个函数来实现JS数据结构和JSON格式的转换处理。一个是JSON.stringify函数，通过传入一个符合JSON格式的数据结构，将其转换成一个JSON字符串。如果传入的数据结构不符合JSON格式，那么在序列化的时候，会对这些值进行对应的特殊处理，使其符合规范。在前端向后端发送数据时，我们可以调用这个函数将数据对象转成JSON格式的字符串。
	另一个函数JSON.parse()函数，这个函数用来将JSON格式的字符串转为一个js数据结构，如果传入的字符串不是标准的JSON格式的字符串的话，就会抛出错误。当我们从后端接收到JSON格式的字符串时，我们可以通过这个方法来将其解析为一个js数据结构，以此来进行数据的访问。
```

## 54.JS延迟加载的方式有哪些？

```
js延迟再加载，也就是等页面加载完成之后再加载JS文件，JS延迟加载有助于提高页面的加载速度。
一般有以下几种方式
	defer 属性
	async 属性
	动态创建DOM方式
	使用setTimeout延迟加载
	让js最后加载
```

**回答**

```
JS的加载，解析和执行会阻塞页面的渲染过程，因此我们希望JS脚本能够尽可能的延迟加载，提高页面的渲染速度。
我了解到的几种方法是。
	1.我们一般采用是将js脚本放到文档的底部，来使JS脚本京可能在最后来加载执行。
	2.给js脚本加载defer属性，这个属性会让脚本的加载与文档的解析同步解析，然后再文档解析完成后再执行或者脚本文件，这样的话就能使页面的渲染不被阻塞。多个设置了defer属性的脚本按规范来说是顺序执行的，但是在一些浏览器中可能不是这样的。
	3.给js脚本添加async属性，这个属性会是脚本异步执行，不会阻塞页面的解析过程，但是当脚本加载完成后立即执行JS脚本，这个时候如果文档没有解析完成的话同样会阻塞，多个async属性的脚本的执行属性是不可预测的，一般不会按照代码的顺序依次执行。
	4.动态创建DOM标签的方式，我们可以对文档的加载事件进行监听，当文档加载完成后再动态script标签来引入js脚本。
```

## 55.Ajax是什么？如何创建一个Ajax？

```
0：请求未初始化。
1：请求已建立。
2：请求已接受。
3：请求处理中。
4：请求已完成，且响应已就绪。
status:200 ok 后端服务器。

function ajax (options) {
	// 存储的是默认值
	var defaults = {
		type: 'get',
		url: '',
		data: {},
		header: {
			'Content-Type': 'application/x-www-form-urlencoded'
		},
		success: function () {},
		error: function () {}
	};
	// 使用options对象中的属性覆盖defaults对象中的属性
	Object.assign(defaults, options);

	// 创建ajax对象
	var xhr = new XMLHttpRequest();
	// 拼接请求参数的变量
	var params = '';
	// 循环用户传递进来的对象格式参数
	for (var attr in defaults.data) {
		// 将参数转换为字符串格式
		params += attr + '=' + defaults.data[attr] + '&';
	}
	// 将参数最后面的&截取掉 
	// 将截取的结果重新赋值给params变量
	params = params.substr(0, params.length - 1);

	// 判断请求方式
	if (defaults.type == 'get') {
		defaults.url = defaults.url + '?' + params;
	}

	// 配置ajax对象
	xhr.open(defaults.type, defaults.url);
	// 如果请求方式为post
	if (defaults.type == 'post') {
		// 用户希望的向服务器端传递的请求参数的类型
		var contentType = defaults.header['Content-Type']
		// 设置请求参数格式的类型
		xhr.setRequestHeader('Content-Type', contentType);
		// 判断用户希望的请求参数格式的类型
		// 如果类型为json
		if (contentType == 'application/json') {
			// 向服务器端传递json数据格式的参数
			xhr.send(JSON.stringify(defaults.data))
		}else {
			// 向服务器端传递普通类型的请求参数
			xhr.send(params);
		}

	}else {
		// 发送请求
		xhr.send();
	}
	// 监听xhr对象下面的onload事件
	// 当xhr对象接收完响应数据后触发
	xhr.onload = function () {
		// xhr.getResponseHeader()
		// 获取响应头中的数据
		var contentType = xhr.getResponseHeader('Content-Type');
		// 服务器端返回的数据
		var responseText = xhr.responseText;
		// 如果响应类型中包含applicaition/json
		if (contentType.includes('application/json')) {
			// 将json字符串转换为json对象
			responseText = JSON.parse(responseText)
		}

		// 当http状态码等于200的时候
		if (xhr.status == 200) {
			// 请求成功 调用处理成功情况的函数
			defaults.success(responseText);
		}else {
			// 请求失败 调用处理失败情况的函数
			defaults.error(responseText);
		}
	}
	
}

ajax({
	type: 'get',
	// 请求地址
	url: 'http://localhost:3000/responseData',
	success: function (data) {
		console.log('这里是success函数');
		console.log(data)
	},
	error:function(data){
		console.log(data);
	}
})

我对ajax的理解是，它是一种异步通信的方法，通过直接由js脚本向服务器发起http通信，然后根据服务器返回的数据，更新页面相对应部分，而不是刷新整个页面的一种方法。
创建一个ajax有这样几个步骤
首先是先创建一个XMLHttpRequest对象。
然后再这个对象上使用open方法创建一个http请求，open方法所需要的参数是请求的方法，请求的地址，是否异步和用于的认证信息。
如果是post或者json请求我们需要设置对应的请求头setRequestHeader('Content-Type','application/json'||'application/s-www-from-urlencoded');
然后通过xhr.onload来监听 如果有getRequestHeader('Content-Type')请求头 我们需要将后台返回的数据转成JSON对象形式。
最后看xhr的状态码是否为200 若是 则default:success(xhr.resposeText);
```

## 56.谈一谈浏览器的缓存机制？

```js
浏览器的缓存机制指的是通过在一段时间内保存已接接收的web资源的副本，如果在资源得有效时间内，发送了对这个资源的再一次请求，那么浏览器会直接使用缓存的符文，而不是向服务器发送请求。使用web缓存可以有效的提高了页面的打开速度，减少了不必要的网络带宽的消耗。
	web资源的缓存一般有服务器来决定，可以分为两种强缓存和协商缓存。
	使用强缓存的适合，如果缓存资源有效，则直接使用缓存资源，不必再向服务器发送请求。强缓存可以通过两种方式来设置，分别是http头信息的Expires和cache-control属性。
	浏览器通过设置Expires属性，来指定的属性过期时间。在这个过期时间内，不必再向服务器发送请求。这个时间是一个绝对时间，它是服务器的时间，因此可能存在这样的问题，就是客户端和服务器端时间不一致，或者用户可以对客户端的时间进行修改的情况，这样就会影响缓存命中的结果。
	Expries是http1.0中的方式。因为它有这个缺点，在http1.1中提出了一个新的http头部属性就是cache-control属性，它提供了对资源的缓存的更精确的控制。它有很多不同的值，常用的比如我们可以通过设置max-age来指定资源能够被缓存的时间的大小，这是一个相对时间，它会根据这个时间和资源第一次请求的时间来计算出资源过期的时间，因此相对于Expires来说，这种方法更有效一些。还有如no-store，用来指定资源不允许被缓存。no-cache代表该资源能够被缓存，但是立即失效，每次都要向服务器发送请求。常用的还有private，用来规定资源能够被客户端存储不能被代理服务器所缓存。一般来说只需要设置设置一种方式就可以实现强缓存策略，当两种方式一起使用的cache-control的优先级大于Expires。
	使用协商缓存策略，会向服务器发送一个请求，如果资源没有发生修改，则返回一个304状态，让浏览器使用本地的缓存副本。如果资源发送了修改，则返回修改后的资源。协商缓存也可以通过两种方式进行设置一种是Etag和Last-modified属性。
	服务器通过在响应头中添加last-modified属性来指出资源最后一次被修改的时间，当服务器下一次发送请求时，会在请求头中添加if-modified-since属性，属性值为上一个资源的modified的值，当请求发送到服务器后服务器会通过这个属性来和资源的最后一次修改时间来进行比较，以此来判断资源是否做了修改。如果资源没有修改，那么返回304状态码，让客户端使用本地缓存。如果资源被修改了，则返回修改后的资源。使用这个方法的缺点。就是Last-modified标注的最后修改时间只能精确道秒级，如果某些文件在1s内修改多此的话，那么文件已经改变了但是Last-modified却没有改变，这样就会造成缓存结果的不准确。
	因为Last-Modified的这种可能会发生的不准确性，http中提供了另外一种方式，那就是Etag属性。服务器在返回资源的时候，在头信息中添加Etag属性，这个属性是资源生成的唯一标识符，当资源发生改变的时候，这个值也会发生改变。在下一次资源请求的时，浏览器会在请求头中添加一个If-None-Match属性，这个属性的值就是上次请求资源的Etag的值，服务器接受请求后会根据这个值和资源当前的Etag的值来进行比较，以此来判断资源是否发生了改变，是否需要返回资源。通过这种方式比Last-Modified的方式更加精确。
	当Last-Modified和Etag同时出现的时候，Etag的优先级高于Last-Modified。使用协商缓存的时候如果需要考虑平衡负载的问题，因此多个服务器上的Last-modified应该保持一致，因为每个浏览器上Etag 的值不一样，因此在考虑平衡负载的时，最好不要使用Etag属性。
	强缓存和协商缓存在缓存命中时都会使用本地的缓存副本，区别在于协商缓存会向服务器发送一次请求。它们缓存不命中时，都会向浏览器发送请求资源。在实际的浏览器缓存中，强缓存和协商缓存是一起合作使用的。浏览器首先会更具请求的信息判断，强缓存是否命中，如果命中则直接使用资源。如果不命中则根据头信息发起请求，使用协商缓存，如果协商缓存命中，则服务器不返回资源，浏览器直接使用本地资源的符本。如果协商缓存不命中，则浏览器返回最新的资源给浏览器。
```

## 57.Ajax解决浏览器缓存问题？

```
1.在ajax发送请求前加上anyAjaxObj.setRequestHeader("if-modified-since","0");
2.在ajax发送请求前面加上anyAjaxObj.setRequestHeader("if-modified-since",'no-cache');
3.在URL后面加上一个随机数:"fresh="+Math.random();
4.在URL后面加上一个时间戳:"nowtime="+new Date.getTime();
5.如果是使用JQ,直接使用&.ajaxSetup({cache:flase})。这样页面的所有ajax都会执行这条语句就是不需要保持缓存记录
```

## 58.同步和异步的区别

```
同步指的是当一个进程在执行某个请求的时候，如果这个请求需要等待一段时间才能返回，那么这个进程就会一致等待下去，直到信息返回为止再继续向下执行。
异步指的是当一个进程再执行某个请求的时候，如果这个请求需要等待一段时间才能返回，这个进程继续往下执行，不会阻塞等待信息的返回，当消息返回时系统再通知进程进行处理。
```

## 59.什么是浏览器的同源政策

```
一个域名下的js脚本在未经允许下不能访问另一个域的内容。这里的同源只是两个域的协议，域名，端口号必须相同，否则则不属于同一个域。
同源政策主要限制了三个方面。
1.当前域下的js脚本不能访问其他域下的cookie。localstorage和indexDB。
2.当前域下的js脚本不能不能操作访问其他域名下的DOM
3.当前域下ajax无法发送跨域请求。
同源政策的目的是为了保证用户的信息安全。他只是对js脚本的一种限制，并不是对浏览器的限制，对于一般img和script脚本请求都不会有跨域的限制，这是因为这些操作都不会通过响应结果来进行可能出现问题的操作
```

## 60.如何解决跨域问题？

```
常用的几个
1.使用Jsonp来实现跨域请求，它的主要原理是通过动态创建script标签来实现跨域请求，因为浏览器对script标签的引入没有跨域限制。通过在请求的url后指定一个回调函数，然后服务器在返回数据的时候，构建一个Json数据的包装，这个包装就是回调函数，然后返回前端，前端接收道数据后，因为请求的是脚本文件，所以会直接执行，这样我们先定义好的回调函数就可以被调用，从而实现了跨域请求的处理，这种方法只能用于get请求。
2.使用CORS的方式，CORS是一个w3c标准，全程是"跨域请求共享"。CORS需要浏览器和服务器同时支持。目前，所有的浏览器都支持该功能，因此我们只需要在服务器端配置就行。服务器将CORS请求分为两类：简单请求和非简单请求。对于简单请求，浏览器直接发送CORS请求。具体来说就是在头信息之中，增加一个Origin字段。Origin字段用来说明本次请求来自哪个源。服务器根据这个值，决定是否同意这次请求。对于如果Origin指定的源，不在允许访问内，服务器会返回一个正常的http回应。浏览器发现，这个回应的头信息没有包含Access-Control-Allow-Origin字段，就知道出错了，从而抛出一个错误，ajax不会收到响应信息。如果成功的话会包含一些以Access-Control-开头的字段。非简单请求，浏览器会先发出一次预检请求，来判断该域名是否在服务器的白名单中，如果收到肯定回复后才会发起请求。
Access-Control-Allow-Origin // 允许哪些客户端访问我。
Access-Control-Allow-Methods // 允许哪些方法访问我
7.使用websocket协议，这个协议没有同源限制。
8.使用服务器代理跨域的访问请求，就是有跨域请求的操作时发送给后端，让后端代为请，然后最后将获取的结果返回
```

## 61.简单谈一下cookie？

```
cookie是服务器端提供的一种用于维护会话状态信息的数据，通过服务器发送给浏览器，浏览器保存在本地，当下一次有同源请求的时候，将保存的cookie信息添加到请求头部，发送给客户端。这可以用来实现记录用户登录状态等功能。cookie一般用于存储4k大小的数据，并且只能够被同源的网页所共享访问。
服务器端可以使用set-Cookie的响应头部来配置cookie信息。一条cookie包括了5个属性值expires，domain，path，secure，HttpOnly。其中expires指的是cookie失效时间，domain指的是域名，path是路径，domain和path一起限制了cookie能够被哪些url访问。secure规定了cooke只能确保安全的环境下传输，httponly规定了这个cookie只能被服务器所访问，不能使用js脚本访问。
只发生在xhr的跨域请求的时候，即使是同源下的cookie，也不会被自动添加到请求头部，除非显示的规定。
```

## 62.模块化开发怎么做？

```js
一个模块实现一个特定功能的一组方法，在最开始的时候，js只实现了一些简单的功能，所有没有模块的概念，但随着程序越来越复杂，代码的模块化开发变得越来越重要。
由于函数具有独立作用域的特点，最原始的写法是使用函数作为模块，几个函数作为一个模块，但是这种方式容易造成全局变量的污染，并且模块间没有联系。
后面提出了对象写法，通过将函数作为一个对象的方法来实现，这样解决了直接使用函数作为模块的一些，但是这种方法会暴露所有的模块成员，外部代码可以修改内部属性的值。
现在最常用的是立即执行函数的写法。通过利用闭包来实现模块化私有作用域的建立，同时不会对全局变量造成污染。
(function(win){
	function aFn(){
        /...
    }
    function bFn(){
        //...
    }
    win.myMethod={aFn.bFn}
})(window)

但是现实是 页面引入过来的script会造成 请求过多 依赖模糊 难以维护
```

## 63.js的几种模块规范？

```
js中出现比较成熟的有四种模块加载方案。
1.CommonJS方案，它通过require来引入模块，通过module.exports定义模块的输出接口。这种模式加载方案是服务器端的解决方法，它是以同步的方式引入模块的，因为在服务器文件都是存储在本地磁盘，所以读取非常块，所以以同步的加载。但是如果是在浏览器端，由于模块的加载是使用网络请求，因此使用异步加载的方式更合适。
2.AMD方案，这种方案是通过异步加载的方式来加载模块，模块的加载不影响后面语句的执行，所有依赖这个模块的语句都定义了一个回调函数，等到加载完成再执行回调函数，require.js实现了AMD规范。define(['有依赖的参数'],function('对应参数'){}) 通过return {} 暴露模块
main.js 立即执行函数 对应依赖的参数所在位置 requirejs(['有依赖的参数'],function(){....})
3.CMD方案，这种方案和AMD方法都是为了异步解决模块加载问题，sea.js实现了CMD规范。它和require.js的区别在于模块定义时对依赖模块的处理不同和对依赖时机的处理不同。
define(function(require,exports,module){
	// 同步引入
	let module2=require('./module2');
	module2();
	//异步引入
	require.async('./module3',function(module3){
		module3.module3.fun();// module3暴露的是对象
	})
})
4.ES6提出的方法，使用import和export的形式引入引出模块。
// 常规暴露
export function foo(){}
import {foo} from './module1.js';

// 默认暴露 可以暴露0任意数据类型，暴露什么数据接收到的就是什么数据
export default{
	mag:"默认暴露",
	foo(){
		console.log('我是默认暴露的箭头函数');
	}
}
import module3 form './module3.js'
```

## 64.AMD和CMD规范的区别

```
它们之间的最主要区别有两个方面。
1.在模块的定义时对依赖的处理不同。AMD模块定义时对依赖前置加载,在定义模块的时候就要声明其依赖模块,CMD模块定义时是后置加载。只有在用到某个模块的时候再去require
2.对依赖模块的执行时机处理不同,首先AMD和CMD对于模块的加载都是异步加载，不过它们的区别在于模块的加载时机。AMD在依赖模块加载完成之后就直接执行依赖模块，依赖模块的执行顺序和我们的书写顺序不一定一致，而CMD在依赖模块加载完成之后并不执行，只是下载而已，等到所有的依赖模块都加载好后，进入回调函数逻辑，遇到require语句的时候时才执行对应的模块，这样模块的执行顺序和我们书写的顺序保持一致了。

// AMD 推荐
define(['./a','./b'],functiona(a,b)){//依赖必须一开始写好
	a.doSomething();
	b.doSomething();
}
// main.js 入口文件
(function(){
	requirejs.config({
		baseUrl:'js/',// 基本的路径 出发点在根目录下
		paths:{
			dataService:'./modules/dataService',
			alerter:'./modules.alerter',
		}
		shim:{
			angular:{
				exports:'angularr'
			}
		}
	})
	
	requirejs(['alerter','angular'],function(alerter,angular){
		alerter.showMsg();
		console.log(angular);
	})
})

//CMD
define(function(require,esports,module){
	var a=require('./a');
	a.doSomething();
	require.async('./module3',function(module3){
		module3.module3.fun(); //module3 返回的是一个对象
	})
})

//main.js
define(function(require){
	let module1=require('./module1');
	console.log(module1.foo());
	let module4=require('./module4');
	module4.fun2();
})
```

## 65.ES6模块与CommonJS模块，AMD，CMD的差异

```
1.CommonJS模块输出的是一个值的拷贝，ES6模块输出的是值的引用。CommonJS模块模块输出的是值的拷贝，也就是说，一旦输出一个值，模块内部的值就影响不到这个值。ES6模块的运行机制和CommonJS不一样。JS引擎对脚本静态分析的时候，遇到模块加载命令import，就会生成一个只读引用。等到脚本真正执行时，再根据这个只读引用，到被加载的那个模块里面去取值。
2.CommonJS模块时运行时加载，ES6模块时编译时输出接口。CommonJS模块就是对象，即在输入时是先加载整个模块，生成一个对象，然后再从这个对象上读取方法，这种加载称为"运行时加载"。而ES6模块不是对象，它的对外接口只是一种静态定义，在代码静态解析阶段就会生成。
```

## 66.requireJS的核心原理是什么？(如果动态加载的？如何避免多此加载的？如何缓存的)

```
require.js的核心原理是通过动态创建scirpt脚本来异步引入模块，然后对每个脚本的load事件进行监听，如果每个脚本都加载完成了，再执行回调函数。
```

## 67.JS模块加载器的轮子怎么造，也就是如果是如何实现一个模块加载器？

```

```

## 68.ES6怎么写class，为什么会出现class这种东西

```
在我看来ES6新添加的class只是为了补充js中缺少的一些面向对象语言的特征，但本质上说它只是一个语法糖，不是一个新的东西，其背后还是原型继承的原理。通过加入class可以有利于我们更好的组织代码。在class中添加的方法，其实是添加在类的原型上的。
```

## 69.document.write和innerHTML的区别？

```
document.write的内容会代替整个文档内容，会重写整个页面。
innerHTML 的内容只是代替指定元素的内容，只会重写页面中的部分内容。
```

## 70.DOM操作--怎么添加，移除，移动，复制，创建和查找节点？

```
1.创建新的节点
createElement(node)
createTextNode(text)
2.添加，移除，替换，插入
appendChild(node)
removeChild(node)
repalceChild(new,old)
insertBefor(new,old)
3.查找
getElementById()
getElementByName()
getElementByClassName()
querySelector()
querySelectorAll()
4.属性操作
getAttribute(key)
setAttribute(key)
hasAttribute(key)
removeAttribute(key)
```

## 71.innerHTML与outerHTML的区别？

```
对于一个HTML元素: <div>content<br/></div>
innerHTML:内部HTML,content<br/>
outerHTML:外部HTML,<div>content<br/></div>
innerHTML:内部文本,content
outerHTML:内部文本,content
```

## 72.call()和apply的区别？

```
它们的作用一模一样，区别仅在于参入参数的形式不同。
apply接收两个参数，第一个参数指定函数内this对象的指向，第二个参数为一个带下标的集合，这个集合可以为数组，也可以为伪数组，apply方法把这个集合中的元素作为参数转递给被调的函数。
call传入的参数数量不固定，跟apply相同的是，第一个对象也是代表函数的this指向，从第二个参数开始往后，每个参数都被依次传入函数。
```

## 73.JS类数组对象的定义？

```
一个拥有length属性和若干索引属性的对象可以被称为类数组对象。类数组对象和数组类似，但是不能调用数组的方法。
常见的类数组有arguments和DOM方法的返回结果，还有一个函数可以被看做是类数组对象，因为它含有lenght属性值，代表可接受的参数个数
常见的类数组转换为数组的方法有这样几种？
1.通过call调用数组的slice方法来实现转换
Array.prototype.slice.call(arrayLike);
2.通过call调用数组的splice方法来实现转化
Array.prototype.splice.call(arrayLike,0);
3.通过apply调用数组里的concat方法来实现转化
Array.prototype.concat.apply([],arrayLike)
4.通过Array.from方法来实现转化
Array.from(arrayLike)
```

## 74.数组和对象有哪些原生方法，举例一下？

```
数组和字符串的转换方法:toString(),join,toLocalString(),其中join方法可以指定转换为字符串时的分隔符。
数组的尾操作pop()和push(),push方法可以传入多个参数
数组的头操作shift()和unshift()
重排序的方法reverse()和sort,sort()方法可以传入一个函数来进行比较,传入前后两个值，如果返回值为蒸熟，则交换两个参数的位置。
数组连接方法concat(),返回的是拼接好的数组,不影响原数组。
数据截取方法slice(),用于截取数组中的一部分挥发，不影响原数组
数组的插入方法splice(),影响原数组
查找指定项的索引值indexOf()和lastIndexOf()
迭代方法 every() some() filter() map() 和forEach()方法
数组归并方法reduce()和reduceRight()方法
```

## 75.数组的fill方法？

```
fill()方法用一个固定的值填充一个数组中从起始索引到终止索引内的全部元素。不包括终止索引。fill方法接受三个参数value,start以及end,start和end参数是可选的，其默认值分别是0,this对象的length属性值。
```

## 76.[,,,]的长度

```
一般情况下是默认忽略的 但是 JSON 中并不允许尾后逗号。仅仅包含逗号的函数参数定义或者函数调用会抛出SyntaxError。而且，当使用剩余参数的时候，并不支持尾后逗号

function f(,) {} // SyntaxError: missing formal parameter
(,) => {};       // SyntaxError: expected expression, got ','
f(,)             // SyntaxError: expected expression, got ','

function f(...p,) {} // SyntaxError: parameter after rest parameter
(...p,) => {}        // SyntaxError: expected closing parenthesis, got ','

JSON.parse('[1, 2, 3, 4, ]');
JSON.parse('{"foo" : 1, }');
// SyntaxError JSON.parse: unexpected character 
// at line 1 column 14 of the JSON data 去掉就好了
```

## 77.JS中的作用域与变量声明提示

```
变量提升的表现是，无论我们在函数中何处位置声明的变量，好像都被提升到了函数首部，我们可以在变量声明前访问到而不会报错。
造成变量声明提升的本质原因是JS引擎在代码执行前有一个解析的过程，创建了执行上下文，初始化了一些代码执行时需要用的对象。当我们访问一个变量时，我们会到当前执行上下文中作用域链中去查找，而作用域链的首段指的是当前执行上下文的变量对象，这个变量对象是执行上下文的一个属性，它包含了函数的形参，所有的函数和变量声明，这个对象是在代码解析的时候创建的，这就是变量提升的根本原因。
```

## 78.如何编写高性能的JS？

```
1.用简单的位元素代替四则元素。
2.避免过深的嵌套循环。
3.不要使用未定义的变量。
4.需要多此访问数组长度时，可以先用变量保存起来，避免每次都去进行属性查找。
```

## 79.简单介绍一下V8引擎的垃圾回收机制

```
V8垃圾回收机制基于分代回收机制，这个机制又基于世代假说,这个假说有两个特点，一是新手的的对象容易早死，另一个是不死的对象会活得更久，基于这个假说，v8引擎将内存分为了新生代和老生代。
新创建得对象或者只经历一次的垃圾回收的对象被称为新手代。经历过多此垃圾回收机制的对象被称为老生代。
新生代被分为From和To两个空间，To一般是闲置的。当Form空间填满了的时候会执行Scavenge算法进行垃圾回收。当我们执行垃圾回收算法的时候应用逻辑将会停止，等垃圾回收接受后再继续执行。这个算法执行分为三步：
1.首先检查From空间的存活对象，如果对象存活则判断对象是否满足晋级到老生代的条件，如果满足条件则晋升到老生代。如果不满足条件则移动To空间。
2.如果对象不存活，则释放对象空间。
3.最后将Form空间和To空间角色进行交换。
新生代晋升老生代有两个条件：
1.第一个判断是对象是否已经经过一次Scavenge回收。若经历过，则将对象从From空间复制到老生代中，若没有经历过，则复制到To空间。
2.如果To空间的内存使用占比是否超过限制。当对象从From空间复制到To空间时，若To空间使用超过25%，则对象直接晋级到老生代中。设置25%的原因主要是因为算法结束后，两个空间结束后会交换位置，如果To空间的内存太小，会影响后续的内存分配。

老生代采用了标记清除法和标记压缩法。标记清除法首先会对内存中存在的对象进行标记，标记结束后清除那些没有标记的对象。由于标记清除后会造成很多的内存碎片，不便于后面的内存分配。所以为了解决这个问题引入了标记-整理法。
由于在进行垃圾回收机制的时候会暂停应用的逻辑，对于新生代方法由于内存小，每次停顿时间不会太长。但对于老生代来说每次垃圾回收的时候长，停顿会造成很大的影响。为了解决这个问题v8引入了增量标记的方法，将一次停顿进行的过程分为了多步，每次执行完一小步就让运行逻辑执行一会，就这样交替运行。
```

## 80.哪些操作会造成内存泄漏？

```
1.我们由于使用未声明的变量，而意外的创建了一个全局变量，而这个变量一直会留在内存中无法被回收。
2.我们设置setInterval定时器，而忘记取消它，如果循环函数有对外部变量的引用的话，那么这个变量就会一直留在内存中，而无法被返回。
3.我们获取一个DOM元素的引用，而后面这个元素被删除，由于我们一直保留了对这个元素的引用，所以它也无法被回收。
4.不合理的使用闭包，从而导致某些变量一直保存在闭包中。
```

## 81.需求：实现一个页面操作不会整页刷新的王者，并且能在浏览器前进，后退时正确响应。给出你的技术实现方案？

```
通过使用pushState+ajax实现浏览器无刷新前进后退，当一次ajax调用成功后我们将一条state记录加入history对象中。一条state记录包含了url，title和content属性，在onpopstate事件中可以获取到这个state对象，我们可以使用content来传递数据。最后我们通过对window.onpopstate事件来监听来响应浏览器的前进后退操作。
使用pushstate来实现有两个问题，一个是打开首页时没有记录，我们需要用replaceState来将首页的内容进行替换，另一个问题是当一个页面刷新的时候，仍然会向服务器发送请求数据，因此如果请求的url需要后端的配合将其重定向到一个页面。
```

## 82.如何判断当前脚本运行在浏览器还是node环境中？

```
this===window?'browser':'node';
通过判断Global对象是否为window，如果不为window，当前脚本就没有运行在浏览器中
```

## 83.把scirpt标签放在页面的最底部的body封闭之前和封闭之后有什么区别？浏览器会如何解析它们？

```
页面加载时自上向下当然时先加载样式。写在body标签后由于浏览器以逐步方式对html文档进行解析，当解析写在尾部的样式表，会导致浏览器停止之前的渲染，等待加载且解析样式表之后再重新渲染，在windows的IE下可能会出现FOUC现象(样式失效导致的页面闪烁问题)
```

## 84. 移动端的点击事件的有延迟，时间是多久，为什么会有？ 怎么解决这个延时？

```
300ms，是因为移动端会有双击缩放的这个操作，因此浏览器在click之后要等待300ms，看用户有没有下一次点击，来判断这次操作是不是双击。
解决方法
1.利用mate标签禁止页面缩放 user-scalable=no
2.利用mate标签将网页的viewport设置为ideal viewsport。
3.调用一些js库，Fastclick
click延迟问题还可能引起带引起点击穿透问题，就是如果我们在一个元素上注册了touchStart的监听事件，这个事件会被这个元素隐藏掉，我们发现当这个元素隐藏后，触发了这个元素下的一个元素的点击事件，这就是点击穿透。
```

## 85.什么是"前端路由"？什么时候适合使用"前端路由"？"前端路由"有哪些优点和缺点？

```
1.什么是前端路由？
	前端路由就是把不同路由对应的不同的内容或者页面任务交给前端来做，之前是通过服务端根据不同的url返回不同的内容
2.什么适合使用前端路由？
	在单页面应用，大部分页面结构不变，只改变部分内容的使用
3.前端路由有什么优点和缺点？
	优点
	用户体验好，不需要每次都从服务器获取，快速展现给用户
	缺点
	单页面无法记住之前的滚动的位置，无法在前进或者后退的时候记住滚动的位置
前端路由一共有两种实现方式，一种是通过hash的方法，一种是通过pushstate的方式。
```

## 86.检查浏览器版本的版本号有哪些方式

```
1.通过windows.navigator.userAgent的值，但这种方法很不可靠，因为userAgent可以被改写，并且早期的浏览器如ie，会通过伪装自己的userAgent的值为Mozilla来躲过服务器的检测
2.功能检测，根据每个浏览器独有的特征功能来进行判断。如ie下独有ActiveObject。
```

## 87.什么是Polyfill？

```
Polufill指的是用于实现浏览器并不支持的原生API的代码。
比如querySelectorALL是现代很多浏览器都支持web API,但是有些古老的浏览器并不支持，那么假设有人谢了一段代码来实现这个功能是这些浏览器也支持这个能够，那么这就可以被叫做polyfill。
一个shim是一个库，有自己的api，而不是单纯实现原生不支持的API。
```

## 88.使用JS实现获取文件的扩展名？

```js
function getFileExtension3(filename) {
    return filename.slice(filename.lastIndexOf('.')==0?'':filename.lastIndexOf('.'));
}
```

## 89.介绍一下js的节流和防抖

```js
// 节流：有个需要频繁触发的函数，在规定的时间内只触发一次。
// 防抖：有个需要频繁触发的函数，只让最后一次触发生效

//节流
function throttle(fn,delay){
	var time=0;
	return function(){
		var nowtime=Date.now();
        if(nowtime-time>delay)
        {
         	fn.call(this);
            time=nowtime;
        }
	}
}
document.onscroll=throttle(()=>console.log(Date.now()),200);
function debounce(fn,delay){
    var time=null;
    return function(){
        clearTimeout(time);
        time=setTimeout(()=>{
            fn.apply(this);
        },delay)
    }
}
/*
回答：
	函数防抖是指时间被触发的n秒后再执行，如果再这n秒内事件又被触发，则重新计时。这可以使用在一些点击请求事件上，避免因为用户多次点击向后端发送多此请求。
	函数节流是指规定的事件内，在这个单位事件内，只能由一次触发事件的回调函数执行，如果在同一个单位时间内某个事件被触发多次，只有一次能生效。节流可以使用在scroll函数监听上，通过事件节流来降低事件调用的频率。
*/
```

## 90.Object.is()与原来的比较运算符"==="，"=="的区别？

```
== 进行判断时 如果两边的类型不一致，则会强制进行转换成一致的再进行比较
=== 进行判断时 如果两边的类型不一致，不会进行强制类型转换，直接返回false。
使用Object.is来判断，一般情况下和===是相同的，它处理了一些特殊的情况，比如-0和+0不再相等，两个Nan认定为相等
```

## 91.excape,encodeURI,encodeURIComponent有什么区别？

```
encodeURI是对整个URI进行转义，将URI中的非法字符转化成合法字符，所以对于一些再URI中有特殊意义的字符不会进行转义。
encodeURIComponent是对URI组成部分进行转义，所以一些特殊字符也会被转义
excape和encodeURI的作用相同，不过它们对于unicode编码在0xff(255)之外字符的时候会有区别，escape是直接在字符的unicode编码前加上%u，而encodeURI首先会将字符转换成UTF-8的格式，再在每个字符前加上%
```

## 92.Unicode和UTF-8的关系？

```
unicode是一种字符集合，现在可容纳100多万个字符。每个字符对应不同的unicode编码。它只规定了符号的二进制编码，却没有规定这个二进制编码在计算机中如何编码传输
UTF-8是一种对unicode的编码方式，它是一种变长的编码方式，可以用1~4个字节来表示一个字符。
```

## 93.js的事件循环是什么？

```
事件队列是一个存放着执行任务的队列，其中的任务严格按照事件先后顺序执行，排在对头的任务将会率先执行，而排在队尾的任务会最后执行。事件队列每次仅执行一次任务，在任务执行完毕之后，再执行下一个任务。执行栈则是一个类似于函数调用栈的运行容器，当栈为空时，JS引擎便检查事件队列，如果不为空，事件队列便将第一个任务压入执行栈中运行。

因为js是单线程运行的，在代码执行的时候，通过将不同函数的执行上下文引入栈中来保存代码的有序执行。在执行同步代码的时候，如果遇到了异步事件，JS引擎并不会一直等待其返回结果，而是将这个事件挂起，继续执行执行栈中的其他任务。当异步事件执行完成之后，再将对应的回调加入到当前执行栈中不同的另一个任务队列中等待执行。任务队列可以分为宏任务队列和微任务队列，当当前执行栈中的事件执行完毕后，js引擎会判断微任务队列中是否有任务可以执行，如果有就将微任务队首的任务压入栈中执行。当微任务所有的任务都执行完成后再去判断宏任务队列中的任务。
微任务包括了promise的回调，node中的process.nextTick,对DOM的变量监听。
宏任务包括script脚本的执行，setTimeout,setInterval,setImmediate一类的定时函数，还有如I/O操作，UI渲染等。

js是单线程运行的，在代码执行前，我们将不同函数的执行上下文引入主线程栈中，当遇到一个异步函数我们不是等待其执行完成而是将其挂起，等到异步函数执行完之后放入任务队列中，当主线程执行栈中任务执行完成之后，在去处理任务队列里面的异步函数,任务队列分为宏任务和微任务，先执行微任务(promise DOM的监听)，将微任务取出压到主线程栈中进行执行，当微任务都执行完之后再执行宏任务(定时器函数)
```

## 94.JS中的深浅拷贝的实现？

```js
浅拷贝指的是将一个对象的属性值复制到另一个对象，如果有的属性的值为引用类型的话，那么会将这个引用的地址复制给对象，因此两个对象会有同一个对象的引用。浅拷贝可以通过Object.assgin和扩展运算符来实现
深拷贝相对于浅拷贝而言，如果遇到的属性值是引用类型的时候，它创建了一个引用类型并将对应的值复制给它，因此对象获得的一个新的引用类型而不是一个原有类型的引用。深拷贝对于一些对象可以使用JSON的两个函数来实习，但是由于JSON的对象格式比js的对象格式更加严格，所有如果属性值里面出现函数或者Symbol类型的值时，会转换失败。

/*
    typeof对于基本数据类型判断是没有问题的，但是遇到引用数据类型（如：Array）是不起作用的。
*/
//浅拷贝
function shallowCopy(object) {
    if (!object || typeof object !== 'object')
        return;
    var newObject = Array.isArray(object) ? [] : {};
    for (let i in object) {
        if (object.hasOwnProperty(i)) {
            newObject[i] = object[i];
        }
    }
    return newObject;
}
var a = {
    id: 1,
    msg: {
        age: 18
    }
}
var b = {};
Object.assign(b, a);
// var b = shallowCopy(a);
b.msg.age = 123;
console.log(a);
//深拷贝
function deepCopy(object) {
    if (!object || typeof object !== 'object')
        return;
    var newObject = Array.isArray(object) ? [] : {};
    for (let i in object) {
        if (object.hasOwnProperty(i)) {
            if (typeof object[i] == 'object') {
                newObject[i] = deepCopy(object[i]);
            } else {
                newObject[i] = object[i];
            }
        }
    }
    return newObject;
}
var c = deepCopy(a);
c.msg.age = 43;
console.log(a);
```

## 95.手写call,apply及bind函数

```js
Function.prototype.Mycall = function (context, ...args) {
    // 判断context是否传入，如果未传入则设置window
    context = context || window;
    // 将调用函数设为对象的方法
    context.fn = this;
    // 获取参数
    var args = [...arguments].slice(1);
    // 调用函数
    var result = context.fn(...args);
    // 将属性删除
    delete context.fn;
    return result;
}

Function.prototype.Myapply = function (context, ...args) {
    context = context || window;
    context.fn = this;
    var result = null;
    if (args.length) {
        result = context.fn(args);
    } else {
        result = context.fn();
    }
    delete context.fn;
    return result;
}

Function.prototype.myBind2 = function (context, ...args1) {
    var self = this;
    return function F(...args2) {
        if (this instanceof F) {
            return new self(...args1, ...args2);
        } else {
            return self.apply(context, args1.concat(...args2));
        }
    }
}
```

## 96.函数柯里化的实现

```js
//柯里化是指把结束多个参数的一个函数转换成接受一个参数的函数
function currying(fn, length) {
    length = length || fn.length;
    return function (...args) {
        if (args.length >= length) {
            return fn(...args);
        } else {
            return currying(fn.bind(null, ...args), length - args.length);
        }
    }
}
var add = currying((...args) => eval(args.join('+')), 3);
console.log(add(1, 2)(3));
```

## 97.为什么0.1+0.2!=0.3?如何解决这个问题?

```
当计算器计算0.1+0.2的时候，实际上计算的是这两个数在计算机里所存储的二进制，0.1和0.2在转化成二进制的时候会出现位数无限循环的清空。js中以64位双精度格式来存储的(在计算机中存储为64位
1 11 52
1: 符号位 0正数 1负数
11: 指数位 用来确定范围
52: 尾数位 用来确定精度)，只有53位的有效数字，超过这个长度的位数将被截取掉，这样 也就造成了精度损失。这是第一个会造成精度损失的地方。在对两个以64位双精度的数据进行计算的时候，首先会进行对阶处理，对阶指的是阶码对齐，也就是小数点的位置对齐，再进行计算，一般是小阶向大阶对齐，因此小阶的数在对齐的过程中，有效数字会向右移动，移动后超过的有效位数将被截取掉。这是第二个可能会出现的精度丢失的地方。当两个数据阶码对齐后，进行相加运算后，得到的结果可能会超过53位有效数字，因此超过的位数也会被截取掉，这是可能发生精度丢失的第三个地方。
对于这样的清空，我们可以将其转化位整数后再进行运算，运算后再将其转换位小数，以这种方式来解决这个问题。
我们还可以将这两个数相加的结果减去右边的结果，如果相减的结果是小于一个极小的数，那么我们就可以认定这个结果是相等的。
```

## 98.原码，反码，补码的介绍

```
原码是计算机对数字的二进制的定点表示方法，最高位表示符号位，其余数字表示数值位，优点是易于分辨，缺点是不能直接参与运算。
正数的反码和其原码一样；负数的反码，符号位为1，数值部分按原码取反。
例如	如 [+7]原 = 00000111，[+7]反 = 00000111；
		[-7]原 = 10000111，[-7]反 = 11111000。
正数的补码和其原码一样；负数的补码为其反码加1
例如 [+7]原 = 00000111，[+7]反 = 00000111，[+7]补 = 00000111； 
	 [-7]原 = 10000111，[-7]反 = 11111000，[-7]补 = 11111001
之所以在计算机中使用补码来表示负数的原因是，这样可以将加法运算扩展到所有数值上，因此在数学电路中我们只需要考虑加法器的设计就行了，而不用再为减法设置新的电路。
```

## 99.toPrecision和toFixed和Math.round的区别

```
toPercision用于处理精度，精度是从左至右第一个不为0的数开始数起。
toFixed是对小数点后指定位数取整，从小数点开始数起。
Math.round是将一个数进行四舍五入。
```

## 100.什么是xss攻击？如何防范xss攻击？

```
xss指的是跨站脚本攻击，是一种代码注入攻击。攻击者通过在网站中注入恶意脚本，使之在浏览器上运行，从而盗取用户的信息如cookie等。
xss的本质是因为网站对恶意代码没有进行过滤，与正常代码混合在一起了，浏览器没办法分辨哪些脚本是可信的，从而导致恶意代码的执行。
xss一般分为存储型，反射型和DOM型。
存储型指的是恶意代码提交到网站的数据库中，当用户请求数据时，服务器将其拼接为HTML后返回给了用户，从而导致恶意代码的执行。
反射型指的是攻击者构建了特殊的URL，当服务器接受到请求后，从URL中获取数据，拼接到HTML后返回，从而导致了恶意代码的执行。
DOM型指的是xss代码并不需要服务器的参与，触发xss靠的是浏览器的DOM解析，完全是客户端的事情
防范xss的总体思路：对输入进行过滤，对输出进行编码，通过设置 set-cookie httpOnly禁止脚本执行cookie。也可以设置只有在https协议下才可以发送cookie。
还有一些方式，比如使用CSP，CSP的本质是建立一个白名单，告诉哪些浏览器外部资源可以加载和执行，从而防止恶意代码的注入攻击。
还可以对一些敏感信息进行保护，比如cookie使用http-only，使得脚本无法获取。也可以使用验证码，避免脚本伪装成用户执行一些操作。
```

## 101.什么是CSP？

```
CSP指的是内容安全策略，它的本质是创建一个白名单，告诉浏览器哪些外部资源可以加载和执行。我们只需要配置规则，如何拦截由浏览器自己来实现。

通常由两种方法来开启CSP,一种设置HTTP首部Context-Security-Policy，一种是设置meta标签的方法<meta http-equiv="content-Security-Policy">
```

## 102.什么是CSRF攻击？如何防范CSRF攻击？

```
CSRF攻击指的跨站请求伪造攻击，攻击者诱惑用户进入一个第三方网站，然后该网站向被攻击网站发送跨站请求。如果用户在被攻击网站的保存了登录状态，那么攻击者就可以利用这个登录状态，绕过后台的用户验证，冒充用户向服务器执行一些操作。
CSRF攻击的本质是利用了cookie会在同源请求中携带发送给服务器的特点，以此来实现用户的冒充。
一般的CSRF攻击类型由三种：
1.GET类型的CRSF攻击，比如一个网站中的一个img标签里面构建一个请求，当用户打开这个页面时就会自动发送提交。
2.POST类型的CRSF攻击，比如说创建一个表单，然后隐藏它，自动提交这个表单。
3.链接类型的CSRF攻击，比如说在a标签的href属性里构建一个请求，然后诱导用户去点击。
CSRF可以用以下几种方法来防护：
1.同源检测的方法，服务器根据http请求头中的origin或者referer信息来判断请求是否为允许访问的站点。
2.使用CSRF Token来进行验证，服务器向用户返回一个随机数Token，当网站再次发送请求的时候，在请求参数中加入服务器端返回的token，然后服务器对这个token进行验证。这种方法解决了使用cookie单一验证的方法，可能会被冒用的问题，但是这种方法存在一个缺点就是，我们需要给网站中所有的请求都添加上这个token，操作比较繁琐。还有一个问题是一般不会只有一台网站服务器，如果我们的请求经过负载平衡转移到其他的服务器，但是这个服务器的session中没有保存这个token的话，就没有办法验证了。这种情况我们可以通过token的构建方式来解决。
3.使用双重Cookie验证的办法，服务器在用户访问页面时，向请求域名注入一个Cookie，内容为随机字符串，然后当用户向服务器发送请求的时候，cookie取出这个字符串，添加到URL参数中，然后服务器通过对cookie中的数据进行比较，来继续验证
4.使用在设置cookie的时候设置Samesite，限制cookie不能作为第三方使用，从而避免被攻击者利用。Samesite一共有两种模式,一种是严格模式，在严格模式下cookie在任何情况下都不能作为第三方Cookie使用，在宽松模式下，cookie可以被请求是GET请求，且会发送页面跳转的请求所使用。
```

## 103.什么是Samesite Cookie属性

```
sameSite代表同站Cookie，避免Cookie被第三方所利用，将sameSite设置为严格模式，表示这个Cookie在任何情况下都不可能作为第三方Cookie。
宽松模式，如果这个请求是GET请求，并且这个请求改变了当前页面或者打开了新的页面，那么可以作为第三方Cookie，其余情况下都不能作为第三方Cookie。
```

## 104.什么是点击挟持？如何防范点击挟持？

```
点击挟持是一种视觉欺骗的手段，攻击者将需要攻击的网站通过iframe嵌套的方式嵌入自己的网页中，并将iframe设置为透明，在页面中诱导用户点击。
我们可以在http相应的头中设置x-frame-options来防止iframe嵌套的点击挟持。通过不同的值，可以规定页面在特定的一些情况下才能作为iframe来使用
```

## 105.SQL注入攻击？

```
SQL注入攻击指的是攻击者在HTTP请求中注入恶意的SQL代码，服务器使用参数构建数据库SQL命令时，恶意的SQL被一起构造，破坏原有的SQL结构，并在数据库中执行，达到编写程序预料之外结果
```

## 106.什么是MVVM？与之MVC有什么区别？什么又是MVP？

```
mvc,mvvm,mvp是常见的三种软件架构设计模式，只要通过分离关注点的方式来组织架构，优化我们的开发效率。
传统的MVC指的是，用户操作会请求服务器端的路由，路由会调用相应的控制器来处理。控制器会获取结果，将结果返回给前端，进行页面重新渲染。
MVVM，传统的前端会将数据手动渲染到页面上。MVVM模式不需要用户收集操作Dom元素。将数据绑定在DOM元素，将数据绑定到ViewMoel层上，会自动将数据渲染到页面中，视图变化了也会通知ViewModel层更新数据。ViewModel就是我们MVVM模式中的桥梁
```

## 107.响应式数据的原理？

```
1.核心：Obeject.defineProperty
1.默认Vue在初始化时，会给data中的属性使用Object.defineProperty重新定义所有属性，当页面取到对应属性时。会进行依赖收集，如果属性发生变化会通知相关依赖进行更新操作
```

## 108.vue双向数据绑定原理

```
	VUE通过双向绑定来实现model层和view层的同步更新，vue的双向绑定主要是通过使用数据劫持和发布订阅者模式来实现。
首先我们通过Object.defineProperty()方法对Model数据的各属性值进行重新定义。因此当Model数据发现改变的时候我们可以通过配置set和get方法来实现来view层数据更新的通知。
	数据在html模板中的绑定有两种情况一种是v-model来对value值进行绑定，一种是文本绑定，在对模板引擎进行解析的过程中。
	如果遇到元素节点并且绑定了v-model的话，我们就从Model中去获取v-model所对应的属性的值，并赋值给元素的value。然后给这个元素设置一个监听事件，当view元素中的数据发送改变的时候触发该事件，通知Model中对应的属性值进行更新。
	如果遇到了绑定的文本节点，我们使用Model中对应的属性值来替换文本。对于文本节点更新我们使用发布订阅者模式，属性作为一个主题，我们为每个节点设置一个订阅者对象，将这个订阅者对象加入这个属性主题的订阅者列表中。当Model层数据发送改变时，Model作为发布者向主题发送通知，主题收到通知后再向它的所有订阅者推送，订阅者收到通知后更改自己的数据。
```

## 109.Object.defineProperty介绍

```
	Object.defineProperty函数一共有三个参数，第一个参数是需要定义属性的对象，第二个参数是需要定义的属性，第三个是被操作属性的特性，常用的有set，写入时触发和get读入时触发
```

## 110.Objecet.defineProperty()来进行数据劫持有什么缺点？

```
	有一些对属性的操作，使用这种方法无法拦截。比如说通过下标修改数组的值或者给对象新添加属性，VUE通过内部重写函数解决这个问题。在vue3.0中已经不使用这种方法了，而是通过使用proxy对对象进行代理，从而实现数据劫持。使用proxy的好处时它可以完美的监听到任何方式的数据改变。唯一缺点时兼容性问题，因为这是ES6的语法。
```

## 111.什么时Virtual DOM？为什么Virtual DOM比原生DOM快？

```
	也就是虚拟节点。它通过js中Object对象模拟DOM中的节点（元素类型，元素属性，子节点）。然后再通过特定的方法渲染成真实DOM节点。

	首先我们将要插入文档中的DOM树结构进行分析，通过JS对象将其表示，比如一个元素对象，包含type，props，children这些属性。然后我们将这个js对象树保存下来，最后再将DOM片段插入文档中。
	当页面的状态发生改变，我们需要对页面的DOM的结构进行调整的时候，我们首先根据变更的状态创建新的对象树，然后把这个对象树和旧的对象树进行比较，记录一下两个树的差异。
	最后将记录的有差异的地方运用到真的DOM树中去，这样视图就更新了。
	我认为虚拟DOM这种方法对于我们大量的操作DOM，能够很好的提高我们的操作效率，通过在操作前确定需要做的最小修改，尽可能的减少DOM操作带来的重流和重绘的影响。
```

## 112.如何比较两个DOM树的差异？

```
首先会对新旧两棵树进行一个深度优先的遍历，这样每个节点都会有一个序号。在深度遍历的时候，每遍历到一个节点，我们就将这个节点和新的节点进行比较，如果有差异，则将这个差异记录到一个对象中。
在对列表元素进行对比的时候，由于标签类型是重复的，我们不能使用这个来对比。我们需要给每一个子节点添加一个key作为唯一标识，列表对比的时候使用key来进行比较，这样我们才能够运用到老的DOM树上的节点。

diff算法
如果老的里面有 新的里面没有 这个属性就移除了
如果老的里面没有 新的里面有 覆盖
如果新的里面有style 老的里面也有style 但是可能不一样 老属性 心属性没有 就清空
如果老的里面没有 新的里面有就遍历赋值
```

## 113.Vue生命周期



## 114.offsetWidth/offsetHeight,clientWidth/clientHeight与scrollWidth/scorllHeight区别

```
clientWidth/clientHeight返回的是元素内部的高度和宽度。它的值包括content+padding，如果有滚动条，不包含滚动条。
clientTop返回的是上边框的宽度。
clientleft返回的左边框的宽度。

offsetWidth/offsetHeight返回的元素content+padding+border包含滚动条。
offsetTop返回当前元素相对于其offsetParent元素的顶部距离。
offsetLeft返回的是当前元素相对于offsetParent元素的左部元素。
offsetParent() 方法返回最近的祖先定位元素。

scrollWidth/scrollHeight 返回值包括content+padding+溢出内容的尺寸。
scrollTop属性返回的是一个元素的内容垂直滚动的像素数。
scrollleft属性返回的是元素滚动条到元素左边的距离。
```

## 115.异步编程的实现方式？

```
1.回调函数
多个回调函数嵌套会形成回调地狱，上下层的回调函数间的代码耦合度太高，不利于代码的维护
2.promise的方式，使用Promise的方式可以将嵌套的回调函数进行链式调用。但是这种方法会造成多个then的链式调用，可能会造成代码语义不够明确。
3.async函数的形式，它内部自带执行器，当函数内部执行到一个await语句时候，如果语句返回一个promise对象，那么函数将会等待promise对象变为resolve后继续向下执行。因此我们可以将异步逻辑，转化为同步的顺序来书写，并且这个函数可以自动执行。
```

## 116.js动画与css动画的区别及相关实习

```
css3动画的优点
在性能上会稍微好一些，浏览器回对css3的动画做一些优化。代码相对简单
缺点
在动画控制上不够灵活 兼容性不好。

js动画正好弥补了这两个缺点，控制能力强，可以单帧操作，变换，同时写得好可以兼容
```

## 117.get请求传参长度的误区

```
我们经常说get请求参数的大小存在限制，而post请求的参数大小是无限制的。
实际上http协议从未规定GET/POST请求的长度限制是多少。对get请求参数的限制是来源于浏览器或web服务器，浏览器或者web服务器限制了url的长度。为了明确这个概念，我们必须再次强调以下几点：
1.http协议中为规定GET和POST的长度限制。
2.GET的最长长度显示是因为web服务器或者浏览器限制了URL的长度。
3.不同的浏览器和web服务器，限制的最大长度不一样。
```

## 118.URL和URI的区别？

```
URI：指的是统一资源识别符。
URL：指的是统一资源定位符。
URN：指的是统一资源名称
URI指的是统一资源识别符，用唯一的标识来确定一个资源，它是一个抽象的定义，也就是说，不管使用什么办法来定义，只要能唯一的标识一个资源，就可以称为URI。
URL指的是统一资源定位符，URL和URN是URI的资源，URL可以理解为使用地址来标识资源，URN可以理解为使用名称来标识资源。
```

## 119.get和post请求在缓存方法的区别

```
缓存一般只适合那些不更新服务器数据的请求，一般get请求都是查找请求，不会对服务器资源造成修改，而post请求一般都会对服务器造成修改，所以一般只会get请求进行缓存，很少会对post请求进行缓存。
```

## 120.mouseover和mouseenter的区别？

```
当鼠标移动到元素上时就会触发moiseenter事件，类似mouseover，它们两者区别时mouseenter不会冒泡。
由于mouseenter不支持事件冒泡，导致在一个元素的子元素上进入或者离开的时候会触发其mouseover和mouseout事件，但是却不会触发mouseenter和mouseleave事件
```

## 121.JS拖拽功能的实现

```
一个元素的拖拽过程，我们可以分为三个步骤，第一步鼠标按下元素，第二步是鼠标保持按下的状态移动鼠标，第三步是鼠标抬起，拖拽过程结束。
	这三步分别对应三个事件，mousedown事件，mousemove事件，mouseup事件。只有在鼠标按下的状态移动鼠标我们才会执行拖拽事件，因为我们需要在mousedown事情中设置一个状态来标识鼠标是否已经按下，然后在mouseup事件中取消这个状态。在mousedown事件中我们首先应该判断，目标元素是否为拖拽元素，如果是拖拽元素，我们就设置状态并保持这个时候的鼠标的位置。然后再mousemove事件中，我们通过判断鼠标现在的位置和之前的位置的相对移动来确定拖拽元素再移动中的位置。最后mouseup事件触发，清除状态，结束拖拽事件。
```

## 122.使用setTimeout实现setInterval？怎么模拟？

```js
使用递归的思想
timerFun();

function timerFun(){
  console.log('要执行的操作');
  let timer=setTimeout(function(){
  timerFun();
  clearTimeout(timer)
  },1000);
}
```

## 123.let和const的注意点？

```
1.声称的变量只有在代码块内有效。
2.不存在变量提升。
3.存在暂时性死区，如果在变量声明前使用会出错。
4.不允许重复声明，重复声明会报错。
```

## 124.什么是rest参数？

```
rest参数(形式为...变量),获取多余变量
```

## 125.什么是尾调用，使用尾调用有什么好处？

```
尾调用指的是函数的最后一步调用函数。我们代码执行时基于执行栈的，所以当我们在一个函数中调用另一个函数时，我们会保留当前的执行上下文，然后再新建另外一个执行上下文放入执行栈中。使用尾调用的话，因为已经是最后一步，所以这个时候我们不必再保留当前的执行上下文，从而节约了内存，这就是尾调用优化。但是es6的尾调用优化只在严格模式下开启，正常模式是无效的。
```

## 126.Symbol类型的注意点？

```
1.symbol函数前不能使用new命令，否则会报错。
2.symbol函数可以结束一个字符串作为参数，表示对symbol实例的描述，主要是为了在控制台显示，或者转为字符串时，比较容易区分。
3.symbol作为属性名，该属性不会出现在for...in,for..of循环中，也不会被Object.keys(),Object.getOwnPropertyNames(),JSON.stringify()返回。
4.Object.getOwnPropertySymbos方法返回一个数组，成员是当前对象的所有用作属性名的Symbol值。
5.symbol.for接受一个字符串作为参数，然后搜索有没有以该参数作为名称的symbol值。如果有，就返回这个symbol值，否则就新建并返回一个以该字符串为名称的symbol值。
6.symbol.keyFor方法返回一个已登记的Symbol类型值的key。
```

## 127.Set和WeakSet结构？

```
1.es6提供了新的数据结构set。它类似于数组，但是成员的值都是唯一的，并没有重复的值。
2.WeakSet结构于Set结构类似，也是不重复值的集合。但实际WeakSet的成员只是对象，而不能是其他类型的值。WeakSet中的对象都是弱引用，即垃圾回收机制不考虑weakSet对该对象的引用。
```

## 128.Map和WeakMap结构？

```
1.Map数据结构，它类似于对象，也就是键值对的集合，但是"键"的范围不限于字符串，各种类型(包括对象)都可以当作健。
2.WeakMap结构与Map结构类型，也是用于生成键值对的集合。但是weakMap只接受对象作为键名(null除外)，不接受其他类型的值作为键名。而且weakMap的键名所指向的对象，不计入垃圾回收机制。
```

## 129.什么是proxy？

```
Proxy用于修改某些操作的默认行为，等同于在语言层面做出修改，所以属于一种"元编程"，即对编程语言进行编程。
proxy可以理解成，在目标对象之前假设了一层“拦截”，外界对该对象的访问，都必须通过通过这层拦截，因此提供了一种机制，可以对外界的访问进行过滤和改写。proxy这个词的意思就是代理，用在这里表示有它来“代理”某些操作，可以译为"代理器"。
```

## 130.require模块引入的查找方式?

```
当Node遇到require(x)时，按下面的顺序处理。
	1.如果x是内置模块(require('http'))
		a.返回该模块
		b.不再继续执行
	2.如果x以'./'或者'/'或者'../'开头
		a.根据x所在的父模块，确定x的绝对路径
		b.将x当成文件,依次查找下面文件，只要有其中一个存在，就返回该文件，不再继续执行。 x x.js x.json x.node
		c.将x当成目录，依次查找下面的文件，只要其中有一个存在，就返回该文件，不再执行 x/package.json x/index.js x/index.json x/index.node
	3.如果X不带路径
		a.根据x所在的父模块，确定x的安装目录。
		b.根据每个目录中，将x当成文件名或者目录名加载。
	4.抛出"not found"
```

## 131.什么是Promise对象，什么是Promises/A+规范？

```
Promise对象是异步编程的一种解决方法。
Promise是一个构造函数，接受一个函数作为参数，返回一个Promise实例。一个Promise实例有三种状态，分别是pending，resolved或者reject状态，分别代表进行中，已成功，已失败。实例的状态只能由padding变成reject或者resolve，并且状态一经改变，无法再被改变。状态的改变是通过resolve()和reject()函数来实现的，我们可以通过异步操作结束后调用这两个函数改变Promise实例的状态，它的原型上定义了一个then方法，使用这个then方法可以为两个状态的改变注册回调函数。这个回调函数属于微任务，会在本轮事件循环的末尾执行。
```

## 132.手写Promise

```js
const PENDING = "pending";
const REJECT = "reject";
const RESOLVE = "resolve";
class myPromise {
    constructor(fn) {
        this.status = PENDING;
        this.value = undefined;
        this.reason = undefined;
        // 用于保存resolve的回调函数
        this.resolveCallback = [];
        // 用于保存reject的回调函数
        this.rejectCallback = [];
        let resolve = (value) => {
            if (this.status == PENDING) {
                this.status = RESOLVE;
                this.value = value;
                this.resolveCallback.forEach((f) => f());
            }
        };
        let reject = (reason) => {
            if (this.status == PENDING) {
                this.status = REJECT;
                this.reason = reason;
                this.rejectCallback.forEach((f) => f());
            }
        };
        try {
            fn(resolve, reject);
        } catch (e) {
            reject(e);
        }
    }
    then(onResolved, onRejected) {
        if (this.status == RESOLVE) {
            onResolved(this.value);
        } else if (this.status == REJECT) {
            onRejected(this.reason);
        } else {
            this.resolveCallback.push(() => {
                onResolved(this.value);
            });
            this.rejectCallback.push(() => {
                onRejected(this.reason);
            });
        }
    }
}
let promise = new myPromise((resolve, reject) => {
    setInterval(() => {
        reject(45);
    }, 1000);
});
promise.then(
    (success) => {
        console.log(success);
    },
    (err) => {
        console.log(err);
    }
);
```

## 133.如何检测浏览器所支持的最小字体大小？

```
用JS设置DOM字体为一个值，然后再取出来，如果能够取出来则说明设置成功，就说明支持。
```

## 134.怎么做JS代码Error统计？

```
error统计使用浏览器的window.error事件。
```

## 135.单列模式模式是什么？

```
单模式保证全局只有一个实例被访问。比如说常用的如弹框组件的实现和全局状态的实现。
```

## 136.策略模式什么？

```
策略模式主要是用来将方法的实现和方法的调用分离开，外部通过不同的参数可以调用不同的策略。
```

## 137.代理模式是什么？

```
代理模式是为一个对象提供一个代用品或占位符，以便控制对它的访问。比如说常见的事件代理。
```

## 138.中介者模式是什么？

```
中介者模式指的是，多个对象通过一个中介者进行交流，而不是直接进行交流，这样能够将通信的各个对象解耦。
```

## 139.适配器模式是什么？

```
适配器是用来解决两个接口不兼容的情况，不需要改变已有的接口，通过包装一层的方法实现两个接口的正常协作。假如我们需要一种新的接口返回方法，但是老的接口由于在太多地方已经使用了，不能随意更改，这个时候就可以使用适配器模式。比如我们需要一种自定义事件返回格式，但是我们又不能对js时间格式化的接口进行修改，这个时候就可以使用适配器模式。
```

## 140.观察者模式和发布订阅者模式有什么不同？ 

```
发布订阅模式是广义上的观察者模式。
在观察者模式中，观察者直接订阅目标，当目标发出内容改变事件后，直接接收事件并做出响应。
而在发布订阅模式中，发布者和订阅者之间多了一个调度中心。调度中心一方面从发布者接收事件，另一方面向订阅者发布事件，订阅者需要在订阅中心订阅事件。通过调度中心实现了发布者和订阅者我关系的解耦。使用发布订阅模式更利于我们代码的可维护性。
```

## 141.Vue的生命周期是什么？

```
Vue的生命周期是指组件从创建到销毁的一系列的过程，被称为Vue的生命周期。通过提供Vue在生命周期各个阶段的钩子函数，我们可以很好的
```

## 142.Vue的各个生命阶段是什么？

```
Vue 一共有8个生命阶段，分别是创建前、创建后、加载前、加载后、更新前、更新后、销毁前和销毁 后，每个阶段对应了一个生命 周期的钩子函数。
1.beforeCreate钩子函数，在实例初始化之前，在数据监听和事件配置之前触发。因此在这个事件我们是不能获取到data数据的。
2.Created钩子函数，在实例创建完成后触发，此时可以访问data、method等属性。但这个时候组件还没挂载到页面中去，所以这个时候访问不到$el属性。一般我们在这个函数中进行一些页面初始化的工作，比如通过ajax请求属性来对页面进行初始化。
3.beforeMount钩子函数，在组件被挂载到页面之前触发，在beforeMount之前，会找到对应的template，并编译成render函数。
4.mounted钩子函数，在组件挂载在页面之后触发。此时可以通过DOM API获取页面中的DOM元素。
5.beforeUpdata钩子函数，在响应式数据更新时触发，发在虚拟DOM和打补丁之前，这个我们可以对可能会被移除的元素做一些操作，比如移除事件监听器。
6.updata钩子函数，虚拟DOM重新渲染和打补丁之后调用。
7.beforeDestroy钩子函数，在实例销毁之前调用。一般在这一步我们可以销毁定时器，解绑全局事件等。数据，方法，过滤器，指令都可以使用
8.destoryed钩子函数，在实例销毁之后调用，调用后，VUe实例中的所有方法都会解除绑定，所有的事件监听器都会被移除，所有的子实例也会被销毁。

当我们使用keep-alive的时候，还有两个钩子函数，分别是activated和deactivated。用keep-alive包裹的组件在切换时不会进行销毁，而是缓存在内存中执行deactivated钩子函数，命中缓存渲染后会执行activated钩子函数
```

## 143.Vue组件间的参数传递方式？

```
1.父子组件间通信
第一种方式是子组件通过props属性来接收父组件的数据，然后父组件在子组件上注册监听事件，子组件通过emit触发事件来向父组件发送数据
第二种是通过设置ref属性给子组件设置一个名字。父组件通过$refs组件名来获取子组件，子组件通过$parent获得父组件，这样就可以实现通信。
第三种是使用provide/inject,在父组件中通过provide提供变量，子组件中使用inject来将变量注入组件中。不论子组件有多深，只要通过inject那么就可以注入provide中的数据
2.兄弟组件间的通信
第一种是使用eventBus的方法，它的本质就是通过创建一个空的vue实例作为数据传递的对象，通信的组件引入这个实例，通信的组件通过这个实例上的监听和触发事件，来进行信息的传递。
第二种是使用this.$parent.$refs来获取兄弟组件，也可以进行通信。
```

## 144.computed和watch的差异？

```
1.computed是计算一个新的属性(如果属性名字和methods的属性名一样，只会调用methods的方法),并讲这个属性挂载到这个vue实例上，而watch是监听已经挂载vue实例上的数据，所以用watch同时也可以监听computed计算属性的变化。
2.computed具有缓存性，只有当依赖变化后，第一次访问computed属性，才会计算新的值，而watch则是当数据发生变化后便会调用执行函数。
3.从使用场景上说，computed适用一个数据数据被多个数据影响，而watch适用一个数据影响多个数据。
```

## 145.vue-router中的导航钩子函数?

```
1.全局钩子函数beforeEach和afterEach
	beforeEach有三个参数，to代表要进入的路由对象，from代表离开的路由对象。next是一个必须要执行的函数,如不传参数，那就执行执行下一个钩子函数，如果传入false，则终止跳转，如果传入一个路径，则导航到对应的路由，如果传入error，则导航终止，error传入错误的监听函数。
2.单个路由独享的钩子函数beforeEnter,它是在路由配置上直接进行定义的。
3.组件内的导航钩子主要有三种:beforeRounteEnter,beforeRouteUpdate,beforeRouteLeave。它们是直接在路由组件内部直接进行定义的。
```

## 146.$route和$router的区别？

```
$route是"路由信息对象",包括path，params，hash，query，fullPath，match，name等路由信息参数。而$router是"路由实例"对象包括了路由的跳转方法，钩子函数等。
```

## 147.vue常见的修饰符？

```
.prevent:提交事件不再重载页面，.stop阻止单机事件冒泡，。self：当事件发生在该元素本身而不是子元素的时候会触发
```

## 148.vue中key值得作用？

```
vue中key值得作用可以分为两种情况来考虑。
1.v-if使用key。由于vue会尽可能高效地渲染元素，通常会复用已有元素而不是从新开始渲染。因此当我们使用v-if来实现元素切换得时候，如果切换前后含有相同类型的元素，那么这个元素会被复用。如果是相同的input元素，那么切换前后用户输入不会被清除掉，这样是不符合需求的。因此我们可以通过key来唯一的标识一个元素，这个情况下，使用key元素不会被复用。这个时候key的作用是来标识一个独立的元素。
2.v-for中使用key。用v-for更新已渲染过的元素列表时，它默认使用"就地复用"的策略，如果数据项的顺序发送了改变，Vue不会移动Dom元素来匹配数据项的顺序，而是简单的复用此处的每个元素。因此通过为每个列表提供一个key值，来以便Vue跟踪元素的身份，从而高效的时候实现复用。这个时候key的作用就是为了搞笑的更新渲染虚拟DOM。
```

## 149.computed和watch区别？

```
computed是计算属性，依赖其他属性计算值，并且computed的值有缓存，只有当计算值变化才会返回内容。
watch监听到值的变化就执行执行回调，在回调中可以进行一些逻辑操作。
```

## 150.keep-alive组件有什么作用？

```
如果你需要在组件切换的时候，保存一些组件的状态防止多此渲染，就可以使用keep-alive组件包裹需要保存的组件。
```

## 151.vue中mixin和mixins区别？

```
mixin用于全局混入，会影响每个组件实现。
mixins应该是我们最常使用的扩展组件的方式了。如果多个组件中有相同的业务逻辑，就可以讲这些逻辑剥离处理，通过mixins混入代码，比如上拉下拉加载数据这种逻辑等等。另外需要注意的是mixins混入的钩子函数会先于组件内的钩子函数执行，并且在遇到同名选项的时候也会有选择性的进行合并。
```

## 152.开发中常见的几种Content-Type？

```
1.application/x-www-form-urlencoded
	浏览器的元素form表单，如果不设置enctype属性，那么最终就会以application/x-www-form-urlencoded方式提交。该方式提交的数据放在body里面，数据按照key1=val1&key2=val2的方式进行编码，key和val都进行了url转码。
2.application/json
	告诉浏览器信息主体是序列化的JSON字符串。
3.text/xml
	该种方式主要用来提交xml格式的数据。
```

## 153.如何判断一个对象是否为空对象？

```js
1. for(var i in obj){
	return true
}
return false、

2. if(JSON.stringify(data)==='{}'){
	return false;
}
return true;

注意：为什么不使用toString(),因为它返回的不是我们需要的
var a={}
a.toString() //"[object Object]"

3.ES6新增的方法Object.keys();
Object.keys()方法会返回一个由一个对象自身可枚举的属性组成的数组。 
if(Object.keys(object).length===0){
	return false;
}
return true;
```

## 154.使用闭包实现每隔1秒打印1,2,3,4,5

```js
//使用闭包实现
for (var i = 0; i < 5; i++) {
    (function (i) {
        setTimeout(() => {
            console.log(i);
        }, i * 1000);
    })(i);
}
//使用let块级作用域
for (let i = 0; i < 5; i++) {
    setTimeout(() => {
        console.log(i);
    }, i * 1000);
}
```

## 155.js中的命名规则

```
1.第一个字符必须市字符，下划线或者美元符号
2.剩下的字符可以是下划线，美元符号或者任何字符或数字
```

## 156.js语句末尾分号是否可以省略

```
语句结尾的分号并不是必需的。但是我们一般最好不要省略分号，因为加上分号一方面又利于我们代码的可维护性，另一方面也可以避免我们在对代码进行压缩时出现错误。
```

## 157.Object.assign()

```
Object.assign()方法用于将所有可枚举属性值从一个或者多个源对象赋值到目标对象。他将返回目标对象。
```

## 169.Math.ceil和Math.floor

```
Math.ceil 向上取整，函数返回一个大于或者等于给定数字的最小整数。
Math.floor 向下取整，函数返回一个小于或者等于给定数字的最大整数。
```

## 170.js for循环注意点

```
for(var i=0,j=0;i<5,j<9;i++,j++){
	console.log(i,j);
}
当判断语句含有多个语句时，以最好一个判断语句的值为准，因此上面的代码会执行10次
当判断语句为空时，循环一直进行。
```

## 171.一个列表，假设有100000个数据，这个该怎么办？

```
我们需要思考的问题：该处理是否必须同步完成？数据是否必须按顺序完成？
解决方法：
	1.将数据分页，利用分页的原理，每次服务器端只返回一定数目的数据，浏览器每次只对一部分进行加载。
	2.使用懒加载，每次加载一部分数据，其余部分等用的时候再去加载。
	3.适应数组分快计数，基本思路是为要处理的项目创建一个队列然后设置定时器每过一段时间取出一部分的数据，然后再使用定时器取出下一个要处理的项目进行处理，接着再设置另一个定时器。
```

## 172.进程间通信的方式？

```
1.管道通信
2.消息队列通信
3.信号量通信
4.信号通信
5.共享内存通信
6.套接字通信
```

## 173.document.write()和innerHTML()

|          | document.write()               | innerHTML()             |
| -------- | ------------------------------ | ----------------------- |
| 类型     | documengt对象中的方法          | 存于Element对象中的属性 |
| 插入位置 | 脚本元素scirpt的位置           | 指定元素内              |
| 拼接方法 | 多此调用                       | +=                      |
| 覆盖问题 | 文档解析完再调用会覆盖否则不会 | 直接调用会覆盖原有内容  |

## 174.浏览器运行机制

1. 创建DOM树
2. 创建渲染树
3. 布局渲染树
4. 绘制渲染树

## 175.回流与重绘

回流：当render tree 的一部分或全部的元素因改变了自身的宽高，布局，显示或隐藏，或者元素内部的文字结构发生变化 导致需要重新构建页面的时候，回流就产生了

重绘：当一个元素自身的宽高，布局，及显示或隐藏没有改变，而只是改变了元素的外观风格的时候，就会产生重绘。例如你改变了元素的background-color

因此得出了一个结论：**回流必定触发重绘，而重绘不一定触发回流**

