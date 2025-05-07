
import java.util.*;

public class Scheduler {
    // Non-Preemptive Priority Scheduling
    public static List<Process> nonPreemptivePriorityScheduling(List<Process> processes) {
        List<Process> scheduled = new ArrayList<>(processes);
        scheduled.sort(Comparator.comparingInt(p -> p.priority));

        int time = 0;
        for (Process p : scheduled) {
            if (p.arrivalTime > time) {
                time = p.arrivalTime;
            }
            p.completionTime = time + p.burstTime;
            p.calculateTurnaroundTime();
            time += p.burstTime;
        }

        return scheduled;
    }

    // Non-Preemptive Shortest Job First (SJF)
    public static List<Process> nonPreemptiveSJF(List<Process> processes) {
        List<Process> scheduled = new ArrayList<>();
        List<Process> readyQueue = new ArrayList<>();

        processes.sort(Comparator.comparingInt(p -> p.arrivalTime));
        int time = 0;

        while (!processes.isEmpty() || !readyQueue.isEmpty()) {
            // Add processes to ready queue
            for (Iterator<Process> iterator = processes.iterator(); iterator.hasNext(); ) {
                Process p = iterator.next();
                if (p.arrivalTime <= time) {
                    readyQueue.add(p);
                    iterator.remove();
                }
            }

            if (!readyQueue.isEmpty()) {
                readyQueue.sort(Comparator.comparingInt(p -> p.burstTime));
                Process p = readyQueue.remove(0);
                if (time < p.arrivalTime) time = p.arrivalTime;

                p.completionTime = time + p.burstTime;
                p.calculateTurnaroundTime();
                time += p.burstTime;
                scheduled.add(p);
            } else {
                time++;
            }
        }

        return scheduled;
    }

    // Shortest Remaining Time First (SRTF)
    public static List<Process> SRTF(List<Process> processes) {
        List<Process> scheduled = new ArrayList<>(processes);
        scheduled.sort(Comparator.comparingInt(p -> p.arrivalTime));

        int time = 0;
        while (!scheduled.isEmpty()) {
            Process currentProcess = null;
            for (Process p : scheduled) {
                if (p.arrivalTime <= time && p.remainingTime > 0) {
                    if (currentProcess == null || p.remainingTime < currentProcess.remainingTime) {
                        currentProcess = p;
                    }
                }
            }

            if (currentProcess != null) {
                currentProcess.remainingTime--;
                time++;
                if (currentProcess.remainingTime == 0) {
                    currentProcess.completionTime = time;
                    currentProcess.calculateTurnaroundTime();
                }
            } else {
                time++;
            }
        }

        return scheduled;
    }
}
