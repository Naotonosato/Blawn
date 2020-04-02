namespace debug {

class Position {
    private:
    int line_number;
    int index_in_line;

    public:
    Position() = default;
    Position(int line_number, int index_in_line)
        : line_number(line_number), index_in_line(index_in_line) {}
};

class DebugInfo {
    Position position;
};

}  // namespace debug