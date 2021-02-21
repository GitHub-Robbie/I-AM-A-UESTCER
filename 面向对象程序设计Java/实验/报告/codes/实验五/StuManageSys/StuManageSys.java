package StuManageSys;

import java.util.Collections;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;
import java.io.*;

public class StuManageSys {
	static List<Student> StuList = new LinkedList<Student>();
	static List<Teacher> TechList = new LinkedList<Teacher>();
	static List<Course> CourseList = new LinkedList<Course>();
	static List<Grade> GradeList = new LinkedList<Grade>();
	public static int mStatus,sStatus,tStatus;
	static Scanner sc=new Scanner(System.in);
	
	public static void main(String[] args) throws IOException {
		// 简单的欢迎界面
		readTxt(1);
		readTxt(2);
		readTxt(3);
		readTxt(4);
		System.out.println("------------------------------------------------------------------");
		System.err.println("\t\t\t" + "欢迎进入学生成绩管理系统");
		System.out.println("------------------------------------------------------------------");
		System.out.println("\t    请选择登录角色:   1. 学生   2. 教师   3. 教务员");

		int input = sc.nextInt();
		switch (input) {
		case 1: {
			if(stuLogin()==1) {
				while(true) {
					stuMenu();
					int opt = sc.nextInt();
					switch (opt) {
					case 1: {
						sStatus =0;
						while (sStatus == 0) 
							sInfo(); 
						break;
					}
					case 2: {
						sStatus=0;
						while(sStatus==0) {
							courseFind();
							System.out.println("返回主菜单? (y/n): ");
							char yn = sc.next().charAt(0);
							if (yn == 'y') 
								sStatus = 1;
						} break;
					}
					case 3: {
						sStatus=0;
						while(sStatus==0) {
							sGradeCheck();
						} break;
					}
					case 4: {
						System.exit(1);
					}
					}
				}
			}
		}
		case 2: {
			if(teaLogin()==1) {
				while(true) {
					teaMenu();
					int opt = sc.nextInt();
					switch (opt) {
					case 1: {
						tStatus=0;
						while(tStatus==0)
							tInfo();
						break;
					}
					case 2: {
						tStatus=0;
						while(tStatus==0)
							tAddCour();
						break;
					}
					case 3: {
						tStatus=0;
						while(tStatus==0)
							tAddGrade();
						break;
					}
					default: System.exit(1);
					}
				}
			}
		}
		case 3: {
			if (manaLogin()==1) {
				while (true) {
					manaMenu();
					int opt = sc.nextInt();
					switch (opt) {
					case 1: {
						mStatus =0;
						while (mStatus == 0) 
							manaFuncStu(); 
						break;
					}
					case 2: {
						mStatus=0;
						while(mStatus==0)
							manaFuncTea();
						break;
					}
					case 3: {
						mStatus=0;
						while(mStatus==0)
							manaFuncCourse();
						break;
					}
					case 4: {
						mStatus=0;
						while(mStatus==0)
							manaFuncGrade();
						break;
					}
					default: System.exit(1);
					}
				}
			}
		}
		}
	}
	
	public static int readTxt(int i) throws FileNotFoundException {	//0学生, 1教师, 2课程
		switch(i) {
		case 1: {
			Scanner file=new Scanner(new File("src/stuManageSys/Student.txt"));
			while(file.hasNextLine()) {
				String temp=file.nextLine();
				String split[]=temp.split("\t");
				int no[]=new int[100];
				no[0]=Integer.valueOf(split[0]).intValue();
				StuList.add(new Student(no[0],split[1], split[2], split[3], split[4], split[5]));
			}
			file.close();
			break;
		}
		case 2: {
				Scanner file=new Scanner(new File("src/stuManageSys/Teacher.txt"));
				while(file.hasNextLine()) {
					String temp=file.nextLine();
					String split[]=temp.split("\t");
					int no[]=new int[100];
					no[0]=Integer.valueOf(split[0]).intValue();
					TechList.add(new Teacher(no[0],split[1], split[2], split[3]));
				}
				file.close();
				break;
		}
		case 3: {
				Scanner file=new Scanner(new File("src/stuManageSys/Course.txt"));
				while(file.hasNextLine()) {
					String temp=file.nextLine();
					String split[]=temp.split("\t");
					int no[]=new int[100];
					no[0]=Integer.valueOf(split[0]).intValue();
					no[2]=Integer.valueOf(split[2]).intValue();
					no[3]=Integer.valueOf(split[3]).intValue();
					CourseList.add(new Course(no[0],split[1], no[2], no[3]));
				}
				file.close();
				break;
		}
		case 4: {
			Scanner file=new Scanner(new File("src/stuManageSys/Grade.txt"));
			while(file.hasNextLine()) {
				String temp=file.nextLine();
				String split[]=temp.split("\t");
				int no[]=new int[100];
				no[0]=Integer.valueOf(split[0]).intValue();
				no[1]=Integer.valueOf(split[1]).intValue();
				no[5]=Integer.valueOf(split[5]).intValue();
				GradeList.add(new Grade(no[0],no[1],split[2], split[3], split[4], no[5]));
			}
			file.close();
			break;
	}
		}
		return 1;
	}
	
