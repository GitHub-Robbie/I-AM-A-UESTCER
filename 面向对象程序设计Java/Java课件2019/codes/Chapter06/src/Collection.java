/**
 * Collection.java
*/
interface Collection {
//	private int i =0;//private is not allowed
	int MAX_NUM=100;//final, static, public
	
	void add (Object objAdd);//public, abstract
	void delete (Object objDelet);
	Object find (Object objFind);
	int currentCount();
	
	static void getElements() {
		System.out.println("Static method in Inferface!!!");
	}
	
	default void setElements() {
		System.out.println("Default method in Inferface!!!");
	}
	
	public static void main(String[] args) {
//		MAX_NUM = 1;//not allowed
		
		
		System.out.println("I am the main function !!!");
//		setElements();//non-static is not allowed in static 
		getElements();
	}
}
