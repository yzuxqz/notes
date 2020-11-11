# 入口函数

$是jQuery的顶级对象，相当于JS中的window

```javascript
        // 法1
        $(document).ready(function () {
            $('div').hide();
        })
        // 法2
        $(function () {
            $('div').hide();
        })
```

==注意==：

1. 区别原始js的onload函数会等DOM和图片都加载完执行，而jQuery的入口函数在DOM加载完就会执行
2. onload会覆盖，而jQuery会依次执行

# jQuery对象

本质：利用$对DOM对象包装后产生的对象，以==伪数组==形式存储，jQuery对象只能使用jQuery方法

## 隐式迭代

通过选择器遍历内部DOM元素，以伪数组的形式存储的过程

```javascript
$("ul li").css("color", "#ccc");
```

## jQuery对象与DOM对象之间的转换

1. DOM转jQuery

   var div = document.querySelector('');

   $(div);

2. jQuery转DOM

   $("div")[index]或者$("div").get(index)

# jQuery静态方法

## each(obj,[calback])

1. 遍历谁就返回谁
2. 不支持在回调函数中对数组进行处理

见元素选择操作

## map(arr|obj,callback)

1. 和原生的forEach一样不能遍历伪数组

2. return后会返回一个新的数组，默认不return，就返回空数组

3. ```javascript
   let arr =[1,4,6,52,2,6]
   $.map(arr,function (value,index) {
       console.log(value)
       return value + index
   })
   ```

## trim(str)

1. 返回新的字符串
2. 去除两端空格

```javascript
        str = '       3434          '
        let newStr =$.trim(str)
        console.log(newStr)
```



## isArray(obj)

## isfunction(obj)

## isWindow(obj)

判断传入的对象是否为window对象，返回值为boolean

## holdReady(hold)

暂停入口函数，等页面其他元素加载完成后再加载

```html
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Title</title>
    <script src="jquery.min.js"></script>
    <script>
        //暂停入口函数
        $.holdReady(true)
        $(function () {
            alert('ready')
        })
    </script>
</head>
<body>
<button>ready</button>
</body>
<script>
   let btn = document.querySelector('button')
    btn.addEventListener('click',function () {
        $.holdReady(false)
    })
</script>
</html>

```



# jQuery基本选择器

| 名称       | 用法            | 描述                      |
| ---------- | --------------- | ------------------------- |
| ID选择器   | $("#id")        | 获取指定ID的元素          |
| 全选择器   | $('*')          | 匹配所有元素              |
| 类选择器   | $(".class")     | 获取同一类class的元素     |
| 标签选择器 | $("div")        | 获取同一类标签的所有元素‘ |
| 子代选择器 | $("ul>li")      | 只获取亲儿子层            |
| 后代选择器 | $("ul li")      | ul下所有层级的li          |
| 并集选择器 | $("div,p,li")   | 选取多个元素              |
| 交集选择器 | $("li,current") | 交集元素                  |

# jQuery筛选选择器

| 语法       | 用法                     | 描述                                                      |
| ---------- | ------------------------ | --------------------------------------------------------- |
| :first     | $('li:first')            | 获取第一个li元素                                          |
| :last      | $('li:last')             | 获取最后一个li元素                                        |
| :eq(index) | $("li:eq(2)")            | 获取到li，因为是存在伪数组中，然后选择索引，索引号从0开始 |
| :odd       | $("li:odd")              | 获取到li元素中，选择索引号为奇数的元素                    |
| :even      | $("li:even")             | 获取到li元素中，选择索引号为偶数的元素                    |
| :checked   | $(".j-checkbox:checked") | 查找被选中的表单元素，.length获取选中个数                 |
| :empty     | $("div:empty")           | 找到没有文本内容或有子元素的指定元素                      |
| :parent    | $("div:parent")          | 找到有文本内容或者有子元素的指定元素                      |



# jQuery筛选方法

