/**
 * SJF scheduling algorithm.
 */
 
 import java.util.*;

 public class SJF implements Algorithm
 {
     private List<Task> queue;
     private Task currentTask;
 
     private int tasksRun;
 
     public SJF(List<Task> queue) {
         this.queue = queue;
         tasksRun = queue.size();
     }
 
     public void schedule() {
         System.out.println("SJF Scheduling \n");
 
         while (!this.queue.isEmpty()) {
             this.currentTask = pickNextTask();             
             CPU.run(currentTask, currentTask.getBurst());

             // remove the task
             queue.remove(currentTask);
         }  
     }
 
     public Task pickNextTask() {
        int m = 0;
        Task task = this.queue.get(m);
        int n = task.getBurst();
        for(int i = 1; i < this.queue.size(); i++){
            if (this.queue.get(i).getBurst() >= n){
                continue;
            };
            m = i;
            n = this.queue.get(i).getBurst();
        }
        task = this.queue.get(m);
        return task;
     }
 }
 