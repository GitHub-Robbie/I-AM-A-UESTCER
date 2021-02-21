/**
 * FIFOQueue.java
*/
class FIFOQueue implements Collection {
//	MAX_NUM = 1;//final, not allowed.
	int x = MAX_NUM;//allowed
	
	public void add (Object objAdd){//must using public
		//add object code
	}
	public void delete (Object objDelet){
		//delete object code
	}
	public Object find (Object objFind){
		return objFind;
		//find object code
	}
	public int currentCount(){
		return 0;
		//count object code
	}
	
	public static void main(String[] args) {
		
		Collection.getElements();
		FIFOQueue f = new FIFOQueue();
		f.setElements();
		
		Collection.main(new String[10]);// main 中调用main，piyixia.
	}
}
