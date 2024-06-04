#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <sstream>
#include <fstream>

struct Helper;

class Command {
public:
    virtual std::unique_ptr<Command> Create(std::string line) = 0;

    virtual void Doing(Helper &dada) = 0;

    virtual bool IsSave() = 0;
};

struct Helper {
    std::ofstream &outputFile;
    std::vector<int> buffer;
    int cursor;
    std::vector<std::unique_ptr<Command>> commands;
};


class Left : public Command {
public:
    Left() = default;

    explicit Left(int val) : val(val) {};

    std::unique_ptr<Command> Create(std::string line) final {
        std::istringstream iss(line);
        std::string cmd;
        iss >> cmd >> val;
        if (cmd == "LEFT") {
            return std::make_unique<Left>(Left(val));
        }
        return nullptr;
    };

    void Doing(Helper &dada) final {
        dada.cursor = std::abs(dada.cursor - val) % int(dada.buffer.size());
    }

    bool IsSave() final { return true; }

private:
    int val = 0;
};

class Right : public Command {
public:
    Right() = default;

    explicit Right(int val) : val(val) {};

    std::unique_ptr<Command> Create(std::string line) final {
        std::istringstream iss(line);
        std::string cmd;
        iss >> cmd >> val;
        if (cmd == "RIGHT") {
            return std::make_unique<Right>(Right(val));
        }
        return nullptr;
    };

    void Doing(Helper &dada) final {
        dada.cursor = std::abs(dada.cursor + val) % int(dada.buffer.size());
    }

    bool IsSave() final { return true; }

private:
    int val = 0;
};

class Add : public Command {
public:
    Add() = default;

    explicit Add(int val) : val(val) { ; }

    std::unique_ptr<Command> Create(std::string line) final {
        std::istringstream iss(line);
        std::string cmd;
        iss >> cmd >> val;
        if (cmd == "ADD") {
            return std::make_unique<Add>(Add(val));
        }
        return nullptr;
    };

    void Doing(Helper &dada) final {
        dada.buffer[dada.cursor] += val;
    }

    bool IsSave() final { return true; }

private:
    int val = 0;
};

class Sub : public Command {
public:
    Sub() = default;

    explicit Sub(int val) : val(val) { ; }

    std::unique_ptr<Command> Create(std::string line) final {
        std::istringstream iss(line);
        std::string cmd;
        iss >> cmd >> val;
        if (cmd == "SUB") {
            return std::make_unique<Sub>(Sub(val));
        }
        return nullptr;
    };

    void Doing(Helper &dada) final {
        dada.buffer[dada.cursor] -= val;
    }

    bool IsSave() final { return true; }

private:
    int val = 0;
};

class Go : public Command{
public:
    Go() = default;
    explicit Go(int val) : val(val) {;}

    std::unique_ptr<Command> Create(std::string line) final {
        std::istringstream iss(line);
        std::string cmd;
        iss >> cmd >> val;
        if (cmd == "GO") {
            return std::make_unique<Go>(Go(val));
        }
        return nullptr;
    };

    void Doing(Helper& dada) final {
        dada.cursor = 0;
        dada.buffer = std::vector<int>(val);

        for (auto& i : dada.commands){
            i->Doing(dada);
        }
        dada.outputFile << dada.buffer[dada.cursor] << std::endl;
    };

    bool IsSave() final {return false;}

private:
    int val = 0;
};

class Rev : public Command{
public:
    Rev() = default;
    explicit Rev(int val) : val(val) {;}

    std::unique_ptr<Command> Create(std::string line) final {
        std::istringstream iss(line);
        std::string cmd;
        iss >> cmd >> val;
        if (cmd == "REV") {
            return std::make_unique<Rev>(Rev(val));
        }
        return nullptr;
    };

    virtual void Doing(Helper& dada) final {
        for (int i = 0; i < val; i++) {
            dada.commands.pop_back();
        }
    };

    bool IsSave() final {return false;}

private:
    int val = 0;
};

class CmdFather{
public:
    CmdFather() {
        cmds.push_back(std::make_unique<Left>(Left()));
        cmds.push_back(std::make_unique<Right>(Right()));
        cmds.push_back(std::make_unique<Add>(Add()));
        cmds.push_back(std::make_unique<Sub>(Sub()));
        cmds.push_back(std::make_unique<Go>(Go()));
        cmds.push_back(std::make_unique<Rev>(Rev()));
    }

    void Parsing(std::ifstream& inputFile, std::ofstream& outputFile){
        std::string line;

        Helper dada = {
                outputFile,
                std::vector<int>(0),
                0,
                std::vector<std::unique_ptr<Command>>(0)
        };

        while (std::getline(inputFile, line)) {
            for (auto& i : cmds) {
                auto cmd_pointer = i->Create(line);
                if (cmd_pointer != nullptr) {
                    if (cmd_pointer->IsSave()) {
                        dada.commands.emplace_back(std::move(cmd_pointer));
                    } else {
                        cmd_pointer->Doing(dada);
                    }
                }
            }
        }
    }
private:
    std::vector<std::unique_ptr<Command>> cmds;
};

int main(int argc, char* argv[]){
    std::string inputFilePath;
    std::string outputFilePath;

    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg == "-i" && i + 1 < argc) {
            inputFilePath = argv[++i];
        } else if (arg == "-o" && i + 1 < argc) {
            outputFilePath = argv[++i];
        }
    }

    if (inputFilePath.empty()) {
        std::cout << "no input file provided: " << inputFilePath;
        return 1;
    }
    if (outputFilePath.empty()) {
        std::cout << "no output file provided: " << outputFilePath;
        return 1;
    }

    std::ifstream inputFile;
    inputFile.open(inputFilePath);

    std::ofstream outputFile;
    outputFile.open(outputFilePath);

    CmdFather robobuba;
    robobuba.Parsing(inputFile, outputFile);
}