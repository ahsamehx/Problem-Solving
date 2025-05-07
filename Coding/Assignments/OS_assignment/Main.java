package OS_assignment;

import java.io.IOException;
import java.util.Scanner;

public class Main {
    public static String currentDirectory = System.getProperty("user.dir");
    public static String homeDirectory = System.getProperty("user.dir");
    public static String previousDirectory = "";

    public static void main(String[] args) throws IOException {
        Terminal terminal = new Terminal();
        Parser parser = new Parser();
        Scanner scanner = new Scanner(System.in);

        while (true) {
            System.out.print(currentDirectory + " $ ");
            String input = scanner.nextLine().trim();

            if (input.equalsIgnoreCase("exit")) {
                break;
            }

            String[] splitPipe = input.split("\\|");
            if (splitPipe.length == 2) {
                String[] firstCommand = parser.parse(splitPipe[0].trim());
                String[] secondCommand = parser.parse(splitPipe[1].trim());
                terminal.pipe(firstCommand, secondCommand);
            } else {

                if (input.contains(">")) {
                    String[] parts = input.split(">");
                    String commandPart = parts[0].trim();
                    String outputFile = parts[1].trim();

                    String[] commandArray = parser.parse(commandPart);
                    terminal.redirect(commandArray, outputFile);
                } else if (input.contains(">>")) {
                    String[] parts = input.split(">>");
                    String commandPart = parts[0].trim();
                    String outputFile = parts[1].trim();

                    String[] commandArray = parser.parse(commandPart);
                    terminal.redirect(commandArray, outputFile);
                } else {

                    String[] tokens = parser.parse(input);

                    // Handle the 'touch' command
                    if (tokens[0].equals("touch")) {
                        if (tokens.length > 1) {
                            for (int i = 1; i < tokens.length; i++) {
                                terminal.touch(tokens[i]); 
                            }
                        } else {
                            System.out.println("Usage: touch <file1> <file2> ...");
                        }



                } else if (tokens[0].equals("mkdir")) {
                        if (tokens.length > 1) {
                            terminal.mkdir(tokens[1]);
                        } else {
                            System.out.println("Usage: mkdir <directory_name>");
                        }
                    } else if (tokens[0].equals("rmdir")) {
                        if (tokens.length > 1) {
                            terminal.rmdir(tokens[1]);
                        } else {
                            System.out.println("Usage: rmdir <directory_name>");
                        }
                    } else if (tokens[0].equals("rm")) {
                        if (tokens.length > 1) {
                            String[] paths = new String[tokens.length - 1];
                            System.arraycopy(tokens, 1, paths, 0, tokens.length - 1);
                            terminal.rm(paths);
                        } else {
                            System.out.println("Usage: rm <path1> <path2> ...");
                        }
                    } else if (tokens[0].equals("ls")) {
                        String[] options = new String[tokens.length - 1];
                        System.arraycopy(tokens, 1, options, 0, tokens.length - 1);
                        terminal.ls(options);
                    } else if (tokens[0].equals("cp")) {
                        if (tokens.length > 2) {
                            String destination = tokens[tokens.length - 1];
                            String[] sources = new String[tokens.length - 2];
                            System.arraycopy(tokens, 1, sources, 0, tokens.length - 2);
                            terminal.cp(sources, destination);
                        } else {
                            System.out.println("Usage: cp <source1> <source2> ... <destination>");
                        }
                    } else if (tokens[0].equals("mv")) {
                        if (tokens.length > 2) {
                            terminal.mv(tokens[1], tokens[2]);
                        } else {
                            System.out.println("Usage: mv <source> <destination>");
                        }
                    } else if (tokens[0].equals("cd")) {
                        if (tokens.length > 1) {
                            terminal.cd(tokens[1]);
                        } else {
                            terminal.cd("");
                        }
                    } else if (tokens[0].equals("pwd")) {
                        terminal.pwd();
                    } else if (tokens[0].equals("date")) {
                        terminal.date();
                    } else if (tokens[0].equals("help")) {
                        terminal.help();
                    } else if (tokens[0].equals("cat")) {
                        if (tokens.length > 1) {
                            String[] fileNames = new String[tokens.length - 1];
                            System.arraycopy(tokens, 1, fileNames, 0, tokens.length - 1);
                            terminal.cat(fileNames);
                        } else {
                            System.out.println("Usage: cat <file1> <file2> ...");
                        }
                    } else {
                        System.out.println("Command not recognized");
                    }
                }
            }
        }

        scanner.close();
    }
}
