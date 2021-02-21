#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
int c[MAX];
int temp_new[MAX];
int temp2[MAX];
int q[MAX];
int q_new[MAX];
int r[MAX];
int r_new[MAX];
int super = 0;
int flag = 0;
int flag1 = 0;

int u2[MAX];
int u1[MAX];
int v2[MAX];
int v1[MAX];
int u[MAX];
int v[MAX];
int d[MAX];


int Add(int f[], int g[])	//	0用来存放最高项次数
{
	memset(c, 0, sizeof(c));
	int ft = checktimes(f);
	int gt = checktimes(g);
	int ct = (ft > gt ? ft : gt);
	c[ct + 1] = MAX;
	int i;
	for (i = 0; i <= ct; i++)
	{
		if (f[i] != MAX && g[i] != MAX)
			c[i] = f[i] + g[i];
		else if (f[i] == MAX)
			c[i] = g[i];
		else
			c[i] = f[i];
	}
	while (c[ct] == 0)
		if (c[ct] == 0)
		{
			c[ct + 1] = 0;
			c[ct] = MAX;
			ct--;
		}
	return ct;
}

int checktimes(int a[])
{
	int i;
	for (i = 0; i < MAX; i++)
	{
		if (a[i] == MAX)
		{
			if (i == 0)
				return i;
			else
				return i - 1;
		}
	}
}

int Sub(int f[], int g[])//f-g
{
	//	memset(c, 0, sizeof(c));
	int ft = checktimes(f);
	int gt = checktimes(g);
	int i;
	for (i = 0; i < gt + 1; i++)
		g[i] *= (-1);
	int ct = (ft > gt ? ft : gt);
	c[ct + 1] = MAX;
	for (i = 0; i <= ct; i++)
	{
		if (f[i] != MAX && g[i] != MAX)
			c[i] = f[i] + g[i];
		else if (f[i] == MAX)
			c[i] = g[i];
		else
			c[i] = f[i];
	}
	while (c[ct] == 0)
		if (c[ct] == 0 && ct >= 0)
		{
			c[ct + 1] = 0;
			c[ct] = MAX;
			ct--;
		}
		else
			ct = 0;
	return ct;
}

int Mul(int f[], int g[])
{
	memset(c, 0, sizeof(c));
	int ft = checktimes(f);
	int gt = checktimes(g);
	int i, j;
	int ct = ft + gt;
	c[ct + 1] = MAX;
	for (i = 0; i < ft + 1; i++)
	{
		for (j = 0; j < gt + 1; j++)
		{
			c[i + j] = f[i] * g[j] + c[i + j];
		}

	}
	return ct;
}
int checkn(int a[])
{
	int i = 0;
	int count = 0;
	int times = checktimes(a);
	if (times == 0)
		return 0;
	else
	{
		for (i = 0; i <= times; i++)
		{
			if (a[i] != 0)
				count++;
		}
	}
	return count;
}
int Div(int f[], int g[])//f÷g
{
	memset(c, 0, sizeof(c));
	memset(r, 0, sizeof(r));
	memset(q, 0, sizeof(q));
//	memcpy(q, q_new, sizeof(int)*(flag + 2));
	int ft = checktimes(f);
	int gt = checktimes(g);
	int qt;
	if (ft < gt)
	{
		q[super] = 0;
		//		q[super] = MAX;
		memcpy(r, f, sizeof(int)*(ft + 1));
		return 0;
	}
	else//c作为每次的余数
	{
		if (ft == gt && checkn(f) < checkn(g))
			return 0;
		qt = ft - gt;
		super = qt;

		q_new[super] = f[ft] / g[gt];
		if (flag1 < qt)
			flag1 = qt;
		q_new[flag1 + 1] = MAX;
		q[super + 1] = MAX;
		q[super]= f[ft] / g[gt];
		int temp[MAX];

		do
		{
 			int k = Mul(q, g);
			memcpy(temp_new, c, sizeof(int)*(k + 1));
			temp_new[k + 1] = MAX;
			int ct = Sub(f, temp_new);
			int qt = checktimes(q);
			flag = qt;
			if (ct == 0)
			{
				memcpy(q_new, q, sizeof(int)*(qt + 2));
				memcpy(r_new, c, sizeof(int)*(ct + 2));
				r_new[ct + 1] = MAX;
				return qt;
			}
			else {
				memcpy(r_new, c, sizeof(int)*(ct + 2));
				r_new[ct + 1] = MAX;
				memset(f, 0, sizeof(f));
				memcpy(f, c, sizeof(int)*(ct + 2));

				//			memcpy(q_new, q, sizeof(int)*(qt + 2));
				if (Div(f, g) == 0)
				{
					return qt;
				}
			}
		} while (checktimes(c) >= gt);
	}
}