| 语法               | 用法                           | 说明                                               |
| ------------------ | ------------------------------ | -------------------------------------------------- |
| parent()           | $("li").parent()               | 查找父级                                           |
| children(selector) | $("ul").children("li")         | 相当于子代选择器                                   |
| find(selector)     | $("ul").find("li")             | 相当于后代选择器                                   |
| siblings(selector) | $(".first").siblings("li")     | 查找兄弟节点，不包括自己本身                       |
| nextAll([expr])    | $(".first").nextAll()          | 查找当前元素之后所有的同辈元素                     |
| prevAll([expr])    | $(".last").prevAll()           | 查找当前元素之前所有的同辈元素                     |
| hasClass(class)    | $('div').hasClass('protected') | 检查当前的元素是否包含某个特定的类，如果有返回true |
| eq(index)          | $("li").eq(2)                  | 相当于筛选器$("li:eq(2)")                          |

其他：

- $(this) 当前元素
- $(this).index() 当前元素索引号
- $("div").parents("") 返回指定父级

# jQuery排他思想

var index = $(this).index;

$().eq(index).siblings("").hide();

$().eq(index).show();

```javascript
$(function () {
    //隐式迭代
    $("button").click(function () {
        $(this).siblings("button").css("background", "");
        $(this).css("background", "red");
    })
})
```

# jQuery尺寸

| 属性                               | 说明                        |
| ---------------------------------- | --------------------------- |
| width()/height()                   | 只包含width或者height       |
| innerWidth()/innerHeight()         | 包含padding                 |
| outerWidth()/outerHeight()         | 包含padding，border         |
| outerWidth(true)/outerHeight(true) | 包含padding，border，margin |

# jQuery位置

| 属性        | 说明                                                         |
| ----------- | ------------------------------------------------------------ |
| offset()    | 设置或返回元素相对于文档的偏移坐标和父级无关，offset().top,;offset({top:,left:}) |
| position()  | 设置或返回元素相对于带有定位的父级偏移坐标，只能获取，不能设置 |
| scrollTop() | 设置或返回被选元素被卷曲的头部;scrollTop(100)设置被卷去的头部 |

```html
<body>
    <div class="father">
        <div class="son"></div>
    </div>
    <script>
        console.log($(".son").offset().top);
        $(".son").offset({
            left:300
        });
    </script>
</body>
```

## 窗口滚动事件

$(Window).scroll(function(){})

## 带有动画的返回顶部

$("body,html").animate({scrollTop:0})

```html
<body>
    <div></div>
    <a href="javascript:;">返回顶部</a>
    <script>
        $(function () {
            //div距离文档顶部的值
            var boxTop = $("div").offset().top;
            $(window).scroll(function () {
                if ($(document).scrollTop() >= boxTop) {
                    $("a").fadeIn();
                } else {
                    $("a").fadeOut();
                }
                $("a").on("click", function () {
                    // $(document).scrollTop(0);
                    $("body,html").stop().animate({
                        scrollTop: 0
                    })
                })
            })
        })
    </script>
</body>
```

==注意==：只有元素可以做动画

# jQuery样式操作

| API                                           | 说明                             |
| --------------------------------------------- | -------------------------------- |
| $(this).css("color")                          | 参数只写属性名，则是只返回属性值 |
| $(this).css("color","red")                    | 值如果是数字可以不加单位和引号   |
| $(this).css({"color":"white","font-size":20}) | 参数为对象形式                   |

# jQuery类操作

jQuery不会覆盖原先的其他类

| API                     | 说明           |
| ----------------------- | -------------- |
| $(this).addClass("")    | 添加类         |
| $(this).removeClass("") | 删除类         |
| $(this).toggleClass("") | 有变无，无变有 |



# jQuery属性操作

