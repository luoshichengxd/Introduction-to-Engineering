#include<stdio.h>
#define NUM 100

//������������
struct _resistance{
	int val;
	int num;
	int cost;
};
typedef struct _resistance resistance;									//����

struct _capacitance{
	int val;
	int num;
	int cost;
};
typedef struct _capacitance capacitance;									//����

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

substance g_sub;															//����ȫ�ֱ��� ���ڴ������
output g_out;

void choice_1(char *choice)
{
	puts("\n");
	puts("Please input according to the tip,");
	puts("Put in a char once and press Enter to verify:\n");

	char garbage;														//����ѡ�� 
	scanf("%c", choice);													//�ų��س����ĸ���
	scanf("%c", &garbage);												//���д����� 

	while (garbage != '\n' || *choice > 'G' || *choice < 'A'){
		puts("Error!");
		puts("Please input according to the tip,");
		puts("Put in a char once and press Enter to verify:\n");			//����ѡ�� 
		scanf("%c", choice);												//�ų��س����ĸ���
		scanf("%c", &garbage);
	}

	return;
}

void choice_2(char *choice)
{
	puts("\n");
	puts("Please input according to the tip,");
	puts("Put in a char once and press Enter to verify:\n");

	char garbage;														//����ѡ�� 
	scanf("%c", choice);													//�ų��س����ĸ���
	scanf("%c", &garbage);												//���д����� 

	while (garbage != '\n' || *choice > 'B' || *choice < 'A'){
		puts("Error!");
		puts("Please input according to the tip,");
		puts("Put in a char once and press Enter to verify:\n");			//����ѡ�� 
		scanf("%c", choice);												//�ų��س����ĸ���
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
	scanf("%d", number);													//�������� 
	scanf("%c", &garbage);												//�ų��س����ĸ���

	while (garbage != '\n'){												//���д�����
		puts("Error!");
		puts("Please input according to the tip,");
		puts("Put in a char once and press Enter to verify:\n");
		scanf("%d", number);												//�������� 
		scanf("%c", &garbage);											//�����س�
	}

	return;
}

void initial(void)
{
	g_sub.ca.num = NUM;													//��ʼ������
	g_sub.re.num = NUM;

	g_sub.ca.cost = 1;													//��ʼ���۸�
	g_sub.re.cost = 2;

	g_sub.re.val = 10;													//��ʼ����ֵ�ͷ���
	g_sub.ca.val = 1;

	return;
}

void A(void)																//����Ԫ���������
{
	char choice;
	int number;

	puts("\n");
	puts(" A: Resistance\n B: Capacitance\n");
	choice_2(&choice);
	getnumber(&number);													//���ӵ�Ԫ������

	if (choice == 'A')
		g_sub.re.num += number;
	else
		g_sub.ca.num += number;

	puts("Put in storage successfully!\n");
	return;
}

void B(void)																//����Ԫ�����ĳ���
{
	char choice;
	int number;

	puts("\n");
	puts(" A: Resistance\n B: Capacitance");
	choice_2(&choice);
	getnumber(&number);													//���ٵ�Ԫ������

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

void C()																	//��Ԫ�����ܼ�ֵ�鿴
{
	puts("\n");

	printf(" Resistance: %d yuan\n Capacitance: %d yuan\n Total price: %d yuan\n",
		g_sub.re.num * g_sub.re.cost,
		g_sub.ca.num * g_sub.ca.cost,
		g_sub.re.num * g_sub.re.cost + g_sub.ca.num * g_sub.ca.cost);

	return;
}

void D()																	//����Ԫ�����ܼ�ֵ�鿴
{
	puts("\n");

	printf(" Resistance: %d yuan\n Capacitance: %d yuan\n Total price: % yuan\n",
		g_out.re * g_sub.re.num,
		g_out.ca * g_sub.ca.cost,
		g_out.re * g_sub.re.cost + g_out.ca * g_sub.ca.cost);

	return;
}

void E()																	//������Ϣ�鿴
{
	puts("\n");

	printf("Number: %d \n Per price: %d yuan\n Resistance: %d OMEGA\n Total price: %d yuan\n",
		g_sub.re.num,
		g_sub.re.cost,
		g_sub.re.val,
		g_sub.re.num * g_sub.re.cost);

	return;

}



void F()																	//������Ϣ�鿴
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
		menu();															//�˵� 
		choice_1(&choice);
		switch (choice){													//ѡ������
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
		if (choice == 'G')												//�˳�
			break;
	}

	return 0;
}


/*
���̸��� ����Ԫ����
ʷ��׿ 18010100339
������ 18010100426
�޴��� 18010500062
*/