#include<stdio.h>
#include<string.h>
#include<time.h>
#define MAX 1000

char c[2000];//ȫ�ֱ������洢��������Ľ��
int temp[MAX];
char a[2000];
char result[MAX * 2];
int binary[MAX];
char res[MAX];
int A1[MAX];
char tempnew[MAX];
int temp_h[MAX];
char temp_q[MAX];

int Judge(char ch[]) //�ж��ַ���ch�Ƿ�ȫΪ0����ȫΪ1�����أ����򷵻�0
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
	int len1 = strlen(num1); // ��������num1�ĳ��ȣ���������λ�� 
	int len2 = strlen(num2); // ��������num2�ĳ��ȣ���������λ��

	// �ڽ��м���֮ǰҪ����һЩԤ���� 
	flag = 0; // Ϊ0��ʾ�������������Ϊ1��ʾ����Ǹ����� 
	if (len1 < len2) // ���������λ��С�ڼ���
	{
		flag = 1; // ��ǽ��Ϊ����
		// ���������������ڼ��� 
		temp = num1;
		num1 = num2;
		num2 = temp;
		len = len1;
		len1 = len2;
		len2 = len;
	}
	else if (len1 == len2) // �����������λ�����ڼ�����λ��
	{
		// �ж��ĸ����� 
		for (i = 0; i < len1; i++)
		{
			if (num1[i] == num2[i])
				continue;
			if (num1[i] > num2[i])
			{
				flag = 0; // ��ǽ��Ϊ���� 
				break;
			}
			else
			{
				flag = 1; // ��ǽ��Ϊ���� 
				// ���������������ڼ��� 
				temp = num1;
				num1 = num2;
				num2 = temp;
				break;
			}
		}
	}
	len = len1 > len2 ? len1 : len2; // ��ȡ�ϴ��λ��
	//��num1�ַ����������ת��Ϊ�����������򱣴�����������sum�У�����λ��ǰ����λ�ں�
	for (i = len1 - 1, j = 0; i >= 0; i--, j++)
		sum[j] = num1[i] - '0';
	// ת���ڶ����� 
	for (i = len2 - 1, j = 0; i >= 0; i--, j++)
		n2[j] = num2[i] - '0';
	// ������������� 
	for (i = 0; i <= len; i++)
	{
		sum[i] = sum[i] - n2[i]; // �������ӵ�λ��ʼ��� 
		if (sum[i] < 0)   // �ж��Ƿ��н�λ 
		{    // ��λ 
			sum[i] += 10;
			sum[i + 1]--;
		}
	}
	// ���������� 
	for (i = len1 - 1; i >= 0 && sum[i] == 0; i--)
		;
	len = i + 1;
	if (flag == 1)
	{
		sum[len] = -1;  // �ڸ�λ���һ��-1��ʾ���� 
		len++;
	}
	return len;   // ���ؽ����λ�� 
}

int Multiplication(char num1[], char num2[], int sum[])
{
	int i, j, len, len1, len2;
	int a[MAX + 10] = { 0 };
	int b[MAX + 10] = { 0 };
	int c[MAX * 2 + 10] = { 0 };

	len1 = strlen(num1);
	for (j = 0, i = len1 - 1; i >= 0; i--) //�������ַ�ת��Ϊ������ 
		a[j++] = num1[i] - '0';
	len2 = strlen(num2);
	for (j = 0, i = len2 - 1; i >= 0; i--)
		b[j++] = num2[i] - '0';

	for (i = 0; i < len2; i++)//�õڶ��������Ե�һ����,ÿ��һλ 
	{
		for (j = 0; j < len1; j++)
		{
			c[i + j] += b[i] * a[j]; //�ȳ�����,����ͳһ��λ
		}
	}

	for (i = 0; i < MAX * 2; i++) //ѭ��ͳһ�����λ����
	{
		if (c[i] >= 10)
		{
			c[i + 1] += c[i] / 10;
			c[i] %= 10;
		}
	}

	for (i = MAX * 2; c[i] == 0 && i >= 0; i--); //������λ��0
	len = i + 1; // ��¼����ĳ��� 
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
	{                        // �ж�p1 > p2
		for (i = len1 - 1; i >= 0; i--)
		{
			if (p1[i] > p2[i])   // ������������������������
				break;
			else if (p1[i] < p2[i]) // ���򷵻�-1
				return -1;
		}
	}
	for (i = 0; i <= len1 - 1; i++)  // �ӵ�λ��ʼ������
	{
		p1[i] -= p2[i];         // ��� 
		if (p1[i] < 0)           // ���Ƿ���Ҫ��λ
		{   // ��λ 
			p1[i] += 10;
			p1[i + 1]--;
		}
	}
	for (i = len1 - 1; i >= 0; i--)  // ���ҽ�������λ
	{
		if (p1[i])             //���λ��һ����Ϊ0
			return (i + 1);       //�õ�λ��������
	}
	return 0;                   //������ȵ�ʱ�򷵻�0
}

int Division(char num1[], char num2[], char sum[], int r[])
{
	int i, j;
	int len1, len2, len = 0;     //����λ��
	int dValue;                //���������λ��
	int nTemp;                 //Subtract��������ֵ
	int num_a[MAX] = { 0 };      //������
	int num_b[MAX] = { 0 };      //����
	int num_c[MAX] = { 0 };      //��
	int temp[MAX * 2 + 10] = { 0 };
	int temp1[MAX] = { 0 };
	char temp2[MAX];
	int temp3[MAX];
	int temp4[MAX];

	len1 = strlen(num1);       //��ô�����λ��
	len2 = strlen(num2);

	//�������ַ�ת�������������ҷ�ת���������������� 
	for (j = 0, i = len1 - 1; i >= 0; j++, i--)
		num_a[j] = num1[i] - '0';
	for (j = 0, i = len2 - 1; i >= 0; j++, i--)
		num_b[j] = num2[i] - '0';

	if (len1 < len2)          //���������С�ڳ�����ֱ�ӷ���-1����ʾ���Ϊ0
	{
		strcpy(tempnew, num1);
		return -1;
	}
	dValue = len1 - len2;      //���λ��
	for (i = len1 - 1; i >= 0; i--)    //����������ʹ�ó����ͱ�����λ�����
	{
		if (i >= dValue)
			num_b[i] = num_b[i - dValue];
		else                         //��λ��0
			num_b[i] = 0;
	}
	len2 = len1;
	for (j = 0; j <= dValue; j++)    //�ظ����ã�ͬʱ��¼���ɹ��Ĵ�������Ϊ��
	{
		while ((nTemp = SubStract(num_a, len1, num_b + j, len2 - j)) >= 0)
		{
			len1 = nTemp;            //�������
			num_c[dValue - j]++;       //ÿ�ɹ���һ�Σ����̵���Ӧλ��1
		}
	}
	// �����̵�λ���������̷���sum�ַ������� 
	for (i = MAX - 1; num_c[i] == 0 && i >= 0; i--);  //������λ0����ȡ�̵�λ�� 
	if (i >= 0)
		len = i + 1; // ����λ�� 
	for (j = 0; i >= 0; i--, j++)     // ��������Ƶ�sum������ 
		sum[j] = num_c[i] + '0';
	sum[j] = '\0';   // sum�ַ������β��0

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

	for (j = 0; i >= 0; i--, j++)     // ��������Ƶ�sum������ 
		temp_h[j] = temp4[i];

	memset(tempnew, 0, sizeof(tempnew));
	for (i = 0; i < j; i++)
	{
		tempnew[i] = (char)('0' + temp_h[i]);
	}

	return len;      // �����̵�λ�� 
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
