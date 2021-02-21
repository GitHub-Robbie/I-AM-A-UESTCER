/**
 * MakeRectangle.java
*/
class Rectangle {
	int width, height;
	int area;
	public Rectangle(int w, int h){
		width = w;
		height = h;
		area = w*h;
	}
	int getArea(int w, int h){
		int area;
		area=w*h;	
		return area;
	}
	public void drawRect(){
		for (int i = width; i>0; i--){
			System.out.print("*");
		}
		System.out.println();
		for (int i = height-2; i>0; i--) {
			System.out.print("*");
			for (int j = width-2; j>0; j--){
				System.out.print(" ");
			}
			System.out.print("*\n");
		}
		for (int i = width; i>0; i--){
			System.out.print("*");
		}
		System.out.println();
	}
}
public class MakeRectangle {
	public static void main(String[] args){
		if(args.length == 2){
			int w=Integer.parseInt(args[0]);
			int h=Integer.parseInt(args[1]);
			Rectangle rect = new Rectangle(w,h);
			rect.drawRect();
			rect = null;
		}else{
			System.out.println("The Parameter is illegal!");
		}
	}
}
