## 模板语法

### Vue的基本使用

1. 引入Vue.js库文件
2. 使用vue语法处理数据
3. 提供填充数据的标签
4. 把vue提供的数据填充到标签中

```html
    <div id="app">
        <div> {{msg}} </div><!-- 插值表达式 -->
    </div>
    <!-- 2.引入库文件 -->
    <script type="text/javascript" src="js/vue.js"> </script>
    <script>
        var vm = new Vue({
            el: '#app',//元素挂载位置（可以是css选择器或者DOM元素）
            data: {//模型数据（值是一个对象）
                msg: 'Hello Vue'
            }
        });
    </script>
```

### 差值表达式

{{}}

### 指令

- 本质是自定义属性
- 格式：v-开始

#### v-cloak

- 作用：解决插值表达式存在闪动问题

- 用法：

  1. 提供css样式

     [v-cloak]{diaplay=none}//属性选择器

  2. 在插值表达式所在的标签中添加v-cloak指令

- 原理：先通过样式隐藏内容，然后再内存中进行值的替换，替换好之后再显示最终的结果

#### 数据绑定

##### 数据响应式

- 概念：数据的变化导致页面内容的变化，vue会监听属性的变化

##### 数据绑定

- 将标签的内容与数据绑定

- 将数据填充到标签中

##### v-once

- 作用：编译一次，显示内容之后不再具有响应式功能
- 应用场景：如果显示的信息后续不需要再修改，可以提高性能

##### v-text

- 作用：填充纯文本
- 区别：没有闪动问题

##### v-html

- 作用：填充HTML片段，能解析html标签
- 区别：存在安全问题，所以只能使用本网站的数据

##### v-pre

- 作用：填充原始信息
- 区别：能跳过编译过程

```html
<body>
    <div id="app">
        <div v-once></div>
        <div v-text="msg"></div>
        <div v-html="msg1"></div>
        <div v-pre>{{msg}}</div>
    </div>
    <script src="js/vue.js"></script>
    <script>
        var vm = new Vue({
            el: '#app',
            data: {
                msg: 'Hello',
                msg1:'<h1>HTML</h1>'
            }
        })
    </script>
</body>
```

##### 双向数据绑定

- MVVM设计思想（model数据-view模板视图-View-Model控制逻辑（Vue））
  - DOM Listener影响数据（事件监听）
  - Data Bindings影响视图（数据绑定）

- v-model
  - 表单的变化引起数据的变化，视图中与之相关联的数据会重新渲染

```html
<body>
    <div id="app">
        <div>{{msg}}</div>
        <div>
            <input type="text" v-model="msg">
        </div>
    </div>
    <script src="../js/vue.js"></script>
    <script>
        var vm = new Vue({
            el: '#app',
            data: {
                msg: 'Hello'
            }
        })
    </script>
</body>
```

- v-model本质原理

  ```html
  <body>
      <div id="app">
          <!-- 一个属性绑定把data对象的数据显示在页面上，一个事件函数把修改的值覆盖data对象中的原数据 -->
          <input type="text" :value="msg" @input='handle'>
          或者
          <input type="text" :value="msg" @input='msg=$event.target.value'>
          <span v-text='msg'></span>
      </div>
      <script src="../js/vue.js"></script>
      <script>
          var vm = new Vue({
              el: '#app',
              data: {
                  msg: 'hello',
              },
              methods: {
                  handle: function (event) {
                      this.msg = event.target.value;
                  }
              },
          })
      </script>
  </body>
  ```

  

#### 事件绑定

##### v-on:||@

```html
<body>
    <div id="app">
        <div>{{num}}</div>
        <button @click='handle()'>点击</button>
    </div>
    <script src="../js/vue.js"></script>
    <script>
        var vm = new Vue({
            el: '#app',
            data: {
                num: 0
            },
            methods: {
                handle: function () {
                    this.num++;//this指vm指的是vue的实例
                }
            }
        })
    </script>
</body>
```

##### 事件函数参数绑定

1. 如果事件直接绑定函数名称不传参，那么默认会传递事件对象做为事件函数的第一个参数

2. 如果事件绑定函数传参，那么事件函数作为最后一个参数，以$event形式进行显示传递

   ```html
   <body>
       <div id="app">
           <div>{{num}}</div>
           <button @click='handle(123,456,$event)'>点击1</button>
           <button @click='handle2'>点击2</button>
       </div>
       <script src="../js/vue.js"></script>
       <script>
           var vm = new Vue({
               el: '#app',
               data: {
                   num: 0
               },
               methods: {
                   handle: function (p1, p2, event) {
                       this.num++; //this指vm指的是vue的实例
                       console.log(p1, p2);
                       console.log(event.target.innerHTML);     
                   },
                   handle2: function (event) {
                       console.log(event.target.innerHTML);
                   }
               }
           })
       </script>
   </body>
   ```

##### 事件修饰符

- 阻止冒泡

  @click.stop='函数名'

- 组织默认行为

  @click.prevent='函数名'
  
  注意：阻止a标签的默认行为：@click.prevent不用添加函数direv

##### 按键修饰符

- enter触发

  @keyup.enter='函数名'

- delete触发

  @keyup.delete='函数名'

- 自定义按键触发

  Vue.config.keyCodes.a=65;

#### 属性绑定

将==标签的属性==和数据绑定

- v-bind:属性名||:属性名

  ```html
  <body>
      <div id="app">
          <a v-bind:href="url">百度</a>
          <button @click='handle'>切换</button>
      </div>
      <script src="../js/vue.js"></script>
      <script>
          var vm = new Vue({
              el: '#app',
              data: {
                  url: 'http://www.baidu.com',
              },
              methods: {
                  handle: function () {
                      //修改url地址
                      this.url = 'http://itcast.cn';
                  }
              },
          })
      </script>
  </body>
  ```

#### 样式绑定

##### class样式处理

- 对象语法

  css的class属性名：属性值（data对象中的属性名）值为true或false

  ```html
  <body>
      <div id="app">
          <div v-bind:class="{active: isActive,error:isError}">测试</div>
          <button @click='handle'>切换</button>
      </div>
      <script src="../js/vue.js"></script>
      <script>
          var vm = new Vue({
              el: '#app',
              data: {
                  isActive: true,
                  isError: true,
              },
              methods: {
                  handle: function () {
                      //控制active
                      this.isActive = !this.isActive;
                      this.isError = !this.isError;
                  }
              },
          })
      </script>
  </body>
  ```

- 数组语法

  data对象中的属性名     属性值为css的class属性名

  ```html
  <body>
      <div id="app">
          <div v-bind:class='[activeClass,errorClass]'></div>
          <button :click='handle'>切换</button>
      </div>
      <script src="../js/vue.js"></script>
      <script>
          var vm = new Vue({
              el: '#app',
              data: {
                  activeClass: 'active',
                  errorClass: 'error'
              },
              methods: {
                  handle: function () {
                      this.activeClass = '';
                      this.errorClass = '';
                  }
              },
          })
      </script>
  </body>
  ```

- 对象和数据语法结合与简化

  提高可读性

  ==注意==：默认的class会保留

  ```html
  <body>
      <div id="app">
          <div v-bind:class='[arrClasses,{test:isTest}]'>数组和对象的结合</div>//结合使用
          <div :class='objClasses'></div>//使用对象
          <button @click='handle'>切换</button>
      </div>
      <script src="../js/vue.js"></script>
      <script>
          var vm = new Vue({
              el: '#app',
              data: {
                  isTest: true,
                  arrClasses: ['active', 'error'],//简化数组
                  objClasses: {//简化对象
                      active: true,
                      error: true,
                  }
              },
              methods: {
                  handle: function () {
                      this.arrClasses.pop();
                      this.objClasses.error = false;
                      this.isTest = !this.isTest;
                  }
              },
          })
      </script>
  </body>
  ```

##### style样式处理

