printf("是否对该商品信息进行修改? (y/n)");
	char yn;
	scanf("%s", &yn);
	switch (yn) {
		case 'y': {
			system("cls");
			printf("! 现在正在对ID为%s的商品信息进行修改! \n", chaid);
			printf("ID: %s\n", chaid);
			printf("名称: ");
			scanf("%s", sch->data.name);
			printf("\n");
			printf("价格: ");
			scanf("%d", &sch->data.price);
			printf("\n"); 
			printf("折扣: ");
			scanf("%s", sch->data.discount);
			printf("\n");
			printf("数量: ");
			scanf("%d", &sch->data.amount);
			printf("\n");
			printf("剩余: ");
			scanf("%d", &sch->data.remain);
			printf("\n");
			system("cls");
			printf("商品信息修改完成! 修改后的商品信息如下: \n");
			printf("============================================\n");
			printf("ID\t名称\t价格\t折扣\t数量\t剩余\n"); 
			printf("============================================\n");
			printf("%s\t%s\t%d\t%s\t%d\t%d\n", sch->data.id, sch->data.name, sch->data.price, 
									sch->data.discount, sch->data.amount, sch->data.remain);
			printf("--------------------------------------------\n");
		}
	case 'n': exit(1);
	} 