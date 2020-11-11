# webpack安装

![](D:\桌面\notes\Webpack\assets\webpack安装.png)

# webpack的基本使用

文件结构

![](D:\桌面\notes\Webpack\assets\webpack基本使用.png)

src：源文件目录

dist：webpack编译处理后的文件目录

全局安装webpack后执行命令：webpack ./src/main.js ./dist/bundle.js

![](D:\桌面\notes\Webpack\assets\webpack步骤1.png)

![](D:\桌面\notes\Webpack\assets\webpack步骤2.png)

![](D:\桌面\notes\Webpack\assets\webpack步骤3.png)

# 配置打包的入口与出口

![](D:\桌面\notes\Webpack\assets\webpack配置.png)

```javascript
const path = require('path')//node核心模块
module.exports = {
	mode: 'development', //编译模式
	entry: path.join(__dirname, './src/index.js'), //入口文件指定路径
	output: {
		path: path.join(__dirname, './dist'), //输出文件的存放路径
		filename: 'bundle.js' //输出文件的名称
	}
}
```

# 配置webpack打包命令

1. npm init创建package.json文件
2. 在scripts属性里配置打包命令
3. 这里使用命令会优先选择局部安装的webpack，其次才是全局安装的webpack

![](D:\桌面\notes\Webpack\assets\package中定义启动.png)

```json
{
  "name": "meetwebpack",
  "version": "1.0.0",
  "description": "",
  "main": "webpack.config.js",
  "scripts": {
    "test": "echo \"Error: no test specified\" && exit 1",
    "build": "webpack"//npm run build执行命令
  },
  "author": "",
  "license": "ISC",
  "devDependencies": {//开发环境依赖
    "webpack": "^3.6.0"
  }
}
```

# loader

![](D:\桌面\notes\Webpack\assets\loader.png)

- 作用：协助webpack进行打包，webpack只能打包.js的文件，当文件后缀不是,js时，会去webpack的配置文件中找loader
- 调用过程：

#### 打包css文件

1. npm install css-loader --save-dev,安装编译css文件的loader

2. 在webpack.config.js的module=>rules数组中，添加loader规则，此时只是编译了css，样式并不会生效

3. npm install style-loader --save-dev，安装渲染DOM的loader

4. 添加loader规则

   ![](D:\桌面\notes\Webpack\assets\css文件处理.png)

   ![](D:\桌面\notes\Webpack\assets\css文件处理-css-loader.png)

   ![](D:\桌面\notes\Webpack\assets\css文件处理-style-loader.png)

```json
const path = require('path')
module.exports={
  entry:'./src/main.js',//要在main中引入css
  output: {
    path:path.resolve(__dirname,'dist'),
    filename:'bundle.js'
  },
  module: {
    rules: [
      {
        //正则匹配
        test: /\.css$/,
        //css-loader只负责将css文件进行加载
        //style-loader负责将样式添加到DOM中
        //使用多个loader时，是从右向左的
        use: [ 'style-loader','css-loader' ]
      }
    ]
  }
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

### 打包图片和字体文件

1. npm i url -loader file-loader -D

2. 在webpack.config.js的moudle的rules数组中，添加loader规则

   ![](D:\桌面\notes\Webpack\assets\图片处理file-loader.png)
   
   ![](D:\桌面\notes\Webpack\assets\file-loader修改文件名称.png)
   
   
   
   ```javascript
   	module: {
   		rules: [{
   			test: /\.css$/, //文件后缀名
   			use: ['style-loader', 'css-loader', 'postcss-loader'] //该文件后缀名使用的插件,顺序从后往前
   		},      {
           test: /\.(png|jpg|gif)$/i,
           use: [
             {
               loader: 'url-loader',
               options: {
                 //当加载的图片，小于limit时，会将图片编译成base64字符串形式
                 //当加载的图片，大于limit时，需要使用file-loader模块进行加载
                 limit: 10000,
               },
             },
           ],
         }]
   	}
   ```

### ES6转ES5

![](D:\桌面\notes\Webpack\assets\babel-loader.png)

```json
{
  test: /\.js$/,
  //这些文件不会被编译处理
  exclude: /(node_modules|bower_components)/,
  use: {
    loader: 'babel-loader',
    options: {
      presets: ['es2015']
    }
  }
}
// npm run build
```

# 在webpack项目中使用vue

![](D:\桌面\notes\Webpack\assets\引入vue.png)

==注意==：

1. 如果报错，就是vue的版本不对，不支持template标签，此时需要在webpack.config.js中添加如下属性

   ```json
     resolve:{
       //别名
       alias:{
         'vue$':'vue/dist/vue.esm.js'
       }
     }
   ```

2. 一般在index.html中不写其他的html，所以将el中的标签用temolate替换掉

main.js

```js
require('./css/normal.css')
import Vue from 'vue'
new Vue({
  el:'#app',
  template:'<h2>{{message}}</h2>',
  data:{
    message:'Hello World'
  }
})
```

index.html

```html
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <title>Title</title>
</head>

