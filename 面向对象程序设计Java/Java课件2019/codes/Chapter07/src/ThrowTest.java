public class ThrowTest {
	public static void main(String args[]) {
		Bank bank = new Bank();
		try {
			bank.income(200, -100);
			bank.income(300, -100);
			bank.income(400, -100);
			System.out.printf("银行目前有%d元\n", bank.getMoney());
			bank.income(-200, -100);
		} 
		catch (BankException e) {
			System.out.println("计算收益的过程出现如下问题:");
			System.out.println(e.warnMess());
		} 
		finally {
			System.out.printf("银行目前有%d元\n", bank.getMoney());
		}
	}
}

class Bank {
	private int money;

	public void income(int in, int out) throws BankException 
	// 可能抛出异常的声明
	{
		if (in <= 0 || out >= 0 || in + out <= 0) {
			throw new BankException(in, out); // 方法抛出异常，导致方法结束
		}
		int netIncome = in + out;
		System.out.printf("本次计算出的纯收入是: %d元\n", netIncome);
		money = money + netIncome;
	}

	public int getMoney() {
		return money;
	}
}

class BankException extends Throwable {
	String message;

	public BankException(int m, int n) {
		message = "入账资金：" + m + "是负数，或支出：" + n + "是正数，不符合系统要求！";
	}

	public String warnMess() {
		return message;
	}
}
