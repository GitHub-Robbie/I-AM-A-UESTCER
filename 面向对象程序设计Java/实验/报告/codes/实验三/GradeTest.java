//yuanhaonan
package pkg2;

public class GradeTest {

	public static void main(String[] args) {
		Grade grade = new Grade();
		Student student = new Student(2018001, "张三", "男", "20000627", "软件学院", "软工");
		Teacher teacher = new Teacher(1001, "李老师", "软件", "网安");
		Course course = new Course(888001, "Java", 2, 48);
		grade.stu = student;
		grade.tea = teacher;
		grade.cour = course;
		grade.setNo(grade.stu.getNo());
		grade.setStudentName(grade.stu.getName());
		grade.setCourseName(grade.cour.getName());
		grade.setTeacherName(grade.tea.getName());
		grade.setPoint(100);
		grade.setGNo(66660001);

		System.out.print(grade.toString());
	}

}

class Student {
	private int sNo;
	private String sName;
	private String sSex;
	private String sBirth; // YYYY.MM.DD
	private String sSchool;
	private String sMajor;

	public Student() {
	}

	public Student(int sNo, String sName, String sSex, String sBirth, String sSchool, String sMajor) {
		super();
		this.sNo = sNo;
		this.sName = sName;
		this.sSex = sSex;
		this.sBirth = sBirth;
		this.sSchool = sSchool;
		this.sMajor = sMajor;
	}

	public void setNo(int no) {
		this.sNo = no;
	}

	public int getNo() {
		return sNo;
	}

	public void setName(String name) {
		this.sName = name;
	}

	public String getName() {
		return sName;
	}

	public void setSex(String sex) {
		this.sSex = sex;
	}

	public String getSex() {
		return sSex;
	}

	public void setBirth(String birth) {
		this.sBirth = birth;
	}

	public String getBirth() {
		return sBirth;
	}

	public void setSchool(String school) {
		this.sSchool = school;
	}

	public String getSchool() {
		return sSchool;
	}

	public void setMajor(String major) {
		this.sMajor = major;
	}

	public String getMajor() {
		return sMajor;
	}

	public String toString() {
		return sNo + "\t" + sName + "\t" + sSex + "\t" + sBirth + "\t" + sSchool + "\t" + sMajor;
	}
}

class Teacher {
	private int tNo;
	private String tName;
	private String tSchool;
	private String tDepartment;

	public Teacher() {
	}

	public Teacher(int tNo, String tName, String tSchool, String tDepartment) {
		super();
		this.tNo = tNo;
		this.tName = tName;
		this.tSchool = tSchool;
		this.tDepartment = tDepartment;
	}

	public void setNo(int no) {
		this.tNo = no;
	}

	public int getNo() {
		return tNo;
	}

	public void setName(String name) {
		this.tName = name;
	}

	public String getName() {
		return tName;
	}

	public void setSchool(String school) {
		this.tSchool = school;
	}

	public String getSchool() {
		return tSchool;
	}

	public void setDepartment(String department) {
		this.tDepartment = department;
	}

	public String getDepartment() {
		return tDepartment;
	}

	public String toString() {
		return tNo + "\t" + tName + "\t" + tSchool + "\t" + tDepartment;
	}
}

class Course {
	private int cNo;
	private String cName;
	private int cCredit;
	private int cHour;

	public Course() {
	}

	public Course(int cNo, String cName, int cCredit, int cHour) {
		super();
		this.cNo = cNo;
		this.cName = cName;
		this.cCredit = cCredit;
		this.cHour = cHour;
	}

	public void setNo(int no) {
		this.cNo = no;
	}

	public int getNo() {
		return cNo;
	}

	public void setName(String name) {
		this.cName = name;
	}

	public String getName() {
		return cName;
	}

	public void setCredit(int credit) {
		this.cCredit = credit;
	}

	public int getCredit() {
		return cCredit;
	}

	public void setHour(int hour) {
		this.cHour = hour;
	}

	public int getHour() {
		return cHour;
	}

	public String toString() {
		return cNo + "\t" + cName + "\t" + cCredit + "\t" + cHour;
	}
}

class Grade {
	public Student stu;

	public Student getStu() {
		return stu;
	}

	public void setStu(Student stu) {
		this.stu = stu;
	}

	public Teacher tea;

	public Teacher getTea() {
		return tea;
	}

	public void setTea(Teacher tea) {
		this.tea = tea;
	}

	public Course cour;

	public Course getCour() {
		return cour;
	}

	public void setCour(Course cour) {
		this.cour = cour;
	}

	private int gNo;
	private int sNo;
	private String cName;
	private String tName;
	private String sName;
	private int gPoint;

	public Grade() {
	}

	public Grade(int gNo, int sNo, String sName, String cName, String tName, int gPoint) {
		super();
		this.gNo = gNo;
		this.sNo = sNo;
		this.cName = cName;
		this.tName = tName;
		this.sName = sName;
		this.gPoint = gPoint;
	}

	public void setNo(int no) {
		this.sNo = no;
	}

	public int getSNo() {
		return sNo;
	}

	public void setGNo(int no) {
		this.gNo = no;
	}

	public int getGNo() {
		return gNo;
	}

	public void setCourseName(String name) {
		this.cName = name;
	}

	public String getCourseName() {
		return cName;
	}

	public void setTeacherName(String name) {
		this.tName = name;
	}

	public String getTeacherName() {
		return tName;
	}

	public void setStudentName(String name) {
		this.sName = name;
	}

	public String getStudentName() {
		return sName;
	}

	public void setPoint(int point) {
		this.gPoint = point;
	}

	public int getPoint() {
		return gPoint;
	}

	public String toString() {
		return gNo + "\t" + sNo + "\t" + sName + "\t" + cName + "\t" + tName + "\t" + gPoint;
	}
}
