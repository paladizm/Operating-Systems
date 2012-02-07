/**
 * BD-shell 1.0.0 SHELL
 * Description: a mini unix shell
 * Author: Daniel Graziotin, 4801, daniel.graziotin@unibz.it
 * Project URL: http://daniel.graziotin.net/projects/bd-shell
 * Read the documentation before using the shell
 */

/**
 * FEATURES:
 *  - Reads commands from standard input and execute them in a loop until a
 *     built-in command exit is issued
 *  - Redirects the standard input and output of commands
 *    by prefixing them with built-in commands in file and out file;
 *  - Terminates (involuntarily) the foreground process
 *    when user presses ^C and return back to the mini-shell;
 *  - Interrupts the foreground process temporarily, when user presses ^Z,
 *    returning to the mini-shell;
 *  - Executes any number of processes in background (i.e., in parallel with the foreground process),
 *    including in particular, the ability to start another process
 *    while a process has been temporarily suspended;
 *  - Informs the user when the background process finishes or is
 *    waiting for an input from the terminal;
 *  - Informs the user what commands are executing in the background by issuing
 *    the built-in command jobs, this should include information about the state
 *    of the process (i.e., suspended, background, waiting for input, etc.)
 *    and about what file(s) is the background process using for standard input and output);
 *  - Terminates involuntarily a background processes by issuing the built-in command kill job-number.
 *  - Resumes a process or to make a background process into the foreground process
 *    by issuing the fg job-number command.
 */

/**
 * LICENSE
 * This file is part of BD-shell.
 *
 *   BD-shell is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   BD-shell is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with BD-shell.  If not, see <http://www.gnu.org/licenses/>.
 *
 **/

#include "headers.h"                                                                            // declarations and prototypes
#include "utils.h"                                                                                   // utility functions

/**
 * generic execute void, tries to execute built-in programs first, and everything else then.
 */
void handleUserCommand()
{
        if ((checkBuiltInCommands(commandArgv[0])) == 0) {
                launchJob(commandArgv, "STANDARD", 0, FOREGROUND);
        }
}

/**
 * built-in commands: exit, in, out, bg, fg, jobs, kill
 * returns 	1 if a built-in command is executed,
 * 			0 otherwise
 */
int checkBuiltInCommands()
{
        if (strcmp("exit", commandArgv[0]) == 0) {
                exit(EXIT_SUCCESS);
        }
        if (strcmp("cd", commandArgv[0]) == 0) {
                changeDirectory();
                return 1;
        }
        if (strcmp("in", commandArgv[0]) == 0) {
                launchJob(commandArgv + 2, *(commandArgv + 1), STDIN, FOREGROUND);
                return 1;
        }
        if (strcmp("out", commandArgv[0]) == 0) {
                launchJob(commandArgv + 2, *(commandArgv + 1), STDOUT, FOREGROUND);
                return 1;
        }
        if (strcmp("bg", commandArgv[0]) == 0) {
                if (commandArgv[1] == NULL)
                        return 0;
                if (strcmp("in", commandArgv[1]) == 0)
                        launchJob(commandArgv + 3, *(commandArgv + 2), STDIN, BACKGROUND);
                else if (strcmp("out", commandArgv[1]) == 0)
                        launchJob(commandArgv + 3, *(commandArgv + 2), STDOUT, BACKGROUND);
                else
                        launchJob(commandArgv + 1, "STANDARD", 0, BACKGROUND);
                return 1;
        }
        if (strcmp("fg", commandArgv[0]) == 0) {
                if (commandArgv[1] == NULL)
                        return 0;
                int jobId = (int) atoi(commandArgv[1]);
                t_job* job = getJob(jobId, BY_JOB_ID);
                if (job == NULL)
                        return 0;
                if (job->status == SUSPENDED || job->status == WAITING_INPUT)
                        putJobForeground(job, TRUE);
                else                                                                                                // status = BACKGROUND
                        putJobForeground(job, FALSE);
                return 1;
        }
        if (strcmp("jobs", commandArgv[0]) == 0) {
                printJobs();
                return 1;
        }
        if (strcmp("kill", commandArgv[0]) == 0) {
                if (commandArgv[1] == NULL)
                        return 0;
                killJob(atoi(commandArgv[1]));
                return 1;
        }
        return 0;
}

/**
 * executes a program redirecting STDIN or STDOUT if newDescriptor != STANDARD
 */
void executeCommand(char *command[], char *file, int newDescriptor,
                    int executionMode)
{
        int commandDescriptor;
        /**
         *  Set the STDIN/STDOUT channels of the new process.
         */
        if (newDescriptor == STDIN) {
                commandDescriptor = open(file, O_RDONLY, 0600);                                        // open file for read only (it's STDIN)
                dup2(commandDescriptor, STDIN_FILENO);
                close(commandDescriptor);
        }
        if (newDescriptor == STDOUT) {
                commandDescriptor = open(file, O_CREAT | O_TRUNC | O_WRONLY, 0600); // open (create) the file truncating it at 0, for write only
                dup2(commandDescriptor, STDOUT_FILENO);
                close(commandDescriptor);
        }
        if (execvp(*command, command) == -1)
                perror("BD-shell(execvp)");
}

