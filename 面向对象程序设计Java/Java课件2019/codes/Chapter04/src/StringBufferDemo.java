
class StringBufferDemo {

	public static void main(String args[]) {
		StringBuffer sb1 = new StringBuffer();
		StringBuilder sb2 = new StringBuilder();

		System.out.println("sb1: " + sb1 + ", length: " + 
		sb1.length() + ", capacity: " + sb1.capacity());
		System.out.println("sb2: " + sb2 + ", length: " + 
		sb2.length() + ", capacity: " + sb2.capacity());
		
		sb1.append("Hello!");
		sb1.append("Hello!");
		sb1.append("Hello");
		sb1.append(sb1);
		sb1.append("1");
//		sb1.append(sb1).append("1");
		sb2.append("Hello!");

		System.out.println("sb1: " + sb1 + ", length: " + sb1.length() 
		+ ", capacity: " + sb1.capacity());
		System.out.println("sb2: " + sb2 + ", length: " + sb2.length() 
		+ ", capacity: " + sb2.capacity());
		
		sb2.insert(2, "abc");
		
		System.out.println("sb2: " + sb2 + ", length: " + sb2.length() + ", capacity: " + sb2.capacity());
		
		
        long begin = System.currentTimeMillis();
        String str = "";
        StringBuilder sb = new StringBuilder();
        for(int i=0;i<10000;i++){
//            str = str+i;
//            str = str.concat(String.valueOf(i));
            sb.append(i);
        }
        long end = System.currentTimeMillis();
        long time = end - begin;
        System.out.println(time+"");
        

		
	}
}
