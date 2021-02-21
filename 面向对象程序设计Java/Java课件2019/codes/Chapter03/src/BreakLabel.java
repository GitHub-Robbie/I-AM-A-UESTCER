// Using break as a civilized form of goto.
class BreakLabel {
	public static void main(String args[]) {
		boolean t = true;
		first: {// block
			second: {// block
				third: {// block
					System.out.println("Before the break.");
					if (t)
						break second; // break out of second block
					System.out.println("This won't execute");
				}
				System.out.println("This won't execute");
			}
			System.out.println("This is after second block.");
		}
	}
}