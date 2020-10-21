#include <iostream>
#define START_BASE 5000
using namespace std;
void input_fun(double *saraly, double *social_base, double *house_base, double *social_rate, double *house_rate,double *specil, double *year_prize)
{
	cout << "���������˰ǰ����: ";
	cin >> *saraly;
	cout << endl;
	while (1)
	{
		if (*saraly < 0)
		{
			cout << "����������������������˰ǰ����: ";

			cin >> *saraly;
			cout << endl;
		}
		else
		{
			break;
		}

	}

	cout << "����������籣����: ";
	cin >> *social_base;
	cout << endl;
	while (1)
	{
		if (*social_base < 0 || *social_base > *saraly)
		{
			cout << "�����������������������籣����: ";

			cin >> *social_base;
			cout << endl;
		}
		else
		{
			break;
		}

	}

	cout << "����������籣���ɰٷֱ�: ";
	cin >> *social_rate;
	cout << endl;
	while (1)
	{
		
		if (*social_rate < 0 || *social_rate > 1)
		{
			cout << "�����������������������籣���ɰٷֱ�: ";

			cin >> *social_rate;
			cout << endl;
		}
		else
		{
			break;
		}

	}

	cout << "��������Ĺ��������: ";
	cin >> *house_base;
	cout << endl;
	while (1)
	{
		if (*house_base < 0 || *house_base > *saraly)
		{
			cout << "���������������������빫�������: ";

			cin >> *house_base;
			cout << endl;
		}
		else
		{
			break;
		}

	}

	cout << "��������Ĺ�������ɰٷֱ�: ";
	cin >> *house_rate;
	cout << endl;
	while (1)
	{
		if (*house_rate < 0 || *house_rate > 1)
		{
			cout << "���������������������빫������ɰٷֱ�: ";

			cin >> *house_rate;
			cout << endl;
		}
		else
		{
			break;
		}

	}
	cout << "���������ר��۳���: ";
	cin >> *specil;
	cout << endl;
	while (1)
	{
		if (*specil < 0 )
		{
			cout << "����������������������ר��۳���: ";

			cin >> *specil;
			cout << endl;
		}
		else
		{
			break;
		}

	}
	cout << "������������ս�����: ";
	cin >> *year_prize;
	cout << endl;
	while (1)
	{
		if (*year_prize < 0)
		{
			cout << "�������������������������ս�����: ";

			cin >> *year_prize;
			cout << endl;
		}
		else
		{
			break;
		}

	}
}

void main()
{
	double saraly = 0;
	double social_base = 0;
	double house_base = 0;
	double social_rate = 0;
	double house_rate = 0;
	const int work_month = 12;
	double year_prize = 0;
	double specil = 0;
	// ����һ�𲿷�
	double old_rate = 0.08;
	double medical_rate = 0.02;
	double unemploy_rate = 0.005;
	uint8_t flag = false;
	// ��������˰����
	double personl_tex = 0;
	input_fun(&saraly, &social_base, &house_base, &social_rate, &house_rate, &specil, &year_prize);

	double sum_5_1 = 0;
	sum_5_1 = social_base * (old_rate + medical_rate + unemploy_rate) + house_base * house_rate;
	
	if ((saraly - sum_5_1) <= START_BASE)
	{
		printf("���Ĺ���̫�ͣ�����Ҫ���ɸ�˰��");
		getchar();
		getchar();
		return;
	}

	double table[12][4] = { 0 };
	double tex_rate = 0;
	double quick_cal = 0;
	int j = 0;

	for (int i = 0; i < work_month; ++i)
	{
		table[i][0] = 1;
		if (i == 0)
		{
			j = i;
		}
		else 
		{
			j = i - 1;
		}
		table[i][1] = table[j][1] + (saraly - sum_5_1 - START_BASE - specil);
		if (table[i][1] <= 36000)
		{
			tex_rate = 0.03;
			quick_cal = 0;
		}
		if (table[i][1] > 36000 && table[i][1] <= 144000)
		{
			tex_rate = 0.1;
			quick_cal = 2520;
		}
		if (table[i][1] > 144000 && table[i][1] <= 300000)
		{
			tex_rate = 0.2;
			quick_cal = 16920;
		}
		if (table[i][1] > 300000 && table[i][1] <= 420000)
		{
			tex_rate = 0.25;
			quick_cal = 31920;
		}
		if (table[i][1] > 420000 && table[i][1] <= 660000)
		{
			tex_rate = 0.3;
			quick_cal = 52920;
		}
		if (table[i][1] > 660000 && table[i][1] <= 960000)
		{
			tex_rate = 0.35;
			quick_cal = 85920;
		}
		if (table[i][1] > 960000)
		{
			tex_rate = 0.45;
			quick_cal = 181920;
		}
		table[i][2] = table[i][1] * tex_rate - quick_cal - table[j][3];
		table[i][3] = table[i][2] + table[j][3];
	}
	
	double avg_prize = year_prize / 12;
	if (avg_prize <= 3000)
	{
		tex_rate = 0.03;
		quick_cal = 0;
	}
	if (avg_prize > 3000 && avg_prize <= 12000)
	{
		tex_rate = 0.1;
		quick_cal = 210;
	}
	if (avg_prize > 12000 && avg_prize <= 25000)
	{
		tex_rate = 0.2;
		quick_cal = 1410;
	}
	if (avg_prize > 25000 && avg_prize <= 35000)
	{
		tex_rate = 0.25;
		quick_cal = 2660;
	}
	if (avg_prize > 35000 && avg_prize <= 55000)
	{
		tex_rate = 0.3;
		quick_cal = 4410;
	}
	if (avg_prize > 55000 && avg_prize <= 80000)
	{
		tex_rate = 0.35;
		quick_cal = 7160;
	}
	if (avg_prize > 80000)
	{
		tex_rate = 0.45;
		quick_cal = 15160;
	}
	double act_year_prize = year_prize-year_prize * tex_rate + quick_cal;
	double act_get = 0;
	double sum = act_year_prize;
	printf("��ÿ����Ӧ�ɵ�����һ���%10.3f Ԫ��\n\n", sum_5_1);
	for (int i = 0; i < 12; i++)
	{
		act_get = saraly - sum_5_1 - table[i][2];
		sum += act_get;
		printf("��%2d����Ӧ���ɸ�������˰��%10.3f Ԫ,  ʵ�ʵ��ֹ��ʣ�%10.3f Ԫ��\n\n",(i+1),table[i][2],act_get);
	}

	printf("��ȫ���������˰�۳���%10.3f Ԫ��\n\n", table[11][3]);
	printf("����˰�����ս���%10.3f Ԫ��\n\n", act_year_prize);
	printf("��ȫ�������룺%10.3f Ԫ��\n\n", sum);
	printf("��ȫ�깫��������(����˾)��%10.3f Ԫ��", (saraly * house_rate * 2 * 12));
	getchar();
	getchar();
}