	public static int outputTxt(int i) throws IOException {
		switch(i) {
		case 1: {
			File ofile=new File("src/stuManageSys/Student.txt");
			if (!ofile.isFile()) {
	            ofile.createNewFile();
	        }
	        BufferedWriter writer = new BufferedWriter(new FileWriter("src/stuManageSys/Student.txt"));
	        for (Student stu:StuList){
	            writer.write(stu.toString() + "\n");
	        }
	        writer.close();
	        break;
		}
		case 2: {
			File ofile=new File("src/stuManageSys/Teacher.txt");
			if (!ofile.isFile()) {
	            ofile.createNewFile();
	        }
	        BufferedWriter writer = new BufferedWriter(new FileWriter("src/stuManageSys/Teacher.txt"));
	        for (Teacher tech:TechList){
	            writer.write(tech.toString() + "\n");
	        }
	        writer.close();
	        break;
		}
		case 3: {
			File ofile=new File("src/stuManageSys/Course.txt");
			if (!ofile.isFile()) {
	            ofile.createNewFile();
	        }
	        BufferedWriter writer = new BufferedWriter(new FileWriter("src/stuManageSys/Course.txt"));
	        for (Course cour:CourseList){
	            writer.write(cour.toString() + "\n");
	        }
	        writer.close();
	        break;
		}
		case 4: {
			File ofile=new File("src/stuManageSys/Grade.txt");
			if (!ofile.isFile()) {
	            ofile.createNewFile();
	        }
	        BufferedWriter writer = new BufferedWriter(new FileWriter("src/stuManageSys/Grade.txt"));
	        for (Grade gra:GradeList){
	            writer.write(gra.toString() + "\n");
	        }
	        writer.close();
	        break;
		}
		}
		return 1;
	}
	
	public static void stuMenu() {
		System.err.println("\n\t*功能菜单*");
		System.out.println("------------------------------------------------------------------");
		System.out.println("\t\t\t1、修改个人信息");
		System.out.println("\t\t\t2、查询课程信息");
		System.out.println("\t\t\t3、查询成绩");
		System.out.println("\t\t\t4、退出系统");
		System.out.println("------------------------------------------------------------------");
		System.out.print("请输入对应的数字进行操作:");
	}
	
	public static void teaMenu() {
		System.err.println("\n\t*功能菜单*");
		System.out.println("------------------------------------------------------------------");
		System.out.println("\t\t\t1、修改个人信息");
		System.out.println("\t\t\t2、添加课程信息");
		System.out.println("\t\t\t3、添加成绩信息");
		System.out.println("\t\t\t4、退出系统");
		System.out.println("------------------------------------------------------------------");
		System.out.print("请输入对应的数字进行操作:");
	}
	