- ​	对象语法

  ```html
  <body>
      <div id="app">
          <div v-bind:style='{border:borderStyle,width:widthStyle,height:heightStyle}'></div>
          <div v-bind:style='objStyles'></div>
          <button @click='handle'>切换</button>
      </div>
      <script src="../js/vue.js"></script>
      <script>
          var vm = new Vue({
              el: '#app',
              data: {
                  borderStyle: '1px solid red',
                  widthStyle: '100px',
                  heightStyle: '200px',
                  objStyles: {						//简化形式对象1
                      border: '1px solid green',
                      width: '200px',
                      height: '100px'
                  },
                  overrideStyles: {					//对象2
                      border: '5px solid orange',
                      backgroundColor: 'blue',
                  }
              },
              methods: {
                  handle: function () {
                      this.heightStyle = '100px';
                      this.objStyles.width = '100px';
                  }
              },
          })
      </script>
  </body>
  ```

- 数组语法

  ​	数组元素是多个对象，覆盖关系

  ```html
   <div v-bind:style='[objStyles,overrideStyles]'></div>
  ```

#### 分支循环结构

##### 分支结构

- v-if

- v-else

- v-else-if

- v-show

  原理：控制display是none还是block

- ==注意==：v-if控制元素是否渲染到页面（dom元素的增加或删除）

  ​			v-show控制元素是否显示（已经渲染到了页面，只是样式的显示与否）

  ```html
  <body>
      <div id="app">
          <div v-if='score>=90'>优秀</div>
          <div v-else-if='score<90&&score>=80'>良好</div>
          <div v-else-if='score<80&&score>=60'>一般</div>
          <div v-else>比较差</div>
  
          <div v-show='flag'>测试v-show</div>
          <button @click='handle'>点击显示</button>
      </div>
      <script src="../js/vue.js"></script>
      <script>
          var vm = new Vue({
              el: '#app',
              data: {
                  score: 99,
                  flag: false
              },
              methods: {
                  handle: function () {
                      this.flag = !this.flag;
                  }
              },
          })
      </script>
  </body>
  ```

##### 循环结构

- v-for遍历数组

  - 遍历数组元素

    <li v-for='item in fruits'>{{item}}</li>

  - 遍历元素和索引

    <li v-for='（item,index）in fruits'>{{item + '-----' + index}}</li>

```html
<body>
    <div id="app">
<div>水果列表</div>
<ul>
    <li v-for='item in fruits'>{{item}}</li>
    <li v-for='(item,index) in fruits'>{{item+'------'+index}}</li>
    <li v-for='(item,index) in myfruits'>
        <span>{{item.cname+'------'+index}}</span>
        <span>{{item.ename+'------'+index}}</span>
    </li>
</ul>
    </div>
    <script src="../js/vue.js"></script>
    <script>
        var vm = new Vue({
            el: '#app',
            data: {
                fruits: ['apple', 'orange', 'banana'],
                myfruits:[{
                    ename:'apple',
                    cname:'苹果'
                },
                {
                    ename:'orange',
                    cname:'橘子'
                },
                {
                    ename:'banana',
                    cname:'香蕉'
                },]
            },
            methods: {

            },
        })
    </script>
</body>
```

- key的作用

  帮助vue区分不同元素，可以提高性能

  ```html
  <li :key='item.id' v-for='item in fruits'>{{item}}</li>//没有提供id，则用key=‘index’，唯一的就可以
  ```

- v-for遍历对象

  ```html
  <div v-for='(value,key,index) in obj'>{{key + '-----' + value + '-----' + index}}</div>
  ```

- v-if和v-for结合使用

  ```html
  <div v-if='obj["age"] > 10 ' v-for='(value,key,index) in obj'>{{key + '-----' + value + '-----' + index}}</div>
  ```


## Vue常用特性

### 表单操作

#### 基于Vue的表单操作

- input

  双向数据绑定

- textarea

  双向数据绑定

- select

  给option value值，select双向数据绑定

- radio

  给表单value值，双向数据绑定

- checkbox

  给表单value值，双向数据绑定

- 注意：提交按钮submit取消默认行为，增加点击事件用ajax传递数据

  ```html
  <body>
      <div id="app">
          <form action="http://itcast.cn">
              <div>
                  <label for="name">姓名：</label>
                  <input type="text" id="name" v-model='uname'>
              </div>
  
              <div>
                  <span>性别：</span>
                  <label for="man" >男</label>
                  <input type="radio" id="man" value="1" v-model='sex'>
                  <label for="woman" > 女</label>
                  <input type="radio" id="woman" value="2" v-model='sex'>
              </div>
  
              <div>
                  <span>爱好：</span>
                  <label for="basketball">篮球</label>
                  <input type="checkbox" id="basketball" value="1" v-model='hobbies'>
                  <label for="sing">唱歌</label>
                  <input type="checkbox" id="sing" value="2" v-model='hobbies'>
                  <label for="code">写代码</label>
                  <input type="checkbox" id="code" value="3" v-model='hobbies'>
              </div>
              <div>
                  <span>职业：</span>
                  <select name="" id="" v-model='occupation' multiple>
                      <option value="0">请选择职业...</option>
                      <option value="1">web前端</option>
                      <option value="2">java后端</option>
                  </select>
              </div>
              <div>
                  <label for="introduction">个人简介：</label>
                  <textarea name="" id="" cols="30" rows="3" v-model='description'></textarea>
              </div>
              <div>
                  <input type="submit" @click.prevent='handle'>
              </div>
          </form>
      </div>
      <script src="../js/vue.js"></script>
      <script>
          var vm = new Vue({
              el: '#app',
              data: {
                  uname: 'xqz',
                  sex:1,
                  hobbies:[1,2],
                  occupation:[1,2],
                  description:'你好'
              },methods: {
                  handle:function(){
                      console.log(this.uname);
                      console.log(this.sex);
                      console.log(this.hobbies.toString());
                      console.log(this.occupation.toString());
                      console.log(this.description);
                      
                      //Ajax
                  }
              },
          })
      </script>
  </body>
  ```

#### 表单域修饰符

- v-model.number

  转为数值

- trim

  去掉开始和结尾的空格,不会去掉中间的

- lazy

  把双向绑定中的input事件切换为change事件，input是在输入时一直触发，change是在失去焦点时才更新数据

```html
<body>
    <div id="app">
        <input type="text" v-model.number='age'>
        <input type="text" v-model.trim='info'>
        <input type="text" v-model.lazy='msg'>
        <div>{{msg}}</div>
        <button @click='handle'>点击</button>
    </div>
    <script src="../js/vue.js"></script>
    <script>
        var vm = new Vue({
            el: '#app',
            data: {
                age: '',
                info:'',
                msg:''
            },
            methods: {
                handle: function () {
                    console.log(this.age + 1);
                    console.log(this.info.length);
                }
            },
        })
    </script>
</body>
```

### 自定义指令

#### 基本使用

Vue.directive('指令的名字',{

钩子函数

})

```html
<body>
    <div id="app">
        <input type="text">
        <input type="text" v-focus>
    </div>
    <script src="../js/vue.js"></script>
    <script>
        Vue.directive('focus', {
            inserted: function (el) {
                //el表示指令所绑定的元素
                el.focus();
            }
        })
        var vm = new Vue({
            el: '#app',
            data: {

            },
            methods: {
                handle: function () {

                }
            },
        })
    </script>
</body>
```

==注意==:focus()函数只在inserted中生效，而在bind中不生效

- `bind` ：指令第一次绑定到元素上时调用
- `inserted`：表示元素在插入到DOM中的时候，会执行inserted函数，只执行一次
- `update` ：VNode更新的时候调用，可能会调用多次

页面上的任何一个元素想要显示，首先需要浏览器的渲染引擎将元素加载到内存中形成DOM树，也就是说执行bind函数的时候，元素还没有插入到内存中去，因为，一个元素只有插入DOM之后，才会获得焦点。所以说，在bind函数中执行el.focus()焦点事件的时机是不对的；同理可得，凡是与js样式有关的需在bind函数中执行`（如：el.style.color = 'blue'）`，而与js行为有关的，需在inserted函数中执行

#### 带参数的自定义指令

binding获取指令的参数值

