/**
 * Priority scheduling algorithm.
 */
 
 import java.util.*;

 public class Priority implements Algorithm
 {
     private List<Task> queue;
     private Task currentTask;
     private int tasksRun;
 
     public Priority(List<Task> queue) {
         this.queue = queue;
         tasksRun = queue.size();
     }
 
     public void schedule() {
         System.out.println("Priority Scheduling \n");
         while (!queue.isEmpty()) {
             currentTask = pickNextTask();
             CPU.run(currentTask, currentTask.getBurst());
 
             // remove the task
             queue.remove(currentTask);
         }
     }
 
     public Task pickNextTask() {
        int n = 0;
        Task task = this.queue.get(n);
        int m = task.getPriority();
        for(int i = 1; i < this.queue.size(); i++)
        {
            if(this.queue.get(i).getPriority() <= m){
                continue;
            }
            n = i;
            m = this.queue.get(i).getPriority();
        }
        task = this.queue.get(n);
        return task;
     }
 }
 