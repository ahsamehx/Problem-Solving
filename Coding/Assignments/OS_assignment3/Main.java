
import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter the number of processes: ");
        int numProcesses = scanner.nextInt();

        System.out.println("Enter the context switching time: ");
        int contextSwitching = scanner.nextInt();

        List<Process> processes = new ArrayList<>();

        // Input processes
        for (int i = 0; i < numProcesses; i++) {
            System.out.println("Enter details for Process " + (i + 1) + ":");
            System.out.print("Process Name: ");
            String name = scanner.next();
            System.out.print("Arrival Time: ");
            int arrivalTime = scanner.nextInt();
            System.out.print("Burst Time: ");
            int burstTime = scanner.nextInt();
            System.out.print("Priority: ");
            int priority = scanner.nextInt();

            processes.add(new Process(name, arrivalTime, burstTime, priority));
        }

        // Non-Preemptive Priority Scheduling
        Scheduler.nonPreemptivePriorityScheduling(new ArrayList<>(processes));

        // Non-Preemptive Shortest Job First (SJF)
        Scheduler.nonPreemptiveSJF(new ArrayList<>(processes));

        // Shortest Remaining Time First (SRTF)
        Scheduler.SRTF(new ArrayList<>(processes));

        scanner.close();
    }
}
