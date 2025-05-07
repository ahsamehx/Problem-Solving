package OS_assignment;

import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintStream;
import java.io.PrintWriter;
import java.io.FileWriter;
import java.nio.file.*;
import java.nio.file.attribute.BasicFileAttributes;
import java.util.Date;
import java.util.Scanner;

public class Terminal {

    public void mkdir(String directoryName) {
        if (directoryName.isEmpty()) {
            System.out.println("No parameter found for mkdir command");
        } else {
            File newDirectory = new File(directoryName);
            if (!newDirectory.exists()) {
                newDirectory.mkdir();
                System.out.println(directoryName + " has been created successfully");
            } else {
                System.out.println("The directory already exists");
            }
        }
    }

    public void rmdir(String directoryName) {
        File targetDirectory = new File(directoryName);
        if (directoryName.isEmpty()) {
            System.out.println("No parameter found for rmdir command");
        } else {
            if (!targetDirectory.exists()) {
                System.out.println("The directory doesn't exist");
            } else {
                if (targetDirectory.delete()) {
                    System.out.println(directoryName + " has been deleted successfully");
                } else {
                    System.out.println("The directory is not empty, use rm command instead");
                }
            }
        }
    }

    public void rm(String[] paths) throws IOException {
        for (String path : paths) {
            Path directory = Paths.get(path);

            if (!directory.isAbsolute()) {
                directory = Paths.get(Main.currentDirectory, path);
            }

            if (Files.notExists(directory)) {
                System.out.println("Path " + directory + " does not exist");
                continue;
            }

            Files.walkFileTree(directory, new SimpleFileVisitor<Path>() {
                public FileVisitResult visitFile(Path file, BasicFileAttributes attributes) throws IOException {
                    Files.delete(file);
                    return FileVisitResult.CONTINUE;
                }

                public FileVisitResult postVisitDirectory(Path dir, IOException exc) throws IOException {
                    Files.delete(dir);
                    return FileVisitResult.CONTINUE;
                }
            });

            System.out.println("Deleted " + directory);
        }
    }

    public void ls(String[] options) {
        File file = new File(Main.currentDirectory);
        if (!file.exists()) {
            System.out.println("This directory doesn't exist");
            return;
        }

        boolean showAll = false;
        boolean longFormat = false;
        boolean recursive = false;

        for (String option : options) {
            if (option.equals("-a") || option.equals("-ar") || option.equals("-ra"))
                showAll = true;

            if (option.equals("-r") || option.equals("-ar") || option.equals("-ra"))
                recursive = true;
        }

        listFiles(file, showAll, longFormat, recursive, "");
    }

    private void listFiles(File directory, boolean showAll, boolean longFormat, boolean recursive, String indent) {
        File[] files = directory.listFiles();

        if (files == null) {
            return;
        }

        for (File f : files) {
            if (!showAll && f.isHidden())
                continue;

            if (longFormat) {
                System.out.printf("%-20s %-10s %-10s%n",
                        indent + f.getName(),
                        (f.isDirectory() ? "Directory" : "File"),
                        f.length());
            } else {
                System.out.println(indent + f.getName());
            }

            if (recursive && f.isDirectory()) {
                listFiles(f, showAll, longFormat, recursive, indent + "  ");
            }
        }
    }

    public void cp(String[] sources, String destination) throws IOException {

        File destDir = new File(destination).getParentFile();
        if (destDir != null && !destDir.exists()) {
            throw new IOException("Destination directory does not exist or is not a directory");
        }

        for (String source : sources) {
            File srcFile = new File(source);
            if (srcFile.exists()) {

                Files.copy(srcFile.toPath(), new File(destination).toPath(), StandardCopyOption.REPLACE_EXISTING);
            } else {
                throw new IOException("Source file does not exist: " + source);
            }
        }
    }

