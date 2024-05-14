#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <sstream>

class Command{
public:
    virtual ~Command() = default;
    virtual std::string cmdName() const = 0;
    virtual void execute(int& index, std::vector<int>& vec) = 0;
};


class CmdLeft : public Command{
public:
    void execute(int &index, std::vector<int> &vec) override{
        index = (index - L + vec.size()) % vec.size();
    }
    std::string cmdName() const override{
        return "LEFT " + std::to_string(L);
    }
private:
    int L;
};

class CmdRight : public Command{
public:
    void execute(int &index, std::vector<int> &vec) override{
        index = (index + R + vec.size()) % vec.size();
    }
    std::string cmdName() const override{
        return "RIGHT " + std::to_string(R);
    }
private:
    int R;
};

class CmdAdd : public Command{
public:
    void execute(int &index, std::vector<int> &vec) override{
        vec[index] += D;
    }
    std::string cmdName() const override{
        return "ADD " + std::to_string(D);
    }
private:
    int D;
};

class CmdSub : public Command{
public:
    void execute(int &index, std::vector<int> &vec) override{
        vec[index] *= B;
    }
    std::string cmdName() const override{
        return "ADD " + std::to_string(B);
    }
private:
    int B;
};

int main() {
    std::vector<int> arr = {1, 2, 3, 4, 5};
    std::vector<Command*> cmdlist;

    std::string name;
    while (true){
        std::getline(std::cin, name);

        if (name == "^C") {
            break;
        }
        std::istringstream essa(name);
        std::string cmd;
        int value;
        essa >> cmd >> value;


        std::unique_ptr<Command> cmdPtr;

    }
}