```html
<body>
    <div id="app">
        <input type="text" v-color='msg'>
    </div>
    <script src="../js/vue.js"></script>
    <script>
        Vue.directive('color',{
            bind:function (el,binding) {
                //根据指令的参数修改背景色
                el.style.backgroundColor = binding.value.color;
                console.log(binding.value.color);
              }
        });
        var vm=new Vue({
            el:'#app',
            data:{
                msg:{
                    color:'orange'
                }
            }
        })
    </script>
</body>
```

#### 局部指令

- 在Vue的实例中添加额外的属性directive

- 只能在本组件中使用

```html
<body>
    <div id="app">
        <input type="text" v-color='msg' v-focus>
    </div>
    <script src="../js/vue.js"></script>
    <script>
        var vm = new Vue({
            el: '#app',
            data: {
                msg: {
                    color: 'blue'
                }
            },
            methods: {
                handle: function () {
                }
            },
     
            directives: {
                color: {
                    bind: function (el, binding) {
                        el.style.backgroundColor = binding.value.color;
                    }
                },
                focus: {
                    inserted: function (el) {
                        el.focus();
                    }
                }
            }
        })
    </script>
</body>
```

### 计算属性

- 表达式的计算逻辑可能会比较复杂，使用计算属性可以使模板内容更加简洁

- 在Vue实例中添加computed属性，直接在插值表达式中调用函数名
- ==注意==：计算属性的数据是基于data的，data变化会引起计算属性的变化

```html
 computed: {
                reserveString:function(){
                    return this.msg.split('').reverse().join('');
                }
            },
```

- ==计算属性和方法的区别==
  - 计算属性是基于他们的依赖进行缓存的，如果依赖不变则使用的是缓存的结果，依赖变化才重新计算
  - 方法不存在缓存

### 过滤器

- 作用：格式化数据，比如将字符串格式化为首字母大写，将日期格式化为指定格式

- 自定义过滤器：

  ```javascript
  Vue.filter{
  "过滤器名称"，function(value){
  //业务逻辑
  	}
  }
  ```

- 过滤器使用

  - 全局和局部，级联使用

  ```html
  <body>
      <div id="app">
          <input type="text" v-model='msg'>
          <div>{{msg | upper}}</div>
          <div>{{msg | upper | lower}}</div>
          <div :abc='msg | upper'>测试数据</div>
      </div>
      <script src="../js/vue.js"></script>
      <script>
          // Vue.filter('upper', function (val) {
          //     return val.charAt(0).toUpperCase() + val.slice(1);
          // });
          Vue.filter('lower', function (val) {
              return val.charAt(0).toLowerCase() + val.slice(1);
          })
          var vm = new Vue({
              el: '#app',
              data: {
                  msg: '',
              },
              // 局部过滤器
              filters: {
                  upper: function (val) {
                      return val.charAt(0).toUpperCase() + val.slice(1);
                  }
              }
          })
      </script>
  </body>
  ```

- 带参数的过滤器

  ```html
  <body>
      <div id="app">
          <div>{{date | format('yyyy-MM-dd')}}</div>
      </div>
      <script src="../js/vue.js"></script>
      <script>
          Vue.filter('format', function (value, arg) {
              if (arg == 'yyyy-MM-dd') {
                  var ret = '';
                  ret += value.getFullYear() + '-' + value.getMonth() + '-' + value.getDate();
                  return ret;
              }         
          })
          var vm = new Vue({
              el: '#app',
              data: {
                  date: new Date(),
              },
          })
      </script>
  </body>
  ```

### 侦听器

- 应用场景：数据变化时执行异步或开销较大的操作

- 数据一旦发生变化就通知侦听器所绑定的方法

- 用法：

  ```javascript
   watch: {		//函数名和属性名一致，这样才知道监听的哪个属性
                  firstName: function (val) { //val表示的是当前数据的最新值
                      this.fullName = val + '' + this.lastName;
                  },
                  lastName: function (val) {
                      this.fullName = this.firstName + '' + val;
                  }
              },
  ```

### 生命周期

- 挂载（初始化相关属性）

  - beforeCreate：在实例初始化后，数据观测和事件配置之前被调用

  - created：在实例创建完成后立即被调用

  - beforeMount：在挂载开始之前被调用

  - mounted：el被新创建的vm.$el替换，并挂载到实例上去之后调用该钩子

    注意：当这个函数调用代表初始化完成，页面中模板内容存在，可以填充数据

- 更新（元素或组件的变更操作）
  
  - beforeUpdate：数据更新时调用，发生在虚拟DOM打补丁之前
  - ubdated：由于数据更改导致的虚拟DOM重新渲染和打补丁，在这之后会调用该钩子
  
- 销毁（销毁相关属性）

  - beforeDestroy：实例销毁之前调用
  - destroyed：实例销毁之后调用

### 数组相关API

#### 变异方法（修改原有数组）

作用：使得数组数据也具有响应式的特性

- push()
- pop()
- shift()
- unshift()
- splice()
- sort()
- reverse()

#### 替换数组（生成新的数组）

==注意==：需要赋值给原始的数组

- filter()
- concat()
- slice()

#### 数组索引 || 对象属性

直接使用数组索引的方法没有响应式的特性，所以Vue提供以下Api

Vue.set(vm.items,indexOfitem,newValue) || vm.$set(vm.items,indexOfitem,newValue)

1. 参数一表示要处理的数组名称
2. 参数二表示要处理的数字索引
3. 参数三表示要处理的数组的值

```html
<body>
    <div id="app">
        <div>
            <span>
                <input type="text" v-model='fname'>
                <button @click='add'>添加</button>
                <button @click='del'>删除</button>
                <button @click='change'>替换</button>
            </span>
        </div>
        <ul>
            <li :key='index' v-for='(item,index) in list'>{{item}}</li>
        </ul>
        <div>{{info.name}}</div>
        <div>{{info.age}}</div>
        <div>{{info.gender}}</div>
    </div>
    <script src="../../js/vue.js"></script>
    <script>
        var vm = new Vue({
            el: '#app',
            data: {
                fname: '',
                list: ['apple', 'orange', 'banana'],
                info: {
                    name: 'lisi',
                    age: 12
                }
            },
            //数组api
            methods: {
                add: function () {
                    this.list.push(this.fname);
                },
                del: function () {
                    this.list.pop();
                },
                change: function () {
                    this.list = this.list.slice(0, 2);
                }
            },
        })
        //数组索引
        Vue.set(vm.list, 1, 'lemon');
        vm.$set(vm.list, 2, 'lemon2')

        //对象属性
        //vm.info.gender='male';//只能显示，不能获取修改的
        vm.$set(vm.info, 'gender', 'female');
    </script>
</body>
```

## 组件化开发

### 组件化开发思想

Web Components通过创建封装好功能的定制元素解决组件化规范问题

### 提供的组件

- component

  根据绑定的is属性来显示组件

  ```html
  <component :is="'keji'"></component>//显示自定义的keji组件
  ```

### 组件注册

- 全局组件

```javascript
Vue.component('button-counter',{
            data:function(){
                return{
                    count:0
                }
            },
            template:'<button @click="handle">点击了{{count}}次</button>',
            methods: {
                handle:function(){
                    this.count++;
                }
            },
        })
```

- 局部组件：只能在父组件中使用

```javascript
<div id="app">
        <hello-world></hello-world>
        <hello-jerry></hello-jerry>
        <hello-tom></hello-tom>
</div>
var HelloWorld = {
            data: function () {
                return {
                    msg: 'HelloWorld'
                }
            },
            template: '<div>{{msg}}</div>'
        }
         var vm = new Vue({
            el: '#app',
            data: {},
            //局部组件
            components: {
                'hello-world': HelloWorld,
                'hello-tom': HelloTom,
                'hello-jerry': HelloJerry
            }
        })
```

==注意==：

1. data是函数不是对象，函数可以形成一个闭包环境使得每一个组件都有独立的数据
2. 组件模板必须是单个根元素，不能有兄弟关系
3. 组件模板内容可以是模板字符串
4. 组件命名方式可以是-或者驼峰命名，驼峰命名只能用在模板字符串的其他组件中，但是在普通标签模板中必须使用-的方式。

