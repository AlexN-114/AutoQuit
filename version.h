#ifndef VERSION_H
#define VERSION_H

namespace AutoVersion{

	//Date Version Types
	static const char DATE[] = "16";
	static const char MONTH[] = "04";
	static const char YEAR[] = "2024";
	static const char UBUNTU_VERSION_STYLE[] =  "24.03";

	//Software Status
	static const char STATUS[] =  "Beta";
	static const char STATUS_SHORT[] =  "ß";

	//Standard Version Type
	static const long MAJOR  = 1;
	static const long MINOR  = 0;
	static const long BUILD  = 5;
	static const long REVISION  = 9;

	//Miscellaneous Version Types
	static const long BUILDS_COUNT  = 36;
	#define RC_FILEVERSION 1,0,5,9
	#define RC_FILEVERSION_STRING "1, 0, 5, 9\0"
	static const char FULLVERSION_STRING [] = "1.0.5.9";

	//These values are to keep track of your versioning state, don't modify them.
	static const long BUILD_HISTORY  = 5;

}
#endif //VERSION_H
