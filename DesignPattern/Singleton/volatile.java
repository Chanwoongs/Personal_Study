public class Test {
    //boolean flag = true;
    volatile boolean flag = true;

    public void test() {
        new Thread(()->{
                int cnt = 0;
                while (flag) {
                    cnt++; 
                }
                System.out.println("Thread1 finished\n");
            }
        ).start();
        new Thread(()-> {
                try {
                    Thread.sleep(100);
                } catch (InterruptedException ignored) {
                    
                }
                System.out.println("flag to false");
                flag = false;
            }
        ).start();
    }

    public static void main(String[] args) {
        new Test().test();
    }
}

// 각각의 캐시 메모리에서 변수를 가져오기 때문에 공유되지 않는다.
// volatile 을 추가하면 메인 메모리에서 가져오기 때문에 공유된다.