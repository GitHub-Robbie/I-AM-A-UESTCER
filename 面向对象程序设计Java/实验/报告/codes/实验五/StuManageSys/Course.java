package StuManageSys;

public class Course implements Comparable<Course>{
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
		return cNo+"\t"+cName+"\t"+cCredit+"\t"+cHour;
	}
	
	public int compareTo(Course cour) {	//按学号排序
		return this.cNo-cour.getNo();
	}
}