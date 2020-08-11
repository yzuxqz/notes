# 模块化开发

## ES6模块化规范

1. 每一个js文件都是一个独立的模块
2. ==导入模块成员==使用==import==关键字
3. ==暴露模块成员==使用==export==关键字

- Node.js中通过babel进行ES6模块化

  1. npm install --save-dev @babel/core @babel/cli @babel/preset-env @babel/node

  2. npm install --save @babel/polyfill

  3. 创建==babel.config.js==配置文件内容

     ```javascript
     const presets = [
     	["@babel/env", {
     		targets: {//支持的浏览器版本
     			edge: "17",
     			firefox: "60",
     			chrome: "67",
     			safari: "11.1"
     		}
     	}]
     ]
     
     module.exports = {
     	presets
     }
     ```

  4. 通过npx babel-node ./index.js执行代码

## ES6模块化基本语法

- 默认导出：exports default (暴露本模块中的私有成员)

  ```javascript
  let a = 10;
  let c = 20;
  let d = 30;
  
  function show () {
  	console.log('111');
  }
  export default {
  	a,
  	c,
  	show
  }
  ```

  ==注意==：在每个模块中只能使用唯一的一次exprot default，否则会报错

- 默认导入：import 接收名称 from ‘模块标识符’

  ```javascript
  import m1 from './m1.js'
  
  console.log(m1);
  console.log(m1.a);
  ```

- 按需导出

  ```javascript
  export let s1='aaa';
  export let s2='ccc';
  export function say(){
  	console.log('say');
  }
  ```

  ==注意==：export按需导出可以用多次

- 按需导入

  ```javascript
  import {
  	s1,
  	s2
  } from './m1.js'
  console.log(s1);
  ```

- 直接导入并执行模块代码

  import './m2.js'

# webpack的基本使用

1. npm install webpack webpack-cli -D 

2. 在项目根目录中，创建名为==webpack.config.js==的webpack配置文件

3. 在webpack的配置文件中，初始化

   module.exports = {

   mode: ' development ' // mode 用来指定构建模式  production为产品发布模式

   }

4. 在package.json配置文件中的scripts节点下，新增dev脚本

   “scripts”：{

   ​	“dev”:"webpack"//script节点下的脚本，可以通过npm run运行

   }

5. 在终端中运行npm run dev 命令，启动webpack进行项目打包

# 配置打包的入口与出口

```javascript
const path = require('path')
module.exports = {
	mode: 'development', //编译模式
	entry: path.join(__dirname, './src/index.js'), //入口文件指定路径
	output: {
		path: path.join(__dirname, './dist'), //输出文件的存放路径
		filename: 'bundle.js' //输出文件的名称
	}
}
```

# 配置webpack的自动打包

1. npm install webpack-dev-server -D 安装支持自动打包的工具
2. 修改package.json的scripts节点的dev命令为“webpack-dev-server”
3. 将html文件中的.script脚本引用路径改为“/bundle.js”
4. npm run dev
5. 浏览器访问http://loacalhost:8080

# 配置html-webpack-plugin生成预览页面

1. 运行npm install html-webpack-plugin -D

2. 修改webpack.config.js文件头部区域

   ```javascript
   const HtmlWebpackPlugin = require('html-webpack-plugin');
   const htmlPlugin = new HtmlWebpackPlugin({//创建插件的实例对象
   	template: './src/index.html', //要复制的文件
   	filename: 'index.html' //要生成的文件名称，文件在内存中，目录中不显示
   })
   ```

3. 修改webpack.config.js文件中向外暴露的配置对象

   ```javascript
   plugins: [htmlPlugin]//plugins数组时webpack打包期间会用到的一些插件列表
   ```

4. 重新npm run dev打包

# 配置自动打包相关参数

- --open 打包完成后自动打开浏览器页面
- --host 配置id地址
- --port 配置端口

在==package.json==中修改

```javascript
	"scripts": {
		"dev": "webpack-dev-server --open --host 127.0.0.1 --prot 8888"
	}
```

# webpack中的加载器

### 通过loader打包非js模块

- 作用：协助webpack进行打包，webpack只能打包.js的文件，当文件后缀不是,js时，会去webpack的配置文件中找loader

- 调用过程：

#### 打包css文件

1. npm install style-loader css-loader -D 安装处理css文件的loader

