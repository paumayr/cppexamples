
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <unordered_map>
#include <functional>

using namespace std;

class phonebook_entry
{
	string name;
	string number;
public:
	phonebook_entry(string name, string number) : name(name), number(number) {}

	const string& getName() const { return name; }
	const string& getNumber() const { return number; }

	bool operator==(const phonebook_entry& other)
	{
		return name == other.name && number == other.number;
	}
};

class phonebook
{
public:
	vector<phonebook_entry> entries;

	bool remove(phonebook_entry entry)
	{
		auto pos = find(begin(entries), end(entries), entry);
		if (pos != entries.end())
			entries.erase(pos);
		return pos != entries.end();
	}
};

ostream& operator<<(ostream& os, const phonebook_entry &e)
{
	os << e.getName() << " " << e.getNumber();
	return os;
}

phonebook load(string path)
{
	fstream f(path);
	string line;
	decltype(load(path)) result;
	if (f)
	{
		while (!f.eof())
		{
			getline(f, line);
			if (line == "")
				continue;

			stringstream ls(line);
			string name;
			string number;

			ls >> name >> number;
			result.entries.emplace_back(phonebook_entry{ name, number });
		}
	}

	return result;
}

void save(string path, phonebook book)
{
	ofstream f(path);
	for (auto &e : book.entries) f << e << endl;
}

int _main(vector<string> args)
{
	const auto& filename = args[1];
	const auto& command = args[2];
	auto phonebook = load(filename);
	bool edited = false;

	unordered_map <string, function<bool()>> commands
	{
		{ "add", [&]() { phonebook.entries.emplace_back(phonebook_entry(args[3], args[4])); return true; } },
		{ "remove", [&]() { return phonebook.remove(phonebook_entry(args[3], args[4])); } }
	};

	// find command to execute
	auto cmd = commands.find(command);
	if (cmd != commands.end())
	{
		// dispatch command
		edited = cmd->second();
	}
	else
	{
		cerr << "unknown command: " << command << endl;
	}

	if (edited)
		save(filename, phonebook);

	return 0;
}

int main(int argc, char **argv)
{
	vector<string> params;
	for (int i = 0; i < argc; i++) params.push_back(argv[i]);
	return _main(params);
}