#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <windows.h> 

#define MAX 100

#define MAX_ID_LEN 30
#define MAX_NAME_LEN 30
#define MAX_PRICE_LEN 30
#define MAX_DISCOUNT_LEN 30

int n;

typedef struct {
    char	id[MAX_ID_LEN];
    char	name[MAX_NAME_LEN];
    int  	price;
    char	discount[MAX_DISCOUNT_LEN];
    int		amount;
    int		remain;
} GoodsInfo;


typedef struct node {
    GoodsInfo data;
    struct node *next;
} GoodsList;

typedef GoodsList *GoodsListptr;

typedef struct {
	GoodsList head;
	int Goodsn;
} Head;

typedef Head *Headptr;

void Login() {
	printf("*****************************************************\n");
	printf("*          欢迎进入超市商品信息管理系统！           *\n"); 
	printf("*****************************************************\n");
	printf("\n");
	
	int land();
	
	if (land() == 0) {
		printf("++++++++++++++++++++++登录成功!++++++++++++++++++++++\n");
		printf("\n");
	}
	else if(land() == -1) {
		printf("fail");
	}

}


int land() {
	int i =3;
	char ch[]={"123"};
	char input[20] = {0};
	
	while (i) {
		printf("请输入登录密码(默认为123):");
		scanf("%s", input);
		
		if(!strcmp(ch,input)) {
			system("cls");
			return 0;
		}
		else{
			i--;
			printf("fail,left%d\n",i);
		}
	}
	if(i==0) {
		return (-1);
	}
	return 0;
}

	
void operation_interface(){
	printf("\n");
	printf("\t    欢迎使用超市商品管理系统！     \n");
	printf("*****************************************************\n");
	printf("*\t      1. 显示所有商品的信息\t            *\n");
	printf("*\t      2. 修改某个商品的信息\t            *\n");
	printf("*\t      3. 插入某个商品的信息\t            *\n");
	printf("*\t      4. 删除某个商品的信息\t            *\n");
	printf("*\t      5. 查找某个商品的信息\t            *\n");
	printf("*\t      6. 商品存盘并退出系统\t            *\n");
	printf("*\t      7. 对商品价格进行排序\t            *\n"); 
	printf("*\t      8. (慎用)删除所有内容\t            *\n");
	printf("*\t      其他. 不存盘并退出系统\t            *\n");
 	printf("*****************************************************\n");
}


bool check_nullfile(void) {
    FILE *fp = fopen("goodsinfo.txt", "r");
    
	if (!fp) {
        printf("商品信息初始化文件不存在！程序将为您新建一个.\n");
        FILE *fp = fopen("goodsinfo.txt", "w");
        fclose(fp);
        return false;
    }
    
	else {
        int temp;
        int res = fscanf(fp, "%d", &temp);
        
		fclose(fp);
        if (res <= 0)
            return false;
        else
            return true;
    }
}


void Read(Headptr l) {
	check_nullfile();
	 
	l->head.next = NULL;
	l->Goodsn = 0;
	FILE *fp;
	
	fp = fopen("goodsinfo.txt", "r");
	if(fp == NULL) {
		fp == fopen("goodsinfo.txt", "w");
		printf("商品信息初始化文件不存在！程序将为您新建一个.\n");
	} 
	else {
		GoodsListptr p;
		p = (GoodsListptr)malloc(sizeof(GoodsList));
		
		while(!feof(fp)) {
			fscanf(fp, "%s", p->data.id);
			fscanf(fp, "%s", p->data.name);
			fscanf(fp, "%d", &p->data.price);
			fscanf(fp, "%s", p->data.discount);
			fscanf(fp, "%d", &p->data.amount);
			fscanf(fp, "%d", &p->data.remain);
			p->next = l->head.next;
			l->head.next = p;
			l->Goodsn++;
			p = (GoodsListptr)malloc(sizeof(GoodsList));
		}
		n = l->Goodsn;	
	} 
}


void Write(Headptr l) {
	FILE *fp;
	
	fp = fopen("goodsinfo.txt", "w");
	if(fp == NULL) {
		fp == fopen("goodsinfo.txt", "w");
		printf("商品信息初始化文件不存在！程序将为您新建一个.\n");
	} 
	else {
		GoodsListptr p;
		p = l->head.next;
		while (p) {
			fprintf(fp, "%s\t", p->data.id);
			fprintf(fp, "%s\t", p->data.name);
			fprintf(fp, "%d\t", p->data.price);
			fprintf(fp, "%s\t", p->data.discount);
			fprintf(fp, "%d\t", p->data.amount);
			fprintf(fp, "%d", p->data.remain);
			p = p->next;
			if (p != NULL) fprintf(fp, "\n");
		}
	}
	fclose(fp);
	return;
}

	
void Output(Headptr l) {
	GoodsListptr prt = l->head.next; 
	
	printf("============================================\n");
	printf("ID\t名称\t价格\t折扣\t数量\t剩余\n"); 
	printf("============================================\n");
	while (prt) {
		printf("%s\t%s\t%d\t%s\t%d\t%d\n", prt->data.id, prt->data.name, prt->data.price, 
							prt->data.discount, prt->data.amount, prt->data.remain);
		printf("--------------------------------------------\n");
		prt = prt->next;
	}
}


