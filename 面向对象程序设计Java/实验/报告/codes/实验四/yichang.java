//yuanhaonan
package pkg;

public class yichang {
	public static void main(String[] args) {
		try {
			//System.out.println(1 / 0);// 会抛出ArithmeticException
			//System.out.println(new int[] {}[0]);// 会抛出ArrayIndexOutOfBoundsException
			String str = null;
			System.out.println(str.toString());// 会抛出NullPointerException
		} 
		catch (ArithmeticException e) {
			System.out.println("算术异常");
		} 
		catch (ArrayIndexOutOfBoundsException e) {
			System.out.println("数组下标越界异常");
		} 
		catch (NullPointerException e) {
			System.out.println("空指针异常");
		}
		finally {
			System.out.println("Finnaly");
		}
	}
}
