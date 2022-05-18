//
//  main.cpp
//  PolicyExamples
//
//  Created by Diana UMA on 20/12/21.
//

#include <iostream>

struct Grid;
struct LoadFromJson;
struct LoadFromGUI;

template <typename DrawingPolicy,
          typename StartPolicy = LoadFromGUI>
class Trial : public DrawingPolicy, public StartPolicy
{
    using DrawingPolicy::draw;
    using StartPolicy::start;
public:
    
    Trial() {
        DrawingPolicy::setup();
        StartPolicy::setup();
    }
    
    void run()
    {
        start();
        draw();
    }
};

struct Grid {
    int parameter1, parameter2;
    
    void setup()
    {
        std::cout << "Setting up grid!" << std::endl;
        parameter1 = 25;
        parameter2 = 26;
    }
    
    void draw()
    {
        std::cout << "Drawing grid!" << parameter1 << " " << parameter2 << std::endl;
        
    }
};

#include <string>

struct LoadFromJson {
    
    std::string parameter;
    
    void setup() {
        std::cout << "Setting up Load From JSON!" << std::endl;
        parameter = "void";
    }
    
    void specialStart(const std::string & _parameter) {
        parameter = _parameter;
    }
    
    void start()
    {
        std::cout << "Loading from JSON with parameter " << parameter << std::endl;
    }
};

struct LoadFromGUI {
    
    int rows, columns;
    
    void setup() {
        rows = 10; columns = 10;
    }
    
    void start()
    {
        std::cout << "Loading from GUI!" << rows << columns << std::endl;
    }
};

Trial<Grid> exp1;  // Default reads from GUI.
Trial<Grid,LoadFromJson> exp2;

int main(int argc, const char * argv[]) {
    exp1.run();
    exp2.specialStart("Super Special Parameter"); // This can be done thanks to
    exp2.run();
    return 0;
}