int Euclid(int f[], int g[])
{
	u2[0] = 1, u2[1] = MAX;
	int u2t = 1;
	u1[0] = 0, u1[1] = MAX;
	int u1t = 0;
	v2[0] = 0, v2[1] = MAX;
	int v2t = 0;
	v1[0] = 1, v1[1] = MAX;
	int v1t = 1;
	int gt = checktimes(g);
	int gn = checkn(g);
	int ft = checktimes(f);
	int fn = checkn(f);
	while (gt != 0 && gn != 0)
	{
		//	memset(q, 0, sizeof(q));
		//	memset(r, 0, sizeof(r));
//		memset(q_new, 0, sizeof(q_new));
		int qt = Div(f, g);
		int rt = checktimes(r_new);
		Mul(q_new, u1);	//结果是c
		int ut = Sub(u2, c);		//结果是c
		memcpy(u, c, sizeof(int)*(ut + 2));

		Mul(q_new, v1);	//结果是c
		int vt = Sub(v2, c);
		memcpy(v, c, sizeof(int)*(vt + 2));

		//  		memset(v, 0, sizeof(v));
		   //	memcpy(v, c, sizeof(int)*(vt + 2));
		memset(f, 0, sizeof(f));
		memcpy(f, g, sizeof(int)*(gt + 2));
		memset(g, 0, sizeof(g));
		memcpy(g, r_new, sizeof(int)*(rt + 2));

		u1t = checktimes(u1);
		u2t = checktimes(u2);
		v1t = checktimes(v1);
		v2t = checktimes(v2);
		memset(u2, 0, sizeof(u2));
		memcpy(u2, u1, sizeof(int)*(u1t + 2));
		memset(u1, 0, sizeof(u1));
		memcpy(u1, u, sizeof(int)*(ut + 2));
		memset(v2, 0, sizeof(v2));
		memcpy(v2, v1, sizeof(int)*(v1t + 2));
		memset(v1, 0, sizeof(v1));
		memcpy(v1, v, sizeof(int)*(vt + 2));
		gt = checktimes(g);
		gn = checkn(g);
	}
	memset(d, 0, sizeof(d));
	ft = checktimes(f);
	memcpy(d, f, sizeof(int)*(ft + 2));
	memset(u, 0, sizeof(u)); 
	u2t = checktimes(u2);
	memcpy(u, u2, sizeof(int)*(u2t + 2));
	memset(v, 0, sizeof(v));
	v2t = checktimes(v2);
	memcpy(v, v2, sizeof(int)*(v2t + 2));
	int vt = checktimes(v);
	return vt;
}

int main()
{
	int f[6] = { -2,-4,-1,2,1,MAX };
	int g[6] = { -2,-2,-1,1,1,MAX };
	//int ct = Add(f, g);
	int i = 0;
	//for (i = 0; i < ct+1; i++)
	//	printf("%d", c[i]);
	//ct = Sub(f, g);
	//for (i = 0; i < ct + 1; i++)
	//	printf("%d", c[i]);
	//int ct = Div(f, g);
	int vt = Euclid(f, g);
	for (i = 0; i < vt + 1; i++)
		printf("%d", v[i]);
	system("pause");
	return 0;
}