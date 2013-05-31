

class Person
{
public:
	virtual int getHolidaysPerYear() = 0;

	virtual int getIncomePerYear() = 0;
};

class Student : public Person
{
public:
	virtual int getHolidaysPerYear()
	{
		return 30 * 5; // ~5 months
	}

	virtual int getIncomePerYear()
	{
		return 12 * (-1000);
	}
};

class Entrepreneur : public Person
{
public:
	virtual int getHolidaysPerYear()
	{
		return 30 * 1; // ~1 months
	}

	virtual int getIncomePerYear()
	{
		return 12 * (5000);
	}
};

class SelfEmployed : public Entrepreneur
{
public:
	virtual int getHolidaysPerYear()
	{
		return 30 * 1; // ~1 months
	}

	virtual int getIncomePerYear()
	{
		return 12 * (5000);
	}
}

}