struct Semaphore {
	int value;
	Queue<process> q; 
};

wait(Semaphore s)
{
	s.value = s.value - 1;
	if (s.value < 0) // 쓸 수 있는 공유자원이 없다.
	{
		q.push(process);
		block();
	}
	else return;
}

signal(Semaphore s)
{
	s.value = s.value + 1;
	if (s.value <= 0) // 대기열에 있던 프로세스를 끄집어내서 공유 자원에 대한 작업을 진행
	{
		Process p = q.pop();
		wakeup(p);
	}
	else return;
}