#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
struct book
{
	char name[20];
	char writer[20];
	char press[20];
	char time[20];
	double price;
	char NUM[10];
	int num;
};
struct system
{
	struct book* info;
	int maxsize;
	int crusize;

};
struct system* create(int maxsize)
{
	struct system* psystem = (struct system*)malloc(sizeof(struct system));
	if (psystem == NULL)
	{
		printf("�����ڴ�ʧ��");
		exit(0);
		system("pause");
	}
	psystem->maxsize = maxsize;
	psystem->info = (struct book*)malloc(sizeof(struct book) * maxsize);
	psystem->crusize = 0;
	return psystem;
}
//��ӹ���
void enter(struct system* psystem, struct book data)
{
	psystem->info[psystem->crusize++] = data;

}

//�ļ�����
void savefile(struct system* psystem, char* filename)
{
	FILE* fp = fopen(filename, "w");
	for (int i = 0; i < psystem->crusize; i++)
	{
		fprintf(fp, "%-16s%-16s%-16s%-16s%-16.2lf%-16s%-2d\n", psystem->info[i].name,
			psystem->info[i].writer,
			psystem->info[i].press,
			psystem->info[i].time,
			psystem->info[i].price,
			psystem->info[i].NUM,
			psystem->info[i].num);
	}
	fclose(fp);
}

//�ļ���д
void wrfile(struct system* psystem, char* filename)
{
	FILE* fp = fopen(filename, "r");
	if (fp == NULL)
	{
		fp = fopen(filename, "w+");
	}
	struct book data;
	int i = 0;
	while (fscanf(fp, "%s%s%s%s%lf%s%d", data.name, data.writer, data.press, data.time, &data.price, data.NUM, &data.num) != EOF)
	{
		psystem->info[psystem->crusize++] = data;
	}
	fclose(fp);
}

//�������
void print(struct system* psystem)
{
	printf("����\t\t����\t\t������\t\t����ʱ��\t�۸�\t\t������\t\t�ݲ�����\n");
	for (int i = 0; i < psystem->crusize; i++)
	{
		printf("%-16s%-16s%-16s%-16s%-16.2lf%-16s%-2d\n", psystem->info[i].name,
			psystem->info[i].writer,
			psystem->info[i].press,
			psystem->info[i].time,
			psystem->info[i].price,
			psystem->info[i].NUM,
			psystem->info[i].num);
	}
}

//��ѯ����
void search(struct system* psystem)
{
	while (1)
	{
		printf("--------------------------\n");
		printf("-------1.��������ѯ-------\n");
		printf("-------2.�����߲�ѯ-------\n");
		printf("-------3.���۸��ѯ-------\n");
		printf("-------���������ѡ��-----\n");
		printf("--------------------------\n");
		//��������ѯ
		int key;
		scanf("%d", &key);
		if (key == 1)
		{
			printf("������������");
			char n[20];
			scanf("%s", n);
			printf("����\t\t����\t\t������\t\t����ʱ��\t�۸�\t\t������\t\t�ݲ�����\n");
			for (int i = 0; i < psystem->crusize; i++)
			{
				if (strcmp(psystem->info[i].name, n) == 0)
				{
					printf("%-16s%-16s%-16s%-16s%-16.2lf%-16s%-2d\n", psystem->info[i].name,
						psystem->info[i].writer,
						psystem->info[i].press,
						psystem->info[i].time,
						psystem->info[i].price,
						psystem->info[i].NUM,
						psystem->info[i].num);
				}
			}
		}
		//����������ѯ
		else if (key == 2)
		{
			printf("��������������");
			char wn[20];
			scanf("%s", wn);
			printf("����\t\t����\t\t������\t\t����ʱ��\t�۸�\t\t������\t\t�ݲ�����\n");
			for (int i = 0; i < psystem->crusize; i++)
			{
				if (strcmp(psystem->info[i].writer, wn) == 0)
				{
					printf("%-16s%-16s%-16s%-16s%-16.2lf%-16s%-2d\n", psystem->info[i].name,
						psystem->info[i].writer,
						psystem->info[i].press,
						psystem->info[i].time,
						psystem->info[i].price,
						psystem->info[i].NUM,
						psystem->info[i].num);
				}
			}
		}
		//識۸��ѯ
		else if (key == 3)
		{
			printf("1.�����ⶨ�۸����µ���\n");
			printf("2.�����ⶨ�۸����ϵ���\n");
			printf("3.�����ⶨ�۸�֮�����\n");
			printf("�������ѡ��\n");
			int k;
			scanf("%d", &k);
			if (k == 1)
			{
				double j;
				printf("���������ⶨ�ļ۸�:");
				scanf("%lf", &j);
				printf("����\t\t����\t\t������\t\t����ʱ��\t�۸�\t\t������\t\t�ݲ�����\n");
				for (int i = 0; i < psystem->crusize; i++)
				{
					if (psystem->info[i].price <= j)
					{
						printf("%-16s%-16s%-16s%-16s%-16.2lf%-16s%-2d\n", psystem->info[i].name,
							psystem->info[i].writer,
							psystem->info[i].press,
							psystem->info[i].time,
							psystem->info[i].price,
							psystem->info[i].NUM,
							psystem->info[i].num);
					}
				}
			}
			else if (k == 2)
			{
				double j;
				printf("���������ⶨ�ļ۸�:");
				scanf("%lf", &j);
				printf("����\t\t����\t\t������\t\t����ʱ��\t�۸�\t\t������\t\t�ݲ�����\n");
				for (int i = 0; i < psystem->crusize; i++)
				{
					if (psystem->info[i].price >= j)
					{
						printf("%-16s%-16s%-16s%-16s%-16.2lf%-16s%-2d\n", psystem->info[i].name,
							psystem->info[i].writer,
							psystem->info[i].press,
							psystem->info[i].time,
							psystem->info[i].price,
							psystem->info[i].NUM,
							psystem->info[i].num);
					}
				}
			}
			else if (k == 3)
			{
				double j, l;
				printf("���������ⶨ�ļ۸�:");
				scanf("%lf%lf", &j, &l);
				printf("����\t\t����\t\t������\t\t����ʱ��\t�۸�\t\t������\t\t�ݲ�����\n");
				for (int i = 0; i < psystem->crusize; i++)
				{
					if (psystem->info[i].price >= j && psystem->info[i].price <= l)
					{
						printf("%-16s%-16s%-16s%-16s%-16.2lf%-16s%-2d\n", psystem->info[i].name,
							psystem->info[i].writer,
							psystem->info[i].press,
							psystem->info[i].time,
							psystem->info[i].price,
							psystem->info[i].NUM,
							psystem->info[i].num);
					}
				}
			}
		}
		printf("�Ƿ��������,yes or no?\n");
		char m[5] = "";
		scanf("%s", m);
		if (strcmp(m, "no") == 0)
			break;
	}
}

