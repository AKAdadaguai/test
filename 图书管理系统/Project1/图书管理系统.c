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
		printf("申请内存失败");
		exit(0);
		system("pause");
	}
	psystem->maxsize = maxsize;
	psystem->info = (struct book*)malloc(sizeof(struct book) * maxsize);
	psystem->crusize = 0;
	return psystem;
}
//添加功能
void enter(struct system* psystem, struct book data)
{
	psystem->info[psystem->crusize++] = data;

}

//文件保存
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

//文件读写
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

//浏览功能
void print(struct system* psystem)
{
	printf("书名\t\t作者\t\t出版社\t\t出版时间\t价格\t\t条形码\t\t馆藏数量\n");
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

//查询功能
void search(struct system* psystem)
{
	while (1)
	{
		printf("--------------------------\n");
		printf("-------1.按书名查询-------\n");
		printf("-------2.按作者查询-------\n");
		printf("-------3.按价格查询-------\n");
		printf("-------请输入你的选择-----\n");
		printf("--------------------------\n");
		//按书名查询
		int key;
		scanf("%d", &key);
		if (key == 1)
		{
			printf("请输入书名：");
			char n[20];
			scanf("%s", n);
			printf("书名\t\t作者\t\t出版社\t\t出版时间\t价格\t\t条形码\t\t馆藏数量\n");
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
		//按作者名查询
		else if (key == 2)
		{
			printf("请输入作者名：");
			char wn[20];
			scanf("%s", wn);
			printf("书名\t\t作者\t\t出版社\t\t出版时间\t价格\t\t条形码\t\t馆藏数量\n");
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
		//铵价格查询
		else if (key == 3)
		{
			printf("1.查找拟定价格以下的书\n");
			printf("2.查找拟定价格以上的书\n");
			printf("3.查找拟定价格之间的书\n");
			printf("输入你的选择：\n");
			int k;
			scanf("%d", &k);
			if (k == 1)
			{
				double j;
				printf("请输入你拟定的价格:");
				scanf("%lf", &j);
				printf("书名\t\t作者\t\t出版社\t\t出版时间\t价格\t\t条形码\t\t馆藏数量\n");
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
				printf("请输入你拟定的价格:");
				scanf("%lf", &j);
				printf("书名\t\t作者\t\t出版社\t\t出版时间\t价格\t\t条形码\t\t馆藏数量\n");
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
				printf("请输入你拟定的价格:");
				scanf("%lf%lf", &j, &l);
				printf("书名\t\t作者\t\t出版社\t\t出版时间\t价格\t\t条形码\t\t馆藏数量\n");
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
		printf("是否继续查找,yes or no?\n");
		char m[5] = "";
		scanf("%s", m);
		if (strcmp(m, "no") == 0)
			break;
	}
}

//修改功能
void fix(struct system* psystem)
{
	printf("输入你想要修改的书名或者条形码：");
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
			printf("请输入书名，作者，出版社，出版时间，价格，条形码，馆藏数量：\n");
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
		printf("未找到该书！返回桌面！\n");
}

//删除功能
void delete(struct system* psystem)
{
	printf("请输入删除方式\n");
	printf("1.以书名或条形码的方式单本删除\n");
	printf("2.以作者或出版社的方式集体删除\n");
	int m = 0;
	scanf("%d", &m);
	if (m == 1)
	{
		printf("请输入书名或者条形码：");
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
				printf("删除成功！\n");
				return;
			}
			else if (strcmp(psystem->info[i].NUM, s) == 0)
			{
				for (int j = i; j < psystem->crusize; j++)
				{
					psystem->info[j] = psystem->info[j + 1];
				}
				psystem->crusize--;
				printf("删除成功！\n");
				return;
			}
			else if (i == psystem->crusize - 1)
			{
				printf("未找到图书信息！删除失败！\n");
				return;
			}
		}
	}
	if (m == 2)
	{
		printf("请输入作者或出版社：");
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
		printf("输入错误！退出删除！\n");
	}
}

//排序功能
void rank(struct system* psystem)

{
	while (1)
	{
		system("cls");
		printf("--------------------------\n");
		printf("-----1.按书本价格排序-----\n");
		printf("-----2.按条形码排序-------\n");
		printf("-----3.按出版时间排序-----\n");
		printf("-----4.按馆藏数量排序-----\n");
		printf("-----5.返回桌面-----------\n");
		printf("请输入你的选择：");
		int e = 0;
		scanf("%d", &e);
		if (e == 2)
		{
			printf("按条形码排序结果为：\n");
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
			printf("按价格从低到高的排序结果为：\n");
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
			printf("按出版时间从早到晚排序结果为：\n");
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
			printf("按馆藏数量从少到多排序结果为：\n");
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
			print("输入错误！返回桌面！\n");
			return;
		}
		system("pause");
	}
}


//统计功能
void  sta(struct system* psystem)
{
	printf("1.统计图书馆藏数量以下的数据\n");
	printf("2.统计出版日期早于某日期的图书\n");
	printf("请输入你的选择：");
	int q;
	scanf("%d", &q);
	if (q == 1)
	{
		int v, n = 0;
		printf("请输入你想统计图书馆藏数量多少以下的图书：");
		scanf("%d", &v);
		printf("书名\t\t作者\t\t出版社\t\t出版时间\t价格\t\t条形码\t\t馆藏数量\n");
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
		printf("馆藏数在%d以下的图书有%d本\n", v, n);
	}
	else if (q == 2)
	{
		char v[20], n = 0;
		printf("请输入你想统计出版日期早于何时的图书：");
		scanf("%s", v);
		printf("书名\t\t作者\t\t出版社\t\t出版时间\t价格\t\t条形码\t\t馆藏数量\n");
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
		printf("出版日期早于%s的图书共有%d本\n", v, n);
	}
	else
	{
		printf("输入错误！退出统计！\n");
		return;
	}
}

//菜单
void menu()
{
	printf("                                            ----------【图书管理系统】-------\n");
	printf("                                            ---------------------------------\n");
	printf("                                            -----------0.退出系统------------\n");
	printf("                                            -----------1.添加功能------------\n");
	printf("                                            -----------2.浏览功能------------\n");
	printf("                                            -----------3.查询功能------------\n");
	printf("                                            -----------4.修改功能----------- \n");
	printf("                                            -----------5.删除功能------------\n");
	printf("                                            -----------6.排序功能----------- \n");
	printf("                                            -----------7.统计功能----------- \n");
	printf("                                            -------------------------------- \n");
	printf("                                            请输入数字 1-7 实现你所想要的功能\n");
}

//登录功能
void login()
{
	printf("\t\t【欢迎来到图书管理系统】\n");
	printf("\t\t用户名：");
	char user[20] = "";
	scanf("%s", user);
	printf("\t\t密码：");
	char pass[7] = "";
	int usk = 0;
	int i = 0;
	while ((usk = getch()) != '\r')
	{
		pass[i++] = usk;
		putchar('*');
	}
	if (strcmp(user, "大大怪将军") == 0 && strcmp(pass, "123456") == 0)
	{
		printf("\n");
		printf("登录成功！\n");
	}
	else
	{
		printf("\n");
		printf("\t\t用户名或密码错误！登录失败！\n");
		printf("\t\t退出系统！\n");
		system("pause");
		exit(0);
	}
}

//主界面控制
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
		printf("-----------1.添加功能------------\n");
		system("cls");
		printf("请输入你想要添加几本图书的信息：");
		int x;
		scanf("%d", &x);
		printf("请输入书名，作者，出版社，出版时间，价格，条形码，馆藏数量：\n");
		for (int i = 0; i < x; i++)
		{
			printf("请输入第%d本图书的信息：\n", i + 1);
			scanf("%s%s%s%s%lf%s%d", data.name, data.writer, data.press, data.time, &data.price, data.NUM, &data.num);
			enter(psystem, data);
		}
		savefile(psystem, "bookinfo.text");
		break;
	case 2:
		printf("-----------2.浏览功能------------\n");
		system("cls");
		print(psystem);
		break;
	case 3:
		printf("-----------3.查询功能------------\n");
		system("cls");
		search(psystem);
		break;
	case 4:
		printf("-----------4.修改功能----------- \n");
		system("cls");
		fix(psystem);
		savefile(psystem, "bookinfo.text");
		break;
	case 5:
		printf("-----------5.删除功能------------\n");
		system("cls");
		printf("请输入想要删除的书名或者条形码：");
		delete(psystem);
		savefile(psystem, "bookinfo.text");
		break;
	case 6:
		printf("-----------6.排序功能----------- \n");
		system("cls");
		rank(psystem);
		break;
	case 7:
		printf("-----------7.统计功能----------- \n");
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