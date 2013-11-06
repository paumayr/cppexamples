
#include <vector>
#include <random>

using namespace std;

// Seed with a real random value, if available
random_device rd;

default_random_engine e1(rd());
uniform_real_distribution<double> uniform_dist(0.0, 1.0);
mt19937 e2(rd());

struct vector4
{
	double x, y, z, w;
};

vector4 operator+(const vector4& lh, const vector4& rh)
{
	return vector4{ lh.x + rh.x, lh.y + rh.y, lh.z + rh.z, lh.w + rh.w };
}

vector4 operator-(const vector4& lh, const vector4& rh)
{
	return vector4{ lh.x - rh.x, lh.y - rh.y, lh.z - rh.z, lh.w - rh.w };
}

vector4 operator*(const vector4& lh, double x)
{
	return vector4{ lh.x * x, lh.y *x, lh.z * x, lh.w * x };
}

vector4 randvec4()
{
	return vector4
	{ 
		uniform_dist(e2),
		uniform_dist(e2),
		uniform_dist(e2),
		uniform_dist(e2)
	};
}
class Particle
{
public:
	vector4 x;
	vector4 optimum;
	vector4 velocity;
	double fitness;


	Particle() {
		fitness = std::numeric_limits<double>::max();
	}

	void SetRandom() {
		x = randvec4();
	}

	void UpdateOptimum()
	{
		optimum = x;
	}

	template<typename VelocityUpdate,
			typename PositionUpdate,
			typename FitnessFunction>
	void Update(VelocityUpdate velocity, PositionUpdate position, FitnessFunction fitness)
	{
		velocity = velocity(*this);
		x = position(*this);
		double fit = fitness(x);
		if (fit < this.fitness)
		{
			optimum = x;
		}
	}
};


class ParticleSwarm
{
public:
	ParticleSwarm(int particleCount) : particles(particleCount)
	{
		for (auto & p : particles) p.SetRandom();
	}

	template<typename VelocityUpdate,
		typename PositionUpdate,
		typename FitnessFunction>
	void Update(VelocityUpdate velocity, PositionUpdate position, FitnessFunction fitness)
	{
		for (auto &p : particles) p.Update(velocity, position, fitness);
	}

	vector4 bestposition;
	double bestfitness;

private:
	vector<Particle> particles;
};

int main(int argc, char **argv)
{
	ParticleSwarm pso(100);
	/*
	auto fitness = [](const vector4 &x) -> double {
		return cos(x.x) + sin(x.y) * 8.0 + x.z * x.z + x.w;
	};

	auto velocity = [&](Particle &p) -> vector4 {
		auto towardGroupOptimum = pso.bestposition - p.x;
		//auto towardParticleOptimum = pso.
			return p.velocity; 
	};

	auto position = [](Particle &p) -> vector4 {

	};
	*/
//	pso.Update();
}