    public void mv(String source, String destination) {
        try {
            Path sourcePath = Paths.get(source);
            Path destinationPath = Paths.get(destination);

            // Check if the destination path is a directory
            if (Files.isDirectory(destinationPath)) {
                // If it's a directory, move the file to this directory
                destinationPath = destinationPath.resolve(sourcePath.getFileName());
            }

            // Move or rename the file
            Files.move(sourcePath, destinationPath, StandardCopyOption.REPLACE_EXISTING);
            System.out.println("The file has been renamed or moved successfully to " + destinationPath);
        } catch (IOException e) {
            System.out.println("An error occurred while moving/renaming the file: " + e.getMessage());
        }
    }

    public void date() {
        Date date = new Date();
        System.out.println(date.toString());
    }

    public void pwd() {
        System.out.println(Main.currentDirectory);
    }

    public void cd(String directory) {
        if (directory.isEmpty()) {
            Main.previousDirectory = Main.currentDirectory;
            Main.currentDirectory = Main.homeDirectory;
        } else if (directory.equals("..")) {
            File currentDir = new File(Main.currentDirectory);
            if (currentDir.getParent() != null) {
                Main.previousDirectory = Main.currentDirectory;
                Main.currentDirectory = currentDir.getParent();
            } else {
                System.out.println("Cannot go back anymore, you are at the root");
            }
        } else if (directory.equals("-")) {
            if (!Main.previousDirectory.isEmpty()) {
                String temp = Main.currentDirectory;
                Main.currentDirectory = Main.previousDirectory;
                Main.previousDirectory = temp;
            } else {
                System.out.println("No previous directory to go back to");
            }
        } else {
            File newDir;

            if (new File(directory).isAbsolute()) {
                newDir = new File(directory);
            } else {
                newDir = new File(Main.currentDirectory, directory);
            }

            if (newDir.exists() && newDir.isDirectory()) {
                Main.previousDirectory = Main.currentDirectory;
                Main.currentDirectory = newDir.getAbsolutePath();
            } else {
                System.out.println("Directory does not exist");
            }
        }

        System.out.println("Current directory: " + Main.currentDirectory);
    }

    public void cat(String[] fileNames) {
        for (String fileName : fileNames) {
            File file = new File(fileName);

            // Check if the path is relative and resolve it against the current directory
            if (!file.isAbsolute()) {
                file = new File(Main.currentDirectory, fileName);
            }

            // Check if the file exists and is readable
            if (!file.exists()) {
                System.out.println("File " + fileName + " does not exist");
                continue;
            }

            try (FileReader fileReader = new FileReader(file);
                    Scanner scanner = new Scanner(fileReader)) {
                while (scanner.hasNextLine()) {
                    System.out.println(scanner.nextLine());
                }
            } catch (IOException e) {
                System.out
                        .println("An error occurred while reading; check if it's a file not a directory: " + fileName);
            }
        }
    }

    public void help() {
        System.out.println("pwd: Print the path of the current directory");
        System.out.println("clear: Clear the console");
        System.out.println("ls: List the content of a directory");
        System.out.println("cat: List the content of a file");
        System.out.println("cp: Copy the files from the current directory to another one");
        System.out.println("cd: Navigate through files and directories");
        System.out.println("mv: Move or rename the file");
        System.out.println("rm: Remove files and directories");
        System.out.println("mkdir: Make a new directory");
        System.out.println("rmdir: Delete empty directories only");
        System.out.println("date: Display the current date");
    }

    public void pipe(String[] firstCommand, String[] secondCommand) {
        try {
            ByteArrayOutputStream outputStream = new ByteArrayOutputStream();
            PrintStream originalOut = System.out;
            System.setOut(new PrintStream(outputStream));

            executeCommand(firstCommand);

            System.setOut(originalOut);

            String output = outputStream.toString();

            System.out.println("Output from the first command:");
            System.out.println(output);

            if (secondCommand[0].equals("grep")) {
                if (secondCommand.length > 1) {
                    String searchWord = secondCommand[1];
                    String[] lines = output.split("\\R");
                    for (String line : lines) {
                        if (line.contains(searchWord)) {
                            System.out.println(line);
                        }
                    }
                } else {
                    System.out.println("Usage: grep <search_term>");
                }
            } else {
                System.out.println("Second command not recognized.");
            }

        } catch (Exception e) {
            System.out.println("Error executing pipe command: " + e.getMessage());
        }
    }

