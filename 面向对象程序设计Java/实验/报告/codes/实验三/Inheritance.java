//yuanhaonan
package pkg;



class Person {
	public String name;
	public char sex;
	public int age;

	public Person(String name, char sex, int age) {
		this.name = name;
		this.sex = sex;
		this.age = age;
	}

	public void setData(String name, char sex, int age) {
		this.name = name;
		this.sex = sex;
		this.age = age;
	}

	public Person getData() {
		return this;
	}

	public String toString() {
		return "Name: " + name + ", Sex: " + sex + ", Age: " + age;
	}
}

class Student extends Person {
	public Student() {
		super("Name", 'M', 0); // !!!!
	}

	public int sID;
	public int classNo;

	public void setData(String name, char sex, int age, int sID, int classNo) {
		setData(name, sex, age);
		this.sID = sID;
		this.classNo = classNo;
	}

	public Student getData() {
		return this;
	}

	public String toString() {
		return "Name: " + name + ", Sex: " + sex + ", Age: " + age + ", ID: " + sID + ", Class: " + classNo;
	}
}

class Teacher extends Person {
	public Teacher() {
		super("Name", 'M', 0); // !!!
	}

	public int tID;
	public String department = "NULL";

	public void setData(String name, char sex, int age, int tID, String department) {
		setData(name, sex, age);
		this.tID = tID;
		this.department = department;
	}
}

public class Inheritance {
	public static void main(String[] args) {
		Person person = new Person("Tommy", 'M', 19);
		System.out.println(person);
		person.setData("New", 'F', 20);
		System.out.println(person);
		Student student = new Student();
		System.out.println(student);
		student.setData("Student", 'M', 15, 1001, 1618);
		System.out.println(student);
	}

}
