public class Singleton{
    private static Singleton instance;

    private Singleton()
    {
        
    }

    public static synchronized Singleton getInstance()
    {
        if (instance == null)
        {
            instance = new Singleton();
        }
        return Singleton;
    }
}
// 메서드의 원자성이 결여됨
// 멀티 스레드 환경에서는 싱글톤 인스턴스를 2개 이상 만들 수 있다.
// synchronized 추가로 스레드 2개 이상 접근 불가하도록 함