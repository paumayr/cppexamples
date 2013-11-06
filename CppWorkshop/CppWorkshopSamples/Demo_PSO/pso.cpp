
#include <vector>
#include <random>
#include <algorithm>
#include <iostream>

using namespace std;

struct vector4
{
	double x = 0, y = 0, z = 0, w = 0;
	vector4() : x(0.0), y(0.0), z(0.0), w(0.0) {}
	vector4(double x, double y, double z, double w)
		: x(x), y(y), z(z), w(w)
	{}
};

double length(vector4 &v)
{
	return sqrt(v.x * v.x + v.y*v.y + v.z*v.z + v.w * v.w);
}

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

ostream& operator<< (ostream &os, const vector4 &v)
{
	os << "{ " << v.x << ", " << v.y << ", " << v.z << ", " << v.w << "}";
	return os;
}

class Particle
{
public:
	vector4 position;
	vector4 optimum;
	vector4 velocity;
	double fitness;


	Particle() {
		fitness = std::numeric_limits<double>::max();
	}

	template<typename Random, typename Fitness> 
	void SetRandom(Random r, Fitness f) {
		this->position = r();
		this->velocity = r();
		this->optimum = this->position;
		this->fitness = f(this->position);
	}

	template<typename VelocityUpdate,
			typename PositionUpdate,
			typename FitnessUpdate>
	void Update(VelocityUpdate velocityUpdate, PositionUpdate positionUpdate, FitnessUpdate fitness)
	{
		velocity = velocityUpdate(*this);
		position = positionUpdate(*this);
		double fit = fitness(position);
		if (fit < this->fitness)
		{
			this->optimum = position;
			this->fitness = fit;
		}
	}
};


template<typename Random, typename FitnessFunction>
class ParticleSwarm
{
public:
	FitnessFunction fitnessFunction;
	vector4 bestposition;
	double bestfitness;

	ParticleSwarm(int particleCount, Random r, FitnessFunction f)
		: particles(particleCount), 
		fitnessFunction(f)
	{
		for (auto & p : particles) p.SetRandom(r, f);
	}

	template<typename VelocityUpdate,
		typename PositionUpdate,
		typename FitnessFunction>
	void Update(VelocityUpdate velocity, PositionUpdate position)
	{
		for (auto &p : particles) p.Update(velocity, position, fitnessFunction);

		auto best = min_element(begin(particles), end(particles),
									[](Particle &lh, Particle &rh)
								{ return lh.fitness < rh.fitness; });

		this->bestposition = best->position;
		this->bestfitness = best->fitness;
	}

private:
	vector<Particle> particles;
};


int main(int argc, char **argv)
{

	// Seed with a real random value, if available
	random_device rd;
	default_random_engine e1(rd());
	uniform_real_distribution<double> uniform_dist(0.0, 1.0);
	
	auto value = uniform_dist(e1);




	auto posgen = [&]() -> vector4 { return vector4{ uniform_dist(e1), uniform_dist(e1), uniform_dist(e1), uniform_dist(e1) }; };
	auto fitness = [](const vector4 &x) -> double 
	{
		static const vector4 opt{ 0.5, 0.5, 0.5, 0.5 };
		return length(opt - x);
	};

	ParticleSwarm pso(100, posgen, fitness);

	auto velocity = [&](Particle &p) -> vector4 
	{
		return p.velocity * 0.5 + 
			(pso.bestposition - p.position) * 0.3 + 
			(p.optimum - p.position) * 0.5;
	};

	auto position = [](Particle &p) -> vector4 {
		return p.position + p.velocity;
	};

	for (int i = 0; i < 10; i++)
	{
		pso.Update(velocity, position);
		std::cout << pso.bestfitness << " at " << pso.bestposition << std::endl;
	}
}

