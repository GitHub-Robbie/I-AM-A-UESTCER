package StuManageSys;

public class Student implements Comparable<Student> {
	private int sNo;
	private String sName;
	private String sSex;
	private String sBirth; //YYYY.MM.DD
	private String sSchool;
	private String sMajor;
	
	public Student() {
}
	public Student(int sNo, String sName, String sSex, String sBirth, String sSchool, String sMajor) {
		super();
		this.sNo=sNo;
		this.sName=sName;
		this.sSex=sSex;
		this.sBirth=sBirth;
		this.sSchool=sSchool;
		this.sMajor=sMajor;
	}
	
	public void setNo(int no) {
		this.sNo=no;
	}
	public int getNo() {
		return sNo;
	}
	
	public void setName(String name) {
		this.sName=name;
	}
	public String getName() {
		return sName;
	}
	
	public void setSex(String sex) {
		this.sSex=sex;
	}
	public String getSex() {
		return sSex;
	}
	
	public void setBirth(String birth) {
		this.sBirth=birth;
	}
	public String getBirth() {
		return sBirth;
	}
	
	public void setSchool(String school) {
		this.sSchool=school;
	}
	public String getSchool() {
		return sSchool;
	}
	
	public void setMajor(String major) {
		this.sMajor=major;
	}
	public String getMajor() {
		return sMajor;
	}
	
	public String toString() {
		return sNo+"\t"+sName+"\t"+sSex+"\t"+sBirth+"\t"+sSchool+"\t"+sMajor;
	}
	
	public int compareTo(Student stu) {	//按学号排序
		return this.sNo-stu.getNo();
	}
}