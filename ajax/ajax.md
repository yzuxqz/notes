# Ajax的实现步骤

![](D:\桌面\notes\ajax\assets\ajax实现步骤.png)

发送

```javascript
        let xhr = new XMLHttpRequest()
        xhr.open('get', 'http://localhost:3000/first')
        xhr.send()
        xhr.onload = function () {
            console.log(xhr.responseText)
        }
```

接收

```java
const express = require('express')
const path = require('path')
const app = express();

app.use(express.static(path.join(__dirname, 'public')))

app.get('/first', (req, res) => {
    res.send('first')
})
app.listen(3000)
console.log('服务器启动成功')
```

# 服务器端响应的数据格式

![](D:\桌面\notes\ajax\assets\服务端响应数据格式.png)

# 请求参数传递

![](D:\桌面\notes\ajax\assets\ajax请求参数传递.png)

## get

1. 将参数拼接在url后面
2. ？加参数，参数名=值，参数之间用&隔开

### 发送

```html
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Title</title>
</head>
<body>
<input type="text" placeholder="用户名" id="userName">
<input type="password" placeholder="密码" id="passWord">
<button>登录</button>
</body>
<script>
    window.onload =function () {
        let userName = document.querySelector('#userName')
        let passWord = document.querySelector('#passWord')
        document.querySelector('button').addEventListener('click',function () {
            let xhr= new XMLHttpRequest()
            let params = "username="+userName.value+"&passWord="+passWord.value
            xhr.open('get','http://localhost:3000/third?'+params)
            xhr.send()
            xhr.onload =function () {
                console.log(xhr.responseText)
            }
        })
    }
</script>
</html>

```

### 接收

1. req.query

```javascript
app.get('/third',(req,res)=>{
    console.log(req.query)
    res.send()
})
```

## 请求报文

![](D:\桌面\notes\ajax\assets\请求报文.png)

## post

1. 一定要在请求报文头上表明content-type（服务端向客户端传递参数的类型）
2. 参数放在send方法中，而不是url后面
3. 先body-parser模块进行解析，再通过req.body进行获取

### 发送

```html
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Title</title>
</head>
<body>
<input type="text" placeholder="用户名" id="userName">
<input type="password" placeholder="密码" id="passWord">
<button>登录</button>
</body>
<script>
    window.onload =function () {
        let userName = document.querySelector('#userName')
        let passWord = document.querySelector('#passWord')
        document.querySelector('button').addEventListener('click',function () {
            let xhr= new XMLHttpRequest()
            let params = "username="+userName.value+"&passWord="+passWord.value
            xhr.open('post','http://localhost:3000/forth')
            xhr.setRequestHeader('Content-Type','application/x-www-form-urlencoded')
            xhr.send(params)
            xhr.onload =function () {
                console.log(xhr.responseText)
            }
        })
    }
</script>
</html>

```

### 接收

```javascript
const bodyParser = require('body-parser')
app.use(bodyParser.urlencoded({extended: false}))
app.post('/forth',(req,res)=>{
    console.log(req.body)
    res.send()
})
```

## 请求参数的格式

get请求不能提交json对象数据格式，传统表单也不行，是x-www-form-urlencoded的格式

![](D:\桌面\notes\ajax\assets\请求参数格式.png)

1. 请求参数格式若为json，要修改请求头的content-type
2. 参数在send中传递，但是注意要用JSON.stringify把json对象改为json字符串再传递
3. 后端bodyparser调用json方法

### 发送

```html
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Title</title>
</head>
<body>
<input type="text" placeholder="用户名" id="userName">
<input type="password" placeholder="密码" id="passWord">
<button>登录</button>
</body>
<div>05</div>
<script>
    window.onload =function () {
        let userName = document.querySelector('#userName')
        let passWord = document.querySelector('#passWord')
        document.querySelector('button').addEventListener('click',function () {
            let xhr= new XMLHttpRequest()
            xhr.open('post','http://localhost:3000/fifth')
            xhr.setRequestHeader('Content-Type','application/json')
            xhr.send(JSON.stringify({userName:userName.value,passWord:passWord.value}))
            xhr.onload =function () {
                console.log(xhr.responseText)
            }
        })
    }
</script>
</html>

```

### 接收

```javascript
const bodyParser = require('body-parser')
app.use(bodyParser.json({extended: false}))
app.post('/fifth',(req,res)=>{
    console.log(req.body)
    res.send()
})
```

# Ajax状态码

![](D:\桌面\notes\ajax\assets\ajax状态码.png)

## 获取服务端响应

onreadystatechange事件，当ajax状态码发生变化时触发该事件

![](D:\桌面\notes\ajax\assets\获取服务端响应.png)

# http状态码

![](D:\桌面\notes\ajax\assets\ajax错误处理.png)

## 发送

```javascript
      let xhr = new  XMLHttpRequest()
        xhr.open('get','http://localhost:3000/six')
        xhr.send()
        xhr.onload=function () {
            if(xhr.status===400){
                console.log('请求出错')
            }
        }
```