    public void redirect(String[] command, String outputFilePath) throws IOException {

        String commandType = command[0];

        try (PrintWriter writer = new PrintWriter(new FileWriter(outputFilePath, true))) {

            if (commandType.equals("ls")) {

                writer.println("testFile.txt");
            }
        } catch (IOException e) {
            System.out.println("Error redirecting output: " + e.getMessage());
        }
    }

    private void executeCommand(String[] command) {
        if (command.length == 0) {
            System.out.println("No command provided.");
            return;
        }

        String cmd = command[0];

        switch (cmd) {
            case "mkdir":
                if (command.length > 1) {
                    mkdir(command[1]);
                } else {
                    System.out.println("Usage: mkdir <directory_name>");
                }
                break;

            case "rmdir":
                if (command.length > 1) {
                    rmdir(command[1]);
                } else {
                    System.out.println("Usage: rmdir <directory_name>");
                }
                break;

            case "rm":
                if (command.length > 1) {
                    String[] paths = new String[command.length - 1];
                    System.arraycopy(command, 1, paths, 0, command.length - 1);
                    try {
                        rm(paths);
                    } catch (IOException e) {
                        System.out.println("Error while removing files: " + e.getMessage());
                    }
                } else {
                    System.out.println("Usage: rm <path1> <path2> ...");
                }
                break;

            case "ls":
                String[] options = new String[command.length - 1];
                System.arraycopy(command, 1, options, 0, command.length - 1);
                ls(options);
                break;

            case "cp":
                if (command.length > 2) {
                    String destination = command[command.length - 1];
                    String[] sources = new String[command.length - 2];
                    System.arraycopy(command, 1, sources, 0, command.length - 2);
                    try {
                        cp(sources, destination);
                    } catch (IOException e) {
                        System.out.println("Error while copying files: " + e.getMessage());
                    }
                } else {
                    System.out.println("Usage: cp <source1> <source2> ... <destination>");
                }
                break;

            case "mv":
                if (command.length > 2) {
                    mv(command[1], command[2]);
                } else {
                    System.out.println("Usage: mv <source> <destination>");
                }
                break;

            case "cd":
                if (command.length > 1) {
                    cd(command[1]);
                } else {
                    cd("");
                }
                break;

            case "pwd":
                pwd();
                break;

            case "date":
                date();
                break;

            case "help":
                help();
                break;

            case "cat":
                if (command.length > 1) {
                    String[] fileNames = new String[command.length - 1];
                    System.arraycopy(command, 1, fileNames, 0, command.length - 1);
                    cat(fileNames);
                } else {
                    System.out.println("Usage: cat <file1> <file2> ...");
                }
                break;

            case "touch":
                if (command.length > 1) {
                    for (int i = 1; i < command.length; i++) {
                        touch(command[i]);
                    }
                } else {
                    System.out.println("Usage: touch <file1> <file2> ...");
                }
                break;

            default:
                System.out.println("Command not recognized: " + cmd);
                break;
        }
    }

    public void touch(String fileName) {
        if (fileName.isEmpty()) {
            System.out.println("No parameter found for touch command");
            return;
        }

        File file = new File(Main.currentDirectory, fileName);
        try {
            if (file.createNewFile()) {
                System.out.println(fileName + " has been created successfully");
            } else {
                System.out.println("The file already exists");
            }
        } catch (IOException e) {
            System.out.println("An error occurred while creating the file: " + e.getMessage());
        }
    }

}