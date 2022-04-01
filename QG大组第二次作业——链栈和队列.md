# QG大组第二次作业

## 链栈

* 通过构造函数初始化

  ```c++
  StackNode(T data) :data(data), next(NULL)//初始化节点
  	{
  	}
  LinkStack()//初始化栈
  	{
  		this->count = 0;
  		this->top = NULL;
  	}
  ```

  

在程序中，有入栈，出栈，清空栈，得到栈顶元素，计算器模式，更换链栈类型，退出程序，其中使用了模板，后面一直报LNK2019的错误，要把声明与定义都放在同一个.h文件解决。销毁链栈暂时还不会，就没写。

* 入栈无什么特别，是创建一个新节点，下一项指向top，再让top指向新节点

  ```c++
  void pushLStack(const T& data)//入栈
  	{
  		if (top == NULL)
  		{
  			top = new StackNode<T>(data);
  		}
  		else
  		{
  			StackNode<T>* now = new StackNode<T>(data);
  			now->next = top;
  			top = now;
  		}
  		count++;
  	}
  ```

* 出栈要判断是否为空

  ```c++
  Status popLStack()//出栈
  	{
  		if (isEmptyLStack())
  		{
  			return ERROR;
  		}
  		StackNode<T>* now = top;
  		top = top->next;
  		delete now;
  		return SUCCESS;
  	}
  ```

* 清空链栈，使用出栈的返回值判断是否继续出栈，直到链栈为空

  ```c++
  void clearLStack()//清空栈
  	{
  		if (isEmptyLStack())
  		{
  			cout << "该链栈为空！" << endl;
  			return;
  		}
  		while (popLStack());
  		cout << "清空完毕" << endl;
  	}
  ```

* 得到链栈元素，将判断空链栈与返回元素分开，方便之后获得栈顶元素

  ```c++
  T& getTopLStack()//得到栈顶元素
  	{
  		return top->data;
  	}
  
  void getTop()//返回元素
  {
      if (isEmptyLStack())
      {
          cout << "该链栈为空！" << endl;
          return;
      }
      cout << getTopLStack() << endl;
  }
  ```

* 计算机模式，创建两个链栈，一个储存数字，一个储存运算符

  ```c++
  int calculator()
  {
  	LinkStack<char> ope;
  	LinkStack<int> num;
  	string str;
  	cin >> str;
  	for (int i = 0; i < (int)str.size(); i++)
  	{
  		if (str[i] >= '0' && str[i] <= '9')
  			num.pushLStack(str[i] - '0');
  		else
  		{
  			if (ope.isEmptyLStack())
  				ope.pushLStack(str[i]);
  			else
  			{
  				if (((int)ope.getTopLStack() == (42 | 47)) || (((int)ope.getTopLStack() == (43 | 45)) && ((int)str[i] == (43 | 45))))//对应ASCII码：*42，+43，-45，/47
  				{//当是同级运算符或者将要加入的比已在运算符链栈顶部的高级时先计算已在栈内的运算符
  					int num1 = num.getTopLStack();//让两个栈顶元素进行计算
  					num.popLStack();
  					int num2 = num.getTopLStack();
  					num.popLStack();
  					switch (ope.getTopLStack())
  					{
  					case '+':
  						num.pushLStack(num1 + num2);
  						break;
  					case'-':
  						num.pushLStack(num2 - num1);
  						break;
  					case'*':
  						num.pushLStack(num1 * num2);
  						break;
  					case '/':
  						num.pushLStack(num2 / num1);
  						break;
  					default:
  						break;
  					}
  					ope.popLStack();
  				}
  				ope.pushLStack(str[i]);
  			}
  		}
  	}
  
  	while (!ope.isEmptyLStack())//运算符链栈内还有剩余，直接进行正常运算
  	{
  		int num1 = num.getTopLStack();
  		num.popLStack();
  		int num2 = num.getTopLStack();
  		num.popLStack();
  		switch (ope.getTopLStack())
  		{
  		case '+':
  			num.pushLStack(num1 + num2);
  			break;
  		case '-':
  			num.pushLStack(num2 - num1);
  			break;
  		case '*':
  			num.pushLStack(num1 * num2);
  			break;
  		case '/':
  			num.pushLStack(num2 / num1);
  			break;
  		default:
  			break;
  		}
  		ope.popLStack();//删除运算符链栈顶，进行下一步运算，直到运算符链栈为空
  	}
  	return num.getTopLStack();
  }
  ```

* 通过用户输入，建立不同数据类型的链栈

  ```c++
  while (true)
  		{
  			cout << "现创建链栈以完成操作：" << endl;
  			cout << "需要什么类型的链栈：" << endl
  				<< "1.整数\t2.字符\t3.小数" << endl;
  			cin >> typeselect;
  			if (typeselect >= 1 && typeselect <= 3)
  			{
  				break;
  			}
  			cout << "输入有误！请重新输入。" << endl;
  		}
  		if (typeselect == 1)
  		{
  			LinkStack<int> a;
  			FaceUser(a);
  		}
  		else if (typeselect == 2)
  		{
  			LinkStack<char> b;
  			FaceUser(b);
  		}
  		else if (typeselect == 3)
  		{
  			LinkStack<float> c;
  			FaceUser(c);
  		}
  ```

  

## 队列

​	一开始在void*那里花了许多时间，想办法在同一个队列中放不同数据类型，后来也是做到了。

```c++
class Node
{
public:
    void* data;                   //数据域指针
    Node* next;                   //指向当前结点的下一结点
    int datatype;//每次创建新节点时确定数据类型，1char，2int，3float
    Node(void* data, int datatype) : data(data), next(NULL), datatype(datatype)
    {
    }
};
class LQueue
{
public:
    Node* front;                   //队头
    Node* rear;                    //队尾
    int length;            //队列长度

    LQueue();//构造函数初始化
    //void DestoryLQueue();不知道怎么销毁类
    Status IsEmptyLQueue();//判断是否为空
    Node* GetHeadLQueue();//获取队头
    Status LengthLQueue();//检测队列长度
    Status EnLQueue(void* data, int datatype);//入队
    Status DeLQueue();//出队
    void ClearLQueue();//清空队列
    Status TraverseLQueue();//遍历，不知道怎么表现，此处通过打印
    void LPrint();//打印所有数据
    void NPrint(Node* node);//打印单个数据
    void AddNode();//面向用户的入队操作
};// LQueue;

void show_LQueue_Menu();
```

* 比较特别的是，打印

  ```c++
  void LQueue::LPrint()//打印所有数据
  {
  	if (IsEmptyLQueue())
  	{
  		std::cout << "该队列为空！" << endl;
  		return;
  	}
  	Node* now = front;
  	while (now)
  	{
  		if (now->datatype == 1)
  		{
  			string* stringdata = static_cast<string*>(now->data);
  			cout << *stringdata << ' ';
  		}
  		else if (now->datatype == 2)
  		{
  			int* intdata = static_cast<int*>(now->data);
  			cout << *intdata << ' ';
  		}
  		else if (now->datatype == 3)
  		{
  			float* floatdata = static_cast<float*>(now->data);
  			cout << *floatdata << ' ';
  		}
  		now = now->next;
  	}
  	std::cout << endl;
  }
  ```

  

## 小结

​	很抱歉这么迟交，因为总有事情接二连三地出现，在学习以上两个知识点时，总能遇上难搞的ERROR，没见过的ERROR，直到最后有些操作也无法完成，不过基本的都还行，希望以后能更快更强，学到更多。