#include<stdio.h>
#include<string.h>


#define MAX 1000    // 大数的最大位数 
int len3;

/*
  大数加法
  参数：
  num1为第一个大数，用字符数组保存
  num2为第二个大数
  sum数组保存相加的结果  即：num1+num2=sum
  返回值：返回数组sum的有效长度，即计算结果的位数
 */
int Addition(char num1[], char num2[], int sum[])
{
	int i, j, len;
	int n2[MAX] = { 0 };
	int len1 = strlen(num1); // 计算数组num1的长度，即大数的位数 
	int len2 = strlen(num2); // 计算数组num2的长度，即大数的位数 

	len = len1 > len2 ? len1 : len2; // 获取较大的位数
	//将num1字符数组的数字字符转换为整型数字，且逆向保存在整型数组sum中，即低位在前，高位在后
	for (i = len1 - 1, j = 0; i >= 0; i--, j++)
		sum[j] = num1[i] - '0';
	// 转换第二个数 
	for (i = len2 - 1, j = 0; i >= 0; i--, j++)
		n2[j] = num2[i] - '0';
	// 将两个大数相加 
	for (i = 0; i <= len; i++)
	{
		sum[i] += n2[i];  // 两个数从低位开始相加 
		if (sum[i] > 9)   // 判断是否有进位 
		{   // 进位 
			sum[i] -= 10;
			sum[i + 1]++;
		}
	}
	if (sum[len] != 0)  // 判断最高位是否有进位 
		len++;
	return len;   // 返回和的位数 
}

/*
  大数减法
  参数：
  num1为被减数，用字符数组保存
  num2为减数
  sum数组保存相减的结果   即：num1-num2=sum
  返回值：返回数组sum的有效长度，即计算结果的位数
 */
int Subtraction(char num1[], char num2[], int sum[])
{
	int i, j, len, flag;
	char *temp;
	int n2[MAX] = { 0 };
	int len1 = strlen(num1); // 计算数组num1的长度，即大数的位数 
	int len2 = strlen(num2); // 计算数组num2的长度，即大数的位数

	// 在进行减法之前要进行一些预处理 
	flag = 0; // 为0表示结果是正整数，为1表示结果是负整数 
	if (len1 < len2) // 如果被减数位数小于减数
	{
		flag = 1; // 标记结果为负数
		// 交换两个数，便于计算 
		temp = num1;
		num1 = num2;
		num2 = temp;
		len = len1;
		len1 = len2;
		len2 = len;
	}
	else if (len1 == len2) // 如果被减数的位数等于减数的位数
	{
		// 判断哪个数大 
		for (i = 0; i < len1; i++)
		{
			if (num1[i] == num2[i])
				continue;
			if (num1[i] > num2[i])
			{
				flag = 0; // 标记结果为正数 
				break;
			}
			else
			{
				flag = 1; // 标记结果为负数 
				// 交换两个数，便于计算 
				temp = num1;
				num1 = num2;
				num2 = temp;
				break;
			}
		}
	}
	len = len1 > len2 ? len1 : len2; // 获取较大的位数
	//将num1字符数组的数字转换为整型数且逆向保存在整型数组sum中，即低位在前，高位在后
	for (i = len1 - 1, j = 0; i >= 0; i--, j++)
		sum[j] = num1[i] - '0';
	// 转换第二个数 
	for (i = len2 - 1, j = 0; i >= 0; i--, j++)
		n2[j] = num2[i] - '0';
	// 将两个大数相减 
	for (i = 0; i <= len; i++)
	{
		sum[i] = sum[i] - n2[i]; // 两个数从低位开始相减 
		if (sum[i] < 0)   // 判断是否有借位 
		{    // 借位 
			sum[i] += 10;
			sum[i + 1]--;
		}
	}
	// 计算结果长度 
	for (i = len1 - 1; i >= 0 && sum[i] == 0; i--)
		;
	len = i + 1;
	if (flag == 1)
	{
		sum[len] = -1;  // 在高位添加一个-1表示负数 
		len++;
	}
	return len;   // 返回结果的位数 
}

/*
  大数乘法
  参数：
  num1为第一个因数，用字符数组保存
  num2为第二个因数
  sum数组保存相乘的结果  即：num1*num2=sum
  返回值：返回数组sum的有效长度，即计算结果的位数
 */