//�޸Ĺ���
void fix(struct system* psystem)
{
	printf("��������Ҫ�޸ĵ��������������룺");
	char s[20];
	scanf("%s", s);
	int flag = 0;
	for (int i = 0; i < psystem->crusize; i++)
	{
		if (strcmp(psystem->info[i].name, s) == 0 || strcmp(psystem->info[i].NUM, s) == 0)
		{
			printf("%-16s%-16s%-16s%-16s%-16.2lf%-16s%-2d\n", psystem->info[i].name,
				psystem->info[i].writer,
				psystem->info[i].press,
				psystem->info[i].time,
				psystem->info[i].price,
				psystem->info[i].NUM,
				psystem->info[i].num);
			printf("���������������ߣ������磬����ʱ�䣬�۸������룬�ݲ�������\n");
			scanf("%s%s%s%s%lf%s%d", psystem->info[i].name,
				psystem->info[i].writer,
				psystem->info[i].press,
				psystem->info[i].time,
				&psystem->info[i].price,
				psystem->info[i].NUM,
				&psystem->info[i].num);
			printf("%-16s%-16s%-16s%-16s%-16.2lf%-16s%-2d\n", psystem->info[i].name,
				psystem->info[i].writer,
				psystem->info[i].press,
				psystem->info[i].time,
				psystem->info[i].price,
				psystem->info[i].NUM,
				psystem->info[i].num);
			flag = 1;
			break;
		}
	}
	if (flag == 0)
		printf("δ�ҵ����飡�������棡\n");
}

