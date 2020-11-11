# namespace模式

```javascript
let obj ={
    msg:'module',
    foo(){
        console.log('foo()',this.msg)
    }
}
```

```html
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Title</title>
</head>
<body>

</body>
<script src="module.js"></script>
<script>
    obj.foo()
    obj.msg='修改了'//对象中的值仍然可以被修改
    obj.foo()
</script>
</html>
```

# IIFE模式

```javascript
//有独立的作用域
(function (window) {
    let msg = 'module'

    function foo() {
        console.log('foo()', msg)
    }
    //给全局的window对象添加属性
    window.module={foo}
})(window)//闭包
```

```html
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Title</title>
</head>
<body>

</body>
<script src="module.js"></script>
<script>
module.foo()
</script>
</html>
```

# IIFE模式增强

```javascript
//有独立的作用域
(function (window, $) {
    let msg = 'module'

    function foo() {
        console.log('foo()', msg)
    }

    window.module = foo
    $('body').css('background', 'red')

})(window, jQuery)
```

```html
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Title</title>
</head>
<body>

</body>
<script src="jquery.min.js"></script>
<script src="module.js"></script>
<script>
    module()
</script>
</html>
```

# CommonJS

## 规范

![](D:\桌面\notes\JS模块化\assets\Commmonjs.png)

## 基于服务器端

文件结构

![](D:\桌面\notes\JS模块化\assets\CommonJS-node.png)

```javascript
//1
module.exports={
    msg:'module1',
    foo(){
        console.log(this.msg)
    }
}
//2
module.exports = function () {
    console.log('module2')
}
//3
exports.foo=function () {
    console.log('foo() module3')
}
exports.bar=function () {
    console.log('bar() module3')
}
exports.arr=[1,2,3,5,4,3,3,5]
```

```javascript
//app.js
//引入第三方库
let uniq =require('uniq')
//将其他的模块汇集到主模块
let module1 = require('./modules/module1')
let module2 = require('./modules/module2')
let module3 = require('./modules/module3')

module1.foo()
module2()
module3.foo()
module3.bar()
let result = uniq(module3.arr)
console.log(result)
```

==注意==：

1. npm install xxx --save-dev 标识开发依赖包

## 基于浏览器端

文件结构

![](D:\桌面\notes\JS模块化\assets\Commonjs-browserify.png)

1. 首先和服务端一样，用module.epxorts进行暴露，require进行引入

2. 其次

   全局下载browserify包：npm install browerify

   再局部下载开发依赖：npm install browerify --save-dev

3. 其次命令行打包处理：

   **错误内容：**
   `'browserify' 不是内部或外部命令，也不是可运行的程序
   或批处理文件。`

   **已解决：**
   命令行前面加上browserify的路径即可，
   `node_modules\.bin\browserify js/src/app.js -o js/dist/build.js`

   ==注意==：

   1. 前面的是原文件
   2. -o表示output
   3. 后面的是输出文件的目录以及文件名字

4. 然后在index.html中引入输出的新文件，即可在浏览器端使用require

# AMD

## 规范

![](D:\桌面\notes\JS模块化\assets\AMD.png)

文件结构

![](D:\桌面\notes\JS模块化\assets\RequireJS.png)

下载requireJS

定义没有依赖的模块

```javascript
//没有依赖的模块
define(function () {
    let name = 'dataService'

    function getName() {
        return name
    }

    //暴露模块
    return {getName}
})
```

定义有依赖的模块

```javascript
//定义有依赖的模块
define(['dataService'],function (dataService) {
    let msg = 'alerter.js'
    function showMsg() {
        console.log(msg,dataService.getName())
    }
    //暴露模块
    return {showMsg}
})
```

main.js

```javascript
(function () {

    requirejs.config({
        baseUrl: 'js/',//基本的路径,出发点在根目录下
        paths: {//配置路径
            dataService: './modules/dataService',//属性名和之前定义的模块名一样
            alerter: './modules/alerter'
        }
    })
    requirejs(['alerter'], function (alerter) {
        alerter.showMsg()
    })
})()
```

==注意==：

1. 引入jquery时要小写

index.html

```html
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Title</title>
</head>
<body>

</body>
<script data-main="./js/main.js" src="./js/libs/require.js"></script>//先通过src找到require第三方库，然后通过data-main找到main.js，再从main中的path找到相应的模块路径
</html>
```



# CMD

# ES6

![](D:\桌面\notes\JS模块化\assets\ES6.png)

步骤：

1. 定义package.json文件

2. 安装babel-cli，babel-preset-es2015和browserify

   - npm install babel-cli browserify -g
   - npm install babel-preset-es2015 --save-dev
   - preset 预设（将es6转为es5的所有插件打包）

3. 定义.babelrc文件,

   ```javascript
   {
     "presets": ["es2015"]
   }
   ```

4. 编码

   文件结构

![](D:\桌面\notes\JS模块化\assets\ES6babel.png)

## 分别暴露

```javascript
//暴露模块 分别暴露
export function foo() {
    console.log('foo() module1')
}

export function bar() {
    console.log('bar() module1')
}

export let arr = [1,3,4,5]
```

## 统一暴露

```javascript
//统一暴露
function fun() {
    console.log('fun() module2')
}

function fun2() {
    console.log('fun2() module2')
}

export {fun,fun2}
```

## 默认暴露

```javascript
//默认暴露 可以暴露任意数据类型 暴露什么数据接收到的就是什么数据
//只能一次
// export default ()=>{
//     console.log("默认")
// }
export default {
    msg:'默认暴露',
    foo(){
        console.log(this.msg)
    }
}
```

main

```javascript
//引入其他的模块

//语法：import xxx from ‘路径’
import {foo,bar} from './module1'
import {fun,fun2} from './module2'
import module3 from './module3'

console.log(module3.foo())
console.log(foo(),bar(),module2)

console.log(module1,module2)
```

​	==注意==：

1. 要使用解构赋值的方式来引入模块

5.编译

- 使用babel将ES6编译为ES5代码：==babel js/src -d js/lib==  

  ​													源文件目录      编译后的文件目录

  改成require那种es5的，但是require仍然需要转换

- 使用Browserify编译js：==browserify js/lib/main.js -o js/lib/bundle.js==

6.引入：index.html中使用bundle文件

​	==注意==：

1. 一旦修改了js文件就需要重新编译打包

打包完成后文件结构

![](D:\桌面\notes\JS模块化\assets\ES6打包后.png)