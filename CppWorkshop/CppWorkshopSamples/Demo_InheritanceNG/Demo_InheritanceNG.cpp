#include "stdafx.h"
#include <iostream>
#include <string>
#include <memory>
#include <vector>

using namespace std;

/*
Rectangle class
*/
class Rectangle
{
public:
	Rectangle() = default;
	Rectangle(int x, int y, int w, int h) : x(x), y(y), width(w), height(h){}

	int x = 0, y = 0;
	int width = 0, height = 0;
};

void draw(const Rectangle &r, ostream &out, size_t position)
{
	out << string(" ", position) << "Rectangle(" << r.x << ", " << r.y << ", " << r.width << ", " << r.height << ")" << endl;
}

/*
Circle class
*/
class Circle
{
public:
	Circle() = default;
	Circle(int x, int y, int r) : x(x), y(y), radius(r){}

	int x = 0, y = 0;
	int radius = 0;
};

void draw(const Circle &r, ostream &out, size_t position)
{
	out << string(" ", position) << "Circle(" << r.x << ", " << r.y << ", " << r.radius << ")" << endl;
}


/*
Node class providing the polymorphism magic.
*/
class Node
{
public:
	template<typename T>
	Node(T x) : self_(new model<T>(move(x)))
	{}

	Node(const Node & x) : self_(x.self_->copy_())
	{}

	Node& operator=(const Node& x)
	{ Node tmp(x); *this = move(tmp); return *this; }

	Node(Node && other)
	{
		// can't = default in VC 2013 :/ RValue reference 
		this->self_ = std::move(other.self_);
	}

	Node& operator=(Node &&other)
	{
		// can't = default in VC 2013 :/ RValue reference 
		this->self_ = std::move(other.self_);
		return *this;
	}

	friend void draw(const Node &x, ostream& out, size_t level)
	{
		x.self_->draw_(out, level);
	}

private:
	struct concept_t {
		virtual ~concept_t() = default;
		virtual concept_t* copy_() const = 0;
		virtual void draw_(ostream&, size_t) const = 0;
	};

	template<typename T>
	struct model : concept_t
	{
		virtual ~model() = default;
		model(T x) : data_(move(x)) {}
		concept_t * copy_() const { return new model(*this); }
		void draw_(ostream &out, size_t position)  const
		{
			draw(data_, out, position);
		}

		T data_;
	};

	unique_ptr<concept_t> self_;
};

using Scene = vector<Node>;

void draw(const Scene& scene, ostream& out, size_t indent)
{
	out << string(" ", indent) << "begin scene" << endl;
	for (const auto & x : scene) draw(x, out, indent + 2);
	out << string(" ", indent) << "end scene" << endl;
}

int main(int argc, char **argv)
{
	Scene scene;
	Circle circle(10, 10, 13);
	Rectangle rectangle(5, 5, 7, 7);

	scene.push_back(circle);
	scene.push_back(rectangle);

	draw(scene, cout, 0);


	cout << "reversed:" << endl;
	reverse(begin(scene), end(scene));

	draw(scene, cout, 0);

	return 0;
}