//ɾ������
void delete(struct system* psystem)
{
	printf("������ɾ����ʽ\n");
	printf("1.��������������ķ�ʽ����ɾ��\n");
	printf("2.�����߻������ķ�ʽ����ɾ��\n");
	int m = 0;
	scanf("%d", &m);
	if (m == 1)
	{
		printf("�������������������룺");
		char s[20];
		scanf("%s", s);
		for (int i = 0; i < psystem->crusize; i++)
		{
			if (strcmp(psystem->info[i].name, s) == 0)
			{
				for (int j = i; j < psystem->crusize; j++)
				{
					psystem->info[j] = psystem->info[j + 1];
				}
				psystem->crusize--;
				printf("ɾ���ɹ���\n");
				return;
			}
			else if (strcmp(psystem->info[i].NUM, s) == 0)
			{
				for (int j = i; j < psystem->crusize; j++)
				{
					psystem->info[j] = psystem->info[j + 1];
				}
				psystem->crusize--;
				printf("ɾ���ɹ���\n");
				return;
			}
			else if (i == psystem->crusize - 1)
			{
				printf("δ�ҵ�ͼ����Ϣ��ɾ��ʧ�ܣ�\n");
				return;
			}
		}
	}
	if (m == 2)
	{
		printf("���������߻�����磺");
		char g[20] = "";
		scanf("%s", g);
		for (int i = 0; i < psystem->crusize; i++)
		{
			while (strcmp(psystem->info[i].writer, g) == 0 || strcmp(psystem->info[i].press, g) == 0)
			{
				if (strcmp(psystem->info[i].writer, g) == 0 || strcmp(psystem->info[i].press, g) == 0)
				{
					for (int j = i; j < psystem->crusize; j++)
					{
						psystem->info[j] = psystem->info[j + 1];
					}
					psystem->crusize--;
				}
			}
		}
	}
	else
	{
		printf("��������˳�ɾ����\n");
	}
}

//������
void rank(struct system* psystem)

{
	while (1)
	{
		system("cls");
		printf("--------------------------\n");
		printf("-----1.���鱾�۸�����-----\n");
		printf("-----2.������������-------\n");
		printf("-----3.������ʱ������-----\n");
		printf("-----4.���ݲ���������-----\n");
		printf("-----5.��������-----------\n");
		printf("���������ѡ��");
		int e = 0;
		scanf("%d", &e);
		if (e == 2)
		{
			printf("��������������Ϊ��\n");
			for (int i = 0; i < psystem->crusize; i++)
			{
				for (int j = 0; j < psystem->crusize - i - 1; j++)
				{
					if (strcmp(psystem->info[j].NUM, psystem->info[j + 1].NUM) > 0)
					{
						struct book tem = psystem->info[j];
						psystem->info[j] = psystem->info[j + 1];
						psystem->info[j + 1] = tem;
					}
				}
			}
			print(psystem);
		}
		else if (e == 1)
		{
			printf("���۸�ӵ͵��ߵ�������Ϊ��\n");
			for (int i = 0; i < psystem->crusize; i++)
			{
				for (int j = 0; j < psystem->crusize - i - 1; j++)
				{
					if (psystem->info[j].price > psystem->info[j + 1].price)
					{
						struct book tem = psystem->info[j];
						psystem->info[j] = psystem->info[j + 1];
						psystem->info[j + 1] = tem;
					}
				}
			}
			print(psystem);
		}
		else if (e == 3)
		{
			printf("������ʱ����絽��������Ϊ��\n");
			for (int i = 0; i < psystem->crusize; i++)
			{
				for (int j = 0; j < psystem->crusize - i - 1; j++)
				{
					if (strcmp(psystem->info[j].time, psystem->info[j + 1].time) > 0)
					{
						struct book tem = psystem->info[j];
						psystem->info[j] = psystem->info[j + 1];
						psystem->info[j + 1] = tem;
					}
				}
			}
			print(psystem);
		}
		else if (e == 4)
		{
			printf("���ݲ��������ٵ���������Ϊ��\n");
			for (int i = 0; i < psystem->crusize; i++)
			{
				for (int j = 0; j < psystem->crusize - i - 1; j++)
				{
					if (psystem->info[j].num > psystem->info[j + 1].num)
					{
						struct book tem = psystem->info[j];
						psystem->info[j] = psystem->info[j + 1];
						psystem->info[j + 1] = tem;
					}
				}
			}
			print(psystem);
		}
		else if (e == 5)
			return;
		else
		{
			print("������󣡷������棡\n");
			return;
		}
		system("pause");
	}
}


//ͳ�ƹ���
void  sta(struct system* psystem)
{
	printf("1.ͳ��ͼ��ݲ��������µ�����\n");
	printf("2.ͳ�Ƴ�����������ĳ���ڵ�ͼ��\n");
	printf("���������ѡ��");
	int q;
	scanf("%d", &q);
	if (q == 1)
	{
		int v, n = 0;
		printf("����������ͳ��ͼ��ݲ������������µ�ͼ�飺");
		scanf("%d", &v);
		printf("����\t\t����\t\t������\t\t����ʱ��\t�۸�\t\t������\t\t�ݲ�����\n");
		for (int i = 0; i < psystem->crusize; i++)
		{
			if (psystem->info[i].num <= v)
			{
				printf("%-16s%-16s%-16s%-16s%-16.2lf%-16s%-2d\n", psystem->info[i].name,
					psystem->info[i].writer,
					psystem->info[i].press,
					psystem->info[i].time,
					psystem->info[i].price,
					psystem->info[i].NUM,
					psystem->info[i].num);
				n++;
			}
		}
		printf("�ݲ�����%d���µ�ͼ����%d��\n", v, n);
	}
	else if (q == 2)
	{
		char v[20], n = 0;
		printf("����������ͳ�Ƴ����������ں�ʱ��ͼ�飺");
		scanf("%s", v);
		printf("����\t\t����\t\t������\t\t����ʱ��\t�۸�\t\t������\t\t�ݲ�����\n");
		for (int i = 0; i < psystem->crusize; i++)
		{
			if (strcmp(psystem->info[i].time, v) < 0)
			{
				printf("%-16s%-16s%-16s%-16s%-16.2lf%-16s%-2d\n", psystem->info[i].name,
					psystem->info[i].writer,
					psystem->info[i].press,
					psystem->info[i].time,
					psystem->info[i].price,
					psystem->info[i].NUM,
					psystem->info[i].num);
				n++;
			}
		}
		printf("������������%s��ͼ�鹲��%d��\n", v, n);
	}
	else
	{
		printf("��������˳�ͳ�ƣ�\n");
		return;
	}
}

