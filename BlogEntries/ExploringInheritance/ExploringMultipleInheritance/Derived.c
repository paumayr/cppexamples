#include "Derived.h"
#include <stdio.h>

DerivedTable derivedTable;
AnotherBaseTable derivedAnotherBaseTable;

void DerivedPrint(Derived *_this)
{
	printf("Derived::print, baseMember = %d, derivedMember = %d, anotherBaseMember = %d\n", 
		_this->baseData.baseMember, _this->derivedData.derivedMember, _this->anotherBaseData.anotherBaseMember);
}

void DerivedScan(AnotherBase *anotherBase)
{
	// we know that we are called through a derived instance -> get the pointer to the derived
	const size_t offset = sizeof(BaseData) + sizeof (DerivedTable*);
	Derived *_this = (Derived*)(((unsigned char*)anotherBase) - offset);

	printf("Derived::scan, baseMember = %d, derivedMember = %d, anotherBaseMember = %d\n", 
		_this->baseData.baseMember, _this->derivedData.derivedMember, _this->anotherBaseData.anotherBaseMember);
}

void DerivedReadFromFile(Derived *_this)
{
	printf("Derived::readFromFile, baseMember = %d, derivedMember = %d, anotherBaseMember = %d\n", 
		_this->baseData.baseMember, _this->derivedData.derivedMember, _this->anotherBaseData.anotherBaseMember);
}

void DerivedConstruct(Derived *derived, int baseMember, int anotherBaseMember, int derivedMember)
{
	// TODO move this to static initialization code
	derivedTable.printBase = DerivedPrint;
	derivedTable.readFromFile= DerivedReadFromFile;
	derivedAnotherBaseTable.scan = DerivedScan;

	BaseConstruct((Base*)derived, baseMember);
	AnotherBaseConstruct((AnotherBase*)&derived->vfptrAnotherBase, anotherBaseMember);

	derived->vfptrDerived = &derivedTable;
	derived->vfptrAnotherBase = &derivedAnotherBaseTable;

	derived->derivedData.derivedMember = derivedMember;
}

void DerivedDesturct(Derived *derived)
{
}