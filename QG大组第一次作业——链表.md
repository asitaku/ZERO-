# QG大组第一次作业——链表

## 单链表ADT

在该程序中重载了`+`,`=`两个运算符

```c++
List List::operator=(const List& other)//重载=
{
	if (size)
		(*this).clean();//清空防止内存泄漏
	LinkedList now = other.head;
	while (now != NULL)
	{
		(*this).insert(now->data);
		now = now->next;
	}
	size = other.size;
	return (*this);
}

List List::operator+(const List& other)//重载+
{
	LinkedList now = other.head;
	while (now != NULL)
	{
		(*this).insert(now->data);//直接在链表结尾进行添加
		now = now->next;
	}
	size += other.size;
	return (*this);
}
```



### 生成

创建`class LNode`类，通过构造函数进行生成初始化，创建`class List`形成链表，如下：

```c++
typedef class LNode
{
public:
	ElemType data;
	LNode* next = NULL;
	LNode(ElemType nums) :data(nums), next(NULL)
	{
	}
}LNode, * LinkedList;
typedef class List
{
    LinkedList head;
    int size;
}
```

初始化有清零初始化，赋值初始化与拷贝初始化：

<img src="C:\Users\86150\AppData\Roaming\Typora\typora-user-images\image-20220320144128329.png" alt="image-20220320144128329" style="zoom:%;" />

### 删除

可以通过节点排位删除

```c++
void List::detele_pos(int pos)//根据节点位置删除
{
	if (pos == 0)//在第一节点
	{
		if (size == 1)//只有一个LNode
		{
			delete head;
			head = NULL;
			size = 0;
		}
		else
		{
			LinkedList bedel = head;
			head = head->next;
			size--;
			delete bedel;
		}
	}
	else
	{
		LinkedList back = head;
		LinkedList now = head->next;
		for (int i = 0; i < pos - 1; i++)//back到达指定输出节点前一位
		{
			back = back->next;
			now = now->next;
		}
		back->next = now->next;//绕过now
		size--;
		delete now;
	}
}
```
### 插入

```c++
void List::insert(ElemType data)//用于初始化与类相加
{
	if (head == NULL)//如果是空链表就直接添加节点
	{
		head = new LNode(data);
	}
	else
	{
		LinkedList now = head;
		while (now->next != NULL)
			now = now->next;
		now->next = new LNode(data);
	}
	size++;
}

void List::insert(ElemType data, int pos)//相比上一函数能够指定插入节点
{
	if (pos == 0)//在链表头
	{
		LinkedList temp = head;
		head = new LNode(data);
		head->next = temp;
	}
	else if (pos == size)//在尾部
	{
		LinkedList now = head;
		while (now->next != NULL)
		{
			now = now->next;
		}
		now->next = new LNode(data);//在尾部创造新节点
	}
	else//在链表中间
	{
		LinkedList back = head;
		for (int i = 0; i < pos - 1; i++)//到达要插入节点的前一位
		{
			back = back->next;
		}
		LinkedList now = new LNode(data);
		LinkedList next = back->next;
		back->next = now;
		now->next = next;
	}
}
```



### 销毁

```c++
void List::clean()//销毁
{
	LinkedList now = head;
	while (now != NULL)//逐个删除数据
	{
		LinkedList temp = now;
		now = now->next;
		delete temp;
	}
	size = 0;
	head = NULL;//防止head成为野指针
}
```



### 查找

```c++
ElemType List::search(int pos)//比较简单，直接用for函数到达即可
{
	LinkedList now = head;
	for (int i = 0; i < pos; i++)
	{
		now = now->next;
	}
	return now->data;
}
```



### 反转

```c++
void List::reverse()//反转链表
{
	if (head == NULL)//若空链表直接跳出
	{
		return;
	}
	LinkedList back = head;
	LinkedList now = head->next;
	while (now != NULL)
	{
		LinkedList temp = now->next;//创建记录指针
		now->next = back;//将后一位的next指向上一位
		back = now;
		now = temp;//now, back指向后一位
	}
	head->next = NULL;
	head = back;
}
```

### 奇偶调换

```c++
void List::change_oddeven()
{
	LinkedList back = head;
	LinkedList now = head->next;
	head = now;//先确定链表头
	back->next = now->next;
	now->next = back;
	back = back->next;
	now = now->next;
	while (now&&back)//在循环过程中now与back指向的奇偶性不断调换，但总有一个会指向NULL
	{
		LinkedList swap = now;//替换两指针的指向，保证下面代码的可行性
		now = back;
		back = swap;
		LinkedList temp = now->next;
		now->next = temp->next;
		back->next = temp;
		temp->next = now;
		back = temp;
		now = now->next;
	}
}
```







## 双向链表ADT

双向链表ADT与单链表相似，相同之处就不加以解释了。

首先在该程序中重载了`+`,`=`两个运算符

```c++
twiceList twiceList::operator=(const twiceList& other)
{
	if (size)
		(*this).clean();
	LinkedList now = other.head;
	while (now != NULL)
	{
		(*this).insert(now->data);
		now->next->front = now;
		now = now->next;
	}
	size = other.size;
	return (*this);
}

twiceList twiceList::operator+(const twiceList& other)
{
	LinkedList now = other.head;
	LinkedList back = head;
	while (back->next)
		back = back->next;
	now->front = back;
	while (now != NULL)
	{
		(*this).insert(now->data);
		now = now->next;
	}
	size += other.size;
	return (*this);
}
```

然后是类的定义：

```c++
typedef class LNode
{
public:
	LNode* front;
	ElemType data;
	LNode* next;
	LNode(ElemType nums) :front(NULL), data(nums), next(NULL)
	{
	}
}LNode, * LinkedList;
```



### 生成，删除等操作变化不大，只是多考虑了`front`指针的指向

## 总结与思考
  这个周末可以说是过得充实过头了，真的想倒头睡大觉，但后面还有更多的任务要去完成。链表是我比较陌生的领域，这两天最经常碰到的BUG就是访问权限的冲突，最后总算用VS的断点调试过来了，新的一周加油吧。



