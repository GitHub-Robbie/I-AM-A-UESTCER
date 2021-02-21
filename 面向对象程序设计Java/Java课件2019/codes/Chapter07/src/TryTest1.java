
public class TryTest1 {
	public TryTest1() {
		try {
			int a[] = new int[2];
			a[5] = 3;
			System.out.println("在异常处理后，会返回到这吗?");
		} 
		catch (IndexOutOfBoundsException e) {
//			System.err.println("Exception msg:" + e.getMessage());
//			System.err.println("Exception string:" + e.toString());
			
			
//			e.printStackTrace();
			
			StackTraceElement[] frames = e.getStackTrace();
			for (StackTraceElement f : frames) 
				System.out.println(f.toString());
			
		} 
		finally {
			System.out.println("-------------");
			System.out.println("finally");
		}
		System.out.println("No exception?");
	}

	public static void main(String[] args) {
		new TryTest1();
	}
}