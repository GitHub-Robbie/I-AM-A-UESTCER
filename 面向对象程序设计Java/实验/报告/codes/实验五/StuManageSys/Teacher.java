package StuManageSys;

public class Teacher implements Comparable<Teacher>{
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
		this.tNo=no;
	}
	public int getNo() {
		return tNo;
	}
	
	public void setName(String name) {
		this.tName=name;
	}
	public String getName() {
		return tName;
	}
	
	public void setSchool(String school) {
		this.tSchool=school;
	}
	public String getSchool() {
		return tSchool;
	}
	
	public void setDepartment(String department) {
		this.tDepartment=department;
	}
	public String getDepartment() {
		return tDepartment;
	}
	
	public String toString() {
		return tNo+"\t"+tName+"\t"+tSchool+"\t"+tDepartment;
	}

	@Override
	public int compareTo(Teacher o) {
		// TODO Auto-generated method stub
		return 0;
	}
}
