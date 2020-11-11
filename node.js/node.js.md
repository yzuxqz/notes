# 环境变量

1. 当我们在命令行窗口打开一个文件或调用一个程序时，系统会首先在当前目录下寻找文件程序，如果找到了直接打开，如果没找到会依次到环境变量path的路径中寻找，否则报错，类似于作用域链。
2. 将一些经常需要访问的程序和文件的路径添加到path中，这样我们就可以在任意位置来访问这些文件和程序了。

# 进程和线程

## 进程

1. 负责为程序的运行提供必备的环境
2. 进程就相当于工厂中的车间

## 线程

1. 线程计算机中的最小的计算单位，线程负责执行进程中的程序
2. 线程相当于工厂中的工人

### 单线程

1. js是单线程

### 多线程

# node简介

1. 能够在服务器端运行的JavaScript环境
2. 处理不了并发量过高的情况，基于web的轻量级应用
3. node是单线程，处理速度很快，对服务器硬件要求低。但是处理不了过多的用户，此时只能用分布式。

# node基础

## 模块化

1. 在node中，一个js文件就是一个模块

2. 在node中，通过require()函数来引入外部的模块,require()可以传递一个文件的路径作为参数，node将会自动根据该路径来引入外部模块

3. 使用require()引入模块以后，该函数会返回一个对象，这个对象代表的是引入的模块

4. 在node中，每一个js文件中的js代码都是独立运行在一个函数中的function（）{}，在全局里看不到，所以一个模块中的变量和函数在其他模块中无法访问

5. 在node中向外部暴露属性或方法，用exports，将需要暴露给外部的变量或方法设置为exports的属性即可

   ```javascript
   exports.x = "我是02.module.js中的x"
   exports.add = function(a,b){
       return a+b
   }
   ```

## 模块标识

1. 使用require()引入外部模块时，使用的就是==模块标识==，我们可以通过模块标识来找到指定的模块

### 核心模块

1. 由node引擎提供的模块

2. 核心模块的标识就是模块的名字

   ```javascript
   var fs = require("fs")
   ```

### 文件模块

1. 由用户自己创建的模块
2. 文件模块的标识就是文件的路径（绝对，相对）

## 全局对象

1. global，它的作用和window类似

2. 在全局中创建的变量都会作为global的属性保存

3. 在全局中创建的函数都会作为global方法保存

   ```javascript
   {a = 10
   log(global.a)}//argunments.callee当前执行的函数对象
   ```

4. node在执行模块中的代码时，它会在代码的最顶部，添加function（exports，require，module，_filename,_dirname）{

   在代码的最底部，添加如下代码 }

5. 实际上模块中的代码都是包装在一个函数中执行的，并且在函数执行时，同时传递进了5个实参

   | 实参      |                                                              |
   | --------- | ------------------------------------------------------------ |
   | exports   | 该对象用于将变量或函数暴露到外部                             |
   | require   | 函数，用来引入外部的模块                                     |
   | module    | 代表的是当前模块自身，exports就是module的属性，可以使用exports导出，也可以使用module.exports导出 |
   | _filename | 当前模块的完整路径                                           |
   | _dirname  | 当前模块所在文件夹的完整路径                                 |


## exports和module.exports

1. 通过exports只能使用.的方式来向外暴露内部变量

2. module.exports既可以通过.的方式，也可以直接赋值

   ```javascript
   module.exports.xxx = xxx
   module.exports = {}
   ```

## 包

1. 包实际上就是一个压缩文件，解压以后还原为目录。符合规范的目录，应该包含

   | 文件名       |                  |
   | ------------ | ---------------- |
   | package.json | 描述文件         |
   | bin          | 可执行二进制文件 |
   | lib          | js代码           |
   | doc          | 文档             |
   | test         | 单元测试         |

  2.package.json中的属性含义，json文件中不能写注释

| 属性名          |                  |
| --------------- | ---------------- |
| dependencies    | 依赖的其他包     |
| description     | 描述该包的作用   |
| devDependencies | 开发环境依赖     |
| name            | 名字,用于require |
| version         | 版本             |
| keywords        | 关键字，用于搜索 |
| maintainers     | 贡献者           |
| contributors    | 维护者           |
| bugs            | 提交bug地址      |
| licenses        | 协议             |
| repositories    | 仓库             |
| homepage        | 主页             |
| os              | 系统             |

## npm简介

1. Node Package Manager
2. 对于node而言，npm帮助其完成了第三方模块的发布，安装和依赖。借助NPM，node与的三方模块之间形成了很好的一个生态系统。

## npm命令

