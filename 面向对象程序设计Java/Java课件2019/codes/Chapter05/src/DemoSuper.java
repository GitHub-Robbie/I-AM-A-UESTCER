// A complete implementation of BoxWeight.
class FBox {
	private double width;
	private double height;
	private double depth;
	
	// construct clone of an object
	FBox(FBox ob) { // pass an object to constructor
		width = ob.width;
		height = ob.height;
		depth = ob.depth;
	}
	// constructor used when all dimensions specified
	FBox(double w, double h, double d) {
		width = w;
		height = h;
		depth = d;
	}
	// constructor used when no dimensions specified
	FBox() {
		width = -1; // use -1 to indicate
		height = -1; // an uninitialized
		depth = -1; // box
	}
	// constructor used when cube is created
	FBox(double len) {
		width = height = depth = len;
	}
	// compute and return volume
	double volume() {
		return width * height * depth;
	}
}
// BoxWeight now fully implements all constructors.
class SBoxWeight extends FBox {
	double weight; // weight of box
	// construct clone of an object
	SBoxWeight(SBoxWeight ob) { // pass object to constructor
		super(ob);
		weight = ob.weight;
	}
	// constructor when all parameters are specified
	SBoxWeight(double w, double h, double d, double m) {
		super(w, h, d); // call superclass constructor
		weight = m;
	}
	// default constructor
	SBoxWeight() {
		super();
		weight = -1;
	}
	// constructor used when cube is created
	SBoxWeight(double len, double w) {
		super(len);
		weight = w;
	}
}
class DemoSuper {
	public static void main(String args[]) {
		SBoxWeight mybox1  = new SBoxWeight(10, 20, 15, 34.3);
		SBoxWeight mybox2  = new SBoxWeight(2, 3, 4, 0.076);
		SBoxWeight mybox3  = new SBoxWeight(); // default
		SBoxWeight mycube  = new SBoxWeight(3, 2);
		SBoxWeight myclone = new SBoxWeight(mybox1);//clone
		double vol;
		vol = mybox1.volume();
		System.out.println("Volume of mybox1 is " + vol);
		System.out.println("Weight of mybox1 is " + mybox1.weight);
		System.out.println();
		vol = mybox2.volume();
		System.out.println("Volume of mybox2 is " + vol);
		System.out.println("Weight of mybox2 is " + mybox2.weight);
		System.out.println();
		vol = mybox3.volume();
		System.out.println("Volume of mybox3 is " + vol);
		System.out.println("Weight of mybox3 is " + mybox3.weight);
		System.out.println();
		vol = mycube.volume();
		System.out.println("Volume of mycube is " + vol);
		System.out.println("Weight of mycube is " + mycube.weight);
		System.out.println();
		vol = myclone.volume();
		System.out.println("Volume of myclone is " + vol);
		System.out.println("Weight of myclone is " + myclone.weight);
		System.out.println();
		
	}
}