### Vue调试工具：vue-devtools

### 组件间的数据交互

#### 父组件传子组件

- 父组件传值

  ```html
  <menu-item title="来自父组件的值">{{msg}}</menu-item>//静态方式
  <menu-item :title="ptitle" content='hello'>{{msg}}</menu-item>//动态绑定属性值，属性值写在父组件的data中
  ```

- 子组件接受值

  ```javascript
  Vue.component('menu-item', {
          props: ['title','content'],//名称和父组件中一致,如果接受的是驼峰形式，在使用时改为-，除非是在字符串模板中
          data: function () {
              return {
                  msg: '子组件本身的数据'
              }
          },
          template: '<div>{{msg + "-------"+ title + "------"+ content}}</div>'
      })
  ```

#### props属性值类型

- String

- Number：用v-bind绑定可以在子组件中获得对应类型的数据，如果不绑定则是string类型

- Boolean：用v-bind绑定可以在子组件中获得对应类型的数据，如果不绑定则是string类型

- Array

- Object

  ```html
  <body>
      <div id="app">
          <div>{{pmsg}}</div>
          <!-- pnum中有：是number类型，没有的话是string类型 ,pboo同理-->
          <menu-item :pstr='pstr' :pnum='12' :pboo='true' :parr='parr' :pobj='pobj'></menu-item>
      </div>
      <script src="../js/vue.js"></script>
      <script>
          Vue.component('menu-item', {
              props: ['pstr','pnum','pboo','parr','pobj'],
              template: `<div>
              <div>{{pstr}}</div>
              <div>{{12 + pnum}}</div>
              <div>{{pboo}}</div>
              <ul>
              <li v-for='(item,index) in parr'>{{item}}</li>
              </ul>
              <div>
              <span>{{pobj.name}}</span>
              <span>{{pobj.age}}</span>
              </div>
              </div>`
          })
          var vm = new Vue({
              el: '#app',
              data: {
                  pmsg: '父组件中的内容',
                  pstr: 'hello',
                  parr:['apple','orange','banana'],
                  pobj:{
                      name:'lisi',
                      age:'12'
                  }
              }
          })
      </script>
  </body>
  ```

#### 子组件传父组件

- 直接操作父组件传来的数据，但是prop传递数据原则是单项数据流，所以不推荐这么做

正确方法：

1. 通过自定义事件向父组件传值

    <button @click='$emit("changecontent")'>改变父组件中的值</button>//$emit(“自定义事件名”)

2. 父组件监听子组件的事件

    <menu-item :pmsg='pmsg' @changecontent='handle' @changefont='handle2'></menu-item>//对子组件传来的事件进行处理

   - 监听不传值的事件

     ```html
     <body>
         <div id="app">
             <div :style='{fontSize:fontSize + "px"}'>{{pmsg}}</div>
             <menu-item :pmsg='pmsg' @changecontent='handle'//父组件处理
                        @changefont='handle2'></menu-item>
         </div>
         <script src="../js/vue.js"></script>
         <script>
             Vue.component('menu-item', {
                 props: ['pmsg'],
                 template: `
                 <div>
                 <div>{{pmsg}}</div>
     			//子组件定义事件
                 <button @click='$emit("changecontent")'>改变父组件中的值</button>
                 <button @click='$emit("changefont")'>改变父组件字体大小</button>
                 </div>
                 `
             })
             var vm = new Vue({
                 el: '#app',
                 data: {
                     pmsg: '父组件中的内容',
                     fontSize: 10
                 },
                 methods: {
                     handle: function () {
                         //改变父组件的值
                         this.pmsg = this.pmsg + "1";
                     },
                     handle2: function () {
                         //改变字体大小
                         this.fontSize += 5;
                     }
                 },
             })
         </script>
     </body>
     ```

- 监听传值的事件

  1. 在$emit(“”，参数)带上参数
  2. 在父组件的自定义监听事件中通过$event获得参数

  ```html
  <body>
      <div id="app">
          <div :style='{fontSize:fontSize + "px"}'>{{pmsg}}</div>
          <menu-item :pmsg='pmsg' @changefont='handle2($event)'></menu-item>
      </div>
      <script src="../js/vue.js"></script>
      <script>
          Vue.component('menu-item', {
              props: ['pmsg'],
              template: `
              <div>
              <div>{{pmsg}}</div>
              <button @click='$emit("changefont",5)'>改变父组件字体大小</button>
              </div>
              `
          })
          var vm = new Vue({
              el: '#app',
              data: {
                  pmsg: '父组件中的内容',
                  fontSize: 10
              },
              methods: {
                  handle2: function (val) {
                      //改变字体大小
                      this.fontSize += val;
                  }
              },
          })
      </script>
  </body>
  ```

#### 兄弟组件

1. 原理：通过事件中心管理组件中的通信

2. 事件中心：var eventHub =  new  Vue()

3. 监听事件：eventHub.$on('事件名称',addTodo)

   销毁事件：eventHub.$off('事件名称')

4. 触发事件：eventHub.$emit('事件名称',id) //事件名称与监听的一致

5. 销毁事件：hub.$off('事件名') 

   ==步骤==：

   1. 兄弟组件按钮绑定点击事件
   2. 创建事件池
   3. 在组件中给事件池中绑定事件，每一个事件的名字都不一样
   4. 在点击事件中触发事件，也就是散发事件，到事件池中去触发一样的事件名的事件

```html
<body>
    <div id="app">
        <div>父组件</div>
        <div>
            <button @click='handle'> 销毁事件</button>
        </div>
        <text-tom></text-tom>
        <text-jerry></text-jerry>
    </div>
    <script src="../js/vue.js"></script>
    <script>
        //提供事件中心
        var hub = new Vue();
        Vue.component('text-tom', {
            data: function () {
                return {
                    num: 0
                }
            },
            template: `
            <div>
            <div>Tom:{{num}}</div>
            <button @click='handle'>给兄弟组件+2</button>
            </div>
            `,
            methods: {
                handle: function () {
                    //触发jerry事件
                    hub.$emit('jerry-event', 2)
                }
            },
            mounted: function () {
                //监听事件
                hub.$on('tom-event', (val) => {
                    this.num += val;
                })
            },
        });
        Vue.component('text-jerry', {
            data: function () {
                return {
                    num: 0
                }
            },
            template: `
            <div>
            <div>Jerry:{{num}}</div>
            <button @click='handle'>给兄弟组件+1</button>
            </div>
            `,
            methods: {
                handle: function () {
                    hub.$emit('tom-event', 1)
                }
            },
            mounted: function (val) {
                hub.$on('jerry-event', (val) => {
                    this.num += val;
                })
            },
        })
        var vm = new Vue({
            el: '#app',
            data: {

            },
            methods: {
                handle: function () {
                    hub.$off('tom-event');
                    hub.$off('jerry-event');
                }
            }
        })
    </script>
</body>
```

### 组件插槽

#### 基本使用

作用：父组件向子组件传递模板内容

<menu-item>content</menu-item>

==注意==：子组件会预留一个位置，就是所谓的插槽<slot></slot>来存放父组件在使用子组件时标签中的内容，插槽内容会随着content的改变而改变，如果content为空，则显示slot标签中的默认内容，有了就会覆盖默认内容

```html
<body>
    <div id="app">
        <test-jerry>有bug</test-jerry>
        <test-jerry>有一个bug发生</test-jerry>
    </div>
    <script src="../js/vue.js"></script>
    <script>
        Vue.component('test-jerry', {
            template: `
            <div>
            <span>ERROR:</span>
            <slot>默认内容</slot>
            </div>
            `
        })
        var vm = new Vue({
            el: '#app',
            data: {
            }
        })
    </script>
</body>
```

#### 具名插槽

步骤：

1. 在模板字符串中给slot标签name值
2. 在父组件中使用时，给标签slot=“name”从而给对应的插槽赋值