	public static void sInfo() throws IOException {
		int stu=0;
		for(int j=0;j<StuList.size();j++) {
			if(StuList.get(j).getNo()==201818001) {
				System.out.println("学号\t\t姓名\t性别\t生日\t\t学院\t专业");
				System.out.println(StuList.get(j).toString());
				stu=j;
			} break;
		}
		System.out.println("请按对应格式输入修改后的学生信息! ");
		Scanner line=new Scanner(System.in);
		String update=line.nextLine();
		String split[]=update.split("\t");
		int no[]=new int[100];
		no[0]=Integer.valueOf(split[0]).intValue();
		line.close();
		StuList.get(stu).setNo(no[0]);
		StuList.get(stu).setName(split[1]);
		StuList.get(stu).setSex(split[2]);
		StuList.get(stu).setBirth(split[3]);
		StuList.get(stu).setSchool(split[4]);
		StuList.get(stu).setMajor(split[5]);
		System.out.println("修改后的学生信息: ");
		System.out.println("学号\t\t姓名\t性别\t生日\t\t学院\t专业");
		System.out.println(StuList.get(stu).toString());
		if(outputTxt(1)==1)
			System.out.println("操作已保存至文件!");
		System.out.println("返回主菜单? (y/n): ");
		char yn = sc.next().charAt(0);
		if (yn == 'y') 
			sStatus = 1;
	}
	
	public static void sGradeCheck() {
		System.out.println("成绩单号\t\t学号\t\t姓名\t课程\t\t教师\t成绩");
		for(int j=0;j<GradeList.size();j++) {
			if(GradeList.get(j).getSNo()==201818001) {
				System.out.println(GradeList.get(j).toString());
			}
		}
		System.out.println("返回主菜单? (y/n): ");
		char yn = sc.next().charAt(0);
		if (yn == 'y') 
			sStatus = 1;
	}
	
	public static void tInfo() throws IOException {
		int tea=0;
		for(int j=0;j<TechList.size();j++) {
			if(TechList.get(j).getNo()==1001) {
				System.out.println("编号\t姓名\t学院\t系");
				System.out.println(TechList.get(j).toString());
				tea=j;
			} break;
		}
		System.out.println("请按对应格式输入修改后的教师信息! ");
		Scanner line=new Scanner(System.in);
		String update=line.nextLine();
		String split[]=update.split("\t");
		line.close();
		int no[]=new int[100];
		no[0]=Integer.valueOf(split[0]).intValue();
		TechList.get(tea).setNo(no[0]);
		TechList.get(tea).setName(split[1]);
		TechList.get(tea).setSchool(split[2]);
		TechList.get(tea).setDepartment(split[3]);
		System.out.println("修改后的教师信息: ");
		System.out.println("编号\t姓名\t学院\t系");
		System.out.println(TechList.get(tea).toString());
		if(outputTxt(2)==1)
			System.out.println("操作已保存至文件!");
		System.out.println("返回主菜单? (y/n): ");
		char yn = sc.next().charAt(0);
		if (yn == 'y') 
			tStatus = 1;
		}
		
	public static void tAddCour() throws IOException {
		System.out.println("请按对应格式输入新增的课程信息! ");
		Scanner line=new Scanner(System.in);
		String update=line.nextLine();
		String split[]=update.split("\t");
		line.close();
		int no[]=new int[100];
		no[0]=Integer.valueOf(split[0]).intValue();
		no[2]=Integer.valueOf(split[2]).intValue();
		no[3]=Integer.valueOf(split[3]).intValue();
		CourseList.add(new Course(no[0],split[1], no[2], no[3]));
		System.out.println("新增的课程信息: ");
		System.out.println("课程号\t\t名称\t学分\t学时");
		System.out.println(no[0]+"\t"+split[1]+"\t"+no[2]+"\t"+no[3]);
		if(outputTxt(3)==1)
			System.out.println("操作已保存至文件!");
		System.out.println("返回主菜单? (y/n): ");
		char yn = sc.next().charAt(0);
		if (yn == 'y') 
			tStatus = 1;
	}
	
	public static void tAddGrade() throws IOException {
		System.out.println("请按对应格式录入成绩信息! ");
		Scanner line=new Scanner(System.in);
		String update=line.nextLine();
		String split[]=update.split("\t");
		line.close();
		int no[]=new int[100];
		no[0]=Integer.valueOf(split[0]).intValue();
		no[1]=Integer.valueOf(split[1]).intValue();
		no[5]=Integer.valueOf(split[5]).intValue();
		GradeList.add(new Grade(no[0],no[1],split[2], split[3], split[4], no[5]));
		System.out.println("录入的成绩信息: ");
		System.out.println("成绩单号\t\t学号\t\t姓名\t课程\t教师\t成绩");
		System.out.println(no[0]+"\t\t"+no[1]+"\t"+split[2]+"\t"+split[3]+"\t"+split[4]+"\t"+no[5]);
		if(outputTxt(4)==1)
			System.out.println("操作已保存至文件!");
		System.out.println("返回主菜单? (y/n): ");
		char yn = sc.next().charAt(0);
		if (yn == 'y') 
			tStatus = 1;
	}
	