| API                    | 说明                                                        |
| ---------------------- | ----------------------------------------------------------- |
| element.prop("")       | 获取元素固有属性的属性值                                    |
| element.prop("","")    | 修改元素固有属性的属性值                                    |
| element.removepro("")  | 移除属性                                                    |
| element.attr("")       | 获取自定义属性                                              |
| element.attr("","")    | 修改自定义属性,根据jquery的隐式迭代，找到多少就能设置多少个 |
| element.removeattr("") | 移除属性                                                    |

==注意==：

1. 在操作属性节点时，具有true和false两个属性的属性节点，如checked，selected获得disabled使用prop()返回true或者false，其他的使用attr（）返回值

## 数据缓存

data()可在元素上存取数据，且不会修改DOM元素结构，一旦页面刷新，之前的数据会被移除

$("").data("键"，"值")//相当于把数据存入变量

$("").data("键")//返回对应值

# jQuery内容文本值

## 普通元素内容

$("").html()//获取元素内容，相当于js中的innerHTML

$("").html("")//设置元素内容

## 获取元素文本内容

$("").text()

## 表单值

$("").val()

# jQuery元素操作

## 遍历元素

1. $("div").each(function(index,domEle){})

   注意：domEle是DOM元素，想要使用jQuery方法，需要给转为jQuery对象:$(domEle

   ```javascript
       $(function () {
           var arr = ["red", "blue", "black"];
           var sum = 0;
           $("div").each(function (index, domEle) {//index:每个元素的索引号，domEle：每个DOM元素对象
               $(domEle).css("color", arr[index]);
               sum += parseInt($(domEle).html());
           })
           console.log(sum);
       })
   ```

2. $.each(arr,function(index,ele){})

   用于遍历数据（数组，对象），可以遍历伪数组

   ```javascript
   $.each(arr,function(index,ele){})//index为数组索引
   $.each({name:'',age:''},function(key,ele){})//key为对象的属性名
   ```

## 创建元素

var li = $("<li></li>");

## 添加元素

### 内部添加

| API                  | 说明               |
| -------------------- | ------------------ |
| $("div").append(li)  | 加入该元素子级末尾 |
| $("div").prepend(li) | 加入该元素子级开头 |

### 外部添加

| API                 | 说明             |
| ------------------- | ---------------- |
| $("div").after(li)  | 同一级该元素之后 |
| $("div").before(li) | 同一级该元素之前 |

## 删除元素

| API               | 说明                                              |
| ----------------- | ------------------------------------------------- |
| $("div").remove() | 删除自身                                          |
| $("div").empty()  | 删除所有孩子，不包括自身，相当于$("div").html("") |

## 替换元素

| API                           | 说明                      |
| ----------------------------- | ------------------------- |
| $('old').replaceWith（'new'） | 替换指定元素为,旧的去调用 |
| new.replaceAll('old')         | 新的去调用                |

## 复制元素

| API                | 说明   |
| ------------------ | ------ |
| $('').clone(false) | 浅拷贝 |
| $('').clone(true)  | 深拷贝 |

区别：浅拷贝只复制元素不会复制元素的事件，深拷贝会复制元素的事件



# jQuery事件

1. 监听网页滚动

   $(window).scroll(function(){})

   获取滚动的距离

   ```javascript
   $('html,body').scrollTop()
   ```

## 绑定事件

### on

$("div").on(events,[selector],fn) 

1. events：事件名
2. selector：子选择器委派的触发对象（冒泡）
3. fn：事件函数

### 以对象的形式书写

1. function不同

   ```javascript
   on({
   
   mouseenter:function(){},
   
   click:function(){}
   
   })
   ```

2. function相同

   ```
   $('ul').on("click mouseleave",function(){})
   ```

==注意==：

1. on可以给动态创建的元素绑定事件，传统单个事件绑定做不到
2. 阻止事件冒泡：在子元素的回调函数中 return false，或者e.stopPropagation()

### one()

用one()绑定的事件只能 触发一次

### trigger()

自动触发事件

$("").click()

$("").trigger("clic k")

$("").triggerHandler("click")//不会触发元素的默认行为，比如表单的光标和边框变色

==注意==:

1. 如果要用trigger来触发a的默认行为，需要把a里面的文本用span包起来，然后监听span的点击事件，通过冒泡才能触发a的跳转，否则无法触发a的跳转

## 事件切换

| 方法                                   | 说明                                                         |
| -------------------------------------- | ------------------------------------------------------------ |
| $("").hover(function(){},function(){}) | 鼠标经过和鼠标离开分别触发不同的方法                         |
| $("").toggle(fn1,fn2...)               | 开关”进行切换，当鼠标单击时的切换：当鼠标第一次单击时，执行fn1的代码，当鼠标第二次单击时，执行fn2的代码，执行完了后进行循环 |
| $("").change(function(){})             | 表单发生改变时触发                                           |



## 事件委派

$("ul").on("click","li",function(){})

根据冒泡原理，将事件绑定在ul上触发的对象是li，function中的this指的是当前触发的li的DOM对象，$（this）.index()方法可以获得li的索引

## 解绑事件

| API                       | 说明         |
| ------------------------- | ------------ |
| $("ul").off()             | 解绑所有事件 |
| $("ul").off("event")      | 解绑对应事件 |
| $("ul").off("event","li") | 解除事件委托 |

## 事件对象

$("").on(events,[selector],function(e){})

==注意==:

1. 在jquery中$（e.targrt）.index()方法可以直接获得li的索引

| API                                | 说明         |
| ---------------------------------- | ------------ |
| e.preventDefault()或者return false | 阻止默认行为 |
| e.stopProgation()                  | 阻止冒泡     |
|                                    |              |

## 自定义事件

1. 事件必须通过on绑定

2. 事件必须通过trigger来触发

   ```javascript
   $('.son').on('myclick',function(){
   	log(1)
   })
   $('.son').trigger('myclick')
   ```

# jQuery效果

## 显示隐藏

1. show([speed,[easing],[fn]])
   1. 参数省略，为无动画直接显示
   2. speed有slow，normal，fast或者毫秒数
   3. easing：用来指定切换效果，默认swing，可用参数linear
   4. fn：回调函数，在动画完成时执行，每个元素执行一次
2. hide()
3. toggle() //切换

```javascript
        $(function () {
            $("button:first").click(function () {
                $("div").show("slow");
            });
            $("button").eq(1).click(function () {
                console.log(1);
                $("div").hide(100, fn);
            });
            function fn() {
                console.log(2);
            }
            $("button:last").click(function () {
                $("div").toggle(1000);
            })
        })
```

## 滑动

1. slideDown()
2. slideUp()
3. slideToggle()

```javascript
        $(function () {
            $("button:first").click(function () {
                $("div").slideDown();
            })
            $("button").eq(1).click(function () {
                $("div").slideUp();
            })
        })
```

## 淡入淡出

1. fadeIn()
2. fadeOut()
3. fadeToggle()
4. fadeTo() //opacity透明度

```javascript
        $("button:first").click(function(){
            $("div").fadeIn();
        })
        $("button").eq(1).click(function(){
            $("div").fadeOut();
        })
        $("button:last").click(function(){
            $("div").fadeTo(20,0.3);
        })
        $("button").eq(2).click(function(){
            $("div").fadeToggle(0.3);
        })
    </script>
```

## 自定义动画

animate(params,[speed],[easing],[fn]（回调函数））

1. params:想要更改的样式属性，以对象的形式传递，必须写。如果是复合属性要驼峰命名

   ==注意==：

   1. 如果要在原先的样式基础上累加，需要使用累加属性，属性是一个字符串

      left：“+=100”

   2. 还可以给属性一个关键字：hide,toggle

      width：“hide”

2. 指定动画时长

3. 指定动画的贝塞尔曲线

4. 回调函数

```javascript
$(function () {
    $("button").click(function () {
        $("div").animate({
            left: 200,
            top:200,
            opacity:.4
        })
    })
})
```

==注意==:

1. 同样支持链式编程

## 动画队列及停止排队

- stop()用于停止动画效果，停止上一次的动画
- 参数为true：停止当前的和后续的所有动画
- 参数为false：停止当前的立即执行后续的，用于链式编程动画的停止

$("").siblings().stop().fadeTo()

```javascript

        $('.first>li').hover(function () {
            $(this).children('ul').stop().slideToggle(1000)
        })
```

![](D:\桌面\notes\jQuery\assest\stop(参数).png)

- delay(speed)可以在动画之间设置延迟

  ```javascript
   $("div").animate({
              left: 200,
              top:200,
              opacity:.4
          }).delay(2000).animate({
          	......
          })
  ```

==注意==：

1. 在动画前停止，所以在动画前调用stop()
2. 因为有动画队列，所以动画可以链式编程，后面的会等前面的执行完成之后再执行，可以不在回调函数中写

# jQuery其他方法

## 对象拷贝

$.extend([deep],target,object1,[objectN])

1. deep：true深拷贝，false浅拷贝（默认）
2. object1拷贝给target
3. objectN：拷贝多个给target

## 多库共存

1. 把$改为jQuery
2. 自己改名：var zidingyi = jQuery.noConflict()

## $.ajax()方法

![](D:\桌面\notes\jQuery\assest\ajax.png)

1. type是get或者post，data可以是对象或者连接好的字符串
2. type是post，且contenttype是application/json，需要将data中的json对象转为json字符串
3. beforeSend，在请求被发送之前调用，如果return false，则请求不会被发送
4. success函数会自动将json字符串转化为json对象
5. 在协议端口一样的情况下可以简写

```javascript
 $('#btn').on('click',function () {
                $.ajax({
                    type:'get',
                    url:'/shisan',
                    success:function (response) {
                        console.log(JSON.parse(response))
                    }
                })
            })
```

==注意==：

1. 方法内部会自动将参数转为？xx=xxx&xx=xxx的格式
2. 如果要使用application/json格式的参数，需要在data中先一步用JSON.stringify()将对象转为字符串

```javascript
                $.ajax({
                    type:'post',
                    url:'/shisan',
                    data:JSON.stringify({ //json对象转字符串
                        name:'zs',
                        age:100
                    }),
                    contentType:'application/json', //修改参数类型
                    success:function (response) {
                        console.log(response)
                    },
                    error:function (err){
                        console.log(err)
                    }
                })
```

### serialize方法

formdata对象是h5中提供的内置对象，serialize方法兼容性更好

1. 将表单中的数据自动拼接成字符串类型的参数

```javascript
        $('#form').on('submit',function ( ) {
            //将表单内容拼接成字符串类型的参数
            let params = $('#form').serialize()
            return false
        })
```

​	2.将表单中的值转为对象

```javascript
//将表单中的值转为对象
function serializeObj(obj) {//传入form对象
    let arr = obj.serializeArray(),result={}
    $.each(arr,function (index,value) {
        result[value.name]=value.value
    })
    return result
}
```

### 发送jsonp请求

![](D:\桌面\notes\ajax\assets\发送jsonp请求.png)

jsonp和jsonCallback在需要时才传入，在修改了callback参数名时，服务端不能再直接用jsonp（）方法返回数据，通过req.query.新的参数名获取函数然后调用

![](D:\桌面\notes\ajax\assets\服务端在修改了callback参数名后.png)

在修改了jsoncallback回调函数时，success失效，需要定义新的回调函数

![](D:\桌面\notes\ajax\assets\jsonpcallback回调函数.png)

## $.get()和$.post()

![](D:\桌面\notes\ajax\assets\$get和$post.png)

## ajax全局事件

```javascript
            //当页面中有ajax请求发送时触发
            $(document).on('ajaxStart', function () {

            })
            //请求完成时触发
            $(document).on('ajaxComplete', function () {

            })
```

## 获取宽高

![](D:\桌面\notes\jQuery\assest\获取宽高.png)