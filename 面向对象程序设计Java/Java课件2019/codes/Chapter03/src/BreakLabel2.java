// Using break as a civilized form of goto.
class BreakLabel2 {
	public static void main(String args[]) {
		outer: for (int i = 0; i < 3; i++) {
			System.out.print("\nPass " + i + ": ");
			for (int j = 0; j < 100; j++) {
				if (j == 10)
					continue outer; // exit this loops
				System.out.print(j + " ");
			}
			System.out.println("This will not print");
		}
		System.out.println("\nLoops complete.");
	}
}