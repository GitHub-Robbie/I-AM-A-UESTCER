#include <stdio.h>
int main()
{
	float loan, rate, payment, m;
	
	printf("Enter amount of loan: ");
	scanf("%f", &loan);
	printf("Enter interest rate: ");
	scanf("%f", &rate);
	printf("Enter monthly payment: ");
	scanf("%f", &payment);
	printf("\n");
	m = rate * 0.01 / 12;
	
	loan = loan * (1 + m) - payment;
	printf("Balance remaining after first payment: $%.2f\n", loan);
	
	loan = loan * (1 + m) - payment;
	printf("Balance remaining after second payment: $%.2f\n", loan);

	loan = loan * (1 + m) - payment;
	printf("Balance remaining after third payment: $%.2f\n", loan);
	
	return 0;
}
