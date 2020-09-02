# 基本语法
  
## 对于文字修饰
### 标题 (Heading)
> 使用#表示，一共分6级标题。   
> 或者使用=和-表示一级和二级标题   

### 斜体 (italic)
> 使用\*表示
> 或者使用_表示

### 加粗 (Bold)
> 使用\*\*表示
> 或者使用\_\_表示

### 又粗又斜
> 3个\*   
> 或者3个\_

### 加下划线（underline）
> 使用HTML标记u   
> 使用形式： `<u>your words</u>`

### 删除线 (delete)
> 2个波浪符 ~~

### 超链接
> 使用形式: `[visible words](Real_link_url)`    
也可以直接输入链接url    
高级链接，使用两个中括号，和1个键值对表示。用途：为了把链接都放在文末，方便修改管理。

这是一个高级链接。[闪耀暖暖材料表][NikkiMedia]包含了搭配学院升级需要的材料。


[NikkiMedia]: https://github.com/Furret2018/NikkiMedia 


### 脚注
> 样式相当HTML上标文字
> 书写形式 `[^your words]`

### 代码
这里指单行代码，可以用反引号包起来

```
cat("Hello World!") # print 'Hello World!'
```


## 对于段落
### 换行
> 使用2个以上的空格加回车   
> 或者，使用一个空行来表示一个段落


### 分割线 (separator)
> 一行中3个以上的 * - 或 _ 来表示分割线   
> 行内不能出现其他字符，除了空格



###### 代码块
这里指多行代码。使用4个空格或1个制表符表示
或者，也可以用3个反引号包裹一段代码，同时也可以指定该代码的所用的语言
```
    # This is a snippet in R application 
    function <- output(yourname){
        cat(yourname)
    }
```




###### 列表
无序列表，使用星号，记号或减号作为列表标记，后面要加一个空格，然后才是内容
使用样例 

````
* first item
* second item
* third item

- Assemble Language
- Basic
- C plus plus
- Delphi

````
有序列表，使用数字加句号(.)来表示
使用样例：

1. Hello word!
2. Add 2 numbers
3. If statement
4. loop struction

列表嵌套，只需要在子列表的选项前添加4个空格即可：

1. Hello World!
    - Your first Application
    - The constructe of the code
    - Use build-in function print to output
2. Add 2 numbers
    - Learn the integrate
    - Write a function
    - Output the result
3. Appendix
    - The ASCII table
    - The compiler and linker


###### 引用或称区块
存放的是普通文字。   
使用符号> 开头，后面跟一个空格：

```
> HTML标签按照是否独占一行，可以分为块元素标签和行元素标签， Block and inline element.   
> 按照标签是否成对，或说是否有内容content，可以分为成对标签和孤立标签
> div就是成对的闭合标签，换行br 和水平分割线hr，不闭合，是孤立标签。
```
区块可以嵌套，也可以包含列表，反之亦可。


###### 表格


-----------------------------------
## 多媒体支持
###### 插入图片
使用格式`![optional文字](image_URL optionaTitle)`
也可使用类似于高级链接的方式：


Athena from <sword online> 
[Athena][athenaavator]

[athenaavator]: http://ys-n.ys168.com/600447130/k4K44533K84M73lpimmq/12962442.png




### 加入视频媒体
### 使用HTML标签


# 特色编辑器
- 数学公式
- 流程图

-----------------







********************************************************************

# 参考链接
- [MarkDown CheatSheet 速查表](https://blog.csdn.net/vitaminc4/article/details/75271323) 或者 [英文原文](https://warpedvisions.org/projects/markdown-cheat-sheet/)
- [Markdown-here工具的速查表](https://github.com/adam-p/markdown-here/wiki/Markdown-Cheatsheet)
更多参考文章
- [你要Markdown不要？看完就爱上🎉🎉🎉](https://zhuanlan.zhihu.com/p/127370233)
- [Markdown cheatsheet（个人版本](https://zhuanlan.zhihu.com/p/83649046)



- [Typora](https://sspai.com/post/54912)


-------------------------

markdown如何实现锚点功能
https://blog.csdn.net/wangzhibo666/article/details/88731227
https://www.jianshu.com/p/debd64e591a0

> Markdown style
```
- [测试](#测试)
### <a id="测试">测试</a>
```

> HTML style
```
### <a href="#测试2">测试2</a>
h
t
m
l
<a id="测试2">测试2</a>
```
> Github会自动将Markdown文件中的标题设置成链接，所以只要在浏览模式下，点击标题，地址栏里#后出现的即是锚点，直接用作锚点即可。

https://www.duitang.com/album/?id=87602478&spm=2014.12553688.202.0
https://www.duitang.com/album/?id=88106280&spm=2014.12553688.202.0
https://www.duitang.com/album/?id=70177280&spm=2014.12553688.202.0
https://www.duitang.com/blog/?id=793235017




https://lilinnan.com/sntx/#/mainland



