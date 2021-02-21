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
	printf("*          ��ӭ���볬����Ʒ��Ϣ����ϵͳ��           *\n"); 
	printf("*****************************************************\n");
	printf("\n");
	
	int land();
	
	if (land() == 0) {
		printf("++++++++++++++++++++++��¼�ɹ�!++++++++++++++++++++++\n");
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
		printf("�������¼����(Ĭ��Ϊ123):");
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
	printf("\t    ��ӭʹ�ó�����Ʒ����ϵͳ��     \n");
	printf("*****************************************************\n");
	printf("*\t      1. ��ʾ������Ʒ����Ϣ\t            *\n");
	printf("*\t      2. �޸�ĳ����Ʒ����Ϣ\t            *\n");
	printf("*\t      3. ����ĳ����Ʒ����Ϣ\t            *\n");
	printf("*\t      4. ɾ��ĳ����Ʒ����Ϣ\t            *\n");
	printf("*\t      5. ����ĳ����Ʒ����Ϣ\t            *\n");
	printf("*\t      6. ��Ʒ���̲��˳�ϵͳ\t            *\n");
	printf("*\t      7. ����Ʒ�۸��������\t            *\n"); 
	printf("*\t      8. (����)ɾ����������\t            *\n");
	printf("*\t      ����. �����̲��˳�ϵͳ\t            *\n");
 	printf("*****************************************************\n");
}


