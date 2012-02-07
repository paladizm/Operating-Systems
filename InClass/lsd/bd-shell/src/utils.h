/**
 * BD-shell 1.0.0 UTILS
 * Description: useful functions
 * Author: Daniel Graziotin, 4801, daniel.graziotin@unibz.it
 * Project URL: http://daniel.graziotin.net/projects/bd-shell
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

/*********************************************************************
 * USER INPUT FUNCTIONS
 *********************************************************************/

/**
 *	gets a line of text from user
 */
void getTextLine()
{
        destroyCommand();                                                                     // clean buffer and command line
        while ((userInput != '\n') && (bufferChars < BUFFER_MAX_LENGTH)) {
                buffer[bufferChars++] = userInput;
                userInput = getchar();
        }
        buffer[bufferChars] = 0x00;                                                         // null terminate buffer
        populateCommand();
}

/**
 * populates commandArgv array with every words
 * of the command line (space " " used as separator)
 */
void populateCommand()
{
        char* bufferPointer;                                                                  // a pointer to the buffer
        bufferPointer = strtok(buffer, " ");
        while (bufferPointer != NULL) {                                               // while the pointer is not NULL
                commandArgv[commandArgc] = bufferPointer;                   // populate commandArgv array
                bufferPointer = strtok(NULL, " ");
                commandArgc++;
        }
}

/**
 *	destroys the arrays of chars, letting the user to input the next command line
 */
void destroyCommand()
{
        while (commandArgc != 0) {
                commandArgv[commandArgc] = NULL;                                 // delete the pointer to the string
                commandArgc--;                                                                       // decrement the number of words in the command line
        }
        bufferChars = 0;                                                                          // erase the number of chars in the buffer
}

/*********************************************************************
 * FUNCTIONS REGARDING ACTIVE JOBS
 *********************************************************************/

/**
 *	inserts an active process in the linked list
 */
t_job* insertJob(pid_t pid, pid_t pgid, char* name, char* descriptor,
                 int status)
{
        usleep(10000);
        t_job *newJob = malloc(sizeof(t_job));

        newJob->name = (char*) malloc(sizeof(name));
        newJob->name = strcpy(newJob->name, name);
        newJob->pid = pid;
        newJob->pgid = pgid;
        newJob->status = status;
        newJob->descriptor = (char*) malloc(sizeof(descriptor));
        newJob->descriptor = strcpy(newJob->descriptor, descriptor);
        newJob->next = NULL;

        if (jobsList == NULL) {
                numActiveJobs++;
                newJob->id = numActiveJobs;
                return newJob;
        } else {
                t_job *auxNode = jobsList;
                while (auxNode->next != NULL) {
                        auxNode = auxNode->next;
                }
                newJob->id = auxNode->id + 1;
                auxNode->next = newJob;
                numActiveJobs++;
                return jobsList;
        }
}

/**
 * modifies the status of a job
 */
int changeJobStatus(int pid, int status)
{
        usleep(10000);
        t_job *job = jobsList;
        if (job == NULL) {
                return 0;
        } else {
                int counter = 0;
                while (job != NULL) {
                        if (job->pid == pid) {
                                job->status = status;
                                return TRUE;
                        }
                        counter++;
                        job = job->next;
                }
                return FALSE;
        }
}

/**
 *	deletes a no more active process from the linked list
 */
t_job* delJob(t_job* job)
{
        usleep(10000);
        if (jobsList == NULL)
                return NULL;
        t_job* currentJob;
        t_job* beforeCurrentJob;

        currentJob = jobsList->next;
        beforeCurrentJob = jobsList;

        if (beforeCurrentJob->pid == job->pid) {

                beforeCurrentJob = beforeCurrentJob->next;
                numActiveJobs--;
                return currentJob;
        }

        while (currentJob != NULL) {
                if (currentJob->pid == job->pid) {
                        numActiveJobs--;
                        beforeCurrentJob->next = currentJob->next;
                }
                beforeCurrentJob = currentJob;
                currentJob = currentJob->next;
        }
        return jobsList;
}

/**
 * searches a job in the active jobs list, by pid, job id, job status
 */
t_job* getJob(int searchValue, int searchParameter)
{
        usleep(10000);
        t_job* job = jobsList;
        switch (searchParameter) {
        case BY_PROCESS_ID:
                while (job != NULL) {
                        if (job->pid == searchValue)
                                return job;
                        else
                                job = job->next;
                }
                break;
        case BY_JOB_ID:
                while (job != NULL) {
                        if (job->id == searchValue)
                                return job;
                        else
                                job = job->next;
                }
                break;
        case BY_JOB_STATUS:
                while (job != NULL) {
                        if (job->status == searchValue)
                                return job;
                        else
                                job = job->next;
                }
                break;
        default:
                return NULL;
                break;
        }
        return NULL;
}

/**
 * prints the active processes launched by the shell
 */
void printJobs()
{
        printf("\nActive jobs:\n");
        printf(
                "---------------------------------------------------------------------------\n");
        printf("| %7s  | %30s | %5s | %10s | %6s |\n", "job no.", "name", "pid",
               "descriptor", "status");
        printf(
                "---------------------------------------------------------------------------\n");
        t_job* job = jobsList;
        if (job == NULL) {
                printf("| %s %62s |\n", "No Jobs.", "");
        } else {
                while (job != NULL) {
                        printf("|  %7d | %30s | %5d | %10s | %6c |\n", job->id, job->name,
                               job->pid, job->descriptor, job->status);
                        job = job->next;
                }
        }
        printf(
                "---------------------------------------------------------------------------\n");
}

/*********************************************************************
 * PROMPT AND ERROR FUNCTIONS
 *********************************************************************/

/**
 *	displays a welcome screen
 */
void welcomeScreen()
{
        printf("\n-------------------------------------------------\n");
        printf("\tWelcome to BD-shell version %s\n", SHELL_VERSION);
        printf("\tThis is bdsh with process id: %d\n", (int) BDSH_PID);
        printf("-------------------------------------------------\n");
        printf("\n\n");
}

/**
 *	displays a nice prompt for the shell
 */
void shellPrompt()
{
        printf("%s - %s j: %d> ", getenv("LOGNAME"),
               getcwd(currentDirectory, 1024), numActiveJobs);                   // nice shellPrompt with current user and current dir
}
