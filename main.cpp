#include <iostream>
#define START_BASE 5000
using namespace std;
void input_fun(double *saraly, double *social_base, double *house_base, double *social_rate, double *house_rate,double *specil, double *year_prize)
{
	cout << "请输入你的税前工资: ";
	cin >> *saraly;
	cout << endl;
	while (1)
	{
		if (*saraly < 0)
		{
			cout << "您的输入有误，请重新输入税前工资: ";

			cin >> *saraly;
			cout << endl;
		}
		else
		{
			break;
		}

	}

	cout << "请输入你的社保基数: ";
	cin >> *social_base;
	cout << endl;
	while (1)
	{
		if (*social_base < 0 || *social_base > *saraly)
		{
			cout << "您的输入有误，请重新输入社保基数: ";

			cin >> *social_base;
			cout << endl;
		}
		else
		{
			break;
		}

	}

	cout << "请输入你的社保缴纳百分比: ";
	cin >> *social_rate;
	cout << endl;
	while (1)
	{
		
		if (*social_rate < 0 || *social_rate > 1)
		{
			cout << "您的输入有误，请重新输入社保缴纳百分比: ";

			cin >> *social_rate;
			cout << endl;
		}
		else
		{
			break;
		}

	}

	cout << "请输入你的公积金基数: ";
	cin >> *house_base;
	cout << endl;
	while (1)
	{
		if (*house_base < 0 || *house_base > *saraly)
		{
			cout << "您的输入有误，请重新输入公积金基数: ";

			cin >> *house_base;
			cout << endl;
		}
		else
		{
			break;
		}

	}

	cout << "请输入你的公积金缴纳百分比: ";
	cin >> *house_rate;
	cout << endl;
	while (1)
	{
		if (*house_rate < 0 || *house_rate > 1)
		{
			cout << "您的输入有误，请重新输入公积金缴纳百分比: ";

			cin >> *house_rate;
			cout << endl;
		}
		else
		{
			break;
		}

	}
	cout << "请输入你的专项扣除额: ";
	cin >> *specil;
	cout << endl;
	while (1)
	{
		if (*specil < 0 )
		{
			cout << "您的输入有误，请重新输入专项扣除额: ";

			cin >> *specil;
			cout << endl;
		}
		else
		{
			break;
		}

	}
	cout << "请输入你的年终奖基数: ";
	cin >> *year_prize;
	cout << endl;
	while (1)
	{
		if (*year_prize < 0)
		{
			cout << "您的输入有误，请重新输入年终奖基数: ";

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
	// 五险一金部分
	double old_rate = 0.08;
	double medical_rate = 0.02;
	double unemploy_rate = 0.005;
	uint8_t flag = false;
	// 个人所得税部分
	double personl_tex = 0;
	input_fun(&saraly, &social_base, &house_base, &social_rate, &house_rate, &specil, &year_prize);

	double sum_5_1 = 0;
	sum_5_1 = social_base * (old_rate + medical_rate + unemploy_rate) + house_base * house_rate;
	
	if ((saraly - sum_5_1) <= START_BASE)
	{
		printf("您的工资太低，不需要缴纳个税！");
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
	printf("您每个月应缴的五险一金金额：%10.3f 元；\n\n", sum_5_1);
	for (int i = 0; i < 12; i++)
	{
		act_get = saraly - sum_5_1 - table[i][2];
		sum += act_get;
		printf("第%2d个月应缴纳个人所得税：%10.3f 元,  实际到手工资：%10.3f 元；\n\n",(i+1),table[i][2],act_get);
	}

	printf("您全年个人所得税扣除：%10.3f 元；\n\n", table[11][3]);
	printf("您的税后年终奖：%10.3f 元；\n\n", act_year_prize);
	printf("您全年总收入：%10.3f 元；\n\n", sum);
	printf("您全年公积金收入(含公司)：%10.3f 元。", (saraly * house_rate * 2 * 12));
	getchar();
	getchar();
}