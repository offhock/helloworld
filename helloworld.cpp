#include "Poco/BasicEvent.h"
#include "Poco/Delegate.h"
#include "Poco/JSON/Parser.h"
#include "Poco/JSON/ParseHandler.h"
#include "Poco/JSON/Object.h"

#include <string>
#include <iostream>

using Poco::BasicEvent;
using Poco::delegate;

class Source
{
public:
    BasicEvent<int> theEvent;

    void fireEvent(int n)
    {
        theEvent(this, n);
    }
};

class Target
{
public:
    void onEvent(const void* pSender, int& arg)
    {
        std::cout << "onEvent: " << arg << std::endl;
    }
};

int main(int argc, char** argv)
{
    {
        Source source;
        Target target;
        source.theEvent += delegate(&target, &Target::onEvent);
        source.fireEvent(42);
        source.theEvent -= delegate(&target, &Target::onEvent);
    }
    {
        // objects
        std::string json = "{ \"test\" : { \"property\" : \"value\" } }";
        Poco::JSON::Parser parser;
        Poco::Dynamic::Var result = parser.parse(json);
        Poco::JSON::Object::Ptr object = result.extract<Poco::JSON::Object::Ptr>();
        Poco::Dynamic::Var test = object->get("test");
        object = test.extract< Poco::JSON::Object::Ptr>();
        test = object->get("property");
        std::string value = test.convert<std::string>();
    }

    {

        // array of objects
        std::string json = "[ {\"test\" : 0}, { \"test1\" : [1, 2, 3], \"test2\" : 4 } ]";
        Poco::JSON::Parser parser;
        Poco::Dynamic::Var result = parser.parse(json);
        Poco::JSON::Array::Ptr arr = result.extract<Poco::JSON::Array::Ptr>();
        Poco::JSON::Object::Ptr object = arr->getObject(0);//
        assert (object->getValue<int>("test") == 0);
        object = arr->getObject(1);
        arr = object->getArray("test1");
        result = arr->get(0);
        assert (result == 1);
    }
    return 0;
}