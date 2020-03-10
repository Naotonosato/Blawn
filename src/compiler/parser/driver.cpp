#include "driver.hpp"
#include <cassert>
#include <cctype>
#include <fstream>

Blawn::Driver::~Driver() {
    delete (scanner);
    scanner = nullptr;
    delete (parser);
    parser = nullptr;
}

void Blawn::Driver::parse(const char *const filename) {
    assert(filename != nullptr);
    std::ifstream in_file(filename);
    if (!in_file.good()) {
        exit(1);
    }
    parse_helper(in_file);
    return;
}

void Blawn::Driver::parse(std::istream &stream) {
    if (!stream.good() && stream.eof()) {
        return;
    }
    // else
    parse_helper(stream);
    return;
}

void Blawn::Driver::parse_helper(std::istream &stream) {
    // delete (scanner);
    auto new_scanner = new Blawn::Scanner(&stream, this);
    // delete (parser);
    auto new_parser = new Blawn::Parser(*new_scanner, *this);
    const int accept(0);
    if (new_parser->parse() != accept) {
        std::cerr << "syntax error" << std::endl;
        /*<< "\033[38;2;0;0;255m"
        << "YOU LOSE\033[0m\n" << "構文解析器の勝ち！\n"
        << "何で負けたか、明日まで考えといてください。\n"
        <<"そしたら何かが見えてくるはずです。\n"
        << "ほな、いただきます!!\n";
        */
    }
    return;
}
