#include "LinkStack.h" 
//链栈

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
					int num1 = num.getTopLStack();
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

	while (!ope.isEmptyLStack())
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
		ope.popLStack();
	}
	return num.getTopLStack();
}

void CalculateForUser()
{
	cout << "请输入希望求解的算式：" << endl;
	int answer = calculator();
	cout << "答案为：" << answer << endl;
}


void show_Menu()
{
	cout << "**************************************************************" << endl;
	cout << "**************欢迎来到QG第二次大组作业链栈!****************" << endl;
	cout << "**********************请输入需要进行的操作：********************" << endl;
	cout << "********************1.入栈*********************************" << endl;
	cout << "********************2.出栈*********************************" << endl;
	cout << "********************3.得到栈顶元素*********************************" << endl;
	cout << "********************4.清空链栈*********************************" << endl;
	//cout << "********************5.销毁链栈*********************************" << endl;
	cout << "********************5.计算器模式*********************************" << endl;
	cout << "********************6.更换链栈类型*********************************" << endl;
	cout << "********************0.退出程序*********************************" << endl;
	cout << "**************************************************************" << endl;
}