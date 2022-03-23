# QG图形组第一次作业——完成一个正六边形

* 我是成功初始化DX11后，copy了X_Jun的代码，通过修改参数实现的（毕竟让我自己去码的话，我也只是将源代码照打下来，哈哈）。不过简单的运行逻辑我还是明白了——我修改的有三处，一个是程序运行时创建的窗口大小，我把它改成了正方形（长720，宽720）。

* 在d3dApp.cpp里的25，26行可设定

  ```c++
  	m_ClientWidth(720),//之前好像是长1024
  	m_ClientHeight(720),
  ```

* 然后是GameApp.cpp(好像主要是通过编写GameApp的两个文件来实现项目的)，原本示例代码是绘制三角形的，所以是在源码中是绘制三个点

```c++
m_pd3dImmediateContext->Draw(3, 0);//意味绘制三个点
```

* 我一开始是修改为12的，因为我发现现在图元类型好像是三角形，所以需要用十二个点绘制四个三角形实现，则：

```c++
m_pd3dImmediateContext->Draw(12, 0);//绘制12个点
```

* 然后告诉计算机要在哪画点，还有用什么颜色渲染

  ```c++
  // 设置六边形顶点
  	VertexPosColor vertices[] =
  	{
  		{ XMFLOAT3(0.0f, 1.0f, 0.5f), XMFLOAT4(5.0f, 0.0f, 0.0f, 1.0f) },
  		{ XMFLOAT3(sqrt(3.0) / 2.0f, 0.5f, 0.5f), XMFLOAT4(0.0f, 0.0f, 1.0f, 1.0f) },
  		{ XMFLOAT3(-sqrt(3.0) / 2.0f, 0.5f, 0.5f), XMFLOAT4(0.0f, 1.0f, 0.0f, 1.0f) },
  		{ XMFLOAT3(-sqrt(3.0) / 2.0f, -0.5f, 0.5f), XMFLOAT4(1.0f, 1.0f, 0.0f, 1.0f) },
  		{ XMFLOAT3(sqrt(3.0) / 2.0f, -0.5f, 0.5f), XMFLOAT4(1.0f, 0.0f, 1.0f, 1.0f) },
  		{ XMFLOAT3(0.0f, -1.0f, 0.5f), XMFLOAT4(1.0f, 1.0f, 1.0f, 0.0f) },
  		{ XMFLOAT3(-sqrt(3.0) / 2.0f, 0.5f, 0.5f), XMFLOAT4(1.0f, 0.0f, 0.0f, 1.0f) },
  		{ XMFLOAT3(sqrt(3.0) / 2.0f, 0.5f, 0.5f), XMFLOAT4(0.0f, 0.0f, 1.0f, 1.0f) },
  		{ XMFLOAT3(sqrt(3.0) / 2.0f, -0.5f, 0.5f), XMFLOAT4(0.0f, 1.0f, 0.0f, 1.0f) },
  		{ XMFLOAT3(-sqrt(3.0) / 2.0f, 0.5f, 0.5f), XMFLOAT4(1.0f, 1.0f, 0.0f, 1.0f) },
  		{ XMFLOAT3(sqrt(3.0) / 2.0f, -0.5f, 0.5f), XMFLOAT4(1.0f, 0.0f, 1.0f, 1.0f) },
  		{ XMFLOAT3(-sqrt(3.0) / 2.0f, -0.5f, 0.5f), XMFLOAT4(1.0f, 1.0f, 1.0f, 0.0f) }
  	};//XMFLOAT3是用来确定位置的(x, y, z),窗口中间是原点，x,y不用说，表示横轴纵轴，z表示深度值，这个项目暂时不需要考虑，x,y大小范围在[-0.1f, 0.1f]内，超出就会看到绘制的图形到窗口之外（是指看不到超出的部分）；XMFLOAT4是用来确定颜色的(a, b, c, d)，a是红色，b是绿色，c是蓝色，d是黑色，改变数值可以混合成其他颜色，
  ```

  图元类型 三角形

  ```c++
  m_pd3dImmediateContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
  ```

  * 然后实现

![屏幕截图 2022-03-23 171839](C:\Users\86150\Desktop\屏幕截图 2022-03-23 171839.png)

然后想到了图元类型（我理解成点之间的连接装配方式）应该不止一种，然后选中IASetPrimitiveTopology函数的参数查看定义，之后就找到了应该是绘制多边形的参数

```c++
m_pd3dImmediateContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP);
```

不过它要求的绘制点的顺序和三角形的顺时针有点不一样，试了一会才搞好

```c++
VertexPosColor vertices[] =
	{
		{ XMFLOAT3(0.0f, 1.0f, 0.5f), XMFLOAT4(1.0f, 0.0f, 0.0f, 0.0f) },
		{ XMFLOAT3(sqrt(3.0) / 2.0f, 0.5f, 0.5f), XMFLOAT4(0.0f, 0.0f, 1.0f, 1.0f) },
		{ XMFLOAT3(-sqrt(3.0) / 2.0f, 0.5f, 0.5f), XMFLOAT4(0.0f, 1.0f, 0.0f, 1.0f) },
		{ XMFLOAT3(sqrt(3.0) / 2.0f, -0.5f, 0.5f), XMFLOAT4(1.0f, 0.0f, 1.0f, 1.0f) },
		{ XMFLOAT3(-sqrt(3.0) / 2.0f, -0.5f, 0.5f), XMFLOAT4(1.0f, 1.0f, 0.0f, 1.0f) },
		{ XMFLOAT3(0.0f, -1.0f, 0.5f), XMFLOAT4(1.0f, 1.0f, 1.0f, 0.0f) }//我的理解是先画了一个三角形，然后再由上到下，由右到左确定下面要渲染的区域
	};
```

![屏幕截图 2022-03-23 173317](C:\Users\86150\Desktop\屏幕截图 2022-03-23 173317.png)

测试了一下确实如此

![屏幕截图 2022-03-23 180106](C:\Users\86150\Desktop\屏幕截图 2022-03-23 180106.png)



# 小结

​	在不断debug的过程中，我了解到了顶点与像素着色器的创建是通过HLSL语法，将信息传入顶点着色器进行设置，当然具体我也还不懂，查看定义知道了更多，断点调试是真的有用特别在大项目里，渲染管线也了解了不少，嗯就这些。