| 命令                    |                                                              |
| ----------------------- | ------------------------------------------------------------ |
| npm-v                   | 查看版本                                                     |
| npm                     | 帮助说明                                                     |
| npm init                | 创建package.json文件                                         |
| npm search 包名         | 搜索模块包                                                   |
| npm install 包名        | 在当前目录安装包                                             |
| npm install 包名 -g     | 全局模式安装包（一般都是一些工具，在计算机里用的，不是在项目中用的） |
| npm install 包名 --save | 安装包并添加自己初始化的package.json的依赖中                 |
| npm remove 包名         | 删除包                                                       |
| npm install             | 下载当前项目所依赖的包                                       |

1. 在需要安装npm包的目录下用npm init来初始化package.json文件
2. 通过npm下载的包，通过包名引入即可
3. node在使用模块名引入模块时，会首先在当前目录的node_modules中寻找是否含有该模块，如果有，则直接使用，如果没有则再去上一级目录寻找，知道找到为止，直到磁盘的根目录，没有则报错

## Buffer缓冲区

1. Buffer的结构和数组很像，操作的方法也和数组类似

2. 数组中不能存储二进制文件，而buffer就是专门存储二进制文件的

3. Buffer式node中的核心模块，使用buffer不用引入模块直接使用

4. 在buffer中存储的都是二进制数据，但是在显示的时候都是以16进制的形式显示

5. ```javascript
   buffer.length  //占用内存的大小，一个汉字占用3个字节，一个字母占用1个字节（8位二进制）
   str.length	//字符串的长度
   ```

6. buffer的构造函数已经废弃了

### 创建和写入

| API                      |                                                              |
| ------------------------ | ------------------------------------------------------------ |
| Buffer.alloc(size)       | 创建一个指定大小的buffer，且把内存的数据清空，都为0          |
| Buffer.allocUnsafe(size) | 创建一个指定大小的buffer，但是buffer中可能含有敏感数据，不会清空内存，但是这个性能更好 |
| Buffer.from(str)         | 将一个字符串转化内buffer                                     |
| buf.toString             | 将缓冲区中的数据转换为字符串                                 |

```javascript
//创建10个字节的buffer
let buf2 = Buffer.alloc(10)
//通过索引，来操作buffer中的元素
buf2[0] = 88
buf2[1] = 255
buf2[2] = 0xaa

let str = 'Hello Buffer'
//将一个字符串保存到buffer中
let buf = Buffer.from(str)
console.log(buf.length)
```

==注意==：

1. buffer的长度一旦确定，就无法改变，因为buffer是直接操作内存的，alloc(10)就是直接分配10个字节的连续的内存空间
2. 如果超过8位二进制【0-256），则取后8位

### 读取

1. buf[index]
2. 调用buf.toString()，可以直接把缓冲区中的数据转为字符串

```javascript
buf[2]  //170,虽然村的时候是16进制，但是只要在控制台输出数字，那一定是10进制

log(buf[2].toString(16))//输出16进制字符串
```

## fs

1. 通过node来操作系统中的文件

### 引入

1. const fs = reqire('fs')

### 同步文件

1. 打开文件

   fs.openSync(path,flags[,mode])

   |       |                                          |
   | ----- | ---------------------------------------- |
   | path  | 要打开文件的路径                         |
   | flags | 打开文件要做的操作类型 r:只读的 w:可写的 |
   | mode  | 设置文件的操作权限，一般不传             |

   返回值：该方法会返回文件的描述符作为结果，我们可以通过该描述符来对文件进行各种操作

2. 写入内容

   fs.writeSync（fd,string[,position[,ecoding]]）

   |          |                                                      |
   | -------- | ---------------------------------------------------- |
   | fd       | 文件的描述符，需要传递要写入的文件的描述符（变量名） |
   | string   | 要写入的内容                                         |
   | position | 写入的起始位置                                       |
   | ecoding  | 写入的编码，默认是utf-8                              |

   3.关闭文件

   fs.closeSync(fd)

   ```javascript
   let fs = require('fs')
   
   let fd = fs.openSync('hello.txt','w')
   
   fs.writeSync(fd,"今天天气真不错",20)
   fs.closeSync(fd)
   
   ```

### 异步文件

1. 打开

   fs.open(path,flags[,mode],callback)

   除了callback是回调函数外，其他和同步相同，两个参数

   err：错误对象，如果没有错误则为null

   fd：文件的描述符

2. 写入

   fs.write(fd,callback)

3. 关闭

   fs.close(fd,callback)

