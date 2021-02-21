// Using run-time polymorphism.
class ClassFigure {
	double dim1;
	double dim2;
	ClassFigure(double a, double b) {
		dim1 = a;
		dim2 = b;
	}
	double area() {
		System.out.println("Area for Figure is undefined.");
		return 0;
	}
}
class ClassRectangle extends ClassFigure {
	
	ClassRectangle(double a, double b) {
		super(a, b);
	}
	// override area for rectangle
	double area() {
		System.out.println("Inside Area for Rectangle.");
		return dim1 * dim2;
	}
}
class ClassTriangle extends ClassFigure {
	ClassTriangle(double a, double b) {
		super(a, b);
	}
	// override area for right triangle
	double area() {
		System.out.println("Inside Area for Triangle.");
		return dim1 * dim2 / 2;
	}
}
class FindAreas {
	public static void main(String args[]) {
		ClassFigure f = new ClassFigure(10, 10);
		ClassRectangle r = new ClassRectangle(9, 10);
		ClassTriangle t = new ClassTriangle(9, 10);
		
		ClassFigure figref;
		figref = r;
		System.out.println("Area is " + figref.area());
		
		System.out.println();
		
		figref = t;
		System.out.println("Area is " + figref.area());
		System.out.println();
		
		figref = f;
		System.out.println("Area is " + figref.area());
		System.out.println();
	}
}