GoodsListptr Search(Headptr l) {
	GoodsListptr sch = l->head.next;
	printf("请输入要查找的商品ID: ");
	char chaid[10];
	scanf("%s", &chaid);
	while(sch) {
		if(strcmp(sch->data.id, chaid) == 0) {
			printf("\n");
			printf("查询到ID为%s的商品信息: \n", chaid);
			printf("============================================\n");
			printf("ID\t名称\t价格\t折扣\t数量\t剩余\n"); 
			printf("============================================\n");
			printf("%s\t%s\t%d\t%s\t%d\t%d\n", sch->data.id, sch->data.name, sch->data.price, 
									sch->data.discount, sch->data.amount, sch->data.remain);
			printf("--------------------------------------------\n");
			return sch;
		}
		sch = sch->next;
	}
	printf("你要查询的商品不存在!\n");
	return NULL;	
}


void Change(Headptr l) {
	GoodsListptr sch = l->head.next;
	GoodsListptr found;
	
	printf("请输入要修改的商品ID: ");
	char chaid[10];
	scanf("%s", &chaid);
	while(sch) {
		if(strcmp(sch->data.id, chaid) == 0) {
			printf("\n");
			printf("查询到ID为%s的商品信息: \n", chaid);
			printf("============================================\n");
			printf("ID\t名称\t价格\t折扣\t数量\t剩余\n"); 
			printf("============================================\n");
			printf("%s\t%s\t%d\t%s\t%d\t%d\n", sch->data.id, sch->data.name, sch->data.price, 
									sch->data.discount, sch->data.amount, sch->data.remain);
			printf("--------------------------------------------\n");
			found = sch; 
		}
		sch = sch->next;
	}
		if (found == NULL)
			printf("你要查询的商品不存在!\n");
			printf("*** 现在正在对ID为%s的商品信息进行修改 ***\n", chaid);
			printf("\n");
			printf("ID: %s\n", chaid);
			printf("名称: ");
			scanf("%s", found->data.name);
			printf("价格: ");
			scanf("%d", &found->data.price);
			printf("折扣: ");
			scanf("%s", found->data.discount);
			printf("数量: ");
			scanf("%d", &found->data.amount);
			printf("剩余: ");
			scanf("%d", &found->data.remain);
			printf("\n");

			printf("商品信息修改完成! 修改后的商品信息如下: \n");
			printf("============================================\n");
			printf("ID\t名称\t价格\t折扣\t数量\t剩余\n"); 
			printf("============================================\n");
			printf("%s\t%s\t%d\t%s\t%d\t%d\n", found->data.id, found->data.name, found->data.price, 
									found->data.discount, found->data.amount, found->data.remain);
			printf("--------------------------------------------\n");
			sch = found;
			printf("是否将修改储存到文件? (y/n): ");
			char yn;
			scanf("%s", &yn);
			switch (yn) {
		    	case 'y': Write(l);	printf("\n"); printf("信息已保存! \n"); return;
		    	case 'n': exit(1);
			}	
}