bool check_nullfile(void) {
    FILE *fp = fopen("goodsinfo.txt", "r");
    
	if (!fp) {
        printf("��Ʒ��Ϣ��ʼ���ļ������ڣ�����Ϊ���½�һ��.\n");
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
		printf("��Ʒ��Ϣ��ʼ���ļ������ڣ�����Ϊ���½�һ��.\n");
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
		printf("��Ʒ��Ϣ��ʼ���ļ������ڣ�����Ϊ���½�һ��.\n");
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
	printf("ID\t����\t�۸�\t�ۿ�\t����\tʣ��\n"); 
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
	printf("������Ҫ���ҵ���ƷID: ");
	char chaid[10];
	scanf("%s", &chaid);
	while(sch) {
		if(strcmp(sch->data.id, chaid) == 0) {
			printf("\n");
			printf("��ѯ��IDΪ%s����Ʒ��Ϣ: \n", chaid);
			printf("============================================\n");
			printf("ID\t����\t�۸�\t�ۿ�\t����\tʣ��\n"); 
			printf("============================================\n");
			printf("%s\t%s\t%d\t%s\t%d\t%d\n", sch->data.id, sch->data.name, sch->data.price, 
									sch->data.discount, sch->data.amount, sch->data.remain);
			printf("--------------------------------------------\n");
			return sch;
		}
		sch = sch->next;
	}
	printf("��Ҫ��ѯ����Ʒ������!\n");
	return NULL;	
}


void Change(Headptr l) {
	GoodsListptr sch = l->head.next;
	GoodsListptr found;
	
	printf("������Ҫ�޸ĵ���ƷID: ");
	char chaid[10];
	scanf("%s", &chaid);
	while(sch) {
		if(strcmp(sch->data.id, chaid) == 0) {
			printf("\n");
			printf("��ѯ��IDΪ%s����Ʒ��Ϣ: \n", chaid);
			printf("============================================\n");
			printf("ID\t����\t�۸�\t�ۿ�\t����\tʣ��\n"); 
			printf("============================================\n");
			printf("%s\t%s\t%d\t%s\t%d\t%d\n", sch->data.id, sch->data.name, sch->data.price, 
									sch->data.discount, sch->data.amount, sch->data.remain);
			printf("--------------------------------------------\n");
			found = sch; 
		}
		sch = sch->next;
	}
		if (found == NULL)
			printf("��Ҫ��ѯ����Ʒ������!\n");
			printf("*** �������ڶ�IDΪ%s����Ʒ��Ϣ�����޸� ***\n", chaid);
			printf("\n");
			printf("ID: %s\n", chaid);
			printf("����: ");
			scanf("%s", found->data.name);
			printf("�۸�: ");
			scanf("%d", &found->data.price);
			printf("�ۿ�: ");
			scanf("%s", found->data.discount);
			printf("����: ");
			scanf("%d", &found->data.amount);
			printf("ʣ��: ");
			scanf("%d", &found->data.remain);
			printf("\n");

			printf("��Ʒ��Ϣ�޸����! �޸ĺ����Ʒ��Ϣ����: \n");
			printf("============================================\n");
			printf("ID\t����\t�۸�\t�ۿ�\t����\tʣ��\n"); 
			printf("============================================\n");
			printf("%s\t%s\t%d\t%s\t%d\t%d\n", found->data.id, found->data.name, found->data.price, 
									found->data.discount, found->data.amount, found->data.remain);
			printf("--------------------------------------------\n");
			sch = found;
			printf("�Ƿ��޸Ĵ��浽�ļ�? (y/n): ");
			char yn;
			scanf("%s", &yn);
			switch (yn) {
		    	case 'y': Write(l);	printf("\n"); printf("��Ϣ�ѱ���! \n"); return;
		    	case 'n': exit(1);
			}	
}


void Cut_in(Headptr l) {
	GoodsListptr sch = l->head.next;
	GoodsListptr temp;
	printf("������Ҫ�����֮ǰ����ƷID: ");
	char chaid[10];
	scanf("%s", &chaid);
	while(sch) {
		if(strcmp(sch->data.id, chaid) == 0) {
			printf("\n");
			printf("��ѯ��IDΪ%s����Ʒ��Ϣ: \n", chaid);
			printf("============================================\n");
			printf("ID\t����\t�۸�\t�ۿ�\t����\tʣ��\n"); 
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
			printf("* ��������IDΪ%s����Ʒ֮�����һ������Ʒ *\n", chaid);
			printf("ID: ");
			scanf("%s", pNew->data.id);
			printf("����: ");
			scanf("%s", pNew->data.name);
			printf("�۸�: ");
			scanf("%d", &pNew->data.price);
			printf("�ۿ�: ");
			scanf("%s", pNew->data.discount);
			printf("����: ");
			scanf("%d", &pNew->data.amount);
			printf("ʣ��: ");
			scanf("%d", &pNew->data.remain);
			printf("\n");
			system("cls");
			
			printf("��Ʒ��Ϣ¼�����! ¼�����Ʒ��Ϣ����: \n");
			printf("============================================\n");
			printf("ID\t����\t�۸�\t�ۿ�\t����\tʣ��\n"); 
			printf("============================================\n");
			printf("%s\t%s\t%d\t%s\t%d\t%d\n", pNew->data.id, pNew->data.name, pNew->data.price, 
									pNew->data.discount, pNew->data.amount, pNew->data.remain);
			printf("--------------------------------------------\n");
			printf("\n");
			printf("���º����ƷĿ¼����: \n");
			Output(l);
			printf("�Ƿ��޸Ĵ��浽�ļ�? (y/n): ");
			
			char yn;
			scanf("%s", &yn);
			switch (yn) {
		    	case 'y': Write(l);	printf("\n"); printf("��Ϣ�ѱ���! \n"); return;
		    	case 'n': exit(1);
			}
}	


void Delete(Headptr l) {
	GoodsListptr sch = l->head.next;
	GoodsListptr temp;
	
	printf("������Ҫɾ������ƷID: ");
	char chaid[10];
	scanf("%s", &chaid);
	
	while(sch) {
		if(strcmp(sch->data.id, chaid) == 0) {
			printf("\n");
			printf("��ѯ��IDΪ%s����Ʒ��Ϣ: \n", chaid);
			printf("============================================\n");
			printf("ID\t����\t�۸�\t�ۿ�\t����\tʣ��\n"); 
			printf("============================================\n");
			printf("%s\t%s\t%d\t%s\t%d\t%d\n", sch->data.id, sch->data.name, sch->data.price, 
									sch->data.discount, sch->data.amount, sch->data.remain);
			printf("--------------------------------------------\n");
			temp = sch;
		}
		sch = sch->next;
	}
	printf("ȷ��ɾ��IDΪ%s����Ʒ? (y/n): ", chaid);
	
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
				
				printf("��Ʒ��Ϣ��ɾ����");
				printf("���º����ƷĿ¼����: \n");
				Output(l);
				printf("�Ƿ��޸Ĵ��浽�ļ�? (y/n): ");
				
				char yn;
				scanf("%s", &yn);
				switch (yn) {
		    		case 'y': Write(l);	printf("\n"); printf("��Ϣ�ѱ���! \n"); return;
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
	printf("��������Ʒ���۸�������������: \n");
	Output(l->head.next);
	
	printf("�Ƿ��޸Ĵ��浽�ļ�? (y/n): ");
			char yn;
			scanf("%s", &yn);
			switch (yn) {
		    	case 'y': Write(l);	printf("\n"); printf("��Ϣ�ѱ���! \n"); return;
		    	case 'n': exit(1);
			}
}


void Clear(Headptr l) {
	printf("�Ƿ����������Ʒ��Ϣ? (y/n): ");
	char yn;
	scanf("%s", &yn);
	switch (yn) {
	case 'y': {
				Headptr temp = NULL;
				if (l->head.next = NULL) {
					printf("��������գ�");
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
			printf("��ǰ����Ʒ��Ϣ��¼! \n");
			printf("�Ƿ��޸Ĵ��浽�ļ�? (y/n): ");
			char yn;
			scanf("%s", &yn);
			switch (yn) {
		    	case 'y': Write(l);	printf("\n"); printf("��Ϣ�ѱ���! \n"); return;
		    	case 'n': exit(1);
			}
		} 
	case 'n': exit(1);
	} 	
}


void Menu() {
	Headptr l;
	Read(l);
	printf("        �ɹ���ȡ�ļ���������,��%d����Ʒ��¼        \n", n);
	operation_interface();
	int choice;
	printf("\n"); 
	printf("����������ѡ��: ");
	scanf("%d", &choice);
	switch (choice) {
		case 1: {
					system("cls"); 
					printf("\t---------------------------------\n");
					printf("\t*��ǰ����: 1. ��ʾ������Ʒ����Ϣ*\n");
					printf("\t---------------------------------\n");
					printf("\n");
					Output(l);
					printf("�ص����˵�? (y/n): ");
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
					printf("\t*��ǰ����: 2. �޸�ĳ����Ʒ����Ϣ*\n");
					printf("\t---------------------------------\n");
					printf("\n");
					Change(l);
					printf("�ص����˵�? (y/n): ");
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
					printf("\t*��ǰ����: 3. ����ĳ����Ʒ����Ϣ*\n");
					printf("\t---------------------------------\n");
					printf("\n");
					Cut_in(l);
					printf("�ص����˵�? (y/n): ");
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
					printf("\t*��ǰ����: 4. ɾ��ĳ����Ʒ����Ϣ*\n");
					printf("\t---------------------------------\n");
					printf("\n");
					Delete(l);
					printf("�ص����˵�? (y/n): ");
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
					printf("\t*��ǰ����: 5. ����ĳ����Ʒ����Ϣ*\n");
					printf("\t---------------------------------\n");
					printf("\n");
					Search(l);
					printf("�ص����˵�? (y/n): ");
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
					printf("\t*��ǰ����: 6. ��Ʒ���̲��˳�ϵͳ*\n");
					printf("\t---------------------------------\n");
					printf("\n");
					Write(l);
					printf("��Ʒ��Ϣ�ѱ���! \n");
					printf("�˳�ϵͳ? (y/n): ");
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
					printf("\t*��ǰ����: 7. ����Ʒ�۸��������*\n");
					printf("\t---------------------------------\n");
					printf("\n");
					Bubble(l);
					printf("�ص����˵�? (y/n): ");
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
					printf("\t*��ǰ����: 8. (����)ɾ����������*\n");
					printf("\t---------------------------------\n");
					printf("\n");
					Clear(l);
					printf("�˳�ϵͳ? (y/n): ");
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
