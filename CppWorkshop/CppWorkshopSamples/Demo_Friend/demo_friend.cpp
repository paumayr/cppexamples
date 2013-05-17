
class ResourceHolder
{
private:
	int myprivatesecret;
	friend class FriendedClass;
};

class FriendedClass
{
public:
	int getPrivateSecret(ResourceHolder &resource)
	{
		return resource.myprivatesecret;
	}
};

class NormalClassWithoutFriendship
{
public:
	int getPrivateSecret(ResourceHolder &resource)
	{
		// cannot access private members of ResourceHolder
		// return resource.myprivatesecret;
	}
};


int main(int argc, char **argv)
{
	return 0;
}