## 接收

```javascript
app.get('/six',(req,res)=>{
    res.status(400).send()
})
```

# 低版本ie缓存问题

![](D:\桌面\notes\ajax\assets\缓存问题.png)

# Ajax封装

1. 根据不同的请求方式，对传递的参数进行处理，首先进行参数拼接，请求方式为get，将参数添加到url后面
2. post请求中，判断不同的参数类型（Content-Type），如果为json，将json转为json字符串后放入send中，否则直接将拼接的字符串放入send中
3. 根据http状态码返回200才调用success函数
4. 处理后端返回的数剧，根据xhr.getResponseHeader('Content-Type')获得响应头数据的类型，如果是json字符串则要转为json对象
5. 设置默认对象，用Object.assign（）对默认对象进行覆盖

```javascript
 window.onload = function () {
        function ajax(obj) {

            let defaultObj = {
                type:'get',
                url:'',
                data:{},
                header:{
                    'Content-Type':'application/x-www-form-urlencoded'
                },
                success:function () {

                },
                error:function () {

                }
            } //默认对象
            Object.assign(defaultObj,obj)//属性覆盖

            let xhr = new XMLHttpRequest()
            let params = ''//拼接get参数
            let contentType = defaultObj.header['Content-Type']//发送的参数的类型
            for (const Key in defaultObj.data) {
                params += Key + '=' + defaultObj.data[Key] + '&'
            }
            params = params.substr(0, params.length - 1)
            if (defaultObj.type === 'get') {
                defaultObj.url = defaultObj.url + '?' + params
            }
            xhr.open(defaultObj.type, defaultObj.url)
            xhr.setRequestHeader('Content-Type', contentType)//设置请求参数格式类型
            if (defaultObj.type === 'post') {//判断请求参数的格式
                if (contentType === 'application/json') {
                    xhr.send(JSON.stringify(defaultObj.data))
                } else {
                    xhr.send(params)
                }
            } else {
                xhr.send()
            }
            xhr.onload = function () {
                let responseText = xhr.responseText
                if(xhr.getResponseHeader('Content-Type').includes('application/json')){
                    responseText = JSON.parse(responseText)
                }
                if(xhr.status===200){
                    defaultObj.success(responseText)
                }else{
                    defaultObj.error(responseText)
                }

            }
        }

        ajax({
            type: 'post',
            url: 'http://localhost:3000/first',
            data: {
                userName: 'xqz',
                password: '123'
            },
            header: {
                'Content-Type': 'application/json'
            },
            success: function (data) {
                console.log(data)
            },
            error:function (data) {
                console.log('error'+data)
            }

        })
    }
```

# 同源政策

![](D:\桌面\notes\ajax\assets\同源.png)

## 使用jsonp解决同源限制问题

1. 服务端返回的是一个函数，函数的参数就是返回值
2. 客户端通过script标签，src属性的值为服务端的url地址
3. 函数需要在script标签之前就定义
4. 然后在script标签中返回的是函数的调用

![](D:\桌面\notes\ajax\assets\解决同源1.png)

## 客户端

```html
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Title</title>
</head>
<body>
<script>
    function f(data) {
        console.log('客户端的f函数被调用')
        console.log(data)
    }
</script>
<!--将非同源服务器端的请求地址写在script标签src中-->
<script src="http://localhost:3001/test">
//服务器端返回f函数的调用
</script>
</body>
</html>
```

## 服务端

```javascript
const express = require('express')
const path = require('path')
const app = express();
const bodyParser = require('body-parser')
app.use(express.static(path.join(__dirname, 'public')))
app.use(bodyParser.urlencoded({extended: false}))

app.get('/test', (req, res) => {
    const result = 'f({name:"张三"})'
    res.send(result)//返回的是该函数的调用
})

app.listen(3001)
console.log('服务器启动成功')
```

## jsonp客户端代码优化

1. 客户端需要将函数名称传递到服务器
2. 将jsonp请求变成动态请求
3. 封装jsonp方法

客户端

```html
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Title</title>
</head>
<body>
<button>向app2请求数据</button>
<script>
    function f(data) {
        console.log('客户端的f函数被调用')
        console.log(data)
    }
</script>
<script>
    window.onload = function () {
        let btn = document.querySelector('button')
        btn.addEventListener('click', function () {
            jsonp({
                url:'http://localhost:3001/test?callback=f'//传递函数名
            })
        })

        function jsonp(obj) {
            let script = document.createElement('script')//动态添加script标签
            script.src = obj.url
            document.body.appendChild(script)
            script.onload = function () {//加载完成后删除
                document.body.removeChild(this)
            }
        }
    }
</script>
</body>
</html>

```

服务端

```javascript
app.get('/better', (req, res) => {
    const fnName = req.query.callback//接收客户端传过来的函数名称
    const result = fnName + '({name:"张三"})'//将函数名称对应的函数调用代码返回给客户端
    res.send(result)
})
```

