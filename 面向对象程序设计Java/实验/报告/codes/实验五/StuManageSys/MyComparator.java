package StuManageSys;

import java.util.Comparator;

/**
 * @date 2018/7/13
 * @author HCQ
 * @see 学生信息管理系统
 */
// 如果进行比较排序，需要自定义一个比较类，见学生信息管理系统类的“1、查询所有学生信息”的具体代码
public class MyComparator implements Comparator<Student> {
	public int compare(Student o1, Student o2) {
		return o1.getNo() - o2.getNo();
	}
}
