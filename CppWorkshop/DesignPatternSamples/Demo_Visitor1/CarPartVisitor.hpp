#pragma once

class Body;
class Wheel;
class Engine;
class Car;

class CarPartVisitor
{
public:
	virtual void accept(Body &body) = 0;
	virtual void accept(Wheel &wheel) = 0;
	virtual void accept(Engine &engine) = 0;
	virtual void accept(Car &car) = 0;
};