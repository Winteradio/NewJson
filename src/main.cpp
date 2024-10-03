#include <iostream>
#include <fstream>
#include <string>

#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/istreamwrapper.h"

using namespace std;

int main()
{
    std::string filePath = "C:\\Users\\Winteradio\\Desktop\\NewGLTF\\resource\\AnimatedCube.gltf";
    std::ifstream fileStream;
    fileStream.open(filePath);

    rapidjson::IStreamWrapper isw(fileStream);

    rapidjson::Document d;
    d.ParseStream(isw);

    // 2. Modify it by DOM.
    rapidjson::Value& s = d["accessors"];
    s.SetInt(s.GetInt() + 1);

    // 3. Stringify the DOM
    rapidjson::StringBuffer buffer;
    rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
    d.Accept(writer);

    // Output {"project":"rapidjson","stars":11}
    std::cout << buffer.GetString() << std::endl;

    system("pause");
    return 0;
}