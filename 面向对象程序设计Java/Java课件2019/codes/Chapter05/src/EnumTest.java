
import java.util.*;

/**
 * This program demonstrates enumerated types.
 */
enum MySize  {
	
	//默认继承自 java.util.Enum 类
	//不能被继承

	// 注：
	//1. 枚举写在最前面，否则编译出错
    //2. 通过括号赋值，如果赋值必须带有一个构造器，否则编译出错;
    //3. 赋值必须都赋值或都不赋值，不能一部分赋值一部分不赋值；
	
	SMALL("S", 1), MEDIUM("M", 2), LARGE("L", 3), 
	EXTRALARGE("XL", 4);
	
	//如果不赋值则不能写构造器，否则编译也出错
//	SMALL(), MEDIUM(), LARGE(), EXTRALARGE();
	
	public String abbreviation;
	int number;
	
	//构造器默认只能是private, 从而保证构造函数只能在内部使用
	MySize(String abbreviation, int number) {//constructor
		this.abbreviation = abbreviation;
		this.number = number;
	}
	
	public String getAbbreviation() { return abbreviation; }
	public int getNumber() { return number; }
}

public class EnumTest {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		System.out.print("Enter a size: (SMALL, MEDIUM, LARGE, EXTRA_LARGE) ");
		String input = in.next().toUpperCase();
		
		MySize size = Enum.valueOf(MySize.class, input);
		
		System.out.println("size=" + size);// equals to size.toString()
		System.out.println("abbreviation=" + 
				size.getAbbreviation() + ", number=" + size.getNumber());

		MySize[] v = MySize.values();
		
		
//		v[1] = Enum.valueOf(MySize.class, input); 
		// we can access a specific element in Enum array.
		
		for (MySize s : v)
			System.out.println(s + ", " + s.ordinal());
	}
}