 	public static void manaMenu() {
		System.err.println("\n\t*功能菜单*");
		System.out.println("------------------------------------------------------------------");
		System.out.println("\t\t\t1、管理学生信息");
		System.out.println("\t\t\t2、管理教师信息");
		System.out.println("\t\t\t3、管理课程信息");
		System.out.println("\t\t\t4、打印成绩单");
		System.out.println("\t\t\t5、退出系统");
		System.out.println("------------------------------------------------------------------");
		System.out.print("请输入对应的数字进行操作:");
	}
	
	public static int manaLogin() {	//Eclipse下运行会报错，用Terminal即可
		System.err.print("请输入管理员账号: ");
		int id = sc.nextInt();
		System.err.print("请输入密码: ");
		int pwd = sc.nextInt();
		if(id == 8888 && pwd == 666)
			return 1;
		else
			return 0;
	}

	public static int stuLogin() {
		System.err.print("请输入学号: ");
		int id = sc.nextInt();
		System.err.print("请输入密码: ");
		int pwd = sc.nextInt();
		if(id == 201818001 && pwd == 666)
			return 1;
		else
			return 0;
	}
	
	public static int teaLogin() {
		System.err.print("请输入教工号: ");
		int id = sc.nextInt();
		System.err.print("请输入密码: ");
		int pwd = sc.nextInt();
		if(id == 1001 && pwd == 666)
			return 1;
		else
			return 0;
	}
	
	public static void stuView() {
		if (StuList.isEmpty() == true) {
			System.out.println("无学生信息! ");
		} else {
			System.out.println("所有学生信息: ");
			System.out.println("学号\t\t姓名\t性别\t生日\t\t学院\t专业");
			for (int j = 0; j < StuList.size(); j++) {
				Collections.sort(StuList);
				System.out.println(StuList.get(j).toString());
			}
		}
	}
	
	public static int stuFind() {
		int j=0;
		if (StuList.isEmpty() == true) {
			System.out.println("无学生信息! ");
			return -1;
		} else {
			System.out.println("请输入学生学号: ");
			int no=sc.nextInt();
			for (j = 0; j < StuList.size(); j++) {
				if(StuList.get(j).getNo()==no)
					break;
			}
			if(j==StuList.size()) {
				System.out.println("无待查学生信息! ");
				return -2;
			} else {
			System.out.println("所查找的学生信息: ");
			System.out.println("学号\t\t姓名\t性别\t生日\t\t学院\t专业");
			System.out.println(StuList.get(j).toString());
			return j;
			}
		}		
	}
	
