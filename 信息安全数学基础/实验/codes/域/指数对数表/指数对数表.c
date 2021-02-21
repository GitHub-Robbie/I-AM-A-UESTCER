#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	//正表
	int table[256];
	int i;

	table[0] = 1;//α^0
	for (i = 1; i < 255; ++i)//生成元为α
	{
		table[i] = (table[i - 1] << 1) ;

		//最高指数已经到了8，需要模上不可约f(x)=x^8+x^6+x^5+x+1
		if (table[i] & 0x100)
		{
			table[i] ^= 0x163;//f(x)=0x163
		}
	}
	//反表
	int arc_table[256];
	for (i = 0; i < 255; ++i)
		arc_table[table[i]] = i;

	//逆元表
	int inverse_table[256];

	for (i = 1; i < 256; ++i)//0没有逆元，所以从1开始
	{
		int k = arc_table[i];
		k = 255 - k;
		k %= 255;//m_table的取值范围为 [0, 254]
		inverse_table[i] = table[k];
	}
	
	printf("(67)对应: %d\n\n", arc_table[67]);
	printf("(111)对应: %d\n\n", arc_table[111]);
	printf("结果多项式对应: %d\n\n", table[(arc_table[67] + arc_table[111]) % 255]);
	printf("(56)逆元对应: %d\n\n", inverse_table[56]);
	system("pause");
	return 0;
}

