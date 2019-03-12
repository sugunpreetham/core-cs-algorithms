package os;

import java.util.*;

public class RoundRobinScheduler {
    public static class Process {
        public final int id;
        public int remainingTime;
        public int turnaroundTime;
        public int waitTime;

        public Process(int id, int burstTime) {
            this.id = id;
            this.remainingTime = burstTime;
        }
    }

    public static void schedule(List<Process> processes, int quantum) {
        Queue<Process> queue = new LinkedList<>(processes);
        int currentTime = 0;

        while (!queue.isEmpty()) {
            Process p = queue.poll();
            int exec = Math.min(p.remainingTime, quantum);
            p.remainingTime -= exec;
            currentTime += exec;

            if (p.remainingTime > 0) {
                queue.add(p);
            } else {
                p.turnaroundTime = currentTime;
            }
        }
    }
}
