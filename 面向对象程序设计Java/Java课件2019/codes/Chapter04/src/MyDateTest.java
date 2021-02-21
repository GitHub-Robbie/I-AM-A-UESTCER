import java.text.SimpleDateFormat;
import java.util.Date;

/**
 * MyDateTest.java
 */
class DateTest {
	int year;
	int month;
	int day;
}

public class MyDateTest {
	
	public static void main(String[] args) {
		
		DateTest date = new DateTest();
		date.year = 2017;
		date.month = 9;
		date.day = 26;
		System.out.println("The day is: " + 
		date.year + "-" + date.month + "-" + date.day);

		// real date...
		Date date2 = new Date();
		System.out.println("The day is: " + date2.toString());

		SimpleDateFormat f = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
		System.out.println("The day is: " + f.format(date2));
	}
}
