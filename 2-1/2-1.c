# include <stdio.h>

int main()
{
	int move, direction, t, location, totalnumber, number, target, change, show, overload = 0, recovery = 0,special;
	int sp[10], ep[10], spog[10], difference[10], epog[10], tt[10], spc[10], epc[10];

	for (;;)
	{
		for (int i = 0; i < 10; ++i)
			sp[i] = 100, ep[i] = 100, spog[i] = 100, epog[i] = 100, tt[i] = 0;
		move = 0, direction = 0, t = -1, number = 0, change = 1, show = 0,special=0;

		printf("��������ݳ�ʼ����¥�㣺");
		scanf("%d", &location);
		printf("������������ݵ��û�������");
		scanf("%d", &totalnumber);
		printf("��������˿���ʼ¥���Ŀ��¥�㣺����ʼ�㡿 ��Ŀ�Ĳ㡿 ��ʱ�䡿\n");
		for (int i = 0; i < totalnumber; ++i)
		{
			scanf("%d %d %d", &spog[i], &epog[i], &tt[i]);
		}
		printf("�������н������¥�㡿 �������� ��ʱ�䡿\n");//������Ϣ

		for (int i = 0; i < 200; ++i)
		{
			t = t + 1;
			for (int i = 0; i < 10; ++i)
				if (tt[i] == t)
					sp[i] = spog[i], ep[i] = epog[i];//ʱ�䵽�˾ͽ��˿���Ϣ��֪����
			
			back://�����˶������غ���ʾϵͳ
			if (overload == 1)//�����أ�������
			{
				for (int i = 0; i < 10; ++i)
					if (sp[i] != 100 && ep[i] != 100)
					{
						sp[i] = 100, ep[i] = 100;
					}
			}

			change = 1;//ʵ�ֵ����˶�����
			if ((move == 1) && (direction == -1))
			{
				for (int i = 0; i < 10; ++i)
				{
					if (sp[i] != 100 && sp[i] < location)
					{
						location = location - 1, change = 0;
						break;
					}
				}
				if (change == 1)
				{
					for (int i = 0; i < 10; ++i)
					{
						if (sp[i] != 100 && sp[i] > location)
							direction = 1;
					}
				}
			}
			if ((move == 1) && (direction == 1))
			{
				for (int i = 0; i < 10; ++i)
				{

					if (sp[i] != 100 && sp[i] > location)
					{
						location = location + 1, change = 0;
						break;
					}
				}
				if (change == 1)
				{
					for (int i = 0; i < 10; ++i)
					{
						if (sp[i] != 100 && sp[i] < location)
						{
							direction = -1;
							goto back;
						}
					}
				}
			}			

			if (move == 1 && direction == 0)
			{
				change = 0, direction = 1;
			}

			if (change == 0)//ʵ�ֵ��������˹���
			{
				for (int i = 0; i < 10; ++i)
				{
					if (location == epog[i] && sp[i] != 100 && ep[i] == 100)
					{
						number--;
						overload = 0;
						continue;
					}
				}
				for (int i = 0; i < 10; ++i)
				{
					if (location == spog[i] && ep[i] != 100)
					{
						number++;
						continue;
					}
				}

				if (overload == 0 && recovery == 1)
					for (int i = 0; i < 10; ++i)
						sp[i] = spc[i], ep[i] = epc[i], recovery = 0;

				for (int i = 0; i < 10; ++i)//��ʾ��������״̬
				{
					if (location == sp[i])
					{
						show = 1;
						sp[i] = ep[i];
						ep[i] = 100;
					}
				}
				if (show == 1)
				{
					printf("%d %d %d\n", location, number,t);
					show = 0;
				}
			}

			if (overload == 0)
			{
				for (int i = 0; i < 10; ++i)
					spc[i] = sp[i], epc[i] = ep[i];
			}
			if (number == 4)
				overload = 1, recovery = 1;

			for (int i = 0; i < 10; ++i)
				difference[i] = abs(sp[i] - location);
			for (int i = 0, m = 100; i < 10; ++i)
			{
				if (m >= difference[i])
					m = difference[i], target = i;
				if (m == 0)
					special = 1;
			}
			if ((move == 0) && (sp[target] != 100))//�����ɾ�ת��ʱ�жϷ���
			{
				if (sp[target] < location)
					direction = -1;
				if (sp[target] == location)
					direction = 0;
				if (sp[target] > location)
					direction = 1;
			}
			if (sp[target] == 100)
                move = 0, direction = 0;
			if (sp[target] != 100 && special == 0)
			{
				move = 1;
			}
			if (sp[target] != 100&&special==1)
			{
				move = 1;
				special = 0;
				goto back;//��goto��Ϊ����������·�ֹʱ������
			}			
		}
	}
}