```javascript
let fs = require('fs')

fs.open("hello2.txt", 'w', function (err, fd) {
    if (!err) {
        fs.write(fd, "这是异步回调的内容", function (err, written, string) {
            if (!err) {
                console.log('写入成功')
            }
            //关闭文件
            fs.close(fd,function (err) {
                if(!err){
                    console.log('文件已关闭')
                }
            })
        })
    } else {
        console.log(err)
    }
})
```

### 简单文件

异步：fs.writeFile(file,data[,options],callback)

==注意==：options是可选项，默认写入w，utf-8,{flag:'r'}进行修改，mode：文件权限

同步：fs.writeFileSync(file,data[,options])

```javascript
let fs = require('fs')
fs.writeFile('hello3.txt', '这是通过writeFile写入的内容',{flag:'r'}, function (err) {
    if (!err) {
        console.log('写入成功')
    }
})
```

![](D:\桌面\notes\node.js\assest\打开方式.png)

如果要写磁盘的位置用绝对路径

### 流式文件

1. 同步，异步，简单文件的写入都不适合大文件的写入，性能较差，容易导致内存溢出

#### 可写流

fs.createWriteStream(path[,options])  //文件路径和配置参数

只要流存在就可以一直写入文件内容

```javascript
let fs = require('fs')
let ws= fs.createWriteStream('hello3.txt')
//向文件中输出内容
ws.write("通过可写流写入文件内容")
ws.write("通过可写流写入文件内容")
ws.write("通过可写流写入文件内容")
```

#### 监听

1. 可以通过监听流的open和close事件来监听流的打开和关闭，用once事件监听

   ```javascript
   let fs = require('fs')
   let ws= fs.createWriteStream('hello3.txt')
   //向文件中输出内容
   ws.write("通过可写流写入文件内容")
   ws.write("通过可写流写入文件内容")
   ws.write("通过可写流写入文件内容")
   
   ws.once('open',function () {
       console.log("流打开了")
   })
   ws.once('close',function () {
       console.log("流关闭了")
   })
   ws.end() //这里不能用close，相当于拔掉了水管的输出端，end是输入端
   ```

### 文件读取

同步

异步

简单

fs.readFile(path[,options],callback)

fs.readFileSync(path[,options])  //通过返回值

|                      |                          |
| -------------------- | ------------------------ |
| path                 | 要读取的文件路径         |
| options              | 读取的选项               |
| callback（err,data） | 回调函数，读取返回的内容 |

```javascript
let fs = require('fs')
fs.readFile('hello3.txt',function (err,data) {
    //读取
    if(!err){
        console.log(data.toString())
        //写入
        fs.writeFile('hello4.txt',data,function (err) {
            if(!err){
                console.log('文件写入成功')
            }

        })
    }else{
        console.log(err)
    }
})

```

流式

1. 如果文件小，只读一次
2. 如果文件大，会分多个buffer读取，每次65536个字节的数据，避免占用大量内存空间

```javascript
let fs = require('fs')
//可读流
let rs = fs.createReadStream('hello4.txt')
rs.once('open',function () {
    console.log('可读流打开')
})
rs.once('close',function () {
    console.log('可读流关闭')
})
//如果要读取可读流中的数据，必须绑定一个data事件，会自动读取数据
rs.on("data",function (data) {
    console.log(data)
})

```

读取后写入其他文件，注意可写流要在可读流关闭时关闭

```javascript
let fs = require('fs')
//可读流
let rs = fs.createReadStream('hello4.txt')
//可写流
let ws  =fs.createWriteStream('hello5.txt')
rs.once('open',function () {
    console.log('可读流打开')
})
rs.once('close',function () {
    console.log('可读流关闭')
    ws.close()
})
ws.once('open',function () {
    console.log('可写流打开')
})
ws.once('close',function () {
    console.log('可写流关闭')
})
//如果要读取可读流中的数据，必须绑定一个data事件，会自动读取数据
rs.on("data",function (data) {
    console.log(data)
    //将读取的数据写入可写流中
    ws.write(data)
    //数据写入完毕关闭可写流，在可读流关闭时关闭
})
```

简单的写法

rs.pipe(ws)

```javascript
let fs = require('fs')
//可读流
let rs = fs.createReadStream('hello4.txt')
//pipe（）可以将可读流中的数据直接输出到可写流中
rs.pipe(ws)
```

### 其他方法

![](D:\桌面\notes\node.js\assest\fs其他.png)

callback参数err，data

![](D:\桌面\notes\node.js\assest\fs其他2.png)

![](D:\桌面\notes\node.js\assest\fs其他3.png)

watchFile中的functionn（curr,prev）

这两个参数都是stats对象，可以用属性

options是对象，可以修改文件的监视时间频率

# formidable模块

https://www.cnblogs.com/abab301/p/9489000.html