<body>
<div id="app"></div>
</body>
<script src="dist/bundle.js"></script>
</html>
```

## el和template区别

![](D:\桌面\notes\Webpack\assets\el和template区别1.png)

![](D:\桌面\notes\Webpack\assets\el和template区别2.png)

## Vue组件化开发引入

![](D:\桌面\notes\Webpack\assets\vue组件化开发引入.png)

## .vue文件打包

![](D:\桌面\notes\Webpack\assets\vue文件封装处理.png)

==注意==：

1. vue-loader在14版本之后要使用loader必须配置插件，否则会报错，如果不用插件需要降低vue-loader版本
2. 如果在import引入时需要省略.vue后缀，则在webpack.config.js中添加如下配置

```json
resolve:{//一般用来解决路径问题
  extensions:['.js','.css','.vue'],//解决文件后缀名问题
  //别名
  alias:{//解决vue版本问题
    'vue$':'vue/dist/vue.esm.js'
  }
}
```

# plugin

文件结构

![](D:\桌面\notes\Webpack\assets\plugin文件结构.png)

![](D:\桌面\notes\Webpack\assets\认识plugin.png)

## 添加版权的Plugin

![](D:\桌面\notes\Webpack\assets\版权plugin.png)

## 打包html的Plugin

![](D:\桌面\notes\Webpack\assets\打包html的plugin.png)

## js压缩的Plugin

开发阶段不建议丑化

![](D:\桌面\notes\Webpack\assets\js压缩的plugin.png)

# 搭建本地服务器

![](D:\桌面\notes\Webpack\assets\搭建本地服务器.png)

```json
devServer:{
  //服务哪一个文件夹
  contentBase:'./dist',
  //是否需要实时监听
  inline:true
}
```

==注意==：

1. 在package.json文件中，scripts属性里添加简化命令

   ```json
   "scripts": {
     "test": "echo \"Error: no test specified\" && exit 1",
     "build": "webpack",//用于打包处理
     "dev": "webpack-dev-server"//用于运行，如果要自动打开网页，加上--open
   }
   ```

# webpack配置的分离

文件结构

![](D:\桌面\notes\Webpack\assets\配置分离文件结构.png)

1. 将webpack.config中的代码分为开发依赖和生产依赖

2. build文件目录存放分离的配置文件

3. 其中base.config存公共的配置，如出入口，loader，部分plugins

   ```json
   const path = require('path')
   const webpack = require('webpack')
   const HtmlWebpackPlugin=require('html-webpack-plugin')
   const UglifyjsWebpackPlugin=require('uglifyjs-webpack-plugin')
   module.exports={
     entry:'./src/main.js',
     output: {
       //上一层文件夹中的dist
       path:path.resolve(__dirname,'../dist'),
       filename:'bundle.js',
       // publicPath:'dist/'
     },
     module: {
       rules: [
         {
           //正则匹配
           test: /\.css$/,
           //css-loader只负责将css文件进行加载
           //style-loader负责将样式添加到DOM中
           //使用多个loader时，是从右向左的
           use: [ 'style-loader','css-loader' ]
         },
         {
           test: /\.(png|jpg|gif)$/i,
           use: [
             {
               loader: 'url-loader',
               options: {
                 //当加载的图片，小于limit时，会将图片编译成base64字符串形式
                 //当加载的图片，大于limit时，需要使用file-loader模块进行加载
                 limit: 10000,
               },
             },
           ],
         },
         {
           test: /\.js$/,
           //这些文件不会被编译处理
           exclude: /(node_modules|bower_components)/,
           use: {
             loader: 'babel-loader',
             options: {
               presets: ['es2015']
             }
           }
         },
         {
           test:/\.vue$/,
           use:['vue-loader']
         }
       ]
     },
     resolve:{//一般用来解决路径问题
       extensions:['.js','.css','.vue'],
       //别名
       alias:{
         'vue$':'vue/dist/vue.esm.js'
       }
     },
     plugins:[
       new webpack.BannerPlugin('最终版权归xqz所有'),
       new HtmlWebpackPlugin({
         template:'index.html'
       }),
       // new UglifyjsWebpackPlugin()
     ],
     // devServer:{
     //   //服务哪一个文件夹
     //   contentBase:'./dist',
     //   //是否需要实时监听
     //   inline:true
     // }
   }
   ```

4. dev.config存放开发配置，如搭建的本地服务器

   ```json
   const webpackMerge=require('webpack-merge')
   const baseConfig = require('./base.config')
   module.exports=webpackMerge.merge(baseConfig,{
     devServer:{
       //服务哪一个文件夹
       contentBase:'./dist',
       //是否需要实时监听
       inline:true
     }
   })
   
   ```

5. prod.config存放生产配置，如压缩js代码

   ```json
   const UglifyjsWebpackPlugin=require('uglifyjs-webpack-plugin')
   const baseConfig= require('./base.config')
   const webpackMerge = require('webpack-merge')
   module.exports = webpackMerge.merge(baseConfig,{
     plugins:[
       // new webpack.BannerPlugin('最终版权归xqz所有'),
       // new HtmlWebpackPlugin({
       //   template:'index.html'
       // }),
       new UglifyjsWebpackPlugin()
     ]
   })
   ```

6. 利用npm install webpack-merage --save-dev,下载合并配置的模块，利用webpackMerge.merge方法进行合并

7. 合并完修改package.json中的scripts的build和dev指令

   ```json
   "scripts": {
     "test": "echo \"Error: no test specified\" && exit 1",
       //--config标识执行的配置是生产
     "build": "webpack --config ./build/prod.config.js",
         //--config标识执行的配置是开发
     "dev": "webpack-dev-server --open --config ./build/dev.config.js"
   },
   ```

8. 修改base.config中的入口和出口，因为是相对路径，此时是在build文件夹下，而不是之前webpack.config所在的根目录

   ```json
     entry:'../src/main.js',
     output: {
       //上一层文件夹中的dist
       path:path.resolve(__dirname,'../dist'),
       filename:'bundle.js',
       // publicPath:'dist/'
     },
   ```



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