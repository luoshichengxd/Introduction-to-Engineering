#include<stdio.h>
#define NUM 100

//设置数据类型
struct _resistance{
	int val;
	int num;
	int cost;
};
typedef struct _resistance resistance;									//电阻

struct _capacitance{
	int val;
	int num;
	int cost;
};
typedef struct _capacitance capacitance;									//电容

struct _substance{
	resistance re;
	capacitance ca;
};
typedef struct _substance substance;

struct _output{
	int re;
	int ca;
};
typedef struct _output output;

substance g_sub;															//声明全局变量 用于存放数据
output g_out;

void choice_1(char *choice)
{
	puts("\n");
	puts("Please input according to the tip,");
	puts("Put in a char once and press Enter to verify:\n");

	char garbage;														//读入选项 
	scanf("%c", choice);													//排除回车键的干扰
	scanf("%c", &garbage);												//进行错误处理 

	while (garbage != '\n' || *choice > 'G' || *choice < 'A'){
		puts("Error!");
		puts("Please input according to the tip,");
		puts("Put in a char once and press Enter to verify:\n");			//读入选项 
		scanf("%c", choice);												//排除回车键的干扰
		scanf("%c", &garbage);
	}

	return;
}

void choice_2(char *choice)
{
	puts("\n");
	puts("Please input according to the tip,");
	puts("Put in a char once and press Enter to verify:\n");

	char garbage;														//读入选项 
	scanf("%c", choice);													//排除回车键的干扰
	scanf("%c", &garbage);												//进行错误处理 

	while (garbage != '\n' || *choice > 'B' || *choice < 'A'){
		puts("Error!");
		puts("Please input according to the tip,");
		puts("Put in a char once and press Enter to verify:\n");			//读入选项 
		scanf("%c", choice);												//排除回车键的干扰
		scanf("%c", &garbage);
	}

	return;
}

void getnumber(int* number)
{
	puts("\n");
	puts("Please input according to the tip,");
	puts("Put in a char once and press Enter to verify:\n");

	char garbage;			
	scanf("%d", number);													//读入数字 
	scanf("%c", &garbage);												//排除回车键的干扰

	while (garbage != '\n'){												//进行错误处理
		puts("Error!");
		puts("Please input according to the tip,");
		puts("Put in a char once and press Enter to verify:\n");
		scanf("%d", number);												//读入数字 
		scanf("%c", &garbage);											//跳过回车
	}

	return;
}

void initial(void)
{
	g_sub.ca.num = NUM;													//初始化数量
	g_sub.re.num = NUM;

	g_sub.ca.cost = 1;													//初始化价格
	g_sub.re.cost = 2;

	g_sub.re.val = 10;													//初始化阻值和法拉
	g_sub.ca.val = 1;

	return;
}

void A(void)																//电子元器件的入库
{
	char choice;
	int number;

	puts("\n");
	puts(" A: Resistance\n B: Capacitance\n");
	choice_2(&choice);
	getnumber(&number);													//增加的元器件数

	if (choice == 'A')
		g_sub.re.num += number;
	else
		g_sub.ca.num += number;

	puts("Put in storage successfully!\n");
	return;
}

void B(void)																//电子元器件的出库
{
	char choice;
	int number;

	puts("\n");
	puts(" A: Resistance\n B: Capacitance");
	choice_2(&choice);
	getnumber(&number);													//减少的元器件数

	if (choice == 'A'){
		g_sub.re.num -= number;
		g_out.re += number;
	}
	else{
		g_sub.ca.num -= number;
		g_out.ca += number;
	}

	puts("Out of storage successfully!\n");
	return;
}

void C()																	//库元器件总价值查看
{
	puts("\n");

	printf(" Resistance: %d yuan\n Capacitance: %d yuan\n Total price: %d yuan\n",
		g_sub.re.num * g_sub.re.cost,
		g_sub.ca.num * g_sub.ca.cost,
		g_sub.re.num * g_sub.re.cost + g_sub.ca.num * g_sub.ca.cost);

	return;
}

void D()																	//出库元器件总价值查看
{
	puts("\n");

	printf(" Resistance: %d yuan\n Capacitance: %d yuan\n Total price: % yuan\n",
		g_out.re * g_sub.re.num,
		g_out.ca * g_sub.ca.cost,
		g_out.re * g_sub.re.cost + g_out.ca * g_sub.ca.cost);

	return;
}

void E()																	//电阻信息查看
{
	puts("\n");

	printf("Number: %d \n Per price: %d yuan\n Resistance: %d OMEGA\n Total price: %d yuan\n",
		g_sub.re.num,
		g_sub.re.cost,
		g_sub.re.val,
		g_sub.re.num * g_sub.re.cost);

	return;

}



void F()																	//电容信息查看
{
	puts("\n");

	printf("Number: %d \n Per price: %d yuan\n Resistance: %d OMEGA\n Total price: %d yuan\n",
		g_sub.ca.num,
		g_sub.ca.cost,
		g_sub.ca.val,
		g_sub.ca.num * g_sub.ca.cost);

	return;

}

void menu(void)
{
	puts("***********************************************");
	puts("A: Warehousing of electronic components\n");
	puts("B: Storage of electronic components\n");
	puts("C: View the total value of library components\n");
	puts("D: Check the total value of storage components\n");
	puts("E: Resistance information view\n");
	puts("F: View resistor information view capacitor information\n");
	puts("G: Exit.\n");

	return;
}
int main(void)
{
	char choice;
	initial();
	while (1){
		menu();															//菜单 
		choice_1(&choice);
		switch (choice){													//选择任务
			case 'A':
				A();
				break;
			case 'B':
				B();
				break;
			case 'C':
				C();
				break;
			case 'D':
				D();
				break;
			case 'E':
				E();
				break;
			case 'F':
				F();
				break;
		}
		if (choice == 'G')												//退出
			break;
	}

	return 0;
}


/*
工程概论 电子元器件
史家卓 18010100339
程正雄 18010100426
罗代树 18010500062
*/