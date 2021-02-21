
class StringBufferDemo {

	public static void main(String args[]) {
		StringBuffer sb1 = new StringBuffer();
		StringBuilder sb2 = new StringBuilder();

		System.out.println("sb1: " + sb1 + "length: " 
				+ sb1.length() + ", capacity: " + sb1.capacity());

		sb1.append("Hello!");
		sb2.append("Hello!").append("Hello!");

		System.out.println("sb1: " + sb1 + ", length: " 
				+ sb1.length() + ", capacity: " + sb1.capacity());
		System.out.println("sb2: " + sb2 + ", length: " 
				+ sb2.length() + ", capacity: " + sb2.capacity());

		sb2.insert(2, "@@@@@");

		System.out.println("sb2: " + sb2 + ", length: " 
				+ sb2.length() + ", capacity: " + sb2.capacity());

		// Test the efficiency of String and StringBuffer
		String result = "";
		int it = 100000;
		long begin = System.currentTimeMillis();

		for (int i = 0; i < it; i++) {
			result += "a";
		}
		long end = System.currentTimeMillis();
		System.out.println("String Test Time: " + (end - begin));

		begin = System.currentTimeMillis();
		StringBuilder result2 = new StringBuilder();
		StringBuffer r3 = new StringBuffer();
		for (int i = 0; i < it; i++) {
			r3.append("a");
		}
		System.out.println("StringBuilder Test Time: " 
				+ (System.currentTimeMillis() - begin));
	}
}
