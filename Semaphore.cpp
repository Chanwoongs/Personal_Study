struct Semaphore {
	int value;
	Queue<process> q; 
};

wait(Semaphore s)
{
	s.value = s.value - 1;
	if (s.value < 0) // �� �� �ִ� �����ڿ��� ����.
	{
		q.push(process);
		block();
	}
	else return;
}

signal(Semaphore s)
{
	s.value = s.value + 1;
	if (s.value <= 0) // ��⿭�� �ִ� ���μ����� ������� ���� �ڿ��� ���� �۾��� ����
	{
		Process p = q.pop();
		wakeup(p);
	}
	else return;
}