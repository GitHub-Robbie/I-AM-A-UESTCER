//yuanhaonan
package pkg;

import java.util.*;

public class MyDate {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("请输入要设置的年月日");
		System.out.print("年：");
		int year = sc.nextInt();
		System.out.print("月：");
		int month = sc.nextInt();
		System.out.print("日：");
		int day = sc.nextInt();
		Date dt = new Date();
		dt.setDate(year, month, day);
		dt.showDate();
		dt.addDate();
	}

}

class Date {
	private int year;
	private int month;
	private int day;

	public void setDate(int y, int m, int d) {
		year = y;
		month = m;
		day = d;
	}

	void showDate() {
		System.out.println("今天是" + year + "年" + month + "月" + day + "日");
	}

	void addDate() {
		if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10) && day == 31) {
			month += 1;
			day = 1;
		} else if ((month == 4 || month == 6 || month == 9 || month == 11) && day == 30) {
			month += 1;
			day = 1;
		} else if ((month == 2) && (year % 4 == 0 && year % 100 != 0 || year % 100 == 0) && day == 29) {
			month += 1;
			day = 1;
		} else if (month == 12 && day == 31) {
			year += 1;
			day = 1;
		} else {
			day++;
		}
		showDate();
	}

}
