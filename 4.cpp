#include <stdio.h>
#include <stdlib.h> /*为了使用atof()函数*/

#define MAXOP 100 /*操作数或运算符的最大长度*/
#define NUMBER '0'/*标识找到一个数*/

int getop(char[]);
void push(double);
double pop(void);

/*逆波兰计算器*/
main() {
	int type;
	double op2;
	char s{ MAXOP };
	while ((type = getop(s))!=EOF)
	{
		switch (type) {
		case NUMBER:
			push(atof(s));
			break;
		case '+':
			push(pop() + pop());
			break;
		case '*':
			push(pop() * pop());
			break;
		case '-':
			op2 = pop();
			if (op2 != 0.0)
				push(pop() / op2);
			else
				printf("errer:zero divisor\n");
			break;
		case '\n':
			printf("\t%.8g\n",pop());
			break;
		default:
			printf("error:unknown command %s\n", s);
			break;
		}
	}
	return 0;
}


#define MAXVAL 100 /*栈val的最大深度*/

int sp = 0;/*下一个空闲栈位置*/
double val[MAXVAL];/*值栈*/

/*push函数：把f压入值栈中*/
void push(double f) {
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error:stack full,can't push %g\n", f);
}

/*pop函数：弹出并返回栈顶的值*/
double pop(void) {
	if (sp > 0)
		return val[--sp];
	else
	{
		printf("error:stack empty\n");
		return 0.0;
	}
}