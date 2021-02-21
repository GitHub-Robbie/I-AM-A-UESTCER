class Super 
{
	static String greeting(){ 
		return "Goodnight"; 
	} 
//	final String name() {  //final method
	String name() {  
		return "Richard"; 
	} 
} 
 
class Sub extends Super { 
	static String greeting()     { 
		return "Hello"; 
	} 
    String name()  { 
	   return "Jack"; 
   } 
} 

class TestMethodHidden { 
	public static void main(String[] args) { 
		
		Super sp = new Super(); 
		
		
//		Super s = new Sub(); //convert 
		Super s;
		Sub sb = new Sub();
		s = sb;

		System.out.println(sp.greeting() + ", " + sp.name()); 
		
		System.out.println(sb.greeting() + ", " + sb.name()); 
		
		System.out.println(s.greeting() + ", " + s.name()); 
		//cannot overide static methods. 
		//name() is overided while greeting() is not.
	} 
}
