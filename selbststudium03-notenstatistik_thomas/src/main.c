/* ----------------------------------------------------------------------------
 * --  _____       ______  _____                                              -
 * -- |_   _|     |  ____|/ ____|                                             -
 * --   | |  _ __ | |__  | (___    Institute of Embedded Systems              -
 * --   | | | '_ \|  __|  \___ \   Zuercher Hochschule Winterthur             -
 * --  _| |_| | | | |____ ____) |  (University of Applied Sciences)           -
 * -- |_____|_| |_|______|_____/   8401 Winterthur, Switzerland               -
 * ----------------------------------------------------------------------------
 */
/**
 * @file
 * @brief Lab implementation
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int students;
    int points_6;
    int best_mark;
    int worst_mark;
    double average_mark;
    int mark_6;
    int mark_5;
    int mark_4;
    int mark_3;
    int mark_2;
    int mark_1;
    int passed;
    } Statistics;
    
Statistics getStatistics(int points[], int len, int points_6);
int getMark(int points, int points_6);
void printStatistics(Statistics);


/**
 * @brief Main entry point.
 * @param[in] argc  The size of the argv array.
 * @param[in] argv  The command line arguments
 *                  with argv[0] being the command call
 *                  argv[1] the 1st argument, ...
 *                  argv[argc-1] the last argument.
 * @returns Returns EXIT_SUCCESS (=0) on success,
 *                  EXIT_FAILURE (=1) if more than one argument is given.
 */
int main(void)
{
	int points[100];
	int len = 0;
	int all_points_inserted = 0;
	int points_6 = 0;
	Statistics statistics;
	char rerun = 'y';
	
	while (!all_points_inserted) {
	    (void)scanf("%d", &points[len]);
	    if (points[len] >= 0) {
	        len++;
	    } else if (points[len] == -1) {
	        all_points_inserted = 1;
	    //  len++;
	    } else {
	        (void)printf("Points must be > 0!\n");
	    }
	}
	
	(void)printf("Insert points needed for a 6: \n");
	(void)scanf("%d", &points_6);

	do {
	    statistics = getStatistics(points, len, points_6);
	    (void)printStatistics(statistics);
	    (void)printf("Enter new minimal points for grade 6(y/n?)");
	    (void)scanf(" %s", &rerun);
	    if (rerun == 'y') {
	        (void)scanf("%d", &points_6);
	        
	    }
	} while (rerun == 'y'); 
	
	return EXIT_SUCCESS;
}

Statistics getStatistics(int points[], int len, int points_6) {
    Statistics statistics = { len, points_6 };
    int grades[len];
    for(int i = 0; i < len; i++) {
        grades[i] = getMark(points[i], points_6);    
    }
    
    int mark6 = 0;
    int mark5 = 0;
    int mark4 = 0;
    int mark3 = 0;
    int mark2 = 0;
    int mark1 = 0;
    int best_mark =1;
    int worst_mark=6;
    double average_mark;
    
    for(int i=0; i<len; i++) {
        best_mark = best_mark > grades[i] ? best_mark : grades[i];
        worst_mark = worst_mark < grades[i] ? worst_mark : grades[i];
        switch(grades[i]) {
            case 1: mark1++;
            break;
            case 2: mark2++;
            break;
            case 3: mark3++;
            break;
            case 4: mark4++;
            break;
            case 5: mark5++;
            break;
            case 6: mark6++;
        }               
    }
    average_mark = (1*mark1+2*mark2+3*mark3+4*mark4+5*mark5+6*mark6)/(double)len;
    statistics.best_mark = best_mark;
    statistics.worst_mark = worst_mark;
    statistics.average_mark = average_mark;
    statistics.mark_1 = mark1;
    statistics.mark_2 = mark2;
    statistics.mark_3 = mark3;
    statistics.mark_4 = mark4;
    statistics.mark_5 = mark5;
    statistics.mark_6 = mark6;
    statistics.passed = mark6+mark5+mark4;
    return statistics;
}

int getMark(int points, int points_6) {
    double mark = 1 + ((5.0*points)/points_6);
    if (mark > 6.0) {
        mark = 6.0;
    }
    if ((mark - (int)mark) > 0.5) {
        mark = ceil(mark);
    } else {
        mark = floor(mark);
    }
    return (int)mark;
}

void printStatistics(Statistics statistics) {
    

    (void)printf("--------------------------------------------------------\n");
    (void)printf("Statistics (%d students, %d points needed for mark 6):\n", statistics.students, statistics.points_6);
    (void)printf("Mark 6: %d\n", statistics.mark_6);
    (void)printf("Mark 5: %d\n", statistics.mark_5);
    (void)printf("Mark 4: %d\n", statistics.mark_4);
    (void)printf("Mark 3: %d\n", statistics.mark_3);
    (void)printf("Mark 2: %d\n", statistics.mark_2);
    (void)printf("Mark 1: %d\n\n", statistics.mark_1);
    (void)printf("Best mark:    %d\n", statistics.best_mark);
    (void)printf("Worst mark:   %d\n", statistics.worst_mark);
    (void)printf("Average mark: %.2f\n", statistics.average_mark);
    (void)printf("Mark >= 4: %d students %d Percent\n", statistics.passed, (statistics.passed*100)/statistics.students);
    (void)printf("--------------------------------------------------------\n");
    
}