2. 在webpack.config.js的module=>rules数组中，添加loader规则

   ```javascript
   	module: {
   		rules: [{
   			test: /\.css$/,//文件后缀名
   			use: ['style-loader', 'css-loader']//该文件后缀名使用的插件，这里顺序不能换，先调用css，再调用style，最后返回给webpack
   		}]
   	}
   ```

### 配置postCSS自动添加css的兼容前缀

作用：解决浏览器的兼容性问题

1. npm install postcss-loader autoprefixer -D

2. 在项目根目录中创建postcss的配置文件postcss.config.js，并初始化

   ```javascript
   const autoprefixer = require('autoprefixer')
   
   module.exports = {
   	plugins: [autoprefixer]//挂载插件
   }
   ```

3. 在webpack.config.js的module=>rules数组中，修改css的loader规则

   ```javascript
   	module: {
   		rules: [{
   			test: /\.css$/,//文件后缀名
   			use: ['style-loader', 'css-loader','postcss-loader']//该文件后缀名使用的插件,顺序从后往前
   		}]
   	}
   ```

### 打包样式中的图片和字体文件

1. npm i url -loader file-loader -D

2. 在webpack.config.js的moudle的rules数组中，添加loader规则

   ```javascript
   	module: {
   		rules: [{
   			test: /\.css$/, //文件后缀名
   			use: ['style-loader', 'css-loader', 'postcss-loader'] //该文件后缀名使用的插件,顺序从后往前
   		}, {
   			test: /\.jpg|png|gif|jpeg|bmp|ttf|eot|woff|woff2$/,
   			use: ['url-loader?limit=400000']//limit表示小于该大小的图片才会被转为base64的图片
   		}]
   	}
   ```

### 打包处理js文件中的高级语法

1. 安装babel转化器相关的包：npm i babel-loader @babel/core @babel/runtime -D

2. 安装babel语法插件相关的包：npm i @babel/preset-env @babel/plugin-transform-runtime @babel/plugin-proposal-class-properties -D

3. 在项目根目录中，创建babel配置文件babel.config.js并初始化

   ```javascript
   module.exports = {
   	presets: ['@babel/preset-env'], //babel语法相关
   	plugins: ['@babel/plugin-transform-runtime', '@babel/plugin-proposal-calss-properties'] //babel插件相关
   }
   ```

4. 在webpack.config.js的moudle的rules的数组中，添加loader规则，增加排除项，排除node_moudels中的js文件

   ```javascript
   		{
   			test: /\.js$/,
   			use: ['babel-loader'],
   			exclude: /node_modules///排除node_modules中的js文件
   		}
   ```

### webpack中配置vue组件的加载器

#### Vue单文件组件

- template 组件的模板区域
- script 业务逻辑区域
- style 样式区域

1. npm i vue-loader vue-template-compiler -D

2. 在webpack.config.js配置文件，添加vue-loader的配置项

   ```javascript
   const VueLoaderPlugin = require('vue-loader/lib/plugin')
   //module。exports中的plugins属性中添加
   plugins: [htmlPlugin, new VueLoaderPlugin()], //需要new一个Vue插件的实例，来引入这个插件
   module的rules属性中添加
   {
   			test: /\.vue$/,
   			use: 'vue-loader'
   		}
   ```

### 在webpack项目中使用vue

1. npm i vue -s安装vue
2. 在src 的index.js文件中，通过import Vue from 'vue'来导入vue 的构造函数
3. 创建vue的实例对象，并指定要控制的el区域，在index.html中有相应的id组件
4. 通过render函数渲染App根组件

```javascript
import Vue from 'vue' //导入包得到一个构造函数，相当于引入js文件
import App from './components/App.vue' //导入单文件组件

const vm = new Vue({
	el: '#app',//指定el区域
	render: h => h(App)//render函数指定要渲染的根组件
})
```

==注意==：要用render函数渲染组件，不能用component和template，因为在webpack中导入的vue是阉割版的vue，只支持render函数渲染组件

# webpack打包发布

- 通过package.json文件配置打包命令

  在scripts节点中，增加build属性，属性值为webpack -p

  ```javascript
  	"scripts": {
  		"test": "echo \"Error: no test specified\" && exit 1",
  		"dev": "webpack-dev-server --open --host 127.0.0.1 --prot 8888",
  		"build": "webpack -p
  	}
  ```

- npm run build