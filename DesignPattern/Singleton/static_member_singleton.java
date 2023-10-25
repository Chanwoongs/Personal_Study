public class Singleton{
    private final static Singleton instance = new Singleton();

    private Singleton()
    {
        
    }

    public static Singleton getInstance()
    {
        return instance;
    }
}

// 많은 스레드들이 getInstance를 호출할 때마다 lock이 걸려 성능 저하가 되므로
// 최초에 미리 싱글톤 인스턴스를 만들어 놓고 반환해준다.
// 자원 낭비라는 문제점이 있다.
// 필요 없을 때에도 만들어야 하기 때문에