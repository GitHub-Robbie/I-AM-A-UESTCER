/**
 * This program demonstrates parameter passing in Java.
 */
public class ParamTest
{
   public static void main(String[] args)
   {
      /*
       * Test 1: Methods can't modify numeric(boolean) parameters
       */
      System.out.println("Testing tripleValue:");
      double percent = 10;
      System.out.println("Before: percent = " + percent);
      tripleValue(percent);
      System.out.println("After: percent = " + percent);
      
      
      System.out.println("\n************************************");

      /*
       * Test 2: Methods can change the state of object parameters
       */
      System.out.println("\nTesting tripleSalary:");
      Employee harry = new Employee("Harry", 50000);
      System.out.println("Before: salary = " + harry.getSalary());
      tripleSalary(harry);
      System.out.println("After: salary = " + harry.getSalary());
      
      System.out.println("\n************************************");

      /*
       * Test 3: Methods can't attach new objects to object parameters
       */
      System.out.println("\nTesting swap:");
      Employee a = new Employee("Alice", 70000);
      Employee b = new Employee("Bob", 60000);
      System.out.println("Before: a = " + a.getName());
      System.out.println("Before: b = " + b.getName());
      swap(a, b);
      System.out.println("After: a = " + a.getName());
      System.out.println("After: b = " + b.getName());
      
      System.out.println("\n************************************");
      
      System.out.println("\nReal swap:");
      System.out.println("Before: a = " + a.getName());
      System.out.println("Before: b = " + b.getName());
      Employee temp = a;
      a = b;
      b = temp;
      System.out.println("After: a = " + a.getName());
      System.out.println("After: b = " + b.getName());
      
      System.out.println("\n************************************");
      
      //对象传递是按引用传递 (与参数传递不同！！！)
      StringBuilder s= new StringBuilder("good");
      StringBuilder s2 = s;
      s2.append(" afternoon.");
      System.out.println(s);
   }

   public static void tripleValue(double x) // doesn't work
   {
      x = 3 * x;
      System.out.println("End of method: x = " + x);
   }

   public static void tripleSalary(Employee x) // X 被初始化为 harry 值的拷贝， 这里是一个对象的引用。
   {
      x.raiseSalary(200); 
      //raiseSalary 方法应用于这个对象引用。 x 和 harry 同时引用的那个 Employee 对象的薪金提高了 200%。
      //方法结束后， 参数变量 x 不再使用。 当然， 对象变量 harry 继续引用那个薪金增至 3 倍的雇员对象
      System.out.println("End of method: salary = " + x.getSalary());
   }

   public static void swap(Employee x, Employee y)
   {
      Employee temp = x;
      x = y;
      y = temp;
      System.out.println("End of method: x = " + x.getName());
      System.out.println("End of method: y = " + y.getName());
   }
}

class Employee // simplified Employee class
{
   private String name;
   private double salary;

   public Employee(String n, double s)
   {
//	  String name = n;
//	  double salary = s;
      name = n;
      salary = s;
   }

   public String getName()
   {
      return name;
   }

   public double getSalary()
   {
      return salary;
   }

   public void raiseSalary(double byPercent)
   {
      double raise = salary * byPercent / 100;
      salary += raise;
   }
}
