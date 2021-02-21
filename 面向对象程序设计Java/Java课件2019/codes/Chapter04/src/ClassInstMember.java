/**
 * ClassInstMember.java
*/
class ClassInstMember {
	static int classVar ;           
	int instVar;              
	void setData(int c, int i){    
		classVar = c;
		instVar = i;
	}
	static int getData(){          

		classVar = 10; 
		
		ClassInstMember cim = new ClassInstMember();
		return  cim.instVar + classVar;
	}
}
