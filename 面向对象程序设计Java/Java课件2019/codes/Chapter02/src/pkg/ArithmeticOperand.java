package pkg;

import java.math.BigDecimal;

/**
 * 源程序：ArithmeticOperand.java
 */
public class ArithmeticOperand {
	public static void main(String args[]) {
		int a = 5 + 4; // a=9
		int b = a * 2; // b=18
		int c = b / 4; // c=4
		int d = b - c; // d=14
		int e = -d; // e=-14
		int f = e % 4; // f=-2
		int g = 3;
		int h = g++; // h=3, g=4
		int i = ++g; // g=5, i=5
		double j = 6.4;
		double k = j % 4.0; // k=2.4

		BigDecimal jj = new BigDecimal(Double.toString(j));
		BigDecimal tt = new BigDecimal(Double.toString(4.0));

		System.out.println(" a = " + a);
		System.out.println(" b = " + b);
		System.out.println(" c = " + c);
		System.out.println(" d = " + d);
		System.out.println(" e = " + e);
		System.out.println(" f = " + f);
		System.out.println(" g = " + g);
		System.out.println(" h = " + h);
		System.out.println(" i = " + i);
		System.out.println(" j = " + j);
		System.out.println(" k = " + k);

		System.out.println(" exact k = " + jj.remainder(tt));

		System.out.println("0.1+0.0: " + (0.1 + 0.0));
		System.out.println("0.1+0.1: " + (0.1 + 0.1));
		System.out.println("0.1+0.2: " + (0.1 + 0.2));
		System.out.println("0.1+0.3: " + (0.1 + 0.3));
		System.out.println("0.1+0.4: " + (0.1 + 0.4));
		System.out.println("0.1+0.5: " + (0.1 + 0.5));
		System.out.println("0.1+0.6: " + (0.1 + 0.6));
		System.out.println("0.1+0.7: " + (0.1 + 0.7));
		System.out.println("0.1+0.8: " + (0.1 + 0.8));
		System.out.println("0.1+0.9: " + (0.1 + 0.9));
		System.out.println("0.1+1.0: " + (0.1 + 1.0));

		System.out.println("float to Binary code: " + Integer.toBinaryString(Float.floatToIntBits((float) -7.5)));
		System.out.println("double to Binary code: " + Long.toBinaryString(Double.doubleToLongBits(7.5)));
	}
}