/**
 * forks a process and launches a program as child
 */
void launchJob(char *command[], char *file, int newDescriptor,
               int executionMode)
{
        pid_t pid;
        pid = fork();
        switch (pid) {
        case -1:
                perror("BD-shell(fork)");
                exit(EXIT_FAILURE);
                break;
        case 0:
                /**
                 *  we set the handling for job control signals back to the default.
                 */
                signal(SIGINT, SIG_DFL);
                signal(SIGQUIT, SIG_DFL);
                signal(SIGTSTP, SIG_DFL);
                signal(SIGCHLD, &signalHandler_child);
                signal(SIGTTIN, SIG_DFL);
                usleep(20000);                                                             // fixes a synchronization bug. Needed for short commands like ls
                setpgrp();                                                                                     // make the child as new process group leader
                if (executionMode == FOREGROUND)
                        tcsetpgrp(BDSH_TERMINAL, getpid());                                           // if we want the process to be in foreground
                if (executionMode == BACKGROUND)
                        printf("[%d] %d\n", ++numActiveJobs, (int) getpid());              // inform the user about the new job in bg

                executeCommand(command, file, newDescriptor, executionMode);

                exit(EXIT_SUCCESS);
                break;
        default:
                setpgid(pid, pid);                                                                        // we also make the child a new process group leader from here
                // to avoid race conditions
                jobsList = insertJob(pid, pid, *(command), file, (int) executionMode); // insert the job in the list

                t_job* job = getJob(pid, BY_PROCESS_ID);                             // and get it as job object

                if (executionMode == FOREGROUND) {
                        putJobForeground(job, FALSE);                                              // put the job in foreground (if desired)
                }
                if (executionMode == BACKGROUND)
                        putJobBackground(job, FALSE);                                             // put the job in background (if desired)
                break;
        }
}

/**
 * puts a job in foreground. If continueJob = TRUE, sends the process group
 * a SIGCONT signal to wake it up. After the job is waited successfully, it
 * restores the control of the terminal to the shell
 */
void putJobForeground(t_job* job, int continueJob)
{
        job->status = FOREGROUND;                                                   // set its status in the list as FOREGROUND
        tcsetpgrp(BDSH_TERMINAL, job->pgid);                                 // give it the control of the terminal
        if (continueJob) {                                                                        // continue the job (if desired)
                if (kill(-job->pgid, SIGCONT) < 0)                                           // by sending it a SIGCONT signal
                        perror("kill (SIGCONT)");
        }

        waitJob(job);                                                                                 // wait for the job
        tcsetpgrp(BDSH_TERMINAL, BDSH_PGID);                              // give the shell control of the terminal
}

/**
 * puts a job in background, and sends the job a continue signal, if continueJob = TRUE
 * puts the shell in foreground
 */
void putJobBackground(t_job* job, int continueJob)
{
        if (job == NULL)
                return;

        if (continueJob && job->status != WAITING_INPUT)
                job->status = WAITING_INPUT;		// fixes another synchronization bug: if the child process launches
		// a SIGCHLD and is set to WAITING_INPUT before this point has been
        // reached, then it would be set to BACKGROUND again

        if (continueJob)                        // if desired, continue the job
                if (kill(-job->pgid, SIGCONT) < 0)
                        perror("kill (SIGCONT)");

        tcsetpgrp(BDSH_TERMINAL, BDSH_PGID);                             // paranoia: give the shell control of terminal
}

/**
 * waits for a job, blocking unless it has been suspended.
 * Deletes the job after it has been executed
 */
void waitJob(t_job* job)
{
        int terminationStatus;
        while (waitpid(job->pid, &terminationStatus, WNOHANG) == 0) {      // while there are child to be waited
                if (job->status == SUSPENDED)                              // exit if the job has been set to be stopped
                        return;
        }
        jobsList = delJob(job);                                            // delete the job
}

/**
 * kills a Job given its number
 */
void killJob(int jobId)
{
        t_job *job = getJob(jobId, BY_JOB_ID);                                   // get the job from the list
        kill(job->pid, SIGKILL);                                                               // send the job a SIGKILL signal
}

/**
 * changes current directory
 */
void changeDirectory()
{
        if (commandArgv[1] == NULL) {
                chdir(getenv("HOME"));                                                        // simulate a "cd" command
        } else {
                if (chdir(commandArgv[1]) == -1) {                                  // go to the new directory
                        printf(" %s: no such directory\n", commandArgv[1]);
                }
        }
}

