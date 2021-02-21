/**
 * ScoreLevel3.java
*/
class ScoreLevel3{
	public static void main(String args[]){
		int testScore = 97;
		int level;
		char grade = ' ';
		level = testScore/10;
		switch (level) {
			case 10:
			case 9:   grade = 'A';
				break; // 如果没有 break 语句，会接着执行下一个分支。
			case 8:   grade = 'B';
				break;
			case 7:   grade = 'C';
				break;
			case 6:   grade = 'D';
				break;
			default:  grade = 'E';
		}
		System.out.println(testScore + "  is  " + grade + "\n");
	}
}
