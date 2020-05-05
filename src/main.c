#include <stdio.h>
#include <math.h>

#include "pitching_game.h"
#include "calcs.h"

struct point top_left      = {.x = 0  , .y = 0   };
struct point top_right     = {.x = 255, .y = 0   };
struct point bottom_right  = {.x = 255, .y = 255 };
struct point bottom_left   = {.x = 0  , .y = 255 };

int A_dir[4][2] = {
    { 1,  1},
    {-1,  1},
    {-1, -1},
    { 1, -1}
};



int main()
{

    int length_data[4]  = {0, 182, 200, 220};
    int length_data_order[3] = {0};

    int index_of_smallest_length = 0;
    find_smallest_length(length_data, &index_of_smallest_length, 4);

    struct point center = {64, 64};
    
    struct vector A_vector[4] = {
	{top_left    , {top_left.x     + length_data[0], top_left.y}},
	{top_right   , {top_right.x    + length_data[1], top_right.y}},
	{bottom_right, {bottom_right.x + length_data[2], bottom_right.y}},
	{bottom_left , {bottom_left.x  + length_data[3], bottom_right.y}}
    };

    struct vector vector_corners_to_center[4] = {
	{top_left    , center},
	{top_right   , center},
	{bottom_right, center},
	{bottom_left , center},
    };

    float rad_corner_to_center[4] = {
	calc_vector_rad(&vector_corners_to_center[0]),
	calc_vector_rad(&vector_corners_to_center[1]),
	calc_vector_rad(&vector_corners_to_center[2]),
	calc_vector_rad(&vector_corners_to_center[3]),	
    };


    for(int count = 0; count < 4; count++) {
        rotate_vector(&A_vector[count],
		      rad_corner_to_center[count],
		      A_dir[count][0],
		      A_dir[count][1]
	    );
    }

    struct vector vector_to_center[4] = {
	{center, A_vector[0].P2},
	{center, A_vector[1].P2},
	{center, A_vector[2].P2},
	{center, A_vector[3].P2},
    };
    
    float lengths_to_center[4] = {
	calc_vector_length(&vector_to_center[0]),
	calc_vector_length(&vector_to_center[1]),
	calc_vector_length(&vector_to_center[2]),
	calc_vector_length(&vector_to_center[3]),	
    };

    order_length_data(lengths_to_center, length_data_order, 4, index_of_smallest_length);
    for(int count = 0; count < 3; count++) printf("ORDER: %d\n", length_data_order[count]);

    struct point longest, medium, shortest;

    for(int count = 0; count < 3; count++) {
	if (length_data_order[count] == 2)     longest  = A_vector[count].P2;
	else if(length_data_order[count] == 1) medium   = A_vector[count].P2;
	else if(length_data_order[count] == 0) shortest = A_vector[count].P2;	
    }

    printf("LONGEST: (%d, %d)\n", longest.x, longest.y);
    printf("MEDIUM: (%d, %d)\n", medium.x, medium.y);
    printf("SHORTEST: (%d, %d)\n", shortest.x, shortest.y);    
    
    //determine the axis for adjustment

    

    for(int count = 0; count < 4; count++) {
	printf("RESULT %d: (%d,%d) - (%d,%d) || ERROR %f\n",
	       count,
	       A_vector[count].P1.x,
	       A_vector[count].P1.y,
	       A_vector[count].P2.x,
	       A_vector[count].P2.y,
	       lengths_to_center[count]
	    );
    }


    
    
    return 0;
}
