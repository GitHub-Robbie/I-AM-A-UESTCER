/**
 * Fibonacci.java
*/
public class Fibonacci{
	public static void main(String []args){
		int fib[] = new int [10];
		System.out.println(fib[0]);
		fib[0] = 1;
		fib[1] = 1;
		for ( int i = 2; i < 10; i++){
			fib[i] = fib[i-1] + fib[i-2];
		}
		for ( int i = 1; i <= 10; i++){
			System.out.println("Fib[" + i + "] = " + fib[i-1]);
		}
	}
}
