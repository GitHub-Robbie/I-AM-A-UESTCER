#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	//����
	int table[256];
	int i;

	table[0] = 1;//��^0
	for (i = 1; i < 255; ++i)//����ԪΪ��
	{
		table[i] = (table[i - 1] << 1) ;

		//���ָ���Ѿ�����8����Ҫģ�ϲ���Լf(x)=x^8+x^6+x^5+x+1
		if (table[i] & 0x100)
		{
			table[i] ^= 0x163;//f(x)=0x163
		}
	}
	//����
	int arc_table[256];
	for (i = 0; i < 255; ++i)
		arc_table[table[i]] = i;

	//��Ԫ��
	int inverse_table[256];

	for (i = 1; i < 256; ++i)//0û����Ԫ�����Դ�1��ʼ
	{
		int k = arc_table[i];
		k = 255 - k;
		k %= 255;//m_table��ȡֵ��ΧΪ [0, 254]
		inverse_table[i] = table[k];
	}
	
	printf("(67)��Ӧ: %d\n\n", arc_table[67]);
	printf("(111)��Ӧ: %d\n\n", arc_table[111]);
	printf("�������ʽ��Ӧ: %d\n\n", table[(arc_table[67] + arc_table[111]) % 255]);
	printf("(56)��Ԫ��Ӧ: %d\n\n", inverse_table[56]);
	system("pause");
	return 0;
}

