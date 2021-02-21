interface InterfaceA { 
	int len = 1 ; 
	void output(); 
} 

interface InterfaceB extends InterfaceA{ 
	int len = 2 ; //overide
	void output(); //overide
} 

interface InterfaceSub extends InterfaceB { } 


class IFExtend implements InterfaceSub { 
	public void output() { 
		System.out.println( "output in class IFExtend." ); 
	} 
	public void outputLen( int type) { 
		switch (type) { 
			case InterfaceA.len: 
				System.out.println( "len of InterfaceA=." +type); break ; 
			case InterfaceB.len: 
				System.out.println( "len of InterfaceB=." +type); break ; 
		} 
	} 
	public static void main(String[] args) { 
		IFExtend xyz= new IFExtend (); 
		xyz.output(); 
		xyz.outputLen(xyz.len); 
	} 
}
