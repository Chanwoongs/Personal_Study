class Singleton
{
    private static class singletionInstanceHolder
    {
        private static final Singleton INSTANCE = new Singleton();
    }
    public static Singleton getInstance()
    {
        return singletionInstanceHolder.INSTANCE;
    }
}

// 외부 모듈들이 필요할 때만 정적 맴버로 선언하여 자원 낭비를 예방함.