```html
<body>
    <div id="app">
        <base-layout>
            <p slot="header">header赋值</p>
            主要内容
            <p slot="body">header赋值</p>
        </base-layout>
    </div>
    <script src="../js/vue.js"></script>
    <script>
        Vue.component('base-layout', {
            template: `
            <div>
            <slot name="header"></slot>
            <slot name="body"></slot>
            <slot></slot>
            </div>
            `
        })
        var vm = new Vue({
            el: '#app',
            data: {}
        })
    </script>
</body>
```

- 渲染多条插槽赋值时

  ```html
   <base-layout>
              <template slot="header">
                  <p>header赋值1</p>
                  <p>header赋值2</p>
              </template>
              <template slot="body">
                  <p>body赋值1</p>
                  <p>body赋值2</p>
              </template>
    </base-layout>
  ```

#### 作用域插槽

应用场景：父组件对子组件的内容进行加工处理

步骤：

1. 子组件中把插槽中的值作为属性传给父组件，当然子组件的数据也可以来自父组件
2. 父组件通过 slot-scope=‘自定义name'，name.子组件中绑定的属性，来获得子组件传来的值，这个值就是子组件中绑定的属性对应的值，==注意==要在<template>标签中进行操作
3. 对传来的数据进行操作，从而影响子组件slot标签中的样式

```html
<body>
    <div id="app">
        <fruit-list :list='list'>
            <!-- 获取子组件插槽传来的值 -->
            <template slot-scope='slotProps'>
                <!-- 通过slotProp.属性名获得值 -->
                <strong :style="{color:slotProps.info.id==2 ? fontcolor:''}">{{slotProps.info.name}}</strong>
            </template>

        </fruit-list>
    </div>
    <script src="../js/vue.js"></script>
    <script>
        Vue.component('fruit-list', {
            props: ['list'],
            template: `
            <div>
            <li :key='item.id' v-for='(item,index) in list'>
                <slot :info='item'>{{item.name}}</slot>              //把插槽中的值作为属性传给父组件
            </li>
            </div>
            `
        })
        var vm = new Vue({
            el: '#app',
            data: {
                fontcolor: 'orange',
                list: [{
                        id: 1,
                        name: 'apple',
                    },
                    {
                        id: 2,
                        name: 'orange',
                    }, {
                        id: 3,
                        name: 'banana',
                    }
                ]
            }
        })
    </script>
</body>
```

## Vue前后端交互

### 前后端交互模式

#### 传统形式的URL

- 格式：schema://host:port/path?query#fragment
  1. schema:协议，例如http,https,ftp等
  2. host:域名或者ip地址
  3. port:端口，http默认端口80，可以省略
  4. path:路径，例如/abc/a/b/c
  5. query：查询参数，例如uname=lisi&age=12
  6. fragment：锚点(哈希Hash)，用于定位i页面的某个位置

#### Restful形式的URL

- http请求方式
  1. GET 查询
  2. POST 添加
  3. PUT 修改
  4. DELETE 删除

==区别==：Resful形式的URL直接用/加参数，传统的需要加？

### Promise用法

#### 异步调用

- 异步效果
  1. 定时器
  2. Ajax
  3. 事件函数

#### 多次异步调用的依赖分析

- 多次异步调用的结果顺序不确定
- 异步调用结果如果存在依赖需要嵌套，变成回调地狱

#### Promise概述

promise是一个对象，它可以获取异步操作的消息

#### Promise使用

步骤：

1. Promise对象实例化传函数作为参数，function有两个参数是resolve和reject用作正常和异常处理

2. 实例对象的then方法，里面传两个函数作为参数，获取异步任务的结果

   ```html
   <body>
       <script>
           // console.log(typeof Promise);
           // console.dir(Promise);
           var p = new Promise(function (resolve, reject) {
               //这里用于实现异步任务
               setTimeout(function () {
                   var flag = false;
                   //正常情况
                   if (flag) {
                       resolve('hello');
                   } else {
                       //异常情况
                       reject('出错了')
                   }
               }, 1000);
           });
           p.then(function (data) {
               console.log(data);//hello
           }, function (data) {
               console.log(data);//出错了
           })
       </script>
   </body>
   ```

- promise处理多个ajax请求

  注意：封装的ajax方法中 return的是一个promise对象，下面then中return的也就是新的promise对象，然后.then的是新的promise对象来获取异步数据

  ```html
  <body>
      <script>
          function queryData(url) {
              var p = new Promise(function (resolve, reject) {
                  var xhr = new XMLHttpRequest();
                  xhr.onreadystatechange = function () {
                      if (xhr.readyState != 4) return;
                      if (xhr.readyState === 4 && xhr.status == 200) {
                          //处理正常的情况
                          resolve(xhr.responseText);
                      } else {
                          //处理异常情况
                          reject('服务器错误')
                      }
                  };
                  xhr.open('get', url);
                  xhr.send(null);
              });
              return p;
          };
  
          //发送多个ajax请求并且保证顺序
          queryData('http://localhost:3000/data')
              .then(function (data) {
                  console.log(data);
                  return queryData('http://localhost:3000/data1');
              })
              .then(function (data) { //这里then的是return的promise的then
                  console.log(data);
                  return queryData('http://localhost:3000/data2')
              })
              .then(function (data) {
                  console.log(data);
              })
      </script>
  </body>
  ```

#### then参数中的函数返回值

1. 返回promise对象

   上面的queryData函数中返回的promise对象，可以继续调用then方法

2. 返回普通值

   返回的普通值，虽然是返回普通值但是会默认产生一个新的promise对象让下一个then调用，通过then参数中函数的参数接收该值

   ```javascript
           //发送多个ajax请求并且保证顺序
           queryData('http://localhost:3000/data')
               .then(function (data) {
                   console.log(data);
                   return queryData('http://localhost:3000/data1') //返回promise对象
               })
               .then(function (data) {
                   console.log(data);
                   return new Promise(function (resolve, reject) { //返回promise对象
                       setTimeout(function () {
                           resolve(123);
                       }, 1000)
                   });
               })
               .then(function (data) {
                   console.log(data);
                   return 'hello' //返回普通值,会默认产生一个新的promise对象让下一个then调用
               })
               .then(function (data) {
                   console.log(data);
               })
   ```

#### Promise常用的API

1. 实例方法

   - p.then() 得到异步任务的正确结果

   - p.catch()获取异常的信息    

     ==注意==：这里p.catch()与p.then()等同于在p.then()中写两个function，第二个function在异常时调用时（promise对象中的reject）等效，

   - p.finally() 成功与否都会执行（尚且不是正式标准）

2. 静态方法

   - Promise.all()并发处理多个任务，==所有任务都执行完成才能得到结果==
   - Promise.race()并发处理多个任务，==只要有一个任务完成就能得到结果==,但是并不会阻止其他任务的执行

```javascript
        //3个异步的接口调用
        var p1 = queryData('http://localhost:3000/data');
        var p2 = queryData('http://localhost:3000/data1');
        var p3 = queryData('http://localhost:3000/data2');
        Promise.all([p1, p2, p3]).then(function (data) {
            console.log(data);//返回的是一个数组，顺序和传参一一对应，直到所有结果都传过来的才执行then，得到所有结果
        });
        Promise.all([p1, p2, p3]).then(function (data) {
            console.log(data);//得到最快返回的一个结果
        })
```

### 接口调用-fetch用法

#### 基本特性

- 更加简单的数据获取方式，可以看成是xhr的升级版
- 基于Promise实现

#### 语法

- .then()获得正常数据，.catch()获得异常数据
- 第一个then的方法中返回data.text()是一个Promise对象
- 第二个then中才是真正的数据

```html
    <script>
        fetch('/data').then(function (data) {
            return data.text();//text()方法属于fetchAPI的一部分，返回的是Promise对象
        }).then(function (data) {
            console.log(data);//拿到数据
        })
    </script>
```

#### fetch请求参数

##### 常用配置选项

- method(String)：HTTP请求方法，默认为GET（GET，POST，PUT，DELETE）
- body(String)：HTTP的请求参数
- headers(Object)：HTTP的请求头，默认为0

##### GET

