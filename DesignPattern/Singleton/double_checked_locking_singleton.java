public class Singleton
{
    private volatile Singleton instance;

    private Singleton()
    {

    }

    public Singleton getinstance()
    {
        if (instance == null)
        {
            synchronized (Singleton.class)
            {
                if (instance == null)
                {
                    instance = new Singleton();
                }
            }
        }
        return instance;
    }
}

// instance 생성 여부를 싱글톤 패턴 잠금 전에 한번, 객체를 생성하기 전에 한번 총 2번을 체크한다.
// instance 가 null이라면 synchronized로 잠금을 건다.

// 멀티 스레드 환경에서 변수를 공유하기 위해 volatile 선언