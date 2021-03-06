#pragma once
#include <string>
#include <vector>
using std::string;
using std::vector;

#include "CompilationUnit/CompilationUnit.h"

class Package : std::enable_shared_from_this<Package>
{
    private:
        string full_name = ".";
        string name = ".";
        vector<string> name_vector;

        vector<shared_ptr<Package>> child_packages;
        vector<shared_ptr<CompilationUnit>> compilation_units;

    public:
        Package();
        Package(string full_name);
        Package(vector<string> name_vector);

        void addChildPackage(string package_name);
        void addChildPackage(vector<string> name_vector, size_t step = 0);

        shared_ptr<Package> getChildPackageByName(string full_name);
        shared_ptr<Package> getChildPackageByName(vector<string> name_vector);
        vector<shared_ptr<Package>> getChildPackages();

        shared_ptr<CompilationUnit> addCompilationUnit(shared_ptr<CompilationUnit> unit);
        vector<shared_ptr<CompilationUnit>> getCompilationUnits();

        string getDebug(string indent = "", bool last = true);
};