void Cut_in(Headptr l) {
	GoodsListptr sch = l->head.next;
	GoodsListptr temp;
	printf("请输入要插入点之前的商品ID: ");
	char chaid[10];
	scanf("%s", &chaid);
	while(sch) {
		if(strcmp(sch->data.id, chaid) == 0) {
			printf("\n");
			printf("查询到ID为%s的商品信息: \n", chaid);
			printf("============================================\n");
			printf("ID\t名称\t价格\t折扣\t数量\t剩余\n"); 
			printf("============================================\n");
			printf("%s\t%s\t%d\t%s\t%d\t%d\n", sch->data.id, sch->data.name, sch->data.price, 
									sch->data.discount, sch->data.amount, sch->data.remain);
			printf("--------------------------------------------\n");
			temp = sch;
		}
		sch = sch->next;
	}
	GoodsListptr pNew;
	pNew = (GoodsListptr)malloc(sizeof(GoodsList));

	pNew->next = temp->next;
	temp->next = pNew;
	
			printf("\n");
			printf("* 现在正在ID为%s的商品之后插入一个新商品 *\n", chaid);
			printf("ID: ");
			scanf("%s", pNew->data.id);
			printf("名称: ");
			scanf("%s", pNew->data.name);
			printf("价格: ");
			scanf("%d", &pNew->data.price);
			printf("折扣: ");
			scanf("%s", pNew->data.discount);
			printf("数量: ");
			scanf("%d", &pNew->data.amount);
			printf("剩余: ");
			scanf("%d", &pNew->data.remain);
			printf("\n");
			system("cls");
			
			printf("商品信息录入完成! 录入的商品信息如下: \n");
			printf("============================================\n");
			printf("ID\t名称\t价格\t折扣\t数量\t剩余\n"); 
			printf("============================================\n");
			printf("%s\t%s\t%d\t%s\t%d\t%d\n", pNew->data.id, pNew->data.name, pNew->data.price, 
									pNew->data.discount, pNew->data.amount, pNew->data.remain);
			printf("--------------------------------------------\n");
			printf("\n");
			printf("更新后的商品目录如下: \n");
			Output(l);
			printf("是否将修改储存到文件? (y/n): ");
			
			char yn;
			scanf("%s", &yn);
			switch (yn) {
		    	case 'y': Write(l);	printf("\n"); printf("信息已保存! \n"); return;
		    	case 'n': exit(1);
			}
}	


void Delete(Headptr l) {
	GoodsListptr sch = l->head.next;
	GoodsListptr temp;
	
	printf("请输入要删除的商品ID: ");
	char chaid[10];
	scanf("%s", &chaid);
	
	while(sch) {
		if(strcmp(sch->data.id, chaid) == 0) {
			printf("\n");
			printf("查询到ID为%s的商品信息: \n", chaid);
			printf("============================================\n");
			printf("ID\t名称\t价格\t折扣\t数量\t剩余\n"); 
			printf("============================================\n");
			printf("%s\t%s\t%d\t%s\t%d\t%d\n", sch->data.id, sch->data.name, sch->data.price, 
									sch->data.discount, sch->data.amount, sch->data.remain);
			printf("--------------------------------------------\n");
			temp = sch;
		}
		sch = sch->next;
	}
	printf("确认删除ID为%s的商品? (y/n): ", chaid);
	
	char yn;
	scanf("%s", &yn);
	switch (yn) {
	case 'y': {
				system("cls");
				GoodsListptr pNew;
				pNew = (GoodsListptr)malloc(sizeof(GoodsList));
				pNew = temp->next;
				temp->data = pNew->data;
				temp->next = pNew->next;
				
				printf("商品信息已删除！");
				printf("更新后的商品目录如下: \n");
				Output(l);
				printf("是否将修改储存到文件? (y/n): ");
				
				char yn;
				scanf("%s", &yn);
				switch (yn) {
		    		case 'y': Write(l);	printf("\n"); printf("信息已保存! \n"); return;
		    		case 'n': exit(1);
			}			 
	} 
	case 'n': exit(1);
	} 	
}


GoodsListptr Bubble(Headptr l) {
	GoodsListptr p, q;
	int num = 0; 
	int x = 0; 
	int i = 0;
	
	q = l->head.next;
	
	while (q != NULL) {
		q = q->next;
		num++;
	} 
	
	for (i = 0; i < num - 1; i++) {
		p = q = l->head.next;
		x = num - i - 1;
		while (p->next != NULL && x != 0) {
			x--;
			if ((p->data.price) > (p->next->data.price)) {
				if (p == l->head.next) l->head.next = p->next;
				else q->next = p->next;
				q->next = p->next;
				q = q->next;
				p->next = q->next;
				q->next = p;
				p = q;
			}
			q = p;
			p = p->next;
		}
	}
	printf("对所有商品按价格升序排序如下: \n");
	Output(l->head.next);
	
	printf("是否将修改储存到文件? (y/n): ");
			char yn;
			scanf("%s", &yn);
			switch (yn) {
		    	case 'y': Write(l);	printf("\n"); printf("信息已保存! \n"); return;
		    	case 'n': exit(1);
			}
}


void Clear(Headptr l) {
	printf("是否清除所有商品信息? (y/n): ");
	char yn;
	scanf("%s", &yn);
	switch (yn) {
	case 'y': {
				Headptr temp = NULL;
				if (l->head.next = NULL) {
					printf("数据已清空！");
					return ; 
				}
				while (l->head.next != NULL) {
					temp = l->head.next;
					free(l->head.next);
					l->head.next = temp;
				}
			if (l->head.next != NULL) {
				free(l->head.next);
				l->head.next = NULL;
			}
			Output(l); 
			printf("当前无商品信息记录! \n");
			printf("是否将修改储存到文件? (y/n): ");
			char yn;
			scanf("%s", &yn);
			switch (yn) {
		    	case 'y': Write(l);	printf("\n"); printf("信息已保存! \n"); return;
		    	case 'n': exit(1);
			}
		} 
	case 'n': exit(1);
	} 	
}