/**
 * initializes variables and enables job control
 * NOTE: function substantially stolen by the very useful glibc manual:
 * http://www.gnu.org/software/libc/manual/html_node/Implementing-a-Shell.html
 */
void init()
{
        BDSH_PID = getpid();                                                             // retrieve the pid of the shell
        BDSH_TERMINAL = STDIN_FILENO;                                       // terminal = STDIN
        BDSH_IS_INTERACTIVE = isatty(BDSH_TERMINAL);            // the shell is interactive if STDIN is the terminal

        if (BDSH_IS_INTERACTIVE) {                                                 // is the shell interactive?
                while (tcgetpgrp(BDSH_TERMINAL) != (BDSH_PGID = getpgrp()))
                        kill(BDSH_PID, SIGTTIN);                                                    // make sure we are in the foreground

                /**
                 * ignore all the job control stop signals and install custom signal handlers
                 */
                signal(SIGQUIT, SIG_IGN);
                signal(SIGTTOU, SIG_IGN);
                signal(SIGTTIN, SIG_IGN);
                signal(SIGTSTP, SIG_IGN);
                signal(SIGINT, SIG_IGN);
                signal(SIGCHLD, &signalHandler_child);

                setpgid(BDSH_PID, BDSH_PID);                                         // we make the shell process as new process group leader
                BDSH_PGID = getpgrp();
                if (BDSH_PID != BDSH_PGID) {
                        printf("Error, the shell is not process group leader");
                        exit(EXIT_FAILURE);
                }
                if (tcsetpgrp(BDSH_TERMINAL, BDSH_PGID) == -1)      // if bdsh cannot grab control of the terminal
                        tcgetattr(BDSH_TERMINAL, &BDSH_TMODES);             // we save default terminal attributes for shell.

                currentDirectory = (char*) calloc(1024, sizeof(char));
        } else {
                printf("Could not make BD-shell interactive. Exiting..\n");
                exit(EXIT_FAILURE);
        }
}

int main(int argc, char **argv, char **envp)
{
        init();
        welcomeScreen();
        shellPrompt();                                                                         // prints the prompt
        while (TRUE) {
                userInput = getchar();
                switch (userInput) {
                case '\n':                                                                               // if the user hits the enter key
                        shellPrompt();                                                                     // nothing happens
                        break;
                default:
                        getTextLine();                                                                     // store user input in buffer
                        handleUserCommand();                                                   // execute user command
                        shellPrompt();                                                                    // print the prompt
                        break;
                }
        }
        printf("\n");
        return 0;
}

/*********************************************************************
 * SIGNAL HANDLERS
 *********************************************************************/

/**
 * signal handler for SIGCHLD
 */
void signalHandler_child(int p)
{
        pid_t pid;
        int terminationStatus;
        pid = waitpid(WAIT_ANY, &terminationStatus, WUNTRACED | WNOHANG); // intercept the process that sends the signal
        if (pid > 0) {                                                                          // if there are information about it
                t_job* job = getJob(pid, BY_PROCESS_ID);                      // get the job from the list
                if (job == NULL)
                        return;
                if (WIFEXITED(terminationStatus)) {                                                    // case the process exits normally
                        if (job->status == BACKGROUND) {                             // child in background terminates normally
                                printf("\n[%d]+  Done\t   %s\n", job->id, job->name); // inform the user
                                jobsList = delJob(job);                                                    // delete it from the list
                        }
                } else if (WIFSIGNALED(terminationStatus)) {                                  // the job dies because of a signal
                        printf("\n[%d]+  KILLED\t   %s\n", job->id, job->name); // inform the user
                        jobsList = delJob(job);                                                     // delete the job from the list
                } else if (WIFSTOPPED(terminationStatus)) {                                  // a job receives a SIGSTP signal
                        if (job->status == BACKGROUND) {                           // the job is in bg
                                tcsetpgrp(BDSH_TERMINAL, BDSH_PGID);
                                changeJobStatus(pid, WAITING_INPUT);                     // change its status to "waiting for input"
                                printf("\n[%d]+   suspended [wants input]\t   %s\n",
                                       numActiveJobs, job->name);                                  // inform the user
                        } else {                                                                           // otherwise, the job is going to be suspended
                                tcsetpgrp(BDSH_TERMINAL, job->pgid);
                                changeJobStatus(pid, SUSPENDED);                         // we modify the status
                                printf("\n[%d]+   stopped\t   %s\n", numActiveJobs, job->name); // and inform the user
                        }
                        return;
                } else {
                        if (job->status == BACKGROUND) {                          // otherwise, delete the job from the list
                                jobsList = delJob(job);
                        }
                }
                tcsetpgrp(BDSH_TERMINAL, BDSH_PGID);
        }
}
