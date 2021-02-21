/**
 * ScoreLevel1.java
*/
class ScoreLevel1  {
	public static void main(String args[])  {
		int testScore = 87;
		char grade = 'E';
		if (testScore >= 90){
			grade='A';
		}else if (testScore >=80){
			grade='B';
		}else if (testScore >= 70){
			grade='C';
		}else{
			grade='D';
		}
		System.out.println(testScore + "  is  " + grade + "\n");
	}
}
