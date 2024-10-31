#include <iostream>
#include <VersioningConfig.h>

int main (int argc, char* argv[])
{
    std::cout << "\nVersion " 
    << Versioning_VERSION_MAJOR << "." 
    << Versioning_VERSION_MINOR << "." 
    << Versioning_VERSION_PATCH << std::endl;

    return 0;
}