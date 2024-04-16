#ifndef VERSION_H
#define VERSION_H

namespace AutoVersion{

	//Date Version Types
	static const char DATE[] = "15";
	static const char MONTH[] = "04";
	static const char YEAR[] = "2024";
	static const char UBUNTU_VERSION_STYLE[] =  "24.03";

	//Software Status
	static const char STATUS[] =  "Beta";
	static const char STATUS_SHORT[] =  "�";

	//Standard Version Type
	static const long MAJOR  = 1;
	static const long MINOR  = 0;
	static const long BUILD  = 4;
	static const long REVISION  = 7;

	//Miscellaneous Version Types
	static const long BUILDS_COUNT  = 36;
	#define RC_FILEVERSION 1,0,4,7
	#define RC_FILEVERSION_STRING "1, 0, 4, 7\0"
	static const char FULLVERSION_STRING [] = "1.0.4.7";

	//These values are to keep track of your versioning state, don't modify them.
	static const long BUILD_HISTORY  = 4;

}
#endif //VERSION_H