	public static void manaFuncStu() throws IOException {
		System.err.println("\n\t*管理学生信息*");
		System.out.println("------------------------------------------------------------------");
		System.out.println("\t\t\t1、显示所有学生信息");
		System.out.println("\t\t\t2、查找学生信息");
		System.out.println("\t\t\t3、导入学生信息");
		System.out.println("\t\t\t4、删除学生信息");
		System.out.println("\t\t\t5、修改学生信息");
		System.out.println("\t\t\t6、返回管理员主界面");
		System.out.println("------------------------------------------------------------------");
		int sopt = sc.nextInt();
		switch (sopt) {
		case 1: {
			stuView();
			System.out.println("返回上一级? (y/n): ");
			char yn = sc.next().charAt(0);
			if (yn == 'n') {
				mStatus = 1;
				break;
			} else
				break;
		}
		case 2: {
			stuFind();
			System.out.println("返回上一级? (y/n): ");
			char yn = sc.next().charAt(0);
			if (yn == 'n') {
				mStatus = 1;
				break;
			} else
				break;
		}
		case 3: {
			System.out.println("导入学生信息成功! ");
			System.out.println("返回上一级? (y/n): ");
			char yn = sc.next().charAt(0);
			if (yn=='n') {
				mStatus = 1;
				break;
			} else
				break;
		}
		case 4: {
			int stu=stuFind();
			if(stu<0) {
				System.out.println("返回上一级? (y/n): ");
				char yn = sc.next().charAt(0);
				if (yn == 'n') {
					mStatus = 1;
					break;
				} else
					break;
				}
			else {
				System.out.println("是否删除该条学生信息? (y/n)");
				char yn = sc.next().charAt(0);
				if (yn=='y') {
					StuList.remove(stu);
					System.out.println("删除成功! ");
					if(outputTxt(1)==1)
						System.out.println("操作已保存至文件!");
			}
				System.out.println("返回上一级? (y/n): ");
				yn = sc.next().charAt(0);
				if (yn == 'n') {
					mStatus = 1;
					break;
				} else
					break;
		}
		}
		case 5: {
			int stu=stuFind();
			if(stu<0) {
				System.out.println("返回上一级? (y/n): ");
				char yn = sc.next().charAt(0);
				if (yn == 'n') {
					mStatus = 1;
					break;
				} else
					break;
			}
			else {
			System.out.println("请按对应格式输入修改后的学生信息! ");
			Scanner line=new Scanner(System.in);
			String update=line.nextLine();
			String split[]=update.split("\t");
			line.close();
			int no[]=new int[100];
			no[0]=Integer.valueOf(split[0]).intValue();
			StuList.get(stu).setNo(no[0]);
			StuList.get(stu).setName(split[1]);
			StuList.get(stu).setSex(split[2]);
			StuList.get(stu).setBirth(split[3]);
			StuList.get(stu).setSchool(split[4]);
			StuList.get(stu).setMajor(split[5]);
			System.out.println("修改后的学生信息: ");
			System.out.println("学号\t\t姓名\t性别\t生日\t\t学院\t专业");
			System.out.println(StuList.get(stu).toString());
			if(outputTxt(1)==1)
				System.out.println("操作已保存至文件!");
			System.out.println("返回上一级? (y/n): ");
			char yn;
			yn = sc.next().charAt(0);
			if (yn == 'n') {
				mStatus = 1;
				break;
			} else
				break;
		}
		}
		default: mStatus=1;
	}
}

	public static void teaView() {
		if (TechList.isEmpty() == true) {
			System.out.println("无教师信息! ");
		} else {
			System.out.println("所有教师信息: ");
			System.out.println("编号\t姓名\t学院\t系");
			for (int j = 0; j < TechList.size(); j++) {
				Collections.sort(TechList);
				System.out.println(TechList.get(j).toString());
			}
		}
	}
	
	public static int teaFind() {
		int j=0;
		if (TechList.isEmpty() == true) {
			System.out.println("无信息! ");
			return -1;
		} else {
			System.out.println("请输入教师编号: ");
			int no=sc.nextInt();
			for (j = 0; j < TechList.size(); j++) {
				if(TechList.get(j).getNo()==no)
					break;
			}
			if(j==TechList.size()) {
				System.out.println("无待查教师信息! ");
				return -2;
			} else {
			System.out.println("所查找的教师信息: ");
			System.out.println("编号\t姓名\t学院\t系");
			System.out.println(TechList.get(j).toString());
			return j;
			}
		}
	}
	
