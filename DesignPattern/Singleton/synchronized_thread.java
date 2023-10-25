public class YunhaSync {
	private static String yunha = "오르트구름";

	public static void main(String[] agrs) {
		YunhaSync a = new YunhaSync(); 
		new Thread(() -> {
			for (int i = 0; i < 10; i++) {
				a.say("사건의 지평선");
			}
		}).start();

		new Thread(() -> {
			for (int i = 0; i < 10; i++) {
				a.say("오르트 구름");
			}
		}).start(); 

	}

	//public void say(String song) {
    public synchronized void say(String song) { // lock을 걸어서 실행 중에 다른 스레드가 접근하지 못하게 함
		yunha = song; 
		try {
			long sleep = (long) (Math.random() * 100);
			Thread.sleep(sleep);
		} catch (InterruptedException e) {
			e.printStackTrace();
		} 
		if (!yunha.equals(song)) {
			System.out.println(song + " | " + yunha);
		}
	}
} 