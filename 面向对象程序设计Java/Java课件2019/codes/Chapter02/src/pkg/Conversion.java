package pkg;

import java.math.*;

class Conversion {
	public static void main(String args[]) {
		byte b;
		int i = 130;
		double d = 323.842;
		System.out.println("\nConversion of int to byte.");
		b = (byte) i;
		System.out.println("i and b: " + i + " " + b);
		System.out.println("\nConversion of double to int.");
		i = (int) d;
//		 long j = Math.round(d);
		System.out.println("d and i: " + d + " " + i);
		System.out.println("\nConversion of double to byte.");
		b = (byte) d;
		System.out.println("d and b: " + d + " " + b);

		// 计算机采用补码存储整数，int型为32位，byte为8位  
		// 130在内存中的表示形式：00000000 00000000 00000000 10000010  
		// 这样截取后8位就变成10000010，补码表示的时候第一位是符号位，0正1负，  
		// 所以可以知道10000010肯定是一个负数了，再来看它的数值部分，  
		// 正数补码为本身;负数补码：“将其对应正数二进制表示所有位取反，再加1”，  
		// 所以00000010应该变为11111101 + 1 = 11111110 (即-126)
		
		
		int a = 2;
		a/=1;

	}
}