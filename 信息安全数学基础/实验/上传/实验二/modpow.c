#include<stdio.h>
#include<string.h>
#include<time.h>
#define MAX 1000

char c[2000];//全局变量，存储大数运算的结果
int temp[MAX];
char a[2000];
char result[MAX * 2];
int binary[MAX];
char res[MAX];
int A1[MAX];
char tempnew[MAX];
int temp_h[MAX];
char temp_q[MAX];

int Judge(char ch[]) //判断字符串ch是否全为0，若全为1，返回，否则返回0
{
	int i, k;
	k = strlen(ch);
	for (i = 0; i < k; i++)
		if (ch[i] != '0')
			return 0;
	return 1;
}

int isstr0(char *num)
{
	int i, len;
	len = strlen(num);
	for (i = 0; i < len; i++)
	{
		if (num[i] != '0')
			return 1;
	}
	return 0;
}

int ToBinary(char from[])
{
	char big_num[MAX];
	char quotient[MAX];

	char temp, n;
	char remider;
	int i, j, k;
	long long flag = 1;
	memset(big_num, 0, MAX);
	strcpy(quotient, from);
	i = j = 0;
	if (strlen(quotient) >= MAX)
	{
		printf("Big num string too long. %d bits limited\n", MAX - 1);
		exit(0);
	}
	k = 0;
	do
	{
		n = 0;
		j = 0;
		strcpy(big_num, quotient);
		for (i = 0; i < strlen(big_num); i++)
		{
			if (big_num[i] < '0' || big_num[i] > '9')
			{
				printf("invalid character in big num string.\n");
				exit(0);
			}
			if (big_num[i] == '1' && i != strlen(big_num) - 1 && n != 10)
			{
				n = 10;
				quotient[j] = '0';
				j++;
				continue;
			}
			else
			{
				temp = big_num[i] - '0';
				temp = n + temp;
				quotient[j] = (temp / 2) + '0';
				j++;
				if ((temp & 1) == 1)
					n = 10;
				else n = 0;
			}
		}
		quotient[j] = '\0';
		result[k] = (temp & 1) + '0';
		k++;
	} while (isstr0(quotient));
	result[k] = '\0';
	//reverse(result);
	//printf("binary: %s\n", result);
	int len = strlen(result);
	
	for (i = 0; i < len; i++)
		binary[i] = result[i] - '0';
	return len;
}

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
		strcpy(tempnew, num1);
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

	int len_new = Multiplication(num2, sum, temp);
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
	int len3 = Subtraction(num1, temp2, temp4);

	i = len3 - 1;

	for (j = 0; i >= 0; i--, j++)     // 将结果复制到sum数组中 
		temp_h[j] = temp4[i];

	memset(tempnew, 0, sizeof(tempnew));
	for (i = 0; i < j; i++)
	{
		tempnew[i] = (char)('0' + temp_h[i]);
	}

	return len;      // 返回商的位数 
}

void ModPow(int a, char k[], char m[])
{
	int i, j,q;
	int len = ToBinary(k);
	if (binary[0] == 0)
		res[0] = '1';
	char A[MAX]="5";
	

	if (binary[0] == 1)
		res[0] = a;
	for (i = 1; i < len; i++)
	{
		int len3=Multiplication(A, A, temp);
		char temp4[MAX];
		for (j = 0, q = len3 - 1; q >= 0; j++, q--)
			temp4[j] = (char)('0' + temp[q]);
		memset(A, 0, sizeof(A));

		strncpy(A, temp4, len3);

		Division(A, m, temp_q, A1);
		int len2 = strlen(tempnew);
		strcpy(A, tempnew);
		if (binary[i] == 1)
		{
			int len3 = Multiplication(A, res, temp);
			char temp4[MAX];
			for (j = 0, q = len3 - 1; q >= 0; j++, q--)
				temp4[j] = (char)('0' + temp[q]);
			memset(res, 0, sizeof(res));
			strncpy(res, temp4, len3);
			Division(res, m, temp_q, A1);
			int len2 = strlen(tempnew);
			strcpy(res, tempnew);
		}
	}
}

int main()
{
	clock_t start, finish;
	double duration;
	start = clock();

	int a = 5;
	char k[] = "596";
	char m[] = "6729475";
	ModPow(a, k, m);
	printf("12332^0 (mod 1234) = ");
	printf("%s\n\n", res);
	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("duration: %f seconds\n\n", duration);
	system("pause");
	return 0;
}
