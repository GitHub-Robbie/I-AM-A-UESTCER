package clone;

import java.util.Date;
import java.util.GregorianCalendar;

public class Employee implements Cloneable
{
   private String name;
   private double salary;
   private Date hireDay;

   public Employee(String n, double s)
   {
      name = n;
      salary = s;
      hireDay = new Date();
   }

   // raise visibility level to public, change return type
   public Employee clone() throws CloneNotSupportedException
   {
      // call Object.clone()
      Employee cloned = (Employee) super.clone();//super
      
//      不能用Object 对象来调用 clone();invisible
//      Object o = new Object();
//      Employee cloned2 = (Employee) o.clone();

      // clone mutable fields
      //为了实现深拷贝，必须克隆所有可变的实例域。
      cloned.hireDay = (Date) hireDay.clone();

      return cloned;
   }

   /**
    * Set the hire day to a given date. 
    * @param year the year of the hire day
    * @param month the month of the hire day
    * @param day the day of the hire day
    */
   public void setHireDay(int year, int month, int day)
   {
      Date newHireDay = new GregorianCalendar(year, month - 1, day).getTime();
      
      // Example of instance field mutation
      hireDay.setTime(newHireDay.getTime());
   }

   public void raiseSalary(double byPercent)
   {
      double raise = salary * byPercent / 100;
      salary += raise;
   }

   public String toString()
   {
      return "Employee[name=" + name + ",salary=" + salary + ",hireDay=" + hireDay + "]";
   }
}