int Multiplication(char num1[], char num2[], int sum[])
{
	int i, j, len, len1, len2;
	int a[MAX + 10] = { 0 };
	int b[MAX + 10] = { 0 };
	int c[MAX * 2 + 10] = { 0 };

	len1 = strlen(num1);
	for (j = 0, i = len1 - 1; i >= 0; i--) //把数字字符转换为整型数 
		a[j++] = num1[i] - '0';
	len2 = strlen(num2);
	for (j = 0, i = len2 - 1; i >= 0; i--)
		b[j++] = num2[i] - '0';

	for (i = 0; i < len2; i++)//用第二个数乘以第一个数,每次一位 
	{
		for (j = 0; j < len1; j++)
		{
			c[i + j] += b[i] * a[j]; //先乘起来,后面统一进位
		}
	}

	for (i = 0; i < MAX * 2; i++) //循环统一处理进位问题
	{
		if (c[i] >= 10)
		{
			c[i + 1] += c[i] / 10;
			c[i] %= 10;
		}
	}

	for (i = MAX * 2; c[i] == 0 && i >= 0; i--); //跳过高位的0
	len = i + 1; // 记录结果的长度 
	for (; i >= 0; i--)
		sum[i] = c[i];
	return len;
}

/*
  函数SubStract功能：
  用长度为len1的大整数p1减去长度为len2的大整数p2
  结果存在p1中，返回值代表结果的长度
  不够减：返回-1 ， 正好够：返回0
*/
int SubStract(int *p1, int len1, int *p2, int len2)
{
	int i;
	if (len1 < len2)
		return -1;
	if (len1 == len2)
	{                        // 判断p1 > p2
		for (i = len1 - 1; i >= 0; i--)
		{
			if (p1[i] > p2[i])   // 若大，则满足条件，可做减法
				break;
			else if (p1[i] < p2[i]) // 否则返回-1
				return -1;
		}
	}
	for (i = 0; i <= len1 - 1; i++)  // 从低位开始做减法
	{
		p1[i] -= p2[i];         // 相减 
		if (p1[i] < 0)           // 若是否需要借位
		{   // 借位 
			p1[i] += 10;
			p1[i + 1]--;
		}
	}
	for (i = len1 - 1; i >= 0; i--)  // 查找结果的最高位
	{
		if (p1[i])             //最高位第一个不为0
			return (i + 1);       //得到位数并返回
	}
	return 0;                   //两数相等的时候返回0
}

/*
  大数除法---结果不包括小数点
  num1 被除数
  num2 除数
  sum  商，存放计算的结果，即：num1/num2=sum
  返回数组sum的有效长度，即商的位数
*/
int Division(char num1[], char num2[], char sum[], int r[])
{
	int i, j;
	int len1, len2, len = 0;     //大数位数
	int dValue;                //两大数相差位数
	int nTemp;                 //Subtract函数返回值
	int num_a[MAX] = { 0 };      //被除数
	int num_b[MAX] = { 0 };      //除数
	int num_c[MAX] = { 0 };      //商
	int temp[MAX * 2 + 10] = { 0 };
	int temp1[MAX] = { 0 };
	char temp2[MAX];
	int temp3[MAX];
	int temp4[MAX];

	len1 = strlen(num1);       //获得大数的位数
	len2 = strlen(num2);

	//将数字字符转换成整型数，且翻转保存在整型数组中 
	for (j = 0, i = len1 - 1; i >= 0; j++, i--)
		num_a[j] = num1[i] - '0';
	for (j = 0, i = len2 - 1; i >= 0; j++, i--)
		num_b[j] = num2[i] - '0';

	if (len1 < len2)          //如果被除数小于除数，直接返回-1，表示结果为0
	{
		return -1;
	}
	dValue = len1 - len2;      //相差位数
	for (i = len1 - 1; i >= 0; i--)    //将除数扩大，使得除数和被除数位数相等
	{
		if (i >= dValue)
			num_b[i] = num_b[i - dValue];
		else                         //低位置0
			num_b[i] = 0;
	}
	len2 = len1;
	for (j = 0; j <= dValue; j++)    //重复调用，同时记录减成功的次数，即为商
	{
		while ((nTemp = SubStract(num_a, len1, num_b + j, len2 - j)) >= 0)
		{
			len1 = nTemp;            //结果长度
			num_c[dValue - j]++;       //每成功减一次，将商的相应位加1
		}
	}
	// 计算商的位数，并将商放在sum字符数组中 
	for (i = MAX - 1; num_c[i] == 0 && i >= 0; i--);  //跳过高位0，获取商的位数 
	if (i >= 0)
		len = i + 1; // 保存位数 
	for (j = 0; i >= 0; i--, j++)     // 将结果复制到sum数组中 
		sum[j] = num_c[i] + '0';
	sum[j] = '\0';   // sum字符数组结尾置0

	int len_new=	Multiplication(num2, sum, temp);
	for (i = 0; i < len_new; i++)
	{
		temp2[i] = (char)('0' + temp[i]);
	}
	temp2[i] = '\0';

	for (i = len_new - 1, j = 0; i >= 0; i--, j++)
		temp3[j] = temp2[i] - '0';

	for (i = 0; i < len_new; i++)
	{
		temp2[i] = (char)('0' + temp3[i]);
	}
	
	len3=Subtraction(num1, temp2, temp4);

	i = len3-1;

	for (j = 0; i >= 0; i--, j++)     // 将结果复制到sum数组中 
		r[j] = temp4[i];


	return len;      // 返回商的位数 
}


