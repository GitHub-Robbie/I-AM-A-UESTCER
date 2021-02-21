package inheritance;


/**
 * This program demonstrates inheritance.
 */
public class ManagerTest
{
   public static void main(String[] args)
   {
      // construct a Manager object
      Manager boss = new Manager("Carl Cracker", 80000, 1987, 12, 15);
      boss.setBonus(5000);

      Employee[] staff = new Employee[3];
      Manager[] manager = new Manager[3];
      staff = manager;
//      manager[i] 是一个manager，也一定是一个Employee。
      
      //the same as above
//      Employee[] staff = new Manager[3];
     
      // fill the staff array with Manager and Employee objects

      staff[0] = boss;//staff[0]与boss引用同一个对象。
      
//      staff[0].setBounus(1000);
      //not allowed,编译器将staff[0]看成Employee对象，
      //而setBonus不是Employee类的方法。
      
      
      staff[1] = new Manager("Harry Hacker", 50000, 1989, 10, 1);
      staff[2] = new Manager("Tommy Tester", 40000, 1990, 3, 15);
//      staff[1] = new Employee("Harry Hacker", 50000, 1989, 10, 1);
//      staff[2] = new Employee("Tommy Tester", 40000, 1990, 3, 15);
//      如果试图存储一个 Employee 类型的引用就会引发ArrayStoreException 异常。

      
      // print out information about all Employee objects
      // e is announced as an Employee object, but it can point to a Manager Object
//      for (Manager e : manager)
      for (Employee e : staff)
         System.out.println("name = " + e.getName() 
         + ", salary=" + e.getSalary() + ", hireday=" + e.getHireDay());
   }
}