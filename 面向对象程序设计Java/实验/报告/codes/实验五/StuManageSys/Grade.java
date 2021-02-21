package StuManageSys;

public class Grade implements Comparable<Grade>{
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
		this.gNo=gNo;
		this.sNo=sNo;
		this.cName=cName;
		this.tName=tName;
		this.sName=sName;
		this.gPoint=gPoint;
	}
	
	public void setNo(int no) {
		this.gNo = no;
	}
	public int getNo() {
		return gNo;
	}
	
	public int getSNo() {
		return sNo;
	}
	
	public void setCourseName(String name) {
		this.cName = name;
	}
	public String getCourseName() {
		return cName;
	}
	
	public void setTeacherName(String name) {
		this.tName=name;
	}
	public String getTeacherName() {
		return tName;
	}
	
	public void setStudentName(String name) {
		this.sName=name;
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
		return gNo+"\t\t"+sNo+"\t"+sName+"\t"+cName+"\t"+tName+"\t"+gPoint;
	}
	
	public int compareTo(Grade gra) {	//按成绩单号排序
		return gra.getPoint()-this.gPoint;
	}
}