int main()
{
	
	//加法测试
	int i, len;
	
	int result1[MAX] = { 0 }; // 存放计算的结果，低位在前，高位在后，即sum[0]是低位 
	char num1[] = "1234567891234742348258374651876245871645567891234"; // 第一个大数 
	char num2[] = "2345678912345198347614512349816498763916678913345"; // 第二个大数 
	len = Addition(num1, num2, result1);    // 两数相加 
	printf("加法测试: %s + %s\n=", num1, num2);
	// 反向输出求和结果
	for (i = len - 1; i >= 0; i--)
		printf("%d", result1[i]);
	printf("\n\n");

	//减法测试
	int result2[MAX] = { 0 }; // 存放计算的结果，低位在前，高位在后，即sum[0]是低位 
	char num3[] = "98761937824698237649816498679197346954321987654321"; // 第一个大数 
	char num4[] = "12345678198367491876498164396498137649269123456789"; // 第二个大数 
	len = Subtraction(num3, num4, result2);    // 两数相减 
	// 输出结果
	printf("减法测试: %s - %s\n=", num3, num4);
	if (result2[i = len - 1] < 0) // 根据高位是否是-1判断是否是负数
	{
		printf("-"); // 输出负号
		i--;
	}
	for (; i >= 0; i--)
		printf("%d", result2[i]);
	printf("\n\n");

	//乘法测试
	int result3[MAX * 2 + 10] = { 0 }; // 存放计算的结果，低位在前，高位在后，即sum[0]是低位 
	char num5[] = "6121439816374291674937"; // 第一个大数 
	char num6[] = "201619876349816749386190415123025"; // 第二个大数 
	len = Multiplication(num5, num6, result3);
	// 输出结果
	printf("乘法测试: %s × %s\n=", num5, num6);
	for (i = len - 1; i >= 0; i--)
		printf("%d", result3[i]);
	printf("\n\n");
	

	//除法测试
	char num7[MAX] = "123456719786439817264981634899876543210";   // 第一个大数
	char num8[MAX] = "20160411987364918365123025";              // 第二个大数
	char result4[MAX] = { 0 };    // 计算结果 
	int r[MAX] = { 0 };
	//scanf("%s", num1);      //以字符串形式读入大数
	//scanf("%s", num2);

	len = Division(num7, num8, result4, r);

	//输出结果
	printf("除法测试: %s ÷ %s\n=", num7, num8);
	if (len >= 0)
	{
		for (i = 0; i < len; i++)
			printf("%c", result4[i]);
	}
	else
	{
		printf("0");
	}
	printf("\nr=");
	if (len3 >= 0)
	{
		for (i = 0; i < len3; i++)
			printf("%d", r[i]);
	}
	else
	{
		printf("0");
	}
	printf("\n\n");
	
//	ModPow();

	system("pause");
	return 0;
}