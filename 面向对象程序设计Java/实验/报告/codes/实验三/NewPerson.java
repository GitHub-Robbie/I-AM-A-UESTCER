//yuanhaonan
package pkg;

public class NewPerson {
	String nameString;
	char sex;
	int age;
	abstract void setData(String name, char sex, int age);
	abstract String getDetail();
}

class Student extends NewPerson {
	int sID;
	String speciality;
}

class Teacher extends NewPerson {
	int tID;
	String departmentString;
}