- 传统url传递：

  ```javascript
      fetch('/data3?id=123', {//用？跟上参数
              method: 'get'
          })
          .then(function (data) {
              return data.text();
          }).then(function (data) {
              console.log(data);
          });
  ```

- 传统url接收：

  ```javascript
  app.get('/data3', (req, res) => {
      res.send('传统url(GET请求)传参' + req.query.id);//在query中拿到参数
  });
  ```

- Resful形式的url传递：

  ```javascript
      fetch('/data3/456', {//直接用/跟上参数
              method: 'get'
          })
          .then(function (data) {
              return data.text();
          }).then(function (data) {
              console.log(data);
          })
  ```

- Resful形式的url接收：

  ```javascript
  app.get('/data3/:id', (req, res) => {//要跟上/:接收的参数名
      res.send('Resful形式的url(GET请求)传参' + req.params.id);//用params拿到参数
  });
  ```

##### DELETE

将method改为delete，接收时改为app.delete，其他同上

##### POST

在对象中加上body属性和headers属性

- 请求内容格式为application/x-www-form-urlencoded的参数传递：

  注意：body中写参数，用&分隔，headers中设置对应的内容类型

  ```javascript
      fetch('/data3', {
              method: 'post',
              body: 'uname=lisi&pwd=123', //参数
              headers: { //请求头设置body中数据的内容类型,与后台bodypaser解析方法相对应
                  'Content-Type': 'application/x-www-form-urlencoded'
              }
          })
          .then(function (data) {
              return data.text();
          }).then(function (data) {
              console.log(data);
          });
  ```

- 请求内容格式为application/x-www-form-urlencoded的参数接收：

  1. 引入express的body-parser模块，用中间件和urlencoded方法进行解析，extended：false指用默认的解析器
  2. 用req.body获取参数

  ```javascript
  app.use(bodyParser.urlencoded({
      extended: false //使用express自带的解析模块
  }));
  app.post('/data3', (req, res) => {
      res.send('POST请求传递参数' + req.body.uname + '---' + req.body.pwd);
  });
  ```

- 请求内容格式为application/json的参数传递:

  注意：body中的json对象需要用JSON.stringify()转为json字符串，headers设置对应的格式

  ```javascript
      fetch('/data3', {
              method: 'post',
              body: JSON.stringify({
                  uname: '张三',
                  pwd: '456'
              }), //参数
              headers: { //请求头设置body中数据的内容类型,与后台bodypaser解析方法相对应
                  'Content-Type': 'application/json'
              }
          })
          .then(function (data) {
              return data.text();
          }).then(function (data) {
              console.log(data);
          })
  ```

- 请求内容格式为application/json的参数接收:

  用bodyParser的json方法进行解析，获取同上

  ```javascript
  app.use(bodyParser.json());
  ```

##### PUT

- 一般用于修改数据

1. 在url中携带需要修改的数据的id，可以用传统url或者Resful类型的url

2. method改为put

3. 在body中写修改的数据，其他同post

   ```javascript
           fetch('/data3/123', {
               method: 'put',
               body: JSON.stringify({
                   uname: '张三',
                   pwd: '789'
               }), //参数
               headers: { //请求头设置body中数据的内容类型,与后台bodypaser解析方法相对应
                   'Content-Type': 'application/json'
               }
           })
           .then(function (data) {
               return data.text();
           }).then(function (data) {
               console.log(data);
           })
   ```

- 接收参数

  ```javascript
  app.put('/data3/:id', (req, res) => {//Resful形式的参数
      res.send('PUT请求传递参数' + req.params.id + req.body.uname + '---' + req.body.pwd);
  });
  ```

#### fetch响应结果

##### text()

- 返回体处理成字符串类型

- 可以用JSON.parse()转为json对象使用

  ```javascript
          fetch('/json')
              .then(function (data) {
                  return data.text();
              }).then(function (data) {
                  var obj = JSON.parse(data);
                  console.log(obj.uname);
              })
  ```

##### json()

- 返回结果和JSON.parse(responseText)一样

  ```javascript
          fetch('/json')
              .then(function (data) {
                  return data.json();
              }).then(function (data) {
                  console.log(data.uname);
              })
  ```

- 后台发送json数据

  ```javascript
  app.get('/json', (req, res) => {
      res.json({
          uname: 'lisi',
          age: 12,
          gender: 'male'
      });
  });
  ```

### 接口调用-axios用法

#### 特征：

1. 支持浏览器和node.js
2. 支持promise
3. 能拦截请求和响应
4. 自动转化JSON数据

#### 基本用法

```html
    <script src="axios.js"></script>
    <script>
        axios.get('/adata')
            .then(function (ret) {
                console.log(ret.data);//data属性是固定的用法，用于获取后台的数据
            });
    </script>
```

#### axios常用API

##### GET

1. 通过url地址传参

   - 传统url

     ```javascript
             axios.get('/axios?id=123')
                 .then(function (ret) {
                     console.log(ret.data);
                 })
     ```

   - Resful形式的url

     ```javascript
             axios.get('/axios/123 ')
                 .then(function (ret) {
                     console.log(ret.data);
                 })
     ```

   - 后台接收传统url

     ```javascript
     app.get('/axios', (req, res) => {
         res.send('axios get 传递参数' + req.query.id);//通过query获取
     });
     ```

   - 后台接收Resful形式的url

     ```javascript
     app.get('/axios/:id', (req, res) => {
         res.send('axios get 传递参数' + req.params.id);//通过params获取
     });
     ```

2. 通过params属性

   ​		后台接收同传统url

   ```javascript
           axios.get('axios', {
               params: {
                   id: 123
               }
           }).then(function (ret) {
               console.log(ret.data);
           })
   ```

##### DELETE

axios.delete()其他同get请求

##### POST

- 默认json格式

  不需要写params属性，后台在通过bodypaser.josn()解析后直接用req.body获取

  ```javascript
          axios.post('axios', {
                  uname: 'lisi',
                  pwd: 123
              })
              .then(ret => {
                  console.log(ret.data);
              });
  
  app.post('/axios', (req, res) => {
      res.send(req.body.uname + req.body.pwd);
  });
  
  ```

- urlencdoed格式

  需要new一个URLSearchParams()实例对象，用append方法添加值，将params传递，后台同json，需要bodyPaser的urlencoded解析

  ```javascript
          var params = new URLSearchParams();
          params.append('uname', 'zhangsan');
          params.append('pwd', '111');
          axios.post('/axios', params).then(ret => {
              console.log(ret.data);
          })
  ```

##### PUT

- 在url中携带id指要修改的目标，其他同post

```javascript
        axios.put('axios/123', {
            uname: 'wangwu',
            pwd: 123
        }).then(ret => {
            console.log(ret.data);
        })
```

- 后台接收时，如果时Resful形式的url需要/：id，id用query获取，其他用body获取

```javascript
app.put('/axios/:id', (req, res) => {
    res.send(req.query.id + req.body.uname + req.body.pwd);
});
```

#### axios响应结果

- data：实际响应结果
- headers：响应头信息
- status：响应状态码
- statusText：响应状态信息

#### axios全局配置

axios.defaults.timeout = 3000;//超时时间

axios.defaults.baseURL = ‘http://localhost:3000/app’;//默认地址

axios.defaults.headers [ 'mytoken' ] = 'dfsfsdfsfsfsfsrgrg';//设置请求头 

```javascript
        //配置请求头信息
        axios.defaults.headers['mytoken'] = 'hello';//需要设置跨域，token
        //需要解决跨域问题
        axios.defaults.baseURL = 'http://localhost:3000/';
        axios.get('axios').then(ret => {
            console.log(ret);
        })

//允许跨域
app.all('*', (rwq, res, next) => {
    res.header("Access-Control-Allow-Origin", "*");
    res.header("Access-Control-Allow-Methods", "PUT,GET,POSY,DELETE,OPTIONS");
    res.header("Access-Control-Allow-Headers", "X_Requested-With");
    res.header("Access-Control-Allow-Headers", "Content-Type");
    res.header("Access-Control-Allow-Headers", "mytoken");
    next();
});
```

