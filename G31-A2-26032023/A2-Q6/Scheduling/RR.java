/**
 * Round Robin scheduling algorithm.
 */

import java.util.*;

public class RR implements Algorithm {
    private List<Task> queue;
    private Task currentTask;
    private int tasksRun;

    // 10 second time quantum
    public int time_quantum = 10; 

    public RR(List<Task> queue) {
        this.queue = queue;
        tasksRun = queue.size();
    }

    public void schedule() {
        System.out.println("Round Robin Scheduling \n");
        int n = 0;
        boolean out_of_time = true;
        
        while (!this.queue.isEmpty()) {
            if(out_of_time == true){
                currentTask = pickNextTask();
            }
            n = currentTask.getBurst();
            if(n < time_quantum){
                n = currentTask.getBurst();
            }
            else{
                n = time_quantum;
            }
            CPU.run(currentTask, n);
            currentTask.setBurst(currentTask.getBurst() - n);
            if(currentTask.getBurst() == 0){
                System.out.printf("Task %s finished.%n", currentTask.getName());
                this.queue.remove(currentTask);
                out_of_time = true;
                continue;
            }
            this.queue.remove(currentTask);
            this.queue.add(currentTask);
            out_of_time = true;
        }
    }


    public Task pickNextTask() {
        Task task = this.queue.get(0);
        return task;
    }
}