	public static void manaFuncTea() throws IOException {
	System.err.println("\n\t*管理教师信息*");
	System.out.println("------------------------------------------------------------------");
	System.out.println("\t\t\t1、显示所有教师信息");
	System.out.println("\t\t\t2、查找教师信息");
	System.out.println("\t\t\t3、导入教师信息");
	System.out.println("\t\t\t4、删除教师信息");
	System.out.println("\t\t\t5、修改教师信息");
	System.out.println("\t\t\t6、返回管理员主界面");
	System.out.println("------------------------------------------------------------------");
	int sopt = sc.nextInt();
	switch (sopt) {
	case 1: {
		teaView();
		System.out.println("返回上一级? (y/n): ");
		char yn = sc.next().charAt(0);
		if (yn == 'n') {
			mStatus = 1;
			break;
		} else
			break;
	}
	case 2: {
		teaFind();
		System.out.println("返回上一级? (y/n): ");
		char yn = sc.next().charAt(0);
		if (yn == 'n') {
			mStatus = 1;
			break;
		} else
			break;
	}
	case 3: {
		System.out.println("导入教师信息成功! ");
		System.out.println("返回上一级? (y/n): ");
		char yn = sc.next().charAt(0);
		if (yn=='n') {
			mStatus = 1;
			break;
		} else
			break;
	}
	case 4: {
		int tea=teaFind();
		if(tea<0) {
			System.out.println("返回上一级? (y/n): ");
			char yn = sc.next().charAt(0);
			if (yn == 'n') {
				mStatus = 1;
				break;
			} else
				break;
			}
		else {
			System.out.println("是否删除该条教师信息? (y/n)");
			char yn = sc.next().charAt(0);
			if (yn=='y') {
				TechList.remove(tea);
				System.out.println("删除成功! ");
				if(outputTxt(2)==1)
					System.out.println("操作已保存至文件!");
		}
			System.out.println("返回上一级? (y/n): ");
			yn = sc.next().charAt(0);
			if (yn == 'n') {
				mStatus = 1;
				break;
			} else
				break;
	}
	}
	case 5: {
		int tea=teaFind();
		if(tea<0) {
			System.out.println("返回上一级? (y/n): ");
			char yn = sc.next().charAt(0);
			if (yn == 'n') {
				mStatus = 1;
				break;
			} else
				break;
			} 
		else if(tea>=0) {
		System.out.println("请按对应格式输入修改后的教师信息! ");
		Scanner line=new Scanner(System.in);
		String update=line.nextLine();
		String split[]=update.split("\t");
		line.close();
		int no[]=new int[100];
		no[0]=Integer.valueOf(split[0]).intValue();
		TechList.get(tea).setNo(no[0]);
		TechList.get(tea).setName(split[1]);
		TechList.get(tea).setSchool(split[2]);
		TechList.get(tea).setDepartment(split[3]);
		System.out.println("修改后的教师信息: ");
		System.out.println("编号\t姓名\t学院\t系");
		System.out.println(TechList.get(tea).toString());
		if(outputTxt(2)==1)
			System.out.println("操作已保存至文件!");
		}
		char yn;
		System.out.println("返回上一级? (y/n): ");
		yn = sc.next().charAt(0);
		if (yn == 'n') {
			mStatus = 1;
			break;
		} else
			break;
	}
	
	case 6: {
		mStatus=1;
		break;
	}
}
}
	
	public static void courseView() {
	if (CourseList.isEmpty() == true) {
		System.out.println("无课程信息! ");
	} else {
		System.out.println("所有课程信息: ");
		System.out.println("课程号\t\t名称\t\t学分\t学时");
		for (int j = 0; j < CourseList.size(); j++) {
			Collections.sort(CourseList);
			System.out.println(CourseList.get(j).toString());
		}
	}
}

	public static int courseFind() {
	int j=0;
	if (CourseList.isEmpty() == true) {
		System.out.println("无课程信息! ");
		return -1;
	} else {
		System.out.println("请输入课程号: ");
		int no=sc.nextInt();
		for (j = 0; j < CourseList.size(); j++) {
			if(CourseList.get(j).getNo()==no)
				break;
		}
		if(j==CourseList.size()) {
			System.out.println("无待查课程信息! ");
			return -2;
		} else {
		System.out.println("所查找的课程信息: ");
		System.out.println("课程号\t\t名称\t\t学分\t学时");
		System.out.println(CourseList.get(j).toString());
		return j;
		}
	}		
}