#### axios拦截器

- 请求拦截器

  在发出请求之前设置一些信息

  axios请求要到达服务器要经过拦截器

```javascript
        axios.interceptors.request.use(function (config) {
            console.log(config.url);
            config.headers.mytoken = 'nihao';
            return config;
        }, function (err) {
            console.log(err);//处理错误信息
        });
        axios.get('http://localhost:3000/adata').then(ret => {//请求头中会有mytoken
            console.log(ret);//返回的数据
        })
```

- 响应拦截器

  在获取数据之前对数据做一些加工

  服务器响应的数据要经过拦截器才能拿到

  ```javascript
          axios.interceptors.response.use(function (res) {
              console.log(res);
              return res.data//对响应的数据进行处理
          }, function (err) {
              console.log(err);
          });
  
          axios.get('http://localhost:3000/adata').then(ret => {
              console.log(ret);//这里拿到的就是data数据，不再是响应回来的对象
          })
  ```

### 接口调用-async/await用法

- ES7的新语法，可以更加方便得进行异步操作
- async用于函数上（async函数得返回值时promise对象）
- await用于saync函数中（await可以得到当前异步的结果）

==注意==：因为async返回的也是个promise对象，在调用时也可以用then获得函数的返回值

```javascript
        async function queryData() {
            var ret = await axios.get('adata');
            console.log(ret.data);
            return ret.data;
        }
        queryData().then(data => {
            console.log(data);
        });
```

==注意==：await后面必须跟promise实例对象，才能获取异步的结果

```javascript
        async function num() {
            var ret = await new Promise(function (resolve, reject) {//resolve成功，reject失败
                setTimeout(function () {
                    resolve('nihao')
                }, 1000)
            });
            console.log(ret);
            return ret;
        };
        num().then(data => {
            console.log(data);
        })
```

- 处理多个异步任务

  桉顺序写即可

  ```javascript
          axios.defaults.baseURL = 'http://localhost:3000';
          async function queryData() {
              var info = await axios.get('async1');
              var ret = await axios.get('async2?info=' + info.data);//用info作为参数
              return ret.data;
          }
          queryData().then(ret=>{
              console.log(ret);
          })
  ```

## Vue-router

### 路由

#### 后端路由

- URL请求地址与服务器资源之间的对应关系

#### 前端路由

- SPA单页面开发技术核心

- 负责事件监听，触发事件后，通过事件函数渲染不同内容

### Vue-router基本使用

步骤：

1. 导入相关文件
2. 路由标签，默认是a标签，to属性中的链接会被渲染为#/xxx
3. 路由占位符，切换路由后显示内容的区域
4. js中路由组件
5. 创建路由实例对象
6. 定义路由规则
7. 在vue实例中挂载路由

```php+HTML
<body>
        <div id="app">
            <!-- 1.路由标签，默认是a标签-->
            <router-link to="/user">User</router-link>
            <router-link to="/register">Register</router-link>

            <!-- 2.路由占位符，切换路由后显示内容的区域 -->
            <router-view></router-view>
        </div>
        <script src="../js/vue.js"></script>
        <script src="../js/vue-router.js"></script>
        <script>
            /*jshint esversion: 6 */
            //3.路由组件
            const User = {
                template: '<h1>User组件</h1>'
            }
            const Register = {
                template: `<h1>Register组件</h1>`
            }

            //4.创建路由实例对象
            const router = new VueRouter({
                //5.路由规则
                routes: [{
                        path: '/user',
                        component: User //只接受组件对象，不接受字符串
                    },
                    {
                        path: '/register',
                        component: Register //只接受组件对象，不接受字符串
                    }
                ]
            })
            //6.把路由挂载到跟实例中
            var vm = new Vue({
                el: '#app',
                router //挂载
            })
        </script>
    </body>
```

### 路由重定向

- 在路由规则中加上redirect属性

  ```javascript
              const router = new VueRouter({
                  //5.路由规则
                  routes: [{
                          path: '/',
                          redirect: '/user'
                      },
                      {
                          path: '/user',
                          component: User //只接受组件对象，不接受字符串
                      },
                      {
                          path: '/register',
                          component: Register //只接受组件对象，不接受字符串
                      }
                  ]
              })
  ```

### 嵌套路由

1. 在父组件模板中定义router-link和router-view
2. 定义子组件
3. 在父级路由中增加children属性，添加子路由规则

```html
<body>
    <div id="app">
        <router-link to="/user">User</router-link>
        <router-link to="/register">Register</router-link>

        <router-view></router-view>
    </div>
    <script src="../js/vue.js"></script>
    <script src="../js/vue-router.js"></script>
    <script>
        const User = {
            template: `<div>User组件</div>`
        }
        //1.在父组件模板中定义router-link和router-view
        const Register = {
            template: `<div>
            <div>Register组件</div>
            <router-link to="/register/tab1">Tab1</router-link>
            <router-link to="/register/tab2">Tab2</router-link>
            <router-view></router-view>
            </div>
            `
        }

        //3.定义子组件
        const Tab1 = {
            template: `
            <div>Tab1组件</div>
            `
        }
        const Tab2 = {
            template: `
            <div>Tab2组件</div>
            `
        }
        //2.父级路由中通过children属性，为register添加子路由规则
        const router = new VueRouter({
            routes: [{
                path: '/user',
                component: User
            }, {
                path: '/register',
                component: Register,
                children: [{//数组形式
                        path: '/register/tab1',
                        component: Tab1
                    },
                    {
                        path: '/register/tab2',
                        component: Tab2
                    }
                ]
            }]
        })
        var vm = new Vue({
            el: '#app',
            router
        })
    </script>
</body>
```

### 动态路由匹配

1. 如果由多个url前面差不多的，只是参数发生变化

2. 用/：id作为路由参数，进行动态路由匹配

3. 组件中用$route.params.xxx获得路由参数

   ```html
       <body>
           <div id="app">
               <!-- 1.路由标签，默认是a标签-->
               <router-link to="/user/1">User</router-link>这里需要动态路由
               <router-link to="/user/2">User</router-link>
               <router-link to="/user/3">User</router-link>
               <router-link to="/register">Register</router-link>
   
               <!-- 2.路由占位符，切换路由后显示内容的区域 -->
               <router-view></router-view>
           </div>
           <script src="../js/vue.js"></script>
           <script src="../js/vue-router.js"></script>
           <script>
               /*jshint esversion: 6 */
               //3.路由组件
               const User = {
                   template: '<h1>User{{$route.params.id}}组件</h1>'//获取动态路由参数
               }
               const Register = {
                   template: `<h1>Register组件</h1>`
               }
   
               //4.创建路由实例对象
               const router = new VueRouter({
                   //5.路由规则
                   routes: [{
                           path: '/',
                           redirect: '/user'
                       },
                       {
                           path: '/user/:id',//接受动态路由参数
                           component: User 
                       },
                       {
                           path: '/register',
                           component: Register 
                       }
                   ]
               })
               //6.把路由挂载到跟实例中
               var vm = new Vue({
                   el: '#app',
                   router //挂载
               })
           </script>
       </body>
   ```

### 路由组件传参

#### props的值为bool类型

- $router与对应的路由形成了高度的耦合，不够灵活，所以一般使用props将组件和路由解耦
  1. 在路由中添加pros属性，为true
  2. 在组件中定义接收的参数
  3. 在模板中使用

```html
    <body>
        <div id="app">
            <router-link to="/user/1">User</router-link>
            <router-link to="/user/2">User</router-link>
            <router-link to="/user/3">User</router-link>
            <router-link to="/register">Register</router-link>

            <router-view></router-view>
        </div>
        <script src="../js/vue.js"></script>
        <script src="../js/vue-router.js"></script>
        <script>
            const User = {
                props:['id'],//使用props接收路由参数
                template: '<h1>User{{id}}组件</h1>'
            }
            const Register = {
                template: `<h1>Register组件</h1>`
            }

            const router = new VueRouter({
                routes: [{
                        path: '/',
                        redirect: '/user'
                    },
                    {
                        path: '/user/:id',
                        component: User,
                        props:true //开启路由传参,route.params会被设置为组件属性
                    },
                    {
                        path: '/register',
                        component: Register 
                    }
                ]
            })
            var vm = new Vue({
                el: '#app',
                router //挂载
            })
        </script>
    </body>
```

