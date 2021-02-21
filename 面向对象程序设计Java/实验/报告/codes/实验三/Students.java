//yuanhaonan
package pkg;

interface Person1 {
	public void setData(String name, char sex, String birthday);

	public String getData();
}

public class Students implements Person1 {
	private String name;
	private char sex;
	private String birthday;
	private int sID;
	private String speciality;

	public void setData(String name, char sex, String birthday) {
		this.name = name;
		this.sex = sex;
		this.birthday = birthday;
	}

	public String getData() {
		return "Name: " + name + " Sex: " + sex + " Birthday: " + birthday + "\n" + "ID: " + sID + " Speciality: "
				+ speciality;
	}

	public void setData(String name, char sex, String birthday, int sID, String speciality) {
		this.name = name;
		this.sex = sex;
		this.birthday = birthday;
		this.sID = sID;
		this.speciality = speciality;
	}

	public static void main(String[] args) {
		Students person = new Students();
		person.setData("Tommy", 'M', "2000.06.27", 1001, "Music");
		System.out.println(person.getData());
	}
}
