public class StringTest {
	public static void main(String args[]) {
		char c[] = {'J', 'a', 'v', 'a'};
		String s1 = new String(c);
		System.out.println("s1: "+s1);

		
		String s2 = "String" + 1 + 2 + 3 + 4 + 5;
		System.out.println("s2: "+s2);
		String s3 = 1 + 2 + 3 + 4 + 5 + "String";
		System.out.println("s3: "+s3);
		
		char ch;
		ch = s1.charAt(1);
		System.out.println("ch: "+ch);
		
		String s = "This is a demo of the getChars method.";
		int start = 0;
		int end = 4;
		char buf[] = new char[end - start];
		s.getChars(start, end, buf, 0);
		System.out.println(buf);
		
		s1 = "Hello";
		s2 = "Hello";
		s3 = "Good-bye";
		String s4 = "HELLO";
		System.out.println(s1 + " equals " + s2 + " -> " + s1.equals(s2));
		System.out.println(s1 + " equals " + s3 + " -> " + s1.equals(s3));
		System.out.println(s1 + " equals " + s4 + " -> " + s1.equals(s4));
		System.out.println(s1 + " equalsIgnoreCase " + s4 + " -> " + s1.equalsIgnoreCase(s4));
	
		s1 = "Hello";
		s2 = new String(s1);
		s3 = s1;
		s4 = "Hell";
		String s5 = "Hello!";
		System.out.println(s1 + " equals " + s2 + " -> " + s1.equals(s2));
		System.out.println(s1 + " == " + s2 + " -> " + (s1 == s2));//the same string, different memory 
		System.out.println(s1 + " == " + s2 + " -> " + (s1 == s3));//the same string and memory
		
		System.out.println(s1 + " compare to " + s2 + " -> " + s1.compareTo(s2));//equals return true
		System.out.println(s1 + " compare to " + s3 + " -> " + s1.compareTo(s4));
		System.out.println(s1 + " compare to " + s3 + " -> " + s1.compareTo(s5));
		
		char[] data = "Car".toCharArray();
		System.out.println(String.copyValueOf(data));
		System.out.println(String.valueOf(data));
		
		s1 = s1.substring(0, 4) + " world.";
		System.out.println(s1);
		
		String s6 = "";
		String s7 = null;
		System.out.println("empty string length: " + s6.length());
		System.out.println("empty string length: " + s7.length());
		
	}
}