#### props的值为对象类型

1. 路由的props属性值为对象，此时id无法使用

2. 在组件中用props依次接收

   ```html
       <body>
           <div id="app">
               <router-link to="/user/1">User</router-link>
               <router-link to="/user/2">User</router-link>
               <router-link to="/user/3">User</router-link>
               <router-link to="/register">Register</router-link>
   
               <router-view></router-view>
           </div>
           <script src="../js/vue.js"></script>
           <script src="../js/vue-router.js"></script>
           <script>
               const User = {
                   props: ['uname', 'age'], //使用props接收路由参数
                   template: '<h1>User{{uname + age}}组件</h1>'
               }
               const Register = {
                   template: `<h1>Register组件</h1>`
               }
   
               const router = new VueRouter({
                   routes: [{
                           path: '/',
                           redirect: '/user'
                       },
                       {
                           path: '/user/:id',
                           component: User,
                           //props: true //开启路由传参,route.params会被设置为组件属性
                           //参数为对象，此时id就无法使用了
                           props: {
                               uname: 'lisi',
                               age: 12
                           }
                       },
                       {
                           path: '/register',
                           component: Register
                       }
                   ]
               })
               var vm = new Vue({
                   el: '#app',
                   router //挂载
               })
           </script>
       </body>
   ```

#### props的值为函数型

- 将上面的动态参数和静态参数结合起来使用

- 箭头函数，参数为route，返回一个对象，动态参数id用route.params.id获取

- 组件中通过props接收

  ```html
      <body>
          <div id="app">
              <router-link to="/user/1">User</router-link>
              <router-link to="/user/2">User</router-link>
              <router-link to="/user/3">User</router-link>
              <router-link to="/register">Register</router-link>
  
              <router-view></router-view>
          </div>
          <script src="../js/vue.js"></script>
          <script src="../js/vue-router.js"></script>
          <script>
              const User = {
                  props: ['id','uname', 'age'], //使用props接收路由参数
                  template: '<h1>User{{id+uname + age}}组件</h1>'
              }
              const Register = {
                  template: `<h1>Register组件</h1>`
              }
  
              const router = new VueRouter({
                  routes: [{
                          path: '/',
                          redirect: '/user'
                      },
                      {
                          path: '/user/:id',
                          component: User,
                          //参数为函数
                          props: route => ({
                                  uname: 'zs',//静态参数
                                  age: 12,
                                  id: route.params.id//动态参数
                              }
                          )
                      },
                      {
                          path: '/register',
                          component: Register
                      }
                  ]
              })
              var vm = new Vue({
                  el: '#app',
                  router //挂载
              })
          </script>
      </body>
  ```

### Vue-router命名路由

- 给路由规则起一个别名，加上name属性

- 此时router-link的to属性中绑定（注意:to前要加冒号）一个对象，name属性表示要去往的路由，params属性是一个对象，表示传递的参数

  ```html
      <body>
          <div id="app">
              <router-link to="/user/1">User</router-link>
              <router-link to="/user/2">User</router-link>
              <router-link :to="{name:'user',params:{id:3}}">User</router-link>
              <router-link to="/register">Register</router-link>
  
              <router-view></router-view>
          </div>
          <script src="../js/vue.js"></script>
          <script src="../js/vue-router.js"></script>
          <script>
              const User = {
                  props: ['id', 'uname', 'age'],
                  template: '<h1>User{{id+uname + age}}组件</h1>'
              }
              const Register = {
                  template: `<h1>Register组件</h1>`
              }
  
              const router = new VueRouter({
                  routes: [{
                          path: '/',
                          redirect: '/user'
                      },
                      { //命名路由
                          name: 'user',
                          path: '/user/:id',
                          component: User,
                          props: route => ({
                              uname: 'zs',
                              age: 12,
                              id: route.params.id
                          })
                      },
                      {
                          path: '/register',
                          component: Register
                      }
                  ]
              })
              var vm = new Vue({
                  el: '#app',
                  router //挂载
              })
          </script>
      </body>
  ```

### vue-router编程式导航

页面导航的两种方式

1. 声明式导航

   通过点击链接实现导航的方式

2. 编程式导航

   通过调用JavaScript形式的API实现导航的方式

#### 常用的编程式导航API

this.$router.push('hash地址')：根据hash地址跳转

this.$router.go(n)：n为1，前进1页，n为-1.后退一页

```html
<body>
        <div id="app">
            <router-link to="/user/1">User</router-link>
            <router-link to="/user/2">User</router-link>
            <router-link :to="{name:'user',params:{id:3}}">User</router-link>
            <router-link to="/register">Register</router-link>

            <router-view></router-view>
        </div>
        <script src="../js/vue.js"></script>
        <script src="../js/vue-router.js"></script>
        <script>
            const User = {
                props: ['id', 'uname', 'age'],
                template: `
                <div>
                <h1>User{{id + uname + age}}组件</h1>
                <button @click="goRegister">跳转到注册页面</button>
            </div>`,
                methods: {
                    goRegister: function () {
                        this.$router.push('/register');
                    }
                },
            }
            const Register = {
                template: `
                <div>
                    <h1>Register组件</h1>
                    <button @click="goback">返回</button>
                    </div>
               `,
                methods: {
                    goback: function () {
                        this.$router.go(-1);
                    }
                },
            }

            const router = new VueRouter({
                routes: [{
                        path: '/',
                        redirect: '/user'
                    },
                    { //命名路由
                        name: 'user',
                        path: '/user/:id',
                        component: User,
                        props: route => ({
                            uname: 'zs',
                            age: 12,
                            id: route.params.id
                        })
                    },
                    {
                        path: '/register',
                        component: Register
                    }
                ]
            })
            var vm = new Vue({
                el: '#app',
                router //挂载
            })
        </script>
    </body>
```

#### router.push()方法的参数规则

##### 参数为字符串

router.push('/home')

##### 参数为对象

router.push({ path :  '/home/:id' })

##### 跳转到命名路由

router.push( {  name: '/user ' ,params:{ userId :123 }  } )

##### 带查询参数

- 在跳转时会自动转为/register？uname = ‘lisi’的形式加在url地址后面

router.push({ path: '/register' , query:{ uname: ' lisi ' }})

## Vue-cli

作用：用于生成Vue项目基础架构

1. npm install -g @vue/cli

### 创建vue项目

#### 基于交互命令行的方式

命令行 vue create my-project创建项目

#### 基于图形化界面的方式

1. 命令行vue ui
2. Babel，Router，Linter/Formatter（ESLint+Standard config），使用配置文件

### Vue脚手架生成的项目结构

### Vue脚手架的自定义配置

- 通过package.json配置项目

```javascript
  "vue":{
    "devServer":{
      "port":8888,
      "open":true
    }
```

注意：不推荐这种配置方式，因为package.json主要用来管理包的配置信息，为了方便维护，推荐将vue脚手架相关的配置，单独定义到vue.config.js配置文件中

- 通过单独的配置文件配置项目

  新建vue.config.js文件

  ```javascript
  module.exports={
    devServer:{
      //自动打开浏览器
      open:true,
      //端口号
      port:8878
    }
  }
  ```


## Element-UI

### 基于命令行方式手动安装

1. npm i element-ui -S
2. 在入口文件中导入Element-UI相关资源

```javascript
import ElementUI from 'elemoent-ui' // 导入ElementUI组件库
import 'element-ui/lib/theme-chalk/index.css' // 导入ElementUI组件相关样式
// 把element-ui配置成vue的插件
Vue.use(ElementUI)
```

### 基于图形化界面自动安装

1. vue ui
2. 通过Vue项目管理器，进入具体的项目配置面板
3. 点击插件=》添加插件，进入插件查询面板
4. 安装vue-cli-plugin-element
5. 配置插件，实现按需导入，从而减少打包后项目的体积