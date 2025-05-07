package OS_assignment;

public class Parser {
    public String[] parse(String command) {
        return command.trim().split("\\s+");
    }
}