4.用回调函数去接收服务端传来的数据（不用再在script标签中定义方法），但是此时方法不是全局作用域下，而导致服务端看不到的情况，给window属性，属性名为方法名，并将方法名通过url传递给后端

5.方法名应该随机传递给后端，这样回调才不会出错

客户端

```html
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Title</title>
</head>
<body>
<button id="firstBtn">向app2请求数据01</button>
<button id="secondBtn">向app2请求数据02</button>
<script>
    window.onload = function () {
        let btn1 = document.querySelector('#firstBtn')
        let btn2=document.querySelector('#secondBtn')
        btn1.addEventListener('click', function () {
            jsonp({
                url:'http://localhost:3001/better',
                success:function (data) {
                    console.log(data)
                }
            })
        })
        btn2.addEventListener('click', function () {
            jsonp({
                url:'http://localhost:3001/better',
                success:function (data) {
                    console.log(data)
                }
            })
        })
        function jsonp(obj) {
            let script = document.createElement('script')
            let fnName = 'myJsonp'+Math.random().toString().replace('.','')//随机方法名，也就是window对象下存储方法的属性名
            window[fnName] = obj.success//变成全局函数
            script.src = obj.url+'?callback='+fnName
            document.body.appendChild(script)
            script.onload = function () {
                document.body.removeChild(this)
            }
        }
    }
</script>
</body>
</html>
```

服务端不变

6.需要传递其它get参数时

客户端

```html
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Title</title>
</head>
<body>
<button id="firstBtn">向app2请求数据01</button>
<button id="secondBtn">向app2请求数据02</button>
<script>
    window.onload = function () {
        let btn1 = document.querySelector('#firstBtn')
        let btn2=document.querySelector('#secondBtn')
        btn1.addEventListener('click', function () {
            jsonp({
                url:'http://localhost:3001/better',
                success:function (data) {
                    console.log(data)
                }
            })
        })
        btn2.addEventListener('click', function () {
            jsonp({
                url:'http://localhost:3001/better',
                data:{
                  name:'lisi',
                  age:12
                },//传递参数
                success:function (data) {
                    console.log(data)
                }
            })
        })
        function jsonp(obj) {
            let script = document.createElement('script')
            let fnName = 'myJsonp'+Math.random().toString().replace('.','')
            let params=''
            for (const Key in obj.data) {
                params += '&'+Key+'='+obj.data[Key]//拼接字符串
            }
            window[fnName] = obj.success 
            console.log(window[fnName])
            script.src = obj.url+'?callback='+fnName+params//拼接到url后面
            document.body.appendChild(script)
            script.onload = function () {
                document.body.removeChild(this)
            }
        }
    }
</script>
</body>
</html>

```

服务端不变

## jsonp服务端代码优化

1. express框架中的res有jsonp方法

```javascript
app.get('/better', (req, res) => {
    // const fnName = req.query.callback//接收客户端传过来的函数名称
    // const data = JSON.stringify({nme:'张三'})
    // const result = fnName + `(${data})`//将函数名称对应的函数调用代码返回给客户端
    // res.send(result)
    res.jsonp({name:'lisi',age:20})
})
```

## 访问非同源数据，服务器端解决方案

![](D:\桌面\notes\ajax\assets\同源政策服务端解决方案.png)

1. app1前端向后端发送请求
2. app1后端向app2后端发送请求，拿到数据返回给app1前端
3. app1后端需要install request模块

app1客户端

```javascript
 btn.onclick = function () {
        ajax({
            type: 'get',
            url: 'http://localhost:3000/eleven',
            success: function (data) {
                console.log(JSON.parse(data))
            }
        })
    }
```

app1服务端

```javascript
const request = require('request')//获取其他服务器的数据
app.get('/eleven',(req,res)=>{
    request('http://localhost:3001/better', //app2的请求地址
            (err,response,body)=>{
        res.send(body)
    })
})
```

## CORS解决跨域问题

![](D:\桌面\notes\ajax\assets\CORS.png)

access-control-allow-origin表示允许访问该服务器的端口，*表示所有都可以,Access-Control-Allow-Methods设置请求方式

在express框架中使用res.header(‘响应头的属性名称’，‘响应头的属性值’)设置响应头

```javascript
app.use((req,res,next)=>{
    //允许所有的客户端访问我
    res.header('Access-Control-Allow-Origin','*')
    //允许客户端使用哪些请求方法访问我
    res.header('Access-Control-Allow-Methods','get,post')
    next()//释放请求，请求继续往下匹配
})
```

# cookie

![](D:\桌面\notes\ajax\assets\cookie.png)

## withCredentials属性

![](D:\桌面\notes\ajax\assets\withCredentials.png)

# RESTful API

![](D:\桌面\notes\ajax\assets\RESTful.png)

服务端

![](D:\桌面\notes\ajax\assets\resful服务端.png)