void Menu() {
	Headptr l;
	Read(l);
	printf("        成功读取文件建立链表,有%d个商品记录        \n", n);
	operation_interface();
	int choice;
	printf("\n"); 
	printf("请输入您的选择: ");
	scanf("%d", &choice);
	switch (choice) {
		case 1: {
					system("cls"); 
					printf("\t---------------------------------\n");
					printf("\t*当前所在: 1. 显示所有商品的信息*\n");
					printf("\t---------------------------------\n");
					printf("\n");
					Output(l);
					printf("回到主菜单? (y/n): ");
					char yn;
					scanf("%s", &yn);
					switch (yn) {
						case 'y': system("cls"); Headptr l; Read(l); Menu();
						case 'n': exit(1);
					}
				}
	
		case 2: {
					system("cls"); 
					printf("\t---------------------------------\n");
					printf("\t*当前所在: 2. 修改某个商品的信息*\n");
					printf("\t---------------------------------\n");
					printf("\n");
					Change(l);
					printf("回到主菜单? (y/n): ");
					char yn;
					scanf("%s", &yn);
					switch (yn) {
						case 'y': system("cls"); Headptr l; Read(l); Menu();
						case 'n': exit(1);
					}
				}
		
		case 3: {
					system("cls"); 
					printf("\t---------------------------------\n");
					printf("\t*当前所在: 3. 插入某个商品的信息*\n");
					printf("\t---------------------------------\n");
					printf("\n");
					Cut_in(l);
					printf("回到主菜单? (y/n): ");
					char yn;
					scanf("%s", &yn);
					switch (yn) {
						case 'y': system("cls"); Headptr l; Read(l); Menu();
						case 'n': exit(1);
					}
		}
		
		case 4: {
					system("cls"); 
					printf("\t---------------------------------\n");
					printf("\t*当前所在: 4. 删除某个商品的信息*\n");
					printf("\t---------------------------------\n");
					printf("\n");
					Delete(l);
					printf("回到主菜单? (y/n): ");
					char yn;
					scanf("%s", &yn);
					switch (yn) {
						case 'y': system("cls"); Headptr l; Read(l); Menu();
						case 'n': exit(1);
					}
		} 
		
		case 5: {
					system("cls"); 
					printf("\t---------------------------------\n");
					printf("\t*当前所在: 5. 查找某个商品的信息*\n");
					printf("\t---------------------------------\n");
					printf("\n");
					Search(l);
					printf("回到主菜单? (y/n): ");
					char yn;
					scanf("%s", &yn);
					switch (yn) {
						case 'y': system("cls"); Headptr l; Read(l); Menu();
						case 'n': exit(1);
					}
				} 
		
		case 6: {
					system("cls"); 
					printf("\t---------------------------------\n");
					printf("\t*当前所在: 6. 商品存盘并退出系统*\n");
					printf("\t---------------------------------\n");
					printf("\n");
					Write(l);
					printf("商品信息已保存! \n");
					printf("退出系统? (y/n): ");
					char yn;
					scanf("%s", &yn);
					switch (yn) {
						case 'n': system("cls"); Headptr l; Read(l); Menu();
						case 'y': exit(1);
					}
		}
		case 7: {
					system("cls"); 
					printf("\t---------------------------------\n");
					printf("\t*当前所在: 7. 对商品价格进行排序*\n");
					printf("\t---------------------------------\n");
					printf("\n");
					Bubble(l);
					printf("回到主菜单? (y/n): ");
					char yn;
					scanf("%s", &yn);
					switch (yn) {
						case 'y': system("cls"); Headptr l; Read(l); Menu();
						case 'n': exit(1);
					}
		} 
		
		case 8: {
					system("cls"); 
					printf("\t---------------------------------\n");
					printf("\t*当前所在: 8. (慎用)删除所有内容*\n");
					printf("\t---------------------------------\n");
					printf("\n");
					Clear(l);
					printf("退出系统? (y/n): ");
					char yn;
					scanf("%s", &yn);
					switch (yn) {
						case 'n': operation_interface();
						case 'y': exit(1);
					}
		}
		
		default: exit(1);
	} 
}


int main()
{
	Login();
	Headptr l;
	Read(l);
	Menu();	
}