//�˵�
void menu()
{
	printf("                                            ----------��ͼ�����ϵͳ��-------\n");
	printf("                                            ---------------------------------\n");
	printf("                                            -----------0.�˳�ϵͳ------------\n");
	printf("                                            -----------1.��ӹ���------------\n");
	printf("                                            -----------2.�������------------\n");
	printf("                                            -----------3.��ѯ����------------\n");
	printf("                                            -----------4.�޸Ĺ���----------- \n");
	printf("                                            -----------5.ɾ������------------\n");
	printf("                                            -----------6.������----------- \n");
	printf("                                            -----------7.ͳ�ƹ���----------- \n");
	printf("                                            -------------------------------- \n");
	printf("                                            ���������� 1-7 ʵ��������Ҫ�Ĺ���\n");
}

//��¼����
void login()
{
	printf("\t\t����ӭ����ͼ�����ϵͳ��\n");
	printf("\t\t�û�����");
	char user[20] = "";
	scanf("%s", user);
	printf("\t\t���룺");
	char pass[7] = "";
	int usk = 0;
	int i = 0;
	while ((usk = getch()) != '\r')
	{
		pass[i++] = usk;
		putchar('*');
	}
	if (strcmp(user, "���ֽ���") == 0 && strcmp(pass, "123456") == 0)
	{
		printf("\n");
		printf("��¼�ɹ���\n");
	}
	else
	{
		printf("\n");
		printf("\t\t�û�����������󣡵�¼ʧ�ܣ�\n");
		printf("\t\t�˳�ϵͳ��\n");
		system("pause");
		exit(0);
	}
}

//���������
void enterkey(struct system* psystem)
{
	int key;
	struct book data;
	scanf("%d", &key);
	switch (key)
	{
	case 0:
		exit(0);
		break;
	case 1:
		printf("-----------1.��ӹ���------------\n");
		system("cls");
		printf("����������Ҫ��Ӽ���ͼ�����Ϣ��");
		int x;
		scanf("%d", &x);
		printf("���������������ߣ������磬����ʱ�䣬�۸������룬�ݲ�������\n");
		for (int i = 0; i < x; i++)
		{
			printf("�������%d��ͼ�����Ϣ��\n", i + 1);
			scanf("%s%s%s%s%lf%s%d", data.name, data.writer, data.press, data.time, &data.price, data.NUM, &data.num);
			enter(psystem, data);
		}
		savefile(psystem, "bookinfo.text");
		break;
	case 2:
		printf("-----------2.�������------------\n");
		system("cls");
		print(psystem);
		break;
	case 3:
		printf("-----------3.��ѯ����------------\n");
		system("cls");
		search(psystem);
		break;
	case 4:
		printf("-----------4.�޸Ĺ���----------- \n");
		system("cls");
		fix(psystem);
		savefile(psystem, "bookinfo.text");
		break;
	case 5:
		printf("-----------5.ɾ������------------\n");
		system("cls");
		printf("��������Ҫɾ�����������������룺");
		delete(psystem);
		savefile(psystem, "bookinfo.text");
		break;
	case 6:
		printf("-----------6.������----------- \n");
		system("cls");
		rank(psystem);
		break;
	case 7:
		printf("-----------7.ͳ�ƹ���----------- \n");
		system("cls");
		sta(psystem);
		break;
	default:
		printf("put error\n");
		break;
	}
}

int main()
{
	//login();
	system("cls");
	struct system* psystem = create(100);
	wrfile(psystem, "bookinfo.text");
	while (1)
	{
		system("color 79");
		menu();
		enterkey(psystem);
		system("pause");
		system("cls");
	}
	return 0;
}