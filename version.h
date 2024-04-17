#ifndef VERSION_H
#define VERSION_H

namespace AutoVersion{

	//Date Version Types
	static const char DATE[] = "16";
	static const char MONTH[] = "04";
	static const char YEAR[] = "2024";
	static const char UBUNTU_VERSION_STYLE[] =  "24.03";

	//Software Status
	static const char STATUS[] =  "Release Canditate";
	static const char STATUS_SHORT[] =  "rc";

	//Standard Version Type
	static const long MAJOR  = 1;
	static const long MINOR  = 0;
	static const long BUILD  = 7;
	static const long REVISION  = 11;

	//Miscellaneous Version Types
	static const long BUILDS_COUNT  = 36;
	#define RC_FILEVERSION 1,0,7,11
	#define RC_FILEVERSION_STRING "1, 0, 7, 11\0"
	static const char FULLVERSION_STRING [] = "1.0.7.11";

	//These values are to keep track of your versioning state, don't modify them.
	static const long BUILD_HISTORY  = 7;

}
#endif //VERSION_H
