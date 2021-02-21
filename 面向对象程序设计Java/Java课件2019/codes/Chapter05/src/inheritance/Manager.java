package inheritance;

import java.util.Date;

public class Manager extends Employee
{
   private double bonus;

   /**
    * @param n the employee's name
    * @param s the salary
    * @param year the hire year
    * @param month the hire month
    * @param day the hire day
    */
   public Manager(String n, double s, int year, int month, int day)
   {
	  //Manager 类不能访问 Employee类的私有域，
	  //必须用Employee类的构造器对这部分私有域进行初始化。

      super(n, s, year, month, day);
      bonus = 0;
   }

   public double getSalary()
   {
//	  double baseSalary = super.salary; //cannot visit private data
//	   double baseSalary = getSalary();//无限调用自己
	   double baseSalary = super.getSalary();
	   Date d = hireDay;

	   hireDay = new Date();// can visit protected area. Carefully!!!
      return baseSalary + bonus;
   }

   public void setBonus(double b)
   {
      bonus = b;
   }
}