	public static void manaFuncCourse() throws IOException {
		System.err.println("\n\t*管理课程信息*");
		System.out.println("------------------------------------------------------------------");
		System.out.println("\t\t\t1、显示所有课程信息");
		System.out.println("\t\t\t2、查找课程信息");
		System.out.println("\t\t\t3、导入课程信息");
		System.out.println("\t\t\t4、删除课程信息");
		System.out.println("\t\t\t5、修改课程信息");
		System.out.println("\t\t\t6、返回管理员主界面");
		System.out.println("------------------------------------------------------------------");
		int sopt = sc.nextInt();
		switch (sopt) {
		case 1: {
			courseView();
			System.out.println("返回上一级? (y/n): ");
			char yn = sc.next().charAt(0);
			if (yn == 'n') {
				mStatus = 1;
				break;
			} else
				break;
		}
		case 2: {
			courseFind();
			System.out.println("返回上一级? (y/n): ");
			char yn = sc.next().charAt(0);
			if (yn == 'n') {
				mStatus = 1;
				break;
			} else
				break;
		}
		case 3: {
			System.out.println("导入课程信息成功! ");
			System.out.println("返回上一级? (y/n): ");
			char yn = sc.next().charAt(0);
			if (yn=='n') {
				mStatus = 1;
				break;
			} else
				break;
		}
		case 4: {
			int cour=courseFind();
			if(cour<0) {
				System.out.println("返回上一级? (y/n): ");
				char yn = sc.next().charAt(0);
				if (yn == 'n') {
					mStatus = 1;
					break;
				} else
					break;
				}
			else {
				System.out.println("是否删除该条课程信息? (y/n)");
				char yn = sc.next().charAt(0);
				if (yn=='y') {
					CourseList.remove(cour);
					System.out.println("删除成功! ");
			}
				if(outputTxt(3)==1)
					System.out.println("操作已保存至文件!");
				System.out.println("返回上一级? (y/n): ");
				yn = sc.next().charAt(0);
				if (yn == 'n') {
					mStatus = 1;
					break;
				} else
					break;
		}
		}
		case 5: {
			int cour=courseFind();
			if(cour<0) {
				System.out.println("返回上一级? (y/n): ");
				char yn = sc.next().charAt(0);
				if (yn == 'n') {
					mStatus = 1;
					break;
				} else
					break;
			}
			else {
			System.out.println("请按对应格式输入修改后的课程信息! ");
			Scanner line=new Scanner(System.in);
			String update=line.nextLine();
			String split[]=update.split("\t");
			line.close();
			int no[]=new int[100];
			no[0]=Integer.valueOf(split[0]).intValue();
			no[2]=Integer.valueOf(split[2]).intValue();
			no[3]=Integer.valueOf(split[3]).intValue();
			CourseList.get(cour).setNo(no[0]);
			CourseList.get(cour).setName(split[1]);
			CourseList.get(cour).setCredit(no[2]);
			CourseList.get(cour).setHour(no[3]);
			System.out.println("修改后的课程信息: ");
			System.out.println("课程号\t名称\t\t学分\t学时");
			System.out.println(CourseList.get(cour).toString());
			if(outputTxt(3)==1)
				System.out.println("操作已保存至文件!");
			System.out.println("返回上一级? (y/n): ");
			char yn;
			yn = sc.next().charAt(0);
			if (yn == 'n') {
				mStatus = 1;
				break;
			} else
				break;
		}
		}
		default: mStatus=1;
	}
}

	public static void manaFuncGrade( ) {
		System.err.println("\n\t*打印成绩单*");
		System.out.println("------------------------------------------------------------------");
		System.out.println("请输入待打印的成绩单编号: ");
		int j=0;
		int no=sc.nextInt();
		for (j = 0; j < GradeList.size(); j++) {
			if(GradeList.get(j).getNo()==no)
				break;
			}
		if(j==GradeList.size()) {
			System.out.println("无待打印成绩单编号! ");
		} else {
		int sum = 0, i=0, count=0;
		System.out.println("编号为"+GradeList.get(j).getNo()+"的成绩单信息: ");
		System.out.println("成绩单号\t\t学号\t\t姓名\t课程\t\t教师\t成绩");
		for(i = 0; i < GradeList.size(); i++) {
			Collections.sort(GradeList);
			if(GradeList.get(i).getNo()==no) {
				System.out.println(GradeList.get(i).toString());
				sum+=GradeList.get(i).getPoint();
				count++;
			}
		}
		System.out.println("平均分: "+(float)(sum/count));
		}
		System.out.println("返回主菜单? (y/n): ");
		char yn = sc.next().charAt(0);
		if (yn == 'y') 
			mStatus = 1;
}
}
